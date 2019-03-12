// tu mówię, co jest

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// i inne

struct count {
  int elements;
  int rows;
};

struct count CountingElementsAndRowsOfFile(char* argv);
int* ReadingFileToArray(struct count NumberOf, char* argv);
int* AddMatrices(struct count NumberOf, int* Arr1, int* Arr2);
int* SubtractMatrices(struct count NumberOf, int* Arr1, int* Arr2);
int* MultiplyMatrices(struct count NumberOf, int* Arr1, int* Arr2);

// i inne