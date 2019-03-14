#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
  struct count RowsNum;
  struct count ElementsNum;
  struct count ElementsNum1;
  int* Arr1;
  int* Arr2;
  int* Arr3;
  if (argc < 5) {
    fprintf(stderr, "I need more arguments.");
    exit(1);
  }
  ElementsNum = CountingElementsAndRowsOfFile(argv[1]);
  ElementsNum1 = CountingElementsAndRowsOfFile(argv[2]);
  RowsNum = CountingElementsAndRowsOfFile(argv[1]);
  if (CheckingEquality(ElementsNum, ElementsNum1) == 0) {
    fprintf(stderr, "Matrices are not equal!\n");
    exit(1);
  }
  if (CheckIfSquare(ElementsNum) == 0 || CheckIfSquare(ElementsNum1) == 0) {
    fprintf(stderr, "Matrices are not square!\n");
    exit(1);
  }
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
      // free(Arr3);
      break;
  }
  free(Arr1);
  free(Arr2);
  WrittingMatrixToFile(argv[4], Arr3, ElementsNum);
  free(Arr3);
  return 0;
}
