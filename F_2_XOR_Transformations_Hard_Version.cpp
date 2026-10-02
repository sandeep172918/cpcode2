//Author:coding_with_alzheimer
//Date: 2026-10-02 08:49

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

struct Node{
    Node* store[2];
    lli count=0;
    Node(){
      store[0]=nullptr;
      store[1]=nullptr;
     }
    ~Node(){
        if(store[0])delete store[0];
        if(store[1])delete store[1];
    }
 
   bool iscontain(lli x){
      return store[x]!=nullptr;
   }
   void put(lli x,Node* root){
     store[x]=root;
   }
   Node* aage(lli x){
    return store[x];
   }
   void badho(){
    count++;
   }
   void decres(){
    count--;
   }

};
class Trie{
private:
    Node* root;
public:
  Trie(){
    root =new Node();
  }
  ~Trie(){
    delete root; 
  }
  void insert(lli x){
    Node* node=root;
    for(lli i=32;i>=0;i--){
        lli chek=(x>>i)&1;
        if(!node->iscontain(chek))
              node->put(chek,new Node);
        node->store[chek]->badho();
        node=node->aage(chek);
        
    }
   
  }
  void delet(lli x){
    vector<lli>bits;
    vector<Node*>child;
    Node* node=root;
    for(lli i=32;i>=0;i--){
        lli check=(x>>i)&1;
        bits.push_back(check);
        child.push_back(node->aage(check));
        node=node->aage(check);
    }
    for(auto &it:child){
        it->decres();
    }
    for(lli i=child.size()-1;i>=0;i--){
        Node* a=child[i];
        if(a->count==0){
            Node* parent;
           if(i==0) parent= root;
              else parent=child[i-1];
           parent->store[bits[i]]=nullptr;
           delete a;
        }else break;
    }
}

lli maxi(lli x){
    Node* node=root;
    lli ans=0;
    for(lli i=32;i>=0;i--){
        lli chek=(x>>i)&1ll;
        lli opo=1-chek;
        if(node->iscontain(opo)){
            ans|=(1LL<<i);
            node=node->aage(opo);

        }else{
            node=node->aage(chek);
        }
    }
    return ans;
}
lli kthmin(lli x, lli k){
    // if(root->count<k || k<=0) return -1;
    Node* node=root;
    lli ans=0;
    for(lli i=32;i>=0;i--){
        lli bit=(x>>i)&1ll;
        if(node->iscontain(bit) && node->aage(bit)->count>=k){
            node=node->aage(bit);
        }else{
            if(node->iscontain(bit))
                k-=node->aage(bit)->count;
            ans|=(1LL<<i);
            node=node->aage(1-bit);
        }
    }
    return ans;
}

};

void solve(){
lli n=0,k=0,ans=0;
string s;
cin>>n>>k;
map<lli,lli>m;
get(v,n);
srt(v);
lli c=0;
m[c++]=v[n-1]-v[0];
while(1){
   vll t;
   Trie tr;
   priority_queue<arr(3),vector<arr(3)>,greater<arr(3)>>pq;
   fr(i,n){
     tr.insert(v[i]);
   }
   fr(i,n){
    pq.push({tr.kthmin(v[i],2),v[i],2});
   }
   lli id=0;
   while(id<2*n){
    arr(3) it=pq.top();
    if(id&1) t.psb(it[0]);
    if(it[2]<n){
     pq.push({tr.kthmin(it[1],it[2]+1),it[1],it[2]+1});   
    }
    pq.pop();
    id++;
   }
   v=t;
   srt(v);
   m[c++]=v[n-1]-v[0];
   if(v.back()==0)break;
}
// return;
while(k--){
  lli j;
  cin>>j;
  cout<<m[j]<<'\n';
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