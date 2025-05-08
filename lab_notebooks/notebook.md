# ECE 445 Antweight Battlebot PCB Design Lab Notebook
## Praman Rai - Spring 2025

---

### Week of 2/17 (2/19/2025)
#### **Objectives:**
- Begin research on PCB requirements for battlebot
- Identify key components needed for control system
- Understand power distribution requirements

#### **Activities:**
1. First team meeting to discuss project scope. We've selected the antweight battlebot category with a lifter mechanism. I'll be responsible for PCB design while Anthony handles mechanical design and Batu will work on electrical testing.

2. Initial research on control system architecture. Main components identified:
   - STM32F401RBT6 microcontroller
   - H-bridge motor drivers for drivetrain and weapon motors
   - Bluetooth module for control
   - Power regulation system for 11.1V battery

3. Created block diagram showing system architecture (Fig. 1):
   ![Block Diagram](images/block-diagram-initial.png)

4. Calculated peak current requirements:
   - Drive motors: 2 × 1.4A = 2.8A
   - Weapon motor: 1 × 3.85A = 3.85A
   - Total peak: ≈6.65A

5. Researched motor controller options. The DRV8952 looks promising as it offers 3.5A continuous current with 6A peak per channel.

#### **References:**
- STM32F401xB/C datasheet (April 2019)
- DRV8952 datasheet (March 2023, Rev. January 2025)
- ServoCity motor specifications (508 RPM Mini Econ & 56 RPM Econ)

---

### Week of 2/24 (2/26/2025)
#### **Objectives:**
- Select specific components for PCB design
- Begin schematic capture
- Draft initial power system design

#### **Activities:**
1. Selected critical components:
   - Microcontroller: STM32F401RBT6
   - Motor controllers: DRV8952 (2 needed)
   - Bluetooth: HC-05 module
   - Voltage regulator: LP2950CZ-3.3
   - Battery: 3S LiPo 2200mAh 11.1V 50C

2. Created schematic for power subsystem (Fig. 2):
   ![Power Subsystem Schematic](images/power-subsystem-schematic-stm32.png)

3. Design includes:
   - MOSFET (P-CH 60V 28A) for reverse polarity protection
   - Polyfuse for overcurrent protection
   - Voltage regulator for 3.3V supply
   - Filtering capacitors (10μF, 470μF, 0.1μF)
   - LED power indicator

4. Calculated voltage drop under peak load:
   - Internal resistance of battery: ≈20mΩ
   - Peak current: 6.65A
   - Voltage drop: 6.65A × 20mΩ = 0.133V
   - Min battery voltage under load: 11.1V - 0.133V = 10.967V

5. Discussed PCB size constraints with Anthony. Based on mechanical design, PCB must fit within 3.5" × 2.5" area.

6. Evaluated 3D printing materials for battlebot chassis and components:
   - Compared ABS, PLA, and PETG options
   - Selected ABS as primary choice due to superior strength-to-weight ratio and impact resistance
   - Created contingency plan for using PLA if ABS printing unavailable
   - Designed part orientation to optimize strength along expected stress directions

---

### Week of 3/3 (3/5/2025)
#### **Objectives:**
- Complete full schematic design
- Begin PCB layout
- Prepare for first PCBway order

#### **Activities:**
1. Completed microcontroller and peripherals schematic (Fig. 3):
   ![Microcontroller Schematic](images/microcontroller-schematic-stm32.png)

2. Added 8MHz crystal oscillator circuit with load capacitors (22pF)
3. Added debug header pins for programming

4. Completed DRV8952 H-bridge connections (Fig. 4):
   ![H-Bridge Schematic](images/h-bridge-schematic-stm32.png)

5. Configured motor controller settings:
   - PWM inputs from STM32 pins
   - Direction control from additional GPIO pins
   - Designed for 2 drive motors (left/right) and 1 weapon motor
   - Added required decoupling capacitors

6. Began PCB layout with component placement optimized for:
   - Short high-current paths
   - Motor connectors at edges
   - Battery connections at front
   - Separation of power and signal domains

7. Submitted first PCB design for team review before ordering. Identified potential issue with H-bridge thermal management.

#### **Problems & Solutions:**
- Concern about thermal performance of DRV8952 under stall conditions
- Added additional copper pour for heat dissipation
- Organized to expedite PCBway order to meet 3/3 deadline

---

### Week of 3/10 (3/12/2025)
#### **Objectives:**
- Build breadboard prototype
- Test basic control functionality
- Prepare for breadboard demo

#### **Activities:**
1. Built breadboard prototype using:
   - STM32 development board
   - DRV8952 evaluation modules (2)
   - HC-05 Bluetooth module
   - LP2950CZ-3.3 voltage regulator

