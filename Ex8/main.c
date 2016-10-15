#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void print_game(char game[5][5]){
    int i, j;
    for(i = 0; i < 5; i++ ){
        for(j = 0; j < 4; j++){
            printf("%c ", game[i][j]);
        }
        printf("%c\n", game[i][j]);
    }
}

int main(){

    char game[5][5], read_aux;
    char move;

    int i, j, blank[2], fail;

    blank[0] = 0;
    blank[1] = 0;

    for(i = 0; i < 5; i++ ){
        scanf("%c", &read_aux);
        for(j = 0; read_aux != '\n'; j++){
            game[i][j] = read_aux;
            if(read_aux == ' '){
                blank[0] = i;
                blank[1] = j;
            }
            scanf("%c", &read_aux);
        }
    }

    fail = 0;
    scanf("%c", &move);
    while(move != 'O'){
        //printf("%c\t", move);
        //printf("%d %d\n", blank[0], blank[1]);

        if(move == 'B'){
            if(blank[0] == 4){
                fail = 1;
                break;
            }
            game[blank[0]][blank[1]] = game[blank[0]+1][blank[1]];
            game[blank[0]+1][blank[1]] = ' ';
            blank[0]++;
        } else if(move == 'A'){
            if(blank[0] == 0){
                fail = 1;
                break;
            }
            game[blank[0]][blank[1]] = game[blank[0]-1][blank[1]];
            game[blank[0]-1][blank[1]] = ' ';
            blank[0]--;
        } else if(move == 'R'){
            if(blank[1] == 4){
                fail = 1;
                break;
            }
            game[blank[0]][blank[1]] = game[blank[0]][blank[1]+1];
            game[blank[0]][blank[1]+1] = ' ';
            blank[1]++;
        } else if(move == 'L'){
            if(blank[1] == 0){
                fail = 1;
                break;
            }
            game[blank[0]][blank[1]] = game[blank[0]][blank[1]-1];
            game[blank[0]][blank[1]-1] = ' ';
            blank[1]--;
        }

        scanf("%c", &move);
    }

    if(fail){
        printf("This puzzle has no final configuration.");
    }else{
        print_game(game);
    }

    return 0;
}
