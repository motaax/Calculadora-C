#include <stdio.h>
#include <stdlib.h>

double adicao(double a, double b) {
    return a + b;
}

double subtracao(double a, double b) {
    return a - b;
} 

double multiplicacao(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    return a / b;
}

int main() {
    int op;
    double num1, num2, resultado;
    char op_char;
    char continuar;
    int entrada_valida;    
    int resultado_scanf;   

    while (1) {
        printf("===============================\n");
        printf("   Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");
        printf("Opcao: ");

        resultado_scanf = scanf("%d", &op);

        if (resultado_scanf != 1) {
            printf("\nErro: Opcao invalida! Por favor, insira um numero entre 1 e 5.\n\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (op == 5) {
            printf("\nObrigado por usar a calculadora! Ate a proxima.\n");
            break;
        }

        if (op < 1 || op > 5) {
            printf("\nErro: Opcao invalida! Por favor, insira um numero entre 1 e 5.\n\n");
            continue;
        }

        entrada_valida = 0;

        printf("Digite o primeiro numero: ");
        while (!entrada_valida) {
            resultado_scanf = scanf("%lf", &num1); 
            
            if (resultado_scanf == 1) {            
                entrada_valida = 1; 
            } else {
                printf("Entrada invalida. Digite um numero valido: ");
                while (getchar() != '\n'); 
            }
        }

        entrada_valida = 0; 

        printf("Digite o segundo numero: ");
        while (!entrada_valida) {
            resultado_scanf = scanf("%lf", &num2); 
            
            if (resultado_scanf == 1) {            
                entrada_valida = 1; 
            } else {
                printf("Entrada invalida. Digite um número valido: ");
                while (getchar() != '\n'); 
            }
        }

        int erro_divisao = 0;

        if (op == 1) {
            resultado = adicao(num1, num2);
            op_char = '+';
        } 
        else if (op == 2) {
            resultado = subtracao(num1, num2);
            op_char = '-';
        } 
        else if (op == 3) {
            resultado = multiplicacao(num1, num2);
            op_char = '*';
        } 
        else if (op == 4) {
            if (num2 == 0) {
                printf("\nErro: Divisao por zero nao e permitida.\n");
                erro_divisao = 1;
            } else {
                resultado = divisao(num1, num2);
                op_char = '/';
            }
        }

        if (!erro_divisao) {
            printf("Resultado: %g %c %g = %g\n", num1, op_char, num2, resultado);
        }

        int resposta_valida = 0;
        while (!resposta_valida) {
            printf("\nDeseja realizar outra operacao? (s/n): ");
            scanf(" %c", &continuar); 

            if (continuar == 's' || continuar == 'S') {
                resposta_valida = 1;
                printf("\n"); 
            } else if (continuar == 'n' || continuar == 'N') {
                printf("\nObrigado por usar a calculadora! Ate a proxima.\n");
                return 0; 
            } else {
                printf("Resposta invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
            }
        }
    }

    return 0;
}