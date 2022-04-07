#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

#define mod (int32_t)(1e9+7)
#define max_n 1003

string s ;
int32_t fact[max_n+ 2] , ifact[max_n + 2] ; 
int32_t s_test ; 

int32_t cnt[300] ; 

auto binpow = [](int32_t a, int32_t b) -> int32_t 
{
    int32_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a =a * a;
        b >>= 1;
    }
    return res;
};

int32_t binapow(int32_t a, int32_t b)
{
    if(!b) return 1;
    int32_t res = binapow(a , b >> 1) ;
    if(b & 1)
         return (1LL*res*res % mod ) * a % mod ;
    return 1LL*res*res % mod   ;     
}




auto solve = []() -> void
{
    fact[0] = 1;
    for(int32_t i = 1; i < max_n ;i++)
    {
        fact[i] = (1LL*fact[i-1]*i) % mod ;
    }
    ifact[max_n - 1] = binapow(fact[max_n - 1] , mod - 2) ; 
    for(int32_t i = max_n - 1 ; i ; i--)
    {
        ifact[i - 1] = (1LL*ifact[i]*i) % mod ;
    }
    for(cin >> s_test; s_test-->0; )
    {
        memset(cnt , 0 ,sizeof(cnt)) ; 
        cin >> s ;
        pair < int32_t , int32_t > __size ;
       __size.first = s.size() ;
       __size.second = fact[__size.first] ; 
    for(char at : s) cnt[(int32_t)at]++;
    for(int32_t at = 'a' ; at <= 'z' ;at++) __size.second = 1LL*__size.second*ifact[cnt[at]] % mod ;
    for(int32_t at = 'A' ; at <= 'Z' ;at++) __size.second = 1LL*__size.second*ifact[cnt[at]] % mod ;
    
    cout << __size.second << "\n" ; 
    }
};


int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0);
    solve() ; 
    assert(true) ;
    return  0; 
}
