#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        vector<int> suf(n);
        suf[n-1] = -arr[n-1];
        for(int i=n-2;i>=0;i--) {
            suf[i] = suf[i+1] - arr[i];
        }
        ll k=arr[0];
        ll ans = suf[1];

        for(int i=1;i<n-1;i++){
            ans = max(ans,k+suf[i+1]); 
            k+=abs(arr[i]);
        }
        ans = max(ans,k);
        cout<<ans<<"\n";
    }

}