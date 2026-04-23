#include <stdio.h>
#include <stdlib.h>
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"
#define LINHAS 10
#define COLUNAS 10
#define NAVIO 3

/*Definições de posicionamentos*/
int navio_horizontal(int matriz [10][10], int navio [3], int linha, int coluna){

    for (int i = 0; i < NAVIO; i++)
    {
        matriz [linha][coluna+i] = navio[i]; // Posiciona o navío na horizontal
    }
}

int navio_vertical(int matriz [10][10], int navio [3], int linha , int coluna){

    for (int i = 0; i < NAVIO; i++)
    {
        matriz [linha+i][coluna] = navio[i]; // Posiciona o navío na vertical
    }
}

int navio_diagonal(int matriz [10][10], int navio [3],int linha, int coluna){

    for (int i = 0; i < NAVIO; i++)
    {
        matriz [linha+i][coluna+i] = navio[i]; // Posiciona o navío na diagonal decrescente para direita
    }
}

int navio_diagonal_inversa(int matriz [10][10], int navio [3], int linha, int coluna){

    for (int i = 0; i < NAVIO; i++)
    {
        matriz [linha+i][coluna-i] = navio[i]; // Posiciona o navío na diagonal decrescente para esquerda
    }
}

/*Definições de habilidades*/
//Habilidade em cruz
int cruz_formato (int matriz [10] [10], int pos_x, int pos_y){
    int colunas = 5;
    int linhas = 3;
    int meio_linhas = linhas / 2;
    int meio_colunas = colunas / 2;
    int cruz[linhas][colunas];

    // Preenchimento
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            //Acha o meio para preencher
            if (i == meio_linhas || j == meio_colunas) {
                cruz[i][j] = 5;
                matriz [pos_x+ i][pos_y+j] = cruz[i][j];
            } else {
                cruz[i][j] = 0;
                matriz [pos_x+ i][pos_y+j] = cruz [i][j];
            }
        }

    }
}
//Habilidade em cone
int cone_formato (int matriz [10] [10], int pos_x, int pos_y){
    int linhas = 3;
    int colunas = 5;
    int cone [linhas][colunas];
    
    // Preenche o triângulo
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas ;j++){
          if(j >= (2-i) && j <= (2+i))
          {
            cone [i][j] = 5;
            matriz[pos_x + i][pos_y + j] = cone [i][j];
          }else{
            cone [i][j] = 0;
            matriz[pos_x + i][pos_y + j] = cone [i][j];
          }
          
        }
    }
}
//Habilidade octaedro
int octaedro_formato (int matriz [10] [10], int pos_x, int pos_y){
    int colunas = 3;
    int linhas = 3;
    int centro = linhas / 2;
    int octaedro[linhas][colunas];

    // Preenchimento
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Calcula a distância do ponto atual ao centro
            // abs() é o valor absoluto (sempre positivo)
            int dist_i = abs(i - centro);
            int dist_j = abs(j - centro);
            // Se a soma das distâncias for menor ou igual ao raio, é 1
            if (dist_i + dist_j <= centro) {
                octaedro[i][j] = 5;
                matriz[pos_x+i][pos_y+j] = octaedro[i][j];
            } else {
                octaedro[i][j] = 0;
                matriz[pos_x+i][pos_y+j] = octaedro[i][j];
            }
        }
    }
}

/*Função principal*/
int main(){
    /*Declaração de variáveis*/
    char colunas_auxiliar[COLUNAS] = {'a','b','c','d','e','f','g','h','i','j'}; // Letras para identificação das colunas no tabuleiro
    int linhas_auxiliar[LINHAS] = {0,1,2,3,4,5,6,7,8,9}; //Números para identificaçaõ das linhas no tabuleiro
    int tabuleiro[LINHAS][COLUNAS]; //Definição do tabuleiro
    int valor_inicial = 0; // Valor inicial de todo o tabuleiro, 0 foi considerado o padrão para água 
    int controle = 0; // Variável de controle para o loop while 
    int navios[NAVIO] =  {3,3,3}; 

    /*Atribuição do valor inicial para toda a matriz*/
    for (int i = 0; i < LINHAS; i++) // Loop para linhas
    {
        for (int j = 0; j < COLUNAS; j++) // Loop para colunas 
        {
            tabuleiro[i][j] = valor_inicial; // Atribuição do valor inicial (0) para toda a matriz
        }
    }

    /*Alocando os navios na matriz*/
    //Navio horizontal
    navio_horizontal(tabuleiro,navios, 0, 0);

    //Navio na vertical
    navio_vertical(tabuleiro,navios , 1 , 0);

    //Navio na diagonal
    navio_diagonal(tabuleiro,navios, 1, 2);

    //Navio na diagonal inversa
    navio_diagonal_inversa(tabuleiro,navios, 0, 9);

    /*Soltando poderes*/
    //Cruz 
    cruz_formato(tabuleiro, 3, 3);

    //Cone
    cone_formato(tabuleiro, 5, 0);

    //Octaedro
    octaedro_formato(tabuleiro, 6,6);
    

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

    return 0;
}
