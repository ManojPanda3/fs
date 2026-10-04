#include <pcre2.h>
#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H
int fileSearch(char* path, char* file, pcre2_code* regex,
               pcre2_match_data* match_data, int strictMode);
#endif// FILE_SEARCH_H
