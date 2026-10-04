#include <pcre2.h>

#ifndef STR_MATCH_H
#define STR_MATCH_H
pcre2_code* strMatch(char* file, pcre2_match_data** match_data);
#endif// STR_MATCH_H
