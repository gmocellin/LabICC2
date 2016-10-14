#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int palindromo(char *start, char *end, int tam){
	if(tam < 2) return 1;
	return (*start != *end) ? 0 : palindromo(start+1, end-1, tam-2);
}

int analisa_p(char *palavra){
	int len = strlen(palavra);
	int i, j, k, first_init, first_end;
	char first[256], second[256];

	first[0] = '\0';

	for(i = len; i >= 3; i--){
		for(j = len-i, k = len-1; j > 0; j--, k--){
			if(palindromo(&palavra[j], &palavra[k], i)){

				if (first[0] == '\0'){
					strncpy(first, &palavra[j], i);
					first_init = j;
					first_end = k;
					first[i] = '\0';
					//printf("first: %s\n", first);
				} else {
					strncpy(second, &palavra[j], i);
					second[i] = '\0';
					//printf("second: %s\n", second);
					if(!(j > first_init && k < first_end) && strcmp(first, second) != 0){
						return 1;
					}
				}
			}
		}
	}

	return 0;
}

int main(){

	char palavras[1000][255];
	int i, n=0;

	while(EOF != scanf("%s", palavras[n])){
		n++;
	}

	for(i=0; i < n; i++){
		if (analisa_p(palavras[i])){
			printf("%s\n", palavras[i]);
		}
	}

	return 0;
}