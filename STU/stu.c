#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STU.h"

int satir_say (FILE* dosya) {
  int satir = 1, c;
  while ((c = fgetc(dosya)) != EOF)
    if (c == '\n')
      satir++;
  return satir; 
}
// cursoru alt satırın başlandıcına indirir
void passline (FILE *file) {
  while (fgetc (file) != '\n');
}
// bir satırın eleman satısını döner
int chrinline (FILE *file) {
  int count = 0;
  while (fgetc (file) != '\n')
    count++;
  return count;
}

int main (int argc, char* argv[]) {
  FILE *dosya;
  dosya = fopen ("ogrenci.txt", "r");
  passline (dosya);
  
  STU *stu_1;
  get_stu (dosya, stu_1);

  stu_1 = fget_all_stu (dosya, NULL);

  int i = 0;
  for (i = 0; stu_1->next != NULL; i++, stu_1 = stu_1->next)
    puts_stu (stu_1);
  
  printf ("toplam ogrenci sayisi: %d\n", i);
  // stu_1'e bağlı bütün elemanları sil
  releaseTheHounds (stu_1);
  
  fclose (dosya);
  return 0;
}
