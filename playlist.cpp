#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>num(n);

    for(int i=0; i<n; i++) cin>>num[i];

    
    unordered_map<int,int> prev;

    int maxi=0;
    int ans=0;
    int start=0;
    for(int i=0; i<n; i++){
        if(prev.find(num[i])!=prev.end()){
            if(start<=prev[num[i]]){
            ans=i-prev[num[i]];
            start=prev[num[i]];}
            else{
                ans++;
            }
        }
        else ans++;
        prev[num[i]]=i;
        maxi=max(maxi,ans);
    }
    cout<< maxi;
    return 0;

}
