sn* getSimpleNode(int val){
	sn *temp = (sn*)malloc(sizeof(sn));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

auxNode* getNode(int val){
	auxNode *temp = (auxNode*)malloc(sizeof(auxNode));
	temp->data = val;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}