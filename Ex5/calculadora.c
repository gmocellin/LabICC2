#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void SUM(int *num1, int *num2, int *result);
void SUB(int *num1, int *num2, int *result);
void MUL(int *num1, int *num2, int *result);
void DIV(int *num1, int *num2, int *result);

void ReadNumber(int *num){
	int i;
	char number_char[1001];

	scanf("%s", number_char);
	int pos = strlen(number_char);
	i=0;

	if(number_char[0] == '-'){
		num[0] = pos-1;
		num[1] = 1;
		i++;
	} else {
		num[0] = pos;
		num[1] = 0;
		pos++;
	}
	for(; i < strlen(number_char); i++, pos--){
		num[pos] = (int)number_char[i] - '0';
		//printf("%d %d\n", num[pos], pos);
	}
}

void PrintNumber(int *num){
	int i;
	int size = num[0];

	//printf("size = %d\n", size);
	if(num[1] == 1){
		printf("-");
	}
	for(i = size+1; i > 1; i--){
		printf("%d", num[i]);
	}
	//printf("\n");
}


void DIV(int *num1, int *num2, int *result){

}

void MUL(int *num1, int *num2, int *result){

}

void SUB(int *num1, int *num2, int *result){
	int i, sub, flag = 1;
	int subNext = 0;

	//PrintNumber(num1);
	//PrintNumber(num2);

	//printf("num1 = %d, num2 = %d\n", num1[0], num2[0]);

	if (num1[0] <= num2[0]){
		//if(num1[2] < num2[2]){
			num1[1] = 1;
			flag = 0;
			SUB(num2, num1, result);
		//}
	} else
		result[1] = 0;

	if(flag){
		for(i = 2; (subNext == 1) || (i < (num1[0]+2)) || (i < (num2[0]+2)); i++){
			if(i >= num1[0]+2 && i >= num2[0]+2){
				result[1] = 1;
				subNext = 0;
			}/* else if(i >= num1[0]+2){
				sub = num2[i] - subNext -1;
				if(sub < 0){
					subNext = 1;
					result[i] = sub + 10;
				} else{
					subNext = 0;
					result[i] = sub;
				}
				result[1] = 1;
			} */else if(i >= num2[0]+2){
				sub = num1[i] - subNext;
				if(sub < 0){
					subNext = 1;
					result[i] = sub + 10;
				} else{
					subNext = 0;
					result[i] = sub;
				}
				result[1] = num2[1];
			} else{
				sub = num1[i] - num2[i] - subNext;
				//printf("sub = %d\n", sub);
				if(sub < 0){
					subNext = 1;
					result[i] = sub + 10;
				} else{
					subNext = 0;
					result[i] = sub;
				}
			}
		}
		result[1] = num2[1];
		result[0] = i-1;
		for(i = result[0]+1; i > 2; i--){
			if(result[i] != 0) break;
		}
		result[0] = i-1;
	}

}

void SUM(int *num1, int *num2, int *result){
	int i, sum;
	int sumNext = 0;

	//PrintNumber(num1);
	//PrintNumber(num2);

	//printf("num1 = %d, num2 = %d\n", num1[6], num2[6]);

	if((num1[1] == 0 && num2[1] == 0) || (num1[1] == 1 && num2[1] == 1)){
		result[1] = 0;
		for(i = 2; (sumNext == 1) || (i < (num1[0]+2)) || (i < (num2[0]+2)); i++){
			//printf("i = %d, sumNext = %d\n", i, sumNext);
			if(i >= num1[0]+2 && i >= num2[0]+2){
				result[i] = 1;
				sumNext = 0;
			} else if(i >= num1[0]+2){
				sum = num2[i] + sumNext;
				if(sum >= 10){
					sumNext = 1;
					result[i] = sum % 10;
				} else{
					sumNext = 0;
					result[i] = sum;
				}
			} else if(i >= num2[0]+2){
				sum = num1[i] + sumNext;
				if(sum >= 10){
					sumNext = 1;
					result[i] = sum % 10;
				} else{
					sumNext = 0;
					result[i] = sum;
				}
			} else{
				sum = num1[i] + num2[i] + sumNext;
				//printf("sum = %d\n", sum);
				if(sum >= 10){
					sumNext = 1;
					result[i] = sum % 10;
				} else{
					sumNext = 0;
					result[i] = sum;
				}
			}
		}
		result[0] = i-2;
	} else {
		SUB(num1, num2, result);
	}

}

int main(){

	char operacao[255];
	int num1[1001];
	int num2[1001];
	int result[1001];
	result[0] = 0;
	result[1] = 0;

	scanf("%s", operacao);

	ReadNumber(num1);
	//PrintNumber(num1);
	ReadNumber(num2);
	//PrintNumber(num2);

	switch (operacao[2]){
		case 'M'://SO 'M' A
			SUM(num1, num2, result);
		break;
		case 'B'://SU 'B' TRAACAO
			SUB(num1, num2, result);
		break;
		case 'L'://MU 'L' TIPLICACAO
			//MUL(num1, num2, result);
		break;
		case 'V'://DI 'V' ISAO
			//DIV(num1, num2, result);
		break;
	}

	PrintNumber(result);

	return 0;
}