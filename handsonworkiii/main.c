#include <stdio.h>
#include <math.h>
#include <string.h>

//CHAMADA DAS FUNÇÕES UTILIZADAS
int converterBin2Dec(long long valor_binario);
long long converterDec2Bin(int valor_decimal);
int converterDec2Oct(int valor_decimal);
long long converterOct2Dec(int valor_octal);

int main()
{

    //VARIAVEIS UTILIZADAS
    char opcao = ' ';
    int valor_octal;
    int opcao2 = 1;
    long long valor_binario;
    int valor_decimal, cociente;
    int sequencial, valor_temp, tamanho_string;
    char valor_hexa[100];

    //ENQUANTO FOR A OPCAO 1 EXECUTA NOVAMENTE, SE FOR DIFERENTE DE 1 SISTEMA É FINALIZADO
     while (opcao2 = 1) {
        //MOSTRA O MENUM PRINCIPAL
        printf("\n----------------------\n");
        printf("##BEM VINDO AO CONVERSOR DE BASES!##\n");
        printf("\nDigite a Opcao de conversao desejada\n");
        printf("\n1 - Binario para Decimal\n");
        printf("2 - Decimal para Binario\n");
        printf("3 - Decimal para Octal\n");
        printf("4 - Octal para Decimal\n");
        printf("0 - Sair\n");
        printf("\nResposta: ");
        scanf("%c", &opcao);
        getchar();

        //OPÇÃO 0 - FECHA O SISTEMA
        if (opcao == '0') {
        printf("Clique em ENTER e o sistema sera finalizado\n");
            opcao2 = 2;
            exit(0);
        }

        //OPÇÃO 1 - BINÁRIO -> DECIMAL
        else if (opcao == '1') {
            printf("Digite numero binario: ");
            scanf("%lld", &valor_binario);
            printf("[%lld] em binario = [%d] em decimal\n", valor_binario, converterBin2Dec(valor_binario));
        }

        //OPÇÃO 2 - DECIMAL -> BINÁRIO
        else if (opcao == '2') {
            printf("Digite o numero decimal: ");
            scanf("%d", &valor_decimal);
            printf("[%d] em decimal = [%lld] em binario\n", valor_decimal, converterDec2Bin(valor_decimal));
        }

        //OPÇÃO 3 - DECIMAL -> OCTAL
        else if (opcao == '3') {
            printf("Digite o numero decimal: ");
            scanf("%d", &valor_decimal);
            printf("[%d] em decimal = [%d] em octal\n", valor_decimal, converterDec2Oct(valor_decimal));
        }

        //OPÇÃO 4 - OCTAL -> DECIMAL
        else if (opcao == '4') {
            printf("Digite o numero octal: ");
            scanf("%d", &valor_octal);
            printf("[%d] em octal = [%lld] em decimal\n", valor_octal, converterOct2Dec(valor_octal));
        }
        //OPÇÃO DESCONHECIDAO
        else {
            printf("Opcao desconhecida[%c]\n", opcao);
        }
     }
}


///FUNCOES PARA CONVERSOES

//CONCERSAO DE BINARIO X DECIMAL
int converterBin2Dec(long long valor_binario)
{
    int valor_decimal = 0, sequencial = 0, resto;

    //ENQUANTO EXISTIR VALOR NO BINÁRIO
    while (valor_binario != 0)
    {
        //PEGA O RESTO DA DIVISÃO DO VALOR POR 10
        resto = valor_binario % 10;

        //DIVIDE O VALOR BINARIO POR 10
        valor_binario /= 10;

        //INCREMENTA O VALOR DECIMAL COM O RESTO DA DIVISÃO MULTIPLICANDO POR 2 ELEVADO AO SEQUENCIAL
        valor_decimal += resto * pow(2, sequencial);

        //INCREMENTA A SEQUENCIAL
        ++sequencial;
    }

    return valor_decimal;
}

//CONCERSAO DE DECIMAL X BINARIO
long long converterDec2Bin(int valor_decimal)
{
    long long valor_binario = 0;
    int resto, sequencial = 1;

    //ENQUANTO O VALOR DECIMAL FOR DIFERENTE DE
    while (valor_decimal != 0)
    {
        //PEGA O RESTO DA DIVISAO
        resto = valor_decimal % 2;

        //DIVIDE O VALOR DECIMAL POR 2
        valor_decimal /= 2;

        //INCREMENTA O VALOR BINÁRIO, MULTIPLICANDO O RESTO DA DIVISAO PELO SEQUENCIAL
        valor_binario += resto * sequencial;

        //MULTIPLICANDO O SEQUENCIAL POR 10
        sequencial *= 10;
    }

    return valor_binario;
}

//CONCERSAO DE DECIMAL X OCTAL
int converterDec2Oct(int valor_decimal)
{
    int valor_octal = 0, sequencia = 1;

    //ENQUANTO O VALOR DECIMAL FOR DIFERENTE DE ZERO
    while (valor_decimal != 0)
    {
        //INCREMENTA O VALOR OCTAL COM O RESTO DA DIVISAO DO DECIMAL POR 8  MULTIPLICANDO PELO SEQUENCIAL
        valor_octal += (valor_decimal % 8) * sequencia;

        //O VALOR DECIMAL SERÁ DIVIDIDO POR 8
        valor_decimal /= 8;

        //O SEQUENCIAL SERA MULTIPLICADO POR 10
        sequencia *= 10;
    }

    return valor_octal;
}

//CONCERSAO DE OCTAL X DECIMAL
long long converterOct2Dec(int valor_octal)
{
    int valor_decimal = 0, sequencia = 0;

    //ENQUANTO O VALOR OCTAL FOR DIFERENTE DE ZERO
    while(valor_octal != 0)
    {
        //INCREMENTA O VALOR DECIMAL COM O RESTO DA DIVISÃO DO VALOR OCTAL POR 10 MULTIPLICADO POR 8 ELEVADO PELO SEQUENCIAL
        valor_decimal += (valor_octal % 10) * pow(8, sequencia);

        //INCREMENTA O SEQUENCIAL
        ++sequencia;

        //DIVIDE O VALOR OCTAL POR 10
        valor_octal /= 10;
    }

    return valor_decimal;
}
