#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

/***** Struktur Data *****/
typedef struct tInfoCustomer {
	char namaPemilik[20];
	char namaHewan[20];
	int waktuKedatangan;
	List daftarPenyakit;
	int nilaiPrioritas;
	int estimasiWaktuMulai;
	int estimasiWaktuPelayanan;
	int estimasiWaktuSelesai;
} infoCustomer;

typedef struct tNodeQueue *addressNodeQueue;
typedef struct tNodeQueue {
	infoCustomer info;
	addressNodeQueue next;
} NodeQueue;

typedef struct {
	addressNodeQueue Head;
	addressNodeQueue Tail;
} Queue;

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool addressEmpty(addressNodeQueue P);
bool queueEmpty(Queue Q);

/**** Manajemen Memory ****/
addressNodeQueue alokasiNodeQueue(infoCustomer X);
void dealokasiNodeQueue(addressNodeQueue *P);

/**** Constructor ****/
void buatAntrian(Queue *Q);
void enqueue(Queue *Q, infoCustomer X);
void insertAfter(Queue *Q, addressNodeQueue P);

/**** Destructor ****/
void hapusAntrian(Queue *Q);
void dequeue(Queue *Q);

/**** Accessor ****/


/**** Mutator ****/
void setInfoCustomer(infoCustomer *X, char namaPemilik[20], char namaHewan[20], int waktuKedatangan, List data);
void setNamaPemilik(infoCustomer *X, char namaPemilik[20]);
void setNamaHewan(infoCustomer *X, char namaHewan[20]);
void setWaktuKedatangan(infoCustomer *X, int waktuKedatangan);
void setDaftarPenyakit(infoCustomer *X, List data);
void setNilaiPrioritas(infoCustomer *X, List L);
void setEstimasiWaktuMulai(infoCustomer *X, int estimasiWaktuMulai);
void setEstimasiWaktuPelayanan(infoCustomer *X, List L);
void setEstimasiWaktuSelesai(infoCustomer *X, int estimasiWaktuSelesai);

/**** Operasi Tambahan ****/
void printQueue(Queue Q);
int hitungNilaiPrioritas(List L);
int hitungWaktuMulai(Queue Q);
int hitungWaktuPelayanan(List L);
int hitungWaktuSelesai(Queue Q);
void hitungWaktu(Queue *Q);





#endif
