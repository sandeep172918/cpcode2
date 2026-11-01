//Author:coding_with_alzheimer
//Date: 2026-10-28 18:57

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

#include <iostream>
#include <vector>
#include <random>

#define lli long long 
using namespace std;

mt19937 rng(1337);
class treap{
public:    
struct Node{
    lli val;
    lli prior; // random priority
    Node *l,*r;
    Node(lli v):val(v),prior(rng()),l(nullptr),r(nullptr){}
};

Node *root;


void split(Node* t,lli k,Node*& l,Node*& r){
    if(!t){
        l=r=nullptr;
        return;
    }
    if(t->val<=k){
        split(t->r,k,t->r,r);
        l=t;
    }else{
        split(t->l,k,l,t->l);
        r=t;
    }
}

void merge(Node*& t,Node* l,Node* r){
    if(!l || !r){
        t=l?l:r;
        return;
    }
    if(l->prior > r->prior){
        merge(l->r,l->r,r);
        t=l;
    }else{
        merge(r->l,l,r->l);
        t=r;
    }
}

void unit(Node *&t,Node *l,Node *r){
    if(!l || !r){
        t=l?l:r;
        return;
    }
    if(l->prior<r->prior)swap(l,r);
    Node *lt,*rt;
    split(r,l->val,lt,rt);
    unit(l->l,l->l,lt);
    unit(l->r,l->r,rt);
    t=l;
}

void dfs(Node *t,vector<lli>& ans,lli k) {
    if(!t)return;
    dfs(t->l,ans,k);
    ans[t->val]=k;
    dfs(t->r,ans,k);
}

public:
treap():root(nullptr){}

void insert(lli k){ 
    Node *l,*r;
    split(root,k,l,r);
    Node* m=new Node(k);
    merge(l,l,m);
    merge(root,l,r);
}


void erase(Node*& root,lli pos){
    Node *l,*m,*r;
    split(root,pos,l,r);
    split(r,1,m,r);
    merge(root,l,r);
    delete m;
}

Node* extract(lli L,lli R){
    Node *left,*mid,*right;
    split(root,L-1,left,mid);
    split(mid,R,mid,right);
    merge(root,left,right);
    return mid;
}
void combine(Node *m){
    unit(root,root,m);
}

void get_ans(vector<lli>& ans,lli val){
    dfs(root,ans,val);
}

};

void solve(){
lli n=0,k=0;
array<lli,1>arr;
string s;
cin>>n;
get(v,n);
cin>>k;
treap t[101];
fr(i,n){
    t[v[i]].insert(i+1);
}
while(k--){
  lli l,r,x,y;
  cin>>l>>r>>x>>y;
  if(x==y)continue;
  treap::Node* tt=t[x].extract(l,r);  
  if(tt){
    t[y].combine(tt);
  }
}
vll ans(n+1);
frs(i,1,100){
    t[i].get_ans(ans,i);
}
ans.erase(ans.begin());
out(ans);

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}