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
 
  struct SegmentTree{
    vector < ll > tree ;
     SegmentTree(ll n){
      tree.resize(4*n+10) ;
     }
    void build(ll node , ll b, ll e){
      if(b == e){
        tree[node] = ar[b] ;
        return ;
      }
      ll mid = (b + e) / 2 , left = node*2, right = node*2 + 1 ;
      build(left , b, mid) ;
      build(right , mid +1 , e) ;
      tree[node] = tree[left] + tree[right] ;
    }
 
    void update(ll node , ll b , ll e  , ll point , ll val){
      if(b == point and b == e){
        tree[node] = val ;
        return ;
      }
      if(b > point or e < point) return ;
      ll mid = (b + e) / 2 , left = node*2 , right = node*2 + 1 ;
      update(left , b, mid, point , val) ;
      update(right , mid +1 , e, point , val) ;
      tree[node] = tree[left] + tree[right] ;
    }
    ll query(ll node , ll b, ll e, ll l , ll r){
      if(b > r or e < l) return  0 ;
      if(l <= b and r >= e) return tree[node] ;
      ll one , two ;
      ll mid = (b + e) / 2, left = node*2 , right = node*2 +1  ;
      one = query(left , b , mid , l , r) ;
      two = query(right , mid +1 , e, l , r) ;
      return one + two ;
    } 
  };
 
 
int main(){
    
    ll n , q ;
    cin >> n >> q ;
    for( ll i = 1 ; i <= n ; i++) cin >> ar[i] ;
    SegmentTree seg(n) ;
    seg.build(1, 1, n) ;
    for( ll i = 0 ; i < q ; i++){
      ll flag , x , y ;
      cin >> flag >> x >> y ;
      if(flag == 1){
        seg.update(1, 1, n, x , y ) ;
      }
      else{
        cout << (seg.query(1, 1, n , x, y)) << endl ;
      }
    }
 
 
       
    
}
