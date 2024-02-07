#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    pair<int,int> start;
    pair<int,int> end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            if (map[i][j] == 'B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }
    

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        string str = "URDL";

        vector<vector<int>> prev(n, vector<int>(m,-1));
    vector<vector<int>> vis(n, vector<int>(m,0));
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second]=1;

    while(!q.empty()){
        
        pair<int, int>curr= q.front();
        q.pop();
        

          for(int i=0; i<4; i++){
        int cx=curr.first+dx[i];
        int cy=curr.second+dy[i];
        if(cx>=0 && cy>=0 && cx<n && cy<m){
            if(map[cx][cy]!='#' && vis[cx][cy]==0){
                vis[cx][cy]=1;
                q.push({cx,cy});
                prev[cx][cy]=i;
                
            }
        }
    }



    }

    if(vis[end.first][end.second]==0) {cout<<"NO";
    return 0;}
    cout<<"YES"<<endl;
    
    vector<int> steps;
		while (end != start) {
			int p = prev[end.first][end.second];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			end = {end.first- dx[p], end.second - dy[p]};
		}
		reverse(steps.begin(), steps.end());
        cout<<steps.size()<<endl;
		for (char c : steps) { cout << str[c]; }
		cout << endl;
}
