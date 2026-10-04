#ifndef ARGS_H
#define ARGS_H 1
#include <stdbool.h>

typedef struct {
  char* path;
  char* file;
  bool  is_success;
  bool  is_help;
  bool  is_strict;
} ArgOutput;

void      print_help();
ArgOutput arg_setup(int argc, char* argv[]);

#endif// ARGS_H
