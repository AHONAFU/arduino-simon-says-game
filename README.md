# 🔴 🟢 🔵 Simon Says
### *A memory game built with Arduino Uno R3*

```
Press. Watch. Remember. Repeat.
```

---

## ✦ Overview

A hardware implementation of the classic **Simon Says** memory game — built from scratch using an Arduino Uno R3, breadboard components, and a 7-segment display. Each round, a randomized sequence of colored LEDs lights up. Your job? Recreate it — perfectly.

Miss a step, and you lose. Nail it, and the sequence grows longer.

---

## ⚙️ Hardware

| Component | Qty | Role |
|---|---|---|
| Arduino Uno R3 | 1 | Brain |
| LEDs (Red, Green, Blue) | 3 | Sequence display |
| Push Buttons | 3 | Player input |
| Piezo Buzzer | 1 | Audio feedback |
| 7-Segment Display | 1 | Stage / score tracker |
| Breadboard + Jumper Wires | — | Wiring |
| Resistors | — | LED & button protection |

---

## 🔌 Pin Map

| Pin | Component |
|---|---|
| `D5` | Blue LED |
| `D6` | Red LED |
| `D7` | Green LED |
| `D2` | Green Button |
| `D3` | Red Button |
| `D4` | Blue Button |
| `D8` | Buzzer |
| `D9–D12, A3–A5` | 7-Segment Display |

---

## 🎮 How to Play

1. **Power on** → startup LED chase animation plays
2. **Watch** the LED sequence carefully
3. **Press** the matching buttons in the exact same order
4. **Win** → green flash, sequence gets longer next round
5. **Lose** → red flash + buzzer tone

After losing, you're prompted to:
- 🟢 **Green Button** → Restart from Stage 0
- 🔴 **Red Button** → Watch the startup animation and stay at game over screen

> The 7-segment display always shows your current stage.

---

## 📈 Difficulty Scaling

The sequence starts at **3 inputs** and grows by 1 each stage:

```
Stage 0 → 3 inputs
Stage 1 → 4 inputs
Stage 2 → 5 inputs
...and so on
```

---

## 🚀 Getting Started

1. Clone this repo
   ```bash
   git clone https://github.com/yourusername/simon-says-arduino.git
   ```
2. Open `simon_says.ino` in the **Arduino IDE**
3. Wire components according to the pin map above
4. Upload to your **Arduino Uno R3**
5. Hit the reset button and play

---

## 📁 Project Structure

```
simon-says-arduino/
├── simon_says.ino     # Main game code
└── README.md
```

---

## 💡 Built With

- **Arduino IDE**
- **C++ (Arduino framework)**
- Pure hardware — no shields, no modules, no libraries

---

*Made with ☕ and too many jumper wires.*
