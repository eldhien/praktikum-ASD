#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mensimulasikan gerakan kuda dalam papan catur
void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Array offset untuk gerakan kuda
    int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                       {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    // Melakukan simulasi gerakan kuda
    for (int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];

        // Memeriksa apakah gerakan kuda masih dalam papan catur
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            // Mengubah nilai pada posisi yang dapat dicapai kuda menjadi 1
            *(chessBoard + new_i * size + new_j) = 1;
        }
    }
}

int main() {
    int i, j;
    printf("Masukkan nilai i dan j dipisahkan dengan spasi: ");
    scanf("%d %d", &i, &j);

    // Inisialisasi array papan catur dengan nilai awal 0
    int chessBoard[8][8] = {0};

    // Simulasi gerakan kuda
    koboImaginaryChess(i, j, 8, (int *)chessBoard);

    // Output array papan catur setelah simulasi
    printf("Hasil simulasi gerakan kuda:\n");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%d ", chessBoard[row][col]);
        }
        printf("\n");
    }

    return 0;
}
