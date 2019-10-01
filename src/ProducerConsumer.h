#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include "BoundedBuffer.h"

using namespace std;

// DO NOT modify any code here
void InitProducerConsumer(int p, int c, int psleep, int csleep, int items);
void *producer(void*);
void *consumer(void*);

#endif
