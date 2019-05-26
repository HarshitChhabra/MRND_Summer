// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <tchar.h>

typedef struct node node;
typedef struct simpleNode simpleNode;
typedef simpleNode sn;


struct simpleNode{
	int data;
	sn *next;
};

struct auxNode{
	int data;
	auxNode* next;
	auxNode *random;
};



// TODO: reference additional headers your program requires here
