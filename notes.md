# Lab 2 Notes - Signal Generation and Capture

## What I did
Task 1
* write a basic memory component with SV and pre-load it with known contents
* design a signal generator by combining a counter with a ROM component
   * counter output is used as the address input
   * both counter and ROM is synchronised (connected to the same clock)

Task 2
* upgrade the ROM to a dual-port ROM
* generate two sinusoidal signals simultaneously (sine and cosine)

Task 3
* capture and store a audio signal using the microphone on Vbuddy and a RAM component
* read and write to a RAM component simultaneously
* use parameterisation to generalise designs for different address or data widths

## Notes
* avoid using binary subtraction
* beware that operations of input if done in the instantiation of module will only be run once
* instantiating module `.{int. sig name}({ext. sig name})`, depending on input/output of internal signal, the external signal will be used as input/output
