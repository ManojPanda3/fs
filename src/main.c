#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#include <stdlib.h>

#include "args.c"
#include "fileSearch.c"
#include "strMatch.c"

int main(int argc, char* argv[])
{
  char** output= (char**)malloc(sizeof(char*));
  argSetup(argc, argv, output);
  char *            file= output[1], *path= output[0];
  int               StrictMode= output[2][0];
  pcre2_match_data* match_data;
  pcre2_code*       regex= strMatch(file, &match_data);
  fileSearch(path, file, regex, match_data, StrictMode);
  pcre2_match_data_free(match_data);
  pcre2_code_free(regex);
  return EXIT_SUCCESS;
}
