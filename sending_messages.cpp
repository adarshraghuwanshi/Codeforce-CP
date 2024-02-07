#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, f, a, b; cin>>n>>f>>a>>b;
    long long prev=0;
    
    for(int i=0; i<n; i++){
        long long t; cin>>t;
        if(f<=0) continue;
        long long ans1=(t-prev)*a;

        long long ans2=b;
        prev=t;
        f-=min(ans1,ans2);
    }
    if(f<=0) cout<<"NO"<<endl;
    else cout<<"Yes"<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
