/*
 * is_unique.cpp

Is Unique:
Implement an algorithm to determine if a string has all
unique characters.
What if you cannot use additional data structures?
 *
 *  Created on: Jun 14, 2016
 *      Author: chen
 */
#include <iostream>


#include "Test/MergeSort_test.h"

using namespace std;

class MyStr
{
public:
	MyStr(string inputString);
	~MyStr() {};
	bool isUniqueAscii();

private:

	string m_str;
	//returns true if a string has all unique characters.
};


MyStr::MyStr(string inputString)
{
	m_str = inputString;
}

bool MyStr::isUniqueAscii()
{
	const char * pStr = m_str.c_str();
	char asciiArray[256]= {0};

	for (int i=0; pStr[i]!=0; i++)
	{
		if (asciiArray[pStr[i]] == 0)
			asciiArray[pStr[i]] = 1;
		else
		{
			cout << m_str << " is not Unique" <<endl;
			return false;
		}
	}
	cout << m_str << " isUnique" <<endl;
	return true;
};



int main()
{
#if 0
	string str("aAbb");
	MyStr string1("aAbb");
	string1.isUniqueAscii();

	MyStr string2("aAbcdefgBCD");
	string2.isUniqueAscii();
#else
	MergeSortTest();
#endif
	return 0;
}


