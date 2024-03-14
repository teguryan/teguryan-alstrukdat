#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (int *n){
    printf("The length of your text is less than specified, please update your text\n");
    *n = MIN_LENGTH;
}

void equalThanRequired (int *n){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (int *n){
    printf("Your text is to long, please reduce the text\n");
    *n = MAX_LENGTH;
}

int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    lengthOfText = strlen(text);
    printf("Leght before : %d\n",lengthOfText);

    selectOption = checkLenghtRequirement(text);
    void (*fun_ptr_arr[])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
    (*fun_ptr_arr[selectOption])(&lengthOfText);
    printf("The Lenght is updated to %d", lengthOfText);

    return 0;
}