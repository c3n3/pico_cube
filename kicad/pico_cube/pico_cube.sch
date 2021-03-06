EESchema Schematic File Version 4
EELAYER 30 0
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
L pico:PICO_RP2040 U1
U 1 1 6102B781
P 2700 3150
F 0 "U1" H 2675 4515 50  0000 C CNN
F 1 "PICO_RP2040" H 2675 4424 50  0000 C CNN
F 2 "generic:pico" H 2600 4600 50  0001 C CNN
F 3 "" H 2600 4600 50  0001 C CNN
	1    2700 3150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 6102DBE3
P 5100 2500
F 0 "U2" H 5100 3281 50  0000 C CNN
F 1 "74HC595" H 5100 3190 50  0000 C CNN
F 2 "generic:SN74HC595N" H 5100 2500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5100 2500 50  0001 C CNN
	1    5100 2500
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U7
U 1 1 61031959
P 6700 2500
F 0 "U7" H 6700 3281 50  0000 C CNN
F 1 "74HC595" H 6700 3190 50  0000 C CNN
F 2 "generic:SN74HC595N" H 6700 2500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 6700 2500 50  0001 C CNN
	1    6700 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male Vert1
U 1 1 6103970C
P 7050 4850
F 0 "Vert1" H 7022 4782 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7022 4873 50  0000 R CNN
F 2 "generic:pin" H 7050 4850 50  0001 C CNN
F 3 "~" H 7050 4850 50  0001 C CNN
	1    7050 4850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male Vert2
U 1 1 61040EC6
P 7050 5100
F 0 "Vert2" H 7022 5032 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7022 5123 50  0000 R CNN
F 2 "generic:pin" H 7050 5100 50  0001 C CNN
F 3 "~" H 7050 5100 50  0001 C CNN
	1    7050 5100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male Vert3
U 1 1 610410BB
P 7050 5350
F 0 "Vert3" H 7022 5282 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7022 5373 50  0000 R CNN
F 2 "generic:pin" H 7050 5350 50  0001 C CNN
F 3 "~" H 7050 5350 50  0001 C CNN
	1    7050 5350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male Vert4
U 1 1 61041363
P 7050 5600
F 0 "Vert4" H 7022 5532 50  0000 R CNN
F 1 "Conn_01x01_Male" H 7022 5623 50  0000 R CNN
F 2 "generic:pin" H 7050 5600 50  0001 C CNN
F 3 "~" H 7050 5600 50  0001 C CNN
	1    7050 5600
	-1   0    0    1   
$EndComp
$Comp
L generic:mosfet Fet1
U 1 1 6104E07B
P 5400 4300
F 0 "Fet1" V 5765 4288 50  0000 C CNN
F 1 "mosfet" V 5674 4288 50  0000 C CNN
F 2 "generic:mosfet" H 5400 4550 50  0001 C CNN
F 3 "" H 5400 4550 50  0001 C CNN
	1    5400 4300
	0    -1   -1   0   
$EndComp
$Comp
L generic:mosfet Fet2
U 1 1 6104EC43
P 5400 4950
F 0 "Fet2" V 5765 4938 50  0000 C CNN
F 1 "mosfet" V 5674 4938 50  0000 C CNN
F 2 "generic:mosfet" H 5400 5200 50  0001 C CNN
F 3 "" H 5400 5200 50  0001 C CNN
	1    5400 4950
	0    -1   -1   0   
$EndComp
$Comp
L generic:mosfet Fet4
U 1 1 6104F310
P 5400 6250
F 0 "Fet4" V 5765 6238 50  0000 C CNN
F 1 "mosfet" V 5674 6238 50  0000 C CNN
F 2 "generic:mosfet" H 5400 6500 50  0001 C CNN
F 3 "" H 5400 6500 50  0001 C CNN
	1    5400 6250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 4300 6550 4300
Wire Wire Line
	6550 4300 6550 4850
Wire Wire Line
	6550 4850 6850 4850
