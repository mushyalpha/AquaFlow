#include "gui/AquaFlowWindow.h"
#include "PinConfig.h"

#include <qcustomplot.h>

#include <QFont>
#include <QFrame>
#include <QSizePolicy>

#include <sstream>
#include <iomanip>

// ─────────────────────────────────────────────────────────────────────────────

AquaFlowWindow::AquaFlowWindow(FillingController& controller,
                               IFlowMeter&        flowMeter,
                               QWidget*           parent)
    : QWidget(parent),
      controller_(controller),
      flowMeter_(flowMeter)
{
    setWindowTitle("AquaFlow — Real-Time Filling Monitor");
    resize(900, 500);

    setupUI();
    setupPlot();
}

// ─── UI Layout ───────────────────────────────────────────────────────────────

void AquaFlowWindow::setupUI() {

    // ── Left panel: status labels + interactive buttons ──────────────────────
    auto* leftPanel = new QVBoxLayout();

    // Title
    auto* titleLabel = new QLabel("AquaFlow Monitor");
    QFont titleFont("Sans", 16, QFont::Bold);
    titleLabel->setFont(titleFont);
    leftPanel->addWidget(titleLabel);

    // Separator line
    auto* sep1 = new QFrame();
    sep1->setFrameShape(QFrame::HLine);
    sep1->setFrameShadow(QFrame::Sunken);
    leftPanel->addWidget(sep1);

    // Status labels
    stateLabel_ = new QLabel("State: SELECTING");
    stateLabel_->setFont(QFont("Monospace", 11));
    leftPanel->addWidget(stateLabel_);

    sizeLabel_ = new QLabel("Size: SMALL (250 ml)");
    sizeLabel_->setFont(QFont("Monospace", 11));
    leftPanel->addWidget(sizeLabel_);

    volumeLabel_ = new QLabel("Volume: 0.0 / 0 ml");
    volumeLabel_->setFont(QFont("Monospace", 11));
    leftPanel->addWidget(volumeLabel_);

    cupsLabel_ = new QLabel("Cups filled: 0");
    cupsLabel_->setFont(QFont("Monospace", 11));
    leftPanel->addWidget(cupsLabel_);

    proximityLabel_ = new QLabel("Proximity: ---");
    proximityLabel_->setFont(QFont("Monospace", 11));
    leftPanel->addWidget(proximityLabel_);

    // Separator before buttons
    auto* sep2 = new QFrame();
    sep2->setFrameShape(QFrame::HLine);
    sep2->setFrameShadow(QFrame::Sunken);
    leftPanel->addWidget(sep2);

    // ── Mouse-interactive buttons (marking requirement) ──────────────────────
    auto* btnLabel = new QLabel("Controls (Mouse Interaction):");
    btnLabel->setFont(QFont("Sans", 10, QFont::Bold));
    leftPanel->addWidget(btnLabel);

    cycleSizeBtn_ = new QPushButton("Cycle Size (S → M → L)");
    cycleSizeBtn_->setMinimumHeight(35);
    cycleSizeBtn_->setToolTip("Click to cycle through Small / Medium / Large cup sizes");
    connect(cycleSizeBtn_, &QPushButton::clicked,
            this, &AquaFlowWindow::onCycleSizeClicked);
    leftPanel->addWidget(cycleSizeBtn_);

    selectSizeBtn_ = new QPushButton("Confirm Size && Start");
    selectSizeBtn_->setMinimumHeight(35);
    selectSizeBtn_->setToolTip("Click to confirm the selected cup size and begin waiting for a cup");
    connect(selectSizeBtn_, &QPushButton::clicked,
            this, &AquaFlowWindow::onSelectSizeClicked);
    leftPanel->addWidget(selectSizeBtn_);

    resetBtn_ = new QPushButton("Reset");
    resetBtn_->setMinimumHeight(35);
    resetBtn_->setToolTip("Click to reset the system back to size selection");
    connect(resetBtn_, &QPushButton::clicked,
            this, &AquaFlowWindow::onResetClicked);
    leftPanel->addWidget(resetBtn_);

    leftPanel->addStretch();

    // ── Right panel: real-time plot ──────────────────────────────────────────
    plot_ = new QCustomPlot(this);
    plot_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    plot_->setMinimumWidth(400);

    // ── Main horizontal layout (left panel + plot) ──────────────────────────
    auto* mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftPanel);
    mainLayout->addWidget(plot_, /*stretch=*/1);
    setLayout(mainLayout);
}

// ─── Plot Configuration ─────────────────────────────────────────────────────

