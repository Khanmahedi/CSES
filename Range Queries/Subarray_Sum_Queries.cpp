// information for a node 
// prefixsum , sufixsum , max_subarray_sum , total_sum ;
 
#include<bits/stdc++.h>
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod =   998244353  , N = 1e6+10 , INF = 5e18, block = 400 ;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
ll ar[N] ;
struct node{
   ll pre_max = 0 ;
   ll suf_max = 0 ;
   ll all_sum = 0 ;
   ll max_sum = 0 ;
};
 
struct SegmentTree{
  vector < node > tree ;
  SegmentTree(ll n){
    tree.resize(4*n+10) ;
  }
  node combine(node left , node right){
    node notun ;
    notun.max_sum = max(left.max_sum , right.max_sum) ;
    notun.max_sum = max(notun.max_sum, left.suf_max + right.pre_max) ;
    notun.pre_max = max(left.pre_max , left.all_sum + right.pre_max) ;
    notun.suf_max = max(right.suf_max , right.all_sum + left.suf_max) ;
    notun.all_sum = left.all_sum + right.all_sum ;
    return notun ;
  }
  void build(ll Node , ll l , ll r){
    if(l == r){
      tree[Node].pre_max = ar[l] ;
      tree[Node].suf_max = ar[l] ;
      tree[Node].all_sum = ar[l] ;
      tree[Node].max_sum = max(0ll , ar[l]) ;
      debug(l , r) ;
      return ;
     }
     ll mid = (l + r) / 2 ;
     ll left = Node*2 ;
     ll right = Node*2 + 1 ;
     build(left , l , mid) ;
     build(right , mid + 1, r) ;
     tree[Node] = combine(tree[left]  , tree[right]) ;
  }
  
  void Update(ll Node , ll b , ll e, ll point , ll val){
    if(b == e and b == point){
      tree[Node].pre_max = val ;
      tree[Node].suf_max = val ;
      tree[Node].all_sum = val ;
      tree[Node].max_sum = max(0ll , val) ;
      return;
    }
    if(e < point or b > point)
      return;
    
    ll mid = (b + e) / 2 ;
    ll left = Node*2 ;
    ll right = Node*2 +1 ;
    node one , two;
    Update(left , b, mid , point , val) ;
    Update(right , mid +1 , e , point , val) ;
    tree[Node] = combine(tree[left], tree[right]) ;
  }
};
 
 
int main(){
    
    ll n , q ;
    cin >> n >> q ;
    for( ll i = 1 ; i <= n ; i++) cin >> ar[i] ;
    SegmentTree seg(n) ;
    seg.build(1, 1, n) ;
 
 
    for( ll i = 0 ; i < q ; i++){
      ll ind , x ;
      cin >> ind >> x ;
      seg.Update(1, 1, n , ind , x) ;
      cout << seg.tree[1].max_sum << endl ;
 
    }
}