Wire Wire Line
	5600 4950 6850 4950
Wire Wire Line
	6850 4950 6850 5100
Wire Wire Line
	6250 5600 6250 5350
Wire Wire Line
	6250 5350 6850 5350
Wire Wire Line
	5600 6250 6850 6250
Wire Wire Line
	6850 6250 6850 5600
$Comp
L generic:mosfet Fet3
U 1 1 6104EFCE
P 5400 5600
F 0 "Fet3" V 5765 5588 50  0000 C CNN
F 1 "mosfet" V 5674 5588 50  0000 C CNN
F 2 "generic:mosfet" H 5400 5850 50  0001 C CNN
F 3 "" H 5400 5850 50  0001 C CNN
	1    5400 5600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 5600 6250 5600
Text GLabel 3300 3800 2    50   Input ~ 0
Clock
Text GLabel 3300 3700 2    50   Input ~ 0
Data
Text GLabel 3300 3500 2    50   Input ~ 0
Latch
Text GLabel 3300 2200 2    50   Input ~ 0
5V
Text GLabel 3300 2400 2    50   Input ~ 0
GND
Text GLabel 5600 4150 2    50   Input ~ 0
GND
Text GLabel 5600 4800 2    50   Input ~ 0
GND
Text GLabel 5600 5450 2    50   Input ~ 0
GND
Text GLabel 5600 6100 2    50   Input ~ 0
GND
Text GLabel 3300 2800 2    50   Input ~ 0
~OutputEnable
Text GLabel 4700 2700 0    50   Input ~ 0
~OutputEnable
Text GLabel 4700 2600 0    50   Input ~ 0
Latch
Text GLabel 4700 2300 0    50   Input ~ 0
Clock
Text GLabel 4700 2400 0    50   Input ~ 0
~OutputClear
Text GLabel 3300 3000 2    50   Input ~ 0
~OutputClear
Text GLabel 6300 2700 0    50   Input ~ 0
~OutputEnable
Text GLabel 6300 2600 0    50   Input ~ 0
Latch
Text GLabel 6300 2300 0    50   Input ~ 0
Clock
Text GLabel 6300 2400 0    50   Input ~ 0
~OutputClear
Text GLabel 4700 2100 0    50   Input ~ 0
Data
Wire Wire Line
	5500 3000 5750 3000
Wire Wire Line
	5750 3000 5750 2100
Wire Wire Line
	5750 2100 6300 2100
Text GLabel 2050 2200 0    50   Input ~ 0
Layer0
Text GLabel 2050 2300 0    50   Input ~ 0
Layer1
Text GLabel 2050 2500 0    50   Input ~ 0
Layer2
Text GLabel 2050 2600 0    50   Input ~ 0
Layer3
Text GLabel 5600 4450 2    50   Input ~ 0
Layer0
Text GLabel 5600 5100 2    50   Input ~ 0
Layer1
Text GLabel 5600 5750 2    50   Input ~ 0
Layer2
Text GLabel 5600 6400 2    50   Input ~ 0
Layer3
$Comp
L generic:4x4 U3
U 1 1 6108B523
P 3400 5050
F 0 "U3" H 3400 5515 50  0000 C CNN
F 1 "4x4" H 3400 5424 50  0000 C CNN
F 2 "generic:4x4" H 3400 5400 50  0001 C CNN
F 3 "" H 3400 5400 50  0001 C CNN
	1    3400 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 6108CB0B
P 3900 4850
F 0 "R9" V 3693 4850 50  0000 C CNN
F 1 "R" V 3784 4850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 4850 50  0001 C CNN
F 3 "~" H 3900 4850 50  0001 C CNN
	1    3900 4850
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 6108D9F1
P 3900 4950
F 0 "R10" V 3693 4950 50  0000 C CNN
F 1 "R" V 3784 4950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 4950 50  0001 C CNN
F 3 "~" H 3900 4950 50  0001 C CNN
	1    3900 4950
	0    1    1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 6108DC3F
