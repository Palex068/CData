// #include <conio.h>

// #include <stdio.h>

// int main() {
//   // put your code here
//   printf("Wake up, Neo...\n\nThe Matrix has you...\n\nFollow the white rabbit...\n");
//   return 0;
// }

// #include <stdio.h>

// int main() {
//   // put your code here
//   printf("NICKNAME: Neo\nCITY: St-Petersburg\nAGE: 35\nHEIGHT: 180\nWEIGHT: 75\n");
//   return 0;
// }

// #include <stdio.h>

// int main() {
//   // put your code here
//     printf("NICKNAME: %s\n", "Neo");
//     printf("CITY: %s\n", "St-Petersburg");
//     printf("AGE: %d\n", 35);
//     printf("HEIGHT: %d\n", 180);
//     printf("WEIGHT: %d", 75);
//   return 0;
// }

// #define US "\
// NICKNAME: Neo\n\
// CITY: St-Petersburg\n\
// AGE: 35\n\
// HEIGHT: 180\n\
// WEIGHT: 75\n"

// #include <stdio.h>

// int main(){
//  printf(US);
//  return 0;
// }

// #include <stdio.h>

// int main(){
//     printf("_________________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("********_________________________________________\n");
//     printf("_________________________________________________\n");
//     printf("_________________________________________________\n");
//     printf("_________________________________________________\n");
//     printf("_________________________________________________\n");
//     printf("_________________________________________________\n");
//     printf("_________________________________________________\n");
//  return 0;
// }

#include <stdio.h>

int main() {
    for(int i = 0; i < 13; i++) {
        if (i > 0 && i < 7) {
            printf("********_________________________________________");
        } else {
            printf("_________________________________________________");
        }
        printf("\n");
    }
    return 0;
}