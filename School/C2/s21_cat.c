#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct argument {
  int b, e, n, s, t, v;
} arguments;

int parser(int argc, char *argv[], arguments *arg);
int read_file(char *argv[], arguments *arg);

int main(int argc, char *argv[]) {
  int err = 1;
  arguments arg = {0};
  err = parser(argc, argv, &arg);
  if (arg.v) {
    arg.e = arg.t = 0;
  }
  if (arg.b == 1) {
    arg.n = 0;
  }

  while (optind < argc) {
    err = read_file(argv, &arg);
    optind++;
  }
  return err;
}

int parser(int argc, char *argv[], arguments *arg) {
  int c;
  int ret = 0;
  int index = 0;
  static struct option options[] = {
      {"number-nonblank", 0, 0, 'b'},
      {"number", 0, 0, 'n'},
      {"squeeze-blank", 0, 0, 's'},
      {0, 0, 0, 0},
  };

  while ((c = getopt_long(argc, argv, "bEnsTvet", options, &index)) != -1) {
    switch (c) {
    case 'b':
      arg->b = 1;
      break;

    case 'E':
      arg->e = 1;
      break;

    case 'n':
      arg->n = 1;
      break;

    case 's':
      arg->s = 1;
      break;

    case 'T':
      arg->t = 1;
      break;

    case 'v':
      arg->v = 1;
      break;

    case 'e':
      arg->e = 1;
      arg->v = 1;
      break;

    case 't':
      arg->t = 1;
      arg->v = 1;
      break;

    case '?':
      ret = -1;
      break;
    }
  }
  return ret;
}

int read_file(char *argv[], arguments *arg) {
  FILE *file;
  int ret = 0;

  file = fopen(argv[optind], "r");

  if (file != NULL) {
    int str_count = 1;
    int empty_str_count = 0;
    int last_sym = '\n';

    while (1) {
      int cur_c = fgetc(file);
      if (cur_c == EOF) {
        break;
      }
      if (arg->s && cur_c == '\n' && last_sym == '\n') {
        empty_str_count++;
        if (empty_str_count > 1) {
          continue;
        }
      } else {
        empty_str_count = 0;
      }
      if (last_sym == '\n' && ((arg->b && cur_c != '\n') || arg->n)) {
        printf("%6d\t", str_count++);
      }
      if (arg->t && cur_c == '\t') {
        printf("^");
        cur_c = 'I';
      }
      if (arg->e && cur_c == '\n') {
        printf("$");
      }
      if (arg->v) {
        if ((cur_c >= 0 && cur_c < 9) || (cur_c > 10 && cur_c < 32)) {
          printf("^");
          cur_c += 64;
        }
      }
      printf("%c", cur_c);
      last_sym = cur_c;
    }
    fclose(file);
  } else {
    ret = -1;
  }
  return ret;
}