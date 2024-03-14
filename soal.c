#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (int *n){
    printf("The length of your text is less than specified, please update your text\n");
    *n = MAX_LENGTH;
}

void equalThanRequired (int *n){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (int *n){
    printf("Your text is to long, please reduce the text\n");
    *n = MIN_LENGTH;
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
    int blengthOfText, lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");
    
    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLenghtRequirement(text);
    void (*fun_ptr_arr[])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
    (*fun_ptr_arr[selectOption])(&lengthOfText);
    blengthOfText = strlen(text);
    printf("Leght before : %d\n",blengthOfText);
    printf("The Lenght is updated to %d", lengthOfText-1);

    return 0;
}

// sebelum program berjalan, deklrasi terlebih dahulu panjang dan max,yaitu 1945 dan 2024
// program berjalan dengan mendeklarasikan variable blenghtOfTextlenghtOfText dan selectOption terlebih dahulu
// lalu FILE *fptr = NULL untuk deklarasi sebuah file yang akan dipanggil nantinya dengan nilai null agar nilai variable fptr NULL
// lanjut dengan deklarasi sebuah variable text dengan panjang maxlength, program disini telah mendeklarasikan panjang (beserta nilai) max dan min diawal code dengan #define
// lalu step berikutnya membuka file dengan code atau syntax fptr = fopen("nama file","r") r disini untuk read jadi diperuntukan untuk dibaca saja
// pengondisian jika fptr null maka akan program akan keluar dan mengirim pesan "Error"
// fgets disni untuk mengambil nilai dari file text, dengan panjang maxlenght lalu fptr untuk tujuannya
// lalu fclose untuk menutup file
// selectOption disini untuk menampung function check
// void funptrarr(function pointer array) untuk menyimpan function2 pengecekan yang telah di buat diatas program main
// lalu variable fun_ptr_arr tadi akan melakukan pengecekan melalui selectOption dengan panjang text yang didalam file lalu dicetak apakah nilai masuk kedalam function less/equal/more
// nantinya program akan mengeluarkan hasil sesuai function yang terpilih
// setelah itu blengOfText berbeda dengan lenghtOfText,disini b(before) ntuk menginput berapa banyak character yang ada didalam file, kalau lenghtOfText untuk mencetak apakah kondisi kurang dari 1945, atau malah kelebihan dari 2024 atau masuk diantaranya
// lalu diprintkan hasil nya melalui output printf, lengOfText -1 karena hasil yang diminta 2023 bukan 2024 maka perlu dikurang 1
