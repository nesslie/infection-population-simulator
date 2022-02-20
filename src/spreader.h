#ifndef SPREADER_H
#define SPREADER_H

#include "spreaderRunner.h"
class Person2{
  public:
    int ID;
    int peopleMet;
    Visitor *visitors;
    int dayInfected;
    bool visited;
    friend const bool operator<(const Person2 &a, const Person2 &b){ // Operator overloading to compare the infections between people
      if(a.dayInfected < b.dayInfected) 
                return true;
       return false;
    } 
};

class Spreader
{
  int populate;
  int ans;
public:
  Spreader(const Person *people, int population);
  int simulate(int starterIDs[], int starterCount, int commandLineOption);
  Person2* data;
};



#endif /* SPREADER_H */

