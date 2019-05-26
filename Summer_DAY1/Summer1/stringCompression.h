void stringCompression(char *stng){
	int i, ind = 1, count = 1, flag = 0;
	char temp, eval = stng[0];
	printf("Got %s\n", stng);
	for (i = 1; stng[i] != '\0'; i++){
		if (stng[i] != stng[i - 1]){
			if (count != 1){
				stng[ind] = count + '0';
				ind += 2;
				count = 1;
			}
			else
				ind++;
		}
		else
			count++;
	}
	if (count != 1){
		stng[ind] = count + '0';
		stng[ind + 1] = '\0';
	}
	else
		stng[ind - 1] = '\0';
	printf("Compressed %s\n", stng);
}

void testStringCompression(){
	int n;
	char *stng;
	printf("Enter String length\n");
	scanf_s("%d", &n);
	stng = (char*)malloc((n+5)*sizeof(char));
	printf("Enter string\n");
	scanf_s("%s", stng);
	stringCompression(stng);
}