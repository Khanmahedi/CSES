#include<bits/stdc++.h>
#pragma GCC target("popcnt")
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
 
const int maxN = 3005 ;
bitset<maxN>B[maxN] ;
 
int main(){
    FastIo ;
 
      ll n , k ;
      cin >> n  ;
  
 
      string s[n];
      for( ll i = 0 ; i < n ; i++){ 
           cin >> B[i] ;
      }
      ll ans = 0 ;
      bitset<31>b1 ;
      for( ll i = 0 ; i < n ; i++){
        for( ll j = i + 1 ; j < n ; j++){
          ll tot = (B[i]&B[j]).count(); 
          ans+=(tot*(tot - 1))/2 ;
        }
      }
      cout << ans << endl ;
 
}
