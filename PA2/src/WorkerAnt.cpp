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
#include <vector>
using namespace std;

WorkerAnt::WorkerAnt() : _capacity(0), _numPoints(0), _food(NULL) {}

WorkerAnt::WorkerAnt(const char* inputFileName, const char* outputFileName)
{
   ifstream inputFile(inputFileName);
   string s;
   getline(inputFile, s);
   _capacity = stoi(s);
   getline(inputFile, s);
   _numPoints = stoi(s);
   _food = new food[_numPoints+1];
   for (int i=1;i<=_numPoints;++i) {
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

   _outputFile.open(outputFileName);
}

void WorkerAnt::print()
{
   printf("numPoints = %d, capacity = %d\n",_numPoints, _capacity);
   for (int i=0;i<=_numPoints;++i)
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

int WorkerAnt::Dynamic()
{
   int load = 0;
   _food[0].dist = 0;
   for (int i=1;i<=_numPoints;++i) {
      load = _food[i].weight;
      int distance;
      for (int j=i-1;j>=0;--j) {
         distance = _food[j].dist + DistToOrigin(j) + dist(j,i) + DistToOrigin(i);
         if (distance < _food[i].dist) {
            _food[i].lastReturn = j;
            _food[i].dist = distance;
         }
         if ((load += _food[j].weight) > _capacity)
            break;
      }
   }

   vector<int> returnPos;
   int pos = _numPoints;
   while (pos > 0) {
      returnPos.push_back(pos);
      pos = _food[pos].lastReturn;
   }
   for (int i=returnPos.size()-1;i>=0;--i)
      _outputFile << returnPos[i] << endl;
   _outputFile << _food[_numPoints].dist << endl;
   return 0;
}

int WorkerAnt::Greedy()
{
   int load = 0;
   for (int i=1;i<=_numPoints;++i) {
      if (load + _food[i].weight <= _capacity) {
         _food[i].dist = _food[i-1].dist + dist(i-1,i);
         load += _food[i].weight;
      } else {
         _food[i].dist = _food[i-1].dist + DistToOrigin(i-1) + DistToOrigin(i);
         load = _food[i].weight;
         _outputFile << i-1 << endl;
      }
   }
   int ret = _food[_numPoints].dist + DistToOrigin(_numPoints);
   _outputFile << _numPoints << endl;
   _outputFile << ret; 
   return ret; 
}
