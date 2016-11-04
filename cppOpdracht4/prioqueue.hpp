/*
 * prioqueue.hpp
 *
 *  Created on: May 24, 2013
 *      Author: Rens Visser
 */

#ifndef PRIOQUEUE_HPP_
#define PRIOQUEUE_HPP_
#include <vector>

using namespace std;
template <class myType> class prioQueue
{
    //vector<int> pq_keys;
    void shiftRight(int low, int high);
    void shiftLeft(int low, int high);
    void buildHeap();
public:
    vector<myType> pq_keys;
    prioQueue(){}
    prioQueue(vector<myType>& items)
    {
        pq_keys = items;
        buildHeap();
    }
    /*Insert a new item into the priority queue*/
    void enqueue(myType item);
    /*Get the maximum element from the priority queue*/
    myType dequeue();
    /*Just for testing*/
    void print();
    //Zamen voegen van prioQueue's.
    void operator+(const prioQueue &priQue1);
    //Nieuwe queue met de inhoud van de 2 anderen
    void operator*(const prioQueue &priQue1);
    //printen van queue
    void operator<<(prioQueue &priQue1);

};

#endif /* PRIOQUEUE_HPP_ */
