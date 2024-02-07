#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    int cnt=0;
    queue<int> q;
    int sum=0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        q.push(a);
        sum+=a;
        while(sum>x) {
        sum-=q.front();
        q.pop();}
        if(sum==x) cnt++;
    }
    cout<< cnt;
}
