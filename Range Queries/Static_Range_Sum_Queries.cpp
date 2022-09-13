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
 
 
 
int main(){
    
    ll n , q ;
    cin >> n >> q ;
    for( ll i = 1 ; i <= n ; i++) cin >> ar[i] ;
    ll pre[n+10] = {} ;
 
    for( ll i = 1 ; i <= n ; i++) pre[i] = pre[i - 1] + ar[i] ;
 
 
    for( ll i = 0 ; i < q ; i++){
      ll ind , x ;
      cin >> ind >> x ;
      cout << (pre[x] - pre[ind - 1]) << endl ;
 
    }
 
 
       
    
}
