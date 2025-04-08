#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Posição inicial: água
        }
    }
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    // Validação de limite do tabuleiro
    if (orientacao == 0 && coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Horizontal
    if (orientacao == 1 && linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Vertical

    // Validação de sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 0 && tabuleiro[linha][coluna + i] != 0) return 0; // Horizontal
        if (orientacao == 1 && tabuleiro[linha + i][coluna] != 0) return 0; // Vertical
    }

    // Posicionar navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = 3; // Horizontal
        } else {
            tabuleiro[linha + i][coluna] = 3; // Vertical
        }
    }

    return 1; // Posicionamento bem-sucedido
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientações predefinidas dos navios
    int linhaNavio1 = 2, colunaNavio1 = 3, orientacaoNavio1 = 0; // Horizontal
    int linhaNavio2 = 5, colunaNavio2 = 5, orientacaoNavio2 = 1; // Vertical

    // Posicionar navio 1
    if (!posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, orientacaoNavio1)) {
        printf("Falha ao posicionar o Navio 1.\n");
    }

    // Posicionar navio 2
    if (!posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, orientacaoNavio2)) {
        printf("Falha ao posicionar o Navio 2.\n");
    }

    // Exibir o tabuleiro com os navios posicionados
    printf("Tabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}