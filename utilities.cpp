/*
 * utilities.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: chen
 */

#include "utilities.h"
#include <iostream>
using namespace std;

utilities::utilities() {
	// TODO Auto-generated constructor stub

}

utilities::~utilities() {
	// TODO Auto-generated destructor stub
}

void utilities::swapmethod4(int &a, int &b)
{
     a=a^b;
     b=a^b;
     a=a^b;
     cout << "swap "<< a<<" " <<b << endl;
}
