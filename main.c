#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
  struct count RowsNum;
  struct count ElementsNum;
  int* Arr1;
  int* Arr2;
  int* Arr3;

  ElementsNum = CountingElementsAndRowsOfFile(argv[1]);
  RowsNum = CountingElementsAndRowsOfFile(argv[1]);
  Arr1 = ReadingFileToArray(ElementsNum, argv[1]);
  Arr2 = ReadingFileToArray(ElementsNum, argv[2]);
  switch (argv[3][0]) {
    case '+':
      Arr3 = AddMatrices(ElementsNum, Arr1, Arr2);
      break;
    case '-':
      Arr3 = SubtractMatrices(ElementsNum, Arr1, Arr2);
      break;
    case '*':
      Arr3 = MultiplyMatrices(ElementsNum, Arr1, Arr2);
      break;
  }

  return 0;
}
