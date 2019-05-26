void printVals(int level, int n, int prev){ //WRONG => PREORDER

	int levelValue;
	if (level == 0)
		return;
	if (level == n){
		for (levelValue = 0; levelValue <= 9; levelValue++)
			printf("%d ", prev + levelValue);
		for (levelValue = 1; levelValue <= 9; levelValue++)
			printVals(level - 1, n, (prev + levelValue) * 10);
	}
	else{
		for (levelValue = 0; levelValue <= 9; levelValue++)
			printf("%d ", prev + levelValue);
		for (levelValue = 0; levelValue <= 9; levelValue++)
			printVals(level - 1, n, (prev + levelValue) * 10);
	}

}

void printAllVals(int n, int prev){
	int i;
	if (n <= 1){
		printf("%d ", prev);
		return;
	}
	for (i = 0; i <= 9; i++)
		printAllVals(n - 1, (prev * 10) + i);
}



void testNDigitPrint(){
	int n = 3;
	int end = pow(10, n - 1) - 1;
	int ans[] = { 0, 0, 0, 0 };
	//printVals(n-1, n - 1, 0);
	printAllVals(n, 0);
}