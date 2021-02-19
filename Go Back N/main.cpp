/*
 *  Go Back N
 *  Created on: 17-Oct-2014
 *      Author: Gourav Siddhad
 */

#include "gbn.h"
using namespace std;

int main()
{
	int f,s;
	cout<<" Enter The Number Of Frames : ";
	cin>>f;
	cout<<" Enter Sequence Bit : ";
	cin>>s;
	sender(f,(pow(2,s-1)));
	return 0;
}
