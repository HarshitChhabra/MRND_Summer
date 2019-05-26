// summer_DAY2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<unordered_map>
#include<set>
#define ModVal 1000000007
#include "Fibonacci.h"
#include "stairsTillK.h"
#include "ArrayAddition_Recursion.h"
#include "APowerN.h"
#include "LogNFibonacci.h"
#include "findStringMatrix.h"
#include "DLLMergeSort.h"
#include "permutations.h"
#include "printNDigitNumbers.h"
#include "recursiveLLReversal.h"


char getChar(int val){
	switch (val){
		case 0: return 'O';
		case 1: return '1';
		case 2: return '2';
		case 3: return 'E';
		case 4: return 'h';
		case 5: return '5';
		case 6: return '9';
		case 7: return 'L';
		case 8: return '8';
		case 9: return '6';
		
	}
}

void reverseLL(){

}


int _tmain(int argc, _TCHAR* argv[]){

	int a=5, n=3,i;

	//testPermutations();
	
	//testLogNFib();
	//testStngMatrixSearch();

	//testStairs();
	//testNDigitPrint();
	
	//testMergeSort();
	//testArrayAdditionRecursion();

	testRevLLRecursive();

	/**/
	_getch();
	return 0;
}

