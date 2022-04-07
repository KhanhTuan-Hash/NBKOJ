#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;

#define mod (int64_t)(1e9+7)

int64_t prefix[100005] , dp[3002][3002] , n , a[100005] , F[3002][3002] ; 

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    auto solve = [&]() -> void
    {
        cin >> n ;
        memset(F , 0, sizeof(F)) ; 
        memset(dp , 0 , sizeof(dp))  ;
        prefix[0] = 0 ;
        for(int64_t i = 1; i <=n; i++)
        {
            cin >> a[i] ;
            prefix[i] = prefix[i - 1] + a[i] ; 
         //   dp[i][0] = 0; 
          //  dp[i][1] = 1 ;
        }
        F[1][0] = 1 ;
        for(int64_t i = 1 ; i <= n; i++)
        {
            for(int64_t j = 1 ; j <= i; j++) dp[i][j] =( F[j][prefix[i] % j] % mod );
            for(int64_t j = 1 ; j <= i ; j++) F[j+1][prefix[i] % (j + 1)] = (F[j+1][prefix[i] % (j + 1)] + dp[i][j] ) % mod ;
        }
        int64_t res = 0 ;
        for(int64_t i = 1; i <=n ; i++)
        {
           res = (res + dp[n][i] ) % mod ;
        }
        cout << res << "\n" ; 
    } ; 
    solve() ; 
    assert(true) ;
    return 0 ; 
}
