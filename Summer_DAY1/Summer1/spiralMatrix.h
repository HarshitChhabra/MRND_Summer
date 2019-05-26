void spiralRecursive(int i, int j, int r, int c, int **arr, int direction, int* depth){
	int itr1;
	if (i>r || j > c)
		return;
	if (direction == 0){
		for (itr1 = j; itr1 <= c; itr1++)
			printf("%d ", arr[i][itr1]);
		spiralRecursive(i + 1, c, r, c, arr, 1, depth);
	}
	else if (direction == 1){
		for (itr1 = i; itr1 <= r; itr1++)
			printf("%d ", arr[itr1][c]);
		spiralRecursive(r, c - 1, r, c - 1, arr, 2, depth);
	}
	else if (direction == 2){
		for (itr1 = c; itr1 >= (*depth); itr1--)
			printf("%d ", arr[r][itr1]);
		spiralRecursive(r - 1, (*depth), r - 1, c, arr, 3, depth);
	}
	else{
		for (itr1 = i; itr1 >= (*depth) + 1; itr1--)
			printf("%d ", arr[itr1][(*depth)]);
		(*depth) = (*depth) + 1;
		spiralRecursive((*depth), (*depth), r, c, arr, 0, depth);
	}
}

void spiralMatrix(int r, int c, int **arr){
	int i, j, colStart = 0, rowStart = 0, rowEnd = r - 1, colEnd = c - 1;
	printf("Original\n");
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	while (rowStart <= rowEnd && colStart <= colEnd){
		for (j = colStart; j <= colEnd; j++)
			printf("%d ", arr[rowStart][j]);
		rowStart++;
		for (j = rowStart; j <= rowEnd; j++)
			printf("%d ", arr[j][colEnd]);
		colEnd--;
		for (j = colEnd; j >= colStart; j--)
			printf("%d ", arr[rowEnd][j]);
		rowEnd--;
		for (j = rowEnd; j >= rowStart; j--)
			printf("%d ", arr[j][colStart]);
		colStart++;
	}
	printf("\n");
}

void testSpiral(){
	int i, j, val = 1, depth = 0;
	int **arr1 = (int**)malloc(3 * sizeof(int*)), **arr2;
	for (i = 0; i < 3; i++){
		arr1[i] = (int*)malloc(3 * sizeof(int));
		for (j = 0; j < 3; j++){
			arr1[i][j] = val++;
			//	printf("")
		}
	}
	spiralMatrix(3, 3, arr1);
	spiralRecursive(0, 0, 2, 2, arr1, 0, &depth);
}