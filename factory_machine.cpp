#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n, t;
    cin>>n>>t;
    vector<int>d(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>d[i];
        sum+=d[i];
    }

    sort(d.begin(), d.end());

    long long start=0, end=1e18;
    long long ans=0;
    while(start<=end){
         ll mid= start+(end-start)/2;
        ll sum=0;
        ll start_time=mid;
        for(int i=0; i<n; i++){
            sum+=start_time/d[i];
            if(sum>=t) break;
            
        }
        if(sum>=t) {end=mid-1;
        ans=mid;}
        else start=mid+1;
    }
    cout<< ans;
    return 0;
}
