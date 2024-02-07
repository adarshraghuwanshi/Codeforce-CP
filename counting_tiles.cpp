#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j){
    if(i==0 && j==0) return 1;
    else if(i<=0 || j<=0) return 0;

    return solve(i-1,j-2)+solve(i-2,j-1);
}
int main(){
    int n,m; cin>>n>>m;
    solve(n,m);
}