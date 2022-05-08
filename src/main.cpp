#include "lista.hpp"

int main(){

	Lista cadeia1, cadeia2;
	Item aux;

	//Criação da lista da cadeia 1
	FLVazia(&cadeia1);
	LeituraCadeia1(&cadeia1);
	Cadeia1Imprime(&cadeia1);

	//Criação da lista da cadeia 2
	FLVazia(&cadeia2);
    LeituraCadeia2(&cadeia2);
	Cadeia2Imprime(&cadeia2);

	ProcuraRelacao(&cadeia1, &cadeia2);

	return 0;
}
