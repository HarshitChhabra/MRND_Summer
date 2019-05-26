
int stairs(int k, int steps){
	int i = 1, sum = 0;
	if (steps <= 1)
		return 1;
	while (steps - i >= 0){
		sum += (stairs(k, steps - i));
		i++;
	}
	return sum;
}

void testStairs(){
	printf("%d\n", stairs(5, 5));
}