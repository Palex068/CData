#include <stdio.h>

int main() {
  FILE* fin =
      fopen("data.txt", "r");  // открыть файл data.txt на чтение - поток fin
  FILE* fout =
      fopen("out.txt", "w");  // открыть файл out.txt на запись - поток fout

  int n;
  fscanf(fin, "%d", &n);  // читаем количество чисел из потока fin

  int i, sum;
  for (sum = 0, i = 0; i < n; i++) {
    int x;
    fscanf(fin, "%d", &x);  // читаем очередное число из потока fin
    sum += x;
    printf("i=%d x=%d sum=%d\n", i, x,
           sum);  // отладочная печать в поток stdout
  }

  fprintf(fout, "%d\n", sum);  // результат пишем в поток fout

  fclose(fin);  // закрываем открытые нами потоки
  fclose(fout);

  return 0;
}