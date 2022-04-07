#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;
using int_64 = long long ;

const int_64 MOD = 1e9+7 ;
const int_64 LIM = 2012  ;

const int_64 base = 1e5 ;
const int_64 BASE = 1e3 ;

string s ;
int_64 DP[(BASE << 1)  + 2][ (BASE << 1 ) + 2] ;

int_64 a[5*base + 2] ;

int_64 len  ;

namespace bracket
{
    class sol
    {
        public :
        int_64 process(int_64 l, int_64 r)
        {
            if(r < 0 || a[l] - r < 0) return 0;

             if(DP[l][r] != -1) return DP[l][r] ;

             if(l == len) return r == 0  ;

            int_64 res =  0 ;
            if(s[l + 1] == '(')
            {
                res = (res + process(l + 1 , r + 1) ) % LIM ;
                res = (res + process( l + 1 , r) ) % LIM ;
            }
            else
            {

                res = (res + process(l + 1 , r - 1) ) % LIM ;
                 res = (res + process(l + 1 , r) ) % LIM ;
            }
            return DP[l][r] = res ;
        }
    };
}


int32_t main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cin >> s ; len = s.size() ;
    s = '&' + s ;
    for(int_64 i = 1; i <= len ; i++)
    {
        if(s[i] == '(')
        {
            a[i] = a[i - 1] + 1 ;
        }
        else
        {

            a[i] = a[i - 1] - 1 ;
        }
    }
    memset(DP, -1 ,sizeof(DP)) ;
    bracket::sol A ;
   cout <<  A.process( 0 , 0 ) << "\n" ;
    assert(true );
    return 0 ;
}
