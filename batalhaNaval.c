#include <stdio.h>
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"
#define LINHAS 10
#define COLUNAS 10
#define NAVIO 3

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    /*Declaração de variáveis*/
    char colunas_auxiliar[COLUNAS] = {'a','b','c','d','e','f','g','h','i','j'}; // Letras para identificação das colunas no tabuleiro
    int linhas_auxiliar[LINHAS] = {0,1,2,3,4,5,6,7,8,9}; //Números para identificaçaõ das linhas no tabuleiro
    int tabuleiro[LINHAS][COLUNAS]; //Definição do tabuleiro
    int valor_inicial = 0; // Valor inicial de todo o tabuleiro, 0 foi considerado o padrão para água 
    int controle = 0; // Variável de controle para o loop while 
    int navios[NAVIO] =  {3,3,3}; 

    /*Atribuição do valor inicial para toda a matriz*/
    for (int i = 0; i < 10; i++) // Loop para linhas
    {
        for (int j = 0; j < 10; j++) // Loop para colunas 
        {
            tabuleiro[i][j] = valor_inicial; // Atribuição do valor inicial (0) para toda a matriz
        }
    }

    /*Alocando os navios na matriz*/
    //Navio horizontal
    for (int i = 0; i < NAVIO; i++)
    {
        tabuleiro [1][1+i] = navios[i]; // Posiciona o navío na horizontal
    }

    //Navio na vertical
    for (int i = 0; i < NAVIO; i++)
    {
        tabuleiro [3+i][4] = navios[i]; // Posociona o navío na vertical
    }

    //Navio na diagonal
    for (int i = 0; i < NAVIO; i++)
    {
        tabuleiro [i][7+i] = navios[i]; // Posiciona o navío a partir de uma posição nadiagonal decrescente a direita
    }

    //Navio na diagonal inversa
    for (int i = 0; i < NAVIO; i++)
    {
        tabuleiro [6+i][2-i] = navios[i]; //Posiciona o navío a partir de uma posição a diagonal decrescente a esquerda
    }
    
    
    /*Exibição do tabuleiro */
    printf(RED "+----------------------------------------------+\n" RESET); // Bordas do tabuleiro
    printf( RED "|      " RESET);// Bordas do tabuleiro

     while (controle < 10)
     {
        printf(RED "%-3c " RESET, colunas_auxiliar[controle]); // Exibição das letras de identificação das colunas 
        controle++; // incremento da variável de controle  
     }
     printf( RED "| " RESET);// Bordas do tabuleiro
     printf("\n");
     
     /*Loop para exibição do tabuleiro e atribuição do valor inicial para toda a matriz*/
    for (int i = 0; i < LINHAS; i++) // Loop para linhas
    {
        printf( RED "| " RESET);// Bordas do tabuleiro
        printf(RED "%d    "RESET, linhas_auxiliar[i]);// Bordas do tabuleiro
        for (int j = 0; j < COLUNAS; j++) // Loop para colunas 
        {
            printf("%-4d", tabuleiro[i][j]); // Exibição do tabuleiro(Matriz) com espaçãmento de -4
        }
        printf(RED "| \n" RESET);// Bordas do tabuleiro
    }

    printf(RED "+----------------------------------------------+\n" RESET);// Bordas do tabuleiro


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
