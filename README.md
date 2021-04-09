# Psoc5_PCR_Thermocycler
This project uses a PSOC5 to measure and control the heating of a PCR Chip conceived at ESIEE Paris' lab.
It can also be used to measure the temperature of a PCB trace.

Currently a work in progress (see To Do section)

## Presentation
Considering the present sanitary crisis, it is now mandatory to create systems capable of assisting health professionals in our struggle against Covid-19.
One of the means to do so for engineers is to conceive tools to facilitate early detection of contaminations, wich are easy to use and reliable.
Thus this prototype was conceived as a mean to test the usability of localy conceived chips.

## Preview
### Actual Prototype :
![ModulePCR](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/ModulePCR.PNG)

## Theory
Considering the Resistivity formulae :

![Math](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/Math.PNG)

We see that we can deduce a resistor's temperature knowing its value, materials and dimensions.
Considering our fabrication process and the use of gold tracks, we get these parameters :

![MathVal](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/MathVal.PNG)

These will require chipt-to-chip tuning (see To Do section)

## Chip Fabrication
Using the Photoresist method, we produced a heating and sensing chip to be used in PCR :

https://en.wikipedia.org/wiki/Photoresist

![ChipFab](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/ChipFab.PNG)

Thus giving us the result below :

![Chip](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/Chip.PNG)

## Model
To use our chip we designed this model :

![Model](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/PsocProfil.PNG)

* It consist mainly of an IDAC set to 1mA fed to the measurement resistor of the chip. A 20bit Delta-Sigma is then used to measure the voltage accross it, which return the resistance value knowing the current.
* The heating element is controled via a 16bit PWM fed to a BJT.
* Calibration being of the utmost importance, a precise un-heated resistor is used to compensate the IDAC tendancy to drift with temperature.
* USB and I2C modules are used for HMI and logging.
* Software Filter can be used to soften the thermal noise the adc might get.
* The PCR temperature and duration steps are controlled via a software Switch-case for ease of update.

### Result

The control loop results are as follow :

![AsservissementModulePCR](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/Asservissement.PNG)

We can see the temperature precision is top notch :

![AsservissementQ](https://github.com/Rojopro/PSOC5_PCR_Thermocycler/blob/main/Doc/AsservissementQ.PNG)

## To Do
* An auto-calibration function is needed, as resistance varies greatly between chips. Consider linearising the 25-70°C measures with 0°C, or use an exterior ambiant temperature measure to assume the resistance offset. Thermal coefficient may or may not need caibration as well.
* Control Loop could use a bit more tuning (faster and/or less overshoot).
* Currently, software filter is disabled to avoid overflow (see commented lines in main.c).
* Find a way to put disposable and thermally-conductive recipient in contact with the chip for an actual test.
* Calibrating the heating offset of regulation() according to the lowest T set instead of hardcoding it.
* PCR should be able to attain and maintain 4°C after the end of its many cycles to inactivate the polymerase component.
* Consider adding a debouncer to the switch if needed
