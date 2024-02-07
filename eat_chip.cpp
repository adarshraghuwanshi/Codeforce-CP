#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long h, w, x1, y1, x2, y2; cin>> h>> w>> x1>>y1>>x2>>y2;

    if(x1>=x2) {
        cout<<"Draw"<<endl;
        return;
    }

    long long ver=abs(x1-x2);
    long long hor=abs(y1-y2);

    if(ver%2==1){
        long long reach;
        if(y1<y2){
            reach=max(w, y2+ver/2);
            if(y1+(ver/2)+1>=reach) cout<<"Alice"<<endl;
            else cout<<"Draw"<<endl;
        }
        else if(y1>y2){
            reach=max(1, y2-ver/2);
            if(y1-(ver/2)-1>=reach) cout<<"Alice"<<endl;
            else cout<<"Draw"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }


    }
    else{
         long long reach;
        if(y1>y2){
            reach=min(w, y1+(ver/2)+1);
            if(y2+ver/2>=reach) cout<<"bob"<<endl;
            else cout<<"Draw"<<endl;
        }
        else if(y1<y2){
            reach=max(1, y1-(ver/2)-1);
            if(y2+ver/2>=reach) cout<<"bob"<<endl;
            else cout<<"Draw"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }


    }

    
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
