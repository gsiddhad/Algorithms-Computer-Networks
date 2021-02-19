/*
 *  snw.h / Stop N Wait
 *  Created on: 17-Oct-2014
 *      Author: Gourav Siddhad
 */

#ifndef SNW_H_
#define SNW_H_

#include "iostream"
#include "cstdlib"
using namespace std;

static bool r=0;
void sender(int);
int receiver(int);

void sender(int n)
{
     int rec=0;
     for(int i=0;i<n;i++)
     {
          cout<<"\n Sending Frame : "<<i<<" Bit Number : "<<(i%2);
          rec = receiver(i%2);
          if((i%2)==rec)
          {
        	  if(rand()%2==0)
          		  cout<<"\n Frame Not Received .. Resending .. ";
          	  else
          		  cout<<"\n Timed Out .. Resending .. ";
          	  i--;
          }
          else
        	  cout<<"\n Acknowledgment Received .. Sending Next .. \n";
     }
}

int receiver(int fbit)
{
	switch(rand()%2)
	{
	case 0:
		if(r==fbit)
		{
			cout<<"\n Frame Received .. Sending Acknowledgment .. ";
			r=!fbit;
			return r;
		}
		else
		{
			cout<<"\n Frame Already Received .. Resending Acknowledgment .. ";
			return r;
		}
	case 1:
		return r;
	}
	return r;
}

#endif /* SNW_H_ */
