//Name: Nicholas Jones
//Date: March 24, 20202
//Course: CSCE 3110 Section 002
//Description: Perform a heap sort on an array using data from and input file and export sorted array to an output file

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Global functions
void heapSort(float arr[], int i);
void heap(float arr[], int n, int i);

int main()
{
    //Instantiating float arrays
    float arr[100];
    float out[100];

    //Instantiating strings
    string line;
    string num;

    char  c_line[10];
    char *pEnd;

    //Instantiating integers
    int pos  = 0;
    int size = 0; //number of integers from file

    //Opening input and output files
    ifstream myfile;
    ofstream outfile;

    myfile.open("data3.txt");
    outfile.open("out3.txt");

    //Putting values into array from input file
    if(myfile.is_open())
    {
        while(getline(myfile, line, ' '))
        {
	    strcpy(c_line, line.c_str());
            arr[size] = strtof(c_line, &pEnd);
            size++;
        }
    }
    else
    {
	    cout << "Error: File not open." << endl;
	    exit(1);
    }

    //Call Heap Sort
    heapSort(arr, size);

    //Print out sorted array to output file
    while(pos < size)
    {
        outfile << arr[pos] << endl;
        pos++;
    }

    //Close input and output files
    myfile.close();
    outfile.close();

    return 0;
}

//Move largest number
void heap(float arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left node is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right node is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        //Recall heap
        heap(arr, n, largest); 
    } 
} 
  
// Perform heap sort
void heapSort(float arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heap(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heap(arr, i, 0); 
    } 
} 


