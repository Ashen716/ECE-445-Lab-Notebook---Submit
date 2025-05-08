# ECE 445 Lab Notebook

# Anthony Shen Worklog

- [2/3/2025: Group Project Idea Discussion](#232025-group-project-idea-discussion) — Initial project selection and roles
- [2/5/2025: Battlebot Project Approval Research](#252025-battlebot-project-approval-research) — Bot weapon types and strategy
- [2/12/2025: Research Motors and Batteries](#2122025-research-motors-and-batteries) — Drive and lift motor, battery selection
- [2/17/2025: Project Proposal](#2172025-project-proposal) — Concept CAD and block diagram
- [2/19/2025: Design Review](#2192025-design-review) — Weight concerns identified
- [2/24/2025: Full Robot CAD Version 1](#2242025-full-robot-cad-version-1) — Initial CAD and part selection
- [2/25/2025: Full Robot CAD Version 2](#2252025-full-robot-cad-version-2) — Manufacturability improvements
- [2/26/2025: Full Robot CAD Version 3](#2262025-full-robot-cad-version-3) — Weight reduction and design improvements
- [3/7/2025: Breadboard Prototyping](#372025-breadboard-prototyping) — H-Bridge and bluetooth tests
- [3/15/2025: Full Robot CAD Version 4](#3152025-full-robot-cad-version-4) — Stability improvements
- [3/25/2025: Power System Test](#3252025-power-system-test) — First PCB voltage test
- [3/26/2025: STM 32 Programming Shutoff Attempt](#3262025-stm-32-programming-shutoff-attempt) — Emergency stop coding issues
- [3/31/2025: ESP 32 Programming](#3312025-esp-32-programming) — Full switch to ESP32 and web control
- [4/1/2025: Print Robot CAD Version 4 and Weapons System Test](#412025-print-robot-cad-version-4-and-weapons-system-test) — Printed version testing
- [4/21/2025: Solder and Test PCB](#4212025-solder-and-test-pcb) — Final PCB soldered and tested
- [4/24/2025: Power System Heat Issue and Solder Backup PCBS](#4242025-power-system-heat-issue-and-solder-backup-pcbs) — LDO heating issue and backup boards
- [4/25/2025: Full Robot CAD Version 5](#4252025-full-robot-cad-version-5) — Final CAD improvements
- [4/26/2025: 3D Print Robot Version 5](#4262025-3d-print-robot-version-5) — Shaft redesign for strength
- [4/27/2025: Final Testing and Spur Gearbox on Lifter Motor Sheered](#4272025-final-testing-and-spur-gearbox-on-lifter-motor-sheered) — Final R/V and gearbox failure


# Week 2/3/2025

## 2/3/2025: Group Project Idea Disscussion
From the initial idea posts, the only one that was viable in terms of uniqueness and complexity was my coffee bean dosing machine. Some additional ideas that seemed interesting was a battlebot and a wildfire detection system. The coffee bean dosing machine while interesting to me was not interesting to the rest of the group. The wildfire detection system, while very applicatble in light of the California wildfires, has already a commerical solution similar to our proposed idea. As a result we ultimatly decided to pursue a battlebot project.

We also plan on dividing the work between software, mechancial, and electrical. I will be in charge of the mechancial work, Batu will be in charge of the software, and Praman will be in charge of the electrical work.

## 2/5/2025: Battlebot Project Approval Research
There are many types of battlebots that compete at all levels. This includes the vertical spinner, horizontal spinner, fullbody spinner, hammer, flipper, and lifter robots. Some examples from the higest level of battlebots competetition are included below.

Weapon Example In Battlebots
* Vertical Spinner: Bite Force
* Horizontal Spinner: Tombstone
* Fullbody Spinner: GigaByte
* Hammer: Blacksmith
* Flipper: Hydra
* Lifter: Deadlift

In the highest level of competition, the meta is a vertical spinner due to its ability to deal a lot of damage while also remaining quite stable. This is because when the vertical spinner hits the enemy, it pushes the robot towards the ground while pushing the enemy robot into the air. The horizontal spinner and fullbody spinner, while deals a lot of damage, has the disadvantage of throwing itself into the side of the arena causeing a lot of damage to both the enemy and itself. Finally there is the lifter and flipper robots that may not do as much damage when compared to the 3 previous options, is still competitive with good driving and controlling the enemey by preventing them from effectivly attacking.

Ultimatly we decided to pursue a control robot similar to a flipper/lifter robot. This decision was influenced by the design restrictions imposed with a 3D printed 2 lbs. antweight battlebot. Because of the low weight limit and restriction on the use of metal for offensive purposes, we believed that kinetic weapons like the spinners would not be as effective as the highest weight class. A flipper or a lifter has the ability to control the match and potential disable the robot if the enemy does not have a self righting mechanism.

From preliminary research, the key components of the project will be a power system, drivetrain system, weapon system, and a control system. The power system will utilize a 3s LiPo battery because of its ability to provide a lot of current and the common 12 V that most motors will use. The drive train system will utlize 2 motors to drive 2 independent wheels on both sides of the robot (shown below in the robot copper head). This will leave the front of the robot to drag on the floor and allow it to more easily get underneath enemy robots and lift them up. For the weapons system, we plan to use a 2 prong system, the bottom prong to get under the enemy and lift them up, and a top prong that will prevent the enemy from escaping by clamping them down. Finally for the control system, we plan to use either the ESP 32 or the STM 32. While I prefer the ESP 32 due to my previous expierence and its integrated WiFi, my groupmate has expience with the STM 32 and believes integrating bluetooth would be easy. We chose to use the STM 32 because of its better real time performance when compared to the ESP 32.

Copperhead: ![image](https://github.com/user-attachments/assets/cbf01d67-a9e5-4046-adc9-25376a3a8eb5)


# Week 2/10/2025

## 2/12/2025: Research Motors and Batteries
Key Mechancial Requirments:
1) The battlebot needs to travel 10 ft/s
2) The battlebot needs to lift at least 2 lbs from 6 inches away
3) Battery with sufficient current rating and light weight

Feasible Drive Motor: https://www.servocity.com/970-rpm-econ-gear-motor/
* Wheel Circumference (inches) = pi * Diameter (inches) = pi * 3 = 9.42
* Desired RPS = Desired Speed (inches per second) / Wheel Circumference (inches) = 120 / 9.42 = 12.6
* Desired RPM = Desried RPS / 60 = 12.6 * 60 = 756

Meets Desired RPM

Feasible Lift Motor: https://www.servocity.com/56-rpm-econ-gear-motor/
* Load Torque (ft-lbs) = Estimated Arm Length (ft) * Enemy Robot Weight (lbs) = 0.5 * 2 = 1

Meets Desired Torque

Feasible 3S LiPo: https://zeeebattery.com/collections/zeee-3s-lipo-battery/products/zeee-3s-2200mah-lipo-battery-11-1v-50c-xt60-plug
* Estimated Current (A) = Motor Stall Current (A) + Micro Controller Current (A) + Motor Controller Current (A) = 3(4) + 0.1 + 0.3 = 12.5
* Max Current Supplied By Battery (Ah) = Battery Capacity (Ah) * Battery Rating = 2.2 * 50 = 110

Meets Worse Case Current Load

# Week 2/17/2025

## 2/17/2025: Project Proposal
I created a quick box CAD of the robot idea to get a feel of the dimensions that we will be working with: ![image](https://github.com/user-attachments/assets/bcedc996-cc89-4a2f-86e9-bb8fcfcab1a5)

The top prong of the robot will hold the enemy robot within our prongs, while the bottom prong will get underneath the enemy and lift the robot up. Currently this configuration is the maximum size that the robot can use within the 13" x 13" restriction. However smaller prongs can be fielded depending on the enemy robot configuration. These prongs can be driven by either pnematics or by motors, but in this competition pnematics would not be practical. An onboard compressor is quite heavy, so the alternative is a precharged tank, but this would limit the number of acctuations. 

From the current research I created a block diagram of the systems on the robot and how they will connect with each other: ![image](https://github.com/user-attachments/assets/d4269410-3f4e-4bcc-a4f1-0148d6ea9676)

One of the main points of this project is the 3D printing aspect. From previous expierence I narrowed down the choice of material to PETG or ABS because both are known for their strength properties when compared to the standard PLA. Ultimatly I decided on ABS because it has similar strength while being less dense then PETG with the tradeoff of being more difficult to print (prone to warping). The lab has a Bambu Labs X1 Carbon which is currently the best enthusiast grade printer that has many features that make printing abs less difficult (heated bed, heated chamber, etc...).

## 2/19/2025: Design Review
After the design review, some design concerns or key areas to keep in mind were disscussed. The first is the weight restriction of the robot. While the individual components such as motors, motor hubs, and battery add up to within the weight limit, it does not account for the weight of the 3D printed robot. I will need to perform some weight simulations as when I iterate to a version of the robot that seems resonabley thought out.

# Week 2/24/2025

## 2/24/2025: Full Robot CAD Version 1
The first version fully parted out CAD:

![image](https://github.com/user-attachments/assets/9555044d-25f8-4c27-8e6d-05939eacb7c3)

Parts List:
* Drive Motor: https://www.servocity.com/970-rpm-econ-gear-motor/
* Lift Motor: https://www.servocity.com/56-rpm-econ-gear-motor/
* 4mm D-Shaft Hub: https://www.servocity.com/1314-series-steel-set-screw-hub-4mm-bore/
* 48T Gear: https://www.servocity.com/2302-series-aluminum-mod-0-8-hub-mount-gear-14mm-bore-48-tooth/
* 3/8" Flanged Hex Bearing: https://www.andymark.com/products/0-375-in-hex-id-7-8-in-od-sealed-flanged-bearing-fr62rs-hex
* 2-7/8" Wheels: https://banebots.com/banebots-wheel-2-7-8-x-0-8-hub-mount-40a-orange/

Many of my parts choices were influenced by my previous expierence in FRC and FTC.

The weapons system needed to rotate on the same axis but not nesscarily the same direction, for 1 set of prongs, the axle served as a live axle, and the second set it served as a dead axle. In the wheel and lifting prongs, the power is transferred over a set of gears rather then direct driving in order to protect the motor in the event of impact. The gears are less fragile and will be able to take more abuse from impacts. 

![image](https://github.com/user-attachments/assets/b29d732f-10fd-4720-a1f0-43edbae7fdad)

## 2/25/2025: Full Robot CAD Version 2
![image](https://github.com/user-attachments/assets/9a654af2-00e6-4773-8b3b-c0fce600a0bd)

In the second version, the overall structure remained the same, however some tweaks were made for manufacturability. The first is the use of a hex shaft with holes that can be threaded and a flaged bolt can be put in to keep the bearing constrained to the shaft. The second as the the pannels of the boxes are split so that they can be fit within the build volume of the 3D printer available to us. 

After assigning materials and custom weights to each part that was provided to the manufacturer, the weight of the robot was significantly overweight.

Potential Ways to Reduce Weight:
* 3D Printed Gears or Direct Drive
* Changing to smaller bearing
* Change from 1 to 2 Prongs
* Change to weaker drivetrain motors
* Change robot design (full shell vs plate and spaces)
* Change to lighter wheel

## 2/26/2025: Full Robot CAD Version 3
All potential ideas were implemented in order to reduce the weight of the build. The main reduction came from reducing the weight associated with metal COTS parts. This meant finding lighter alternatives or reducing the amount used. Overall the resulting robot weight simulation was within specification.

![image](https://github.com/user-attachments/assets/18502e8f-fc6b-4dd0-9329-326e9770e9c5)

New Parts List:
* New Drive Motor: https://www.servocity.com/508-rpm-mini-econ-gear-motor/
* 3/8" Radial Bearing: https://wcproducts.com/collections/cnc-hardware/products/ball-bearings
* 3" 50A Wheel: https://www.andymark.com/products/compliant-wheels

From this robot design, however at this point in the robot design I am still not completely happy with the design. The robot seemed to be unstable because of the center of gravity was directly over the axle rather than in front of it. This meant that when driving the robot would rock back and forth. To solve this the wheels of the robot will need to be moved further back. The tradeoff for more stability will mean that part of the wheel will be exposed to the enemy weapons.

In addition I removed pockets of material from the robot to reduce the wieght of the 3D printed components by about half.

# Week 3/3/2025

## 3/7/2025: Breadboard Prototyping
![image](https://github.com/user-attachments/assets/e19d0507-7c0a-47b3-abbb-449565b7dd8a)

L298N Data Sheet: https://www.st.com/resource/en/datasheet/l298.pdf
L298N Setup Example: https://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf
LP295X LDO Data Sheet: [Link](https://www.ti.com/lit/ds/symlink/lp2950.pdf?ts=1745699658873&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FLP2950%253Futm_source%253Dgoogle%2526utm_medium%253Dcpc%2526utm_campaign%253Dapp-lp-null-44700045336317407_prodfolderdynamic-cpc-pf-google-ww_en_int%2526utm_content%253Dprodfolddynamic%2526ds_k%253DDYNAMIC+SEARCH+ADS%2526DCM%253Dyes%2526gad_source%253D1%2526gbraid%253D0AAAAAC068F3PFgQ9fDrVIpsEHAg__eOSH%2526gclid%253DCj0KCQjwiLLABhCEARIsAJYS6undjGNkoo3DvvPmXcUwaHdccSHN0LngsK56F55CCfDEccTkZUecDKAaAuHMEALw_wcB%2526gclsrc%253Daw.ds)

To help the electrical team, I worked to setup and test the L298N H-Bridge and create a small wireless test program that would interface the STM 32 using the HC-05 bluetooth module. The schematic above is what I designed and tested. In this prototyping session I successfully verfied the creation of varying PWM signal using STM 32 through the use of the analog output pins. I was able to create a serial bluetooth connection from the HC-05 and send the data to the STM 32 using serial TX and RX pins. 

We had difficulties finding a serial bluetooth terminal that would work on PC. We were still able to remotely control the motor using a serial arduino terminal (https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en_US). This could mean difficulties creating a custom interface for more control of the robot.

Another concern is the current limit of the L298N, the motor controller can supply sufficient stall current to the drive motors (2 A), but it will not be able to safely supply the lift motor stall current (4 A). We may need to look into putting multiple L298N in parallel or even different motor controllers.

The last concern is with the power system, while testing on the breadboard the voltage seems to change depending on the load, fluctuating between 2.5v and 4.5v. This may be a concern, but we believe that this is the result of the high resistance at the input and output of the LDO from not using SMD capacitors and the breadboard itself. We will need to test more on the PCB.

# Week 3/10/2025

## 3/15/2025: Full Robot CAD Version 4
![image](https://github.com/user-attachments/assets/d78d1217-3f07-4f28-b1dc-ca43050417e2)

I worked to decrease the height of the overall robot and shifted the wheels of the robot all the way to the back. I also decided to direct the drive the robot and remove the gear coupling to reduce the weight further so that the infill of the 3D printed robot could be increased. I believe the tradeoff is worth it as the 3D printed shaft of the robot is weaker then the gearbox on the motor.

# Week 3/24/2025

## 3/25/2025: Power System Test
Today our first PCB came in with the power system on board. We tested the LP295X, both the 3.3v and 5v variants and the results helped relieve our concerns with unstable voltages. The problem from the breadboard is resolved.

## 3/26/2025: STM 32 Programming Shutoff Attempt
Today we attempted to complete our last requirement with the control system. That is the emergency shutoff of the robot motors whenever there is a connection loss within 500ms of that connection loss. We hit a significant road block and have not been able to program the shutoff into the STM 32. 

On the STM 32 and HC-05 it seems that we are not able to constantly check for the number of active connections to the bluetooth device. In this case we need to create a "heart beat" mechanism where the device controlling the STM 32 constantly sends a signal every so often (500 ms or faster in this case) to check for a connection. Before we were able to receieve data from the serial terminal and translate it into a motor input, however the customizability of the terminal is quite limited and are not able to implement it in this case. Our inexpierence in using the bluetooth protocal prevents us from creating a custom app that would accomplish this task.

There are 2 alternatives, figure out how to properly use serial bluetooth, or switch the the ESP 32. Because of my previous expierence in using the ESP 32, I believe that this is the best option. However my groupmate has concerns regarding the real time performance of the ESP 32 when compared to the STM 32. I believe that this trade off is negligable in our application and even worth it if we are able to at least program the minimum requirements.

# Week 3/31/2025

## 3/31/2025: ESP 32 Programming 
![image](https://github.com/user-attachments/assets/c54a8be6-a572-4f92-b18b-a213ce5dcea6)

Because of the limited time left and a need to get in a viable PCB I decided to go ahead and make the switch to the ESP 32 and was able to program all features that was required using the ESP 32 to prove that the switch is worth it. The switch from the STM 32 to the ESP 32 also meant that the wireless communication protocal was now through Wifi instead.

The wireless communication is done by creating an access point on the ESP 32 and then creating a custom webserver that can take inputs. This method was effective in allowing both the computer and phone to control the robot. In addition there was no noticable latency or distance tradeoff compared to the STM 32 + HC05.

Some additional features that I more easily tested is the current sens of the motor controller. Hooking a 1 ohm resistor to the current sens output of the L298N I am able to measure the current the motor controller is drawing. While this feature is not within our specification, it can be intresting to expierement and use as a limit switch or be an auto motor shutoff in case of stall. The limit switch function is particularly useful for the lifter arm. Currently we plan to just visually check if our arms reach the limits of the range of motion because we did not have weight allocation to implement limit switches. However if we exploit the increase in current under stall condition, we can check whenever the lift motor has reached the end of its motion.

ESP 32 S3 Wroom 2 Datasheet: https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/index.html

## 4/1/2025: Print Robot CAD Version 4 and Weapons System Test
![image](https://github.com/user-attachments/assets/75a4b9e7-d553-4469-817e-fbde3b77e457)

This is the first version of the robot that was printed and while majority of it was good, there was an issue with the way the end of the drivetrain was held together. Pulling from my previous gearbox designing expierence, I constrained the axle in by clamping the shaft between 2 bearings. However previously the gearboxes I designed were from aluminum and thus much more rigid when compared to 3D printed plastic.

In this case, if the end of the plate was hit at the right angle, the plate could bend and the shaft of the wheel could slip out of the bearing and jam. This will need to be changed by locking the axle into the shaft and the bearing into the plate (currently the bearing is friction fit and also held in by the clamping of the assmbly).

Lifter Torque Test Procedures:
1) Atach 2 hammers to the lifter prongs. These each weigh 1 lb and will simulate the maximum weight of the enemy robot.
2) Actuate the lifter arm and record the current draw from benchtop power supply, and measure the height of the arm position
3) Connect more bench top power supplies in order to increase the current supply. Each have a limit of 1 A

Lifter Torque Test:
| Attempt | Height Achieved  | Current Draw |
| --- | --- | --- |
| 1 | 1.2" | 1 A |
| 2 | 1.1" | 1 A |
| 3 | 3.8" | 2 A |
| 4 | 3.5" | 2 A |
| 5 | 3.6" | 2 A |

Lifter Deployment Time Test Procdures:
1) Attach 2 hammers to the lifter prongs.
2) Acctuate the lifter arm and record time it takes to lift 2 inches off the ground

Lifter Deployment Time:
| Attempt | Time |
| --- | --- | 
| 1 | 0.82 Seconds |
| 2 | 0.91 Seconds |
| 3 | 0.76 Seconds |
| 4 | 0.88 Seconds |
| 5 | 0.84 Seconds |

Self-Right Test Procedure:
1) Flip Robot Upsidedown
2) Acuate Arm
3) Check if Robot is self righted

Self-Right Test:
| Attempt | Time |
| --- | --- | 
| 1 | Success |
| 2 | Success |
| 3 | Success |
| 4 | Success |
| 5 | Success |

# Week 4/7/2025

## 4/9/2025: Microcontroller and Power System Test
The second version of the PCB came with integration of all call components but the flyback diode. This is the first attempt at soldering the ESP 32 and other components. We were able to program the ESP 32 using only the TX RX and GND pins from the programming module. 

Programming Procedure:
1) Connect GND of PCB to GND of programming module
2) Connect TX to RX and RX to TX between the PCB and programming module
3) Hold GPIO 0 Strapping
4) Press and release EN
5) Release GPIO 0 Strapping
6) Program

However we encountered an issue that the ESP 32 would not turn on when supplied through our 3.3v power system, however it had no problem turning on when supplied through the bench top power supply. When measured at the terminals the voltage is completely stable (no fluctuations at all) at 3.306v and it seems that the ESP 32 is getting all the power that is needed. We believe that the issue is that our 3.3v LDO can only supply a maximum of 100 mA which would be in specification for the STM 32, however the ESP 32 has a maximum current draw of 700 mA and as a result is not able to power on. I have similar concerns with the 5v for the L298N motor drivers not supplying enough maximum current.

I will order some alternative LDOs from our supply store and test them out on the PCB to check if the motor controller and the microcontroller and be powered from them. These both have a current limit of 1 A which is well above both the current limit of the ESP 32 and L298N.

LDO Alternatives: 
* 3.3v Alternative: https://www.digikey.com/en/products/detail/diodes-incorporated/AZ1117CD-3-3TRG1/4470979
* 5v Alternative: https://www.digikey.com/en/products/detail/rohm-semiconductor/BD50FC0FP-E2/7896453

## 4/10/2025: New Power System Test
We ordered some alternative LDOs and soldered them onto the PCB. The voltage at the test points are stable at 3.304 V and 5.016 V for the 3.3 V and 5 V output respectively. Similar to the PCB with the L295X LDOs the microcontroller was able to get programmed, but it still will not turn on. However whenever the benchtop power supply 3.3 V is directly connected it still works. 

Another potential issue may be the SMD 10 uF capacitors that we are using at the input and output of the LDO. The manufacturer specifies that the capcitors need to be low resistance capcitors, so I have tried to use tantalum SMD capacitors. However the issue still occurs.

After searching online a potential issue could be that the 3.3 V while quite stable quickly before we can measure it, it might be unstable during the ESP 32 initialization phase. I will try to re-enable the ESP 32 after a short duration. This solution has worked and from the 5 power on attempts, this method has worked. This means that the LP295X was not the problem.

With a working I will test the ability of powering everything from 12 V battery the BMS. After turning the GPIO pins for each motor one, it seems that everything is now working as planned. I will test the power subsystem requirment of maintaining 3.3 V +- 5% and the batteries ability to run for a 2 minute match.

Voltage Regulation Test Procedure:
1) Connect all 3 motors to the motor outputs and battery
2) Turn on all 3 motors
3) Measure the 3.3 V and 5 V output

Voltage Regulation Test:
| Attempt | 3.3 V Output  | 5 V Output |
| --- | --- | --- |
| 1 | 3.304 V | 5.067 V |
| 2 | 3.304 V | 5.067 V |
| 3 | 3.306 V | 5.068 V |
| 4 | 3.304 V | 5.067 V |
| 5 | 3.302 V | 5.067 V |

Battery Runtime Test Prodcedure:
1) Connect all 3 motors to the motor outputs and battery
2) Turn on all 3 motors
3) Run for 2 Minutes

Battery Runtime Test:
| Attempt | Ran For 2 Minutes? |
| --- | --- | 
| 1 | Yes |
| 2 | Yes |
| 3 | Yes |

The voltage regulation and battery runtime meets the required specifications. Finally I will test the full code on the PCB including the wireless capability. The full code works as expected. The current draw is also signifcantly higher whenever wireless mode is enabled (0.346 A). This means that the switch the the new voltage regulator is still needed.

## 4/11/2025: Design Full PCB Version
With the verification with both the power and control susbsytem from the previous PCB, the final adjustment can be made for the final PCB. This includes increasing trace dimensions to be able to supply max current, adding flyback diodes, putting the fuzes directly on the motor power lines, removing the tranistor programming circuit, and useing 2 reverse polarity protection circuits.

From and online calculator it is apparent that it is not feasible to design a PCB using the standard 1 oz copper trace. At 4 A, the trace width needs to be 200 mils. This means that the PCB will switch to using 2 oz copper trace which will significantly cut down on the trace widths.

| Current | Trace Width |
| --- | --- | 
| 1 A | 20 mils |
| 3 A | 70 mils |
| 4 A | 100 mils |

The decision the move the fuzes to the motor power lines because, if the fuze trips, the LDO and thus the ESP 32 will also turn off. Instead because most of the current draw will result from the motors, it is better to just prevent those from overdrawing current. The deicision to have 2 reverse polarity protection circuit is because the PMOS we are using has a maximum current of 8 A which is too close to our max current draw. As a result splitting the motors to draw from 2 seperate circuits will cut our draw from each circuit to just 4 A, comfortably withing the max current rating of the PMOS. Finally to save space in a small pcb, the transistor part of the programming ciruit is removed.

Reverse Polarity PMOS: https://www.vishay.com/docs/91076/91076.pdf

Schematic: ![image](https://github.com/user-attachments/assets/adeed1c5-a4bf-4ea4-b986-05b101fb59d5)

PCB Layout: ![image](https://github.com/user-attachments/assets/533e58a2-eac8-4299-af50-e2c088ae0a95)

# Week 4/14/2025

# Week 4/21/2025

## 4/21/2025: Solder and Test PCB
Baking, soldering, and programming the finalized PCB went flawlessly and did not run into any problems. The finalized PCB seems to be working great. I will test all the high level and R/V. One issue is that the L298N is taller then expected and collides with the shaft for the lifting arm. I will need to increase the height of the robot so that the PCB can fully fit into the robot.

## 4/24/2025: Power System Heat Issue and Solder Backup PCBS
While my groupmate was testing some new code, the ESP 32 stopped turning on. I have probed a few key pin on the ESP 32 and noticed that the enable pin is low inidcating a short between the 3.3 and GND. This would cause the behavior my groupmate was noticing. We also noticed that the 3.3 V LDO is getting hot and could be the cause of the issue. Shortly after the 3.3 V line was shorted to GND which indicates that there was a short that could have been potentially cause by the hot 3.3 V LDO.

LDO Power Dissapation:
* Power Dissapation (W) = (Vin (V) - Vout (V)) * Current (A) = (12.3 - 3.3) * 0.5 = 4.5 W

With the PCB failing, we soldered 2 additional boards to act as backup. They all function as expected and have tested the theory of the hot LDO. Dissapating 4.5 W in a small package and on a small PCB is a challenge and could be the culprit. After adding a heatsink the LDO seems to resolve the heating issue, while it still runs hot, it is no longer completely uncomfortable to touch. Another possible reason for the failure could be just shorting of the pins underneath the board.

## 4/25/2025: Full Robot CAD Version 5
In the final version I slighlty stretched the robot both vertically and horizontally to more easily to be able to fit the PCB and battery into the chassis. I also implemented the change I noticed I needed in version 4. I added a second clamping mechanism to the wheel. It still meets the dimensional constraints and weight constraints.

![image](https://github.com/user-attachments/assets/280bde0b-c9dc-4266-9719-e261dc95a02b)


## 4/26/2025: 3D Print Robot Version 5
After 3D printing the robot and while testing the lifter weapon, the shaft sheered twice. I believe that this issue is the result of me increasing the width of the robot and thus increasing the length of the center shaft. The solution to this is that I have re-designed the way the power from the lift motor is transferred to the prong. Instead of directly transferring the power through the shaft, the power is directly transfereed through the hub into the prong. The shaft now serves to provide stability to the rotating mechanism rather then power transfer. This new designed worked and no longer have axle breaking problems.

New Axle Design: ![image](https://github.com/user-attachments/assets/8b4889e5-2165-46ff-891a-8ef3d0020a4a)


## 4/27/2025: Final Testing and Spur Gearbox on Lifter Motor Sheered
While performing a final round of R/V checks before the demo the gearbox on the lifter motor sheered. This was during the test that the motor controller can tempporarily supply max stall current for 2 seconds. While stalling the lift motor, cracking noises was heard. After dissassembly of the gearbox, I verified that the spur gears had broken. The motor itself is rated for a stall torque of 4.8 lb-ft, the gears themselves were not rated for that amount of force. I still believe that the motor is correctly speced as the torque in our application (1 lb-ft) is about 1/5th of the stall torque.

### Drivetrain Subsystem

#### Speed Test (ft/s)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 5.30    | 5.25    | 5.35    | 5.40    | 5.30    | 5.32    |

#### Torque Test (ft-lbs)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 0.170   | 0.165   | 0.168   | 0.166   | 0.171   | 0.168   |

---

### Weapon Subsystem

#### Lifting Torque (ft-lbs)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 4.50    | 4.45    | 4.48    | 4.47    | 4.50    | 4.48    |

#### Size Limit (13" max)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

#### Lifting Height (min 2 in)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

#### Deployment Time (s)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 0.85    | 0.87    | 0.86    | 0.85    | 0.87    | 0.86    |

#### Self-righting Capability

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

#### Arm Structural Strength (20 N Impact)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

---

### Power Subsystem

#### Voltage Regulation (3.3V ±5%)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 3.295   | 3.300   | 3.310   | 3.305   | 3.295   | 3.30 (±0.2%) |

#### Battery Current Capacity (2 min runtime)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

---

### Control Subsystem

#### Wifi Stability (15 ft)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |

#### Emergency Stop Response Time (ms)

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| 135     | 140     | 137     | 138     | 140     | 138     |

#### Motor Controller Stall Current Capability

| Trial 1 | Trial 2 | Trial 3 | Trial 4 | Trial 5 | Average |
|---------|---------|---------|---------|---------|---------|
| Passed  | Passed  | Passed  | Passed  | Passed  | Passed  |
