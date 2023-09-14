//Name: Nicholas Jones
//Date: February 18, 2020
//Course: CSCE 3110 Section 002
//Description: Performs a merge sort on a list of numbers retrieved from a file.
//If the size is less than 8. If more than 8 it performs insertion sort.

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Functions
void mergeSort(string arr[], int l, int r);
void merge(string arr[], int l, int m, int r);
void insertionSort(string arr[], int n);

int main ()
{
 //Instantiate Variables
  string line;
  string filename;
  ifstream myfile;
  ofstream outfile;

  int pos = 0;

  string arr[500];

  //Open files to be used
  myfile.open("data1.txt");
  outfile.open("out1.txt");

  if (myfile.is_open())
  {
    while ( getline (myfile,line, ' ') )
    {
      arr[pos] = line;
      pos++;
    }
    myfile.close();
  }

  else {
    cout << "Unable to open file" << endl;
  }

 //Check to do Merge or Insertion Sort
 if( pos > 8)
 {
	insertionSort(arr, pos);
 }
 else
 {
	mergeSort(arr, 0, pos-1);
 }

 //Copy sorted array to outfile
 for(int i = 0; i < pos; i++)
 {
	outfile << arr[i] << endl;
 }

  outfile.close();

  return 0;
}


void merge(string arr[], int l, int m, int r)
{
	int n_one;
	int n_two;

	//Get sizes for the temp arrays
	n_one = m - l + 1;
	n_two = r - m;

	//Temp arrays
	string left_arr[n_one];
	string right_arr[n_two];

	//Copy data to temp arrays
	for(int i = 0; i < n_one; i++)
		left_arr[i] = arr[l + i];
	for(int j = 0; j < n_two; j++)
		right_arr[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	//Merge Arrays
	while(i < n_one && j < n_two)
	{
		if(left_arr[i] <= right_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else
		{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while(i < n_one)
	{
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while(j < n_two)
	{
		arr[k] = right_arr[j];
		j++;
		k++;
	}

}

void mergeSort(string arr[], int l, int r)
{
	if(l < r)
	{
		int mid = l + (r-l)/2;

		//Sort first and second half of arrays
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, mid, r);

	}
}

void insertionSort(string arr[], int n)
{
	int i;
	string node;
	int j;

	for(int i = 1;i < n; i++)
	{
		node = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > node)
	        {
        	        arr[j + 1] = arr[j];
                	j = j - 1;
        	}
		arr[j + 1] = node;

	}
}
