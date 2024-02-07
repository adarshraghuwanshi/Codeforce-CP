#include<bits/stdc++.h>
using namespace std;

/*int main(){
    int n; cin>>n;
    vector<int>nums(n);

    for(int i=0; i<n; i++) cin>>nums[i];

    int maxi=0;
    unordered_set<int> st;
    int start=0;
    for(int i=0; i<n; i++){
       int  curr=nums[i];
       
        while(st.count(curr)){
            st.erase(nums[start]);
            start++;
        }
       st.insert(curr);
       maxi=max(maxi, i-start+1);
    }
    cout<< maxi;
    return 0;

}
*/
int main() {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    unordered_set<int> seen;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        while (seen.count(songs[right])) {
            seen.erase(songs[left++]);
        }
        seen.insert(songs[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;

    return 0;
}