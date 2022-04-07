#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
using int_64 = int32_t;

// gia su cost move tu o thu 1
// luc dau chua co ai nguoi phuc vu danh dau  = 0
// boi vi hai nhan vien ko the cung luc phuc vu tai 1 diem
// vd : nhan vien 1 di phuc vu thi se la 1 , con 2 nhan vien chua phuc vu la 0 - > cu tiep tuc toi phien tiep theo thi ta chi hoan doi 0 vs 1
/*
dp[pos][p1][p2] : o day minh chi xet hai nhan vien ko phuc vu 
gia su nhan vien 1 di phuc vu thi : solve(pos + 1, p2 , p3, index[pos] ) + chi phi de di chuyen (c[p1][index[pos]])
tim min cua ba truong hop -> kq 
;
*/
const int_64 max_n = 500 ;
const int_64 N = 100 ;
const int_64 oo = 2e9 ;

#define xx LLONG_MIN

typedef tuple <int_64 , int_64 , int_64 > t64 ; 

int_64 n , m ;
int_64 index_general[1002] ;
int_64 dp[1002][208][208] ;
int_64 cost[208][208] ;


namespace service
{
        
      int_64 pre_Compute(int_64 pos_n , int_64 pos_1, int_64 pos_2 , int_64 pos_3 )
      {
          if(pos_1 == pos_2 or pos_2 == pos_3 or pos_1 == pos_3) return oo;
          
          if(pos_n > m) return 0;
          
          int_64 &ans = dp[pos_n][pos_1][pos_2] ;
          
          if(ans != -1) return ans ;
          
          ans = oo;
          t64 pos ;
          t64 res{ oo , oo ,oo } ; 
          get<0>(pos) = pre_Compute( pos_n + 1, pos_2 , pos_3 , index_general[pos_n]) + cost[pos_1][index_general[pos_n]] ; 
          get<1>(pos) = pre_Compute(pos_n + 1, pos_1 , pos_3 , index_general[pos_n]) + cost[pos_2][index_general[pos_n]] ; 
          get<2>(pos) = pre_Compute(pos_n + 1, pos_1 , pos_2 ,index_general[pos_n]) + cost[pos_3][index_general[pos_n]] ; 
          ans = min({ans , get<0>(pos) , get<1>(pos) , get<2>(pos)})  ;
          return ans ;
      }
    
}

int32_t main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ; 
    
    memset(dp , -1 ,sizeof(dp)) ; 
    
    cin >> n >> m ;
    
    for(int_64 i = 1; i <= n ;i++)
    {
        for(int_64 j = 1; j <= n ; j++)
        {
            cin >> cost[i][j] ; 
        }
    }
    
    for(int_64 i = 1; i <= m ;i++) cin >> index_general[i]  ;
    
    return cout << service::pre_Compute(1 , 1, 2 , 3)<< "\n" , 0 ; 
    
}