P 3900 5050
F 0 "R11" V 3693 5050 50  0000 C CNN
F 1 "R" V 3784 5050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5050 50  0001 C CNN
F 3 "~" H 3900 5050 50  0001 C CNN
	1    3900 5050
	0    1    1    0   
$EndComp
$Comp
L Device:R R12
U 1 1 6108DEC8
P 3900 5150
F 0 "R12" V 3693 5150 50  0000 C CNN
F 1 "R" V 3784 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5150 50  0001 C CNN
F 3 "~" H 3900 5150 50  0001 C CNN
	1    3900 5150
	0    1    1    0   
$EndComp
$Comp
L Device:R R13
U 1 1 6108E162
P 3900 5250
F 0 "R13" V 3693 5250 50  0000 C CNN
F 1 "R" V 3784 5250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5250 50  0001 C CNN
F 3 "~" H 3900 5250 50  0001 C CNN
	1    3900 5250
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 6108E42D
P 3900 5350
F 0 "R14" V 3693 5350 50  0000 C CNN
F 1 "R" V 3784 5350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5350 50  0001 C CNN
F 3 "~" H 3900 5350 50  0001 C CNN
	1    3900 5350
	0    1    1    0   
$EndComp
$Comp
L Device:R R15
U 1 1 6108E777
P 3900 5450
F 0 "R15" V 3693 5450 50  0000 C CNN
F 1 "R" V 3784 5450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5450 50  0001 C CNN
F 3 "~" H 3900 5450 50  0001 C CNN
	1    3900 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R R16
U 1 1 6108E9AD
P 3900 5550
F 0 "R16" V 3693 5550 50  0000 C CNN
F 1 "R" V 3784 5550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3830 5550 50  0001 C CNN
F 3 "~" H 3900 5550 50  0001 C CNN
	1    3900 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 6108ED09
P 2900 4850
F 0 "R1" V 2693 4850 50  0000 C CNN
F 1 "R" V 2784 4850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 4850 50  0001 C CNN
F 3 "~" H 2900 4850 50  0001 C CNN
	1    2900 4850
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 6108EF67
P 2900 4950
F 0 "R2" V 2693 4950 50  0000 C CNN
F 1 "R" V 2784 4950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 4950 50  0001 C CNN
F 3 "~" H 2900 4950 50  0001 C CNN
	1    2900 4950
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 6108F258
P 2900 5050
F 0 "R3" V 2693 5050 50  0000 C CNN
F 1 "R" V 2784 5050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5050 50  0001 C CNN
F 3 "~" H 2900 5050 50  0001 C CNN
	1    2900 5050
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 6108F517
P 2900 5150
F 0 "R4" V 2693 5150 50  0000 C CNN
F 1 "R" V 2784 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5150 50  0001 C CNN
F 3 "~" H 2900 5150 50  0001 C CNN
	1    2900 5150
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 61090FC3
P 2900 5250
F 0 "R5" V 2693 5250 50  0000 C CNN
F 1 "R" V 2784 5250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5250 50  0001 C CNN
F 3 "~" H 2900 5250 50  0001 C CNN
	1    2900 5250
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 610912CE
P 2900 5350
F 0 "R6" V 2693 5350 50  0000 C CNN
F 1 "R" V 2784 5350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5350 50  0001 C CNN
F 3 "~" H 2900 5350 50  0001 C CNN
	1    2900 5350
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 61091686
P 2900 5450
F 0 "R7" V 2693 5450 50  0000 C CNN
F 1 "R" V 2784 5450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5450 50  0001 C CNN
F 3 "~" H 2900 5450 50  0001 C CNN
	1    2900 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 6109198A
P 2900 5550
F 0 "R8" V 2693 5550 50  0000 C CNN
F 1 "R" V 2784 5550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2830 5550 50  0001 C CNN
F 3 "~" H 2900 5550 50  0001 C CNN
	1    2900 5550
	0    1    1    0   
