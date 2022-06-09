#include "apk_layanan_dokter_hewan.h"

/**** Fitur ****/
void Registrasi(Queue *Q) 
{
	// Kamus Data
	Time T;
	List data;
	infoCustomer X;
	char namaPemilik[20], namaHewan[20];
	int waktuKedatangan, indeks, jumlahPenyakit, pilihan;
	int i;
	
	// Algoritma
	BuatList(&data);
	createTime(&T);
	i = 1;
	
	printf("\t\t                 _     _                 _  \n");
	printf("\t\t                (_)   | |               (_) \n");
	printf("\t\t  _ __ ___  __ _ _ ___| |_ _ __ __ _ ___ _  \n");
	printf("\t\t | '__/ _ \\/ _` | / __| __| '__/ _` / __| | \n");
	printf("\t\t | | |  __/ (_| | \\__ \\ |_| | | (_| \\__ \\ | \n");
	printf("\t\t |_|  \\___|\\__, |_|___/\\__|_|  \\__,_|___/_| \n");
	printf("\t\t            __/ |                           \n");
	printf("\t\t           |___/                            \n");
	printf("\t\t============================================\n\n");
	
	printf("\t\tNama Hewan\t : "); scanf(" %[^\n]", &namaHewan);
	printf("\t\tNama Pemilik\t : "); scanf(" %[^\n]", &namaPemilik);
	printf("\t\tWaktu Kedatangan : "); 
	printf("Jam   "); scanf("%d", &T.HH);
	printf("\t\t\t\t   Menit "); scanf("%d", &T.MM);
	printf("\t\tJumlah Penyakit  : "); 
	scanf("\t\t%d", &jumlahPenyakit);
	
	printf("\n\t\tDaftar Penyakit yang Dapat Dilayani \n");
	printf("\t\t1. Bersin \n");
	printf("\t\t2. Luka Ringan \n");
	printf("\t\t3. Penyakit Kulit \n");
	printf("\t\t4. Cacingan \n");
	printf("\t\t5. Diare \n");
	printf("\t\t6. Luka Dalam \n");
	printf("\t\t7. Gangguan Kerongkongan yang Mengeluarkan\n\t\t   Lendir Berbau Busuk \n");
	printf("\t\t8. Kuning \n");
	printf("\t\t9. Terkena Virus \n\n");
	do {
		printf("\t\tPenyakit ke-%d : ", i); 
		scanf("\t\t%d", &indeks);
		insertToList(&data, indeks);
		i++;
	} while(i <= jumlahPenyakit);
	
	setInfoCustomer(&X, namaPemilik, namaHewan, T, data);
	enqueue(&(*Q), X);
	printf("\n\t\tProses registrasi telah berhasil...\n\n\n");
	system("pause");
	system("cls");
}

void ProsesAntrian(Queue *Q)
{
	// Kamus Data
	addressNodeQueue P;
	char pilihan;
	
	// Algoritma
	if(queueEmpty(*Q)) {
		printf("Antrian Kosong...\n\n\n");
	}
	else {
		P = (*Q).Head;
		printf("\n\t\t\t\t+=================================================+");
		printf("\n\t\t\t\t|               Proses Pelayanan                  |");
		printf("\n\t\t\t\t+=================================================+");
		printf("\n\t\t\t\t Nama Hewan       : %s\n", P->info.namaHewan);
		printf("\t\t\t\t Waktu Kedatangan : ");
		printTime(P->info.waktuKedatangan);
		printf("\n\t\t\t\t Nilai Prioritas  : %d\n", P->info.nilaiPrioritas);
		printf("\n\n\t\t\t\t Penyakit Kucing \n");
		printList(P->info.daftarPenyakit);
		printf("\n\t\t\t\t Apakah kamu ingin memulai pemeriksaan %s? [Y/N] ", P->info.namaHewan);
		scanf(" %c", &pilihan);
		if(toupper(pilihan) == 'N')
			return;
			
		simpanDataAntrian(&(*Q));	
		dequeue(&(*Q));
		printf("\t\t\t\t %s sedang diperiksa...\n\n\n", P->info.namaHewan);
	}
}

