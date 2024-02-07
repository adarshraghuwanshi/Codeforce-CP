#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> sizes(n);
    
    for(int i=0; i<n; i++){
        cin>>sizes[i];
       
    }
    sort(sizes.begin(), sizes.end());
    //long long min_cost=1e15;
    long long curr_cost=0;
    /*
    Brute Force approach
    for(int i=sizes[0]; i<=sizes[n-1]; i++){
        curr_cost=0;
        for(int j=0; j<n; j++){
            curr_cost+=abs(i-sizes[j]);
        }
        min_cost=min(min_cost,curr_cost);

    }*/
   
     curr_cost=0;
        for(int j=0; j<n; j++){
            curr_cost+=abs(sizes[j]-sizes[n/2]);
        }
       
    
    cout<<curr_cost;
    return 0;
    
}
