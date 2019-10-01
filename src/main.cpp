#include "ProducerConsumer.h"

int main(int argc, char* argv[]){
	if (argc !=6){
		printf("usage: prodcon #producers #consumers #psleep #csleep #items\n");
        return 1;
	}

	int p = atoi(argv[1]); // number of producer threads
	int c = atoi(argv[2]); //number of consumer threads
	int psleep = atoi(argv[3]); //sleep time for producer in ms
	int csleep = atoi(argv[4]); //sleep time for consumer in ms
	int items = atoi(argv[5]); //total number of data items

	InitProducerConsumer(p,c,psleep,csleep,items);

	return 0;
}