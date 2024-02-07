#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long long mod=1000000007;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        long long ans=pow(a,b);
        ans%=mod;
        cout<< ans <<endl;
    }
    return 0;
}
