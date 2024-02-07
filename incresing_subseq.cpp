#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long> &arr, long long index, long long prev, vector<vector<int>> &dp)
{
    long long n=arr.size();
    if (index < 0)
        return 0;

    if (dp[index][prev] != -1)
        return dp[index][prev];

    long long include = solve(arr, index - 1, prev, dp);
    long long exclude = 0;
    if (prev == n || arr[prev] > arr[index])
    {
        exclude = 1 + solve(arr, index - 1, index, dp);
    }
    return dp[index][prev] = max(include, exclude);
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    long long prev = n;
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));

    for (long long index = 0; index < n; index++)
    {
        for (long long prev = index + 1; prev <= n; prev++)
        {
            long long include = dp[index - 1][ prev];
            long long exclude = 0;
            if (prev == arr.size() || arr[prev] > arr[index])
            {
                exclude = 1 + dp[index - 1][index];
            }
             dp[index][prev] = max(include, exclude);
        }
    }

    cout << dp[n-1][n]<<endl;
    return 0;
}
