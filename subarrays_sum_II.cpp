#include<bits/stdc++.h>
using namespace std;
void solve(deque<long long> dq, long long sum, long long x, set<pair<long long,long long>> &st){
    if(dq.empty()) return;
    if(sum==x) st.insert({dq.front(), dq.back()});

    long long a=dq.front(), b=dq.back();
    dq.pop_front();
    solve(dq, sum-a, x, st );
    dq.push_front(a);
    dq.pop_back();
    solve(dq, sum-b, x, st);
}

int main(){
    long long n,x; cin>>n>>x;
    vector<long long> nums(n);
    long long sum=0;
    deque<long long> dq;
    for(int i=0; i<n; i++) {cin>>nums[i];
    sum+=nums[i];
    dq.push_back(i);
    }

    set<pair<long long,long long>> st;
    solve(dq, sum, x, st);
    cout<< st.size();
}

/*int main(){
    int n,x; cin>>n>>x;
    int cnt=0;
    vector<int>nums(n);
    for(int i=0;i<n; i++) cin>>nums[i];
    
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=nums[j];
            if(sum==x)cnt++;
        }
    }
    cout<< cnt;
}*/
