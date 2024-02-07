#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &arr, long long n)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (long long index = 1; index <= n; ++index)
    {
        for (long long prev = 0; prev <= n; ++prev)
        {
            long long include = dp[index - 1][prev];
            long long exclude = 0;

            if (prev == 0 || arr[prev - 1] > arr[index - 1])
            {
                exclude = 1 + dp[index - 1][index - 1];
            }

            dp[index][prev] = max(include, exclude);
        }
    }

    return dp[n][n];
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n) << endl;
    return 0;
}
