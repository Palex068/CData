// #include <stdio.h>
// int main(void){
//   int a=7, b=2;
//   float res;

//   res = a/b;
//   printf("%d / %d = %f\n",a,b,res);

//   return 0;
// }

// #include <stdio.h>
// int main(void){
//   int a=7, b=2;
//   float res;

//   res = (float)a/b;
//   printf("%d / %d = %f\n",a,b,res);

//   return 0;
// }

// #include <stdio.h>

// int main() {
//   int a, b;
//   scanf("%d", &a);
//   scanf("%d", &b);

//   printf("%d", a * b * 2);
//   return 0;
// }

// #include <stdio.h>

// int main() {
//   int a, res = 0;
//     scanf("%d", &a);
//     while(a > 0) {
//         res += a % 10;
//         a = a / 10;
//     }
//     printf("%d\n", res);
//     getch();
//   return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int main() {
//     int a, b;
//     double c;
//         scanf("%d", &a);
//         scanf("%d", &b);
//         scanf("%lf", &c);
//         printf("%.02lf\n", c * (double)(b-a));
//         getch();
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int main() {
//     int A;
//     double pi = 3.1415926;
//         scanf("%d", &A);
//         printf("%.02lf\n", pi * (double)(A) / 180);
//         getch();
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int main() {
//     int A;
//         scanf("%d", &A);
//         printf("%d\n", A % 2);
//         getch();
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int main() {
//     int A;
//         scanf("%d", &A);
//         printf("%d\n", (A + 1) % 2);
//         getch();
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h
// int main (void) {
//   int a, b, c2;

//   scanf("%d",&a);
//   scanf("%d",&b);
	
//   c2 =  a*a + b*b;
//   printf("c = %.2f\n", sqrt(c2)); 
//   getch();  
//   return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h

// int main (void) {
//     int x = 0.14;
//     float y = 0;
//     x = 3.14/2;
//     y = x + 3.14;
//     printf("%.2f\n", y); 
//     getch();  
//     return 0;
// }
// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h

// int main (void) {
//     int x, y, res;
//     scanf("%d", &x);
//     scanf("%d", &y);
//     res = fabs(x - y);
//     printf("%d\n", res); 
//     getch();  
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h

// int main (void) {
//     double x_1, y_1, x_2, y_2, res;
//     scanf("%lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2);
//     res = sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
//     printf("%.2lf\n", res); 
//     getch();  
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h

// int main (void) {
//     const double pi = 3.141593;
//     double a, b, alpha, res;
//     scanf("%lf %lf %lf", &a, &b, &alpha);
//     alpha = alpha * pi / 180;
//     res = a * b * sin(alpha) / 2;
//     printf("%.2lf\n", res); 
//     getch();  
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h>   // подключаем math.h
// #include <stdlib.h> // чтобы использовать функцию rand()
// #include <time.h>   // чтобы использовать функцию time()

// int main (void) {
//     srand(time(NULL));
//     printf("%d\n", 80 + rand()%(100 - 80 + 1));
//     printf("%d\n", 80 + rand()%(100 - 79));
//     printf("%d\n", 80 + rand()%21);
//     printf("%d\n", 80 + rand()%21);
//     printf("%d\n", 80 + rand()%21);
    
//     getch();
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>
// #include <math.h> // подключаем math.h

// int main (void) {
//     double a, b, c, d, e, f, h, res;
//     scanf("%lf %lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f, &h);
//     // res = a / (b * (c / (d * (e / (f * h)))));
//     res = (a * d * e)/(b * c * f * h);
//     printf("%.2lf\n", res); 
//     getch();  
//     return 0;
// }
