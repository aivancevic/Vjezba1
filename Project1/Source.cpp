/*1. Napisati program koji prvo pročita koliko redaka ima datoteka, tj. koliko ima studenata zapisanih u
datoteci. Nakon toga potrebno je dinamički alocirati prostor za niz struktura studenata (ime, prezime,
bodovi) i učitati iz datoteke sve zapise. Na ekran ispisati ime, prezime,apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
	char ime[50] = {0};
	char prezime[50] = {0};
	int bodovi;
}_student;

int Counter();
int citanjeDatoteke(_student*,int);

int main() {
	int brojac=0,i;
	_student* s;

	brojac = Counter();
	
	s = (_student*)malloc(brojac *sizeof (_student));

	if (s == NULL) {
		printf("Neuspjesno alociranje!");
		return 1;
	}

	citanjeDatoteke(s,brojac);

	for (i = 0; i < brojac; i++) {
		printf("%s %s %d\n", s->ime, s->prezime, s->bodovi);
		s++;
	}

	return 0;
}

int Counter()
{
	FILE* file1;
	int brojac = 0;
	char popis[1024];

	file1 = fopen("Kolokvij.txt", "r");

	if (file1 == NULL) {
		printf("Neuspjesno ucitavanje datoteke!");
		return 1;
	}

	while (!feof(file1))
	{
		fgets(popis, 1023, file1);
		brojac++;
	}

	fclose(file1);
	return brojac;
}

int citanjeDatoteke(_student *s,int brojac)
{
	int i;
	FILE* file1;

	file1 = fopen("Kolokvij.txt", "r");

	for (i = 0; i < brojac; i++) {
		fscanf(file1, " %s %s %d", s->ime, s->prezime, &s->bodovi);
		s++;
	}

	fclose(file1);
	return 0;
}
