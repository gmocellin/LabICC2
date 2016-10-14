#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ItemLista{
    char *chave;
    struct ItemLista *prox;
} ItemLista;

typedef struct HashList{
    ItemLista **firstItem;
} HashList;

void insereLista(HashList *List, char *chave){
    int indice;
    ItemLista *itemProx;
    ItemLista *itemAnt;
    ItemLista *newItem;

    indice = chave[0] - 'a';
    itemProx = List->firstItem[indice];
    itemAnt = NULL;

    newItem = (ItemLista*) malloc (sizeof(ItemLista));
    newItem->chave = (char*) malloc ((strlen(chave)+1)*sizeof(char));
    strcpy(newItem->chave, chave); 

    printf("indice: %d, chave: %s \n", indice, newItem->chave);

    while(itemProx->prox != NULL){

        if(itemProx->chave == NULL || strcmp(chave, itemProx->chave) < 0){ //entra antes
            if(itemAnt != NULL){
                itemAnt->prox = newItem;
            } else{
                List->firstItem[indice] = newItem;
                printf("batata\n");
            }
            newItem->prox = itemProx;
            break;
        }
        itemAnt = itemProx;
        itemProx = itemProx->prox;    
    }
}

void removeItemLista(HashList *List, char *chave){
    
}

void printLista(HashList *List){
    int i;
    ItemLista *item;

    for (i = 0; i < 26; i++){
        item = List->firstItem[i];
        while(item->prox != NULL){
            if(item->chave != NULL)
                printf("%s", item->chave);
            item = item->prox;
        }
    }
}

int buscaItemLista(HashList *List, char *chave){
    int indice;
    ItemLista *item;

    indice = chave[0] - 'a';
    item = List->firstItem[indice];

    while(item->chave != NULL){
        if(strcmp(item->chave, chave) == 0){
            return 1;
        } else {
            item = item->prox;
        }
    }

    return 0;
}

/*
void criaLista(HashList *List){
    int i;

    List->firstItem = (ItemLista**) malloc (26 * sizeof(ItemLista*));
    for(i = 0; i < 26; i++){
        List->firstItem[i] = (ItemLista*) malloc (sizeof(ItemLista));
        List->firstItem[i]->chave == NULL;
        List->firstItem[i]->prox == NULL;
    }
}*/

void destroyList(HashList List){

}

int main (){

    int i;
    char operacao;
    char chave[1000];
    HashList *List = (HashList*) malloc (sizeof(HashList));;

    List->firstItem = (ItemLista**) malloc (26 * sizeof(ItemLista*));
    for(i = 0; i < 26; i++){
        List->firstItem[i] = (ItemLista*) malloc (sizeof(ItemLista));
        //List->firstItem[i]->chave == NULL;
        //List->firstItem[i]->prox == NULL;
    }

    scanf("%c", &operacao);
    while(operacao != 'f'){
        if(operacao == 'i'){
            scanf("%s", chave);
            insereLista(List, chave);
        }else if(operacao == 'b'){
            scanf("%s", chave);
            //buscaItemLista(List, chave);
        }else if(operacao == 'r'){
            scanf("%s", chave);
            //removeItemLista(List, chave);
        }
        //printf("%c, %s\n", operacao, chave);
        scanf("%c", &operacao);        
    }

    printf("%s\n", List->firstItem[3]->chave);

    printLista(List);

    //destroyList(List);

    return 0;
}