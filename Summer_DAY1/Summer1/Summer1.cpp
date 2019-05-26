// Summer1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "nodeCreations.h"
#include<unordered_map>
#include "cloneAuxiliaryLinkedList.h"
#include "reverse_K_Elements_LL.h"
#include "stringCompression.h"
#include "spiralMatrix.h"
#include "transposeMatrix.h"
#include "mergePoint.h"

sn* addingLLUtil(sn *root1, sn* root2, sn** ans,int *carry,int diff){
	int tempVal;
	sn *temp,*temp2;
	if (diff){
		temp= addingLLUtil(root1->next, root2, ans, carry, diff - 1);
		tempVal = (*carry);
		(*carry) = (tempVal + root1->data) / 10;
		temp2 = getSimpleNode((tempVal + root1->data)%10);

	}
	else{
		if (!root1->next && !root2->next){
			tempVal = (*carry);
			(*carry) = ((*carry) + root1->data + root2->data) / 10;
			//printf("Returning %d\n", (tempVal + root1->data + root2->data)%10);
			return getSimpleNode((tempVal + root1->data + root2->data) % 10);
		}
		/*else if (!root1->next && root2->next){
			temp = addingLLUtil(root1, root2->next, ans, carry);
			temp2 = getSimpleNode(((*carry) + root2->data) % 10);
			temp2->next = temp;
			(*carry) = ((*carry) + root2->data) / 10;
			//printf("Returning %d %d %d\n", (*carry),root2->data,temp2->data);
			return temp2;
		}
		else if (root1->next && !root2->next){
			temp = addingLLUtil(root1->next, root2, ans, carry);
			temp2 = getSimpleNode(((*carry) + root1->data) % 10);
			temp2->next = temp;
			(*carry) = ((*carry) + root1->data) / 10;
			//printf("Returning %d %d %d\n", (*carry),root2->data,temp2->data);
			return temp2;
		}*/
		temp = addingLLUtil(root1->next, root2->next, ans, carry,diff);
		//printf("check %d %d %d\n", root1->data, root2->data,(*carry));
		temp2 = getSimpleNode(((*carry) + root1->data + root2->data) % 10);
		temp2->next = temp;
		//printf("Returning %d\n", ((*carry) + root1->data + root2->data) % 10);
		(*carry) = ((*carry) + root1->data + root2->data) / 10;
		return temp2;
	}
}

void printLL(sn *root){
	while (root){
		printf("%d ", root->data);
		printf("\n");
		root = root->next;
	}
}

void addingLL(sn *root1, sn *root2){
	int len1=0, len2=0, maxLen,carry=0;
	sn **ans=NULL,*temp,*root;
	temp = root1;
	while (temp){
		len1++;
		temp = temp->next;
	}
	temp = root2;
	while (temp){
		len2++;
		temp = temp->next;
	}
	if (len1 > len2)
		root = addingLLUtil(root1, root2, ans, &carry, len1 - len2);
	else
		root = addingLLUtil(root2, root1, ans, &carry, len2 - len1);
	if (carry){
		temp = getSimpleNode(1);
		temp->next = root;
		root = temp;
	}
	while (root){
		printf("%d ", root->data);
		root = root->next;
	}
	
}

void testAddingLL(){

	int num1,num2,carry=0;
	sn *root1=NULL, *root2=NULL,*temp;
	printf("Enter two numbers\n");
	scanf_s("%d%d", &num1, &num2);
	while (num1){
		if (!root1)
			root1 = getSimpleNode(num1 % 10);
		else{
			temp = getSimpleNode(num1 % 10);
			temp->next = root1;
			root1 = temp;
		}
		num1 /= 10;
	}
	while (num2){
		if (!root2)
			root2 = getSimpleNode(num2 % 10);
		else{
			temp = getSimpleNode(num2 % 10);
			temp->next = root2;
			root2 = temp;
		}
		num2 /= 10;
	}
	printLL(root1);
	printLL(root2);
	addingLL(root1, root2);
}

void twoColourSort_Count(int *arr,int n){
	int ones = 0,i;
	for (i = 0; i < n; i++)
		ones += arr[i];
	for (i = 0; i < n; i++){
		if (i >= ones)
			arr[i] = 1;
		else
			arr[i] = 0;
	}
	printf("Result:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void twoColourSort_Swap(int *arr, int n){
	int front=0, end=n-1,i=0;
	while (front<end){
		if (arr[i] == 1){
			arr[i] = arr[end];
			arr[end] = 1;
			end--;
		}
		else{
			front++;
		}
		i++;
	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void testTwoColourSort(){
	int n, *arr,i;
	printf("Enter number of elements\n");
	scanf_s("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	printf("Enter values (Only 0s and 1s)\n");
	for (i = 0; i < n; i++){
		scanf_s("%d", &arr[i]);
		//printf("check %d\n", arr[i]);
	}
	twoColourSort_Count(arr, n);
	twoColourSort_Swap(arr, n);
}

void threeColourSort(int *arr,int n){
	int front = 0, mid=0,end = n - 1,i=0;
	while (mid <= end){
		if (arr[mid] == 0){
			arr[mid] = arr[front];
			arr[front] = 0;
			mid++;
			front++;
		}
		else if (arr[mid] == 1)
			mid++;
		else{
			arr[mid] = arr[end];
			arr[end] = 2;
			end--;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void testThreeColourSort(){
	int n, *arr, i;
	printf("Enter number of elements\n");
	scanf_s("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	printf("Enter values (Only 0s 1s and 2s)\n");
	for (i = 0; i < n; i++){
		scanf_s("%d", &arr[i]);
	}
	threeColourSort(arr, n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//cloneRandomLL(createLL());
	//testTransposeMatrix();
	//testSpiral();
	//testRevLL();
	//testTransposeMatrix();
	//testStringCompression();
	//testMergePt();
	//testTwoColourSort();
	testThreeColourSort();
	//testAddingLL();
	_getch();
	return 0;
}

