#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define lim (int64_t)(2e6)

int64_t n;
struct data
{
  int64_t num , save ;  
};
vector < int64_t > res_num , res_save; 
int64_t ans(0) ;
unordered_map < int64_t , int64_t > um ;
int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
     
     auto pre = [&](int64_t a) -> int64_t
     {
         return 1LL*a*(a - 1) / 2; 
     };
    auto pre_c = [&](int64_t u , int64_t v) -> int64_t
    {
      return 1LL*u*v;  
    };
    auto solve = [&]() -> void
    {
        cin >>  n;
        for(int64_t i = 1; i <= 9 ; i++)
        {
           ans = i ;
           while(ans <= lim)
           {
               res_num.push_back(ans) ;
               ans*=10; ans+=i;
           }
           ans = 0 ;
        }
        
        for(int64_t i = 1 , x; i <= n ;i++)
        {
            cin >> x;
            res_save.push_back(x) ; 
            um[x]++;
        }
       sort(all(res_save)) ;
       res_save.erase(unique(all(res_save)) , res_save.end()) ;     
       int64_t kq = 0 ; 
       for(auto V : res_save)
       {
           if(um[V]) 
           {
               for(auto S : res_num)
               {
                   int64_t temp = S - V ;
                   if(!um[temp] or temp <= 0) continue;
                   if(temp > V) kq = kq + pre_c(um[V] , um[temp]) ;  
                   if(temp == V) kq = kq + pre(um[V]) ; 
               }
           }
       }
       cout << kq << "\n" ; 
    };
    solve() ; 
    
    assert(true);
    return 0 ;
}
