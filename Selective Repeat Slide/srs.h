/*
 * 	srs.h / Selective Repeat Slide
 *  Created on: 01-Nov-2014
 *      Author: Gourav Siddhad
 */

#ifndef SRS_H_
#define SRS_H_

#include "iostream"
#include "cstdlib"
using namespace std;

static int done=0;
void sender(int, int);
int receiver(int[],bool[],int);

void sender(const int f,const int w)
{
	int temp=0;
	int frames[w+1],win=0;
	bool ack[w+1],ackno[f+1];

	for(int j=0;j<=f;j++)
		ackno[j]=0;

	for(int i=0;i<f;)
	{
		temp=i;
		win=(f-i<w) ? (f-i):(w);
		for(int j=0; j<win; j++,i++)
		{
			frames[j]=i;
			ack[j]=ackno[i];
		}

		cout<<"\n Frames Sent : "<<win<<" | ";
		for(int j=0;j<win;j++)
			if(ack[j]==0)
				cout<<frames[j]+1<<" ";
			else
			{
				if((frames[j]+1)%100 > 10)
					cout<<" ";
				cout<<"  ";
			}

		i=receiver(frames,ack,win);
		for(int j=0;j<win;j++)
			ackno[temp+j]=ack[j];

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
		if(ack[i]==0)
			ack[i]=random;
	}

	cout<<"\n Frames Received ";
	if(win%100 > 9)
		cout<<" ";
	cout<<"| ";

	bool flag=0;
	for(int i=0;i<win;i++)
		if(ack[i]==1)
		{
			cout<<frames[i]+1<<" ";
			if(!flag)
				done++;
		}
		else
		{
			if((frames[i]+1)%100 > 9)
				cout<<" ";
			cout<<"  ";
			flag=1;
		}

	cout<<endl;
	return done;
}

#endif /* SRS_H_ */
