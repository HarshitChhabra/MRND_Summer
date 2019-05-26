auxNode* createLL(){
	int n = 6, i;
	int vals[] = { 1, 2, 3, 4, 5, 6 };
	auxNode **arr = (auxNode**)malloc(n*sizeof(auxNode*));
	auxNode* root = NULL, *temp;
	for (i = 0; i < n; i++){
		arr[i] = getNode(vals[i]);
		if (!root){
			root = arr[i];
			temp = arr[i];
		}
		else{
			temp->next = arr[i];
			temp = temp->next;
		}
	}
	arr[0]->random = arr[2];//1 to 3
	arr[1]->random = arr[3]; //2 to 4
	arr[2]->random = arr[4]; //3 to 5
	arr[4]->random = arr[3]; //5 to 4

	return root;
}

void cloneRandomLL(auxNode *root){
	auxNode *newRoot = NULL, *itr = root, *temp = NULL, *newItr = NULL;
	while (itr){
		/*		printf("check %d, ", itr->data);
		if (itr->random)
		printf("%d\n", itr->random->data);
		else
		printf("-1\n");*/

		if (!newRoot){
			newRoot = getNode(itr->data);
			temp = newRoot;
		}
		else{
			temp->next = getNode(itr->data);
			temp = temp->next;
		}
		itr = itr->next;
	}

	//Linear LL Created with new root

	std::unordered_map<auxNode*, auxNode*> map1;
	itr = root;
	newItr = newRoot;
	while (itr){
		map1[itr] = newItr;
		printf("%d %d\n", itr->data, map1[itr]->data);
		itr = itr->next;
		newItr = newItr->next;
	}
	itr = root;
	newItr = newRoot;
	while (itr){

		if (itr->random == NULL)
			newItr->random = NULL;
		else{
			newItr->random = map1[itr->random];
			//printf("check %d %d\n", itr->data,map1[itr]->data);
		}
		itr = itr->next;
		newItr = newItr->next;
	}
	newItr = newRoot;
	while (newItr){

		printf("Val: %d  ", newItr->data);
		if (!newItr->random)
			printf("no random\n");
		else
			printf("Random: %d\n", newItr->random->data);
		newItr = newItr->next;
	}

}
