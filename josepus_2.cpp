#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
    int n,k; cin>>n>>k;
    ordered_set<int> st;
    for(int i=0; i<n; i++) st.insert(i+1);

    int ind= k%n;
    while(n--){
        auto y = st.find_by_order(ind);
        cout<<*y<<' ';
        st.erase(y);
        if(n) ind=(ind+k)%n;
    }
    
    return 0;


}
