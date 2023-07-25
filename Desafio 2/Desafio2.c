/* Faça um programa para jogar o jogo da velha. Ao final imprima o resultado do jogo e pergunte se deseja jogar novamente. */

#include <stdio.h>
#include <stdlib.h>

int main(){

//estrutura de dados

int i,j, linha, coluna, jogador, ganhou, jogadas, opcao;
char jogo[3][3];

do{
    jogador = 1;
    ganhou = 0;
    jogadas = 0;

    //como inicializar nossa estrutura de dados

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            jogo[i][j] = ' '; // foi atribuido o caracter espaço para cada linha da matriz
        }
    }

    do{
        //imprimir jogo
        printf("\n\n\t 0   1   2\n\n");
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(j == 0)
                    printf("\t");
                printf(" %c ", jogo[i][j]);
                if(j < 2)
                    printf("|");
                if(j == 2)
                    printf("  %d", i);
            }
            if(i < 2)
                printf("\n\t------------");
            printf("\n");
        }

        //ler coordenadas
        do{
        printf("\n\nJogador %d : Digite a linha e a coluna que deseja jogar: ", jogador);
        scanf("%d%d", &linha, &coluna);
        }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

        //salvar coordenadas
        if(jogador == 1){
            jogo[linha][coluna] = '0';
            jogador ++;
        }
        else{
            jogo[linha][coluna] = 'X';
            jogador = 1;
        }
        jogadas++;

        //alguém ganhou por linha?
        if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
           jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
           jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
             printf("\nParabens! O jogador 1 venceu por linha!\n");
             ganhou = 1;
        }

        if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
           jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
           jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
             printf("\nParabens! O jogador 2 venceu por linha!\n");
             ganhou = 1;
        }

        //alguém ganhou por coluna?
        if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
           jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
           jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
             printf("\nParabens! O jogador 1 venceu por coluna!\n");
             ganhou = 1;
        }

        if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
           jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
           jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
             printf("\nParabens! O jogador 2 venceu por coluna!\n");
             ganhou = 1;
           }

        //alguém ganhou na diagonal principal?
        if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
             printf("\nParabens! O jogador 1 venceu na diagonal principal!\n");
             ganhou = 1;
        }

        if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
             printf("\nParabens! O jogador 2 venceu na diagonal principal!\n");
             ganhou = 1;
        }

        //alguém ganhou na diagonal secundaria?
        if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
             printf("\nParabens! O jogador 1 venceu na diagonal secundaria!\n");
             ganhou = 1;
        }

        if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
             printf("\nParabens! O jogador 2 venceu na diagonal secundaria!\n");
             ganhou = 1;
        }

    }while(ganhou == 0 && jogadas < 9);

    if(ganhou == 0)
        printf("\nO jogo finalizou sem ganhador\n");

    printf("\nDigite 1 para jogar novamente\n");
    scanf("%d", &opcao);

}while(opcao == 1);

return 0;
}
