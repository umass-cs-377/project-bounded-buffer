#ifndef _BOUNDEDBUFFER_H
#define _BOUNDEDBUFFER_H

//// DO NOT MODIFY ANYTHING IN THIS FILE //////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

class BoundedBuffer {
	public:
		BoundedBuffer(int N); // constructor to initialize locks and conditional variables
		void append(int data);
		int remove();
		bool isEmpty();
	private:
		int *buffer;
		int buffer_size;
		int buffer_cnt;
		int buffer_last;

		pthread_mutex_t buffer_lock; //lock
		pthread_cond_t buffer_full; //Condition indicating buffer is full
		pthread_cond_t buffer_empty; //Condition indicating buffer is empty
};

#endif
