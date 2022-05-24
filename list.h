#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tInfoPenyakit {
	char kategori[10];
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
bool isAddressEmpty(addressNodeList P);
bool isListEmpty(List L);

/**** Manajemen Memory ****/
addressNodeList Alokasi(infoPenyakit X);
void Dealokasi(addressNodeList *P);

/**** Constructor ****/
void BuatList(List *L);
void insertToList(List *L, int indeks);
void insertFirst(List *L, addressNodeList P);
void insertLast(List *L, addressNodeList P);

/**** Destructor ****/
void HapusList(List *L);

/**** Accessor ****/
char *getKategori(addressNodeList P);
int getIndeksPenyakit(addressNodeList P);
int getWaktuPelayanan(addressNodeList P);

/**** Mutator ****/
void setInfoPenyakit(infoPenyakit *X, int indeks);
void setKategori(infoPenyakit *X, int indeks);
void setIndeksPenyakit(infoPenyakit *X, int indeks);
void setWaktuPelayanan(infoPenyakit *X, int indeks);

/**** Operasi Tambahan ****/
void printList(List L);
int hitungJumlahPenyakit(addressNodeList First);

#endif
