#include <iostream>
using namespace std;

void mergeAndDisplay(int *arr1, int *arr2, int n)
{
    int *merged = new int[2 * n];
    int i = 0, j = 0, k = 0;

    while (i < n && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        merged[k++] = arr1[i++];
    }

    while (j < n)
    {
        merged[k++] = arr2[j++];
    }

    cout << "Merged and Sorted Array: ";
    for (int i = 0; i < 2 * n; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

    delete[] merged;
}

int main()
{
    int n;

    cout << "Enter size of the arrays: ";
    cin >> n;

    int *arr1 = new int[n];
    int *arr2 = new int[n];

    cout << "Enter elements of the first sorted array (arr1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements of the second sorted array (arr2): ";
    for (int j = 0; j < n; j++)
    {
        cin >> arr2[j];
    }

    mergeAndDisplay(arr1, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}