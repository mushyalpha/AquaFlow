# FlowFizzy — Full RTES Lecture Gap Analysis

> Based on: Lec 2 (Callbacks/Threads), Lec 3 (IO/Interfaces), Lec 4 (Qt), Lec 5&6 (DDS/FastCGI), + Assessment Criteria & Course Marking Requirements transcript.

---

## ✅ STRONG — You are clearly satisfying these

| Requirement | Evidence in your code |
|---|---|
| **`std::thread` for every blocking worker** | `FlowMeter::edgeThread_`, `GestureSensor::workerThread_`, `Timer::workerThread_` all use `std::thread` |
| **No `std::bind` (banned)** | Zero results — you use lambdas correctly |
| **Lambda functions for publisher→subscriber wiring** | `AquaFlowApp::start()` wires button→controller with `[this]{ controller_.onShortPress(); }` |
| **`timerfd` blocking timer (not `sleep()`)** | `Timer.cpp` uses `timerfd_create` + blocking `read()` — textbook lecture example |
| **`libgpiod` edge interrupts (not polling)** | `FlowMeter` uses `request_->wait_edge_events()` — exactly what Lec 2 teaches |
| **`std::atomic` for thread-safe shared state** | `FillingController` has `atomic<CupSize>`, `atomic<bool>`, `atomic<double>` throughout |
| **No raw `new`/`delete` outside Qt** | Qt widgets use `new` (explicitly allowed by Lec 4 — Qt manages its own memory) |
| **`std::function` callbacks** | `Timer::TimerCallback`, `FillingController::MonitorCallback` — correct STL approach |
| **SOLID — SRP** | Each class has one job: `FlowMeter` counts pulses, `PumpController` switches GPIO, `GestureSensor` reads proximity, `Logger` logs |
| **SOLID — DIP** | `FillingController` depends on `IProximitySensor`, `IPump`, `IFlowMeter` interfaces — not concrete classes |
| **SOLID — ISP** | Separate `IProximitySensor`, `IPump`, `IFlowMeter`, `IHardwareDevice` interfaces — not one bloated interface |
| **Qt GUI with QCustomPlot** | `AquaFlowWindow` plots live dispensed volume with mouse-clickable buttons (Lec 4 ✅) |
| **Qt timer for GUI refresh only** | `refreshTimer_` used for window refresh, not for real-time timing — correct per Lec 4 |
| **CMake build system** | Present and working — mandatory per all lectures |
| **State machine (event-driven, not polling)** | `FillingController`: `SELECTING_SIZE → WAITING_FOR_CUP → CONFIRMING → FILLING → FILL_COMPLETE` |
| **Emergency stop < 150ms** | Proximity cleared → pump off in one 100ms tick ✅ |
| **Centralised Logger (no `std::cout` in drivers)** | `Logger` class; no driver touches `std::cout` ✅ |

---

## ⚠️ GAPS — Fixable before marking

### 1. GestureSensor: timerfd polling instead of INT pin interrupt (Lec 3 ⚠️)

**What the lecture says:**
> *"If you have a device which has non-blocking IO like I²C, you MUST also use a GPIO data-ready pin to wake up a thread. Make sure you have components which have a data-ready pin."*

**What you're doing:**
The APDS-9960 has an `INT` pin but it's not wired. Instead, `GestureSensor` uses a `timerfd` every 50ms to poll over I²C. The code even comments:
```
// The APDS-9960 INT pin is not wired; instead a timerfd fires every 50ms
```

**Risk:** The lecturer says timerfd is *"a last resort"* and explicitly doesn't want to see timers everywhere. A marker could penalise this.

**Fix (documentation):** Add a note in your ADR / README explaining *why* you chose timerfd over the INT pin (e.g., hardware constraint — pin not wired in your physical build, and 50ms latency is acceptable for cup detection). This turns a gap into a justified engineering decision.

---

### 2. SOLID — Open/Closed Principle not explicitly demonstrated (Lec marking ⚠️)

**What the lecture says:**
> *"Open/Closed: create a base class, then inherit to extend. Don't modify — extend."*

**What you have:** Your interfaces (`IProximitySensor` etc.) are pure abstract — good. But there's no concrete example of *extending* a base class to add functionality without modifying it.

