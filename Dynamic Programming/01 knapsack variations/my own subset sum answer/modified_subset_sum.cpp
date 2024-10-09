// this is a recursive subset sum solution with My modifications

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

class ModifiedSubsetSum
{
public:
    bool solve(int n, int sum, int arr[])
    {
        // base cases
        if (sum == 0)
            return true;
         // I added the if(sum < 0) return false; line to Aditya Verma's code
        if (sum < 0 || n == 0)
            return false;

        if (arr[n - 1] <= sum)
        {
            // take or not take
            return solve(n - 1, sum - arr[n - 1], arr) || solve(n - 1, sum, arr);
        }
        else
        {
            return solve(n - 1, sum, arr);
        }
    }
};

signed main()
{
    vector<vector<int>> vec = {
        {3, 4, 5, 2},             // yes
        {3, 34, 4, 12, 5, 2},     // yes
        {3, 34, 4, 12, 5, 2},     // no
        {4, 3, 2, 1},             // yes
        {2, 5, 1, 6, 7},          // no
        {9, 1, 2, 1, 3},          // yes
        {1, 7, 2, 9, 10},         // no
        {31, 32, 33, 35, 4},      // no
        {1, 1, 1, 1, 1, 1, 1, 1}, // yes
        {1, 2, 1, 2},             // yes
    };
    // int arr[][] cannot be used for jagged arrays (arrays of arrays where
    //  each sub array is of different length)
    int sums[10] = {9, 9, 30, 5, 4, 7, 6, 5, 8, 5};

    ModifiedSubsetSum ob;
    for (int i = 0; i < 10; i++)
    {
        int n = vec[i].size();
        int *arr = vec[i].data();
        int sum = sums[i];

        bool ans = ob.solve(n, sum, arr);

        cout << "-----------------" << endl;
        cout << "This is the " << i << "th test case" << endl;
        if (ans)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    return 0;
}