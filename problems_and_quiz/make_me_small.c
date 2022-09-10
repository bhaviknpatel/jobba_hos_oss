#include <stdio.h>

typedef struct __attribute__((__packed__)) structure_1
{
  short int b;
  char a;
} structure_1;

typedef struct __attribute__((__packed__)) structure_2
{
  int c;
  short int a;
  char b;
} structure_2;

typedef struct __attribute__((__packed__)) structure_3
{
  double b;
  int c;
  char a;
} structure_3;

typedef struct __attribute__((__packed__)) structure_4
{
  double a;
  int b;
  char c;
} structure_4;

typedef struct __attribute__((__packed__)) structure_5
{
  structure_3 a;
  structure_4 c;
  structure_2 d;
  structure_1 b;
} structure_5;

int main()
{
  printf("Make me small\n");
  int i = 0;
  size_t tot_structs_size = sizeof(structure_1) + sizeof(structure_2) + sizeof(structure_3) + sizeof(structure_4) + sizeof(structure_5);
  printf("Total size of structs: %zu\n", tot_structs_size);
  return 0;
}
