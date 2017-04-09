// **************************************************************************
//  File       [main.cpp]
//  Author     [Cheng-Yu Tsai]
//  Synopsis   [The implementation of worker ant function]
//  Modify     [2017/4/8 Cheng-Yu Tsai]
// **************************************************************************

#include "WorkerAnt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

WorkerAnt::WorkerAnt() : _capacity(0), _numPoints(0), _food(NULL) {}

WorkerAnt::WorkerAnt(const char* inputFileName)
{
   ifstream inputFile(inputFileName);
   string s;
   getline(inputFile, s);
   _capacity = stoi(s);
   getline(inputFile, s);
   _numPoints = stoi(s);
   _food = new food[_numPoints];
   for (int i=0;i<_numPoints;++i) {
      getline(inputFile, s);
      size_t end = s.find_first_of(' ');
      _food[i].x = stoi(s.substr(0,end));
      size_t start = s.find_first_not_of(' ', end);
      end = s.find_first_of(' ',start);
      _food[i].y = stoi(s.substr(start,end));
      start = s.find_first_not_of(' ',end);
      end = s.find_first_of(' ',start);
      _food[i].weight = stoi(s.substr(start,end));
   }
   inputFile.close();
}

void WorkerAnt::print()
{
   printf("numPoints = %d, capacity = %d\n",_numPoints, _capacity);
   for (int i=0;i<_numPoints;++i)
      printf("food[%d]: x=%d, y=%d, w=%d\n",i,_food[i].x,_food[i].y,_food[i].weight);
}

WorkerAnt::~WorkerAnt()
{
   delete[] _food;
}

int WorkerAnt::DistToOrigin(int i)
{
   return (_food[i].x + _food[i].y);
}

int WorkerAnt::dist(int i, int j)
{
   if (i>j) {
      int temp = j;
      j = i;
      i = temp;
   }
   int sum = 0;
   for (; i<j; ++i) {
      sum += abs(_food[i+1].x - _food[i].x);
      sum += abs(_food[i+1].y - _food[i].y);
   }
   return sum;
}
