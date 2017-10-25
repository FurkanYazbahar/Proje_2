#include <time.h>
#include <stdio.h>
#include <string.h>

int satir_say(FILE* dosya){
    int satir=0;
    char c;
    while(feof(dosya)==NULL){
        c=getc(dosya);
        if(c=='\n')
            satir++;
    }
    return satir+1; // Dosya sonunda EOF olduğundan son satırı saymaz. O yüzden satir+1 yaptık.
}
struct ogrenci{
    char ad[15];
    char soyad[15];
    char k_sirasi[4];
    char num[8];
    char ogretim_tur[3];
 };
/*struct ogrenci al_dosyadan(struct ogrenci* kayit, int boy){
    struct ogrenci* olustur = (struct ogrenci*)malloc(boy*sizeof(struct ogrenci));

}*/
int main ()
{
    FILE * dosya;
    dosya = fopen("cccc.txt","r");
    char c;
    fseek(dosya,60,SEEK_SET);   // Dosyanın ikinci satırından başlamak için
    int satir = satir_say(dosya);
    printf("%d  tane kayit vardir. \n",satir);
    // struct ogrenci* kayit =(struct ogrenci*)malloc((satir+1)*sizeof(struct ogrenci));
    struct ogrenci ogr;
    int i=1;
    while(!feof(dosya)){
        fscanf(dosya,"%s%s%s%s%s",&ogr.num, &ogr.ad, &ogr.soyad,
                &ogr.k_sirasi, &ogr.ogretim_tur);
        printf("Birinci Kayit %d:\n%s\t%s\t%s\t%s\t%s",i+1, ogr.num, ogr.ad, ogr.soyad,
                ogr.k_sirasi, ogr.ogretim_tur);
        i++;
    }
    return 0;
}

