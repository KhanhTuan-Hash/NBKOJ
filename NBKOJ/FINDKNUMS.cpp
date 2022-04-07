#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;

typedef pair <int64_t,  int64_t > node ;
typedef tuple < int64_t , int64_t , int64_t > adj ;

#define fastio cin.tie(0)->sync_with_stdio(false); 

// phan tich snt 
// ... 

// corner case : neu n la snt thi in ra 1  

node res { 1 , 1 }  , cnt ;

int64_t n ;

int64_t dp[1003][1003] ; 

vector < int64_t > fact ; 

namespace sequence
{   
    
    bool check_prime(int64_t x )
    {
        if(x < 2) return false; 
        if(x % 2 == 0 or x % 3 == 0 ) return false; 
        if(x == 2 or x == 3) return true ;
        for(int64_t i = 5; i*i <= x;  i+=6)
        {
            if(x %  i == 0 or x %(i + 2) == 0) return false; 
        }
        return true; 
    }
    
    bool prime(int64_t x)
    {
        if(x < 2) return false; 
        for(int64_t i = 2; 1LL*i*i  <= x;  i++)
        {
            if(n % i == 0 )
            return false; 
        }
        return true; 
    }
    
    void subtack_1() 
    {
      cout << 1 << "\n" ; 
    }
    
    void subtack_2()
    {
        // phan tich thua so nguyen to 
        for(int64_t i = 2; 1LL*i*i <= n ; i++)
        
        {
            if(n % i == 0 )
            {
                cnt.second = 0; 
                while(n % i == 0 ) n/=i  , cnt.second++ ;
                fact.push_back(cnt.second ) ; 
            }
        }
        if( n != 1) fact.push_back(1) ; 
        sort(fact.begin() , fact.end()) ; 
        cnt.second = *max_element(fact.begin() , fact.end()) ; 
        cnt.first = *min_element(fact.begin() , fact.end()) ; 
        for(int64_t V  : fact)
        {
             memset(dp , 0 , sizeof(dp));
            for(int64_t i = 0; i <= cnt.second ; i++) dp[i][0] = 1; 
            for(int64_t i = 1; i <= V; i++)
                for(int64_t j = 1 ; j <= cnt.second ; j++)
                    for(int64_t k = 0 ; 1LL*k*j <= i ; k++)
                        //dp[j][i] = ((i >= 1LL*j*k ) ? dp[j][i] + dp[j - 1][i - 1LL*k*j] : dp[j- 1][1LL*k*j - i]  ) ;  
                        dp[j][i]  = dp[j][i] + dp[j - 1][ i - 1LL*k*j] ; 
                    res.first *= dp[cnt.second][V]  ; 
                    res.second *= dp[cnt.second - 1][V ] ;
        }
        int64_t ans = res.first - res.second  ;
        cout << ans << "\n" ; 
    }
    
}

int32_t main(int32_t argc,char*argv[])
{
    fastio 
    cin >>n ;
    if(sequence::prime(n) or n == 1){
    sequence::subtack_1() ; 
    }
    else{
    sequence::subtack_2() ; 
    }
    assert(true) ; 
    return 0 ; 
}
