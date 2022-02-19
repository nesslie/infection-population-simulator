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
  for(int i = 0; i < population; i++){
    //data[i].ID = people[i].ID;
    data[i].peopleMet = people[i].peopleMet;
    data[i].visitors  = new Visitor[people[i].peopleMet];
    
    for(int j = 0; j < people[i].peopleMet;j++){
      data[i].visitors[j].ID = people[i].visitors[j].ID;
      data[i].visitors[j].period = people[i].visitors[j].period;
    }

    data[i].dayInfected = 2147483647;
    data[i].visited = false;
  }
  populate = population;
} // Spreader()


int Spreader::simulate(int starterIDs[], int starterCount, int commandLineOption)
{
  BinaryHeap <Person2> heap(populate);
  ans = 0;
  int distance = 0;

  for(int i = 0; i < starterCount; i++){
    data[starterIDs[i]].dayInfected = 0;
    heap.insert(data[starterIDs[i]]);
  }

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
