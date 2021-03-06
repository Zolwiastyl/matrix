#include "matrix.h"

FILE* OpeningFile(char* argv) {
  FILE* file1 = fopen(argv, "r");
  if (file1 == NULL) {
    fprintf(stderr, "File %s doesn't exist\n", argv);
    perror("Please don't");
    exit(1);
  }
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
  printf(" %i \n", NumberOf.rows);
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
  printf(" %i \n", NumberOf.rows);

  for (int j = 0; j < NumberOf.rows; j++) {
    for (int i = 0; i < NumberOf.rows; i++) {
      for (int k = 0; k < NumberOf.rows; k++) {
        AuxillaryVariable +=
            Arr1[k + NumberOf.rows * j] * Arr3[k + NumberOf.rows * i];
      }

      Arr4[i + NumberOf.rows * j] = AuxillaryVariable;
      AuxillaryVariable = 0;
    }
  }
  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr4[i]);
  }

  return Arr4;
}

int* TransponingMatrix(struct count NumberOf, int* Arr2) {
  /*AuxillaryVariable +=
      Arr1[k + NumberOf.rows * i] * Arr3[j + NumberOf.rows * k];*/
  int* Arr3 = malloc(sizeof(int) * (NumberOf.elements + 1));
  for (int i = 0; i < NumberOf.rows; i++) {
    for (int j = 0; j < NumberOf.rows; j++) {
      Arr3[j + NumberOf.rows * i] = Arr2[i + NumberOf.rows * j];
      // dodawanie nas przemieszcza między kolumnami, a mnożenie między
      // wierszami. w arr3||
      // dodawanie nas przemieszcze między wierszami,
    }
  }

  for (int i = 0; i < NumberOf.elements; i++) {
    printf(" %i \n", Arr3[i]);
  }
  /*for (int i = 0; i < NumberOf.rows; i++) {
    for (int k = 0; k < NumberOf.elements; k += NumberOf.rows) {
      Arr3[k] = Arr2[k];
    }
  }*/
  return Arr3;
}

//
void WrittingMatrixToFile(char* argv, int* Arr, struct count NumberOf) {
  FILE* file = fopen(argv, "w");
  for (int i = 0; i < NumberOf.rows; i++) {
    for (int j = 0; j < NumberOf.rows; j++) {
      fprintf(file, "%5i ", Arr[j + NumberOf.rows * i]);
      // while (fscanf(file1, "%i", &arr[i]) != EOF)
    }
    fprintf(file, "\n");
  }
}
int CheckingEquality(struct count Size1, struct count Size2) {
  if (Size1.elements != Size2.elements) {
    return 0;
  } else {
    return 1;
  }
}
int CheckIfSquare(struct count Size1) {
  for (int i = 0; i <= Size1.elements; i++) {
    if (i * i == Size1.elements) {
      return 1;
    }
  }
  return 0;
}