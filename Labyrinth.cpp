#include <bits/stdc++.h>
using namespace std;
string solve(vector<vector<char>> &map, int x, int y, vector<vector<int>> visited, bool & reached, vector<vector<string>> &dp)
{
    if (map[x][y] == 'B')
    {
        reached=true;
        visited[x][y]=true;
        return "";
    }
    if(dp[x][y]!="-1") return dp[x][y];
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    string str="LRUD";
    string ans="";
    int size=INT_MAX;
    visited[x][y]=1;
    for(int i=0; i<4; i++){
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0 && cy>=0 && cx<map.size() && cy<map[0].size()){
            if(map[cx][cy]=='.' && visited[cx][cy]==0){
                
                string curr=solve(map, cx, cy, visited, reached, dp);
                if(size>curr.size()){
                    size=curr.size();
                    ans=curr;
                    ans+=str[i];
                }
                
            }
        }
        

        
    }
    visited[x][y]=0;
    return dp[x][y]=ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    int start_i, start_j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'A')
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    bool reached =false;
    vector<vector<string>> dp(n, vector<string>(m,"-1"));

    string ans=solve(map, start_i, start_j, visited, reached, dp);
    if(reached==false) {cout<<"NO";
    return 0;}
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i];
    }
}
