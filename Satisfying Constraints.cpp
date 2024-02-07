#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >>t;
    while(t--){
        int n; cin>>n;
        int start=0, end=1e9;
        set<int> st;
        for(int i=0; i<n; i++){
            int a,x; cin>>a>>x;
            if(a==1){
                start=max(start,x);
            }
            else if(a==2){
                end=min(end,x);
            }
            else{
                if(x>=start && x<=end) st.insert(x);
            }
        }
        if(start>end) {cout<<"0"<<endl;
        }
        else{
        int ans=end-start+1;
        for(auto it: st){
            if(it>=start && it<=end) ans--;
        }

        cout<<ans<<endl;}
    }
}
