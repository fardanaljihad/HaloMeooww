#include "list.h"

/*** DAFTAR PENYAKIT YANG DAPAT DILAYANI ***/
char *daftarPenyakit[9] = {
	"Penyakit Kulit", 
	"Luka Ringan", 
	"Bersin",
	"Cacingan", 
	"Diare", 
	"Luka Dalam",
	"Gangguan Kerongkongan dan Mengeluarkan Lendir Berbau Busuk", 
	"Kuning", 
	"Terkena Virus"
};

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool isAddressEmpty(addressNodeList P) {
	if(P == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool isListEmpty(List L) {
	if(L.First == NULL){
		return true;
	}
	else{
		return false;
	}
}

/**** Manajemen Memory ****/
addressNodeList Alokasi(infoPenyakit X) {
	
	addressNodeList P = (addressNodeList)malloc(sizeof(NodeList));
	
	if(P == NULL){
		return NULL;
	}
	P->	info = X;
	P->next = NULL;
	
	return P;
}

void Dealokasi(addressNodeList *P) {
	if(P == NULL){
		return;
	}
	free(P);
}

/**** Constructor ****/
void BuatList(List *L) {
	
	(*L).First = NULL; 
}

void insertToList(List *L, int indeks) {
	// Kamus Data
	addressNodeList P;
	infoPenyakit X;
	
	// Algoritma
	setInfoPenyakit(&X, indeks);
	P = Alokasi(X);
	if(isListEmpty(*L)) {
		insertFirst(&(*L), P);
	}
	else {
		insertLast(&(*L), P);
	}
}

void insertFirst(List *L, addressNodeList P) {
	
	(*L).First = P;
}

void insertLast(List *L, addressNodeList P) {
	// Kamus Data
	addressNodeList Last;
	
	// Algoritma
	Last = (*L).First;
		while(Next(Last) != NULL){
			Last = Next(Last);
		}
	Next(Last) = P;
}

/**** Destructor ****/
void HapusList(List *L) {
	
	free((*L).First);
	(*L).First = NULL;
}

/**** Accessor ****/
char *getKategori(addressNodeList P) {
	
	return P->info.kategori;
}

int getIndeksPenyakit(addressNodeList P) {
	
	return P->info.indeksPenyakit;
}

int getWaktuPelayanan(addressNodeList P) {
	
	return P->info.waktuPelayanan;
}

/**** Mutator ****/
void setInfoPenyakit(infoPenyakit *X, int indeks) {
	
	setKategori(&(*X),indeks);
	setIndeksPenyakit(&(*X),indeks);
	setWaktuPelayanan(&(*X),indeks);
}

void setKategori(infoPenyakit *X, int indeks) {
	
	if(indeks<4){
		strcpy((*X).kategori,"Penyakit Ringan");
	}else if(indeks<7){
		strcpy((*X).kategori,"Penyakit Sedang");
	}else if(indeks<10){
		strcpy((*X).kategori,"Penyakit Berat");
	}
}

void setIndeksPenyakit(infoPenyakit *X, int indeks) {
	
	(*X).indeksPenyakit = indeks;
}

void setWaktuPelayanan(infoPenyakit *X, int indeks) {
	
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
	// Kamus Data
	addressNodeList P;
	int nomor = 1;
	
	// Algoritma
	if(isListEmpty(L)) {
		printf("List is empty...");
	}
	else {
		P = L.First;
	    while(!isAddressEmpty(P)) {
			printf("%d. %s\n   Kategori : %s\n", nomor, daftarPenyakit[P->info.indeksPenyakit-1], P->info.kategori);
			nomor += 1;
			P = Next(P);
		}
	}
	
}

int hitungJumlahPenyakit(addressNodeList First) {
	
	if(isAddressEmpty(First)) {
		return 0;
	}
	else {
		return hitungJumlahPenyakit(First->next) + 1;
	}
}

