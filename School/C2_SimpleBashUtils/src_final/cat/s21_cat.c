#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arguments {
  int b, n, s, E, T, v;
} arguments;

arguments argument_parser(int argc, char** argv) {
  arguments arg = {0};
  struct option long_options[] = {{"number", no_argument, NULL, 'n'},
                                  {"number-nonblank", no_argument, NULL, 'b'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {"show-ends", no_argument, NULL, 'E'},
                                  {"show-tabs", no_argument, NULL, 'T'}};

  int opt;
  int index = 0;
  while ((opt = getopt_long(argc, argv, "bEnsTvet", long_options, &index)) !=
         -1) {
    switch (opt) {
      case 'b':
        arg.b = 1;
        break;
      case 'e':
        arg.E = 1;
        arg.v = 1;
        break;
      case 'E':
        arg.E = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 't':
        arg.T = 1;
        arg.v = 1;
        break;
      case 'T':
        arg.T = 1;
        break;
      case 'v':
        arg.v = 1;
        break;
      default:
        fprintf(stderr, "use: ./s21_cat [-bnsvetET] [file ...]\n");
        exit(1);
    }
  }
  return arg;
}

char v_output(char ch) {
  if (ch == '\n' || ch == '\t')
    ;
  else if (ch >= 0 && ch <= 31) {
    printf("^");
    ch += 64;
  } else if (ch == 127) {
    printf("^");
    ch -= 64;
  } else if (ch < -96 && ch > -128) {
    printf("M-^");
    ch -= 64;
  } else if (ch < -1 && ch >= -96) {
    printf("M-");
    ch -= 128;
  } else if (ch == -1) {
    printf("M-^");
    ch += 64;
  }
  return ch;
}

void outline(arguments* arg, char* line, int n) {
  for (int i = 0; i < n; i++) {
    if (arg->T && line[i] == '\t') {
      printf("^I");
    } else {
      if (arg->E && line[i] == '\n') {
        putchar('$');
      }
      if (arg->v) {
        line[i] = v_output(line[i]);
      }
      putchar(line[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  arguments arg = argument_parser(argc, argv);
  FILE* f = fopen(argv[optind], "r");
  char* line = NULL;
  size_t memline = 0;
  int read = 0;
  int line_count = 1;
  int empty_count = 0;
  read = getline(&line, &memline, f);
  while (read != -1) {
    if (line[0] == '\n') {
      empty_count++;
    } else {
      empty_count = 0;
    }
    if (arg.s && empty_count > 1) {
      ;
    } else {
      if (arg.n || arg.b) {
        if (arg.b && line[0] != '\n') {
          printf("%6d\t", line_count++);
        } else if (arg.n) {
          printf("%6d\t", line_count++);
        }
      }
      outline(&arg, line, read);
    }
    read = getline(&line, &memline, f);
  }
  free(line);
  fclose(f);
  return 0;
}