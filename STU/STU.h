#define STU_BUFF 30
typedef struct stu STU;

struct stu {
  char   num[8];
  char   name[STU_BUFF];
  char   surname[STU_BUFF];
  int    seq;        // sequence
  char   kind[3];    // kind of edu.
  struct stu *next;  // next element
  struct stu *pre;   // previous element
};

// res'in içeriğini ori'ye kopyalar
void stu_copy (STU *ori, STU *res) {
  strcpy (ori->num, res->num);
  strcpy (ori->name, res->name);
  strcpy (ori->surname, res->surname);
  strcpy (ori->kind, res->kind);
  ori->next = res->next;
  ori->pre = res->pre;
  ori->seq = res->seq;
} 
// change s1 content with s2
void stu_content_swap (STU *s1, STU *s2) {
  STU swap;
  stu_copy (&swap, s1);
  stu_copy (s1, s2);
  stu_copy (s2, &swap);
}
// s1 ve s2 değerlerini değiştir
void stu_swap (STU **s1, STU **s2) {
  STU *temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}
// mallocla alınan belleği geri verir
//also
// void dell_stu (STU **stu) { 
void releaseTheHound (STU **hound){
  free (*hound);
}
// verilen elemana bağlı bütün elemanları serbest bırakır
// void dell_stus (STU **stu) {
void releaseTheHounds (STU *hound) {
  STU *phound,*nhound, *snoppy;
  if (hound != NULL) { // hound'un NULL olma ihtimaline karşı
    phound = hound->pre;
    nhound = hound->next;
    releaseTheHound (&hound);
  }
  // pre'ye ağlı bütün elemanları siler
  while (phound != NULL) {
    snoppy = phound->pre;
    releaseTheHound (&phound);
    phound = snoppy;
  }
  // nexte bağlı bütün elemanları sil
  while (nhound != NULL) {
    snoppy = nhound->next;
    releaseTheHound (&nhound);
    nhound = snoppy;
  }
}
// verilen akıştan stu formatında ve sırasında satır çeker
void get_stu (FILE *stream, STU *stu) {
  if (stu == NULL)
    fprintf (stderr, "Warning: Call the manager! There is no Student\n");
  else if (stream == NULL)
    fprintf(stderr, "Warning: Where is stream?\n");
  else
    fscanf (stream, "%s\t%s\t%s\t%d\t%s\n", stu->num, stu->name,
      stu->surname, &(stu->seq), stu->kind);
}
// STU'yu ekrana basar
void puts_stu (const STU *const stu) {
  if (stu == NULL)
    fprintf (stderr, "Warning: This student don't have head!\n");
  else
    printf ("%s\t%s\t%s\t%d\t%s\n", stu->num, stu->name,
      stu->surname, stu->seq, stu->kind);
}
// STU'yu verilen akışa basar
void fputs_stu (FILE* stream, STU *stu) {
  if (stu == NULL)
    fprintf (stderr, "Warning: Dead student!\n");
  else
    fprintf (stream, "%s\t%s\t%s\t%d\t%s\n", stu->num, stu->name,
      stu->surname, stu->seq, stu->kind);
}
// ori'nin next elemanına, parametre next'in değerini verir
void link_next (STU *ori, STU *next){
  if(next == NULL || ori == NULL)
    fprintf(stderr, "Warning: There is no original or next value!");
  else
    ori->next = next;
};
// ori'nin pre elemanına, parametre pre'in değerini verir
void link_pre (STU *ori, STU *pre){
  if(pre == NULL || ori == NULL)
    fprintf(stderr, "Warning: There is no original or previus value!");
  else
    ori->pre = pre;
};
// ori'nin pre ve next elemanlarını atar
void link (STU *ori, STU *pre, STU *next){
  link_next (ori, next);
  link_pre (ori, pre);
};
// stu için bellekten yer ayırır 
// ve verilen alkıştan stuya uygun satır çeker ve parçalar
void add_stu (FILE *stream, STU **stu){
  *stu = (STU*) malloc (sizeof(STU));
  get_stu (stream, *stu);
}
//config
auto dell_stu = releaseTheHound;
auto dell_stus = releaseTheHounds;