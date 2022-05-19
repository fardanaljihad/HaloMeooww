#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct tInfoPenyakit {
	char namaPenyakit[30];
	char kategori[10];
};
typedef struct tNodeList *addressNodeList;
typedef struct tNodeList {
	int indeks;
	addressNodeList next;
} NodeList;
typedef struct {
	addressNodeList First;
} List;

#endif
