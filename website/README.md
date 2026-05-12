# AquaFlow Website

This folder contains the static website for the AquaFlow project — a touchless water dispenser built from scratch.

## Files

| File | Description |
|------|-------------|
| `index.html` | Main webpage (single-page article) |
| `style.css` | All styling for the page |

---

## How to Open the Website

### Option 1 — Open directly in browser (quickest)

1. Navigate to this `website/` folder in File Explorer.
2. Double-click `index.html`.
3. It will open in your default browser as a `file://` URL.

> **Note:** This works fine for viewing. Some browser security policies may block certain features when using `file://`.

---

### Option 2 — Serve locally with Node.js (recommended)

This method serves the site over `http://localhost`, avoiding any `file://` restrictions.

**Requirements:** [Node.js](https://nodejs.org/) installed.

**Steps:**

1. Open a terminal (PowerShell or Command Prompt).
2. Navigate to this folder:
   ```powershell
   cd path\to\FlowFizzy\website
   ```
3. Start the server:
   ```powershell
   npx -y serve . -p 8080
   ```
4. Open your browser and go to:
   ```
   http://localhost:8080
   ```
5. To stop the server, press `Ctrl+C` in the terminal.

---

### Option 3 — Serve locally with Python

**Requirements:** [Python 3](https://www.python.org/) installed.

**Steps:**

1. Open a terminal and navigate to this folder:
   ```powershell
   cd path\to\FlowFizzy\website
   ```
2. Start the server:
   ```powershell
   python -m http.server 8080
   ```
3. Open your browser and go to:
   ```
   http://localhost:8080
   ```
4. To stop the server, press `Ctrl+C` in the terminal.
