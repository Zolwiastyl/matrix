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
  int* Arr4;

  ElementsNum = CountingElementsAndRowsOfFile(argv[1]);
  RowsNum = CountingElementsAndRowsOfFile(argv[1]);
  Arr1 = ReadingFileToArray(ElementsNum, argv[1]);
  Arr2 = ReadingFileToArray(ElementsNum, argv[2]);
  switch (argv[3][0]) {
    case '+':
      Arr4 = AddMatrices(ElementsNum, Arr1, Arr2);
      break;
    case '-':
      Arr4 = SubtractMatrices(ElementsNum, Arr1, Arr2);
      break;
    case '*':
      Arr4 = MultiplyMatrices(ElementsNum, Arr1, Arr2);
      // free(Arr3);
      break;
  }
  free(Arr1);
  free(Arr2);
  free(Arr4);
  return 0;
}
