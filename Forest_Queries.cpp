#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 5e18 , nmax = 2501;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
 
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   
       
    ll n , m ;
    cin >> n >> m ;
 
    ll sum[n+10][n+10] = {}, tot_sum[n+10][n+10] = {} ;
 
    for( ll i = 1 ; i <= n ; i++){
      for( ll j = 1 ; j <= n ; j++){
        char c ;
        cin >> c ;
        if(c == '*') sum[i][j] = 1 ;
      }
    }
 
    for( ll i = 1 ; i <= n ; i++){
      for( ll j = 1 ; j <= n ; j++){
        sum[i][j]+=sum[i][j - 1];
        tot_sum[i][j]+=sum[i][j];
        tot_sum[i][j]+=tot_sum[i-1][j] ;
      }
    }
 
 
 
    for( ll i = 0 ; i < m ; i++){
      ll x, y , x1, y1;
      cin >> x >> y >> x1 >> y1 ;
    
      ll ans = (tot_sum[x1][y1] - (tot_sum[x1][y - 1] + tot_sum[x-1][y1])) + tot_sum[x-1][y-1] ;
      cout << ans << endl ;
    }
           
   
}
