#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long int
#define fr(i,n) for(int i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define vec(v,n,k) vector<lli>v(n,k)
#define vect(v) vector<lli>v
#define vec2(v,x,y) vector<vector<lli>>v(x,vector<lli>(y));
#define pr pair<lli,lli>
#define take(x) lli x;cin>>x
#define get(v,n) vec(v,n,0);frs(i,0,n-1)cin>>v[i]
#define out(v,n) frs(i,0,n-1)cout<<v[i]
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<
#define no cout<<
#define ff first
#define ss second
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int n;
int block_size;
vector<int>v,freq,ans;
int cnt=0;
struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int b1 = l / block_size;
        int b2 = other.l / block_size;
        if (b1 != b2)
            return b1 < b2;
        return (b1 & 1) ? (r < other.r) : (r > other.r);
    }
};
set<int>st;
void add(int curr){
  freq[v[curr]]++;
  if(freq[v[curr]]==1)cnt++;
 
}
void remove(int curr){
  freq[v[curr]]--;
  if(freq[v[curr]]==0)  
    cnt--;
}
int get_ans(){
  return cnt;
}
 
void Mo_algo(vector<Query>&q){
    sort(all(q));
    int cur_l=0,cur_r=-1;  // take care if index strat from 1 then cur_r=0 else -1;
    
    for(auto &it:q){
        while(it.l<cur_l){
            cur_l--;
            add(cur_l);
        }
        while(it.r>cur_r){
            cur_r++;
            add(cur_r);
        }
        while(it.l>cur_l){
            remove(cur_l);
            cur_l++;
        }
        while(it.r<cur_r){
            remove(cur_r);
            cur_r--;
        }
        ans[it.idx]=get_ans();
    
    }
 
}
 

void solve(){
cin>>n;int k;cin>>k;
vector<Query>q(k);
block_size=(int)sqrt(n)+1;
v.resize(n);
fr(i,n)cin>>v[i];
vector<int>temp;
temp=v;
srt(temp);

temp.erase(unique(all(temp)),temp.end());

freq.resize(temp.size());

fr(i,n){
    v[i]=lower_bound(all(temp),v[i])-temp.begin();
}

ans.resize(k);
fr(i,k){
    int l,r;cin>>l>>r;l--;r--;
    q[i]={l,r,i};
}
Mo_algo(q);
fr(i,k)cout<<ans[i]<<'\n';
 
}
 
int32_t main(){
fastio;
int tt=1;
while(tt--){
solve();
}
}
