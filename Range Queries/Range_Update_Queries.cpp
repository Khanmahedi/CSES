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
 
int a[N];
struct ST {
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void pushdown(int n, int b, int e) {
    if (lazy[n] == 0) return;
    int l = n << 1 , r = l | 1 ;
    t[n]+=lazy[n] ;
     if (b != e) {
      lazy[l] = lazy[l] + lazy[n];
      lazy[r] = lazy[r] + lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1 , l = n << 1 , r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = max(t[l] , t[r]) ;
  }
  void update(int n, int b, int e, int i, int j, long long v) {
    pushdown(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      pushdown(n, b, e);
      return;
    }
    int mid = (b + e) >> 1 , l = n << 1 , r = l |1;
    update(l, b, mid, i, j, v);
    update(r, mid + 1, e, i, j, v);
    t[n] = max(t[l] , t[r]) ;
  }
  long long query(int n, int b, int e, int i, int j) {
    pushdown(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1 , l = n << 1 , r = l | 1;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
}t;
 
int main(){
  
  int n , q ;
  cin >> n >> q ;
  for( int i = 1 ; i <= n ; i++) cin >> a[i] ;
  t.build(1 , 1 , n) ;
  for( int i = 0 ; i < q ; i++){
    int fg , a , b , u , x;
    cin >> fg ;
    if(fg == 1){
      cin >> a >> b >> u ;
      t.update(1 , 1 , n , a, b , u) ;
    }
    else{
       cin >> x ;
       debug(t.lazy[x]) ;
       cout << (t.query(1 , 1 , n , x , x)) << endl ;
    }
  }    
 
    
}
