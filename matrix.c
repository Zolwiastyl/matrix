#include "matrix.h"

FILE* OpeningFile(char* argv) {
  FILE* file1 = fopen(argv, "r");
  return file1;
}

struct count CountingElementsAndRowsOfFile(char* argv) {
  struct count NumberOf;
  NumberOf.elements = 0;
  int buffor;
  FILE* file1 = OpeningFile(argv);
  while (fscanf(file1, "%i", &buffor) != EOF) {
    NumberOf.elements++;
  }
  NumberOf.rows = sqrt(NumberOf.elements);
  fclose(file1);
  return NumberOf;
}

int* ReadingFileToArray(struct count NumberOf, char* argv) {
  int* arr = malloc(sizeof(int) * (NumberOf.elements + 1));
  int i = 0;
  FILE* file1 = OpeningFile(argv);
  while (fscanf(file1, "%i", &arr[i]) != EOF) {
    i++;
  }

  return arr;
}

int* AddMatrices(struct count NumberOf, int* Arr1, int* Arr2) {
  int* Arr4 = malloc(sizeof(int) * (NumberOf.elements + 1));

  for (int i = 0; i < NumberOf.elements; i++) {
    Arr4[i] = Arr1[i] + Arr2[i];
  }
  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr4[i]);
  }
  return Arr4;
}

int* SubtractMatrices(struct count NumberOf, int* Arr1, int* Arr2) {
  int* Arr4 = malloc(sizeof(int) * (NumberOf.elements + 1));

  for (int i = 0; i < NumberOf.elements; i++) {
    Arr4[i] = Arr1[i] - Arr2[i];
  }
  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr4[i]);
  }
  return Arr4;
}
int* MultiplyMatrices(struct count NumberOf, int* Arr1, int* Arr2) {
  int* Arr3 = TransponingMatrix(NumberOf, Arr2);
  int AuxillaryVariable = 0;
  int* Arr4 = malloc(sizeof(int) * (NumberOf.elements + 1));
  for (int i = 0; i < NumberOf.elements; i + NumberOf.rows) {
    for (int i = 0; i < NumberOf.rows; i++) {
      AuxillaryVariable += Arr1[i] * Arr3[i];
    }
    Arr4[i] = AuxillaryVariable;
  }
  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr4[i]);
  }

  return Arr4;
}

int* TransponingMatrix(struct count NumberOf, int* Arr2) {
  int* Arr3 = malloc(sizeof(int) * (NumberOf.elements + 1));
  for (int i = 0; i < NumberOf.rows; i++) {
    for (int i = 0; i < NumberOf.elements; i + NumberOf.rows) {
      Arr3[i] = Arr2[i];
    }
  }
  return Arr3;
}