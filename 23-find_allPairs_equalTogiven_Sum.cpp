#include <bits/stdc++.h>
using namespace std;

// Bad(Naive) Apprcoach ~ T.C - O(n^2), S.C - O(1)
void findPairs(int *A, int n, int sum)
{
    cout << "Pairs Are : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == sum)
            {
                cout << "(" << A[i] << ", " << A[j] << ")"
                     << "  ";
            }
        }
    }
}

// Using unordered map ~ T.C - O(n), S.C - O(n), as we have created map thus Space is O(n)
int findPairsCount(int *A, int n, int sum)
{

    unordered_map<int, int> m; // Created a m named map to store the first integer here as keys and second integer as no. of occurences of those keys

    int count = 0; // Stores count of pairs
    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        if (m.find(sum - A[i]) != m.end())
        {
            // sum-A[i] which means it finds the value in the map to make the perfect pair with the current index value which is equal to sum

            int b = sum - A[i]; // Another pair value which has to be found
            count += m[b];      // If value is found in the map then sum the occurence/frequency of that value to count
        }
        m[A[i]]++; // And then store the current index value of array to map by increasing its current occurences / store kr denge map me uske occurences ke bdhane ke saath
    }
    return count;
}

// Driver code
int main()
{
    // int A[] = {8, 7, 2, 5, 3, 1};
    int A[] = {1, 5, 7, -1, 5};
    int sum = 6;
    int n = sizeof(A) / sizeof(A[0]);
    findPairs(A, n, sum);
    cout << endl;
    cout << "Pairs count are : " << findPairsCount(A, n, sum);
    return 0;
}