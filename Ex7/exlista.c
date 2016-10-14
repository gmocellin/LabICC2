#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ItemLista{
    int chave;
    int tempo;
    struct ItemLista *prox;
    struct ItemLista *back;
    struct ItemLista *ant;
} ItemLista;

struct Lista{
    ItemLista *inicio;
} Lista;

void insereLista(int tempo, int chave, int back, struct Lista *listaValores){

    ItemLista *itemAnterior = NULL;
    ItemLista *itemAtual = NULL;

    //printf("listaValores->inicio: %p\n", listaValores->inicio);
    if(listaValores->inicio == NULL){
        listaValores->inicio = (ItemLista *) malloc (sizeof(ItemLista));
        itemAtual = listaValores->inicio;
    } else {
        //printf("inicio: %p\n", listaValores->inicio);
        itemAtual = listaValores->inicio;
        while(itemAtual != NULL){
            //printf("%d %d %p %p %p\n", itemAtual->chave, itemAtual->tempo, itemAtual->prox, itemAtual->ant, itemAtual->back);
            itemAnterior = itemAtual;
            itemAtual = itemAtual->prox;
        }
        itemAtual = (ItemLista *) malloc (sizeof(ItemLista));
        itemAnterior->prox = itemAtual;
    }

    itemAtual->tempo = tempo;
    itemAtual->chave = chave;
    itemAtual->ant = itemAnterior;
    itemAtual->prox = NULL;
    
    //printf("%d %d %p %p %p\n", itemAtual->chave, itemAtual->tempo, itemAtual->prox, itemAtual->ant, itemAtual->back);    
        
    //printf("listaValores->chave: %d\n", listaValores->inicio->chave);

    //printf("back = %d\n", back);
    if(back == 0){      
        itemAtual->back = NULL;
    } else {
        while(back > 1 && itemAnterior != NULL){
            itemAnterior = itemAnterior->ant;
            //printf("%p ", itemAnterior);
            back--;
        }
        //printf("\n");
        itemAtual->back = itemAnterior;
        //printf("itemAtual->back->chave = %d\n", itemAtual->back->chave);
    }
    
    //printf("\n\n");
    //printf("%d %d\n", ItemListaValores->tempo, ItemListaValores->chave);
}

void removeItemLista(int valor1, struct Lista *listaValores){
    
    ItemLista *itemAnterior = NULL;
    ItemLista *itemAtual = NULL;
    ItemLista *itemRemocao = NULL;

    //printf("REMOCAO\n");
    if(listaValores->inicio != NULL){
        //printf("inicio: %p\n", listaValores->inicio);
        itemAtual = listaValores->inicio;
        while(itemAtual != NULL){
            //printf("iR: %p\n", itemRemocao);
            if(itemRemocao != NULL && itemAtual->back != NULL && itemAtual->back->chave == itemRemocao->chave){
                //printf("itemRemocao->chave: %d     itemAtual->chave: %d     itemAtual->back->chave: %d\n", itemRemocao->chave, itemAtual->chave, itemAtual->back->chave);
                itemAtual->back = NULL;
            }

            if(itemAtual->chave == valor1){
                //printf("itemAtual->chave: %d\nitemAnterior->chave: %d\nitemAtual->prox->chave: %d\n", itemAtual->chave, itemAnterior->chave, itemAtual->prox->chave);
                if(itemAnterior != NULL){
                    itemAnterior->prox = itemAtual->prox;
                    if(itemAtual->prox != NULL)
                        itemAtual->prox->ant = itemAnterior;
                    itemRemocao = itemAtual;
                    itemAtual = itemAnterior->prox;
                } else {
                    listaValores->inicio = itemAtual->prox;
                    //printf("PROXIMO ATUAL: %p\n", itemAtual->prox);
                    if(itemAtual->prox != NULL)
                        itemAtual->prox->ant = NULL;
                    itemRemocao = itemAtual;
                    itemAtual = listaValores->inicio;
                }
            } else {
                itemAnterior = itemAtual;
                itemAtual = itemAtual->prox;
            }    
        }
    }
    free(itemRemocao);
    //printf("\n\n");

}

int returnPos(int pos, int chave, int tempo, ItemLista *item){
    if (item == NULL){
        return -1;
    } else if(item->chave == chave && item->tempo == tempo){
        return pos;
    }
    pos++;
    return returnPos(pos, chave, tempo, item->prox);
}

void printLista(struct Lista *listaValores){
    struct ItemLista *proxItem = listaValores->inicio;
    int aux;
    //printf("proxItem: %p\n", proxItem);
    if(listaValores->inicio == NULL){
        printf("-1");
    }
    while(proxItem != NULL){
        if(proxItem->back == NULL)
            printf("[%d,%d", proxItem->chave, proxItem->tempo);
        else{
            printf("[%d,%d", proxItem->chave, proxItem->tempo);
            aux = returnPos(0, proxItem->back->chave, proxItem->back->tempo, listaValores->inicio);
            if(aux > -1)
                printf(",%d",aux);
        }
        proxItem = proxItem->prox;
        if(proxItem == NULL){
            printf("]");
        }else{
            printf("] ");
        }
    }
}

void destroiLista(struct Lista *listaValores){
    ItemLista *proxItem;
    ItemLista *antItem;

    antItem = listaValores->inicio;
    while(antItem != NULL){
        proxItem = antItem->prox;
        free(antItem);
        antItem = proxItem;
    }
}

int main(){

    int tempo = 0;
    //int i, j;

    struct Lista *listaValores;

    listaValores = (struct Lista*) malloc(sizeof(struct Lista));
    listaValores->inicio = NULL;

    int valor1, valor2;
    char operacao;

    scanf("%c", &operacao);
    while(operacao != 'f'){
        if(operacao == 'i'){
            scanf("%d %d", &valor1, &valor2);
            insereLista(tempo, valor1, valor2, listaValores);
            tempo++;
        } else if(operacao == 'r'){
            scanf("%d", &valor1);
            removeItemLista(valor1, listaValores);
            tempo++;
        }
        scanf("%c", &operacao);    
    }

    printLista(listaValores);

    destroiLista(listaValores);
    free(listaValores);

    return 0;
}