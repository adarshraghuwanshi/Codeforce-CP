#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    stack<pair<int,int>> q;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        
        
            while(!q.empty() && q.top().first>=a) q.pop();
            if(q.empty()) cout<<"0 ";
            else cout<<q.top().second<<" ";
        
        q.push({a,i+1});
    }
    return 0;
}
