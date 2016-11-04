/*
 * main.cpp
 *
 *  Created on: May 24, 2013
 *  Author: Rens Visser
 */

#include "prioqueue.hpp"
#include <assert.h>
#include <iostream>

template <class myType>
void prioQueue<myType>::enqueue(myType item){
    pq_keys.push_back(item);
    shiftLeft(0, pq_keys.size() - 1);
}

template <class myType> myType prioQueue<myType>::dequeue(){
    assert(pq_keys.size() != 0);
    int last = pq_keys.size() - 1;
    int tmp = pq_keys[0];
    pq_keys[0] = pq_keys[last];
    pq_keys[last] = tmp;
    pq_keys.pop_back();
    shiftRight(0, last-1);
    return tmp;
}

template <class myType>
void prioQueue<myType>::print()
{
    int size = pq_keys.size();
    for (int i = 0; i < size; ++i)
        cout << pq_keys[i] << "  | ";
    cout << endl;
}

template <class myType>
void prioQueue<myType>::shiftLeft(int low, int high)
{
    int childIdx = high;
    while (childIdx > low)
    {
        int parentIdx = (childIdx-1)/2;
        /*if child is bigger than parent we need to swap*/
        if (pq_keys[childIdx] > pq_keys[parentIdx])
        {
            int tmp = pq_keys[childIdx];
            pq_keys[childIdx] = pq_keys[parentIdx];
            pq_keys[parentIdx] = tmp;
            /*Make parent index the child and shift towards left*/
            childIdx = parentIdx;
        }
        else
        {
            break;
        }
    }
    return;
}

template <class myType>
void prioQueue<myType>::shiftRight(int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (pq_keys[swapIdx] < pq_keys[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (pq_keys[swapIdx] < pq_keys[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = pq_keys[root];
            pq_keys[root] = pq_keys[swapIdx];
            pq_keys[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}

template <class myType>
void prioQueue<myType>::buildHeap()
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int size = pq_keys.size();
    int midIdx = (size -2)/2;
    while (midIdx >= 0)
    {
        shiftRight(midIdx, size-1);
        --midIdx;
    }
    return;
}

//queue 2 invoegen in 1.
template <class myType>
void prioQueue<myType>::operator+(const prioQueue &priQue1){
	int i = 0;
	;
	for(i; i<priQue1.pq_keys.size(); i++){
		this->enqueue(priQue1.pq_keys[i]);
	}
}

//nieuwe quemaken en invoegen oude 2;
template <class myType>
void prioQueue<myType>::operator*(const prioQueue &priQue1){
	unsigned int i = 0;
	prioQueue *priQue2 = new prioQueue();
	for(i; i<priQue1.pq_keys.size(); i++){
			priQue2->enqueue(priQue1.pq_keys[i]);
	}

	for(i=0; i<this->pq_keys.size(); i++){
				priQue2->enqueue(this->pq_keys[i]);
		}
		this->pq_keys = priQue2->pq_keys;
}

//uit printen van queue
template <class myType>
void prioQueue<myType>::operator<<(prioQueue &priQue1){
	priQue1.print();
}
