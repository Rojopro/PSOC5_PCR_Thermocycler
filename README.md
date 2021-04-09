# Psoc5_PCR_Thermocycler
This project uses a PSOC5 to measure and control the heating of a PCR Chip conceived at ESIEE Paris' lab.
It can also be used to measure the temperature of a PCB trace.

Currently a work in progress (see To Do section)

## Presentation
Considering the present sanitary crisis, it is now mandatory to create systems capable of assisting health professionals in our struggle against Covid-19.
One of the means to do so for engineers is to conceive tools to facilitate early detection of contaminations, with easy to use and produce tests.
Thus this prototype was conceived as a mean to test the usability of localy conceived chips.

## Preview
![ModulePCR](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/ModulePCR.PNG)


## To Do
An auto-calibration function is needed, as resistance varies greatly between chips. Consider linearising the 25-70°C measures with 0°C, or use an exterior ambiant temperature measure to assume the resistor offset. Thermal coefficient may or may not need caibration as well.
Control Loop could use a bit more tuning.
Currently, software filter is disabled to avoid overflow (see commented lines in main.c).
