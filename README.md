# Psoc5-ResistorTemperature
This project uses a Psoc5 dev kit to calculate a known resistor temperature, typically from a PCB trace to be used for PCR Covid tests. 
An OLED screen module can be used via the I2C lines.
Currently, software filter is disabled to avoid overflow (see commented lines in main.c).
##/!\make sure you name the folder containing these files "PCR.cydsn" else it won't work /!\
