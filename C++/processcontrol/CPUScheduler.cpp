/**
 * A simple non-preemptive CPU Scheduler simulator
 * @author Aaron Cao
 * @since 2017-02-16
 * Course: CS3102.01
 * Programming Project #: 1
 * Instructor: Dr. Duncan
 * @see Heap.cpp
 * @see PCB.h
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Heap.cpp"
#include "PCB.h"


using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));
    double p = atof(argv[1]);
    int s = atoi(argv[2]);
    double q;
    int pidCounter = 0;
    int waitCounter = 0;
    int randPriority, length;
    Heap<PCB> scheduler;
    for (int i = 0; i < s; i++)
    {
        cout << "Cycle #: " << i+1 << endl;
        if (!scheduler.isEmpty() && (scheduler.peek()).getLength() == (i+1-(scheduler.peek()).getStart()))
        {
            cout << "Process #" << (scheduler.peek()).getPid() << " has just terminated." << endl;
            waitCounter += (scheduler.peek()).getWait();
            scheduler.remove();
        }

        else if (!scheduler.isEmpty() && !(scheduler.peek()).isExecuting())
        {
            (scheduler.peek()).execute();
            (scheduler.peek()).setStart(i+1);
            (scheduler.peek()).setWait(i+1-(scheduler.peek()).getArrival());
        }

        if (!scheduler.isEmpty() && (scheduler.peek()).isExecuting())
        {
            cout << "Process #" << (scheduler.peek()).getPid() << " is executing." << endl;
        }
        q = ((double)rand()/RAND_MAX);
        if (q <= p)
        {
            pidCounter++;
            randPriority = rand()%20-20;
            length = rand()%100 + 1;
            scheduler.insert(PCB(pidCounter, -randPriority, 0, i+1, length));
            cout << "Adding job with pid #" << pidCounter << " and priority " << randPriority << " and length " << length << "." << endl;
        }
        else
            cout << "No new job this cycle." << endl;
    }


    cout << "The average turnaround time is " << (double)pidCounter/s <<"per cycle." << endl;
    cout << "The average wait time is " << (double)waitCounter/pidCounter << "." << endl;
    return 0;
}