2. Test results:
   - Measured regulated voltage: 3.31V (within 0.6% tolerance)
   - Verified Bluetooth connection range: >20 feet
   - Tested PWM motor control signals
   - Verified emergency stop functionality

3. Assisted Batu with control system testing and debugging for breadboard prototype

4. Prepared for breadboard demo on 3/11. Demonstrated control system functionality to TA.

5. **Critical decision point**: Team meeting to discuss microcontroller performance. Multiple issues identified with STM32 implementation:
   - Bluetooth connectivity reliability issues under motor noise
   - Programming complexity slowing development
   - Limited GPIO availability for expansion
   - Inability to implement the required 500ms automatic disconnect when connection was lost
   - Difficulty in soldering the STM32's small pins even with a baking process
   - Decision made to switch to ESP32 WROOM 2 module for next revision

6. Began research on ESP32 WROOM 2 integration:
   - Built-in Bluetooth and WiFi capability eliminates need for HC-05 module
   - More GPIO pins and processing power
   - Built-in USB interface simplifies programming
   - More RAM and flash for future feature expansion

#### **Problems & Solutions:**
- Discovered interference between motor PWM signals and Bluetooth communication
- Solution: Added additional filtering capacitors and improved ground connections
- Identified need for better timeout detection for safety stop feature

---

### Week of 3/17 (Spring Break)
#### **Objectives:**
- Redesign system architecture for ESP32
- Improve circuit design for PCB revision
- Begin ESP32-based PCB design iteration

#### **Activities:**
1. Reviewed breadboard test results:
   - Motor control functionality worked, but had noise issues
   - Bluetooth range exceeded requirements (15ft specified, achieved >20ft)
   - Voltage regulator stable under load

2. Complete redesign based on ESP32 platform:
   - Replaced STM32 + HC-05 with integrated ESP32 WROOM 2 module
   - Redesigned power circuit for ESP32 requirements
   - Eliminated external crystal (ESP32 has internal oscillator)
   - Added USB-to-UART bridge for programming
   - Redesigned GPIO connections for motor control
   - Switched from DRV8952 to L298N H-bridges due to simpler implementation

3. Power system redesign:
   - Added BD50FC0FP-E2 voltage regulator for 5V supply needed by the L298N H-bridges
   - Replaced LP2950CZ-3.3 with AZ1117CD-3.3TRG1 voltage regulator for ESP32
   - ESP32 draws approximately 0.5A when connected to WiFi vs. LP2950CZ-3.3's 0.1A max
   - Added heat sink for 3.3V regulator for better thermal management  

4. Created new ESP32-based schematic (Fig. 5):
   ![ESP32 Schematic Rev1](images/esp32-schematic-rev1.png)

5. Began layout of ESP32-based PCB using 2-layer design:
   - Top layer: Signal routing and components
   - Bottom layer: Ground plane with power routing
   - Improved thermal relief for H-bridges
   - Added test points for debugging

6. Created preliminary bill of materials for all ESP32-based components

---

### Week of 3/24 (3/26/2025)
#### **Objectives:**
- Complete ESP32-based PCB design (Revision 2)
- Verify DRC/ERC checks
- Submit PCB for third round PCBway order

#### **Activities:**
1. Completed ESP32-based PCB layout (Rev 2) (Fig. 6):
   ![PCB Layout Rev2](images/pcb-layout-rev2.png)

2. Verified all design rules:
   - Min trace width: 10mil for signals, 40mil for power
   - Clearance: 10mil minimum
   - Via size: 0.6mm drill, 1.2mm pad
   - Board dimensions: 3.4" × 2.4"

3. Added mounting holes (3mm) in corners for securing to chassis

4. Added silkscreen labels for all connectors and test points

5. Added identification text and project information

6. Performed power analysis:
   - Maximum power dissipation in regulator: (11.1V - 3.3V) × 0.5A = 3.9W
   - Selected TO-220 package with larger heatsink for 3.3V regulator

7. Verified component spacing against mechanical constraints

8. Generated Gerber files and checked with viewer

9. Submitted design for PCBway order on 3/24 to meet third round deadline

#### **Problems & Solutions:**
- Initial layout had power traces too close to sensitive analog components
- Solution: Rerouted power traces and added ground plane isolation
- Reduced board size by 0.1" in each dimension to better fit in chassis

---

### Week of 3/31 (4/2/2025)
#### **Objectives:**
- Receive and inspect ESP32-based PCBs (Rev 2)
- Test and identify any issues
- Begin planning for Rev 3 with flyback diodes

#### **Activities:**
1. Received ESP32-based PCBs from fabricator (Rev 2):
   ![ESP32 PCB Rev2](images/esp32-pcb-rev2.png)

2. Visual inspection showed no obvious defects

3. Continuity testing for power and ground:
   - No shorts detected
   - All power rails continuous
   - Ground plane connections verified

