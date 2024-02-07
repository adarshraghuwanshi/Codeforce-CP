#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n;i++){
        cin>> nums[i];
    }
   /* int round=0, curr=0;
    while(curr<n){
        round++;
        for(int i=0; i<n; i++){
            if(curr+1==nums[i]) curr++;
        }
    }
    cout<<round;*/
    int round=0;
    vector<int> rounds(n+1,0);
    for(int i=0; i<n; i++){
        int curr=nums[i];
        if(rounds[curr-1]==0) {rounds[curr]=++round;
        }
        else rounds[curr]=1;
    }
    cout<< round;
    return 0;
}
