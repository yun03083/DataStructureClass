#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

void insertionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for (int j = i+1; j >= 0; j--)
        {
            if(arr[j-1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
            }
            else
            {
                continue;
            }
        }
    }
}

void bubbleSort(int arr[], int size)
{
    bool needSwap;
    do {
        needSwap = false;
        for (int i = 1; i < size; i++)
        {
            if (arr[i-1] > arr[i])
            {
                swap(arr[i-1], arr[i]);
                needSwap = true;
            }
        }
    }while(needSwap);
}

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void quickSort(int arr[], int size)
{
    int pivot = arr[0];
    int cursor = 0;

    for(int i = 1; i < size; i++)
    {
        if (pivot > arr[i])
        {
            cursor++;
            swap(arr[cursor], arr[i]);
        }
    }

    swap(arr[0], arr[cursor]);

    if(cursor > 0)
    {
        quickSort(arr,cursor);
    }

    if((cursor + 1) < size - 1)
    {
        quickSort(arr + cursor + 1, size - cursor - 1);
    }
}

void merge(int arr[], int left, int mid, int right, int size)
{
    int i, j, k;

    i = left;
    j = mid + 1;
    k = left;

    int tmp_arr[size];

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            tmp_arr[k] = arr[i];
            i++;
        }
        else
        {
            tmp_arr[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        for(int m = j; m <= right; m++)
        {
            tmp_arr[k] = arr[m];
            k++;
        }
    }
    else
    {
        for(int m = i; m <= mid; m++)
        {
            tmp_arr[k] = arr[m];
            k++;
        }
    }

    for(int m = left; m <= right; m++)
    {
        arr[m] = tmp_arr[m];
    }
}

void mergeSort(int arr[], int left, int right, int size)
{
    int mid = 0;

    if(left < right)
    {
        mid = (left + right) / 2;

        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid+1, right, size);

        merge(arr, left, mid, right, size);
    }
}

void heapify(int arr[], int size, int rootIndex)
{
    int leftChildIndex = (rootIndex + 1) * 2 - 1;
    int rightChildIndex = (rootIndex + 1) * 2;
    int largest = rootIndex;

    if(leftChildIndex < size && arr[leftChildIndex] > arr[largest])
    {
        largest = leftChildIndex;
    }
    if(rightChildIndex < size && arr[rightChildIndex] > arr[largest])
    {
        largest = rightChildIndex;
    }

    if (largest != rootIndex)
    {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    for(int i = size/2 - 1; i>=0 ; i--)
    {
        heapify(arr, size, i);
    }
    for(int i = size - 1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int size, int digit)
{
    int output[size] = {0,};
    int count[100000] = {0,};
    int i = 0;

    for(i = 0; i < size; i++)
    {
        count[ (arr[i]/digit)%10 ]++;
    }

    for(i = 1; i < 100000; i++)
    {
        count[i] += count[i-1];
    }

    for(i = size - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/digit)%10 ] - 1] = arr[i];
        count[ (arr[i]/digit)%10 ]--;
    }

    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for(int digit = 1; max/digit > 0; digit *= 10)
    {
        countSort(arr, n, digit);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);

    string text;
    getline(in,text);
    const char* tempSize = text.c_str();

    int arraySize = atoi(tempSize);

    int arr[arraySize] = {0,};
    int count = 0;

    while(true)
    {
        getline(in,text);
        if(text == "-1")
        {
            break;
        }

        const char* value = text.c_str();
        string num;
        while(*value)
        {
            if(isdigit(*value))
            {
                num += *value;
            }
            else
            {
                const char* c = num.c_str();
                arr[count] = atoi(c);
                num = "";
                count++;
            }
            value++;
        }
        cout << endl;
    }

    in.close();

    int arrInsertion[arraySize] = {0,};
    int arrBubble[arraySize] = {0,};
    int arrSelection[arraySize] = {0,};
    int arrQuick[arraySize] = {0,};
    int arrMerge[arraySize] = {0,};
    int arrHeap[arraySize] = {0,};
    int arrRadix[arraySize] = {0,};

    memcpy(arrInsertion,arr,arraySize*sizeof(int));
    memcpy(arrBubble,arr,arraySize*sizeof(int));
    memcpy(arrSelection,arr,arraySize*sizeof(int));
    memcpy(arrQuick,arr,arraySize*sizeof(int));
    memcpy(arrMerge,arr,arraySize*sizeof(int));
    memcpy(arrHeap,arr,arraySize*sizeof(int));
    memcpy(arrRadix,arr,arraySize*sizeof(int));



    clock_t sInsertion, eInsertion, sBubble, eBubble, sSelection, eSelection, sQuick, eQuick, sMerge, eMerge, sHeap, eHeap, sRadix, eRadix;
    double InsertionWork_time, BubbleWork_time, SelectionWork_time, QuickWork_time, MergeWork_time, HeapWork_time, RadixWork_time;



    sInsertion = clock();
    insertionSort(arrInsertion, arraySize);
    eInsertion = clock();

    InsertionWork_time = (double)(eInsertion-sInsertion)/CLOCKS_PER_SEC;



    sBubble = clock();
    bubbleSort(arrBubble, arraySize);
    eBubble = clock();

    BubbleWork_time = (double)(eBubble-sBubble)/CLOCKS_PER_SEC;



    sSelection = clock();
    selectionSort(arrSelection, arraySize);
    eSelection = clock();

    SelectionWork_time = (double)(eSelection-sSelection)/CLOCKS_PER_SEC;



    sQuick = clock();
    quickSort(arrQuick, arraySize);
    eQuick = clock();

    QuickWork_time = (double)(eQuick-sQuick)/CLOCKS_PER_SEC;



    sMerge = clock();
    mergeSort(arrMerge, 0, arraySize-1, arraySize);
    eMerge = clock();

    MergeWork_time = (double)(eMerge-sMerge)/CLOCKS_PER_SEC;



    sHeap = clock();
    heapSort(arrHeap, arraySize);
    eHeap = clock();

    HeapWork_time = (double)(eHeap-sHeap)/CLOCKS_PER_SEC;




    sRadix = clock();
    radixSort(arrRadix, arraySize);
    eRadix = clock();

    RadixWork_time = (double)(eRadix-sRadix)/CLOCKS_PER_SEC;


    cout << "insertion time: " << InsertionWork_time << endl;
    cout << "bubble time: " << BubbleWork_time << endl;
    cout << "selection time: " << SelectionWork_time << endl;
    cout << "quick time: " << QuickWork_time << endl;
    cout << "merge time: " << MergeWork_time << endl;
    cout << "heap time: " << HeapWork_time << endl;
    cout << "radix time: " << RadixWork_time << endl;

    return 0;
}
