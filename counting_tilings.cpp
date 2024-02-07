#include<bits/stdc++.h>
using namespace std;
long long solve(long long i, long long j, vector<vector<long long>> grid, long long n, long long m){
    if(i==n ) return 1;
    long long ans=0;
    if(i==0 && j==0 ){
        grid[i][j]=1;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
        grid[i][j]=3;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
    }
    else if(j==0 ) {
        if(grid[i-1][j]==3) {
        grid[i][j]=4;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
        }
        else{
            grid[i][j]=1;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
        grid[i][j]=3;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
        }
    }

    if(grid[i-1][j]==3 && grid [i][j-1]==1) return 0;
    if(grid [i][j-1]==1){
         grid[i][j]=2;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
    }
    else if(grid[i-1][j]==3) {
        grid[i][j]=4;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
    }
    else {
        grid[i][j]=1;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
        grid[i][j]=3;
        ans+=solve(i+(j+1)%m,(j+1)%m, grid, n, m );
    }
    return ans;
}
int main(){
    long long n,m;
    cin>>n>>m;

    vector<vector<long long>> grid(n, vector<long long>(m,-1));
    cout<<solve(0,0,grid,n,m);

}
