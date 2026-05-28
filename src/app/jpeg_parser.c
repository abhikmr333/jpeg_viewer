#include "jpeg_parser.h"

#include <stdint.h>
#include <stdio.h>

void parse_jpeg(const char* filepath) {
  // open the file in read binary mode
  FILE* img = fopen(filepath, "rb");

  // printf("%X", fgetc(img));
  // fgetc returns a 32 bit int not a 8 bit or 1 byte char constant.
  int32_t byte;
  int8_t column = 0;

  /*!= has higher precedence than = that is why byte was storing the result of
  fgetc(img) != EOF  i.e. a boolean val*/
  while ((byte = fgetc(img)) != EOF) {
    printf("%02X ", byte);

    if (column == 16) {
      printf("\n");
      column = 0;
    }
    column++;
  }
  printf("\n");
  /* destroys the buffer being used by img and the memory FILE
   pointer is taking as well*/
  fclose(img);
  img = NULL;  // preventing reuse
}