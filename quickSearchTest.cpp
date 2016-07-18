/*
 * quickSotTest.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: chen
 */

#include <vector>
#include <iostream>
using namespace std;

int quickSearch(int data, vector<int> &arr, int start, int end)
{
	if (end < start) return -1;
	int mid = (start + end) /2;

	if (data == arr[mid])
		return mid;
	else if (data > arr[mid])
		return quickSearch(data, arr, mid+1, end);
	else
		return quickSearch(data, arr, start, mid-1);
}

void quickSearchTest()
{
	vector<int> arr{ -10, -5, 1, 3, 5, 8 ,20, 100};
	cout << quickSearch(3, arr, 0, arr.size()) <<endl;
	cout << quickSearch(4, arr, 0, arr.size()) <<endl;
}


