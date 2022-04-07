#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
using int_64 = long long ; 

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }


int_64 prefix[505][505];
int_64 a[505][505];
pair<pair<int_64,int_64>,pair<int_64,int_64>> Intersect(pair<pair<int_64,int_64>,pair<int_64,int_64>> rect1, 
                                                 pair<pair<int_64,int_64>,pair<int_64,int_64>> rect2)
{
    if(rect1.first.first > rect2.first.first)
    {
        swap(rect1,rect2);
    }
    if(rect1.first.first==-1) return {{-1,-1},{-1,-1}};
    int_64 x1 = max(rect1.first.first,rect2.first.first);
    int_64 y1 = max(rect1.first.second,rect2.first.second);
    int_64 x2 = min(rect1.second.first,rect2.second.first);
    int_64 y2 = min(rect1.second.second,rect2.second.second);
    if(x1 > x2 || y1 > y2) return {{-1,-1},{-1,-1}};
    return {{x1,y1},{x2,y2}};

}
pair<int,int> point[10];
void solve()
{
    int_64 n,x,r,p;
    cin >> n >> x >> r >> p;
    int_64 ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
            
            auto getsum_on_board =[&](int x, int y, int u, int v)->int_64
    {
        if(x == -1) return 0 ;
	return prefix[u][v] - prefix[x - 1][v] - prefix[u][y - 1] + prefix[x -1][y - 1];
        };
            
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < p; j++)
        {
            cin >> point[j].first >> point[j].second;
        }
        int_64 total = 0;

        for(int_64 mask = 1; mask < (1<<p); mask++)
        {
            pair<pair<int,int>,pair<int,int>> now = {{1,1},{n,n}};
            for(int k = 0; k < p; k++)
                if(mask&(1<<k)) now = Intersect(now,{{point[k].first,point[k].second},{point[k].first+r-1,point[k].second+r-1}});
            int_64 co = getsum_on_board(now.first.first,now.first.second,now.second.first,now.second.second);
            if(__builtin_popcount(mask) % 2) total += co;
            else total -= co;
        }
        maximize(ans , total) ; 
    }
    cout << ans;


}
int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);  
    solve();
    return 0;
}
