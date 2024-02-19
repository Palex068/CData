// #include <stdio.h>

// int main() {
//   FILE* fin =
//       fopen("data.txt", "r");  // открыть файл data.txt на чтение - поток fin
//   FILE* fout =
//       fopen("out.txt", "w");  // открыть файл out.txt на запись - поток fout

//   int n;
//   fscanf(fin, "%d", &n);  // читаем количество чисел из потока fin

//   int i, sum;
//   for (sum = 0, i = 0; i < n; i++) {
//     int x;
//     fscanf(fin, "%d", &x);  // читаем очередное число из потока fin
//     sum += x;
//     printf("i=%d x=%d sum=%d\n", i, x,
//            sum);  // отладочная печать в поток stdout
//   }

//   fprintf(fout, "%d\n", sum);  // результат пишем в поток fout

//   fclose(fin);  // закрываем открытые нами потоки
//   fclose(fout);

//   return 0;
// }

// #include <stdio.h>

// #define N 100
// typedef struct {
//   char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
//   unsigned int n;  // наибольшая степень десяти
// } Decimal;

// void elong_set(Decimal* res, const char str[]) {
//   int n = 0;
//   for (unsigned int i = 0; str[i] != '\0'; i++, n++)
//     ;
//   res->n = n - 1;
//   for (int i = 0; i < n; i++) {
//     res->a[i] = str[n - i - 1] - '0';
//   }
// }

// void elong_print(Decimal x) {
//   for (unsigned int i = 0; i <= x.n; i++) {
//     printf("%d", x.a[x.n - i]);
//   }
// }

// int main() {
//   Decimal res;
//   elong_set(&res, "12345678901234567890");  // res = 12345678901234567890

//   elong_print(res);  // print 12345678901234567890

//   return 0;
// }

// #include <check.h>
// #include <stdio.h>
// #include <string.h>

// int main() {
//   int x = 0, y = 0;
//   char s[10];

//   while (1) {
//     scanf("%9s", s);
//     if (0 != strcmp(s, "Treasure!")) {
//       int step;
//       scanf("%d", &step);
//       switch (s[0]) {
//         case 'N':
//           y += step;
//           break;
//         case 'S':
//           y -= step;
//           break;
//         case 'E':
//           x += step;
//           break;
//         case 'W':
//           x -= step;
//           break;
//         default:
//           break;
//       }
//     } else
//       break;
//   }
//   printf("%d %d", x, y);
// }

// #include <ctype.h>  // для функции tolower
// #include <stdio.h>

// int main() {
//   char str1[] = "";
//   char str2[] = "";
//   const char* str = trim(&str1, &str2);
//   printf("%s", str);
//   return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int my_strsrt(char s[], int len, const char word[], int word_len) {
//   int total = 0;
//   if (len > word_len) {
//     for (int i = 0; i < len - word_len + 1; i++) {
//       int result = 0;
//       for (int j = 0; j < word_len; j++) {
//         if (s[i + j] == word[j]) {
//           result++;
//         } else
//           break;
//         if (result == word_len - 1) total++;
//       }
//     }
//   }
//   //  if (total) printf("%s %d\n", s, total);
//   return total;
// }

// int main() {
//   const char word[] = "bomb";
//   int word_len = strlen(word);
//   char s[21];
//   int answer = 0;
//   while (1 == scanf("%20s", s)) {
//     int len = strlen(s);
//     answer += my_strsrt(s, len, word, word_len);
//   }
//   printf("%d", answer);
// }

#include <math.h>
#include <stdio.h>
#include <string.h>

double s21_ceil(double x) {
  return ((long)x == x || x <= 0) ? (long)x : (long)x + 1;
}

double s21_ceil_old(double x) {
  long floor_x = (long)x;
  if (x > 0) {
    return floor_x + 1;
  } else {
    return floor_x;
  }
}

int main() {
  for (double i = -3; i <= 3; i += 0.25) {
    if (ceil(i) != s21_ceil_old(i) || ceil(i) != s21_ceil(i)) {
      printf("%.2lf new: %.2lf old: %.2lf TRUE: %.2lf \n", i, s21_ceil(i),
             s21_ceil_old(i), ceil(i));
    }
  }
  return 0;
}