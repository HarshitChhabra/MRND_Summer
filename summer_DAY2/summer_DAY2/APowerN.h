int APowerN(int a, int n){
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	//return (a%ModVal * APowerN(a, n - 1) % ModVal) % ModVal;
	return ((APowerN(a, n / 2)*APowerN(a, n / 2) % ModVal)*APowerN(a, n % 2)) % ModVal;
}

void testPower(){
	int a = 5, n = 2;
	printf("Power of %d raised to %d = %d\n", a, n, APowerN(a, n));
}