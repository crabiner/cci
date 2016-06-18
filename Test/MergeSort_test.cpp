/*
 * MergeSort_test.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: chen
 */

#include "../MergeSort.h"

void MergeSortTest()
{
	int unsorted1[] = {4,7,5,9,1,0,8,12};
	MergeSort ms(unsorted1, sizeof(unsorted1)/sizeof(int));
	ms.sort();
}