void HapusAntrian(Queue *Q) 
{
	// Kamus Data
	char namaHewan[20];
	addressNodeQueue P;
	
	// Algoritma
	printf("\t\t _  _   __   ____  _  _  ____     __   __ _  ____  ____  __   __   __ _  \n");
	printf("\t\t/ )( \\ / _\\ (  _ \\/ )( \\/ ___)   / _\\ (  ( \\(_  _)(  _ \\(  ) / _\\ (  ( \\ \n");
	printf("\t\t) __ (/    \\ ) __/) \\/ (\\___ \\  /    \\/    /  )(   )   / )( /    \\/    / \n");
	printf("\t\t\\_)(_/\\_/\\_/(__)  \\____/(____/  \\_/\\_/\\_)__) (__) (__\\_)(__)\\_/\\_/\\_)__) \n");
	printf("\t    ================================================================================\n\n");
	
	printf("\t\tMasukkan Nama Hewan : ");
	scanf(" %[^\n]", &namaHewan);
	hapusAntrian(&(*Q), namaHewan);
	if(!queueEmpty(*Q)) {
		setLast(&(*Q));
		P = (*Q).Head;
		hitungWaktu(&(*Q), P);
	}
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void Riwayat() 
{
	// Kamus Data
	char namaHewan[20], namaPemilik[20];
	
	// Algoritma
	printf("Cari Riwayat");
	printf("\n==================");
	printf("\nMasukkan Nama Hewan   : "); scanf(" %[^\n]", &namaHewan);
	printf("Masukkan Nama Pemilik : "); scanf(" %[^\n]", &namaPemilik);
	tampilkanRiwayat(namaHewan, namaPemilik);
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void simpanDataAntrian(Queue *Q)
{
	// Referensi Kelompok A7
	riwayatCust X;
	addressNodeList P;
	FILE *Riwayat;
	int i=0;
	
	time_t currentTime;
	time(&currentTime);
	
	struct tm *myTime = localtime(&currentTime);
	
	
	if ((Riwayat = fopen("RiwayatCustomer.txt", "ab+")) == NULL)
	{
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}
	
	P = (*Q).Head->info.daftarPenyakit.First;
	strcpy(X.namaHewan, (*Q).Head->info.namaHewan);
	strcpy(X.namaPemilik, (*Q).Head->info.namaPemilik);
	while(!isAddressEmpty(P)) {
		X.indeksPenyakit[i] = P->info.indeksPenyakit;
		i++;
		P = P->next;
	}
	X.jmlPenyakit = i-1;
	X.tanggal[0] = myTime->tm_mday;
	X.tanggal[1] = myTime->tm_mon+1;
	X.tanggal[2] = myTime->tm_year+1900;
	X.waktu = (*Q).Head->info.waktuKedatangan;
	
	fwrite(&X, sizeof(X), 1, Riwayat);
    fclose(Riwayat);
}

void tampilkanRiwayat(char namaHewan[20], char namaPemilik[20])
{
	// Referensi Kelompok A7
	riwayatCust X;
	FILE *Riwayat;
	bool found = false;
	int indeks = 0;
		
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
			
	Riwayat = fopen("RiwayatCustomer.txt", "rb+");
	while(fread(&X, sizeof(X), 1, Riwayat)) {
		if(strcmp(namaHewan, X.namaHewan) == 0 && strcmp(namaPemilik, X.namaPemilik) == 0) {
			found = true;
			printf("\nTanggal        : %d/%d/%d", X.tanggal[0], X.tanggal[1], X.tanggal[2]);
			printf("\nWaktu          : ");
			printTime(X.waktu);
			printf("\nNama Hewan     : %s", X.namaHewan);
			printf("\nNama Pemilik   : %s", X.namaPemilik);
			printf("\nPenyakit Hewan ");
			while(indeks <= X.jmlPenyakit) {
				printf("\n %d) %s", indeks+1, daftarPenyakit[X.indeksPenyakit[indeks]-1]);
				indeks++;
			}
	 	}
	}
	if(!found) {
		printf("Data tidak ditemukan...");
	}
}

void ShowMenu() 
{
	puts("\t\t                        ===========> WELCOME <===========");
	puts("\t\t  ===============================================================================");
	puts("\t\t||  __ __   ____  _       ___   ___ ___    ___   ___    ___   __    __  __    __  ||");
	puts("\t\t|| |  |  | /    || |     /   \\ |   |   |  /  _] /   \\  /   \\ |  |__|  ||  |__|  | ||");
	puts("\t\t|| |  |  ||  o  || |    |     || _   _ | /  [_ |     ||     ||  |  |  ||  |  |  | ||");
	puts("\t\t|| |  _  ||     || |___ |  O  ||  \\_/  ||    _]|  O  ||  O  ||  |  |  ||  |  |  | ||");
	puts("\t\t|| |  |  ||  _  ||     ||     ||   |   ||   [_ |     ||     ||  `  '  ||  `  '  | ||");
	puts("\t\t|| |  |  ||  |  ||     ||     ||   |   ||     ||     ||     | \\      /  \\      /  ||");
	puts("\t\t|| |__|__||__|__||_____| \\___/ |___|___||_____| \\___/  \\___/   \\_/\\_/    \\_/\\_/   ||");
	puts("\t\t||================================================================================||");
	puts("\t\t||                         ||                           ||                        ||");
	puts("\t\t||     (1) Registrasi      ||   (2) Informasi Antrian   ||  (3) Proses Pelayanan  ||");
	puts("\t\t||                         ||                           ||                        ||");
	puts("\t\t||================================================================================||");
	puts("\t\t||                         ||                           ||                        ||");
	puts("\t\t||    (4) Hapus Antrian    ||        (5) Riwayat        ||        (6) Exit        ||");
	puts("\t\t||                         ||                           ||                        ||");
	puts("\t\t||================================================================================||");
	printf("\t\t                        Masukan Menu Pilihan : ");
}

void MainMenu()
{
	Queue Q;
	List L;
	infoCustomer X;
	int pilihan;
	
	buatAntrian(&Q);
	BuatList(&L);
	
	do {
		ShowMenu();
		scanf("%d", &pilihan);
		system("cls");
		
		if(pilihan == 1) {
			Registrasi(&Q);
		}
		
		else if(pilihan == 2) {
			printQueue(Q);
			system("pause");
			system("cls");
		}
		
		else if(pilihan == 3) {
			ProsesAntrian(&Q);
			system("pause");
			system("cls");
		}
		
		else if(pilihan == 4) {
			HapusAntrian(&Q);
		}
		
		else if(pilihan == 5) {
			Riwayat();
		}
		
	} while(pilihan != 6); 
	
	Exit();
}

void Exit()
{
	printf("\n\n\n\n");
	printf("\t\t\t\t\t _________________________________________\n");
	printf("\t\t\t\t\t\xb3  ____  _  _  ____    ____  _  _  ____   \xb3\n");
	printf("\t\t\t\t\t\xb3 (  _ \\( \\/ )(  __)  (  _ \\( \\/ )(  __)  \xb3\n");
	printf("\t\t\t\t\t\xb3  ) _ ( )  /  ) _)    ) _ ( )  /  ) _)   \xb3\n");
	printf("\t\t\t\t\t\xb3 (____/(__/  (____)  (____/(__/  (____)  \xb3\n");
	printf("\t\t\t\t\t\xb3_________________________________________\xb3\n");
	printf("\t\t\t\t\t\xb3                                         \xb3\n");
	printf("\t\t\t\t\t\xb3          SAMPAI JUMPA KEMBALI!!         \xb3\n");
	printf("\t\t\t\t\t\xb3                HALOMEEOOW               \xb3\n");
	printf("\t\t\t\t\t\xb3_________________________________________\xb3\n\n");
}
