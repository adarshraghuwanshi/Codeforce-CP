#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> coins(n);
    long long total=0;
    for(int i=0; i<n; i++){
        cin>>coins[i];
        total+=coins[i];
    }
    sort(coins.begin(), coins.end());
    // vector<int> value(INT_MAX,0);

  /*  for(int i=0; i<n; i++){
        int curr=coins[i];
        value[curr]=1;
        for(int c=1; c<curr; c++){
            if(value[c]==0){cout<<c; return 0;}
            value[c+curr]=1;
        }
    }*/
     long long curr_sum = 0;

    for(int i = 0; i < n; i++){
        if(coins[i] > curr_sum + 1){
            cout << curr_sum + 1;
            return 0;
        }
        curr_sum += coins[i];
    }

    cout << curr_sum + 1;
    
    return 0;
}
