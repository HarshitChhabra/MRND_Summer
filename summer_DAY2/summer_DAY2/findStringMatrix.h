void findStng(char **arr, int m, int n, char *stng, int direction, int index, int current_row, int current_col, int *count, int start, int end){
	//Terminating condition

	if (index == strlen(stng))
		return;

	if (current_row < 0 || current_row >= m || current_col < 0 || current_col >= n)
		return;

	if (direction == 0){ //S
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
			findStng(arr, m, n, stng, direction, index + 1, current_row + 1, current_col, count, start, end);

		}
		else
			return;
	}
	else if (direction == 1){ //W
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
			findStng(arr, m, n, stng, direction, index + 1, current_row, current_col - 1, count, start, end);

		}
		else
			return;
	}
	else if (direction == 2){ //NE
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
			//printf("%c %d %d %d count: %d\n", stng[index], direction, current_row, current_col,(*count)+1);
			findStng(arr, m, n, stng, direction, index + 1, current_row - 1, current_col + 1, count, start, end);

		}
		else
			return;
	}
	else if (direction == 3){ //NW
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
			//printf("%c %d %d %d\n", stng[index], direction, current_row, current_col);
			findStng(arr, m, n, stng, direction, index + 1, current_row - 1, current_col - 1, count, start, end);

		}
		else
			return;
	}
	else if (direction == 4){ //N
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
		}
		findStng(arr, m, n, stng, direction, index + 1, current_row - 1, current_col, count, start, end);
	}
	else if (direction == 5){ //E
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
		}
		findStng(arr, m, n, stng, direction, index + 1, current_row, current_col + 1, count, start, end);
	}
	else if (direction == 6){ //SW
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
		}
		findStng(arr, m, n, stng, direction, index + 1, current_row + 1, current_col - 1, count, start, end);
	}
	else{ //SE
		if (stng[index] == arr[current_row][current_col]){
			if (index + 1 == strlen(stng)){
				printf(" Starts at %d %d , Ends at %d %d\n", start, end, current_row, current_col);
				(*count) = (*count) + 1;
				return;
			}
		}
		findStng(arr, m, n, stng, direction, index + 1, current_row + 1, current_col + 1, count, start, end);
	}
}

void testStngMatrixSearch(){
	int i, j, r = 2, c = 5, count = 0;
	char *stng = "hi";
	char **arr = (char**)malloc(r*sizeof(char*));
	enum direction{ NW, N, NE, E, SE, S, SW, W }dir;
	for (i = 0; i < r; i++)
		arr[i] = (char*)malloc(c*sizeof(char));
	printf("Enter matrix\n");
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++)
			scanf_s(" %c", &arr[i][j]);
	}
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			if (arr[i][j] == stng[0]){
				findStng(arr, r, c, stng, 0, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 1, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 2, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 3, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 4, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 5, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 6, 0, i, j, &count, i, j);
				findStng(arr, r, c, stng, 7, 0, i, j, &count, i, j);
			}
		}
	}
	printf("Count: %d\n", count);
}
