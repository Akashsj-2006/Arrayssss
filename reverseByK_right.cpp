#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    k = k % n;

   
    reverseArray(arr, 0, n - 1);

    
    reverseArray(arr, 0, k - 1);

    reverseArray(arr, k, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}