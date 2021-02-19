/*
 *  gbn.h / Go Back N
 *  Created on: 17-Oct-2014
 *      Author: Gourav Siddhad
 */

#ifndef GBN_H_
#define GBN_H_

#include "iostream"
#include "cstdlib"
#include "cmath"
using namespace std;

static int done=0;
void sender(int, int);
int receiver(int[],bool[],int);

void sender(int f,const int w)
{
	int frames[w+1],win=0;
	bool ack[w+1];

	for(int j=0;j<=w;j++)
		ack[j]=0;

	for(int i=0;i<f;)
	{
		win=(f-i<w) ? (f-i):(w);
		for(int j=0; j<win; j++,i++)
			frames[j]=i;

		cout<<"\n Frames Sent : "<<win<<" | ";
		for(int j=0;j<win;j++)
			cout<<frames[j]+1<<" ";

		i=receiver(frames,ack,win);
		if(i==frames[0])
			cout<<"\n Time Out... Resending... ";
	}
}

int receiver(int frames[],bool ack[],int win)
{
	bool random=0;
	for(int i=0;i<win;i++)
	{
		switch(rand()%4)
		{
			case 0:
			case 1:
			case 2:
				random=1;
				break;
			default:
				random=0;
		}
		ack[i]=random;
	}

	cout<<"\n Frames Received ";
		if(win%100 > 9)
			cout<<" ";
		cout<<"| ";

	for(int i=0;i<win && ack[i];i++,done++)
		cout<<frames[i]+1<<" ";
	cout<<endl;
	return done;
}

#endif /* GBN_H_ */
