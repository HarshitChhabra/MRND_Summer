typedef struct node node;

struct node{
	int data;
	node *next;
};

node* getNode(int val){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

node* reverseLLRecursive(node *root, node *mainRoot, node **newRoot){
	node *returned;
	if (!root->next || !root){
		(*newRoot) = root;
		return root;
	}
	returned = reverseLLRecursive(root->next, mainRoot, newRoot);
	returned->next = root;
	if (root == mainRoot)
		root->next = NULL;
	return root;
}

void testRevLLRecursive(){
	node *newRoot;
	node *root = getNode(1);
	node *node2 = getNode(2);
	node *node3 = getNode(3);
	node *node4 = getNode(4);
	node *node5 = getNode(5);
	root->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	reverseLLRecursive(root, root, &newRoot);
	while (newRoot){
		printf("%d ", newRoot->data);
		newRoot = newRoot->next;
	}

	printf("\n");
}
