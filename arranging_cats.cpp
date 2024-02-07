#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long arrange(int n, string&s, string &f, long long k, vector<vector<long long>> &dp){
    //base case
    if(n<0){
        if(k==0) return 0;
        else return INT_MAX;
    }
    if(dp[n][k+n+2]!=-1) return dp[n][k+n+2];

    if(s[n]==f[n]) return arrange(n-1, s, f,k, dp);
    long long ans1= 1+arrange(n-1, s, f, k, dp);
    long long ans2=INT_MAX;

    if(s[n]=='1'){
         ans2=min(ans2,1+ arrange(n-1,s,f,k+1, dp));
         if(k<0) ans2=min(ans2, arrange(n-1,s,f,k+1, dp));
    }
    else{
        if(k>0) ans2=min(ans2, arrange(n-1,s,f,k-1, dp));
        ans2=min(ans2,1+ arrange(n-1,s,f,k-1, dp));

    }
    return dp[n][k+n+2]=min(ans1,ans2);

}
void solve(){
    int n; cin>>n;
    string s, f; cin>> s>>f;
    long long k=0;
    vector<vector<long long>> dp(n+1, vector<long long>(2*n+10,-1));


    cout<<arrange(n-1, s, f, k,dp)<<endl;

}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
