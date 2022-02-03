#include "histogram.hpp"

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <time.h>

using namespace std;


//Global variable
long int COUNTER;
long int numRange;
mutex mu;
Histogram histogramArray(600);


void computeCollatzSeq() {
	
	//Need to Fix Race Condition most likely due to COUNTER Variable in while loop
	while(COUNTER < numRange) {
	mu.lock();
	long int value = COUNTER;
	long int stoppingTime = 1;
	++COUNTER;
	mu.unlock();

		do {
			cout << "counter: " << COUNTER << endl;//
			if(value % 2 == 0) {
				value = value / 2;
				cout << "   even" << endl;//
			}
			else {
				value = (3 * value) + 1;
				cout << "   odd" << endl;//
			}
			if(value != 1) {
				++stoppingTime;
			}
		}
		while(value != 1);
		cout << "   VALUE IS 1" << endl;//

	/*
	mu.lock();
	//cout << COUNTER -1 <<":" << stoppingTime << endl; //Used for Debugging
	histogramArray.updateHistogram(stoppingTime);
	mu.unlock();
	*/
	
	}
}


int main(int argc, char *argv[]) {
	
	//Initialize Global Variables
	COUNTER = 2;
	numRange = atoi(argv[1]);

	//Initialize Threads
	int numThreads = atoi(argv[2]);
	thread threads[numThreads];

	struct timespec start, stop;

	clock_gettime(CLOCK_REALTIME, &start);
	

	//Create Threads
	for(int i = 0; i < numThreads; i++) {
		threads[i] = thread(computeCollatzSeq);
	}

	/*
	//Wait for threads to join main thread
	for(int i = 0; i < numThreads; i++) {
		threads[i].join();
	}

	
	clock_gettime(CLOCK_REALTIME, &stop);
	
	//Calculate the Time in nanoseconds

	cerr << numRange << "," << numThreads << "," << start.tv_nsec << endl;	
	
	//cout << endl;
	//cout << COUNTER << endl; //Used for debugging if COUNTER is not one over numRange then it's experiencing a race condition
	
	histogramArray.printHistogram();

	histogramArray.deAllocateArray();	
	*/
	return 0;
}

