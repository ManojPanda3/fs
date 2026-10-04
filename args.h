#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARGS_H
typedef struct ArgOutput {
  char* path;
  char* file;
  bool  is_strict;
  bool  is_help;
  bool  is_success;
} ArgOutput;

void print_help();

ArgOutput arg_setup(int argc, char* argv[]);
#define ARGS_H
#endif
