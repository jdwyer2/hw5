//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void bubblesort (int A[], int n);
void insertionsort(int A[], int n);
void quicksort(int a[], int left, int right);
void shellsort(int A[], int n);
void mergesort(int *a, int low, int high);
int comparisons = 0;
int exchanges = 0;

bool file_to_array(string file_name, int *& numbers)
{
    ifstream thisfile;
    thisfile.open (file_name.c_str());

    if(!thisfile.is_open())
    {
        cout << "Yo, can't find your file!" << file_name << endl;
        cout << "Check the location, bro! \n";
        return false;
    }
    string temp;
    string file_content="";
    while(thisfile.peek()!=EOF)
    {
        thisfile>>temp;
        file_content += temp + " ";
    }
    thisfile.clear();
    thisfile.close();

    vector<string> lines;
    temp= "";
    for( int i = 0; i < file_content.length();i++)
    {
        if (file_content[i] == ' ')
        {
            lines.push_back(temp);
            temp= "";
        }
        else
        {
            temp +=file_content[i];
        }
    }
    if(numbers!=NULL) delete numbers;
   numbers = new int[lines.size()];
   for(int i=0; i<lines.size(); i++)
    {
        numbers[i]= atoi(lines[i].c_str());
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int * allNumbers;
    string fileNames[4];
    fileNames[0] = "FewUnique.txt";
    fileNames[1] = "NearlySorted.txt";
    fileNames[2] = "Random.txt";
    fileNames[3] = "Reversed.txt";
    //int * test=file_to_array("Random.txt");

    for(int i= 0;i<4; i++)
    {
       /*file_to_array(fileNames[i],allNumbers);
       bubblesort(allNumbers,10000);
       cout << comparisons << endl;
       cout << exchanges << endl;*/

       /*file_to_array(fileNames[i],allNumbers);
       insertionsort(allNumbers,10000);
       cout << comparisons << endl;
       cout << exchanges << endl;*/

       //int nums[] = {1,13,4,6,4,33,5,25,7,1};
       //quicksort(nums,1,10);

       file_to_array(fileNames[i], allNumbers);
       quicksort(allNumbers,0,10000);
       cout << comparisons << endl;
       cout << exchanges << endl;

       /*file_to_array(fileNames[i],allNumbers);
       shellsort(allNumbers,10000);
       cout << comparisons << endl;
       cout << exchanges << endl;*/

       /*file_to_array(fileNames[i],allNumbers);
       mergesort(allNumbers,0,10000);
       cout << comparisons << endl;
       cout << exchanges << endl;*/

    }
}

void bubblesort (int A[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            comparisons++;
            if(A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                exchanges++;
            }
        }
    }
}

void insertionsort(int A[], int n)
{
    int i, j, element;
    for(i = 1; i < n; i++)
    {
        element = A[i];
        j = i;
        comparisons++;
        while ((j > 0) && (A[j - 1] > element))
        {
            comparisons++;
            exchanges++;
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = element;
    }
}

int partition(int a[], int left, int right, int pivotIndex)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot)
        {
            left++;
            comparisons++;
        }
        while (a[right] > pivot)
        {
            right--;
            comparisons++;
        }

        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);
            exchanges++;
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}


void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
}

void shellsort(int A[], int n)
{
    int temp, gap, i;
    int swapped;
    gap = n/2;
    do
    {
        do
        {
            swapped = 0;
            for(i = 0; i < n - gap; i++)
            {
                comparisons++;
                if(A[i] > A[i + gap])
                {
                    exchanges++;
                    temp = A[i];
                    A[i] = A[i + gap];
                    A[i + gap] = temp;
                    swapped = 1;
                }
            }
        }
        while(swapped == 1);
    }
    while((gap = gap/2) >= 1);
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[10000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        comparisons++;
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
            comparisons++;
            exchanges++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            exchanges++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
