/*
 * MergeSort.h
 *
 *  Created on: Jun 15, 2016
 *      Author: chen
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

class MergeSort {
public:
	MergeSort(int data[], int size);
	virtual ~MergeSort();
	void sort();
private:
	int m_n;
	int * m_data;

};

#endif /* MERGESORT_H_ */
