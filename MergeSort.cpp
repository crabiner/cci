/*
 * MergeSort.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: chen
 */

#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(int data[], int size) {
		m_data = new int[size];
		m_n = size;
		m_data = data;

		for (int i=0; i<size; i++)
		{
			cout << " "<<data[i];
		}
}

void merge(int *data, int size, int low, int middle, int high)
{
	if (size == 1)
		return;

	int * scratch = new int[size];
	int l = low;
	int h = middle+1;

	cout <<"merge low= "<<low<< " middle= "<<  middle  << " high= "<<  high  <<" size= "<< size<<endl;


	for (int i =0 ; i< size ; i++)
	{
		if (	(l <= (middle)) &&
				(h == (high +1)  || (data[l] < data[h]))
				)
		{
			scratch[i] = data[l];
			l++;
		}
		else
		{
			scratch[i] = data[h];
			h++;
		}
	}
	for (int i=0; i< (size); i++)
		data[low+i] = scratch[i];
	delete [] scratch;
}

void recursiveMergeSort(int *pData, int size, int low, int high)
{
	cout <<  "size="<<size<<" low= "<<low << " high= "<<  high  <<endl;
	if (low < high)
	{
		int middle = (low + high)/2;
		//recursively mergesort the Lower half
		recursiveMergeSort(pData, middle + 1 - low, low, middle);

		//recursively mergesort the Higher half
		recursiveMergeSort(pData, high - middle, middle + 1, high);
		// Merge together sorted
		merge(pData, size, low, middle, high);
	}

	for (int i=low; i<(low+size); i++)
	{
		cout << " "<<pData[i];
	}
	cout <<endl;
}

void MergeSort::sort()
{
	int sorted[m_n];
	recursiveMergeSort(m_data, m_n , 0, m_n - 1);
}

MergeSort::~MergeSort() {
	cout <<endl<< "Free resources" <<endl;
	// TODO Auto-generated destructor stub
	delete [] m_data;
}


