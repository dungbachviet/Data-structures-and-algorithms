#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define TABLE_SIZE 13
#define PRIME 7

// Create Hash Table using Double Hashing mechanism
class DoubleHash 
{
	
	int *hashTable; // point to an array of hash table
	int curr_size; // current size of hash table

public:
	// Check if hash table is full
	bool isFull()
	{
		// if hash size reaches maximum size
		return (curr_size == TABLE_SIZE);
	}

	// calculate first hash
	int hash1(int key)
	{
		return (key % TABLE_SIZE);
	}

	// calculate second hash
	int hash2(int key)
	{
		return (PRIME - (key % PRIME));
	}

	// Constructor to initialize hash table
	DoubleHash()
	{
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable[i] = -1;
	}

	// Insert key into hash table
	void insertHash(int key)
	{
		// if hash table is full
		if (isFull())
			return;

		// get index from first hash
		int index = hash1(key);

		// if collision occurs
		if (hashTable[index] != -1)
		{
			// get index2 from second hash
			int index2 = hash2(key);
			int i = 1;
			while (1)
			{
				// get new index of combination from hash1 and hash2
				int newIndex = (index + i * index2) % TABLE_SIZE;

				if (hashTable[newIndex] == -1)
				{
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		else
			hashTable[index] = key;
		curr_size++;
	}

	// Dislay the hash table
	void displayHash()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (hashTable[i] != -1)
				cout << i << " --> " << hashTable[i] << endl;
			else
				cout << i << endl;
		}
	}

	// Check if key exists in hash table
	bool isExisted(int key)
	{
		int i = 0;
		int newIndex = (hash1(key) + i * hash2(key)) % TABLE_SIZE;

		while (1)
		{
			// Not found after TABLE_SIZE loops
			if (i == TABLE_SIZE) return false;

			if (hashTable[newIndex] == -1)
				return false;
			else if (hashTable[newIndex] == key)
				return true;
			
			// continue to find key in hash table
			i++;
			newIndex = (hash1(key) + i * hash2(key)) % TABLE_SIZE;
		}
	}

};

int main()
{
	int a[] = { 19, 27, 36, 10, 64, 15, 32, 32 };
	int n = sizeof(a) / sizeof(a[0]);

	DoubleHash h;
	for (int i = 0; i < n; i++)
		h.insertHash(a[i]);

	h.displayHash();

	cout << "Does 19 exist : " << h.isExisted(19) << endl;
	cout << "Does 100 exist : " << h.isExisted(100) << endl;
	cout << "Does 28 exist : " << h.isExisted(28) << endl;
	cout << "Does 10 exist : " << h.isExisted(10) << endl;


	getchar();
	return 0;
}