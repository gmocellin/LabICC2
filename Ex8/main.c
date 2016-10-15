#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    float total_bytes_left, sum_bytes;
    int count_total;
    char read_aux[100];

    scanf("%f", &total_bytes_left);

    printf("Data size of %.0f bytes:\n", total_bytes_left);

    sum_bytes = 0;
    count_total = 0;

    scanf("%s", read_aux);
    while(strcmp(read_aux, "F\0") != 0){
        sum_bytes += atoi(read_aux);

        count_total++;

        if(count_total%5 == 0){

            total_bytes_left -= sum_bytes;

            if(sum_bytes == 0){
                printf("Time remaining: stalled\n");
            } else {
                printf("Time remaining: %.0lf seconds\n", ceil(total_bytes_left/(sum_bytes/5))); 
            }
            sum_bytes = 0;
        }

        scanf("%s", read_aux);
    }

    printf("Total time: %d seconds", count_total);

    return 0;
}
