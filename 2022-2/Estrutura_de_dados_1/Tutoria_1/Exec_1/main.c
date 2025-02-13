#include <stdio.h>
#include "lista.h"

#define MAX_TAM 100000

int main(){
    
    TLista lista;
    TLista_Inicia(&lista);

    char string[MAX_TAM];
    int tamString;

    char temp[MAX_TAM];
    int tamTemp = -1;

    char caracter;


    while(fgets(string, MAX_TAM, stdin) != NULL){

        tamString = strlen(string);
        if(string[tamString-1] == '\n'){
            string[tamString-1] = '\0';
            tamString--;
        }

        //Indo de caracter por caracter da String
        //Se o primeiro caracter for um [, eu vou começar do próximo
        for(int i = string[0] == '[' ? 1 : 0; i < tamString; i++){
            caracter = string[i];

            if(caracter == '['){
                //Fazer um for procurando até um proximo [ ou ] ou fim da string, gerando um string temporaria com os dados
                int j;
                for(j=i+1; j<tamString && string[j] != '[' && string[j] != ']'; j++){
                    tamTemp++;
                    temp[tamTemp] = string[j];
                }
                //inserir os dados da String temporaria no inicio da lista
                for(int k = tamTemp; k>=0; k--){
                    TLista_Insere_Inicio(&lista, temp[k]);
                }
                //Reiniciar a string temporaria
                temp[tamTemp+1]='\0';
                tamTemp = -1;
                i = j-1;
            }
            else if (caracter != ']'){
                TLista_Insere_Fim(&lista, caracter);
            }

        }

        TLista_Imprime(&lista);
        TLista_Esvazia(&lista);
        TLista_Inicia(&lista);

    }

    TLista_Esvazia(&lista);


    return 0;
}