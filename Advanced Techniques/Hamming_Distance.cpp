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
 
      ll n , k ;
      cin >> n >> k ;
      bitset<30> bit[n] ;
      string s[n];
      for( ll i = 0 ; i < n ; i++){ 
        cin >> s[i] ;
        ll mask = 0 ;
        reverse(s[i].begin(), s[i].end()) ;
        for( ll j = 0 ; j < s[i].size() ; j++){ 
          mask+=((s[i][j] - '0')*(1ll << j)) ;
        }
        bit[i] = mask ;
      }
      ll ans = INF ;
      bitset<31>b1 ;
      for( ll i = 0 ; i < n ; i++){
        for( ll j = i + 1 ; j < n ; j++){
          ans = min(ans, (ll)(bit[i]^bit[j]).count()) ;
        }
      }
      cout << ans << endl ;
 
}
