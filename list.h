/** File      : lis.h
 *  Deskripsi : File header dari ADT List dengan alokasi dinamis
 *  Author    : Kelompok A1
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Next(P) P->next

typedef struct tInfoPenyakit {
	char kategori[18];
	int indeksPenyakit;
	int waktuPelayanan;
} infoPenyakit;

typedef struct tNodeList *addressNodeList; 
typedef struct tNodeList {
	infoPenyakit info;
	addressNodeList next;
} NodeList;

typedef struct {
	addressNodeList First;
} List;

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool isAddressEmpty(addressNodeList P);	// R
bool isListEmpty(List L);	// R

/**** Manajemen Memory ****/
addressNodeList Alokasi(infoPenyakit X);	// R
void Dealokasi(addressNodeList P);	// R

/**** Constructor ****/
void BuatList(List *L);	// R
void insertToList(List *L, int indeks);
/** Author : Fardan Al Jihad
 *  FS : Info penyakit customer belum dimasukkan ke List
 *  IS : Info penyakit customer sudah dimasukkan ke List
 */

void addFirst(List *L, addressNodeList P);
/** Author : Salma Edyna Putri
 *  IS : Info penyakit customer belum dimasukkan ke List
 *  FS : Info penyakit customer sudah dimasukkan ke List posisi pertam
 */
 
void addLast(List *L, addressNodeList P);
/** Author : Salma Edyna Putri
 *  IS : Info penyakit customer belum dimasukkan ke List
 *  FS : Info penyakit customer sudah dimasukkan ke List posisi terakhir
 */

/**** Destructor ****/
void HapusList(List L);
/** Author : Fardan Al Jihad
 *  FS : List belum dihapus
 *  IS : List sudah dihapus
 */

/**** Accessor ****/
char *getKategori(addressNodeList P);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mendapatkan kategori penyakit
 *  Return : char[18]
 */
 
int getIndeksPenyakit(addressNodeList P);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mencari alamat berdasarkan nama hewan.
 *  Return : addressNodeQueue
 */
 
int getWaktuPelayanan(addressNodeList P);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mendapatkan indeks penyakit.
 *  Return : Integer
 */

/**** Mutator ****/
void setInfoPenyakit(infoPenyakit *X, int indeks);
/** Author : Salma Edyna Putri
 *  IS : list infoPenyakit belum berisi data apapun.
 *  FS : list infoPenyakit sudah berisi data seperti kategori, 
 *		 indeks penyakit dan waktu pelayanan
 */
 
void setKategori(infoPenyakit *X, int indeks);
/** Author : Salma Edyna Putri
 *  IS : Kategori penyakit belum diketahui
 *  FS : Kategori penyakit sudah diketahui
 */
 
void setIndeksPenyakit(infoPenyakit *X, int indeks);
/** Author : Salma Edyna Putri
 *  IS : Indeks pada penyakit belum diketahui
 *  FS : Indeks pada penyakit diketahui
 */
 
void setWaktuPelayanan(infoPenyakit *X, int indeks);
/** Author : Salma Edyna Putri
 *  IS : Waktu pelayanan penyakit belum diketahui
 *  FS : Waktu pelayanan penyakit diketahui
 */

/**** Operasi Tambahan ****/
void printList(List L);
/** Author : Fardan Al Jihad
 *  FS : List belum ditampilkan ke layar
 *  IS : List sudah ditampilkan ke layar
 */

int hitungJumlahPenyakit(addressNodeList First);
/** Author : Fardan Al Jihad
 *  FS : Jumlah penyakit belum diketahui
 *  IS : Jumlah penyakit diketahui
 */

#endif
