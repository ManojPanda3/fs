#define PCRE2_CODE_UNIT_WIDTH 8
#include <dirent.h>
#include <pcre2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileIgnore.c"
#define typedef enum { false, true } Bool;
#define EXIT_FAIL 0
#define MAX_PATH_LEN 350
int fileSearch(char* path, char* file, pcre2_code* regex,
               pcre2_match_data* match_data, int strictMode)
{
  DIR* dir;
  if((dir= opendir(path)) == NULL) {
    return EXIT_FAIL;
  }
  struct dirent*  pt;
  struct dirent** filePt;
  int             fileNum;
  fileNum= scandir(path, &filePt, NULL, alphasort);
  if(fileNum < 0) {
    perror("scandir");
    return EXIT_FAIL;
  }

  for(int i= 0; i < fileNum; i++) {
    pt= filePt[i];
    if(pt->d_type == DT_DIR) {
      if(fileIgnore(pt->d_name, strictMode)) {
        continue;
      }
      char newPath[MAX_PATH_LEN];
      snprintf(newPath, MAX_PATH_LEN, "%s/%s", path, pt->d_name);
      fileSearch(newPath, file, regex, match_data, strictMode);
      continue;
    }
    char* fileName= pt->d_name;
    int   ret= pcre2_match(regex, (PCRE2_SPTR)fileName, strlen(fileName), 0, 0,
                           match_data, NULL);
    if(ret > 0) {
      printf("%s/%s\n", path, fileName);
    }
  }
  free(filePt);
  closedir(dir);
  return 1;
}
