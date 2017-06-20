// 0-1Knapsack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int W = 0; // Knapsack weight, can carry weight
	int n = 0; // total number of items
	vector<Item> items;  // store all items' weight and value

	scanf_s("%d", &W); // input can carry weight
	rewind(stdin);
	scanf_s("%d", &n); // input the number of items
	
	for (int i = 0; i < n; i++)
	{
		int itemWeight, itemValue;
		Item newItem;
		scanf_s("%d %d", &itemWeight, &itemValue); // input one pair of item's properties
		newItem.itemWeight = itemWeight;
		newItem.itemValue = itemValue;

		items.push_back(newItem); 
	}
	int** c; // DP table, create a ( n + 1 ) rows , ( W + 1 ) colummns table
	bool** takeItems; // determine each item whether take it or not
	c = (int**)calloc(n + 1, sizeof(int *));
	takeItems = (bool**)calloc(n + 1, sizeof(bool *));
	for (int i = 0; i < n + 1; i++)
	{
		c[i] = (int *)calloc(W + 1, sizeof(int));
		takeItems[i] = (bool *)calloc(W + 1, sizeof(bool));
	}
	// initial table as c[n+1][W+1] = 0 when n == 0 or i == 0
	for (int i = 0; i < n + 1; i++)
	{
		c[i][0] = 0;
	}
	for (int i = 0; i < W + 1; i++)
	{
		c[0][i] = 0;
	}

	// exhaustive loop for every items and every weights
	for(int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (items[i-1].itemWeight > j)	// if Wi > W
				c[i][j] = c[i - 1][j];
			else {	// if Wi <= W
				c[i][j] = max(c[i - 1][j], c[i - 1][j - items[i - 1].itemWeight] + items[i - 1].itemValue ); 
				if ((c[i - 1][j - items[i - 1].itemWeight] + items[i - 1].itemValue) > c[i - 1][j]) // if take the items total value will be higher
					takeItems[i][j] = true;  // take the item
				else 
					takeItems[i][j] = false;
			}
		}
	}

	
	stack<int> printTakeItems;
	for (int i = n, j = W; i >= 0; i--)
	{
		if (takeItems[i][j]) // if current item has been taken
		{
			//cout << i << ", ";
			printTakeItems.push(i);
			j = j - items[i - 1].itemWeight; // total weight the thief can taken away decrease current item's weight
		}
	}

	cout << "Total Value = " << c[n][W] << endl;
	cout << "Items ";
	while (!printTakeItems.empty())
	{
		cout << printTakeItems.top() << ", ";
		printTakeItems.pop();
	}
	cout << '\b' << '\b'; // Cursor moves 2 position backwards
	cout << " " << endl; // Overwrites character ',' with space


	system("pause");

    return 0;
}


