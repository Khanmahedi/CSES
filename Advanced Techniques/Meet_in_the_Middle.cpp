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
ll n ;
unordered_map < ll , ll > mp , mp1  ;
vector < ll > v , a, b;
 
 
int main(){
    FastIo ;
    ll  x ;
    cin >> n>> x ;
    v.resize(n) ;
    for( ll i = 0 ; i < n ; i++) cin >> v[i] ;
      sort(v.begin(), v.end()) ;
    if(n == 1){
      cout << (x == v[0]) << endl ;
      return 0 ;
    }
 
    for( ll i = 0 ; i < n /2 ; i++) a.pb(v[i]) ;
    for( ll i = n/2 ; i < n  ; i++) b.pb(v[i]) ;
     for( int i = 0 ; i < (1ll << (a.size())) ; i++){
      ll sum = 0 ;
      for( int j = 0 ; j < a.size() ; j++){
        ll mask = 1ll << j ;
        if(mask&i) sum+=a[j] ;
      }
      mp[sum]++ ;
    }
    ll ans = 0 ;
     for( int i = 0 ; i < (1ll << (b.size())); i++){
      ll sum = 0 ;
      for( int j = 0 ; j < (b.size()) ; j++){
        ll mask = 1ll << j ;
        if(mask&i) sum+=b[j] ;
      }
      if(mp.find(x - sum) != mp.end()) ans+=((mp[x - sum])) ;
    }
 
    cout << ans << endl ;
 
}
