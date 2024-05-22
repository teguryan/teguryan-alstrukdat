#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[50];
    int duration; 
} Pengunjung;

typedef struct {
    Pengunjung data[MAX];
    int head;
    int tail;
    int capacity; 
    int size; 
} Queue;

void init(Queue *queue, int capacity) {
    queue->head = -1;
    queue->tail = -1;
    queue->capacity = capacity;
    queue->size = 0;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

bool isFull(Queue *queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, Pengunjung newPengunjung) {
    if (!isFull(queue)) {
        if (isEmpty(queue)) {
            queue->head = 0;
        }
        queue->tail = (queue->tail + 1) % MAX;
        queue->data[queue->tail] = newPengunjung;
        queue->size++;
        printf("%s masuk ke dalam antrian.\n", newPengunjung.name);
    } else {
        printf("Rumah makan penuh!\n");
    }
}

void dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        printf("%s keluar dari rumah makan.\n", queue->data[queue->head].name);
        if (queue->head == queue->tail) {
            queue->head = -1;
            queue->tail = -1;
        } else {
            queue->head = (queue->head + 1) % MAX;
        }
        queue->size--;
    } else {
        printf("Rumah makan kosong!\n");
    }
}

void printQueue(Queue *queue) {
    if (!isEmpty(queue)) {
        printf("Daftar pengunjung rumah makan:\n");
        int i = queue->head;
        int count = 0;
        do {
            printf("Nama: %s, Waktu tinggal: %d menit\n", queue->data[i].name, queue->data[i].duration);
            i = (i + 1) % MAX;
            count++;
        } while (i != (queue->tail + 1) % MAX && count < queue->size);
    } else {
        printf("Rumah makan kosong!\n");
    }
}

int main() {
    Queue queue;
    init(&queue, MAX);

    int option;
    
    while(1) {
        printf("\nMenu:\n");
        printf("1. Masukkan pengunjung ke dalam rumah makan\n");
        printf("2. Keluarkan pengunjung dari rumah makan\n");
        printf("3. Tampilkan daftar pengunjung\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                Pengunjung newPengunjung;
                printf("Masukkan nama pengunjung: ");
                scanf("%s", newPengunjung.name);
                printf("Masukkan waktu tinggal (dalam menit): ");
                scanf("%d", &newPengunjung.duration);
                enqueue(&queue, newPengunjung);
                break;
            }
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Program selesai.\n");
                exit(0);
            default:
                printf("Menu tidak valid!\n");
                break;
        }
    }

    return 0;
}
