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
        long long max_sum=INT_MIN;
        for(int i=0; i<x; i++){
            total=total-2*(num[n-1-i]);
        }
        max_sum=max(max_sum,total);
        
        for(int i=0; i<k; i++){
            if( n-1-i-x>=0)
            total=total+num[n-1-i]-2*num[n-1-i-x];
            else if(n-i-1>=0) total=total+num[n-i-1];
            
            else break;
            max_sum=max(max_sum,total);
        }
        cout<<max_sum<<endl;
    }
    return 0;
}
