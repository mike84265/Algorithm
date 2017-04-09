// **************************************************************************
//  File       [WorkerAnt.h]
//  Author     [Cheng-Yu Tsai]
//  Synopsis   [The header file of worker ant]
//  Modify     [2017/4/8 Cheng-Yu Tsai]
// **************************************************************************

#ifndef _WORKERANT_H
#define _WORKERANT_H
class food{
 public:
   food() : x(0), y(0), weight(0), dist(0) {}
   int x;
   int y;
   int weight;
   int dist;
};
class WorkerAnt {
 public:
   WorkerAnt();
   WorkerAnt(const char* inputFileName);
   ~WorkerAnt();
   int Dynamic();
   int Greedy();
   void print();
 private:
   // Helper functions:
   int DistToOrigin(int i);
   int dist(int i, int j);
   // Member variables:
   int            _capacity;
   int            _numPoints;
   food*          _food;

};

#endif
