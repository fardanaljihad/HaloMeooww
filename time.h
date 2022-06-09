/** File      : time.h
 *  Deskripsi : File header dari ADT Time
 *  Author    : Kelompok A1
 */

#ifndef __TIME_H__
#define __TIME_H__

#include <stdio.h>

/***** Struktur Data *****/
typedef struct {
	int HH;
	int MM;
	int SS;
} Time;

/**** Constructor ****/
void createTime(Time *T);
/** Author : Fardan Al Jihad
 *  IS : T tak tentu
 *  FS : T bernilai 07:00:00
 */

/**** Accessor ****/
int getHH(Time T);	
/** Author : Reka Briyan Cahya Heryana
 *  Modul ini bertujuan untuk mendapatkan nilai HH dari Time
 *  Return : Integer
 */
int getMM(Time T);	
/** Author : Reka Briyan Cahya Heryana
 *  Modul ini bertujuan untuk mendapatkan nilai MM dari Time
 *  Return : Integer
 */

/**** Mutator ****/
void setHH(Time *T, int jam);
/** Author : Fardan Al Jihad
 *  IS : Nilai HH tak tentu atau 7
 *  FS : Nilai HH sama dengan nilai dari variabel jam
 */
 
void setMM(Time *T, int menit);
/** Author : Salma Edyna Putri
 *  IS : Nilai MM tak tentu atau 0
 *  FS : Nilai MM sama dengan nilai dari variabel menit
 */

/**** Operasi Tambahan ****/
void printTime(Time T);
/** Author : Fardan Al Jihad
 *  IS : Nilai dari T belum ditampilkan
 *  FS : Nilai dari T sudah ditampilkan berdasarkan format (HH:MM WIB)
 */

int konversiTimeKeMenit(Time T);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mengonversi Time ke Menit.
 *  Return : Integer
 */
 
Time konversiMenitKeTime(int menit);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mengonversi Menit ke Time.
 *  Return : Time
 */

#endif
