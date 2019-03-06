#include <stdio.h>
#include <stdlib.h>

/* TODO:

- [x] Czytać pliki
- [ ] Wczytać macierz
- [ ] Mieć strukturę na macierz
- [ ] Robić operacje na macierzach
- [ ] Zapisać macierz do pliku

Potrzebne rzeczy na zewnatrz (w x.c i w x.h)
- [ ] "klasa" macierz - struct
- [ ] funkcje robiace dzialania

*/

typedef struct {
  int size;  // square root of number of elements
  int* values;
} SquareMatrix;

void test() {
  SquareMatrix matrix;
  matrix.size = 3;
  matrix.values = (int*)malloc(2 * sizeof(int));

  matrix.values[1] = 99;

  printf("%d", matrix.values[1]);
}

SquareMatrix addMatrix(SquareMatrix a, SquareMatrix b) {}
SquareMatrix subMatrix(SquareMatrix a, SquareMatrix b) {}
SquareMatrix multiplyMatrix(SquareMatrix a, SquareMatrix b) {}

int main(int argc, char** argv) {
  if (argc < 4) {
    printf("I need four arguments.\n");
    return 1;
  }
  printf(">> %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
  FILE* file1 = fopen(argv[1], "r");

  test();

  return 0;
}