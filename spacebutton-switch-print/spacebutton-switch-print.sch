EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:wemos_mini
LIBS:spacebutton-switch-print-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R3
U 1 1 5A6A1CCA
P 4150 6200
F 0 "R3" V 4230 6200 50  0000 C CNN
F 1 "R" V 4150 6200 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4080 6200 50  0000 C CNN
F 3 "" H 4150 6200 50  0000 C CNN
	1    4150 6200
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5A6A1D97
P 4150 5550
F 0 "R2" V 4230 5550 50  0000 C CNN
F 1 "R" V 4150 5550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4080 5550 50  0000 C TNN
F 3 "" H 4150 5550 50  0000 C CNN
	1    4150 5550
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A6A1DD7
P 4150 5050
F 0 "R1" V 4230 5050 50  0000 C CNN
F 1 "R" V 4150 5050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4080 5050 50  0000 C CNN
F 3 "" H 4150 5050 50  0000 C CNN
	1    4150 5050
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 5A6A1F55
P 3650 5050
F 0 "D1" H 3650 5150 50  0000 C CNN
F 1 "RED" H 3650 4950 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 3650 5050 50  0000 C CNN
F 3 "" H 3650 5050 50  0000 C CNN
	1    3650 5050
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 5A6A1FE1
P 3650 5550
F 0 "D2" H 3650 5650 50  0000 C CNN
F 1 "YELLOW" H 3650 5450 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 3650 5550 50  0000 C CNN
F 3 "" H 3650 5550 50  0000 C CNN
	1    3650 5550
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5A6A201F
P 3650 6200
F 0 "D3" H 3650 6300 50  0000 C CNN
F 1 "GREEN" H 3650 6100 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 3650 6200 50  0000 C CNN
F 3 "" H 3650 6200 50  0000 C CNN
	1    3650 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 6200 3850 6200
Wire Wire Line
	3150 5050 3450 5050
Wire Wire Line
	4000 5550 3850 5550
Wire Wire Line
	3150 5550 3450 5550
Wire Wire Line
	4000 5050 3850 5050
Wire Wire Line
	3150 6200 3450 6200
$Comp
L SW_PUSH SW_TOGGLE1
U 1 1 5A6A2449
P 8250 5300
F 0 "SW_TOGGLE1" H 8400 5410 50  0000 C CNN
F 1 "SW_PUSH" H 8250 5220 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8250 5300 50  0000 C CNN
F 3 "" H 8250 5300 50  0000 C CNN
	1    8250 5300
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW_RESET1
U 1 1 5A8D928A
P 8250 5950
F 0 "SW_RESET1" H 8400 6060 50  0000 C CNN
F 1 "SW_PUSH" H 8250 5870 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8250 5950 50  0000 C CNN
F 3 "" H 8250 5950 50  0000 C CNN
	1    8250 5950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X05 RTC_DS1307_I2C1
U 1 1 5A8F2226
P 9650 2900
F 0 "RTC_DS1307_I2C1" H 9650 3200 50  0000 C CNN
F 1 "CONN_01X05" V 9750 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 9650 2900 50  0000 C CNN
F 3 "" H 9650 2900 50  0000 C CNN
	1    9650 2900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 DHT22
U 1 1 5A8F259F
P 9650 4050
F 0 "DHT22" H 9650 4300 50  0000 C CNN
F 1 "CONN_01X04" V 9750 4050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 9650 4050 50  0000 C CNN
F 3 "" H 9650 4050 50  0000 C CNN
	1    9650 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5550 4300 6050
Wire Wire Line
	4300 6050 6250 6050
Wire Wire Line
	4300 5050 4450 5050
Wire Wire Line
	4450 5050 4450 5900
Wire Wire Line
	4450 5900 6350 5900
Wire Wire Line
	5850 5450 5850 5700
Wire Wire Line
	5850 5700 7150 5700
Wire Wire Line
	7150 5700 7150 5950
Wire Wire Line
	7150 5950 7950 5950
Wire Wire Line
	6550 3900 9450 3900
Wire Wire Line
	6550 2800 6550 4450
Wire Wire Line
	9450 4000 6350 4000
Wire Wire Line
	6350 4000 6350 4450
Wire Wire Line
	6450 4200 9450 4200
Wire Wire Line
	6450 2700 6450 4450
Wire Wire Line
	8550 4350 8550 5950
Connection ~ 8550 5300
Wire Wire Line
	9450 2700 6450 2700
Wire Wire Line
	9450 2800 6550 2800
$Comp
L WeMos_mini U1
U 1 1 5A6A1AF3
P 6200 4950
F 0 "U1" H 6200 5450 60  0000 C CNN
F 1 "WeMos_mini" H 6200 4450 60  0000 C CNN
F 2 "wemos-d1-mini:wemos-d1-mini-with-pin-header" H 6750 4250 60  0000 C CNN
F 3 "" H 6750 4250 60  0000 C CNN
	1    6200 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 4350 8550 4350
Connection ~ 6450 4350
Wire Wire Line
	9450 2900 6250 2900
Wire Wire Line
	6250 2900 6250 4450
Wire Wire Line
	9450 3000 6150 3000
Wire Wire Line
	6150 3000 6150 4450
Wire Wire Line
	9450 3100 6050 3100
Wire Wire Line
	6050 3100 6050 4450
Wire Wire Line
	7950 5300 7050 5300
Wire Wire Line
	7050 5300 7050 5600
Wire Wire Line
	7050 5600 6450 5600
Wire Wire Line
	6450 5600 6450 5450
Wire Wire Line
	3150 4350 3150 6200
Connection ~ 3150 5050
Connection ~ 3150 5550
Connection ~ 6550 3900
Connection ~ 6450 4200
Wire Wire Line
	6350 5900 6350 5450
Wire Wire Line
	6250 6050 6250 5450
Wire Wire Line
	6150 6200 6150 5450
Wire Wire Line
	6150 6200 4300 6200
$EndSCHEMATC