#include <iostream>  // for debugging
#include <cstring>
#include "spreader.h"
#include "BinaryHeap.h"

using namespace std;

Spreader::Spreader(const Person *people, int population)
{
  // Students write this. 
  // Note that people will be deleted before simulate() is called.
  data = new Person2[population];
  // TODO: Find a way to do this using MEMCPY
  // Copy all of the data from the original person class
  for(int i = 0; i < population; i++){
    data[i].peopleMet = people[i].peopleMet;
    data[i].visitors  = new Visitor[people[i].peopleMet]; // Allocate memory before the original data gets yeeted

    for(int j = 0; j < people[i].peopleMet;j++){
      data[i].visitors[j].ID = people[i].visitors[j].ID;
      data[i].visitors[j].period = people[i].visitors[j].period;
    }
    // Initializing all of the data so the Dijikstra's Algorithm works properly
    data[i].dayInfected = 2147483647;
    data[i].visited = false;
  }
  populate = population;
} // Spreader()


int Spreader::simulate(int starterIDs[], int starterCount, int commandLineOption)
{
  // Binary heap to find the smallest adjacent node
  BinaryHeap <Person2> heap(populate);
  ans = 0;
  int distance = 0;
  // Initialize the heap to insert the first people infected
  for(int i = 0; i < starterCount; i++){
    data[starterIDs[i]].dayInfected = 0;
    heap.insert(data[starterIDs[i]]);
  }
  // Visit every single person and insert the people they visit into the heap
  while(!heap.isEmpty()){
    Person2 temp = heap.findMin();//get the top of heap
    if(ans < temp.dayInfected) ans = temp.dayInfected;
    if(temp.visited){ // check if the the person has been visited
      heap.deleteMin(); 
      continue;
    }
    
    for(int i = 0; i < temp.peopleMet; i++){    
      while(((temp.dayInfected+3 + distance)%temp.visitors[i].period)!=0){
        distance+=1;
      }
      distance = distance + temp.dayInfected+3;
      if(distance < data[temp.visitors[i].ID].dayInfected){
        data[temp.visitors[i].ID].dayInfected = distance;
        heap.insert(data[temp.visitors[i].ID]);
      }
      distance = 0;
    }
    data[temp.ID].visited = true; // mark visited
    heap.deleteMin();
  }
  return ans;
}
