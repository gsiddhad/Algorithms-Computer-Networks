/*
 * crc.h / CRC
 * Created on: 01-Oct-2014
 * Author: Gourav Siddhad
 */

#ifndef CRC_H_
#define CRC_H_

char myxor(char,char);

char myxor(char x,char y)
{
	if(x==y)
		return '0';
	else
		return '1';
}

#endif /* CRC_H_ */
