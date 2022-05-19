#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct tNodeQueue *addressNodeQueue;
typedef struct tNodeQueue {
	char namaPemilik[20];
	char namaHewan[20];
	List daftarPenyakit;
	int nilaiPrioritas;
	int waktuKedatangan;
	int waktuMulai;
	int waktuPelayanan;
	int waktuSelesai;
} NodeQueue;
typedef struct {
	addressNodeQueue Front;
	addressNodeQueue Rear;
} Queue;

void CreateQueue(Queue *Q);

#endif
