# CMPS-103

### Description [Not Complete]

1. **Simulation Time**:
   - Time divided into discrete time steps.
   - Changes in the system simulated at each time step.

2. **Army Units**:
   - Earth army consists of soldiers, tanks, and gunnery units.
   - Alien army consists of soldiers, monsters, and drones.
   - Units can join or leave the battle at each time step.

3. **Information Stored for Each Army Unit**:
   - ID, Type, Join Time, Health, Power, Attack Capacity.

4. **Battle Rules & Attack Logic**:
   - Earth units attack alien units, then alien units attack Earth units.
   - Dismiss units with zero or negative health.
   - Attack and defense order based on joining the battle.
   - Winner determined by destroying all units of the opposing army.

5. **Earth Tank (ET)**:
   - Attacks monsters primarily.
   - Fresh tanks attack first.
   - If Earth soldier count falls, tanks also attack alien soldiers until a threshold is reached.

6. **Earth Gunnery (EG)**:
   - Attacks drones and monsters.
   - Random selection of monsters for attack.
   - Attack drones in pairs if possible.

7. **Alien Monster (AM)**:
   - Attacks tanks and soldiers randomly.
   - Attack order based on the order of targets.

8. **Alien Drone (AD)**:
   - Attacks tanks and gunnery.
   - Attack in pairs if possible.

9. **Random Unit Generator**:
   - Parameters loaded from input file: N, ES%, EG%, AS%, AM%, AD%, and Prob.
   - Generate N army units for each army based on specified distributions.
   - Generate units with random data within specified ranges.
   - Unique ID assigned to each unit.
