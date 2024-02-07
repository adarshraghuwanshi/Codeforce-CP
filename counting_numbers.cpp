#include<bits/stdc++.h>
using namespace std;
long long count_digit(long long a){
    
    long long ans=0;
    while(a>0){
        ans++;
        a=a/10;
    }
    return ans;
}
long long solve(long long a, long long n, long long prev, bool trail){
    

    long long num=pow(10,n-1);
    long long ans=0;
    long long x=a/num;
    if(n==1) {
        if(prev>x)
        return x;
        else return x-1;
    }
    if(trail==false){
        if(x==0) return solve(a%num, n-1, prev, trail);
    }
    trail=true;
    ans+=pow(9,n-1)*x;
    if(prev<x) ans-=pow(9,n-1);
    if(prev!=x) ans+=solve(a%num,n-1,x, trail);
    return ans;
}
int main(){
    long long a,b; cin>>a>>b;
    if(a==b){
        long long prev=a%10;
        a=a/10;
        while(a>0){
            if(prev==a%10){
                cout<<"0";
                return 0;
            }
            prev=a%10;
            a=a/10;
        }
        cout<<"1";
        return 0;
    }
    
    long long n2=count_digit(b);
    bool trail=false;
    cout<< solve(b,n2,11, trail)-solve(a-1,n2,11, trail);
    

}