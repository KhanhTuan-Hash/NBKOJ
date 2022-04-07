#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

// phân quân đoàn thành hai tập
// ko chia lẻ , phải chia theo pair hoặc 3 4 cặp trở lên
// sort hai tập sau khi phân chia

// vd test đề : 
/*
input :  
7
2 5 3 1 6  9 5

output : 
7 cách chia : 
1.(5,6) = { 6 , 9 } = 15 -> (1,2,3,4,7) = {2,5,3,1,5} = 2+ 5 + 3 + 1 + 5 = 16 - > suy ra độ chêch lệch giữa 2 tập là 1
tương tự vs 6 cách chia còn lại


*/ 
using namespace std ;
using ll = long long ;

//2e6 

#define um unordered_map
#define pb push_back
#define  ep emplace_back

const ll max_n = 1e6 ; 
const ll inf = 1e18 ; 
const ll base = 100 ; 


// resize  = erase (push  != emplace )

ll n ; 
vector < ll  > a1 , a2 , b1 , b2 ; 
pair <ll , ll > doan ; 
um < ll ,ll > save ;


namespace bfdiv

{
    void sol()
    {
        cin >> n; 
       // phan thanh 2 tap { n /2 , n - n /2 } ; 
       doan.first = n >> 1 ; 
       doan.second = n - (n >> 1) ; 
       for(ll i = 0  ; i <  doan.first; i++)
       {
           ll x ; cin >> x ; a1.ep(x) ;
       }
       for(ll i = 0 ;  i<  doan.second ; i++)
       {
           ll x; cin >> x; a2.ep(x) ; 
       }
       auto generate = [](ll n  , vector < ll > &c1  ,vector <ll > &c2)// sinh nhi phan by bitmask
       {
           ll sum(0)  ; 
           for(auto V : c1)
           {
               sum+=V; 
           }
           // 1 <<  n = 2 mu n
           const ll module = 1 << n ;
           for(ll mask = 0;mask < module ; mask++)
           {
              ll cnt =  0 ;
               for(ll  i = 0; i < n ; i++ )
               {
                   if((mask >> i ) & 1)
                   {
                       cnt+=c1[i] ; 
                   }
               }
               c2.ep(2LL*cnt - sum)  ;
           }
           
       };
       
       generate(doan.first  , a1 , b1) ; 
       generate(doan.second , a2 , b2) ; 
       
       // theo nhom 1
       
       for(ll a : b1)
       {
           ++save[a];
       }
       
     sort(b1.begin() , b1.end()) ; 
     b1.erase(unique(b1.begin() , b1.end() ) , b1.end()) ; 
     b1.resize(unique(b1.begin()  , b1.end()) - b1.begin())  ; 
       
       ll min_diff = LLONG_MAX ;
      ll way(-1);
       
       for(ll A : b2)
       {
           auto s = lower_bound(b1.begin() , b1.end() , A);
         //  auto e = upper_bound(b1.begin() , b1.end() , A) ;  
           if(s != b1.end() && *s - A <= min_diff)
           {
               if(*s- A < min_diff)
               {
               min_diff = *s - A ;
               way = 0  ; 
               }
               way+=save[*s] ; 
              //  cout << min_diff << " " << way << "\n"  ; 
           }
          
        /*  if(e - 1 != b1.end() and ((*e - 1) - A) <= min_diff)
           {
               if(min_diff > (*e - 1) - A)
               {
                   min_diff = (*e - 1) - A ; 
                   way = 0 ;
               }
               way+=save[*e - 1] ; 
              //  cout << min_diff  << " " << way << "\n" ; 
           }
       */
       }
      if(min_diff == 0) 
      {
          way /=2;  
      }   
          cout << min_diff << " " << way << "\n" ; 
       
    }
}

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ; 
    bfdiv::sol() ; 
    assert(true); 
    return 0 ;
}
