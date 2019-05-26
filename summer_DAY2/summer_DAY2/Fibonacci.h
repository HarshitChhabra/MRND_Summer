long fibo(int n){
	if (n <= 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

long fiboDP(int n, std::unordered_map<int, int> *memo){
	//printf("call %d\n",n);
	if ((*memo).find(n) != (*memo).end()){
		printf("found %d\n", n);
		return (*memo)[n];
	}
	(*memo)[n] = fiboDP(n - 1, memo) + fiboDP(n - 2, memo);
	printf("calc %d\n", n);
	return (*memo)[n];
}

void testFibo(){
	int fiboVal = 30;
	std::unordered_map<int, int> map;
	map[0] = 0;
	map[1] = 1;
	if (fiboVal>0)
		printf("DP : %ld\n", fiboDP(fiboVal, &map));
	if (fiboVal >= 0)
		printf("%ld\n", fibo(fiboVal));
	else
		printf("Negative input");
}