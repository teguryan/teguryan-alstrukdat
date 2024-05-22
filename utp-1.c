#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char *data[MAX];
    int head;
    int tail;
} Queue;

void init(Queue *queue){
    queue->head = -1;
    queue->tail = -1;
}

bool isEmpty(Queue *queue){
    return queue->head == -1 && queue->tail == -1;
}

bool isFull(Queue *queue){
    return queue->tail == MAX - 1;
}

int size(Queue *queue){
    return queue->tail + 1;
}

char* head(Queue *queue){ 
    return !isEmpty(queue) ? queue->data[queue->head] : NULL; 
}

void enqueue(Queue *queue, char *newValue){ 
    if(!isFull(queue)){
        if(isEmpty(queue)){
            queue->head++;
            queue->data[++queue->tail] = (char *)malloc(strlen(newValue) + 1); //malloc disini berfungsi untuk alokasi memori data baru
            strcpy(queue->data[queue->tail], newValue); 
            return;
        }
        queue->data[++queue->tail] = (char *)malloc(strlen(newValue) + 1); 
        strcpy(queue->data[queue->tail], newValue); 
        return;
    }
    printf("Antrian penuh!\n");
}

void dequeue(Queue *queue){
    if(!isEmpty(queue)){
        if(queue->head == 0 && queue->tail == 0){
            free(queue->data[queue->head]); 
            queue->head--;
            queue->tail--;
            return;
        }
        free(queue->data[queue->head]); 
        for(int i = queue->head + 1; i < queue->tail + 1; i++){
            queue->data[i - 1] = queue->data[i];
        }
        queue->tail--;
        return;
    }
    printf("Antrian kosong!\n");
}

void printQueue(Queue *queue){
    if(!isEmpty(queue)){
        for(int i = queue->head; i < queue->tail + 1; i++){
            printf("%s ", queue->data[i]); 
        }
        return;
    }
    printf("Antrian kosong!");
}

int main(){
    Queue queue;
    init(&queue);

    int option;
    
    while(1){
        printf("---------------------------------------------------------------\n");
        printf("Antrian Konsumen: ");
        printQueue(&queue);
        printf("\t|\tHead: %s", head(&queue)); 
        printf("\t|\tSize: %d\n", size(&queue));
        printf("---------------------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("---------------------------------------------------------------\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        if(option == 1){
            char value[100]; 
            printf("Masukkan nilai baru: ");
            scanf("%s", value);
            enqueue(&queue, value);
        }else if(option == 2){
            dequeue(&queue);
        }else if(option == 3){
            break;
        }
        else{
            printf("Opsi tidak valid!\n");
        }
        system("cls");
    }
    return 0;
}
