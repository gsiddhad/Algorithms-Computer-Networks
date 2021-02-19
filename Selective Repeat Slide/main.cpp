/*
 * 	Selective Repeat Slide
 *  Created on: 01-Nov-2014
 *      Author: Gourav Siddhad
 */

#include "srs.h"
using namespace std;

int main()
{
	int f,w;
	cout<<" Enter The Number Of Frames : ";
	cin>>f;
	cout<<" Enter Window Size : ";
	cin>>w;
	sender(f,w);
	return 0;
}
