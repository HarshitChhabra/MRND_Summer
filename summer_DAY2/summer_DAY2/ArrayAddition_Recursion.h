long addArrayRecursion(int arr[], int index){
	if (index == 0)
		return arr[0];
	return arr[index] + addArrayRecursion(arr, index - 1);
}
void testArrayAdditionRecursion(){
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = 1;
	if (n)
		printf("%ld ", addArrayRecursion(arr, n - 1));
	else
		printf("No elements\n");
}