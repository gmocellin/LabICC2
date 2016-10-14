#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_val(int n, int m, int **labirinto, char start, char end){

    int i, j;

    printf("n = %d\n", n);
    printf("m = %d\n", m);

    printf("start = %c\n", start);
    printf("end = %c\n", end);

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }

}

int caminha(int **labirinto, int start_pos[2], int end_pos[2], int n, int m){

    //printf("start_pos[0] = %d, start_pos[1] = %d, N = %d, M = %d, end_pos[0] = %d, end_pos[1] = %d\n", start_pos[0] , start_pos[1], n , m, end_pos[0], end_pos[1] );

    if(start_pos[0] < 0 || start_pos[1] < 0 || start_pos[0] > n || start_pos[1] > m){
        return 0;
    }

    if(labirinto[start_pos[0]][start_pos[1]] == 1){
        return 0;
    }

    if(start_pos[0] == end_pos[0] || start_pos[1] == end_pos[1]){
        return 1;
    }

    int next_pos[2];

    labirinto[start_pos[0]][start_pos[1]] = 1;

    next_pos[0] = start_pos[0]+1;
    next_pos[1] = start_pos[1];
    if (!caminha(labirinto, next_pos, end_pos, n, m)){
        next_pos[0] = start_pos[0];
        next_pos[1] = start_pos[1]+1;
        if(!caminha(labirinto, next_pos, end_pos, n, m)){
            next_pos[0] = start_pos[0];
            next_pos[1] = start_pos[1]-1;
            if(!caminha(labirinto, next_pos, end_pos, n, m)){
                next_pos[0] = start_pos[0]-1;
                next_pos[1] = start_pos[1];
                if(!caminha(labirinto, next_pos, end_pos, n, m)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int labirinto_start(int **labirinto, char start, char end, int n, int m ){
    int start_pos[2], end_pos[2];

     if(start =='N'){
        start_pos[0] = 0;
        start_pos[1] = 0;
        if(end == 'S'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = n-1;
                end_pos[1] = -1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'O'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = -1;
                end_pos[1] = 0;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'L'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = -1;
                end_pos[1] = m-1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }
    } else if(start == 'S'){
        start_pos[0] = n-1;
        start_pos[1] = 0;
        if(end == 'N'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = 0;
                end_pos[1] = -1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'O'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = -1;
                end_pos[1] = 0;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'L'){
            for(; start_pos[1] < m; start_pos[1]++){
                end_pos[0] = -1;
                end_pos[1] = m-1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }
    } else if (start == 'O'){
        start_pos[0] = 0;
        start_pos[1] = 0;
        if(end == 'S'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = n-1;
                end_pos[1] = -1;
                //printf("start_pos[0] = %d, start_pos[1] = %d, N = %d, M = %d, end_pos[0] = %d, end_pos[1] = %d\n", start_pos[0] , start_pos[1], n , m, end_pos[0], end_pos[1] );
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'N'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = 0;
                end_pos[1] = -1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'L'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = -1;
                end_pos[1] = m-1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }
    }else if(start == 'L'){
        start_pos[0] = 0;
        start_pos[1] = m-1;
        if(end == 'S'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = n-1;
                end_pos[1] = -1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'O'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = -1;
                end_pos[1] = 0;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }else if(end == 'N'){
            for(; start_pos[0] < n; start_pos[0]++){
                end_pos[0] = 0;
                end_pos[1] = -1;
                if((labirinto[start_pos[0]][start_pos[1]] != 1 ) && caminha(labirinto, start_pos, end_pos, n-1, m-1))
                    return 1;
            }
        }
    }else{
            printf ("Só são aceitos: N, S, L, O");
    }

    return 0;
}

int main (){

    int i, j, n, m;
    int **labirinto;

    char start, end;

    scanf("%c %c %d %d", &start, &end, &n, &m);

    if(start == end){
        printf("Entrada e saida do labirinto igual.");
        return 1;
    }

    labirinto = (int**) malloc (n * sizeof(int*));
    for (i = 0; i < n; i++){
        labirinto[i] = (int*) malloc (m * sizeof(int));
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &labirinto[i][j]);
        }
    }

    //print_val(n, m , labirinto, start, end);

    if (labirinto_start(labirinto, start, end, n , m)){
        printf("Existe saida %c - %c.", start, end);
    } else {
        printf("Nao existe saida %c - %c.", start, end);
    }

    for( i = 0; i < n; i++){
        free(labirinto[i]);
    }
    free(labirinto);


    return 0;
}