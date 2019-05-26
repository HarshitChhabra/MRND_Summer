void printPermutations(int available[], int result[], int index, int n, std::set<int> selected){
	int i;
	//printf("check %d\n",availa)
	if (index == n){
		for (i = 0; i < n; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < n; i++){
		if (selected.find(i) != selected.end())
			continue;
		selected.insert(i);
		result[index] = available[i];
		printPermutations(available, result, index + 1, n, selected);
		selected.erase(i);
	}
}



void testPermutations(){
	int arr[] = { 1, 3, 5 };
	int result[3];
	std::set<int> selected;
	printPermutations(arr, result, 0, 3, selected);
}