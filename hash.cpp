/*
 * hash.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: chen
 */


class charHash
{
public:

	charHash(int hashSize): m_hashSize(0),
					m_hashArray(0)
	{
		char ** m_hashArray = new char *[hashSize];
	};
	~charHash() {};

//	void add(char x)
//	{
//		m_hashArray[x % m_hashSize] = x;
//	}

private:

	int m_hashSize;
	char ** m_hashArray;
};

