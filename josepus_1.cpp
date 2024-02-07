#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    set<int> st;
    for(int i=0; i<n; i++) st.insert(i+1);

    auto it= st.begin();
    while(st.size()>1){
        ++it;
        if(it==st.end()) it=st.begin();
        cout<<*it<<" ";
        st.erase(it++);
         if(it==st.end()) it=st.begin();
    }
    cout<<*it<<" ";
    st.erase(it);
    return 0;


}
