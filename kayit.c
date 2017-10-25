#include <stdio.h>
#include <time.h>
#include <string.h>

// ön tanımlayıcı yerine tür olarak tanımladık
typedef struct ogrenci
{
  char num[8];
  char ad[30];
  char soyad[30];
  int  sira;
  char tur[3];
  struct ogrenci* next;
} STU;

int satir_say (FILE* dosya) {
  int satir=1;
  char c;
  while (!feof(dosya)) {
    c = getc(dosya);
    if (c == '\n')
      satir++;
  }
  return satir; 
}
// cursoru alt satırın başlandıcına indirir
void passline (FILE* file) {
  while (fgetc (file) != '\n');
}
// bir satırın eleman satısını döner
// cursoru alt satıra geçirmek için kullandık
int chrinline (FILE* file) {
  int chr_count = 0;
  while (fgetc (file) != '\n')
    chr_count++;
  return chr_count;
}
// copy result into original
void stu_copy (STU* ori, STU* res) {
  strcpy (ori->num, res->num);
  strcpy (ori->ad, res->ad);
  strcpy (ori->soyad, res->soyad);
  strcpy (ori->tur, res->tur);
  ori->next = res->next;
  ori->sira = res->sira;
} 
// change s1 content with s2
void stu_swap (STU* s1, STU* s2) {
  STU swap;
  stu_copy (&swap, s1);
  stu_copy (s1, s2);
  stu_copy (s2, &swap);
}

int main (int argc, char* argv[]) {
  FILE *dosya, *file;
  dosya = fopen ("ogrenci.txt","r");
  file = fopen ("re-writen.txt","w");// read and write result test

// swap example
  STU furkan = {"123456", "furkan", "yazbahar", 123, "I"};
  STU yasir = {"123457", "yasir", "kiroglu", 10, "II", &furkan};
  
  stu_swap (&furkan, &yasir);
  
  printf ("Furkan nesnesi:\n %s\t%s\t", furkan.num, furkan.ad);
  printf ("%s\t%d\t", furkan.soyad, furkan.sira);
  printf ("%s\t\n", furkan.tur);
  printf ("Yasir nesnesi:\n %s\t%s\t", yasir.num, yasir.ad);
  printf ("%s\t%d\t", yasir.soyad, yasir.sira);
  printf ("%s\n", yasir.tur);
  printf ("sonuc:%s", (yasir.next)->num);

  printf ("%s\n%s\n", furkan.num, yasir.num );
// end of swap example

  STU ogr;
  int satir = satir_say(dosya);
  rewind (dosya);
  printf ("eleman sayısı%d\nsatiir sayisi: %d\n", chrinline(dosya), satir);

  while (!feof(dosya)) {
    fscanf (dosya, "%s\t%s\t%s\t%d\t%s\n" ,ogr.num, ogr.ad, ogr.soyad,
      &ogr.sira, ogr.tur);
    fprintf (file, "%s\t%s\t%s\t%d\t%s\n" ,ogr.num, ogr.ad, ogr.soyad,
      ogr.sira, ogr.tur);
  }
  fclose(dosya);
  fclose(file);
  return 0;
}
