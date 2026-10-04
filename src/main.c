#include <string.h>
#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#include <stdlib.h>

#include "args.h"
#include "fileIgnore.h"
#include "fileSearch.h"
#include "strMatch.h"

int main(int argc, char* argv[])
{
  ArgOutput argout= arg_setup(argc, argv);
  if(argout.is_help) {
    print_help();
  }

  if(argout.is_success == false) {
    return EXIT_FAIL;
  }

  pcre2_match_data* match_data;
  pcre2_code*       regex= strMatch(argout.file, &match_data);
  fileSearch(argout.path, argout.file, regex, match_data, argout.is_strict);
  pcre2_match_data_free(match_data);
  pcre2_code_free(regex);
  return EXIT_SUCCESS;
}
