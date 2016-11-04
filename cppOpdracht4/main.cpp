/*
 * main.cpp
 *
 *  Created on: May 24, 2013
 *      Author: Rens Visser
 */
//Look into forward_list
#include <iostream>
#include  "prioqueue.hpp"
#include "prioqueue.cpp"

using namespace std;

int main(int argc, char *argv[]){
	prioQueue<int> b, a;
	b.dequeue();//(5);
	b.enqueue(6);
	b.enqueue(1);
	b.enqueue(2);
	b.enqueue(3);
	b.enqueue(3);
	b.enqueue(7);
	b.enqueue(10);
	a.enqueue(111);
	b.operator* (a);
	b.operator <<(b);
	return 0;
}
