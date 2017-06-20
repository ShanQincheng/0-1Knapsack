// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <algorithm>
#include <stack>


typedef struct item
{
	int itemWeight;
	int itemValue;
}Item;

using namespace std;


bool compareByWeight(const Item A, const Item B);
//void knapsack(int n, int w);


// TODO: reference additional headers your program requires here
