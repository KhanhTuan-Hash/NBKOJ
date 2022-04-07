#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
using int_64 = long long;
const int_64 base = 30 ;
const int_64 MOD =1e9+7 ;

#define FAURIST( i ,l ,r , k) for(int_64 i = l ; i <= r; i+=k)

// index start = 0 - > n- 1
int_64 n , m , pow_2 = 0 , pow_3 = 0 , pow_5 = 0 ; 

// dp[n][a][b][c] : so cach gieo 
// so lan gieo xuc xac : co dang 2^a*3^b*5^c - > neu m ko co uoc la 2 , 3, 5 -> kq = 0 
// di chuyen trang thai tu n - > n + 1, voi 6 mat thi ......

int_64 dp[105][61][51][41] ;


namespace sub // sub1 + sub2
{
    class xucxac
    {
        public :

     int_64 module(int_64 a, int_64 b)
     {
         if(b == 0) return 1;
         if(b & 1)
         {
             return module(1LL*a*a%MOD , b >> 1) ;
         }
             return 1LL*module(1LL*a*a%MOD , b >> 1)%MOD; 
     }
        
      /*  int_64 solve(int_64 n , int_64 pow_2 , int_64 pow_3 , int_64 pow_5)
        {
            if(n == 0 or m==0) return (pow_5 == 0 and (pow_2 == 0 and pow_3 == 0)) ;
            
            if(dp[n][pow_2][pow_3][pow_5] != -1) return dp[n][pow_2][pow_3][pow_5] ; 
             
             int_64 ans =  solve(n - 1, pow_2 , pow_3 , pow_5) ;     
        
        
            if(pow_2 >= 1)
            {
                ans = (ans + solve( n - 1, pow_2 - 1, pow_3 , pow_5 )) % MOD ;
                // sau mot luot gieo thi so luot giam -> n -> n-1
            }
            if(pow_3 >= 1)
            {
                ans = (ans + solve ( n - 1, pow_2 , pow_3 - 1, pow_5 )) % MOD ;
            }
            if(pow_2 >= 2)
            {
                ans = (ans + solve(n - 1, pow_2 - 2, pow_3 , pow_5)) % MOD ;
            }
            if(pow_2 >= 1 && pow_3 >= 1)
            {
                ans = (ans + solve( n - 1, pow_2 - 1, pow_3 - 1 , pow_5)) % MOD ; 
            }
            if(pow_2 >=1 && pow_5 >= 1)
            {
                ans = (ans + solve(n - 1, pow_2 - 1, pow_3 , pow_5 - 1)) % MOD ;
            }
            if(pow_5 >= 1)
            {
                ans = (ans + solve( n - 1 , pow_2 , pow_3 , pow_5 - 1)) % MOD ;
            }
            if(pow_5 >= 1 and pow_3 >= 1)
            {
                ans = (ans + solve( n - 1 , pow_2 , pow_3 - 1, pow_5 - 1)) % MOD ; 
            }
            dp[n][pow_2][pow_3][pow_5] = ans ;
            return ans ; 
        }*/
    };
}

sub::xucxac A ; 

int32_t main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    
    cin >> n >> m ; 
    
    while(m > 0 && (m % 2 == 0))
    {
        m/=2 , pow_2++;
    }
    while(m > 0 && (m % 3 == 0))
    {
        m/=3 , pow_3++ ; 
    }
    while(m > 0 && (m % 5 == 0))
    {
        m/=5 , pow_5++;
    }
    
    // cout << n << " " << m << "\n" ; 
    
    //memset(dp , -1, sizeof(dp)) ; 
    
    if(m != 1)
    {
        cout << 0 << "\n" ; return  0 ;
    }
    dp[0][0][0][0] = 1; 
    
  for(int_64 i = 0; i < n ;i++)
            {
                for(int_64 j = 0; j <= pow_2 ; j++)
                {
                    for(int_64 k = 0; k <= pow_3 ; k++)
                    {
                        for(int_64 v = 0; v <= pow_5 ; v++)
                        {
                            dp[i + 1][j ][k][v] += dp[i][j][k][v]  , dp[i+ 1][j][k][v] %= MOD ;// face 1 
                            dp[i + 1][j + 1][k][v] += dp[i][j][k][v] , dp[i + 1][j][k][v] % MOD ; // face 2
                            dp[i + 1][j][k + 1][v] += dp[i][j][k][v] , dp[i+1][j][k + 1][v] % MOD ; // face 3
                            dp[i + 1][j][k][v + 1] += dp[i][j][k][v] , dp[i+1][j][k][v + 1]%MOD;// face 4
                            dp[i + 1][j + 1][k + 1][v] += dp[i][j][k][v] , dp[i+1][j+1][k+1][v] % MOD ; // face 5
                            dp[i+1][j + 2][k][v] += dp[i][j][k][v] , dp[i+1][j + 2][k][v] % MOD ; // face 6
                        }
                    }
                }
            }
      // cout << pow_2 << " " << pow_3 << " " << pow_5 << " " << "\n" ; 
    
    return cout << dp[n][pow_2][pow_3][pow_5] << "\n" ,0;
    
}
