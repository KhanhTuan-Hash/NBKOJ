#include <bits/stdc++.h>

using namespace std ;

int64_t n ; 
int64_t cnt , res ;  
int64_t a[100005] ,  dp[100005] ; 
int64_t mark[100005]  ;  
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 

    // iota : 
    cin >> n ; 
    for(int64_t i = 1; i <= n; i++) cin >>a[i] ;
    dp[0] = 1; 
     
    for(int64_t i = 1; i <= n; i++)
    {
        cnt = cnt + a[i] ; 
        for(int64_t j = cnt ; j >= a[i] ; --j)
        {
           // if(j  < a[i]) continue ;
            if(dp[j - a[i]] and !(mark[j]))
            {
                mark[j] = 1;
                res++ ; 
                dp[j] = 1; 
            }
        }
    }
    return cout << res , 0 ; 

}
