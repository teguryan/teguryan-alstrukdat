#include <stdio.h>
typedef struct Kalender
{
    int day;
    int month;
    int year;
}kalender;

void cekKabisat(kalender kalender){
    int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //iniasi untuk jumlah hari per bulannya = total 12 bulan
    if((kalender.year % 400 == 0) || ((kalender.year % 4 == 0) && (kalender.year % 100 != 0))){ //pengecekan kabisat di februari
        dayInMonth[1] = 29; //jika kabisat maka index 1 yaitu februari (28) berubah menjadi 29
    }

    kalender.day++; //tambah satu hari

    if (kalender.day > dayInMonth[kalender.month - 1]) { //cek apakah melewati jumlah hari bulan ini, 
    //-1 karena di array berawal dari 0 sedangkan dayInMonth index 0 bulan pertama
        kalender.day = 1; //setting atau reset hari ke angka 1 
        kalender.month++; //dan tambah satu ke bulan

        if (kalender.month > 12) { //jika bulan melewati angka 12 maka,
            kalender.month = 1; // setting atau reset bulan ke angka 1
            kalender.year++; //dan tambah satu ke tahun
        }
    }

    printf("%d %d %d",kalender.day, kalender.month, kalender.year); //cetak tanggal yang telah diubah
}

int main(){
    kalender kalender;
    scanf("%d %d %d", &kalender.day, &kalender.month, &kalender.year); //menginput nilai tanggal, pakai & karena menginput 
    cekKabisat(kalender); //memanggil prosedur cekkabisat

    return 0;
}
//maaf kak pas bikin video malah lupa penjelasan code,saya tulis penjelasan di code ya kak.
//yt : https://youtu.be/OtwVZSSVOtQ