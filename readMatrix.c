#include <stdio.h>
#include <stdlib.h>

void loadMatrix(double* matrix, const char* fileName){
  FILE *fd = fopen(fileName, "r"); 
  
  if(fd == NULL){
    perror("Error opening file: ");
    exit(1);
  }

  int i = 0;
  while(fscanf(fd, "%lf", matrix+i) != EOF){
    i++;
  }
}

int main(){
  const int size = 9;
  double* matrix = malloc(sizeof(double)*size);
  //double matrix[3][3];
  loadMatrix(matrix, "matrix");
  for(int i=0; i<size; i++){
    printf("%lf\n", *(matrix + i));
  }
  return 0;
}
