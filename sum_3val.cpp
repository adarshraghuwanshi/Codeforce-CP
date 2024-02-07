#include<bits/stdc++.h>
using namespace std;

int main(){
   int n, x; cin>>n>>x;
   vector<pair<int,int>> arr(n);
   for(int i=0; i<n; i++) {cin>>arr[i].first;
   arr[i].second=i+1;}
   sort(arr.begin(), arr.end());

   for(int i=0; i<n; i++){
    int s=0, e=n-1;
    while(s<e){
        if(i==s) {s++; continue;}
        if(i==e) {e--; continue;}
        if(arr[i].first+arr[s].first+arr[e].first==x){
            cout<< arr[i].second<< " "<< arr[s].second<< " "<< arr[e].second;
            return 0;
        }
        else if(arr[i].first+arr[s].first+arr[e].first>x) e--;
        else s++;
    }
   }
   cout<<"IMPOSSIBLE";
   return 0;
}
