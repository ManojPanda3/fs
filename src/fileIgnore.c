#include <string.h>

char* DirIgnore[7]= {"node_module", "vendor", "tmp",
                     "coverage",    "target", "build"};
int   isIn(char** entries, int entriesLen, char* file)
{
  for(int i= 0; i < entriesLen; i++) {
    if(entries[i] == file) {
      return 1;
    }
  }
  return 0;
}

int fileIgnore(char* file, int strictMode)
{
  if(!strcmp(file, "..") || !strcmp(file, ".")) {
    return 1;
  }
  if(!strictMode && (file[0] == '.' || isIn(DirIgnore, 7, file))) {
    return 1;
  }
  return 0;
}
