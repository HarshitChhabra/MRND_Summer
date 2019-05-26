void transposeMatrix(int r, int c, int **arr){
	int **transpose = (int**)malloc(c*sizeof(int*)), i, j;
	for (i = 0; i < c; i++)
		transpose[i] = (int*)malloc(r*sizeof(int));
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			transpose[j][i] = arr[i][j];
		}
	}
	printf("Original\n");
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("Transpose\n");
	for (i = 0; i < c; i++){
		for (j = 0; j < r; j++)
			printf("%d ", transpose[i][j]);
		printf("\n");
	}
}

void testTransposeMatrix(){
	int i, j, val = 1;
	int **arr1 = (int**)malloc(3 * sizeof(int*)), **arr2;
	for (i = 0; i < 3; i++){
		arr1[i] = (int*)malloc(2 * sizeof(int));
		for (j = 0; j < 2; j++){
			arr1[i][j] = val++;
		}
	}
	transposeMatrix(3, 2, arr1);
}
