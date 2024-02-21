#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
  int e, i, v, c, l, n, h, s, f, o;
  int len_pattern, mem_pattern;
  char *pattern, *new_pattern;
} flag;

flag arg_parser(int argc, char **argv);
void processFile(flag arg, char *path, regex_t *reg);
void output(flag arg, int argc, char **argv);
void output_line(flag arg, char *line, int n, char *path, int line_count);
void reg_file(flag *arg, char *filepath);
void pattern_add(flag *arg, char *pattern);
void print_match(flag arg, regex_t *reg, char *line, char *path,
                 int line_count);

int main(int argc, char **argv) {
  flag arg = arg_parser(argc, argv);
  output(arg, argc, argv);
  free(arg.pattern);
  return 0;
}

flag arg_parser(int argc, char **argv) {
  flag arg = {0};
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        arg.e = 1;
        pattern_add(&arg, optarg);
        break;
      case 'i':
        arg.i = REG_ICASE;
        break;
      case 'v':
        arg.v = 1;
        break;
      case 'c':
        arg.c = 1;
        break;
      case 'l':
        arg.c = 1;
        arg.l = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 'h':
        arg.h = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'f':
        arg.f = 1;
        reg_file(&arg, optarg);
        break;
      case 'o':
        arg.o = 1;
        break;
    }
  }
  if (arg.len_pattern == 0) {
    pattern_add(&arg, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) arg.h = 1;
  return arg;
}

void output(flag arg, int argc, char **argv) {
  regex_t re;
  int error = regcomp(&re, arg.pattern, REG_EXTENDED | arg.i);
  if (error) {
    perror("Error");
    exit(1);
  }
  for (int i = optind; i < argc; i++) {
    processFile(arg, argv[i], &re);
  }
  regfree(&re);
}

void output_line(flag arg, char *line, int n, char *path, int line_count) {
  if (!arg.h) printf("%s:", path);
  if (arg.n) printf("%d:", line_count);
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}

void processFile(flag arg, char *path, regex_t *reg) {
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    if (!arg.s) perror(path);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = 0;
  int line_count = 1;
  int count = 0;
  read = getline(&line, &memlen, f);
  while (read != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if ((result == 0 && !arg.v) || (result != 0 && arg.v)) {
      if (!arg.c && !arg.l) {
        if (arg.o) {
          print_match(arg, reg, line, path, line_count);
        } else {
          output_line(arg, line, read, path, line_count);
        }
      }
      count++;
    }
    read = getline(&line, &memlen, f);
    line_count++;
  }
  free(line);
  if (arg.c && !arg.l) {
    if (!arg.h) printf("%s:", path);
    printf("%d\n", count);
  }
  if (arg.l && count > 0) printf("%s\n", path);
  fclose(f);
}

void reg_file(flag *arg, char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    if (!arg->s) perror(filepath);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  int read = getline(&line, &memlen, f);
  while (read != -1) {
    if (line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }
    pattern_add(arg, line);
    read = getline(&line, &memlen, f);
  }
  free(line);
  fclose(f);
}

void pattern_add(flag *arg, char *pattern) {
  int n = 0;
  if (pattern == NULL) {
    printf("Usage: ./s21_grep [OPTION]... PATTERNS [FILE]...\n");
  } else {
    n = strlen(pattern);
  }
  if (arg->len_pattern == 0) {
    arg->mem_pattern = 1024;
    arg->pattern = malloc(arg->mem_pattern * sizeof(char));
  }
  if (arg->mem_pattern < arg->len_pattern + n) {
    arg->new_pattern = realloc(arg->pattern, arg->mem_pattern * 2);
    arg->pattern = arg->new_pattern;
  }
  if (arg->len_pattern != 0) {
    strcat(arg->pattern + arg->len_pattern, "|");
    arg->len_pattern++;
  }
  arg->len_pattern += sprintf(arg->pattern + arg->len_pattern, "(%s)", pattern);
}

void print_match(flag arg, regex_t *reg, char *line, char *path,
                 int line_count) {
  regmatch_t math;
  int offset = 0;
  while (1) {
    int result = regexec(reg, line + offset, 1, &math, 0);
    if (result != 0) {
      break;
    }
    if (!arg.h) printf("%s:", path);
    if (arg.n) printf("%d:", line_count);
    for (int i = math.rm_so; i < math.rm_eo; i++) {
      putchar(line[offset + i]);
    }
    putchar('\n');
    offset += math.rm_eo;
  }
}