4. Initial testing revealed potential motor switching issues:
   - Observed voltage spikes when motors turn off
   - Decided to add flyback diodes for Rev 3 to protect circuit from inductive loads
   - Designed improved motor protection circuit

5. Prepared individual progress report documenting PCB design iterations and current status

6. Full system testing with Rev 2 PCB:
   - Measured current draw: 1.1A typical, 5.4A peak during weapon activation
   - Verified Bluetooth connection and control using ESP32's built-in BLE
   - Tested emergency stop functionality (disconnected in 482ms, within 500ms requirement)

#### **Problems & Solutions:**
- Found incorrect footprint for one capacitor (C4)
- Solution: Modified component to fit by bending leads
- Discovered one via not connecting to ground plane
- Solution: Added jumper wire to ensure proper connection
- Observed voltage spikes during motor switching
- Solution: Plan to add flyback diodes in Rev 3

---

### Week of 4/7 (4/9/2025)
#### **Objectives:**
- Design PCB Rev 3 with flyback diodes
- Submit ESP32-based PCB Rev 3 design
- Plan for final PCB revision

#### **Activities:**
1. Updated schematic for Rev 3 with flyback diodes (Fig. 7):
   ![ESP32 Schematic Rev3](images/esp32-schematic-rev3.png)

2. Design improvements for Rev 3:
   - Added flyback diodes across all motor terminals
   - Improved power distribution paths
   - Enhanced ground plane connections
   - Added more test points for debugging

3. Completed ESP32-based PCB layout for Rev 3 (Fig. 8):
   ![ESP32 PCB Layout Rev3](images/esp32-pcb-layout-rev3.png)

4. Collaborated with Batu on control system requirements and testing procedures

5. Design advantages of ESP32 implementation observed:
   - Simplified circuit with fewer components
   - Built-in wireless eliminates separate module
   - Reduced noise susceptibility due to fewer interconnections
   - Improved programming interface
   - Better interrupt handling for emergency stop functionality

6. Submitted ESP32-based PCB Rev 3 design for PCBway order

#### **Problems & Solutions:**
- At high motor speeds, observed interference with control signals
- Solution: Added additional filtering and improved signal routing
- Added hardware watchdog circuit to ESP32 design for additional safety
- Addressed thermal concerns with improved layout and additional cooling areas

---

### Week of 4/14 (4/16/2025)
#### **Objectives:**
- Receive and assemble ESP32-based PCB Rev 3
- Perform comprehensive testing
- Document final design and performance

#### **Activities:**
1. Assembled PCB Rev 3 with all components (Fig. 9):
   ![Assembled ESP32 PCB Rev3](images/esp32-pcb-assembled-rev3.png)

2. Testing against requirements:
   - **Voltage regulation**: Maintained 3.3V ±1.8% under all load conditions (req: ±5%)
   - **Bluetooth range**: Stable at 32 feet using built-in BLE (req: 15 feet)
   - **Emergency stop**: Triggered in 356ms when connection lost (req: <500ms)
   - Test methodology: Deliberately powered off controller while operating motors at full speed, measured time until motors stopped using high-speed camera
   - **Motor controller**: Successfully handled stall current for >3 seconds

3. Identified final improvements for Rev 4:
   - Minor routing improvements
   - Added additional filtering capacitors
   - Enhanced motor protection circuitry
   - Improved silkscreen labeling

4. Submitted final PCB version (Rev 4) for production

5. Advantages of ESP32 implementation confirmed:
   - Reduced component count by eliminating HC-05 module
   - More reliable wireless connection with less interference
   - Simpler programming interface via USB
   - Better power management with sleep modes

6. Prepared for team contract assessment due this week

#### **Problems & Solutions:**
- Initial issues with ESP32 deep sleep affecting emergency stop response
- Solution: Modified firmware to use light sleep instead
- Some pin assignment conflicts required trace cutting and jumper wires
- Solution: Fixed pin assignments in Rev 4 design

---

### Week of 4/21 (4/23/2025)
#### **Objectives:**
- Receive and assemble ESP32-based PCB Rev 4
- Perform final testing and debugging
- Document design decisions and lessons learned

#### **Activities:**
1. Received and assembled ESP32-based PCB Rev 4 (Fig. 10):
   ![Assembled ESP32 PCB Rev4](images/esp32-pcb-assembled-rev4.png)

2. Conducted extensive pre-demo testing:
   - Verified all subsystems working correctly
   - Tested under various battery voltage levels (fully charged vs. partially discharged)
   - Verified failsafe mechanisms

3. Performance measurements:
   - Control latency: 36ms average
   - Maximum continuous runtime: 19 minutes
   - Recovery time after emergency stop: 0.9 seconds
   - Flyback diode effectiveness: Voltage spikes reduced by 87%

