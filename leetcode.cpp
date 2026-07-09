//Author:coding_with_alzheimer
//Date: 2026-07-09 16:02

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



class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxi, vector<vector<int>>& q) {
        vpr p(n);
        fr(i,n){
            p[i]={nums[i],i};
        }
        srt(p);
        vvll s(n,vll(18));
        lli l=0;
        fr(r,n){
            while(p[r].ff-p[l].ff>maxi){
                s[l][0]=r-1;
                l++;
            }
        }
        while(l<n){
            s[l][0]=n-1;
            l++;
        }
        frs(i,1,17){
          fr(j,n){
            s[j][i]=s[s[j][i-1]][i-1];
          }
        }
        vll id(n);
        fr(i,n){
            id[p[i].ss]=i;
        }
        lli m=q.size();
        vll ans(m,-1);
        fr(i,m){
            lli u=id[q[i][0]];
            lli v=id[q[i][0]];
            if(u==v){
                ans[i]=0;
                continue;
            }
            if(u>v)swap(u,v);
            lli cnt=0;
            rfr(i,17,0){
                if(s[u][i]<v){
                    u=s[u][i];
                    cnt+=(1ll<<i);
                }
            }
            if(s[u][0]==v)ans[i]=cnt+1;

        }
        return ans;
            
    }
};