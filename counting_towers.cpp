#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;



int main(){
    long long t; cin>>t;
    vector<long long> arr(t); 
    long long n=0;
    for(int i=0; i<t; i++){
        cin>>arr[i];
        n=max(n,arr[i]);
    }
     vector<vector<long long>> dp(n+1, vector<long long>(2));
    dp[1][1]=1;
    dp[1][0]=1;
    for(int i=2; i<=n; i++){
        dp[i][1]=(2*dp[i-1][1]%MOD+dp[i-1][0]%MOD)%MOD;
        dp[i][0]=(dp[i-1][1]%MOD+4*dp[i-1][0]%MOD)%MOD;
    }
    for(int i=0; i<t; i++){
        long long ans=(dp[arr[i]][1]+dp[arr[i]][0])%MOD;
        cout<< ans<<endl;
    }

    return 0;
}
