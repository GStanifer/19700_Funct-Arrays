/*
Program:  Assignment 9.c
Made by:  Garrett Stanifer
Date:  4/19/2021
Use functions and arrays for different purposes 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Elements 72

//Prototype functions below
void createArray(int arr[], int numElements);
void printArray(int arr[], int numElements);
int sequentialSearch(int arr[], int numElements, int s);
void bubbleSort(int arr[], int sorted[], int numElements);


int main()
{
	int s;
	int high = 300;
	int low = 1;
	int arr[Elements];
	int origArray[Elements];
	int sortedArray[Elements];
	int posArray[Elements];

	srand(time(NULL));
	createArray(arr, Elements);
	printArray(arr, Elements);
	s = sequentialSearch(arr, Elements, (rand() % high) + low);
	bubbleSort(arr, sortedArray, Elements);

	printf("\n\nThe sorted array is: \n");
	printArray(sortedArray, Elements);


	return 0;
}
//Creates an array of random values ranging from 1 to 300
void createArray(int arr[], int numElements)
{
	int k;
	for (k = 0; k < numElements; k++)
	{
		arr[k] = (rand() % (300) + 1);
		//If number is evenly divisible by 5,7, or 11 it is stored as a negative number
		if (arr[k] % 5 == 0 || arr[k] % 7 == 0 || arr[k] % 11 == 0)
		{
			arr[k] *= -1;
		}
	}
}
//Prints the array that was created, prints 10 values per line
void printArray(int arr[], int numElements)
{
	int k;
	for (k = 0; k < numElements; k++)
	{
		if (k % 10 == 0)  //Prints 10 values per line
		{
			printf("\n");
		}
		printf("%d ", arr[k]);
	}
}
//Does a linear search to determine if value entered is in the array
int sequentialSearch(int arr[], int numElements, int s)
{
	int k;
	for (k = 0; k < numElements; k++)
	{
		if (s == arr[k])
			return k;
		return -1;
	}
}
//Copies the original array into a new array, and sorts 2nd array in ascending order
void bubbleSort(int arr[], int sorted[], int numElements)
{
	for (int k = 0; k < numElements; k++)  //Using bubble sort algorithm
	{
		sorted[k] = arr[k];
	}
	for (int k=0;k<numElements-1;k++)
	{
		for (int b = 0; b < numElements - k - 1; b++)
		{
			if (sorted[b] > sorted[b + 1])
			{
				int temp = sorted[b];
				sorted[b] = sorted[b + 1];
				sorted[b + 1] = temp;
			}
		}
	}
}
