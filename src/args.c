#include "args.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help()
{
  fprintf(
      stdout,
      "fs [..filename] [..flags] [..options]\n\tex: fs main.cpp -d / \n\t "
      "-d "
      "or --dir : used for mentioning \n\t\tthe dir on which to search for "
      "the "
      "file.\n\t\tdefault is ./"
      "\n -s/--strict : \n\t by thing flag you can also search inside . dir "
      "and ignored dir");
}

ArgOutput arg_setup(int argc, char* argv[])
{
  ArgOutput argout= {NULL, NULL, false, false, true};

  if(argc < 2) {
    argout.is_success= false;
    argout.is_help   = true;

    return argout;
  }

  char*  file    = argv[1];
  char*  path    = NULL;
  size_t file_len= strlen(file);
  size_t path_len= 0;

  for(int i= 1; i < argc; i++) {
    if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "--dir")) {
      path    = argv[i + 1];
      path_len= strlen(path);
      if(path_len > 1 && path[path_len - 1] == '/') {
        path[strlen(path) - 1]= '\0';
      }
    } else if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
      argout.is_help= true;
      return argout;
    } else if(!strcmp(argv[i], "--strict") || !strcmp(argv[i], "-s")) {
      argout.is_strict= true;
      continue;
    }
  }

  // path points to a memory in argv which is provided by outside function
  // so even after the frame of this function release the pointed memory will be
  // valid so theres no need to create an heap memory and allocate memory
  // since it assumes those are managed in argv;
  argout.path= path;
  argout.file= file;

  return argout;
}
