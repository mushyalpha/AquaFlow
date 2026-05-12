#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include "PinConfig.h"
#include "hardware/FlowMeter.h"
#include "hardware/GestureSensor.h"
#include "hardware/PumpController.h"
#include "state/FillingController.h"

class FillingControllerTest : public ::testing::Test {
protected:
    GestureSensor gs;
    PumpController pump{4, 27};
    FlowMeter flow{4, 17, 1.0f};
    FillingController fc{gs, pump, flow};

    FillingControllerTest() {
        pump.enableSimulationForTest();
    }

    void simulateProximity(ProximityState state) {
        gs.emitEventForTest({state, GestureDir::NONE, 200});
    }

    void waitForCupConfirmation() {
        std::this_thread::sleep_for(std::chrono::milliseconds(CUP_CONFIRM_MS + 50));
    }
};

TEST_F(FillingControllerTest, InitialStateIsSelectingSize) {
    EXPECT_EQ(fc.getState(), SystemState::SELECTING_SIZE);
    EXPECT_EQ(fc.getBottleCount(), 0);
    EXPECT_EQ(fc.getTargetVolumeML(), 0.0);
    EXPECT_EQ(fc.getSizeName(), "SMALL");
}

TEST_F(FillingControllerTest, LongPressConfirmsSelectionAndWaitsForCup) {
    fc.onShortPress(); // SMALL -> MEDIUM
    EXPECT_EQ(fc.getSizeName(), "MEDIUM");

    fc.onLongPress();
    fc.tick();

    EXPECT_EQ(fc.getState(), SystemState::WAITING_FOR_CUP);
    EXPECT_EQ(fc.getTargetVolumeML(), 400.0);
}

TEST_F(FillingControllerTest, ReturnsToWaitingIfProximityClearedDuringConfirmation) {
    fc.onLongPress();
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::WAITING_FOR_CUP);

    simulateProximity(ProximityState::PROXIMITY_TRIGGERED);
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::CONFIRMING);

    simulateProximity(ProximityState::PROXIMITY_CLEARED);
    fc.tick();

    EXPECT_EQ(fc.getState(), SystemState::WAITING_FOR_CUP);
}

TEST_F(FillingControllerTest, CompletesFullCycleSuccessfully) {
    fc.onShortPress(); // SMALL -> MEDIUM (400 ml)
    fc.onLongPress();
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::WAITING_FOR_CUP);
    EXPECT_EQ(fc.getTargetVolumeML(), 400.0);

    simulateProximity(ProximityState::PROXIMITY_TRIGGERED);
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::CONFIRMING);

    waitForCupConfirmation();
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::FILLING);
    EXPECT_TRUE(pump.isRunning());

    flow.injectPulseCountForTest(400);

    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::FILL_COMPLETE);
    EXPECT_FALSE(pump.isRunning());
    EXPECT_EQ(fc.getBottleCount(), 1);

    simulateProximity(ProximityState::PROXIMITY_CLEARED);
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::SELECTING_SIZE);
}
