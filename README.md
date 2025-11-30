# 🎮 Blackjack – C++ Console Game

A simple Blackjack game implemented in C++ as a school project.  
The goal is to demonstrate object-oriented thinking, card handling logic, randomization, and user interaction in the console.

---

## ✨ Features

- Full 52-card deck
- Random shuffle (no repeated cards)
- Dynamic Ace logic (1 or 11 depending on the score)
- Player actions: Hit / Stand
- Dealer draws until reaching at least 17 points
- Round result: Win / Lose / Push (Tie)
- Option to restart the game after each round

---

## 🛠️ Technologies

- C++17 (or newer)
- Standard Library features:
  - `<vector>` for card storage
  - `<algorithm>` for shuffling
  - `<ctime>` for random seed
  - Console input/output

---

## SCREANSHOOTS
<img width="202" height="108" alt="image" src="https://github.com/user-attachments/assets/a6f7ba71-5865-469b-a499-27e75558ec13" />
<img width="271" height="271" alt="image" src="https://github.com/user-attachments/assets/76b86698-c3bf-4a76-8e1a-9e59e8989095" />
<img width="282" height="285" alt="image" src="https://github.com/user-attachments/assets/4a793c54-12b1-4794-8207-8b51e6a63655" />

---
## ▶️ How to Build & Run

Compile using any C++ compiler:

```bash
g++ src/main.cpp -o blackjack
./blackjack

