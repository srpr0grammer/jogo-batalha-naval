#include <stdio.h>
#include <stdlib.h>

#define TAM 8 // tamanho do tabuleiro 8x8

// Função para exibir o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n   ");
    for (int j = 0; j < TAM; j++) printf("%d ", j + 1);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ===== MÓDULO 1 — NOVATO =====
// Usa vetores e loops simples para posicionar um navio
void moduloNovato() {
    printf("\n[MÓDULO 1 - NOVATO] Representação de tabuleiro com vetor e posicionamento de navio simples.\n");

    char tabuleiro[TAM][TAM];
    // Inicializa tudo com '~' (água)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';

    // Posiciona um navio horizontal na linha 4
    int linha = 3;
    for (int j = 2; j < 5; j++) {
        tabuleiro[linha][j] = 'N'; // N = navio
    }

    mostrarTabuleiro(tabuleiro);
}

// ===== MÓDULO 2 — AVENTUREIRO =====
// Usa matrizes e loops aninhados para posicionar vários navios, inclusive em diagonal
void moduloAventureiro() {
    printf("\n[MÓDULO 2 - AVENTUREIRO] Posicionando múltiplos navios em diferentes direções.\n");

    char tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';

    // Navio horizontal
    for (int j = 1; j < 5; j++)
        tabuleiro[2][j] = 'N';

    // Navio vertical
    for (int i = 4; i < 7; i++)
        tabuleiro[i][6] = 'N';

    // Navio diagonal
    for (int d = 0; d < 4; d++)
        tabuleiro[d + 3][d + 2] = 'N';

    mostrarTabuleiro(tabuleiro);
}

// ===== MÓDULO 3 — MESTRE =====
// Condicionais dentro de loops aninhados para simular áreas de efeito
void moduloMestre() {
    printf("\n[MÓDULO 3 - MESTRE] Áreas de efeito de habilidades especiais.\n");

    char tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';

    int centroX = 4, centroY = 4;

    // 1️⃣ Área em cruz
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == centroX || j == centroY)
                tabuleiro[i][j] = '+';
        }
    }

    printf("\n>> Habilidade em CRUZ:\n");
    mostrarTabuleiro(tabuleiro);

    // 2️⃣ Área em cone (para baixo)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';

    for (int i = centroX; i < TAM; i++) {
        for (int j = centroY - (i - centroX); j <= centroY + (i - centroX); j++) {
            if (j >= 0 && j < TAM)
                tabuleiro[i][j] = 'V';
        }
    }

    printf("\n>> Habilidade em CONE:\n");
    mostrarTabuleiro(tabuleiro);

    // 3️⃣ Área em octaedro (diamante)
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';

    int raio = 3;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - centroX) + abs(j - centroY) <= raio)
                tabuleiro[i][j] = 'O';
        }
    }

    printf("\n>> Habilidade em OCTAEDRO:\n");
    mostrarTabuleiro(tabuleiro);
}

// ===== MENU PRINCIPAL =====
int main() {
    int opcao;
    do {
        printf("\n=== BATALHA NAVAL - OCEANIC GAMES ===\n");
        printf("1. Módulo Novato (vetores)\n");
        printf("2. Módulo Aventureiro (matrizes e loops aninhados)\n");
        printf("3. Módulo Mestre (áreas de efeito condicionais)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: moduloNovato(); break;
            case 2: moduloAventureiro(); break;
            case 3: moduloMestre(); break;
            case 0: printf("Encerrando o jogo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
