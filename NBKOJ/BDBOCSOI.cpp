#pragma GCC optimize("O3")
#pragma GCC targte("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

using int_64 = int;

const int_64 N = 25 ;

int_64 dp[351][351][351] ;
int_64 n , k ;
string s ;
int_64 prefix[351] ; 

// c1+c2 = sumC(1,n) - sumC(l , r) -> c2 = sumC( l, r) - sumC(l  ,r) - c1
// prefix on range : c_2 = prefix[n] - (prefix[r] - prefix[l - 1]) - c_1 ;

bool win(int_64 l ,int_64 r , int_64 c_1 )
{
  int c_2 = prefix[n] - (prefix[r] - prefix[l - 1]) - c_1 ;
    if(c_1 >= k) return false;
    if(c_2 >= k) return true;
    int_64 &res = dp[l][r][c_1];
    if(res != -1) return res;
   // cout << l << " " << r << " " <<c_1 << " " << c_2 << "\n" ; 
   return res = ((!win(l + 1, r , c_2) ) or ((!win(l , r - 1, c_2))));
                            
}

int32_t main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
     
    cin >> n >> k >> s;
    //s = "@" + s; 
    prefix[0] = (s[0] == 'C') ; 
    for(int_64 i = 1; i <= n; i++) prefix[i] = prefix[i-1] + (s[i] == 'C') ;
     memset(dp , -1,sizeof(dp));
//    getline(cin,s) ;
  //  getline(cin ,s) ;
//  cout << n << " " << k << " " << s << "\n" ;
   return cout << ((win(0 , n - 1 , 0 ) ? "YES\n" : "NO\n")), 0  ; 
}