void AquaFlowWindow::setupPlot() {
    // Volume graph (blue line, filled area beneath)
    volumeGraph_ = plot_->addGraph();
    volumeGraph_->setPen(QPen(QColor(30, 120, 230), 2));
    volumeGraph_->setBrush(QBrush(QColor(30, 120, 230, 40)));
    volumeGraph_->setName("Dispensed Volume (ml)");

    // Target reference line (red dashed)
    targetGraph_ = plot_->addGraph();
    targetGraph_->setPen(QPen(QColor(220, 50, 50), 2, Qt::DashLine));
    targetGraph_->setName("Target Volume");

    // Axis labels
    plot_->xAxis->setLabel("Time (s)");
    plot_->yAxis->setLabel("Volume (ml)");

    // Initial axis ranges
    plot_->xAxis->setRange(0, 20);
    plot_->yAxis->setRange(0, 550);

    // Enable mouse interaction on the plot itself (zoom, drag)
    plot_->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // Legend
    plot_->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    plot_->legend->setFont(legendFont);
    plot_->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));

    // Grid styling
    plot_->xAxis->grid()->setPen(QPen(QColor(200, 200, 200), 0, Qt::DotLine));
    plot_->yAxis->grid()->setPen(QPen(QColor(200, 200, 200), 0, Qt::DotLine));

    plot_->replot();
}

// ─── Start DAQ (timer-driven GUI refresh) ────────────────────────────────────

void AquaFlowWindow::startDAQ() {
    refreshTimer_ = new QTimer(this);
    connect(refreshTimer_, &QTimer::timeout,
            this, &AquaFlowWindow::onTimerTick);
    refreshTimer_->start(40);   // 40 ms = ~25 fps (matches lecturer's example)
}

// ─── Timer Tick: refresh plot + labels ───────────────────────────────────────

void AquaFlowWindow::onTimerTick() {
    elapsedSeconds_ += 0.040;   // 40 ms per tick

    double currentVolume = flowMeter_.getVolumeML();
    double targetVolume  = controller_.getTargetVolumeML();
    int    cups          = controller_.getBottleCount();

    // ── Update status labels ─────────────────────────────────────────────────
    stateLabel_->setText(QString("State: %1").arg(
        QString::fromStdString(controller_.getStateName())));

    sizeLabel_->setText(QString("Size: %1").arg(
        QString::fromStdString(controller_.getSizeName())));

    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1)
            << "Volume: " << currentVolume << " / "
            << static_cast<int>(targetVolume) << " ml";
        volumeLabel_->setText(QString::fromStdString(oss.str()));
    }

    cupsLabel_->setText(QString("Cups filled: %1").arg(cups));

    // Proximity status indicator
    SystemState st = controller_.getState();
    if (st == SystemState::CONFIRMING || st == SystemState::FILLING) {
        proximityLabel_->setText("Proximity: CUP DETECTED ✓");
        proximityLabel_->setStyleSheet("color: green; font-weight: bold;");
    } else if (st == SystemState::WAITING_FOR_CUP) {
        proximityLabel_->setText("Proximity: waiting...");
        proximityLabel_->setStyleSheet("color: orange;");
    } else {
        proximityLabel_->setText("Proximity: ---");
        proximityLabel_->setStyleSheet("");
    }

    // ── Update plot data ─────────────────────────────────────────────────────
    timeData_.append(elapsedSeconds_);
    volumeData_.append(currentVolume);

    // Trim to scrolling window
    if (timeData_.size() > MAX_DATA_POINTS) {
        timeData_.removeFirst();
        volumeData_.removeFirst();
    }

    volumeGraph_->setData(timeData_, volumeData_);

    // Update target reference line (horizontal line across full x range)
    if (targetVolume > 0) {
        double xMin = timeData_.isEmpty() ? 0 : timeData_.first();
        double xMax = timeData_.isEmpty() ? 20 : timeData_.last();
        targetGraph_->setData(QVector<double>{xMin, xMax},
                              QVector<double>{targetVolume, targetVolume});
    } else {
        targetGraph_->data()->clear();
    }

    // Auto-scale axes to follow the data
    if (!timeData_.isEmpty()) {
        double latestTime = timeData_.last();
        double windowStart = (latestTime > 20.0) ? latestTime - 20.0 : 0.0;
        plot_->xAxis->setRange(windowStart, latestTime + 1.0);
    }

    double yMax = (targetVolume > 0) ? targetVolume * 1.2 : 550;
    if (currentVolume > yMax * 0.8) yMax = currentVolume * 1.3;
    plot_->yAxis->setRange(0, yMax);

    plot_->replot();

    // ── Update button enabled state based on current system state ─────────────
    bool isSelecting = (st == SystemState::SELECTING_SIZE);
    cycleSizeBtn_->setEnabled(isSelecting);
    selectSizeBtn_->setEnabled(isSelecting);
}

// ─── Button Slots (Mouse Interaction) ────────────────────────────────────────

void AquaFlowWindow::onCycleSizeClicked() {
    controller_.onShortPress();
}

void AquaFlowWindow::onSelectSizeClicked() {
    controller_.onLongPress();
}

void AquaFlowWindow::onResetClicked() {
    // Reset the plot data
    timeData_.clear();
    volumeData_.clear();
    elapsedSeconds_ = 0.0;
    plot_->replot();
}
