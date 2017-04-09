// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2015 Spring Algorithm PA2]
//  Modify     [2015/03/20 Yu-Hao Ho]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include "../lib/tm_usage.h"
#include "WorkerAnt.h"

using namespace std;

void help_message() {
    cout << "usage: WorkerAnt -[GD|DP] <input_file> <output_file>" << endl;
    cout << "options:" << endl;
    cout << "   GD  - Greedy" << endl;
    cout << "   DP  - Dynamic Programming" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 4) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file /////////////
    WorkerAnt worker(argv[2]);
    worker.print();
    return 0;


    //////////// find the solution to pick up the food ////
    tmusg.periodStart();

    if(strcmp(argv[1], "-GD") == 0) {
       // greedy 
    }
    else if(strcmp(argv[1], "-DP") == 0) {
      // dynamic programming  
    }
    else {
        help_message();
        return 0;
    }

    tmusg.getPeriodUsage(stat);

    //////////// write the output file ///////////


    cout <<"# run time = " << (stat.uTime + stat.sTime) / 1000000.0 << "sec" << endl;
    cout <<"# memory =" << stat.vmPeak / 1000.0 << "MB" << endl;

    return 0;
}

