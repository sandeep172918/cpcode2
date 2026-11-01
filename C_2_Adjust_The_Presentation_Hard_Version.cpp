//Author:coding_with_alzheimer
//Date: 2026-10-27 17:37

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
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define psbp(a,b) push_back({a,b})
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define pn(x) cout<<(x)<<"\n"
#define pt(x) cout<<(x)<<" "
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
#define arr(a) array<lli,a>
using namespace std;
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(1337);


class Treap{
private:
    struct Node {
        lli key,val,prior,size, first_val, last_val;
        bool is_seq;
        Node *l, *r;
        
        Node(lli k, lli v) : key(k), val(v), prior(rng()), size(1), 
                             first_val(v), last_val(v), is_seq(true), 
                             l(nullptr), r(nullptr) {}
    };

    Node* root;

    void upd(Node* t) {
        if (!t) return;
        t->size = 1;
        t->first_val = t->val;
        t->last_val = t->val;
        t->is_seq = true;

        if (t->l) {
            t->size += t->l->size;
            t->first_val = t->l->first_val;
            if (!t->l->is_seq || t->val != t->l->last_val + 1) t->is_seq = false;
        }
        if (t->r) {
            t->size += t->r->size;
            t->last_val = t->r->last_val;
            if (!t->r->is_seq || t->r->first_val != t->val + 1) t->is_seq = false;
        }
    }

    void split(Node* t, lli key, Node*& l, Node*& r) {
        if (!t) { l = r = nullptr; return; }
        if (t->key <= key) {
            split(t->r, key, t->r, r);
            l = t;
        } else {
            split(t->l, key, l, t->l);
            r = t;
        }
        upd(t);
    }

    void merge(Node*& t, Node* l, Node* r) {
        if (!l || !r) { t = l ? l : r; return; }
        if (l->prior > r->prior) {
            merge(l->r, l->r, r);
            t = l;
        } else {
            merge(r->l, l, r->l);
            t = r;
        }
        upd(t);
    }

    void clear_tree(Node* t) {
        if (!t) return;
        clear_tree(t->l);
        clear_tree(t->r);
        delete t;
    }

public:
    Treap() : root(nullptr) {}
    

    void insert(lli key, lli val) {
        Node *l, *r;
        split(root, key, l, r);
        Node* m = new Node(key, val);
        merge(l, l, m);
        merge(root, l, r);
    }

    void erase(lli key) {
        Node *l, *m, *r;
        split(root, key - 1, l, m);
        split(m, key, m, r);
        delete m; 
        merge(root, l, r);
    }

    bool isValid() {
        if (!root) return true;
        return (root->first_val == 0 && root->is_seq);
    }
};



void solve(){
lli n=0,k=0,ans=0;
array<lli,1>arr;
string s;
lli q;
cin>>n>>k>>q;
get(v,n);
map<lli,lli>m;
fr(i,n)m[v[i]]=i;

map<lli,set<lli>>f;
get(b,k);
fr(i,k)f[b[i]].insert(i);

Treap t;
for(auto &it:f){
    t.insert(*it.ss.begin(),m[it.ff]);
}

if(t.isValid())cout<<"YA\n";
else cout<<"TIDAK\n";

while(q--){
    lli id,val;
    cin>>id>>val;
    id--;

    lli x=b[id];
    b[id]=val;

    lli fir=*f[x].begin();
    t.erase(fir);

    f[x].erase(id);

    if(!f[x].empty()){
        t.insert(*f[x].begin(),m[x]);
    }

    if(!f[val].empty()){
        fir=*f[val].begin();
        t.erase(fir);
    }

    f[val].insert(id);
    t.insert(*f[val].begin(),m[val]);

    if(t.isValid())cout<<"YA\n";
    else cout<<"TIDAK\n";
}
}

int32_t main(){
fastio;
lli test=1;
cin>>test;
while(test--){
solve();
}
}