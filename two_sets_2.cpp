#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int solve(long long sum, long long n, vector<vector<long long>> &dp) {
    if (sum == 0) return 1;
    if (n == 0 || sum<0) return 0;
    if (dp[n][sum] != -1) return dp[n][sum];

    long long include = solve(sum - n, n - 1, dp) % MOD;
    long long exclude = solve(sum, n - 1, dp) % MOD;

    return dp[n][sum] = (include + exclude) % MOD;
}

int main() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "0";
        return 0;
    }

    sum /= 2;
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, -1));

    cout << solve(sum, n, dp) / 2;
   
    
    return 0;
}
