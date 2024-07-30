#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* help()
{
  return "fs [..filename] [..flags] [..options]\n\tex: fs main.cpp -d / \n\t "
         "-d "
         "or --dir : used for mentioning \n\t\tthe dir on which to search for "
         "the "
         "file.\n\t\tdefault is ./"
         "\n -s/--strict : \n\t by thing flag you can also search inside . dir "
         "and ignored dir";
}

void argSetup(int argc, char* argv[], char** output)
{
  char *path= ".", *file= "";
  char* StrictMode= malloc(sizeof(char));
  StrictMode[0]   = 0;
  if(argc < 2) {
    printf("ERROR :\n %s\n", help());
    exit(EXIT_FAILURE);
  }
  file= argv[1];
  for(int i= 1; i < argc; i++) {
    if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "--dir")) {
      path= argv[i + 1];
      if(strlen(path) > 1 && path[strlen(path) - 1] == '/') {
        path[strlen(path) - 1]= '\0';
      }
    } else if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
      printf("%s\n", help());
      exit(EXIT_SUCCESS);
    } else if(!strcmp(argv[i], "--strict") || !strcmp(argv[i], "-s")) {
      StrictMode[0]= 1;
      continue;
    }
  }
  output[0]= path;
  output[1]= file;
  output[2]= StrictMode;
}
