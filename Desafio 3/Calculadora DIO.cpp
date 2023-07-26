
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num) {
    if (num > 0) {
        decimalToBinary(num / 2);
        printf("%d", num % 2);
    }
}

int main() {
    char op;
    int num1, num2, result;

    printf("Digite um operador (+, -, *, %% , / ): ");
    scanf(" %c", &op);

    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Erro: divisão por zero não permitida!\n");
                return 1;
            }
            break;
        case '%':
        	result = num1 % num2;
        	break;
        default:
            printf("Operador inválido!\n");
            //return 1;
    }

    printf("Resultado em binário: ");
    decimalToBinary((int)result);
    printf("\n");

    printf("Resultado em hexadecimal: %X\n", result);

   printf("Resultado em octal: %o\n", result);

   printf("Resultado em decimal: %d\n", result);
    
	//return 0;      	 
}
