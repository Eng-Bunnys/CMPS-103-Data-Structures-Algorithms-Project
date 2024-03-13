# CMPS-103

Join the Discord Server where any update to this repo will be automatically sent there: https://discord.gg/pwPh3PVpbn

# Chosen Data Structures for picking

1. **Soldiers**
   - Queue =>
 "A queue is a linear data structure where elements are added at the rear (enqueue operation) and removed from the front (dequeue operation). This fits perfectly with the concept of soldiers joining the battle in the order they arrive."
1.1. Soldier joins the battle, they are enqueued
1.2. When it's time for the soldier to participate in the battle, they are dequeued from the front of the queue in the order they joined, this way they participate in the same order they joined.

Example:
```c++
    queue<string> SoldierQueue;

    // Soldiers join the battle
    SoldierQueue.push("Soldier 1");
    SoldierQueue.push("Soldier 2");
    SoldierQueue.push("Soldier 3");

    // Display soldier order
    cout << "Soldier order:" << endl;
    while (!SoldierQueue.empty()) {
        cout << SoldierQueue.front() << endl;
        soldierQueue.pop();
    }
```
![Queue](https://courses.engr.illinois.edu/cs225/sp2019/assets/notes/quacks/queue.png)

2. **Tank**
  - Stack =>LIFO Behaviour, the last element added will be the first one removed which is perfect for this scenario
    Estimated time complexity for push, pop, and top: O(1)
    ---------------------------------------------------------
    ![Stack](https://media.geeksforgeeks.org/wp-content/uploads/20230116192305/stack-768.png)

3. **Gunnery**
   - Priority Queue => Elements are moved according to their priority, in our scenario the priority would be determined by the power & health, so the highest will be on top
     The estimated time complexity for update O(log(n)) will likely be similar to retrieval, insertion, deletion, and update if we use the tree approach.
     If a queue implementation was used, the estimated time complexity might be O(k + m) where m is the number of elements k is the priority level for insertion, O(1) for deletion, O(k + m) for update
      ---------------------------------------------------------
     ![Priority Queue Queue method](https://miro.medium.com/v2/resize:fit:1200/1*8qeO7nFIxK_MhDY2MBVKXw.png)
     ![Priority Queue Tree method](https://he-s3.s3.amazonaws.com/media/uploads/6cedb81.jpg)

5. **Monster**
   - List / Array => Since it's random, we can create an array-implemented list and create a random number generator to generate a number between 0 and N - 1, where N is the number of elements in the list/array.
     Estimated time complexity O(1)

6. **Drone**
   - Queue, insertions, and deletions can be done with complexities O(1) **but** the operation to find pairs would require dequeuing two drones so it *could* be O(n)
   - Deque, a double-ended queue, this way we can insert and delete at both ends so estimated complexity O(1)
   - Array/List, Depending on the algorithm used the estimated min. complexity would be O(n log(n)) and worst case scenario would be O(n²)
      ---------------------------------------------------------
   ![Deque](https://media.geeksforgeeks.org/wp-content/uploads/anod.png)

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
