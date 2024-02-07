#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n; 
    cin >> n;
    
    unordered_set<pair<ll, ll>> st;
    
    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        st.insert({a, 0});
    }
    
    for(auto it = st.begin(); it != st.end(); ++it) {
        int a; 
        cin >> a;
        it->second = a;
    }
    
    for(int i = 0; i < n; i++) {
        ll ans = 0;
        if(st.size() <= 1) {
            cout << "0 ";
        }
        else {
            ll prev = 0;
            for(auto it = st.begin(); it != st.end(); ++it) {
                ll next = 0;
                auto nextIt = next(it);
                if(nextIt != st.end()) {
                    next = nextIt->first;
                }
                if(it->second < prev + next) {
                    prev = it->first;
                    st.erase(it);
                    ans++;
                }
                prev = it->first;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ll t; 
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
