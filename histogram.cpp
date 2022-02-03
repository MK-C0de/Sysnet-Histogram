#include "histogram.hpp"


Histogram::Histogram(int sizeOfArray) {
	histogramArray = new long int[sizeOfArray];
	this->sizeOfArray = sizeOfArray;
}


void Histogram::updateHistogram(int stoppingTime) {
	histogramArray[stoppingTime] += 1;
}



void Histogram::deAllocateArray() {
	delete histogramArray;
}


void Histogram::printHistogram() {
	for(int i = 0; i < sizeOfArray; i++) {
		cout << i << "," << histogramArray[i] << endl;
	}
}
