/*
 * CRC
 * Created on: 01-Oct-2014
 * Author: Gourav Siddhad
 */

#include "iostream"
#include "cstring"
#include "cstdio"
#include "cctype"
#include "crc.h"
#define MAX 20
using namespace std;

int main()
{
	char msg[MAX],gen[MAX],temp[MAX],trans[MAX];
	unsigned int m,g,k;

	cout<<" Enter The Message : ";
	cin>>msg;										//Input The Message To Be Transmitted
	strcpy(temp,msg);
	m=strlen(msg);

	cout<<" Enter The Generator (Must Start With 1) : ";
	cin>>gen;										//Input The Generator Polynomial
	g=strlen(gen);

	if(strlen(msg)==0 || strlen(gen)==0)
	{
		cout<<" Can't Generate Message To Be Transmitted .. ";
		return 0;
	}

	for(k=0;k<g-1;++k)								//Appending Zero's At The End Of Message
		temp[m++]='0';
	temp[m]='\0';

	strcpy(trans,temp);

	unsigned int i=0;
	while(i<=(m-g))									//Starting Divisio0n
	{
		if(temp[i]=='1'){
			for(k=0;k<g;k++)
				temp[i+k]=myxor(temp[i+k],gen[k]);
		}
		if(temp[i]=='1')
			continue;
		else
			++i;
	}

	for(k=0;k<g;k++)								//Conctatinating Last Bits To Transmitting Message
		trans[m-k]=temp[m-k];

	cout<<"\n The Message To Be Transmitted Is : ";
	cout<<trans;

	return 0;
}
