#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin>>pages[i];
    if(n==1){
        cout<<2*pages[0];
        return 0;
    }
    sort(pages.begin(), pages.end());
    int s=0, e=n-1;
    int sum1=pages[0], sum2=pages[n-1];
    while(e-s>2){
        if(sum1> sum2){
            sum2+=pages[e--];
        }
        else{
            sum1+=pages[s++];
        }
    }
    cout<<sum1+sum2;
    return 0;
}
