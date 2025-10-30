# Bluepath--Indoor-Bluetooth-tracking-System---Silicon-Lab-project-
# Indoor Bluetooth Tracking System – Basic Demo

This project demonstrates a **basic indoor Bluetooth Low Energy (BLE) tracking prototype** using the **Silicon Labs BRD2605A** board.

---

## Objective
To simulate an **indoor navigation system** using BLE beacons.  
Each beacon broadcasts a **unique UUID** and **location name**, which can be detected using the **EFR Connect mobile app**.

---

## Hardware Used
- Silicon Labs **BRD2605A** (EFR32BG22-based board)
- USB cable for flashing and power

---

##  Software Used
- **Simplicity Studio 6**
- **Bluetooth SDK**
- **EFR Connect App** (for Android/iOS)

---

## Steps to Run

1. Open **Simplicity Studio 6**.
2. Connect the **BRD2605A** board.
3. Create a new project using the *SoC - iBeacon* or *SoC - Empty* template.
4. Replace the `main.c` (or `app.c`) code with the one in this repository.
5. Click **Build → Flash to Device**.
6. Open the **EFR Connect App** → *Bluetooth Browser*.
7. You’ll see a device broadcasting as **BluePath-Beacon**.

---

## Output Example

**EFR Connect App Output:**
