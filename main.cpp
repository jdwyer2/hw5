#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include<array>

using namespace std;

bool read_file(char * file_name,int  w[]);
void bubbleSort(int num[]);
void quickSort(int arr[], int left, int right, int &exchanges, int &comparisons);
void insertion_sort (int arr[], int length);
void shellsort(int v[], int n);
void merge(int arr[], int l, int m, int r, int &exchanges, int &comparisons);
void mergeSort(int arr[], int l, int r, int &exchanges, int &comparisons);
void printVector(int vect[]);

int main()
{
    int FewUnique[10000], NearlySorted[10000], Random[10000], Reversed[10000];
    int exchanges, comparisons = 0;
    int * mypointer = FewUnique;
    read_file("FewUnique.txt", mypointer);
    cout<<"Few Unique: \n";
    bubbleSort(mypointer);
    //printVector(mypointer);
    mypointer=FewUnique;
    read_file("FewUnique.txt", mypointer);
    //printVector(mypointer);
    cout<<"Few Unique: \n";
    insertion_sort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=FewUnique;
    read_file("FewUnique.txt", mypointer);
    cout<<"Few Unique: \n";
    shellsort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=FewUnique;
    read_file("FewUnique.txt", mypointer);
    quickSort(mypointer, 0, 10000 , exchanges, comparisons);
    cout<<"Few Unique: \n";
    cout<<"Number of exchanges for a quick sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a quick sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    mypointer=FewUnique;
    read_file("FewUnique.txt", mypointer);
    mergeSort(mypointer, 0, 10000, exchanges, comparisons);
    cout<<"Few Unique: \n";
    cout<<"Number of exchanges for a merge sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a merge sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    delete mypointer;
    cout<<"\n";

    mypointer = NearlySorted;
    read_file("NearlySorted.txt", mypointer);
    cout<<"Nearly Sorted: \n";
    bubbleSort(mypointer);
    //printVector(mypointer);
    mypointer=NearlySorted;
    read_file("NearlySorted.txt", mypointer);
    //printVector(mypointer);
    cout<<"Nearly Sorted: \n";
    insertion_sort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=NearlySorted;
    read_file("NearlySorted.txt", mypointer);
    cout<<"Nearly Sorted: \n";
    shellsort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=NearlySorted;
    read_file("NearlySorted.txt", mypointer);
    quickSort(mypointer, 0, 10000 , exchanges, comparisons);
    cout<<"Nearly Sorted: \n";
    cout<<"Number of exchanges for a quick sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a quick sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    mypointer=NearlySorted;
    read_file("NearlySorted.txt", mypointer);
    mergeSort(mypointer, 0, 10000, exchanges, comparisons);
    cout<<"Nearly Sorted: \n";
    cout<<"Number of exchanges for a merge sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a merge sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    delete mypointer;
    cout<<"\n";

    mypointer = Random;
    read_file("Random.txt", mypointer);
    cout<<"Random: \n";
    bubbleSort(mypointer);
    //printVector(mypointer);
    mypointer=Random;
    read_file("Random.txt", mypointer);
    //printVector(mypointer);
    cout<<"Random: \n";
    insertion_sort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=Random;
    read_file("Random.txt", mypointer);
    cout<<"Random: \n";
    shellsort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=Random;
    read_file("Random.txt", mypointer);
    quickSort(mypointer, 0, 10000 , exchanges, comparisons);
    cout<<"Random: \n";
    cout<<"Number of exchanges for a quick sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a quick sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    mypointer=Random;
    read_file("Random.txt", mypointer);
    mergeSort(mypointer, 0, 10000, exchanges, comparisons);
    cout<<"Random: \n";
    cout<<"Number of exchanges for a merge sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a merge sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    delete mypointer;
    cout<<"\n";

    mypointer = Reversed;
    read_file("Reversed.txt", mypointer);
    cout<<"Reversed: \n";
    bubbleSort(mypointer);
    //printVector(mypointer);
    mypointer=Reversed;
    read_file("Reversed.txt", mypointer);
    //printVector(mypointer);
    cout<<"Reversed: \n";
    insertion_sort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=Reversed;
    read_file("Reversed.txt", mypointer);
    cout<<"Reversed: \n";
    shellsort(mypointer, 10000);
    //printVector(mypointer);
    mypointer=Reversed;
    read_file("Reversed.txt", mypointer);
    quickSort(mypointer, 0, 10000 , exchanges, comparisons);
    cout<<"Reversed: \n";
    cout<<"Number of exchanges for a quick sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a quick sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    mypointer=Reversed;
    read_file("Reversed.txt", mypointer);
    mergeSort(mypointer, 0, 10000, exchanges, comparisons);
    cout<<"Reversed: \n";
    cout<<"Number of exchanges for a merge sort: "<<exchanges<<endl;
    cout<<"Number of comparisons for a merge sort: "<<comparisons<<endl;
    exchanges = 0;
    comparisons = 0;
    delete mypointer;
    cout<<"\n";


    /*
    read_file("FewUnique.txt", FewUnique3);
    insertion_sort(FewUnique3, FewUnique3.size());
    read_file("FewUnique.txt", FewUnique4);
    shellsort(FewUnique4, FewUnique4.size());
    read_file("FewUnique.txt", FewUnique5);
    mergeSort(FewUnique5,0,FewUnique5.size());
    */
    read_file("NearlySorted.txt", NearlySorted);
    read_file("Random.txt", Random);
    read_file("Reversed.txt", Reversed);

    //printVector(FewUnique);


    /*cout<<FewUnique.size()<<endl;
    cout<<NearlySorted.size()<<endl;
    cout<<Random.size()<<endl;
    cout<<Reversed.size()<<endl;
    */

    return 0;
}
//BubbleSort
void bubbleSort(int num[])
{
        int i, j;
      int temp;
      int comparisons, exchanges;
      comparisons = exchanges = 0;
      int numLength = 10000;
      for(i = 1; (i </*=*/ numLength); i++) //traverse array starting at second element
     {
          for (j=0; j < (numLength -1); j++) //traverse array from begininng till second to last element
         {
                comparisons++;
               if (num[j+1] < num[j])      // Test for ascending
              {
                    temp = num[j];             // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    exchanges++;         // indicates that a swap occurred.
               }
          }
     }
     cout<<"Number of exchanges for a bubble sort: "<<exchanges<<endl;
     cout<<"Number of comparisons for a bubble sort: "<<comparisons<<endl;
     return;   //arrays are passed to functions by address; nothing is returned
}
//Insertion SOrt
void insertion_sort (int arr[], int length){
	 	int j, temp;
	 	int comparisons, exchanges;
      comparisons = exchanges = 0;

	for (int i = 0; i < length; i++){ //traverse array
		j = i;
		comparisons++;

		while (j > 0 && arr[j] < arr[j-1]){ //compare elements for ascending
			  temp = arr[j];  //swap elements
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  exchanges++;
			  comparisons++;
			  }
		}
    cout<<"Number of exchanges for an insertion sort: "<<exchanges<<endl;
     cout<<"Number of comparisons for an insertion sort: "<<comparisons<<endl;
}
void quickSort(int arr[], int left, int right, int &exchanges, int &comparisons) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
     //run until low is less than high
      while (i <= j) {
            while (arr[i] < pivot) //
                  i++;
                  comparisons++;
            while (arr[j] > pivot)
                  j--;
                  comparisons++;
            if (i <= j) { //swap elements
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
                  exchanges++;
            }
      };
      /* recursion */
      if (left < j) //recursion
            quickSort(arr, left, j, exchanges, comparisons);
      if (i < right) //recursion
            quickSort(arr, i, right, exchanges, comparisons);
     //cout<<"Number of exchanges for a quick sort: "<<exchanges<<endl;
     //cout<<"Number of comparisons for a quick sort: "<<comparisons<<endl;
}
void shellsort(int v[], int n)
{
    int comparisons, exchanges;
      comparisons = exchanges = 0;
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2){ //make gap half the length
        for (i = gap; i < n; i++){
            comparisons++;
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) { //compare elements that are gap distance away, decrement gap
                temp = v[j]; //swap
                v[j] = v[j+gap];
                v[j+gap] = temp;
                exchanges ++;
                comparisons++;
            }
        }
    }
    cout<<"Number of exchanges for a shell sort: "<<exchanges<<endl;
     cout<<"Number of comparisons for a shell sort: "<<comparisons<<endl;
}
void merge(int arr[], int l, int m, int r, int&exchanges, int&comparisons)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        comparisons ++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            exchanges++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            exchanges++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int &exchanges, int &comparisons)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m, exchanges, comparisons);
        mergeSort(arr, m+1, r, exchanges, comparisons);
        merge(arr, l, m, r, exchanges, comparisons);
    }
}
bool read_file(char * file_name,int w[])
{
    int i = 0;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) return false;
    char * word = new char [100];
    int s_word;
    while(in.peek()!=EOF)
    {
        in.getline(word,100,' ');
        s_word=atoi(word);
        //s_word=(int)word;
        //w.push_back(s_word);
        //w.push_back(word);
        w[i] = s_word;
        i++;
    }
    in.clear();
    in.close();
    return true;
}
void printVector(int vect[])
{
    for (int i =0; i <10000; i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n";
}
