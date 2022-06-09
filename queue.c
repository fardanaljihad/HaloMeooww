/** File      : queue.c
 *  Deskripsi : File body dari ADT Queue dengan alokasi dinamis
 *  Author    : Kelompok A1
 */

#include "queue.h"

/**************** PROTOTYPE ****************/
/**** Validator ****/
bool addressEmpty(addressNodeQueue P) 
{
	if(P == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool queueEmpty(Queue Q) 
{	
	return ((Q.Head == NULL) && (Q.Tail == NULL));
}

/**** Manajemen Memory ****/
addressNodeQueue alokasiNodeQueue(infoCustomer X)
{
	addressNodeQueue P = (addressNodeQueue)malloc(sizeof(NodeQueue));
	
	if(addressEmpty(P)){
		printf("Alokasi gagal...");
		return;
	}
	P->info = X;
	P->next = NULL;
	
	return P;
}

void dealokasiNodeQueue(addressNodeQueue P) 
{	
	free(P);
	(P) = NULL;
}

/**** Constructor ****/
void buatAntrian(Queue *Q) 
{	
	(*Q).Head = NULL;
	(*Q).Tail = NULL;
}

void enqueue(Queue *Q, infoCustomer X) 
{
	// Kamus Data
	addressNodeQueue pNew, P;
	int i, menitCustLama, menitCustBaru;
	int waktuSelesai;
	
	// Algoritma
	pNew = alokasiNodeQueue(X);
	P = (*Q).Head;
	i = 1;
	
	if(queueEmpty(*Q)) {
		insertFirst(&(*Q), pNew);
	}
	else {
		menitCustLama = konversiTimeKeMenit(P->info.waktuKedatangan);
		menitCustBaru = konversiTimeKeMenit(pNew->info.waktuKedatangan);
		waktuSelesai = konversiTimeKeMenit(P->info.estimasiWaktuSelesai);
		
		if(menitCustBaru < waktuSelesai) {
			if((*Q).Head == (*Q).Tail) {
				if(pNew->info.nilaiPrioritas > P->info.nilaiPrioritas) {
					insertFirst(&(*Q), pNew);
				}
				else if(pNew->info.nilaiPrioritas == P->info.nilaiPrioritas) {
					if(menitCustBaru < menitCustLama) {
						insertFirst(&(*Q), pNew);
					}
					else {
						insertLast(&(*Q), pNew);
					}
				}
				else {
					insertLast(&(*Q), pNew);
				}
			}
			else {
				if(pNew->info.nilaiPrioritas > P->info.nilaiPrioritas) {
					insertFirst(&(*Q), pNew);
				}
				else {
					P = searchByNilaiPrioritas(*Q, pNew->info.nilaiPrioritas);
					while(addressEmpty(P)) {
						if(pNew->info.nilaiPrioritas > 1) {
							P = searchByNilaiPrioritas(*Q, pNew->info.nilaiPrioritas-i);
						}
						else {
							P = searchByNilaiPrioritas(*Q, pNew->info.nilaiPrioritas+i);
						}
						i += 1;
					}
					
					if(pNew->info.nilaiPrioritas > P->info.nilaiPrioritas) {
						P = searchBefore(*Q, P);
					}
					
					if(P == (*Q).Head && menitCustBaru < menitCustLama && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
						insertFirst(&(*Q), pNew);
					}
					
					else {
						while(menitCustLama > menitCustBaru && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
							P = searchBefore(*Q, P);
						}
						
						while(menitCustLama <= menitCustBaru && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
							if(P == (*Q).Tail || P->next->info.nilaiPrioritas != pNew->info.nilaiPrioritas) {
								break;
							}
							P = P->next;
						}
						
						insertAfter(&(*Q), P, pNew);
					}
				}
			}
		}
		else {
			P = searchByNilaiPrioritas((*Q), pNew->info.nilaiPrioritas);
			
			while(addressEmpty(P)) {
				if(pNew->info.nilaiPrioritas > 1) {
					P = searchByNilaiPrioritas(*Q, pNew->info.nilaiPrioritas-i);
				}
				else {
					P = searchByNilaiPrioritas(*Q, pNew->info.nilaiPrioritas+i);
				}
				i += 1;
			}
			
			waktuSelesai = konversiTimeKeMenit(P->info.estimasiWaktuSelesai);
			
			while(menitCustBaru > waktuSelesai && P->next != NULL) {
				P = P->next;
				waktuSelesai = konversiTimeKeMenit(P->info.estimasiWaktuSelesai);
			}
				
			if(pNew->info.nilaiPrioritas > P->info.nilaiPrioritas && searchBefore(*Q, P) != NULL) {
				P = searchBefore(*Q, P);
			}
				
			if(P == (*Q).Head && menitCustBaru < menitCustLama && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
				insertFirst(&(*Q), pNew);
			}	
			else {
				while(menitCustLama > menitCustBaru && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
					P = searchBefore(*Q, P);
				}
					
				while(menitCustLama <= menitCustBaru && P->info.nilaiPrioritas == pNew->info.nilaiPrioritas) {
					if(P == (*Q).Tail || P->next->info.nilaiPrioritas != pNew->info.nilaiPrioritas) {
						break;
					}
					P = P->next;
				}
				insertAfter(&(*Q), P, pNew);
			}
		}
	}
	setLast(&(*Q));
	hitungWaktu(&(*Q), pNew);
}

void insertFirst(Queue *Q, addressNodeQueue pNew) 
{
	if(queueEmpty(*Q)) {
		(*Q).Head = pNew;
		(*Q).Tail = pNew;
	}
	else {
		pNew->next = (*Q).Head;
		(*Q).Head = pNew;
		(*Q).Tail = pNew->next;
	}
}

void insertAfter(Queue *Q, addressNodeQueue P, addressNodeQueue pNew) 
{	
	if(P == (*Q).Tail) {
		insertLast(&(*Q), pNew);
	}
	else {
		pNew->next = P->next;
		P->next = pNew;
	}
}

void insertLast(Queue *Q, addressNodeQueue pNew) 
{	
	(*Q).Tail->next = pNew;
	(*Q).Tail = pNew;
}

/**** Destructor ****/
void hapusAntrian(Queue *Q, char namaHewan[20]) 
{
	// Kamus Data
	addressNodeQueue pDel, prev;
	
	// Algoritma
	pDel = searchByName(*Q, namaHewan);
	if(addressEmpty(pDel)) {
		printf("\t\tData tidak ditemukan, silakan ulang kembali!");
		return;
	}
	
	if((*Q).Head == (*Q).Tail) {
		dealokasiNodeQueue(pDel);
		(*Q).Head = NULL;
		(*Q).Tail = NULL;
	}
	else {
		if(pDel == (*Q).Head) {
			(*Q).Head = pDel->next;
			pDel->next = NULL;
			dealokasiNodeQueue(pDel);
		}
		else {
			prev = searchBefore(*Q, pDel);
			prev->next = pDel->next;
			pDel->next = NULL;
			dealokasiNodeQueue(pDel);	
		}
	}
	
	printf("\t\tAntrian Anda telah dihapus...");
}

void dequeue(Queue *Q) 
{
	// Kamus Data
	addressNodeQueue pDel;
	
	// Algoritma
	pDel = (*Q).Head;
	if((*Q).Head == (*Q).Tail) {
		(*Q).Head = NULL;
		(*Q).Tail = NULL;
	}
	else {
		(*Q).Head = (*Q).Head->next;
		pDel->next = NULL;
	}
	dealokasiNodeQueue(pDel);
}

/**** Accessor ****/


/**** Mutator ****/
void setInfoCustomer(infoCustomer *X, char namaPemilik[20], char namaHewan[20], Time waktuKedatangan, List data) 
{	
	setNamaPemilik(&(*X), namaPemilik);
	setNamaHewan(&(*X), namaHewan);
	setWaktuKedatangan(&(*X), waktuKedatangan);
	setDaftarPenyakit(&(*X), data);
	setNilaiPrioritas(&(*X), data);
	setEstimasiWaktuPelayanan(&(*X), data);
}

void setNamaPemilik(infoCustomer *X, char namaPemilik[20]) 
{
	strcpy((*X).namaPemilik, namaPemilik);
}

void setNamaHewan(infoCustomer *X, char namaHewan[20]) 
{	
	strcpy((*X).namaHewan, namaHewan);
}

void setWaktuKedatangan(infoCustomer *X, Time waktuKedatangan) 
{	
	(*X).waktuKedatangan = waktuKedatangan;
}

void setDaftarPenyakit(infoCustomer *X, List data) 
{
	(*X).daftarPenyakit = data;
}

void setNilaiPrioritas(infoCustomer *X, List L) 
{
	(*X).nilaiPrioritas = hitungNilaiPrioritas(L);
}

void setEstimasiWaktuMulai(Queue Q, addressNodeQueue pNew) 
{
	pNew->info.estimasiWaktuMulai = hitungWaktuMulai(Q, pNew);
}

void setEstimasiWaktuPelayanan(infoCustomer *X, List L) 
{	
	(*X).estimasiWaktuPelayanan = hitungWaktuPelayanan(L);
}

void setEstimasiWaktuSelesai(Queue Q, addressNodeQueue pNew)
{
	pNew->info.estimasiWaktuSelesai = hitungWaktuSelesai(Q, pNew);
}

void setLast(Queue *Q) 
{
	addressNodeQueue P;
	
	P = (*Q).Head;
	while(P->next != NULL) {
		P = P->next;
	}
	(*Q).Tail = P;
}

/**** Operasi Tambahan ****/
void printQueue(Queue Q) 
{
	addressNodeQueue P;
	int nomor = 1;
	
	P = Q.Head;
	if(addressEmpty(P)) {
		printf("Antrian kosong...\n\n\n");
	}
	else {
		printf("\t\t ____________________________________________________________________________________\n");
		printf("\t\t\xb3  _        __                               _               _        _              \xb3 \n");
		printf("\t\t\xb3 (_)      / _|                             (_)             | |      (_)             \xb3 \n");
		printf("\t\t\xb3  _ _ __ | |_ ___  _ __ _ __ ___   __ _ ___ _    __ _ _ __ | |_ _ __ _  __ _ _ __   \xb3 \n");
		printf("\t\t\xb3 | | '_ \\|  _/ _ \\| '__| '_ ` _ \\ / _` / __| |  / _` | '_ \\| __| '__| |/ _` | '_ \\  \xb3 \n");
		printf("\t\t\xb3 | | | | | || (_) | |  | | | | | | (_| \\__ \\ | | (_| | | | | |_| |  | | (_| | | | | \xb3 \n");
		printf("\t\t\xb3 |_|_| |_|_| \\___/|_|  |_| |_| |_|\\__,_|___/_|  \\__,_|_| |_|\\__|_|  |_|\\__,_|_| |_| \xb3 \n");
		printf("\t\t\xb3____________________________________________________________________________________\xb3 \n\n");

		
		while(!addressEmpty(P)) {
			printf("\t\t\t\tNo. Antrian: %d", nomor);
			printf("\n\t\t\t\t===============");
			printf("\n\t\t\t\tNama Hewan                         : %s", P->info.namaHewan);
			printf("\n\t\t\t\tWaktu Kedatangan                   : ");
			printTime(P->info.waktuKedatangan);
			printf("\n\t\t\t\tNilai Prioritas                    : %d ", P->info.nilaiPrioritas);
			printf("\n\n\t\t\t\tPenyakit Kucing \n");
			printList(P->info.daftarPenyakit);
			printf("\n\t\t\t\tEstimasi Waktu Mulai Pemeriksaan   : ");
			printTime(P->info.estimasiWaktuMulai);
			printf("\n\t\t\t\tEstimasi Waktu Pemeriksaan         : %d menit", P->info.estimasiWaktuPelayanan);
			printf("\n\t\t\t\tEstimasi Waktu Selesai Pemeriksaan : ");
			printTime(P->info.estimasiWaktuSelesai);
			printf("\n\t\t\t--------------------------------------------------------------------\n");
			nomor++;
			P = P->next;
		}
	}
}

int hitungNilaiPrioritas(List L) 
{
	// Kamus Data
	addressNodeList P;
	int Ringan = 0;
	int Sedang = 0;
	int Berat  = 0;
	int nilaiPrioritas = 0;
	
	// Algoritma
	P = L.First;
	while(!isAddressEmpty(P)) {
		if(strcmp(P->info.kategori, "Penyakit Ringan") == 0) {
			Ringan++;
		}
		else if(strcmp(P->info.kategori, "Penyakit Sedang") == 0) {
			Sedang++;
		}
		else if(strcmp(P->info.kategori, "Penyakit Berat") == 0) {
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

Time hitungWaktuMulai(Queue Q, addressNodeQueue pNew) 
{
	// Kamus Data
	addressNodeQueue P;
	Time waktuMulai;
	int waktuSelesai, waktuDatang;
	
	// Algoritma
	if(Q.Head == Q.Tail || pNew == Q.Head) {
		waktuMulai.HH = pNew->info.waktuKedatangan.HH;
		waktuMulai.MM = pNew->info.waktuKedatangan.MM;
	}
	else {
		P = searchBefore(Q, pNew);
		waktuDatang = konversiTimeKeMenit(pNew->info.waktuKedatangan);
		waktuSelesai = konversiTimeKeMenit(P->info.estimasiWaktuSelesai);
		if(waktuDatang >= waktuSelesai) {
			waktuMulai.HH = pNew->info.waktuKedatangan.HH;
			waktuMulai.MM = pNew->info.waktuKedatangan.MM;
		}
		else {
			waktuMulai.HH = P->info.estimasiWaktuSelesai.HH;
			waktuMulai.MM = P->info.estimasiWaktuSelesai.MM + 1;
		}
	}
	return waktuMulai;
}

int hitungWaktuPelayanan(List L) 
{
	// Kamus Data
	addressNodeList P;
	int Ringan = 0;
	int Sedang = 0;
	int Berat  = 0;
	
	// Algoritma
	P = L.First;
	while(!isAddressEmpty(P)) {
		if(strcmp(P->info.kategori, "Penyakit Ringan") == 0) {
			Ringan++;
		}
		else if(strcmp(P->info.kategori, "Penyakit Sedang") == 0) {
			Sedang++;
		}
		else if(strcmp(P->info.kategori, "Penyakit Berat") == 0) {
			Berat++;
		}
		P = P->next;
	}
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

Time hitungWaktuSelesai(Queue Q, addressNodeQueue pNew) 
{
	//Kamus Data
	Time waktuSelesai;
	int menit;
	
	//Algoritma
	menit = konversiTimeKeMenit(pNew->info.estimasiWaktuMulai) + pNew->info.estimasiWaktuPelayanan;
	waktuSelesai = konversiMenitKeTime(menit);
	return waktuSelesai;
}

void hitungWaktu(Queue *Q, addressNodeQueue pNew)
{
	// Kamus Data
	addressNodeQueue P;
	
	// Algoritma
	P = pNew;
	while(!addressEmpty(P)) {
		setEstimasiWaktuMulai(*Q, P);
		setEstimasiWaktuSelesai(*Q, P);
		P = P->next;
	}
}

addressNodeQueue searchByNilaiPrioritas(Queue Q, int nilaiPrioritas) 
{
	// Kamus Data
	addressNodeQueue P;
	
	// Algoritma
	P = Q.Head;
	while(!addressEmpty(P) && P->info.nilaiPrioritas != nilaiPrioritas) {
		P = P->next;
	}
	return P;
}

addressNodeQueue searchByAddress(Queue Q, addressNodeQueue pNew) 
{
	// Kamus Data
	addressNodeQueue pS;
	
	// Algoritma
	pS = Q.Head;
	while(!addressEmpty(pS) && pS != pNew) {
		pS = pS->next;
	}
	return pS;
}

addressNodeQueue searchBefore(Queue Q, addressNodeQueue P) 
{
	// Kamus Data
	addressNodeQueue pSearch;
	
	// Algoritma
	pSearch = Q.Head;
	while(!addressEmpty(pSearch) && pSearch->next != P) {
		pSearch = pSearch->next;
	}
	return pSearch;
}

addressNodeQueue searchByName(Queue Q, char namaHewan[20]) 
{
	// Kamus Data
	addressNodeQueue P;
	
	// Algoritma
	P = Q.Head;
	while(!addressEmpty(P) && strcmp(P->info.namaHewan, namaHewan) != 0) {
		P = P->next;
	}
	return P;
}