4. Participated in mock demo with team:
   - Demonstrated all control functions
   - Showed emergency stop features
   - Explained PCB design evolution from STM32 to ESP32
   - Highlighted improved performance metrics

5. Documented key design decisions:
   - Rationale for switching from STM32 to ESP32
   - Component selection criteria
   - Layout optimizations for noise immunity
   - Power distribution strategy
   - Thermal management approach

#### **Problems & Solutions:**
- Minor WiFi interference issues when operating near other robots
- Solution: Implemented channel hopping algorithm in ESP32 firmware
- Documented procedure for secure assembly

---

### Week of 4/28 (4/30/2025)
#### **Objectives:**
- Prepare for final demo
- Complete final documentation
- Analyze system performance
- Prepare for battlebot competition

#### **Activities:**
1. Final system preparation:
   - Verified all connections secure
   - Fully charged battery
   - Confirmed firmware is latest version

2. Created comprehensive system diagram (Fig. 11):
   ![System Diagram](images/system-diagram.png)

3. Final performance analysis:
   - Power efficiency: 87%
   - Maximum reliable control distance: 35 feet (exceeded 15ft requirement)
   - Battery life under typical operation: 24 minutes

4. **Critical incident**: During final testing, we accidentally stalled the lift motor which resulted in a mechanical failure - the gear shaft sheared completely.
   - Immediate assessment of damage showed motor was unusable
   - Placed emergency order for replacement 56 RPM Econ Gear Motor
   - Created contingency plan for competition if replacement didn't arrive in time

5. Performed final demonstration with instructors despite lift motor issue:
   - Demonstrated driving and control systems
   - Explained PCB design evolution from STM32 to ESP32
   - Showed documentation of lift system functionality from previous tests

6. Documented all test results for final report

7. Created final bill of materials with actual costs:
   - Total component cost: $212.45
   - PCB fabrication cost: $32.90 (×4 iterations)
   - Emergency replacement motor: $14.99 + expedited shipping

8. Received replacement motor on Thursday, just in time for Friday's competition

#### **Problems & Solutions:**
- Lift motor failure just before final demo
- Solution: Emergency replacement order with expedited shipping
- Reviewed stall protection in the control system to prevent future failures
- Added mechanical safety features to limit maximum torque

---

### Week of 5/5 (5/7/2025)
#### **Objectives:**
- Document competition results
- Complete final presentation
- Submit final documentation
- Analyze project success and future improvements

#### **Activities:**
1. **Battlebot Competition Results (Friday, May 2nd)**:
   - Successfully competed with fully functioning robot
   - Replacement lift motor performed well during matches
   - Our lifter design proved effective against several opponents
   - Robot sustained minimal damage throughout competition
   - Demonstrated excellent control and maneuverability
   - Successfully demonstrated all functions we designed into the system

2. Prepared PCB section for final presentation:
   - Design methodology
   - Key challenges overcome
   - Performance results vs. requirements
   - Detailed explanation of STM32 to ESP32 transition
   - Competition performance analysis

3. Collected all design files for submission:
   - Schematics (both STM32 and ESP32 versions)
   - PCB layouts
   - Gerber files
   - BOM
   - Test data
   - Competition performance data

4. Final project analysis:
   - Successfully met all high-level requirements
   - PCB design went through 4 iterations (1 with STM32, 3 with ESP32)
   - ESP32 design provided significant improvements in reliability and performance
   - Final design handled peak loads without issues
   - Bluetooth control range exceeded requirements by 2.3×
   - Robot performed competitively at the competition

5. Documented lessons learned:
   - Importance of microcontroller selection for specific application
   - Better noise immunity needed for motor control circuits
   - More test points would improve debugging
   - Consider 4-layer board for better power/ground planes
   - Earlier mechanical integration would prevent connector issues
   - Need for mechanical safeguards against stall conditions

6. Future improvements:
   - Leverage ESP32 capabilities for telemetry and data logging
   - Implement more advanced control algorithms using ESP32's processing power
   - Add OTA firmware updates
   - Consider ESP32-S3 for future revisions with additional features
   - Add current limiting protection for motors

7. Submitted final paper and all documentation

8. Participated in award ceremony

#### **Final Thoughts:**
The PCB design process was challenging but rewarding. The mid-project switch from STM32 to ESP32 WROOM 2 proved to be a critical design decision that significantly improved performance and reliability. Adding flyback diodes in revision 3 was another key improvement that protected our circuits from inductive spikes. Despite the last-minute motor failure, we were able to quickly recover and perform well at the competition. Our battlebot demonstrated good performance and sustained minimal damage, validating our design decisions. The experience provided valuable lessons in system integration, microcontroller selection, high-current PCB design, and design for manufacturability.