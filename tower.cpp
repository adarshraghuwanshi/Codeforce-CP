#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    multiset<int> st;
    int cnt=0;
    for(int i=0; i<n; i++){
        int curr; cin>>curr;
        auto it=st.upper_bound(curr);
        if(it!=st.end() && *(it)!=curr) {st.erase(it); cnt--;}
        st.insert(curr);
        cnt++;
    }
    cout<<cnt;
    return 0;
}
