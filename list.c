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

void insertFirst(List *L, addressNodeList P){
	(*L).First = P;
}
void insertLast(List *L, addressNodeList P){
	addressNodeList Last;
	
	Last = (*L).First;
		while(Next(Last) != NULL){
			Last = Next(Last);
		}
	Next(Last) = P;
}

/**** Destructor ****/
void HapusList(List *L);

/**** Accessor ****/
char *getKategori(addressNodeList P){
	return P->info.kategori;
}
int getIndeksPenyakit(addressNodeList P){
	return P->info.indeksPenyakit;
}
int getWaktuPelayanan(addressNodeList P){
	return P->info.waktuPelayanan;
}

/**** Mutator ****/
void setInfoPenyakit(infoPenyakit *X, int indeks){
	setKategori(&(*X),indeks);
	setIndeksPenyakit(&(*X),indeks);
	setWaktuPelayanan(&(*X),indeks);
}
void setKategori(infoPenyakit *X, int indeks){
	if(indeks<4){
		strcpy((*X).kategori,"Penyakit Ringan");
	}else if(indeks<7){
		strcpy((*X).kategori,"Penyakit Sedang");
	}else if(indeks<10){
		strcpy((*X).kategori,"Penyakit Berat");
	}
}
void setIndeksPenyakit(infoPenyakit *X, int indeks){
	(*X).indeksPenyakit = indeks;
}
void setWaktuPelayanan(infoPenyakit *X, int indeks){
	if(indeks<4){
		(*X).waktuPelayanan = 15;
	}else if(indeks<7){
		(*X).waktuPelayanan = 30;
	}else if(indeks<10){
		(*X).waktuPelayanan = 45;
	}
}

/**** Operasi Tambahan ****/
void printList(List L){
	
}
int hitungJumlahPenyakit(addressNodeList First);

