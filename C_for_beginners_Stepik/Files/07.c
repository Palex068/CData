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

#include <stdio.h>
#include <math.h>

int main() {
    int num, k, result = 1;
    scanf("%d %d", &num, &k);
	
    while (num > pow(2, k)) {
	    A:
	    for (int i = 2; i < 10; i++) {
		    int del = (int)pow(i, k);
		    if (num % del == 0) {
			    num /= del;
			    printf("%d %d\n", i, num);
			    result *=i;
			    goto A;				
			}
        }
        break;
    }
    printf("%d", num != 1 ? -1 : result);
    return 0;
}


