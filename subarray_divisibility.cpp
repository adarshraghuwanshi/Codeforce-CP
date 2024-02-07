#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;

    unordered_map<long long,long long> mp;
    long long prefix=0;
    mp[prefix]=1;
    long long ans=0;
    for(int i=0; i<n; i++){
        long long a; cin>>a;
        prefix += a;
        prefix %= n;
        while(prefix<0) prefix+=n;
        if(mp.find(prefix)!=mp.end()) ans+=mp[prefix];

        mp[prefix]++;

    }
    cout<< ans;
}
