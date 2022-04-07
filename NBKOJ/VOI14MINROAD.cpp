#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
const int oo = (int)(1e9+7);

int n ,a , b  ;


int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
        cin >> n >> a >> b;
        vector < pair < int, int> > Tree(n) ;
        for(int i = 0 ; i < n ; i++) cin >> Tree[i].first >> Tree[i].second;
        sort(Tree.begin() , Tree.end()) ;
        vector < int > pos_first(n) , pos_second(n) ;
        int index_first  = 0, index_second  = 0 , res = oo ;
        for(int i = 0; i < n ; i++)
        {
            if(Tree[i].second == 1) pos_first[index_first++] = Tree[i].first ;
            else pos_second[index_second++] = Tree[i].first ;
            if(index_first >= a and index_second >= b)
            {
                res = min(res , Tree[i].first - min(pos_first[index_first - a] , pos_second[index_second - b])) ;
             }
        }
        cout << ((res == oo) ? -1 : res)  << "\n" ;
    assert(true);
    return 0;
}
