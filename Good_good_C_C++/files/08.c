// #include <stdio.h>

// int main(void) {
//     char str[] = "Function fputc() in action.";

//     FILE* fp = fopen("my_file.txt", "w");
//     if (fp == NULL) return 1;

//     for (int i = 0; str[i]; ++i) fputc(str[i], fp);

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char str[] = "Function fputc() in action.";
//     char buff[100];

//     FILE* fp = fopen("my_file.txt", "w");
//     if (fp == NULL) return 1;

//     for (int i = 0; str[i]; ++i) fputc(str[i], fp);

//     fclose(fp);

//     FILE* in = fopen("my_file.txt", "r");
//     if (in == NULL) {
//         puts("File open error");
//         return 2;
//     }

//     char ch;
//     int i = 0;
//     while ((ch = fgetc(in)) != EOF) buff[i++] = ch;
//     buff[i] = '\0';
//     puts(buff);

//     fclose(in);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     FILE* fp = fopen("test.dat", "r");
//     if (fp == NULL) return 2;

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     FILE* fp = fopen("test_file.txt", "r");
//     if (fp == NULL) return 1;

//     int data;
//     while ((data = fgetc(fp)) != EOF) printf("%c", data);

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     FILE* fp = fopen("test_file.txt", "w");
//     if (fp == NULL) return 1;

//     int data[] = {1, 2, 3, 0, -1, -100};
//     for (size_t i = 0; i < sizeof(data) / sizeof(*data); ++i) {
//         fputc(data[i], fp);
//     }

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     FILE* fp = fopen("test_file.txt", "r");
//     if (fp == NULL) return 1;

//     char byte;
//     char buff[100];
//     int i = 0;

//     while ((byte = fgetc(fp)) != EOF) buff[i++] = byte;
//     buff[i] = '\0';
//     puts(buff);

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     FILE* fp = fopen("test_file.txt", "a");
//     if (fp == NULL) return 1;

//     char byte = 'B';

//     fputc(byte, fp);

//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char byte;
//     FILE* fp = stdin;  // стандартный поток для чтения данных

//     while ((byte = fgetc(fp)) != EOF) {
//         printf("%d: %d ", (int)byte, (int)ftell(fp));
//     }
//     fseek(fp, 1, SEEK_SET);
//     // fclose(fp); для стандартного потока делать не нужно

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     const char* str[] = {"- Скажи-ка, дядя, ведь не даром", "Я Python, Си учил с каналом",
//                          "Балакирев что раздавал?"};

//     FILE* fp = fopen("my_file.txt", "w");
//     if (fp == NULL) {
//         perror("my_file.txt");
//         return 1;
//     }

//     for (size_t i = 0; i < sizeof(str) / sizeof(*str); ++i) {
//         fputs(str[i], fp);
//         fputc('\n', fp);
//     }

//     fclose(fp);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char buffer[100];

//     FILE* fp = fopen("my_file.txt", "r");
//     if (fp == NULL) {
//         perror("my_file.txt");
//         return 1;
//     }

//     while (fgets(buffer, sizeof(buffer), fp)) puts(buffer);

//     fclose(fp);
//     return 0;
// }

// #include <stdio.h>

// enum { max_length = 1024 };

// int main(void) {
//     double rub_usd[max_length] = {0.0};
//     unsigned length = 0;

//     FILE* fp = fopen("data_rubusd.csv", "r");
//     if (fp == NULL) {
//         perror("data_rubusd.csv");
//         return 1;
//     }

//     while (fscanf(fp, "%lf ; ", &rub_usd[length]) == 1) length++;

//     fclose(fp);

//     for (unsigned int i = 0; i < length; ++i) printf("%.3f ", rub_usd[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char buff[512];

//     FILE* fp = fopen("test_file.txt", "r");
//     if (fp == NULL) return 1;

//     if (fgets(buff, sizeof(buff), fp) == NULL) {
//         fclose(fp);
//         return 2;
//     }
//     fclose(fp);

//     fp = fopen("test_file.txt", "w");
//     if (fp == NULL) return 3;

//     fputs(strcat(buff, "Hello C!"), fp);
//     fclose(fp);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// enum { max_length = 512 };

// int main(void) {
//     char buff[max_length];

//     FILE* fp = stdin;  // имитация отрытого файлового входного потока

//     if (fgets(buff, sizeof(buff), fp) == NULL) {
//         // fclose(fp); закрывать стандартный поток не нужно
//         return 2;
//     }

//     int res = 0;

//     for (size_t i = 0; i < max_length && buff[i] != '\0'; i++) {
//         if (buff[i] != ' ' && (buff[i + 1] == ' ' || buff[i + 1] == '\0')) res++;
//     }

//     printf("%d", res);

//     // fclose(fp); закрывать стандартный поток не нужно

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char buff[512];
//     int w, h;

//     FILE* fp = stdout;  // имитация отрытого файлового потока

//     scanf("%d %d", &w, &h);

//     sprintf(buff, "rectangle: %d; %d", w, h);

//     fputs(buff, fp);

//     // fclose(fp); закрывать стандартный поток не нужно

//     return 0;
// }

// #include <stdio.h>

// enum { max_length_ar = 20 };

// int main(void) {
//     double temp[max_length_ar];

//     FILE* fp = stdin;  // имитация отрытого файлового потока

//     size_t count = 0;

//     while (count < max_length_ar && fscanf(fp, "%lf", &temp[count]) == 1) count++;

//     for (size_t i = 0; i < count; i++) {
//         if (temp[i] > 0) printf("%.2lf ", temp[i]);
//     }

//     // fclose(fp); закрывать стандартный поток не нужно

//     return 0;
// }

#include <stdio.h>

typedef struct {
    unsigned id;
    unsigned width;
    unsigned height;
    unsigned depth;
    double weight;
} BOX;

int main(void) {
    FILE* fp = stdout;  // имитация отрытого файлового потока

    BOX tmp;

    scanf("%u; %u; %u; %u; %lf", &tmp.id, &tmp.width, &tmp.height, &tmp.depth, &tmp.weight);

    fprintf(fp, "box %u: %u x %u x %u", tmp.id, tmp.width, tmp.height, tmp.depth);

    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}