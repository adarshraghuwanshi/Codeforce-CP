#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    set<int> lights{0, n};
	multiset<int> dist{n};
  
    for(int i=0; i<m; i++){
        int curr; cin>>curr;
        auto it1=lights.upper_bound(curr);
        auto it2=it1;
        --it1;

        dist.erase(dist.find(*it2-*it1));
        lights.insert(curr);
        dist.insert(curr-*it1);
        dist.insert(*it2-curr);

        auto ans=dist.end();
        --ans;
        cout<<*ans<<" ";
    }
return 0;
}
