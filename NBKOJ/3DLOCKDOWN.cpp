// Author : Minh Tuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;
using ll = long long ;

const ll base = 500 ;
const ll N = 1e6 ; 
const ll oo = LLONG_MAX ; 
const ll mod = 1e9 + 7; 

ll d_first[base + 2]  , d_second[base + 2]; 
ll Path[base + 2]  , n , edges[base + 3][base + 3] ; 
vector < ll >::reverse_iterator it ; 
void dijkstra_1()
{
        fill(d_first + 1, d_first + 1 + n , oo - mod) ; 
//    for(ll i = 1 ; i <= n ; i++) d[i].first = 0 ;
   
    priority_queue < pair < ll ,ll > , vector < pair <ll , ll >> ,greater < pair < ll , ll >  > > Heap ; 
     d_first[1] = 0 ;
    Heap.push({0 , 1}) ; 
    while(!Heap.empty())
    {
        ll u = Heap.top().second  ;
        ll du = Heap.top().first ;
        Heap.pop();
        if(d_first[u] != du) continue ;
        for(ll i= 1; i <= n; i++)
        {
            if(edges[u][i] == 0 or edges[u][i] == -1) continue ;
            if(d_first[i] > du + edges[u][i])
            {
                d_first[i] = du + edges[u][i] ;
                    
                Heap.push({d_first[i] , i}) ; 
                Path[i] = u ;
            }
        }
    }
}

void dijkstra_2()
{
        fill(d_first + 1, d_first + 1 + n , oo - mod) ; 
//    for(ll i = 1 ; i <= n ; i++) d[i].first = 0 ;
    d_first[1] = 0 ;
    priority_queue < pair < ll ,ll > , vector < pair <ll , ll >> ,greater < pair < ll , ll >  > > Heap ; 

    Heap.push({0 , 1}) ; 
    while(!Heap.empty())
    {
        ll u = Heap.top().second  ;
        ll du = Heap.top().first ;
        Heap.pop();
        if(d_first[u] != du) continue ;
        for(ll i= 1; i <= n; i++)
        {
            if(edges[u][i] == 0 or edges[u][i] == -1) continue ;
            if(d_first[i] > du + edges[u][i])
            {
                d_first[i] = du + edges[u][i] ;
                Heap.push({d_first[i] , i}) ; 
            }
        }
    }
}
vector < ll > trace ; 



int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cin >> n ;
    for(ll i =1; i <= n ; i++) 
    {
        for(ll j =1; j <= n ; j++)
        {
            cin >> edges[i][j] ;
        }
    }
      dijkstra_1();
    for(ll i = 1; i <= n ; i++) d_second[i] = d_first[i] ;
   ll  res(0);
   for(ll i = 1; i  <= n ; i++)
   {
       ll ans = edges[Path[i]][i]  ;
       edges[Path[i]][i] = -1 ; 
       dijkstra_2() ;
       edges[Path[i]][i] = ans ; 
       ll cnt(0) ;
       for(ll j = 2 ; j <= n; j++)
       {
           if(d_first[j]> d_second[j])
           {
               cnt++; 
           }
       }
        res = max(res, cnt) ;
   }
    
    return cout << res << "\n" , 0 ;
}
