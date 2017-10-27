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
  dosya = fopen ("ogrenci.txt","r");

  passline (dosya);

  STU *stu_1, *stu_2, *stu_3;
  //elemanları çek ve yükle
  add_stu (dosya, &stu_1);
  add_stu (dosya, &stu_2);
  add_stu (dosya, &stu_3);

  // öğrenci içerikleri
  puts_stu (stu_1);
  puts_stu (stu_2);
  puts_stu (stu_3);

  // stu1'e 2 ve 3 ü bağla
  link (stu_1, stu_2, stu_3);
  
  // stu_1'e bağlı bütün elemanları sil
  dell_stus (stu_1);

  fclose(dosya);
  return 0;
}
