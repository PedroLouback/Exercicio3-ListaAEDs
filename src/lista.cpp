#include "lista.hpp"

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, Item d){
	if (l->last >= MAXTAM){
		cout << "LISTA CHEIA!" << endl;
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void LRemove(Lista *l, Item d){
	bool ok = false;

	if(l->first == l->last)
		cout << "LISTA VAZIA!" << endl;
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].codons == d.codons){
				Swap(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}

void Cadeia1Imprime(Lista *l){
	cout << "\nCadeia 1: ";
	for(int i=l->first; i<l->last; i++)
		cout << l->vet[i].codons << "  ";
	cout << "\n\n";
}

void Cadeia2Imprime(Lista *l){
	cout << "\nSequência de nucleotídios: ";
	for(int i=l->first; i<l->last; i++)
		cout << l->vet[i].codons << "  ";
	cout << "\n\n";
}

void LeituraCadeia1(Lista *l){
	string nome_arquivo, cadeia1;
	ifstream arq;
	cout << "\nInforme o nome do arquivo em que contém a primeira cadeia de DNA: ";
	getline(cin, nome_arquivo);

    if(!arq){
        cerr << "Não foi possivel abrir o arquivo de saida : " << nome_arquivo << " \nSaindo do programa! \n";
        exit(1);
    }

	arq.open(nome_arquivo);

	while(!arq.eof()){
		getline(arq, cadeia1);
	}
	arq.close();

    SepararEmCodon(cadeia1, l);
}

void LeituraCadeia2(Lista *l){
	string nome_arquivo, cadeia2;
	ifstream arq;
	cout << "Informe o nome do arquivo em que contém a sequência de nucleotídios: ";
	getline(cin, nome_arquivo);

    if(!arq){
        cerr << "Não foi possivel abrir o arquivo de saida : " << nome_arquivo << " \nSaindo do programa! \n";
        exit(1);
    }

	arq.open(nome_arquivo);

	while(!arq.eof()){
		getline(arq, cadeia2);
	}
	arq.close();

    SepararEmCodon(cadeia2, l);
}

void SepararEmCodon(string cadeia, Lista *l){
	Item aux;
	int tam=0;
	tam = cadeia.size();
    for (int i=0; i < tam; i+=3){
        aux.codons=cadeia.substr(i, 3);
        LInsert(l, aux);  
    }
	
}

void ProcuraRelacao(Lista *cadeia1, Lista *cadeia2){
	int i=0, j=0,l=0, count=0;
	vector <int> pos;
	bool verifica = false;
	for (i=cadeia1->first; i<cadeia1->last; i++){
		for(j=cadeia2->first; j<cadeia2->last; j++){
			if(cadeia1->vet[i].codons == cadeia2->vet[j].codons ){
				pos.push_back(i);
				count++;
				if (count>1){
					if(cadeia1->vet[i-1].codons == cadeia2->vet[j-1].codons){
						pos.push_back(i);
					}else if (verifica == false){
						 cout << "A maior cadeia que se relacionou com a nova sequência de nucleotídios foi apenas a do códon " << pos.size()-1 << "!\n" << endl;
						 verifica=true;
					}
				}
			}else if(verifica == false && pos.size()>1){
				cout << "A maior cadeia que se relacionou com a nova sequência de nucleotídios foi a do códon " << pos[l] << " ao códon " << pos.back() << "!\n" << endl;
				verifica=true;
			}
		}
	}
	if(verifica == false){
		if(pos.size()>1){
			cout << "A maior cadeia que se relacionou com a nova sequência de nucleotídios foi a do códon " << pos[l] << " ao códon " << pos.back() << "!\n" << endl;
		}else{
			cout << "A maior cadeia que se relacionou com a nova sequência de nucleotídios foi apenas a do códon " << pos[l] << "!\n" << endl;
		}
	}
}






