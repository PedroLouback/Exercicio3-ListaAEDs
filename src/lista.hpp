#ifndef LISTA_HPP 
#define LISTA_HPP

#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define MAXTAM 100

typedef struct Item{
	string codons;
}Item;

typedef struct Lista{
	Item vet[MAXTAM];
	int first;
	int last;
}Lista;

void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Item *a, Item *b);
void Cadeia1Imprime(Lista *l);
void Cadeia2Imprime(Lista *l);
void LeituraCadeia1(Lista *l);
void LeituraCadeia2(Lista *l);
void SepararEmCodon(string cadeia, Lista *l);
void ProcuraRelacao(Lista *cadeia1, Lista *cadeia2);

#endif