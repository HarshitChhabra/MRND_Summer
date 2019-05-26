void findMergePt(sn *root){
	sn *slow = root, *fast = root;
	do {
		//printf("%d %d\n", slow->data, fast->data);
		slow = slow->next;
		fast = fast->next->next;
	} while (fast && fast->next && slow != fast);
	if (!fast || !fast->next)
		printf("No merge pt\n");
	else{
		while (root != slow){
			root = root->next;
			slow = slow->next;
		}
		printf("Merge pt: %d\n", root->data);
	}
}

void testMergePt(){
	sn *root = getSimpleNode(1);
	sn *node2 = getSimpleNode(2);
	sn *node3 = getSimpleNode(3);
	sn *node4 = getSimpleNode(4);
	sn *node5 = getSimpleNode(5);
	root->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//node5->next = node3;
	findMergePt(root);


}
