#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

using ll = long long ;

#define X first
#define Y second

typedef pair < ll ,ll > NODE ;
typedef pair < NODE , NODE >  node ;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }

node v; 
ll n , m , k , preSum[1002][1002]  , a[1002][1002] ; 
ll res ; 

struct data
{
    ll up , down , bottom , under ; 
} cut ;

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    #ifndef ONLINE_JUDGE
    freopen("MINCUT.INP" , "r" ,stdin);
    freopen("MINCUT.OUT" , "w" ,stdout) ;
    #endif
    //sub_1
   
    cin >> m >> n >> k ;
    for(ll i = 1; i <= m ; i++)
    {
        for(ll j = 1; j <= n ; j++)
        {
            cin >>a[i][j] ; 
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + a[i][j] ; 
        }
    }
    
    auto get_sum = [&](ll x , ll y , ll u , ll v) -> ll
    {
        return preSum[u][v] - preSum[x-1][v] - preSum[u][y-1] + preSum[x-1][y-1] ; 
    };
     auto sub_1 =[&]() -> void
    {
    while(k-->0)
    {
        res = 1e10 + 2; 
        cin >> v.X.X >> v.X.Y >> v.Y.X >> v.Y.Y ; 
        NODE temp{ 0 , 0} ; 
        temp.X = get_sum(v.X.X , v.X.Y , v.Y.X , v.Y.Y); 
        for(ll i = v.X.X ; i < v.Y.X ; i++) // hoanh do
        {
            temp.Y = get_sum(v.X.X , v.X.Y , i , v.Y.Y) ; 
            res = min(res , abs(temp.Y - (temp.X  - temp.Y))) ; 
        }
        for(ll i = v.X.Y ; i < v.Y.Y; i++) // tung do
        {
             temp.Y = get_sum(v.X.X , v.X.Y , v.Y.X , i) ; 
            res = min(res , abs(temp.Y- (temp.X - temp.Y))) ; 
        }
        cout << res <<"\n" ; 
    }
    };
    auto sub_2 = [&]() -> void
    {
        while(k-->0)
        {
      res = 1e10 + 2; 
      cin >> v.X.X >> v.X.Y >> v.Y.X >> v.Y.Y ;
      ll left = v.X.X , right = v.Y.X ; 
      ll total = get_sum(v.X.X , v.X.Y , v.Y.X , v.Y.Y) ;
      while(left <= right)
      {
          ll mid = (left + right) >> 1;
          cut.up = get_sum(v.X.X , v.X.Y , mid ,v.Y.Y ) , cut.down = total - cut.up ; 
          ll diff = cut.up - cut.down ; 
          minimize(res , abs(diff)) ;
          if(diff > 0) right = mid - 1;
          else left = mid + 1;
      }
      left = v.X.Y , right = v.Y.Y ; 
      while(left <= right)
      {
          ll mid = (left + right ) >> 1;
          cut.bottom = get_sum(v.X.X , v.X.Y , v.Y.X , mid)  , cut.under = total - cut.bottom ; 
          ll diff_1 = cut.bottom - cut.under ; 
          minimize(res , abs(diff_1)) ;
          if(diff_1 > 0) right = mid - 1;
          else left = mid + 1;
      }
      cout << res << "\n"  ;
        }
    };
    if(n <= 100 && m <= 100)
    {
        sub_1() ; 
    }
    else 
    {
        sub_2() ; 
    }
    return  0; 
}
