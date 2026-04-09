# GreHack 2025 — Hardware Challenges

Two hardware security challenges created for GreHack CTF 2025. (200+ participants)

---

## rtl_433 — RF Signal Analysis

### Objective
Introduce participants to basic radio signal analysis in a noisy, real-world RF environment and extract challenge-relevant messages from 433 MHz captures.

### Context
Short text phrases are transmitted by a 433 MHz transmitter controlled by an Arduino MKR WiFi 1010. The payloads are encrypted with a Vigenère cipher. The Vigenère key itself is transmitted in clear text somewhere in the captures.

The flag format is `GH{<key>}` — recover the key from the captures (it appears as a single plain-text token) and wrap it accordingly.

**Important:**
- The captures were recorded in a dense RF environment — many unrelated transmissions are present
- Only some bursts contain the challenge payloads or the plaintext key

### Repository structure
```
rtl_433/
├── chall/        # Challenge files (given to participants)
│   └── data/     # Solution script
└── ...           # Challenge construction (messy, don't panic)
```

---

## starting_hardware_com — Hardware Protocols

### Objective
Introduce three major hardware communication protocols through real signal captures made with a logic analyzer (PulseView/sigrok).

### Context
Three capture files are provided, each corresponding to a different protocol:
- **UART**
- **I²C**
- **SPI**

Each capture contains one part of the flag. The final flag is the concatenation of all three parts in order: `UART → I²C → SPI`.

### Repository structure
```
starting_hardware_com/
├── challenge/    # Challenge files (given to participants)
├── solve/        # One resolution method
└── ...           # Challenge construction
```

---

## Tools

- [rtl_433](https://github.com/merbanan/rtl_433) — RF signal decoder
- [PulseView / sigrok](https://sigrok.org/wiki/PulseView) — Logic analyzer software
- SDR receiver (RTL-SDR or HackRF)
