//Author:coding_with_alzheimer
//Date: 2026-09-24 10:29

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
const lli MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const lli INF = 1e18;
const lli NINF = -1e18;

struct Node {
    lli min1, min2;
    lli min_cnt;
    lli lazy_add;
    lli lazy_max;
};

class SegTreeBeats {
private:
    lli n;
    vector<Node> tree;

    void push_up(lli node) {
        lli lc = 2 * node, rc = 2 * node + 1;
        if (tree[lc].min1 < tree[rc].min1) {
            tree[node].min1 = tree[lc].min1;
            tree[node].min_cnt = tree[lc].min_cnt;
            tree[node].min2 = min(tree[lc].min2, tree[rc].min1);
        } else if (tree[lc].min1 > tree[rc].min1) {
            tree[node].min1 = tree[rc].min1;
            tree[node].min_cnt = tree[rc].min_cnt;
            tree[node].min2 = min(tree[lc].min1, tree[rc].min2);
        } else {
            tree[node].min1 = tree[lc].min1;
            tree[node].min_cnt = tree[lc].min_cnt + tree[rc].min_cnt;
            tree[node].min2 = min(tree[lc].min2, tree[rc].min2);
        }
    }

    void apply_add(lli node, lli v) {
        if (tree[node].min1 != INF) tree[node].min1 += v;
        if (tree[node].min2 != INF) tree[node].min2 += v;
        tree[node].lazy_add += v;
        if (tree[node].lazy_max != NINF) tree[node].lazy_max += v;
    }

    void apply_max(lli node, lli v) {
        if (tree[node].min1 >= v) return;
        tree[node].min1 = v;
        tree[node].lazy_max = max(tree[node].lazy_max, v);
    }

    void push_down(lli node) {
        lli lc = 2 * node, rc = 2 * node + 1;
        if (tree[node].lazy_add != 0) {
            apply_add(lc, tree[node].lazy_add);
            apply_add(rc, tree[node].lazy_add);
            tree[node].lazy_add = 0;
        }
        if (tree[node].lazy_max != NINF) {
            apply_max(lc, tree[node].lazy_max);
            apply_max(rc, tree[node].lazy_max);
            tree[node].lazy_max = NINF;
        }
    }

    void build(lli node, lli start, lli end, const vector<long long>& arr) {
        tree[node].lazy_add = 0;
        tree[node].lazy_max = NINF;
        if (start == end) {
            tree[node].min1 = arr[start];
            tree[node].min2 = INF;
            tree[node].min_cnt = 1;
            return;
        }
        lli mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        push_up(node);
    }

    // Standard Range Add
    void update_add(lli node, lli start, lli end, lli l, lli r, lli v) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply_add(node, v);
            return;
        }
        push_down(node);
        lli mid = (start + end) / 2;
        update_add(2 * node, start, mid, l, r, v);
        update_add(2 * node + 1, mid + 1, end, l, r, v);
        push_up(node);
    }

    // The "Beats" Range chmax
    void update_chmax(lli node, lli start, lli end, lli l, lli r, lli v) {
        if (r < start || end < l || tree[node].min1 >= v) return;
        if (l <= start && end <= r && tree[node].min2 > v) {
            apply_max(node, v);
            return;
        }
        push_down(node);
        lli mid = (start + end) / 2;
        update_chmax(2 * node, start, mid, l, r, v);
        update_chmax(2 * node + 1, mid + 1, end, l, r, v);
        push_up(node);
    }

    void point_set(lli node, lli start, lli end, lli idx, lli val) {
        if (start == end) {
            tree[node].min1 = max(val,tree[node].min1);
            tree[node].min2 = INF;
            tree[node].min_cnt = 1;
            tree[node].lazy_add = 0;
            tree[node].lazy_max = NINF;
            return;
        }
        push_down(node);
        lli mid = (start + end) / 2;
        if (idx <= mid) point_set(2 * node, start, mid, idx, val);
        else point_set(2 * node + 1, mid + 1, end, idx, val);
        push_up(node);
    }

    lli query_point(lli node, lli start, lli end, lli idx) {
        if (start == end) return tree[node].min1;
        push_down(node);
        lli mid = (start + end) / 2;
        if (idx <= mid) return query_point(2 * node, start, mid, idx);
        else return query_point(2 * node + 1, mid + 1, end, idx);
    }

    lli query_zeros(lli node, lli start, lli end, lli l, lli r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return (tree[node].min1 == 0) ? tree[node].min_cnt : 0;
        }
        push_down(node);
        lli mid = (start + end) / 2;
        return query_zeros(2 * node, start, mid, l, r) + query_zeros(2 * node + 1, mid + 1, end, l, r);
    }

public:
    SegTreeBeats(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n + 1);
        build(1, 0, n - 1, arr);
    }

    // Operation 1: Subtract 'val', but floor at 0
    void range_sub_cap_zero(lli l, lli r, lli val) {
        update_add(1, 0, n - 1, l, r, -val);
        update_chmax(1, 0, n - 1, l, r, 0);
    }

    // Operation 2: Point Set
    void point_update(lli idx, lli val) {
        // point_set(1, 0, n - 1, idx, max(0LL, val));
        update_chmax(1, 0, n - 1, idx, idx, val);
    }

   // Operation 3: Point Query
    lli get_val(lli idx) {
        return query_point(1, 0, n - 1, idx);
    }

    // Operation 4: Count Zeros in Range
    lli count_zeros(lli l, lli r) {
        return query_zeros(1, 0, n - 1, l, r);
    }
};

void solve(){
lli n=0,m,k=0;string s;
cin>>n>>k;
get(v,n);
SegTreeBeats st(v);
fr(i,k){
    lli id,val;
    cin>>id>>val;
    id--;
    st.range_sub_cap_zero(0,n-1,1);
    st.point_update(id,val);
    cout<<n-st.count_zeros(0,n-1)<<'\n';
}
fr(i,n){
    cout<<st.get_val(i)<<' ';
}

}

int32_t main(){
fastio;
lli test=1;
// cin>>test;
while(test--){
solve();
}
}