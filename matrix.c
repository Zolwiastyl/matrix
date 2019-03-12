#include "matrix.h"

FILE* OpeningFile(char* argv) {
  FILE* file1 = fopen(argv, "r");
  return file1;
}

struct count {
  int elements;
  int rows;
};
struct CountingElementsAndRowsOfFile(char* argv) {
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

int* ReadingFileToArray(struct NumberOf, char* argv) {
  int* arr = malloc(sizeof(int) * (NumberOf.elements + 1));
  int i = 0;
  FILE* file1 = OpeningFile(argv);
  while (fscanf(file1, "%i", &arr[i]) != EOF) {
    i++;
  }

  return arr;
}

int* AddMatrices(struct NumberOf, int* Arr1, int* Arr2) {
  int* Arr3 = malloc(sizeof(int) * (NumberOf.elements + 1));

  for (int i = 0; i < NumberOf.elements; i++) {
    Arr3[i] = Arr1[i] + Arr2[i];
  }
  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr3[i]);
  }
  return Arr3;
}

int* SubtractMatrices(struct NumberOf, int* Arr1, int* Arr2) {
  int* Arr3 = malloc(sizeof(int) * (NumberOf.elements + 1));

  for (int i = 0; i < NumberOf.elements; i++) {
    Arr3[i] = Arr1[i] - Arr2[i];
  }

  return Arr3;
}
int* MultiplyMatrices(struct NumberOf, int* Arr1, int* Arr2) {
  int* Arr3 = malloc(sizeof(int) * (NumberOf.elements + 1));

  for (int i = 0; i < NumberOf.rows; i++) {
    for (int j = 0; j < NumberOf.rows; j++) {
      Arr3[i] += Arr1[i] * Arr2[j * NumberOf.rows];
    }
    for (int i = 0; i < NumberOf.elements; i++) {
      printf(" %i \n", Arr3[i]);
    }
  }
  return Arr3;
}

/*void DoPrintedDebug() {
  printf("The second number is: %i \n", arr1[2]);
  printf("number of elements: %i \n", elementsCount);
  printf("last element: %i\n", buffor);
  printf("row number is: %i\n", NumberOf.rows);
  return 0;
}*/