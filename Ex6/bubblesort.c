#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct corredor{
    int id;
    char name[256];
    char instituicao[256];
} corredor;

void bubblesort_ID(struct corredor *vector, int tam){
    int aux_int, i, j;
    char aux_string[256];
    for(i=tam-1; i >= 1; i--){  
        for(j=0; j < i ; j++){
            if(vector[j].id>vector[j+1].id) {
                //troca os ids
                aux_int = vector[j].id;
                vector[j].id = vector[j+1].id;
                vector[j+1].id = aux_int;

                //troca os nomes;
                strcpy(aux_string, vector[j].name);
                strcpy(vector[j].name, vector[j+1].name);
                strcpy(vector[j+1].name, aux_string);

                //troca instituicao
                strcpy(aux_string, vector[j].instituicao);
                strcpy(vector[j].instituicao, vector[j+1].instituicao);
                strcpy(vector[j+1].instituicao, aux_string);
            }
        }
    }
}

void bubblesort_NAME(struct corredor *vector, int tam){
    int aux_int, i, j;
    char aux_string[256];
    for(i=tam-1; i >= 1; i--){  
        for(j=0; j < i ; j++){
            if(strcmp(vector[j].name, vector[j+1].name) >= 0){
                //troca os ids
                aux_int = vector[j].id;
                vector[j].id = vector[j+1].id;
                vector[j+1].id = aux_int;

                //troca os nomes;
                strcpy(aux_string, vector[j].name);
                strcpy(vector[j].name, vector[j+1].name);
                strcpy(vector[j+1].name, aux_string);

                //troca instituicao
                strcpy(aux_string, vector[j].instituicao);
                strcpy(vector[j].instituicao, vector[j+1].instituicao);
                strcpy(vector[j+1].instituicao, aux_string);
            }
        }
    }
}

int main(){

    struct corredor *corredores;
    int i, j, tam;
    char letra;
    char scan[256];


    corredores = (struct corredor*) calloc(1, sizeof(struct corredor));
    scanf("%s", scan);
    //printf("%s\n", scan);
    scanf("%s", scan);
    for(i = 0; strcmp(scan, "CAASO") != 0; i++){
        corredores = (struct corredor*) realloc (corredores, (i+1)*sizeof(struct corredor));
        strcpy(corredores[i].instituicao, "FEDERAL");
        corredores[i].id = atoi(scan);
        scanf("%c", &letra);
        scanf("%c", &letra);
        for(j = 0; letra != '\n' ; j++){
            corredores[i].name[j] = letra;
            scanf("%c", &letra);
        }
        corredores[i].name[j] = '\0';
        scanf("%s", scan);
    }
    scanf("%s", scan);
    for(; strcmp(scan, "ID") != 0 && strcmp(scan, "NAME") != 0; i++){
        corredores = (struct corredor*) realloc (corredores, (i+1)*sizeof(struct corredor));
        strcpy(corredores[i].instituicao, "CAASO");
        corredores[i].id = atoi(scan);
        scanf("%c", &letra);
        scanf("%c", &letra);
        for(j = 0; letra != '\n' ; j++){
            corredores[i].name[j] = letra;
            scanf("%c", &letra);
        }
        corredores[i].name[j] = '\0';
        scanf("%s", scan);
        if(i == 20) break;
    }
    tam = i;

    if(strcmp(scan, "ID") == 0){
        bubblesort_ID(corredores, tam);
    } else {
        bubblesort_NAME(corredores, tam);
    }

    //print vector
    for(i = 0; i < tam; i++)
    {
        printf("%s %d %s\n",corredores[i].instituicao, corredores[i].id, corredores[i].name);
    }

    free(corredores);

    return 0;
}

