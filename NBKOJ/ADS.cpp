#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
using namespace std;

bool visited[2001];
vector<int32_t> edges[2001];

int32_t n , m ; 

void DFS(int32_t u)
{
    visited[u] = 1;
    for(int32_t i = 0; i < edges[u].size() ; i++)
    {
        if(visited[edges[u][i]]) continue ;
        DFS(edges[u][i]) ; 
    }
}

int main(int argc,char*argv[]){
    cin.tie(0)->sync_with_stdio(false) ; 
    cin >> n >> m;
    
    for(int32_t u , v , i =1; i <= m ; i++)
    {
        cin >> u >> v;
        if(u == v) continue ;
        edges[u].push_back(v) ;
        edges[v].push_back(u) ;
    }
    int32_t components(0) ; 
    for(int32_t i = 1; i <= n ;i++)
    {
        if(!visited[i])
        {
            visited[i] = 1; 
            DFS(i) ;
            components++;
        }
    }
    return cout << m - n + components << "\n" , 0; 
}
