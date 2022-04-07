#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int64_t n , m , res = LLONG_MAX ; 

namespace subtack_3
{
    // use legendre's formula
    // example : !n thi sẽ có [n/m] số chia hết m - >  giá trị của k (luỹ lớn nhất của m để !n % m ) - > luỹ thừa nhỏ nhất của k là [n / m ] ; 
    // - >  k = n/m + [n/m^2] + [n / m^3] + ,,...  
    int64_t get_power(int64_t n , int64_t m )
    {
        int64_t ans = 0 ;
        int64_t pp = m ;
        while(pp <= n and pp > 0)
        {
            ans += (n / pp ) ;
            n*=pp;
        }
        return ans ; 
    }
    int64_t legendre(int64_t n , int64_t m )
    {
        int64_t ans = n / m ; 
        if( n < m) return 0 ; 
        n/=m ;
        while(n >= m )
        {
            ans += ( n / m)  , n/=m ; 
        }
        return (1LL*ans) ; 
    }
    void pre_Compute()
    {
        //phan tich thua so nguyen to cua m 
        // optimize : for từ 2 - > căn của m 
        for(int64_t i = 2; 1LL*i <= m ; i++)
        {
            if(m % i == 0 )
            {
                int64_t cnt = 0 ;
                while(m % i == 0 )
                {
                    m/=i , cnt++; 
                }
                res = min(res, legendre( n , i ) / cnt) ; 
            }
        }
        if(m > 1) res = min(res , legendre( n , m)) ; 
        //not exist when res <= 0 - > k = -1 
        cout  << ((res <= 0  ) ? -1 : res) <<"\n" ; 
    }
}
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cin >> n >> m ;
    subtack_3::pre_Compute() ;
    assert(true) ;
    return 0  ; 
    
}
