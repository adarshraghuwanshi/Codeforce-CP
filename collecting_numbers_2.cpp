#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    vector<int>nums(n+1);
    for(int i=1; i<=n;i++){
        cin>> nums[i];
    }

    // round without any operation
     int round=0;
    vector<int> rounds(n+1,0);
    vector<int> pos(n+1,0);
    for(int i=1; i<=n; i++){
        int curr=nums[i];
        pos[nums[i]]=i;
        if(rounds[curr-1]==0) {rounds[curr]=++round;
        }
        else rounds[curr]=1;
    }

    while(m--){
        int a,b; cin>>a>>b;
        

        swap(nums[a], nums[b]);
        swap(pos[nums[a]], pos[nums[b]]);

        

        cout<<find_round(nums, n)<<endl;
        
    }
    return 0;
}
