#include <string.h>
#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#include <stdio.h>
#include <stdlib.h>

unsigned short int zAlgo(char* text, char* pattern)
{
  int textLen= strlen(text), patternLen= strlen(pattern);
  if(textLen < patternLen) {
    return 0;
  }
  int   zLen= textLen + 1 + patternLen;
  char* z   = (char*)malloc(sizeof(char) * zLen);
  char* str = (char*)malloc(sizeof(char) * zLen);
  sprintf(str, "%s %s", pattern, text);
  int L= 0, R= patternLen + 1;
  while(R < zLen) {
    if(str[R] == str[L]) {
      L++;
      z[R - L]+= 1;
    } else if(L) {
      L= 0;
      continue;
    }
    R++;
  }
  for(int i= patternLen + 1; i < zLen; i++) {
    if(z[i] == patternLen) {
      return 1;
    }
  }
  return 0;
}
pcre2_code* strMatch(char* file, pcre2_match_data** match_data)
{
  pcre2_code* regax;
  int         error;
  PCRE2_SIZE  erroroffset;
  regax= pcre2_compile((PCRE2_SPTR)file, PCRE2_ZERO_TERMINATED, 0, &error,
                       &erroroffset, NULL);
  if(regax == NULL) {
    PCRE2_UCHAR buff[256];
    pcre2_get_error_message(error, buff, sizeof(buff));
    printf("Error compilation failed at offset %d : %s\n", (int)erroroffset,
           buff);
    exit(EXIT_FAILURE);
  }
  *match_data= pcre2_match_data_create_from_pattern(regax, NULL);
  return regax;
}
