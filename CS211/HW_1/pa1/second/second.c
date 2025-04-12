#include <stdio.h>
#include <stdlib.h>

int read_file(const char *filename, int ***matrix, int *n, int *discard)
{
  FILE *file = fopen(filename, "r");
  if (!file)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  if((fscanf(file, "%d", n)) != 1){
    fprintf(stderr, "error reading input \n");
    return 1; 
  }
  if((fscanf(file, "%d", discard)) != 1){
    fprintf(stderr, "error reading input \n");
    return 1; 
  }
  

  *matrix = (int **)malloc(*n * sizeof(int *));

  int z; 
  if(n == discard){
    printf("true \n");
  }
  for (int i = 0; i < *n; i++) // 
  {
    (*matrix)[i] = (int *)malloc(*n * sizeof(int));
    for (int j = 0; j < *n; j++)
    {
      if((fscanf(file, "%d", &z) == 1)){
        (*matrix)[i][j] = z; 
      }
    }
  }
  fclose(file);
  return 0; 
}

void rotate(int **matrix, int n)
{
  int **done = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++)
  {
    done[i] = (int *)malloc(n * sizeof(int));
  }

  // rotate matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      done[j][n - 1 - i] = matrix[i][j];
    }
  }

  // print matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d", done[i][j]);
      if (j < n - 1)
        printf("\t");
    }
    printf("\n");
  }

  // free memory
  for (int i = 0; i < n; i++)
  {
    free(done[i]);
  }
  free(done);
}

//free original matrix

void free_matrix(int **matrix, int n){
    for(int i = 0; i < n; i++){
      free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "./second {text file}\n");
    exit(1);
  }

  int **matrix;
  int n;
  int discard;

  //read file first
  read_file(argv[1], &matrix, &n, &discard); 

  //then rotate it
  rotate(matrix, n); 
  
  //then free the original matrix
  free_matrix(matrix, n); 

  return EXIT_SUCCESS;
}