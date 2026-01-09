#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int y = count(s.begin(), s.end(), 'Y');
        cout << ((y <= 1) ? "YES" : "NO") << "\n";
    }
    return 0;
}