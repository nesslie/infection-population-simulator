# Infection Population Simulator
This was a homework for my Data Structures and Algorithms class, originally modeling how covid spreads. All credits go to Mark Weissman for writing the datastructure implementations and lecturer Sean Davis for writing the test cases and the problem itself!

## What is this?
The goal of this project is to calculate the amount of time until a certain population is infected given information on how many people are in the population and detailed information on who they visit and how often. The algorithm treats the all of the information as if it was graph and runs Dijkstra's algorithm to find the shortest path for each person to be infected. The weights of the graph are the days until each person visits another + 3 days for the incubation period!

## How does it work?
### The CSV
The program takes in CSV a formatted CSV file as its way of obtaining the information. The first line contains information on the population and who starts off infected. The first number is the total population, the second number is the total amount of people who start off infected, and the following numbers are their ID's. So in the following first line `20,3,13,5,15`, out of the total of 20 people, 3 start off infected and their ID's are 13, 5, 15.

The rest of the lines are information for every single person within the population. The person ID is the first number of each line, followed by the number of people they visit. The rest of the line is the ID of the person they visit followed by how often they visit. For example in the line `1,1,19,1` we can tell that this is Person 1 who visits person 19 every day.

**Note: Sean Davis provided the data format and the spreaderRunner.cpp which reads the data**

### The Implementation
The students were responsible for editing spreader.cpp, spreader.h and any additional edits we could make to cut down on runtime.

### Spreader.cpp and Spreader.h
Since in the driver program provided by the instuctor deletes all of the memory allocated to storing the data before calling the `simulate()` function , we needed reallocate the memory using our own data structure in the class initialization. Since our ultimate goal was to implement Dijiktra's aglorithm, I decided to mark each person as unvisited and initialize their distance to infinity to avoid dealing with extra arrays to keep track of everything. The `simulate()` function carries out the actual Dijiktra's algoritm by inserting each of the starter infected people into a binary heap and then inserting each person they visit into the binary heap.

### Optimizations
The biggest key to reducing runtime was using gprof to find how long each process took to carry out. It turns out in the default version of Weiss's version of a Binary Heap, the Weiss vector is used. This means that it's contantly resizing to store the incoming data when we know that there is going to be a limited size. Therefore the binary heap was edited to use an array instead of a vector to reduce the amount of time it took to create the main binary heap. This resulted in a timescore that was equal to the professor's implementation!
