#include <bits/stdc++.h>
using namespace std;

void printArray(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    return a;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

int MinDiff(int *A, int n, int k)
{
    sort(A, A + n);
    int oDiff = A[n - 1] - A[0]; // Gives the original difference between max and min height
    int low = A[0] + k;          // increasing the first element by k
    int high = A[n-1] - k;         // increasing the last element by k
    int minimum, maximum;
    // Will find maximum and minimum in each iteration by corrosponding kth increament and decreament then it will find the minimum which will became the new oDiff of ours
    for (int i = 0; i < n - 1; i++)
    {
        minimum = min(low, A[i + 1] - k); // Same way decreament of this A[i+1] element, if we see to the [high] last element in which we are decreamenting by k, its also the same way here

        maximum = max(high, A[i] + k); // Same way increament of this A[i] element, if we see to the [low]first element in which we are increamenting by k, its also the same way here

        if (minimum < 0)
        {
            continue;
        }
        oDiff = min(oDiff, maximum - minimum); // Updating the oDiff by comparing that coming new - {max-min} with our first oDiff, which gives the actual minimized differenced value between them
    }
    return oDiff;
}

int main()
{
    int A[] = {1, 5, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 2;
    printArray(A, n);
    cout << "  ";
    cout << "K = " << k << endl;
    cout << "The minimum difference between height is : " << MinDiff(A, n, k);
    return 0;
}