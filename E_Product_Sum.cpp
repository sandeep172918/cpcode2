//Author:coding_with_alzheimer
//Date: 2026-02-16 23:54

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long int
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define pr pair<lli,lli>
#define vll vector<lli>
#define vbl vector<bool>
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define tr true
#define fs false
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠤⠤⠤⠴⠶⠶⠒⠚⠋⠉⠉⠉⠉⣷⢀⣀⡤⠤⠶⠶⠒⠛⢶⡄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡀⠀⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣇⣾⠀⠀⠀⠀⣴⡄⢠⣿⣄⡀⣰⠏⠙⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⠶⠚⠉⠉⠙⢦⣄⣀⣀⡟⠙⠋⠁⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⢰⠋⢈⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⠀⠀⠀⠀⠀⠀⠠⣆⠀⠀⢿⠀⢸⡶⢿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣤⣀⡼⠀⠀⠻⠀⠀⠙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡖⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠳⣦⡀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⣿⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⡟⢳⣄⠀⠀⠀⠀⠙⣇⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⡿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⢿⡀⠀⠀⠀⢀⡞⠁⠉⠓⠀⠀⠀⠀⣯⠴⠻⣆⠀⠀⠀⠀⢻⡆⠀⠀⠀⠻⠃⠀⠀⠀⠀⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⢸⡇⠀⠀⠀⠘⣧⠀⠖⠚⣷⠀⠀⠀⣧⠀⠀⠘⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⠀⠀⠘⡇⠀⠀⠀⠀⠘⠷⣤⣠⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⢀⡠⠞⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠾⣦⠀⢸⡇⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣀⣠⡤⠔⠚⠉⠀⠀⠀⠀
⠀⠀⣴⢦⣄⠀⠀⢀⣰⠏⠀⠘⣧⣿⠀⠀⠀⠀⢠⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡤⠴⠶⠒⠋⢹⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡏⠀⠈⠛⠋⠉⢀⣴⣿⣟⢿⡏⠀⠀⢀⡴⠋⠀⣧⠀⠀⢀⣀⣠⣤⣤⠤⠴⠒⠚⠛⠉⠉⠀⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣧⢀⣴⣶⣶⡄⢾⣿⣿⡿⣸⠃⠀⢠⠞⠁⠀⠀⠈⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢿⣿⣿⣿⣿⣿⠘⢿⣭⡵⠋⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠳⣬⣿⣭⠯⠖⠚⠁⠀⢀⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣰⠏⠀⣀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡼⢃⡴⠚⡿⠀⠀⠀⣤⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣾⠗⠋⠀⢠⡏⠀⠀⣸⠋⢷⡀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠋⠁⣄⠀⢠⡿⡇⠀⢰⡏⠀⠀⠻⣮⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠙⠛⠋⠀⡇⢠⡟⠀⠀⠀⠀⠈⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣧⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/

class LiChao {
public:
   

    struct Line {
        lli m, b;
        Line(lli _m = 0, lli _b = -(1ll<<62)) : m(_m), b(_b) {}
        lli gett(lli x) const { return m * x + b; }
    };

    struct Node {
        Line line;
        Node *l = nullptr, *r = nullptr;
        Node(Line v) : line(v) {}
    };

    lli L, R;
    Node* root;

    LiChao(lli l, lli r) : L(l), R(r), root(nullptr) {}

    void add_line(Line nw) {
        add_line(nw, L, R, root);
    }

    void add_line(Line nw, lli l, lli r, Node*& node) {
        if (!node) {
            node = new Node(nw);
            return;
        }

        lli mid = (l + r) >> 1;

        bool left = nw.gett(l) > node->line.gett(l);
        bool middle = nw.gett(mid) > node->line.gett(mid);

        if (middle) swap(nw, node->line);

        if (r - l == 1) return;

        if (left != middle)
            add_line(nw, l, mid, node->l);
        else
            add_line(nw, mid, r, node->r);
    }

    lli query(lli x) {
        return query(x, L, R, root);
    }

    lli query(lli x, lli l, lli r, Node* node) {
        if (!node) return -(1ll<<62);

        lli res = node->line.gett(x);
        if (r - l == 1) return res;

        lli mid = (l + r) >> 1;
        if (x < mid && node->l) res = max(res, query(x, l, mid, node->l));
        if (x >= mid && node->r) res = max(res, query(x, mid, r, node->r));
        return res;
    }
};


void solve(){
lli n,k;cin>>n;
// get(v,n);
vll v(n+1);

lli ans=0;
vll pf(n+1,0);
frs(i,1,n){
    cin>>v[i];
    ans+=i*v[i];
    pf[i]+=pf[i-1]+v[i];
}
LiChao li(-1e9,1e9),lc(-1e9,1e9);
lli pre=ans;
rfr(i,n-1,1){
  li.add_line({i+1,-pf[i+1]});
  lli ch=pf[i]-v[i]*i+li.query(v[i]);
  ans=max(ans,pre+ch);
}
frs(i,2,n){
    lc.add_line({i-1,-pf[i-2]});
    lli ch=pf[i-1]-v[i]*i+lc.query(v[i]);
    ans=max(ans,pre+ch);
}
cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}