// Vijit Deogade 2024BMS028 HeapSort Implementation
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printer(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void heapify(int arr[], int i, int n, int a)
{
    if (a == 0)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            heapify(arr, smallest, n, a);
        }
    }
    if (a == 1)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, largest, n, a);
        }
    }
}
void heapm(int arr[], int n, int a)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, n, a);
    }
}

void hsorter(int arr[], int n, int a)
{
    // printf("sorting started");
    heapm(arr, n, a);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i, a);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        // printf("Enter element: ");
        arr[i]=rand()%100;
                // scanf("%d", &arr[i]);
    }
    // int a=1;
    printf("descending ");
    hsorter(arr, n, 0);
    printer(arr, n);
    printf("ascending ");
    hsorter(arr, n, 1);
    printer(arr, n);

    return 0;
}

