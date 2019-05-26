void revLL(sn *root, int k){
	int kCopy = k;
	int LL_Len = 7;
	sn *prev = NULL, *next = NULL, *firstOccur = root, *lastOccur = NULL, *nRoot = NULL;
	while (root){

		next = root->next;
		root->next = prev;
		prev = root;
		if (next)
			root = next;
		k--;
		if (k == 0){
			firstOccur->next = next;
			if (!nRoot)
				nRoot = prev;
			else
				lastOccur->next = prev;
			prev = firstOccur;
			lastOccur = firstOccur;
			firstOccur = next;
			k = kCopy;
			//break;
		}
		LL_Len--;
		if ((LL_Len < kCopy && k == kCopy) || !next)
			break;

	}
	if (nRoot)
		root = nRoot;
	while (root){
		printf("%d\n", root->data);
		root = root->next;
	}
}

void testRevLL(){
	sn *root = NULL, *temp;
	int n = 7, i;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (i = 0; i < n; i++){
		if (!root){
			root = getSimpleNode(arr[i]);
			temp = root;
		}
		else{
			temp->next = getSimpleNode(arr[i]);
			temp = temp->next;
		}
	}
	//If condition if the length is less or greater than length
	revLL(root, 2);
}