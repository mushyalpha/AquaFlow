#include <gtest/gtest.h>

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

    void simulateGesture(GestureDir dir) {
        gs.emitEventForTest({ProximityState::PROXIMITY_TRIGGERED, dir, 200});
    }
};

TEST_F(FillingControllerTest, InitialStateIsWaiting) {
    EXPECT_EQ(fc.getState(), SystemState::WAITING);
    EXPECT_EQ(fc.getBottleCount(), 0);
}

TEST_F(FillingControllerTest, TransitionToAwaitSelectionOnProximity) {
    EXPECT_EQ(fc.getState(), SystemState::WAITING);

    simulateProximity(ProximityState::PROXIMITY_TRIGGERED);
    fc.tick();

    EXPECT_EQ(fc.getState(), SystemState::AWAIT_SELECTION);
}

TEST_F(FillingControllerTest, ReturnsToWaitingIfProximityClearedPrematurely) {
    simulateProximity(ProximityState::PROXIMITY_TRIGGERED);
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::AWAIT_SELECTION);

    simulateProximity(ProximityState::PROXIMITY_CLEARED);
    fc.tick();

    EXPECT_EQ(fc.getState(), SystemState::WAITING);
}

TEST_F(FillingControllerTest, CompletesFullCycleSuccessfully) {
    simulateProximity(ProximityState::PROXIMITY_TRIGGERED);
    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::AWAIT_SELECTION);

    simulateGesture(GestureDir::DOWN); // 400ml

    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::FILLING);
    EXPECT_TRUE(pump.isRunning());
    EXPECT_EQ(fc.getTargetVolumeML(), 400.0);

    flow.injectPulseCountForTest(400);

    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::FILL_COMPLETE);
    EXPECT_FALSE(pump.isRunning());
    EXPECT_EQ(fc.getBottleCount(), 1);

    fc.tick();
    EXPECT_EQ(fc.getState(), SystemState::WAITING);
}
