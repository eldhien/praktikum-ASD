#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Fungsi untuk mencetak list
void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("(%p %d) ", (void*)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Fungsi untuk menukar node dua node
void swapNodes(Node** head, Node* a, Node* b) {
    if (a == b) return;

    Node* aPrev = a->prev;
    Node* aNext = a->next;
    Node* bPrev = b->prev;
    Node* bNext = b->next;

    // Special case if nodes are adjacent
    if (aNext == b) {
        a->next = bNext;
        a->prev = b;
        b->next = a;
        b->prev = aPrev;

        if (bNext != NULL) bNext->prev = a;
        if (aPrev != NULL) aPrev->next = b;
    } else if (bNext == a) {
        b->next = aNext;
        b->prev = a;
        a->next = b;
        a->prev = bPrev;

        if (aNext != NULL) aNext->prev = b;
        if (bPrev != NULL) bPrev->next = a;
    } else {
        a->next = bNext;
        a->prev = bPrev;
        b->next = aNext;
        b->prev = aPrev;

        if (aNext != NULL) aNext->prev = b;
        if (aPrev != NULL) aPrev->next = b;
        if (bNext != NULL) bNext->prev = a;
        if (bPrev != NULL) bPrev->next = a;
    }

    // Fix head pointer if needed
    if (*head == a) *head = b;
    else if (*head == b) *head = a;
}

// Fungsi untuk mengurutkan list
void sortList(Node** head) {
    if (*head == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    // Jika list hanya memiliki satu node
    if ((*head)->next == *head) return;

    do {
        swapped = 0;
        ptr1 = *head;

        do {
            if (ptr1->next != lptr && ptr1->data > ptr1->next->data) {
                swapNodes(head, ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != *head && ptr1 != lptr);

        lptr = ptr1;
    } while (swapped);
}

int main() {
    int N, i, data;
    Node* head = NULL;

    // Input
    printf("Masukkan jumlah data (N): ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }

    // Output sebelum pengurutan
    printf("List sebelum pengurutan:\n");
    printList(head);

    // Pengurutan list
    sortList(&head);

    // Output setelah pengurutan
    printf("List setelah pengurutan:\n");
    printList(head);

    return 0;
}
