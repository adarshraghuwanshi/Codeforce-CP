#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i1=0, j1=n-1, i2=m-1, j2=0;
    long long maxVar=0;
    while(i1<=j1){
        if(abs(a[i1]-b[i2])>=abs(a[j1]-b[j2])){
            maxVar+=abs(a[i1]-b[i2]);
            i1++; i2--;
        }
        else{
            maxVar+=abs(a[j1]-b[j2]);
            j1--; j2++;
        }
    }
    cout<<maxVar<<endl;


}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
