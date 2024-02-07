#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {int a; cin>>a;
    arr[i]=1<<a;}

    sort(arr.begin(), arr.end());
    int ans=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int z=j+1; z<n; z++){
                if(arr[z] < arr[i] + arr[j] )  ans++;
                else break;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {int a; cin>>a;
    arr[i]=1<<a;}

    sort(arr.begin(), arr.end());
    int ans=0;
   
    for(int i=n-1; i>=2; i--){
        int left=0, right=i-1;
        while(left<right){
            if(arr[left]+arr[right]>arr[i]) {
                ans+=right-left;
                right--;
            }
            else left++;
        }
               
    }
        
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
*/