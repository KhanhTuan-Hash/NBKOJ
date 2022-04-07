#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
using ll = long long ;

#define MOD (ll)(1e9+7)
#define max_n 100005

ll n , res(0) , a ; 
ll cnt[max_n + 1] ;
ll prime[max_n + 2] ;

function<ll(ll , ll) > binpow = [](ll a , ll n) -> ll
{
  if(!n) return 1;
  ll mid = binpow(a , n >> 1) ;
  if( n & 1)
    return (1LL*mid*mid % MOD) * a % MOD ;
   return 1LL*mid*mid % MOD ;    
};

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
     for(ll i = 0; i < max_n ; i++) prime[i] = binpow( 2 , i) ;
     
     auto merge = [&](ll a , ll b , ll c) -> ll
{
    if(c & 1) return a = (a - b + MOD) % MOD ;
          return a = (a + b) % MOD ;
};
     
     cin >> n;
     
     for(ll x; n-->0; ) // phan tich thua so nguyen to
     {
         
         vector < ll > inver;
         
         cin >> x ;
         for(ll i = 2 ; 1LL*i*i <= x ; i++)
             if(!(x%i))
             {
                 inver.push_back(i) ;
                 while(!(x%i)) x/=i ;
             }
             if(x > 1) inver.push_back(x) ;
          //   cout << x << "\n" ;
             
             for(ll mask = 0; mask < (1 << inver.size()) ; mask++)
             {
                 ll ans = 1;
                 for(ll i = 0; i < inver.size(); i++)
                       if((mask >> i) & 1)  ans*=inver[i] ; 
                       
              
                
              // merge(res , prime[cnt[ans]] , __builtin_popcount(mask) ) ;     
              
              if(__builtin_popcount(mask)  & 1)
              {
                  res = (res + MOD - prime[cnt[ans]]) % MOD ; 
              }
              else 
              {
                  res = (res + prime[cnt[ans]]) % MOD ; 
              }
            
                cnt[ans]++;
                
             }
     }
     cout << res << "\n" ;
    assert(true);
    return 0 ;
}
