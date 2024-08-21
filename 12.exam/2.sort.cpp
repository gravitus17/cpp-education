#include <iostream>
using namespace std;


void heapify(float arr[], int N, int i)
{

    // Initialize largest as root
    int smallest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] < arr[smallest])
        smallest = r;

    // If largest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, smallest);
    }
}

// Main function to do heap sort
void heapSort(float arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(float arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    float arr[15];

    for (int i= 0; i < 15; i++ )
        cin >> arr[i];



    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
    
}