**Fix (low effort):** In your README/ADR, point to the fact that `GestureSensor : public IHardwareDevice, public IProximitySensor` could be swapped for a mock sensor in tests without changing `FillingController`. That IS the open/closed principle in action — just needs to be stated explicitly.

---

### 3. Liskov Substitution — Not explicitly documented (Lec marking ⚠️)

**What the lecture says:**
> *"The base class interface must be flexible enough that the inherited class doesn't break it. Make callbacks future-proof."*

**Gap:** Your interfaces define callbacks with specific single-value returns (proximity bool, pump on/off). If you ever needed to return multiple readings, the interface would break. The lecturer flags this exact issue with his own example code.

**Fix (documentation):** Note in your ADR that you are aware of LSP and explain why your current interfaces are sufficient for a single-sensor dispenser use case. This is a *justified design decision*, not a flaw — just needs to be stated.

---

### 4. No Doxygen / doc-string coverage in all files (Lec 2 ⚠️)

**What the lecture says:**
> *"I would expect doc strings for Doxygen in there... describing what these different functions are doing. That's basically what I'm expecting from your projects."*

**Evidence:** `GestureSensor.h` and some other headers have Doxygen-style `/** @brief */` comments. But coverage may be inconsistent across all files.

**Fix:** Run a quick audit — make sure every public method in every header has at least a `/** @brief ... */` doc comment.

---

### 5. GitHub branching strategy (Assessment Criteria ⚠️)

**What the criteria says:**
> *"A1-A2: Professional use with regular commits, branching, merging"*
> *"C1-C3: Only master branch, shortcomings in commits"*

**Unknown status:** It's unclear if you used feature branches. If all work was done on `main`, this caps you at C for revision control.

**Fix:** Check `git log --oneline --graph`. If it's all one straight line on `main`, it's too late to retroactively branch — but you can document that you used commit messages as a substitute for branching in the README.

---

### 6. GitHub Issue Tracker not mentioned (Assessment Criteria ⚠️)

**What the criteria says:**
> *"Use of issue tracker"* — listed explicitly as a component of the 25% Project Management mark.

**Fix:** Even retrospectively, you can create a few closed GitHub Issues referencing your major milestones (e.g., "APDS-9960 gesture engine bug", "SOLID refactor", "Flow meter calibration"). This shows awareness of professional tooling.

---

### 7. GitHub Release tag (Assessment Criteria 🚨)

**What the criteria says:**
> *"Latest release from team's GitHub repository will be downloaded and marked on the deadline."*
> *"Team responsibility to create a release on GitHub by deadline."*

**Deadline was 20 April 2026, 9am.**

**Status unknown** — Did you create a GitHub Release (not just a commit) by the deadline? If not, the marker may not assess your latest code.

**Action:** Check GitHub → Releases tab immediately.

---

## ❌ NOT REQUIRED — Don't worry about these

| Topic | Why not needed |
|---|---|
| **Fast DDS** | Only needed if communicating between 2 Raspberry Pis — you have 1 |
| **FastCGI + NGINX** | Only needed for a public web dashboard — your Qt GUI fully satisfies the "plot on screen" requirement |
| **JavaScript frontend** | Qt is the equivalent and was the lecturer's primary example |

---

## 📊 Estimated Mark Impact (before fixes)

| Category | Weight | Estimate | Notes |
|---|---|---|---|
| Code Structure (SOLID) | 25% | **B1-B2** | Strong implementation, needs better SOLID documentation |
| Realtime Coding | 30% | **A3-A4** | `timerfd`, `libgpiod`, `atomic`, no `sleep()` — excellent |
| Revision Control / PM | 25% | **B3-C1** | 140 commits good, branching unknown, Issue tracker unknown |
| Promotion / Docs | 10% | **B1-B2** | Good GitHub, website, social media — video would push to A |
| Presentation | 10% | N/A | Not assessed here |

---

## 🔧 Priority Action List

1. **[ ] Check GitHub Release exists** — most critical
2. **[ ] Add GestureSensor timerfd justification to ADR** — turns a potential deduction into a documented decision
3. **[ ] Create GitHub Issues retrospectively** — 30 minutes work, boosts PM mark
4. **[ ] Add SOLID open/closed + LSP notes to README** — explicit documentation = A range
5. **[ ] Audit Doxygen coverage** — make sure every public method has `@brief`
6. **[ ] Check git branch history** — if only `main`, note it
