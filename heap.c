/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 * 	Version: Feb 1, 2025
 *      Author: Annika Laberge
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n); // TODO - BuildHeap on the heap

	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// Heapify() every element from A[n/2] down-to A[0]
	int current = n/2;
	while (current >= 0){
		heapify(A, current, n);
		current++;
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	if (i > (n - 1))
	{
		return;
	}
	int leftChild = 2 * (i + 1) - 1; // TODO - get index of left child of element i
	if (leftChild > n - 1)
	{
		return; // We've hit a leaf
	}
	int rightChild = 2 * (i + 1); // TODO - get index of right child of element i
	if (rightChild > n - 1)
	{
		rightChild = NULL; // No right child, set to null
	}

	int smaller = NULL;

	if (rightChild == NULL)
	{ // Check to make sure there is a right child
		smaller = leftChild;
	}
	else if (A[leftChild].salary < A[rightChild].salary)
	{						 // Determine which child has a smaller salary. 
		smaller = leftChild; //We'll call the index of this element: "smaller"
	}
	else
	{
		smaller = rightChild;
	}

	if (A[i].salary > A[smaller].salary)// Recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	{
		swap(i, smaller);
		heapify(A, smaller, n);
	}
	else // We've percolated down to the correct position
	{
		return;
	}										//			Then recursively heapify A[smaller].
	// Continue recursion as long as i is within range AND either right_child and left_child are still within range.
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// TODO
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	// TODO
}
