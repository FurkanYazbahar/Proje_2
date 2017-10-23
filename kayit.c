#include <time.h>
#include <stdio.h>

int satir_say(FILE* dosya){
    int satir=0;
    char c;
    while(feof(dosya)==NULL){
        c=getc(dosya);
        if(c=='\n')
            satir++;
    }
    return satir;
}
struct ogrenci{
    char numara[7];
    char ad[15];
    char soyad[15];
    int k_sirasi;
    char ogretim_tur[2];
 };
int main ()
{
    clock_t t;
    t = clock();
    FILE * dosya;
    dosya = fopen("cccc.txt","r");
    fseek(dosya,44,SEEK_SET);
    printf("satir sayisi : %d",satir_say(dosya));
    /*do
    {
        c = getc(dosya);    // Bir karakter oku
        putchar(c);         // ekranda goster
    }while (c != EOF);*/
    t = clock() - t;
    printf("\n %f ", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}
