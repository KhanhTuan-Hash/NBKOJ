// Author : .. Khanh Tuan itk20

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Os")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")

#include<bits/stdc++.h>
#include <assert.h>

using namespace std;
using RR = long long int ;  
 
 
const int N = 100005;
vector < int >  Tree[N << 1];
 
RR art[N << 1] , arr[N << 1]  , index_tree[N * 4] , sub[N  << 1] , in[N << 1] ; 
int _timer = 0;
 
 namespace subt  
 {
void dfs(int node, int par)
{
	sub[node] = 1;
	in[node] = ++_timer;
	art[in[node]] = arr[node];
	
	for(int child : Tree[node])
	if(child != par)
	dfs(child , node) , sub[node] += sub[child];
}
 
void build_tree(int index , int l , int r)
{
	
	if(l == r){
       index_tree[index] = art[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build_tree(index << 1 , l , mid);
	build_tree(index << 1 | 1 , mid+1 , r);
	
	index_tree[index] = index_tree[index << 1] + index_tree[index << 1 | 1];
}
 
void update(int index, int l , int r , int que , int value)
{
	if(l > que or r < que) return;
	
	if(l == r)
	{
		index_tree[index] += value;
		return;
	}
	
	int mid = (l + r) >> 1;
	update(index << 1 , l , mid , que , value);
	update(index << 1 | 1, mid+1 , r , que , value);
	
	index_tree[index] = index_tree[index << 1] + index_tree[index << 1 | 1]; 
}
 
RR get_sum(int index, int l , int r , int u , int  v)
{
	if(l > v || r < u) return 0;
	
	if(l >= u and r <= v)
	return index_tree[index] ;
	
	int mid = (l + r) >> 1;
	
	return (RR)get_sum(index << 1 , l , mid , u , v) + get_sum(index << 1 | 1 , mid + 1, r , u , v) ;  
} 
}
 
int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
	int n , q , a , b , t;
	cin>>n>>q;
	
	for(int i = 1; i <= n; i++) cin >> arr[i] ;
	for(int i = 1; i <= n- 1; i++)
	{
	    cin >> a >> b ;
	    Tree[a].push_back(b) ;
	    Tree[b].push_back(a) ;
	}
	
	subt::dfs(1 , -1);
	subt::build_tree(1 , 1 , n);
	
	while(q--)
	{
		cin>>t;
		
		if(t == 1) {
			cin>>a>>b;
			subt::update(1 , 1 , n , in[a] , b - art[in[a]]);
			art[in[a]] = b;
		}
		else{
			cin>>a;
			cout<<subt::get_sum(1 , 1 , n , in[a] , in[a] + sub[a] - 1) <<"\n" ;
		}
	}
}
