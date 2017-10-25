#include <stdio.h>
#include <time.h>
#include <string.h>
// ön tanımlayıcıları şimdilik es geç
#define STU struct ogrenci

int satir_say(FILE* dosya)
{
  int satir=0;
  char c;
  while(!feof(dosya))
  {
    c=getc(dosya);
    if(c=='\n')
      satir++;
  }
  // Dosya sonunda EOF olduğundan son satırı saymaz. O yüzden satir+1 yaptık.
  return satir+1; 
}
// bir satırın eleman satısını döner
// cursoru alt satıra geçirmek için kullandık
int chrinline(FILE* file)
{
  int chr_count = 0;
  while(fgetc(file) != '\n')
    chr_count++;
  return chr_count;
}
struct ogrenci
{
    char ad[30];
    char soyad[30];
    int  k_sirasi;
    char num[8];
    char ogretim_tur[2];
};
int main () {
  FILE *dosya, *file;
  dosya = fopen("ogrenci.txt","r");
  file = fopen("re-writen.txt","w");
  printf("%d\n", chrinline(dosya));
  // WTF!
  // fseek(dosya,60,SEEK_SET);   // Dosyanın ikinci satırından başlamak için
  STU ogr;
  
  printf("furkan\n");
  while(!feof(dosya))
  {
    fscanf(dosya,"%s\t%s\t%s\t%d\t%s\n",ogr.num, ogr.ad, ogr.soyad,
      &ogr.k_sirasi, ogr.ogretim_tur);
    fprintf(file, "%s\t\t%s\t\t%s\t\t%d\t\t%s\n",ogr.num, ogr.ad, ogr.soyad,
      ogr.k_sirasi, ogr.ogretim_tur);
  }
  fclose(dosya);
  fclose(file);
  return 0;
}
