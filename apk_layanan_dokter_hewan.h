#ifndef __APK_LAYANAN_DOKTER_HEWAN__
#define __APK_LAYANAN_DOKTER_HEWAN__

#include "queue.h"

typedef struct {
	char namaHewan[20];
	char namaPemilik[20];
	int jmlPenyakit;
	int indeksPenyakit[9];
	int tanggal[3];
	Time waktu;
} riwayatCust;

/**** Fitur ****/
void Registrasi(Queue *Q);
/** Author : Fardan Al Jihad
 *  IS : Customer belum diregistrasi
 *  FS : Customer sudah diregistrasi
 */

void ProsesAntrian(Queue *Q);
/** Author : Salma Edyna Putri
 *  IS : Antrian belum ada yang diproses
 *  FS : Antrian diproses
 */
 
void HapusAntrian(Queue *Q);
/** Author : Reka Briyan Cahya Heryana
 *  IS : Customer ada di dalam antrian
 *  FS : Customer berhasil dihapus dari antrian
 */

void Riwayat();
/** Author : Fardan Al Jihad
 *  IS : Mencari riwayat penyakit customer sesuai inputan user
 *  FS : Menampilkan riwayat penyakit customer jika ditemukan
 */
 
void simpanDataAntrian(Queue *Q);
/** Referensi : Kelompok A7
 *  Modified by : Fardan Al Jihad
 *  IS : Data customer belum disimpan di file
 *  FS : Data customer sudah disimpan di file
 */

void tampilkanRiwayat(char namaHewan[20], char namaPemilik[20]);
/** Referensi : Kelompok A7
 *  Modified by : Fardan Al Jihad
 *  IS : Riwayat penyakit customer belum ditampilkan
 *  FS : Menampilkan riwayat penyakit customer
 */
 
void ShowMenu();
void MainMenu();
void Exit();

#endif
