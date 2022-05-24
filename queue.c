#include "queue.h"

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool addressEmpty(addressNodeQueue P){
	if(P == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool queueEmpty(Queue Q) {
	
	return ((Q.Head == NULL) && (Q.Tail == NULL));
}

/**** Manajemen Memory ****/
addressNodeQueue alokasiNodeQueue(infoCustomer X){
	addressNodeQueue P = (addressNodeQueue)malloc(sizeof(NodeQueue));
	
	if(P == NULL){
		return NULL;
	}
	P->	info = X;
	P->next = NULL;
	
	return P;
}

void dealokasiNodeQueue(addressNodeQueue *P){
	if(P == NULL){
		return;
	}
	free(P);
}

/**** Constructor ****/
void buatAntrian(Queue *Q){
	(*Q).Head = NULL;
	(*Q).Tail = NULL;
}

void enqueue(Queue *Q, infoCustomer X);
void insertAfter(Queue *Q, addressNodeQueue P);

/**** Destructor ****/
void hapusAntrian(Queue *Q);
void dequeue(Queue *Q);

/**** Accessor ****/


/**** Mutator ****/
void setInfoCustomer(infoCustomer *X, char namaPemilik[20], char namaHewan[20], int waktuKedatangan, List data);
void setNamaPemilik(infoCustomer *X, char namaPemilik[20]){
	strcpy((*X).namaPemilik, namaPemilik);
}

void setNamaHewan(infoCustomer *X, char namaHewan[20]){
	strcpy((*X).namaHewan, namaHewan);
}

void setWaktuKedatangan(infoCustomer *X, int waktuKedatangan){
	(*X).waktuKedatangan = waktuKedatangan;
}

void setDaftarPenyakit(infoCustomer *X, List data);
void setNilaiPrioritas(infoCustomer *X, List L);
void setEstimasiWaktuMulai(infoCustomer *X, int estimasiWaktuMulai);

void setEstimasiWaktuPelayanan(infoCustomer *X, List L) {
	// Kamus Data
	addressNodeList P;
	int totalWaktu = 0;
	
	// Algoritma
	P = L.First;
	while(!isAddressEmpty(P)) {
		if(strcmp(P->info.kategori, "Ringan") == 0) {
			totalWaktu += 15;
		}
		else if(strcmp(P->info.kategori, "Sedang") == 0) {
			totalWaktu += 30;
		}
		else if(strcmp(P->info.kategori, "Berat") == 0) {
			totalWaktu += 45;
		}
		P = P->next;
	}
	
	(*X).estimasiWaktuPelayanan = totalWaktu;
}

void setEstimasiWaktuSelesai(infoCustomer *X, int estimasiWaktuSelesai);

/**** Operasi Tambahan ****/
void printQueue(Queue Q);

int hitungNilaiPrioritas(List L) {
	// Kamus Data
	addressNodeList P;
	int Ringan = 0;
	int Sedang = 0;
	int Berat  = 0;
	int nilaiPrioritas = 0;
	
	// Algoritma
	P = L.First;
	while(!isAddressEmpty(P)) {
		if(strcmp(P->info.kategori, "Ringan") == 0) {
			Ringan++;
		}
		else if(strcmp(P->info.kategori, "Sedang") == 0) {
			Sedang++;
		}
		else if(strcmp(P->info.kategori, "Berat") == 0) {
			Berat++;
		}
		P = P->next;
	}
	
	if(Berat >= 1) {
		nilaiPrioritas = 4;
	}
	else if(Sedang >= 2) {
		nilaiPrioritas = 3;
	}
	else if(Ringan >= 3) {
		nilaiPrioritas = 2;
	}
	else {
		nilaiPrioritas = 1;
	}
	
	return nilaiPrioritas;
}

int hitungWaktuMulai(Queue Q);
int hitungWaktuPelayanan(List L);
int hitungWaktuSelesai(Queue Q);
void hitungWaktu(Queue *Q);
