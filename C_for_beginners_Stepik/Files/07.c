// #include <stdio.h>

// int main()
// {
// 	int price, delta, money;

//     // читаем входные данные (что дано)
// 	scanf("%d%d%d", &price, &delta, &money);

// 	int result = 0; // счетчик дней

// 	while (price > money) {
// 		money -= price;	// купили рис
// 		result++;			// посчитали день
//         if (result % 7 == 0) {
// 		    price += delta;
//         }
// 	}
// 	// робот закончил шаги, больше никуда не идем, печатаем ответ
// 	printf("%d", result);

// 	return 0;
// }

// #include <stdio.h>

// int main() {
//     int a, b, a_, b_;
//     scanf("%d %d", &a, &b);
//     a_ = a;
//     b_ = b;

//     // Euclid algoritm

//     while (b != 0) {
//         int tmp = a % b;
//         a = b;
//         b = tmp;
//     }

//     printf("GCD(%d, %d) = %d\n", a_, b_, a);
// }

// #include <stdio.h>

// int main() {
//     int a, b, ost;

//     // читаем входные данные (что дано)
//     scanf("%d%d", &a, &b);

//     do {
//         ost = a % b;  // считаем остаток
//                       // отладочная печать - все переменные цикла
//         printf("a=%d b=%d ost=%d\n", a, b, ost);
//         // готовимся к следующей итерации цикла
//         a = b;
//         b = ost;
//     } while (ost != 0);

//     // подумайте, какую переменную мы должны печатать вместо ???
//     printf("НОД = %d\n", a);

//     return 0;
// }

// #include <stdio.h>

// int main() {
//   int n, result = 1;
//   scanf("%d", &n);

//   while (n > 0) {
//     result *= n--;
//   }
//   printf("%d", result);
//   return 0;
// }

// #include <stdio.h>

// int main() {
//   int n, min;
//   scanf("%d %d", &n, &min);

// 	for (int i = 1; i < n; i++) {
// 		int x;
// 		scanf("%d", &x);
// 		if (x < min) {
// 			min = x;
// 		}
// 	}
// 	printf("%d", min);
//   return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int main() {
//     int num, k, result = 1;
//     scanf("%d %d", &num, &k);

//     while (num > pow(2, k)) {
// 	    A:
// 	    for (int i = 2; i < 10; i++) {
// 		    int del = (int)pow(i, k);
// 		    if (num % del == 0) {
// 			    num /= del;
// 			    printf("%d %d\n", i, num);
// 			    result *=i;
// 			    goto A;
// 			}
//         }
//         break;
//     }
//     printf("%d", num != 1 ? -1 : result);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int main() {
//     int d, k, result = 0, num;
//     scanf("%d %d", &d, &k);
// 	num = k;
//     while (num > 0) {
// 	    if (num % 10 == d) {
// 			result++;
// 		}
// 		num /=10;
//     }
//     printf("%d %d %d", d, k, result);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 1001

// int main() {
//   char d;
//   int result = 0;
//   scanf("%c", &d);
//   printf("%c ", d);
//   char number[MAX];
//   scanf("%1000s", number);
//   printf("%s", number);
//   int len = strlen(number);
//   for (int i = 0; i < len; i++) {
//     if (number[i] == d) {
//       result++;
//     }
//   }
//   printf(" %d", result);
//   return 0;
// }

// #include <ctype.h>
// #include <stdio.h>

// int main() {
//   char d, x;  // d - эталонный символ, x - очередной ОДИН символ
//   scanf("%c ", &d);
//   printf("%c ", d);

//   int n = 0;
//   int res;
//   while (1) {
//     res = scanf("%c", &x);
//     if (res != 1 || !isdigit(x))  // не прочитали или прочитали не цифру
//       break;
//     printf("%c", x);
//     if (d == x) n++;
//     // printf("n=%d d=%с=%d x=%c=%d\n", n, d, d, x, x);
//   };

//   printf(" %d\n", n);

//   return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 100

// int main() {
//   int result = 0;
//   char number[MAX];
//   scanf("%99s", number);
//   int len = strlen(number);

//   for (int i = 0; i < len; i++) {
//     if (result < 0) {
//       break;
//     } else if (number[i] == '(') {
//       result++;
//     } else if (number[i] == ')') {
//       result--;
//     }
//   }
//   printf("%s", result ? "NO" : "YES");
//   return 0;
// }


#include <stdio.h>

int main(){
    int b[10] = {0};
    int n, result = 0;
    scanf("%d", &n);
	int * a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    for(int i = 0; i < 10; i++) {
        printf("%d %d\n", i, b[i]);
    }
    return 0;
}