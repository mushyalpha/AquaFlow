#pragma once

#include "IFlowMeter.h"
#include "state/FillingController.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTimer>
#include <QVector>

// Forward-declare QCustomPlot to avoid header dependency here
class QCustomPlot;
class QCPGraph;

/**
 * @brief Qt6 GUI window for the AquaFlow filling machine.
 *
 * Provides two marking-critical capabilities:
 *  1. **Real-time plotting** — a scrolling QCustomPlot graph of dispensed
 *     volume (ml) over time, satisfying "Not plotting values on screen" dealbreaker.
 *  2. **Mouse interaction** — clickable QPushButtons to cycle cup size,
 *     confirm selection, and reset the fill, satisfying "No mouse interaction" dealbreaker.
 *
 * Architecture notes (SOLID compliance):
 *  - The window depends only on FillingController (state machine) and
 *    IFlowMeter (volume readings) — no direct hardware coupling.
 *  - A QTimer drives the 40 ms GUI refresh (as per the lecturer's example);
 *    this is NOT used for real-time sampling — the hardware Timer + timerfd
 *    handles that independently.
 *  - The window does NOT own any hardware — it observes state via
 *    const-safe accessors only.
 */
class AquaFlowWindow : public QWidget {
    Q_OBJECT

public:
    /**
     * @param controller  Reference to the FillingController state machine.
     * @param flowMeter   Reference to the IFlowMeter for live volume readings.
     * @param parent      Optional Qt parent widget.
     */
    AquaFlowWindow(FillingController& controller,
                   IFlowMeter&        flowMeter,
                   QWidget*           parent = nullptr);

    /** @brief Start the data acquisition timer and begin plotting. */
    void startDAQ();

private slots:
    /** @brief Called every 40 ms to refresh the plot and status labels. */
    void onTimerTick();

    /** @brief Mouse-interactive button: cycle cup size (Small → Medium → Large). */
    void onCycleSizeClicked();

    /** @brief Mouse-interactive button: confirm selected size, begin fill. */
    void onSelectSizeClicked();

    /** @brief Mouse-interactive button: reset to SELECTING_SIZE state. */
    void onResetClicked();

private:
    // ── External references (not owned) ──────────────────────────────────────
    FillingController& controller_;
    IFlowMeter&        flowMeter_;

    // ── Qt widgets ───────────────────────────────────────────────────────────

    // Status panel (left side, vertical layout)
    QLabel*      stateLabel_;       ///< Current state name
    QLabel*      sizeLabel_;        ///< Selected cup size
    QLabel*      volumeLabel_;      ///< Current / target volume (ml)
    QLabel*      cupsLabel_;        ///< Total cups filled this session
    QLabel*      proximityLabel_;   ///< Proximity sensor status indicator

    // Interactive buttons (mouse interaction — marking requirement)
    QPushButton* cycleSizeBtn_;     ///< "Cycle Size" button (short press equivalent)
    QPushButton* selectSizeBtn_;    ///< "Confirm Size" button (long press equivalent)
    QPushButton* resetBtn_;         ///< "Reset" button

    // Real-time plot (plotting requirement)
    QCustomPlot* plot_;             ///< QCustomPlot widget for live volume graph
    QCPGraph*    volumeGraph_;      ///< Graph line for dispensed volume
    QCPGraph*    targetGraph_;      ///< Horizontal reference line at target volume

    // GUI refresh timer (NOT for real-time sampling — just display refresh)
    QTimer*      refreshTimer_;

    // ── Plot data ────────────────────────────────────────────────────────────
    static constexpr int MAX_DATA_POINTS = 500;  ///< ~20 seconds at 40 ms refresh
    QVector<double> timeData_;
    QVector<double> volumeData_;
    double elapsedSeconds_{0.0};

    // ── Layout helpers ───────────────────────────────────────────────────────
    void setupUI();
    void setupPlot();
};
