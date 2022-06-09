/** File      : queue.h
 *  Deskripsi : File header dari ADT Queue dengan alokasi dinamis
 *  Author    : Kelompok A1
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "time.h"

/***** Struktur Data *****/
typedef struct tInfoCustomer {
	char namaPemilik[20];
	char namaHewan[20];
	Time waktuKedatangan;
	List daftarPenyakit;
	int nilaiPrioritas;
	Time estimasiWaktuMulai;
	int estimasiWaktuPelayanan;
	Time estimasiWaktuSelesai;
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
/**** Modul untuk memeriksa keadaan pointer ke node queue dan antrian ****/
bool addressEmpty(addressNodeQueue P);
/** Author : Reka
 *  Mengirim true jika pointer kosong atau mengirim false
 *  jika pointer tidak kosong
 */
 
bool queueEmpty(Queue Q);
/** Author : Fardan Al Jihad
 *  Mengirim true jika antrian kosong atau mengirim false
 *  jika antrian tidak kosong
 */

/**** Manajemen Memory ****/
addressNodeQueue alokasiNodeQueue(infoCustomer X);
/** Author : Reka Briyan Cahya Heryanas
 *  Modul ini bertujuan untuk mengalokasikan memori
 *  Return :
 *  addressNodeQueue
 */
void dealokasiNodeQueue(addressNodeQueue P);
/** Author : Reka Briyan Cahya Heryana
 *  Modul ini bertujuan untuk mendealokasi elemen P yang menunjuk
 *  ke alamat queue
 *  IS : P terdefinisi
 *  FS : P dikembalikan ke sistem
 */

/**** Constructor ****/
void buatAntrian(Queue *Q);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Antrian belum ada
 *  FS : Antrian sudah dibuat
 */
void enqueue(Queue *Q, infoCustomer X);	
/** Author : Fardan Al Jihad
 *  IS : Antrian mungkin kosong atau antrian berisi antrian
 *  FS : Customer dengan data X berhasil dimasukkan ke dalam antrian
 *		 dengan urutan sesuai nilai prioritas atau waktu kedatangannya
 */
 
void insertFirst(Queue *Q, addressNodeQueue pNew);
/** Author : Salma Edyna Putri
 *  IS : Queue bagian Head mungkin kosong atau sudah berisi data
 *  FS : Menambahkan elemen pertama dengan nilai pNew
 */
 
void insertAfter(Queue *Q, addressNodeQueue P, addressNodeQueue pNew);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Queue bagian HEAD mungkin kosong atau sudah berisi data
 *  FS : Menambahkan elemen pertama dengan nilai pNew
 */
void insertLast(Queue *Q, addressNodeQueue pNew);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Queue mungkin kosong atau sudah berisi data
 *  FS : Menambahkan elemen di akhir/Tail Queue
 */

/**** Destructor ****/
void hapusAntrian(Queue *Q, char namaHewan[20]);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Customer ada di dalam antrian
 *  FS : Customer berhasil dihapus dari antrian
 */
void dequeue(Queue *Q);
/** Author : Salma Edyna Putri
 *  IS : Customer ada di dalam antrian
 *  FS : Customer berhasil dihapus dari antrian
 */

/**** Mutator ****/
void setInfoCustomer(infoCustomer *X, char namaPemilik[20], char namaHewan[20], Time waktuKedatangan, List data);
/** Author : Salma Edyna Putri
 *  IS : Data customer belum dimasukkan ke X
 *  FS : Data customer berhasil dimasukkan ke X
 */
 
void setNamaPemilik(infoCustomer *X, char namaPemilik[20]);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Data nama pemilik belum dimasukkan ke dalam record
 *  FS : Data nama pemilik berhasil dimasukkan ke dalam record
 */
void setNamaHewan(infoCustomer *X, char namaHewan[20]);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Data nama hewan belum dimasukkan ke dalm record
 *  FS : Data nama hewan berhasil dimasukkan ke dalma record
 */
void setWaktuKedatangan(infoCustomer *X, Time waktuKedatangan);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Waktu kedatangan customer belum dimasukkan ke dala record
 *  FS : Waktu kedatangan customer berhasil dimasukkan ke dalam record
 */
void setDaftarPenyakit(infoCustomer *X, List data);
/** Author : Salma Edyna Putri
 *  IS : Daftar penyakit customer belum dimasukkan ke dalam record
 *  FS : Daftar penyakit customer berhasil dimasukkan ke dalam record
 */
 
void setNilaiPrioritas(infoCustomer *X, List L);
/** Author : Salma Edyna Putri
 *  IS : Nilai prioritas customer belum dimasukkan ke dalam record
 *  FS : Nilai prioritas customer berhasil dimasukkan ke dalam record
 */
 
void setEstimasiWaktuMulai(Queue Q, addressNodeQueue pNew);
/** Author : Fardan Al Jihad
 *  IS : Estimasi waktu mulai customer belum dimasukkan ke dalam record
 *  FS : Estimasi waktu mulai customer berhasil dimasukkan ke dalam record
 */
 
void setEstimasiWaktuPelayanan(infoCustomer *X, List L);
/** Author : Fardan Al Jihad
 *  IS : Estimasi waktu pelayanan customer belum dimasukkan ke dalam record
 *  FS : Estimasi waktu pelayanan customer berhasil dimasukkan ke dalam record
 */
 
void setEstimasiWaktuSelesai(Queue Q, addressNodeQueue pNew);
/** Author : Fardan Al Jihad
 *  IS : Estimasi waktu selesai customer belum dimasukkan ke dalam record
 *  FS : Estimasi waktu selesai customer berhasil dimasukkan ke dalam record
 */
 
void setLast(Queue *Q);
/** Author : Fardan Al Jihad
 *  IS : Tail dari antrian tak tentu
 *  FS : Tail dari antrian sudah berada di ujung antrian
 */

/**** Operasi Tambahan ****/
void printQueue(Queue Q);
/** Author : Salma Edyna Putri
 *  IS : Informasi antrian belum ditampilkan
 *  FS : Informasi antrian berhasil ditampilkan
 */
int hitungNilaiPrioritas(List L);
/** Author : Fardan Al Jihad
 *  Modul ini bertujuan untuk menghitung nilai prioritas customer
 *  Return : Integer
 */
 
Time hitungWaktuMulai(Queue Q, addressNodeQueue pNew);
/** Author : Fardan Al Jihad
 *  Modul ini bertujuan untuk menghitung waktu mulai pemeriksaan customer
 *  Return : Time
 */
 
int hitungWaktuPelayanan(List L);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk menghitung estimasi waktu pelayanan customer.
 *  Return : Integer
 */
 
Time hitungWaktuSelesai(Queue Q, addressNodeQueue pNew);	
/** Author : Reka Briyan Cahya Heryana
 *  Modul ini bertujuan untuk menghitung estimasi waktu selesai customer
 *  Return : Time
 */
void hitungWaktu(Queue *Q, addressNodeQueue pNew);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Waktu mulai dan waktu selesai belum diperbaharui
 *  FS : Waktu mulai dan waktu selesai sudah diperbaharui
 */

addressNodeQueue searchByNilaiPrioritas(Queue Q, int nilaiPrioritas);
/** Author : Fardan Al Jihad
 *  Modul ini bertujuan untuk mencari data berdasarkan nilai prioritas
 *  Return : addressNodeQueue
 */
 
addressNodeQueue searchByAddress(Queue Q, addressNodeQueue pNew);
/** Author : Reka Briyan Cahya Heryana
 *  Modul ini bertujuan untuk mencari data mencari data berdasarkan addressnya
 *  Return : addressNodeQueue
 */

addressNodeQueue searchBefore(Queue Q, addressNodeQueue P);
/** Author : Fardan Al Jihad
 *  Modul ini bertujuan untuk mencari alamat antrian sebelumnya
 *  Return : addressNodeQueue
 */
 
addressNodeQueue searchByName(Queue Q, char namaHewan[20]);
/** Author : Salma Edyna Putri
 *  Modul ini bertujuan untuk mencari alamat berdasarkan nama hewan.
 *  Return : addressNodeQueue
 */

#endif
