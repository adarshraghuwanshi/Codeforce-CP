#include<bits/stdc++.h>
using namespace std;
long long dp[20][10][2][2];
long long solve(string a, long long n, long long prev, bool leading_zero, bool tight){
    
    if(n==0) return 1;
    if(prev!=-1 && dp[n][prev][leading_zero][tight]!=-1) return dp[n][prev][leading_zero][tight];
   
    long long lo=0;
    long long up=tight ? a[a.length()-n]-'0':9;

    long long ans=0;
    for(long long dig=lo; dig<=up; dig++){
        if(dig==prev && leading_zero==0) continue;

        ans+=solve(a, n-1, dig, (dig==0 & leading_zero), (tight & dig==up));

        

    }
    return dp[n][prev][leading_zero][tight]=ans;
}
int main(){
    long long a,b; cin>>a>>b;
    string A=to_string(a-1);
    string B=to_string(b);
    memset(dp,-1,sizeof dp);
    long long ans1=solve(B,B.length(), -1, 1, 1);
    memset(dp,-1,sizeof dp);
    long long ans2=solve(A,A.length(), -1, 1, 1);

    cout<<ans1-ans2;

    
   

}