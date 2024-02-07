#include<bits/stdc++.h>
using namespace std;

int main(){
   int n, x; cin>>n>>x;
   vector<int> arr(n);
   for(int i=0; i<n; i++) cin>>arr[i];

   unordered_map<int, pair<int,int>> mp;

   for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        int curr=x-arr[i]+arr[j];
        if(mp.find(curr)!=mp.end()){
            if(i!=mp[curr].first && j!=mp[curr].first && i!=mp[curr].second  && j!=mp[curr].second ){
                cout<<i+1<< " "<<j+1<< " "<< mp[curr].first+1<< " "<<mp[curr].second+1<< " ";
                return 0;
            }
        }
        mp[arr[i]+arr[j]]={i,j};
    }
   }
   
   
   cout<<"IMPOSSIBLE";
   return 0;
}
