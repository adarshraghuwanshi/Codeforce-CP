#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k,x; cin>>n>>k>>x;

        vector<int> num(n);
        long long total=0;
        for(int i=0; i<n; i++){
            cin>>num[i];
            total+=num[i];
        }

        sort(num.begin(), num.end());
        long long max_sum=1e-9;
        for(int i=0; i<x; i++){
            total=total-2*(num[n-1-i]);
        }
        max_sum=max(max_sum,total);
        
    }
    return 0;
}
