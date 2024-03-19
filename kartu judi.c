#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Fungsi untuk mengonversi nilai kartu J, Q, K menjadi nilai numerik
int convertToNumericValue(char *card) {
    if (strcmp(card, "J") == 0) return 11;
    else if (strcmp(card, "Q") == 0) return 12;
    else if (strcmp(card, "K") == 0) return 13;
    else return atoi(card); // Untuk nilai kartu numerik (1-10)
}

// Fungsi untuk mengonversi nilai numerik kembali menjadi kartu J, Q, K atau angka
void convertToCardValue(int value, char *card) {
    if (value == 11) strcpy(card, "J");
    else if (value == 12) strcpy(card, "Q");
    else if (value == 13) strcpy(card, "K");
    else sprintf(card, "%d", value); // Untuk nilai kartu numerik (1-10)
}

// Fungsi untuk memeriksa apakah nilai kartu valid (1-10, J, Q, K)
bool isValidCard(char *card) {
    int value = atoi(card);
    if ((value >= 1 && value <= 10) || strcmp(card, "J") == 0 || strcmp(card, "Q") == 0 || strcmp(card, "K") == 0)
        return true;
    else
        return false;
}

// Fungsi untuk menghitung jumlah langkah pertukaran menggunakan algoritma selection sort
int countSwaps(int cards[], int n) {
    int swaps = 0;
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (cards[j] < cards[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            // Tukar posisi kartu
            int temp = cards[min_index];
            cards[min_index] = cards[i];
            cards[i] = temp;
            swaps++;

            // Tampilkan pertukaran
            printf("Langkah %d: ", swaps);
            for (int k = 0; k < n; k++) {
                char card[3];
                convertToCardValue(cards[k], card);
                printf("%s ", card);
            }
            printf("\n");
        }
    }
    return swaps;
}

int main() {
    int N;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &N); // Menerima jumlah kartu

    int cards[N];
    printf("Masukkan nilai kartu dipisahkan dengan spasi (1-10, J, Q, K): ");
    for (int i = 0; i < N; i++) {
        char card[3];
        do {
            scanf("%s", card); // Menerima nilai kartu
            if (!isValidCard(card)) {
                printf("Nilai kartu tidak valid! Masukkan kembali: ");
            }
        } while (!isValidCard(card));
        cards[i] = convertToNumericValue(card);
    }

    // Menghitung jumlah langkah pertukaran untuk mengurutkan kartu
    int swaps = countSwaps(cards, N);

    printf("Jumlah minimal langkah pertukaran: %d\n", swaps); // Output jumlah minimal langkah pertukaran

    return 0;
}
