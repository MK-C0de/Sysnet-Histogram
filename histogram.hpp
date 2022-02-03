#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include <iostream>

using namespace std;


class Histogram {

	private:
		long int *histogramArray;
		int sizeOfArray;	
	
	public:
		Histogram(int sizeOfArray);
		
		void updateHistogram(int stoppingTime);

		void printHistogram();

		void deAllocateArray();
};

#endif
