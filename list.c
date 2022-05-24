#include "list.h"

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool isAddressEmpty(addressNodeList P){
	if(P == NULL){
		return true;
	}
	else{
		return false;
	}
}
bool isListEmpty(List L){
	if(L.First == NULL){
		return true;
	}
	else{
		return false;
	}
}

/**** Manajemen Memory ****/
addressNodeList Alokasi(infoPenyakit X){
	addressNodeList P = (addressNodeList)malloc(sizeof(NodeList));
	if(P ==NULL){
		return NULL;
	}
	P->	info = X;
	P->next = NULL;
	return P;
}
void Dealokasi(addressNodeList *P){
	if(P == NULL){
		return;
	}
	free(P);
}

/**** Constructor ****/
void BuatList(List *L){
	(*L).First = NULL; 
}

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

