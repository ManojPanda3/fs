#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_FAIL 0;
#define MAX_TMPPATH_LEN 2024
typedef enum { False, True } Bool;

int          StrictMode  = False;
unsigned int DirIgnoreLen= 7;
char*        DirIgnore[7]= {"node_module", "vendor", "tmp",
                            "coverage",    "target", "build"};

Bool isIn(char** arr, unsigned int arrLen, char* elm)
{
  for(int i= 0; i < arrLen; i++) {
    if(arr[i] == elm) {
      return True;
    }
  }
  return False;
}
char* addStr(char* str1, char* str2)
{
  if(str1 == NULL || str2 == NULL) {
    return NULL;
  }
  unsigned int size= strlen(str1) + strlen(str2) + 1;

  char* ans= (char*)malloc(sizeof(char) * size);
  if(ans == NULL) {
    return NULL;
  }

  int i= 0, j= 0;
  while(i < size - 1) {
    if(j < strlen(str1)) {
      ans[i++]= str1[j++];
    } else {
      ans[i++]= str2[i - strlen(str1)];
    }
  }
  ans[i]= '\0';

  return ans;
}
// This File Finding Program uses kmp searching algorithm to find match in b/w
// provided and founded files This function is a critical part of kmp search i
// write it diffly to find pattern of given file and use it on other files. :)
char* patternArrCreator(char* pattern, unsigned int patternLen)
{
  char* patternArr= (char*)malloc(patternLen * sizeof(char) + 1);
  if(patternArr == NULL) {
    printf("Error While Locating memory for patternArr");
    abort();
  }// we are storing the pattern as a char to save memory
  // this part is no need but ok :)
  patternArr[patternLen - 1]= '\0';

  // creating the pattern
  for(int i= 1, j= 0; i < patternLen; i++) {
    if(pattern[i] == pattern[j]) {
      j++;
    } else if(j) {
      j= 0;
    }
    patternArr[i]= j + 1;
  }
  return patternArr;
}
// the main component of kmp seraching
int kmpSubStringSearching(char* text, unsigned int textLen, char* pattern,
                          char* patternArr, unsigned int patternLen)
{
  for(int i= 0, j= 0; i < textLen; i++) {
    if(text[i] == pattern[j]) {
      if(j == patternLen - 1) {
        return i - j;
      }
      j++;
    } else if(j) {
      j= patternArr[j - 1];
      i--;
    } else {
      j= 0;
    }
  }
  return -1;
}
// the crucial function which run recurcively to find available files mathching
// with given file;
int fileSearch(char* path, char* file, unsigned int fileSLen, char* fileArr)
{
  // to know how much turn the program tack to find the file(turn mean how
  // many directory its searched for)
  static unsigned int turn= 0;
  turn++;
  int isslash= (path[strlen(path) - 1] == '/');

  // just reading the directory
  DIR* dir;
  if((dir= opendir(path)) == NULL) {
    return EXIT_FAIL;
  }
  struct dirent* pt;
  // A func which check wether the given path has / on last or not
  while((pt= readdir(dir)) != NULL) {
    if(pt->d_type == DT_DIR) {
      // if there a directory found then another function was called.

      if(strcmp(pt->d_name, ".") == 0 || strcmp(pt->d_name, "..") == -0 ||

         (!StrictMode && (pt->d_name[0] == '.'

                          || isIn(DirIgnore, DirIgnoreLen, pt->d_name)))) {
        continue;// avoiding looping;
      }
      char* tmpPath;
      if(!isslash) {
        tmpPath= addStr(path, "/");
        tmpPath= addStr(tmpPath, pt->d_name);
      } else {
        tmpPath= addStr(path, pt->d_name);
      }
      // NOTE:: The recursive func
      fileSearch(tmpPath, file, fileSLen, fileArr);
      free(tmpPath);
      continue;
    }
    // herechecking which file is matching with given file .
    if(strlen(pt->d_name) >= fileSLen) {
      if(kmpSubStringSearching(pt->d_name, strlen(pt->d_name), file, fileArr,
                               fileSLen) != -1) {
        printf("%d: %s%s\n", turn, path, pt->d_name);
      }
    }
  }
  closedir(dir);
  return EXIT_SUCCESS;
}
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
int main(int argc, char* argv[])
{
  char *path= "./", *file= "";
  if(argc < 2) {
    printf("ERROR :\n %s\n", help());
    return EXIT_FAIL;
  }
  file= argv[1];
  for(int i= 1; i < argc; i++) {
    if(!strcmp(argv[i], "-d") || !strcmp(argv[i], "--dir")) {
      path= argv[i + 1];
    } else if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
      printf("%s\n", help());
      return EXIT_SUCCESS;
    } else if(!strcmp(argv[i], "--strict") || !strcmp(argv[i], "-s")) {
      StrictMode= True;
      continue;
    }
  }
  int   fileSLen= strlen(file);
  char* fileArr = patternArrCreator(file, fileSLen);
  // printf("%s", addStr("Hello", "world"));
  if(fileSearch(path, file, fileSLen, fileArr)) {
    printf("DONE\n");
  }
  free(fileArr);
  return EXIT_SUCCESS;
}
