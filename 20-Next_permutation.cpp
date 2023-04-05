// Next permutation problem in O(n) and O(1) space
#include <iostream>
using namespace std;

// Shows the elements
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

// Function that reverses array
void reverse(int *A, int n)
{
    int j = 0;
    int tmp;
    for (int i = n; i > n / 2; i--)
    {
        tmp = A[n - j - 1];
        A[n - j - 1] = A[j];
        A[j] = tmp;
        j++;
    }
}

// Finds the next permutation
void nextPermutation(int *A, int n)
{
    int i, k, ind1, ind2;
    int flag, tmp;

    A[n] = 0; // Storing 0 to hold the conditions below
    // Finds the breakpoint ~ linearly traversing from behind
    for (i = n - 1; i >= 0; i--)
    {
        flag = 1;
        if (A[i] < A[i + 1])
        {
            ind1 = i; // Stores the index of breakpoint value
            flag = 0;
            break;
        }
    }

    // If breakpoint found then : 
    if (flag == 0)
    {
        // Finds the greater value compare to breakpoint value
        for (k = n - 1; k >= 0; k--)
        {
            if (A[ind1] < A[k])
            {
                ind2 = k; // Stores the index of greater value
                break;
            }
        }

        // Swaps the greater value to breakpoint value
        tmp = A[ind1];
        A[ind1] = A[ind2];
        A[ind2] = tmp;

        //  Before reversing find out the middle of the array according to new reverse part which is [ind1 + 1 to n-1] <---- or find out the middle of this part
        int newSizeCount = (n - 1) - ind1;

        // Reverses the ind1 + 1 part to n-1 ~ so to arrange the numbers for no next breakpoint
        int j = ind1 + 1;
        for (i = 0; i < newSizeCount / 2; i++)
        {
            tmp = A[n - 1];
            A[n - 1] = A[j];
            A[j] = tmp;
            j++;
        }
    }
    else
    {
        // If no breakpoint found, just reverse the whole array
        reverse(A, n);
    }

    // Prints the elements
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

// Driver code
int main()
{
    int A[] = {1, 3, 5, 4, 2};
    // int A[] = {5, 4, 3, 2, 1};
    int n = 5;

    printArray(A, n);
    cout << endl;
    nextPermutation(A, n);
    return 0;
}