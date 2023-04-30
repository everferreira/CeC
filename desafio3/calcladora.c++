#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declaração de funções
int obter_inteiro(char *mensagem);
float obter_float(char *mensagem);
int obter_base(char *mensagem);
int obter_operacao();
void imprimir_resultado(int resultado);

// Função principal
int main()
{
    // Obter os números e a operação do usuário
    int num1, num2, resultado, op;
    float fnum1, fnum2, fresultado;
    int base;
    
    base = obter_base("Escolha uma base (1 = decimal, 2 = binário, 3 = hexadecimal): ");
    num1 = obter_inteiro("Digite o primeiro número: ");
    num2 = obter_inteiro("Digite o segundo número: ");
    op = obter_operacao();

    // Executar a operação selecionada
    switch (op)
    {
        case 1:
            resultado = num1 + num2;
            break;
        case 2:
            resultado = num1 - num2;
            break;
        case 3:
            resultado = num1 * num2;
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Erro: Divisão por zero\n");
                exit(1);
            }
            resultado = num1 / num2;
            break;
        case 5:
            fnum1 = obter_float("Digite o primeiro número: ");
            fnum2 = obter_float("Digite o segundo número: ");
            fresultado = fnum1 + fnum2;
            printf("Resultado: %f\n", fresultado);
            break;
        case 6:
            fnum1 = obter_float("Digite o primeiro número: ");
            fnum2 = obter_float("Digite o segundo número: ");
            fresultado = fnum1 - fnum2;
            printf("Resultado: %f\n", fresultado);
            break;
        case 7:
            fnum1 = obter_float("Digite o primeiro número: ");
            fnum2 = obter_float("Digite o segundo número: ");
            fresultado = fnum1 * fnum2;
            printf("Resultado: %f\n", fresultado);
            break;
        case 8:
            fnum1 = obter_float("Digite o primeiro número: ");
            fnum2 = obter_float("Digite o segundo número: ");
            if (fnum2 == 0)
            {
                printf("Erro: Divisão por zero\n");
                exit(1);
            }
            fresultado = fnum1 / fnum2;
            printf("Resultado: %f\n", fresultado);
            break;
        case 9:
            num1 = obter_inteiro("Digite o número: ");
            resultado = sqrt(num1);
            break;
        case 10:
            fnum1 = obter_float("Digite o número: ");
            fresultado = sqrt(fnum1);
            printf("Resultado: %f\n", fresultado);
            break;
        default:
            printf("Operação inválida\n");
            exit(1);
    }

    // Imprimir o resultado
    if (op != 5 && op != 6 && op != 7 && op != 8 && op != 10)
    {
        imprimir_resultado(resultado);
    }

    return 0;
}

// Função para obter um número inteiro do usuário
int obter_inte
