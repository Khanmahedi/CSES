#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll      long long int
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll  INF = 5e18 , nmax = 2501 , block = 350 , N = 1e6 +10;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
string s ;
ll link[N] , tree[N][27] , len[N] , ans[N] , occ[N] ; 
ll idx = 2 , t = 2 , temp = 0 , ending;
void build_Pal_Tree(ll p){
  while(s[p - len[t] - 1] != s[p]) t = link[t] ;
  ll x = link[t] ;
  while(s[p - len[x] - 1] != s[p]) x = link[x] ;
  ll c = s[p] - 'a' ;
  if(!tree[t][c]){
      tree[t][c] = ++idx ;
      len[idx] = len[t] + 2 ;
      link[idx] = len[idx] == 1? 2 : tree[x][c] ;
      if(temp < len[idx]){
        ending = p ;
        temp = len[idx] ;
      }
      ans[idx] = 1 + ans[link[idx]] ;
  }
  occ[t]++ ;
  t = tree[t][c] ;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
 
   for( ll i = 0 ; i <= s.size() ; i++) len[i] = link[i] = 0 , ans[i] = 0 , occ[i] = 0 ;
   for( ll i = 0 ; i <= s.size() ; i++){
    for( ll j = 0 ; j < 27 ; j++) tree[i][j] = 0 ;
   }
 
 
 
   len[1] = -1, len[2] = 0 ;
   link[2] = 1, link[1] = 1 ;
   t = idx =2  ;
   cin >>s ;
   for( ll i = 0 ; i < s.size(); i++){
    build_Pal_Tree(i) ;
   }
 
 
 
   for( ll i = ending - temp +1 ; i <= ending ; i++) cout << s[i] ;
    cout << endl ;
 
  }
   
