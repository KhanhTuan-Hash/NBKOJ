#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std ; 
using ll  = int ;

typedef pair < ll ,ll >  node ; 

#define maxx 11 

template<class X, class Y> bool maximize(X &a, Y b)
{
    if(a >= b) return false;
    a = b;
    return true;
}

template<class X, class Y> bool minimize(X &a, Y b)
{
    if(a <= b) return false;
    a = b;
    return true;
}

/*
quan ma co the di toi 8  vi tri
        (-2 , -1 )         (-2 , 1)
   (-1 ,-2)                        (-1 , 2)
                  (0 , 0 ) 
    (1 , -2 )                       (1 , 2)
        (2 , -1)           (2 , 1)
*/

const ll Dx[] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2} ; 
const ll Dy[] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 } ;


ll res, point ; 
ll n , k  , a[10][10] ; 
bool mark[10][10]  ; 
ll row[1003] , col[1003] , cheo_phu[10] , tam[20] ;
ll* cheo_chinh = tam + 11 ; 
namespace Knight
{
      void Ma_Hau(ll move , ll x , ll y)
    {
    //   if(move > n ) exit(0) ; 
       if(move  > n) return ;
        if(move == n)
        {
            maximize(res,  point) ; 
            return ; 
        }
        
        for(ll i = 0; i < 8 ;i++)
        {
            node o ; 
            o.first = x + Dx[i] ;
            o.second = y + Dy[i] ;
            if(o.first < 1 or o.first > 8 or o.second < 1 or o.second > 8) continue ; 
            if(mark[o.first][o.second] )
            {
                if(row[o.first]  > 1 or col[o.second] > 1 or cheo_phu[o.first + o.second] > 1 or
                                                             cheo_chinh[o.first - o.second] > 1) continue ;
                    mark[o.first][o.second ] = false; 
                    row[o.first]--, col[o.second]--;
                     cheo_phu[o.first + o.second]--;
                    cheo_chinh[o.first - o.second]-- ;
                    Ma_Hau(move + 1 , o.first , o.second) ;
                    mark[o.first][o.second] = true ; 
                    row[o.first]++ , col[o.second]++;
                    cheo_phu[o.first + o.second]++;
                    cheo_chinh[o.first - o.second]++;
                    
            }
            if(row[o.first] or col[o.second] or cheo_chinh[o.first - o.second] or cheo_phu[o.first + o.second] ) continue ;
            ll temp = a[o.first][o.second] ;
            point+=temp  , a[o.first][o.second] = 0;
            Ma_Hau(move + 1, o.first , o.second) ;
            point-=temp , a[o.first][o.second] = temp ; 
        }
        
        
    }
}

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ; 
    cin >> n >> k ; 
    
    for(ll i = 1; i <= 8 ; i++)
    {
        for(ll j  = 1 ; j <= 8 ; j++)
        {
            cin >> a[i][j] ; 
        }
    }
    string s ; 
    while(k-->0)
    {
        cin >> s ;
        node val ;
        val.first = s[1] - '0' ; 
        val.second = s[0] - 'A' + 1;  
        row[val.first]++ , col[val.second]++;
        cheo_chinh[val.first -val.second]++ ;
        cheo_phu[val.first + val.second]++;
        mark[val.first][val.second] = true ; 
    }
    cin >> s;
    Knight::Ma_Hau(0 , s[1] - '0' , s[0] - 'A' + 1)  ; 
    
    return cout << res , 0 ; 
    
    assert(true) ;
}
