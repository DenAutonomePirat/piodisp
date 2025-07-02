# piodisp

This project contains PIO (Programmable I/O) programs and related code for display and data shifting applications on the Raspberry Pi 5. It uses a simple lookup table in `vfd.c` to drive a VFD (Vacuum Fluorescent Display) using MAX6921xx or similar drivers.

## Contents
- `clock.pio`: PIO assembly program for shifting data with side-set and clocking, suitable for driving shift registers or display logic.
- `vfd.c`: Lookup table and logic for segment mapping and VFD control.

## Hardware
- Raspberry Pi 5 (or compatible RP2040 board)
- VFD (Vacuum Fluorescent Display)
- MAX6921xx or similar shift register/driver IC

## Usage
1. Assemble the `.pio` file using `pioasm` to generate the corresponding header for C/C++ projects:
    https://wokwi.com/tools/pioasm
2. Include the generated header in your piolib project.
3. Use the provided C-SDK initialization function in your firmware to set up the PIO state machine.
4. Use the lookup table in `vfd.c` to convert display data to the correct bit pattern for the VFD.

## Notes
- Adjust pin numbers and clock dividers in the `.pio` and C code as needed for your hardware.
- See the comments in `clock.pio` for details on the program's operation.
- Refer to your VFD and driver datasheets for wiring and timing requirements.

## Example
![Example Output](https://github.com/DenAutonomePirat/piodisp/blob/main/output.png)