$EndComp
Text GLabel 4050 4850 2    50   Input ~ 0
led0
Text GLabel 4050 4950 2    50   Input ~ 0
led1
Text GLabel 4050 5050 2    50   Input ~ 0
led2
Text GLabel 4050 5150 2    50   Input ~ 0
led3
Text GLabel 4050 5250 2    50   Input ~ 0
led4
Text GLabel 4050 5350 2    50   Input ~ 0
led5
Text GLabel 4050 5450 2    50   Input ~ 0
led6
Text GLabel 4050 5550 2    50   Input ~ 0
led7
Text GLabel 2750 4850 0    50   Input ~ 0
led8
Text GLabel 2750 4950 0    50   Input ~ 0
led9
Text GLabel 2750 5050 0    50   Input ~ 0
led10
Text GLabel 2750 5150 0    50   Input ~ 0
led11
Text GLabel 2750 5250 0    50   Input ~ 0
led12
Text GLabel 2750 5350 0    50   Input ~ 0
led13
Text GLabel 2750 5450 0    50   Input ~ 0
led14
Text GLabel 2750 5550 0    50   Input ~ 0
led15
Text GLabel 5500 2100 2    50   Input ~ 0
led0
Text GLabel 5500 2200 2    50   Input ~ 0
led1
Text GLabel 5500 2300 2    50   Input ~ 0
led2
Text GLabel 5500 2400 2    50   Input ~ 0
led3
Text GLabel 5500 2500 2    50   Input ~ 0
led4
Text GLabel 5500 2600 2    50   Input ~ 0
led5
Text GLabel 5500 2700 2    50   Input ~ 0
led6
Text GLabel 5500 2800 2    50   Input ~ 0
led7
Text GLabel 7100 2100 2    50   Input ~ 0
led8
Text GLabel 7100 2200 2    50   Input ~ 0
led9
Text GLabel 7100 2300 2    50   Input ~ 0
led10
Text GLabel 7100 2400 2    50   Input ~ 0
led11
Text GLabel 7100 2500 2    50   Input ~ 0
led12
Text GLabel 7100 2600 2    50   Input ~ 0
led13
Text GLabel 7100 2700 2    50   Input ~ 0
led14
Text GLabel 7100 2800 2    50   Input ~ 0
led15
NoConn ~ 7100 3000
Text GLabel 5100 1900 1    50   Input ~ 0
5V
Text GLabel 6700 1900 1    50   Input ~ 0
5V
Text GLabel 5100 3200 3    50   Input ~ 0
GND
Text GLabel 6700 3200 3    50   Input ~ 0
GND
NoConn ~ 3300 3100
NoConn ~ 3300 3200
NoConn ~ 3300 3300
NoConn ~ 3300 3400
NoConn ~ 3300 3600
NoConn ~ 3300 3900
NoConn ~ 3300 4000
NoConn ~ 3300 4100
NoConn ~ 3300 2900
NoConn ~ 3300 2700
NoConn ~ 3300 2600
NoConn ~ 3300 2500
NoConn ~ 3300 2300
NoConn ~ 2050 2400
$Comp
L Connector:Conn_01x15_Female J1
U 1 1 61026A85
P 1850 3400
F 0 "J1" H 1742 2475 50  0000 C CNN
F 1 "extra" H 1742 2566 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x15_P2.54mm_Vertical" H 1850 3400 50  0001 C CNN
F 3 "~" H 1850 3400 50  0001 C CNN
	1    1850 3400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 610317D5
P 3900 2050
F 0 "J2" H 3928 2026 50  0000 L CNN
F 1 "Conn_01x02_Female" H 3928 1935 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3900 2050 50  0001 C CNN
F 3 "~" H 3900 2050 50  0001 C CNN
	1    3900 2050
	1    0    0    -1  
$EndComp
Text GLabel 3700 2050 0    50   Input ~ 0
5V
Text GLabel 3700 2150 0    50   Input ~ 0
GND
$EndSCHEMATC
