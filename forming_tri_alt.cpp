#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin>>n;
    vector<long long> arr(n+1,0);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        arr[a]++;
    }
    long long prev=0;
    long long ans=0;
    for(int i=0; i<=n; i++){
        long long c=arr[i];
        if(c>=3){
            ans+=(c*(c-1)*(c-2))/6;
        }
        if(c>=2){
            ans+=(c*(c-1)/2)*prev;
        }
        prev+=c;
    }
    cout<<ans<<endl;
    
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
