/** File      : time.c
 *  Deskripsi : File body dari ADT Time
 *  Author    : Kelompok A1
 */

#include "time.h"

/**** Constructor ****/
void createTime(Time *T) // 07:00:00
{
	(*T).HH = 7;
	(*T).MM = 0;
	(*T).SS = 0;
}

/**** Destructor ****/

/**** Accessor ****/
int getHH(Time T) 
{
	return T.HH;
}

int getMM(Time T)
{
	return T.MM;
}

/**** Mutator ****/
void setHH(Time *T, int jam) 
{
	(*T).HH = jam;
}

void setMM(Time *T, int menit) 
{
	(*T).MM = menit;
}

/**** Operasi Tambahan ****/
void printTime(Time T)
{
	if(T.HH < 10 && T.MM < 10) {
		printf("0%d:0%d WIB", getHH(T), getMM(T));
	} 
	else if(T.HH < 10 && T.MM >= 10) {
		printf("0%d:%d WIB", getHH(T), getMM(T));
	}
	else if(T.HH >= 10 && T.MM < 10) {
		printf("%d:0%d WIB", getHH(T), getMM(T));
	}
	else {
		printf("%d:%d WIB", getHH(T), getMM(T));
	}
}

int konversiTimeKeMenit(Time T) 
{
	return T.HH * 60 + T.MM;
}

Time konversiMenitKeTime(int menit)
{
	// Kamus Data
	Time T;
	
	// Algoritma
	T.HH = menit / 60;
	T.MM = menit % 60;
	
	return T;
}
