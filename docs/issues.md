# Project Issue Tracker (Offline)

This document tracks technical issues and milestones for the AquaFlow project. 
*Note: These are synced to GitHub Issues periodically.*

## Open Issues

### [#15] Finalise Unit Testing for FillingController
- **Status:** Open
- **Priority:** High
- **Description:** Need to verify state transitions in `FillingController` using a Mock FlowMeter.

---

## Closed Issues

### [#14] Replace std::cout with Logger in state machine
- **Status:** Closed (Linked in commit 9e1f565)
- **Resolved:** Removed non-deterministic I/O from `FillingController::tick()`.

### [#13] Implement acquire/release memory ordering for proximity flag
- **Status:** Closed (Linked in commit 9e1f565)
- **Resolved:** Improved thread safety for the `bottlePresent_` atomic.

### [#12] Fix GestureSensor POLL_INTERVAL
- **Status:** Closed (Linked in commit 10d415f)
- **Resolved:** Reverted to 50ms for better responsiveness.

### [#11] Add timerfd-based blocking to GestureSensor
- **Status:** Closed
- **Resolved:** Replaced `sleep_for` with kernel-managed timerfd.

### [#10] Migrate Pump to libgpiod v2.x
- **Status:** Closed
- **Resolved:** Updated hardware drivers for Raspberry Pi 5 compatibility.

### [#1] Initial Project Structure
- **Status:** Closed
- **Resolved:** Created hardware, state, and monitor directories.
