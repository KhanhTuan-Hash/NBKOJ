#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
using i32 = int ;

string s ,x  ;
i32 res = INT_MIN ;
i32 q ;
i32 max_length , pos ;


unordered_map < string , i32 > __hashmap ;
i32 a[27] ;



namespace sub1
{
    void solve()
    {
        while(q-->0)
        {
            string x ;
            cin >> x ; 
            sort(x.begin() , x.end()) ;
            for(i32 i = 0;  i < (i32)s.size(); i++)
            {
                string temp = s.substr(i , (i32)x.size()) ; 
                sort(temp.begin() , temp.end()) ; 
                if(x == temp) 
                {
                    cout << i + 1 << "\n" ; 
                }
            }
        }
    }
}
namespace sub2
{

   void intit()
   {
           while(q-->0)
           {
               cin >> x ; 
            sort(x.begin() , x.end()) ;
          cout << __hashmap[x] << "\n" ;
           }
   }
}

namespace sub3
{
    
    
    void Calc()
    {
        while(q-->0)
        {

            i32 pre_S[40] , pre_X[40] ; 
            memset(pre_X , 0 , sizeof(pre_X )) ; 
            memset(pre_S , 0 , sizeof(pre_S))  ; 
            i32 suit(0) ; 
            
            cin >> x ; 
            
            for(i32  i = 0; i < (i32)x.size() ; i++)
            {
                pre_X[x[i] - 'A']++ ; 
                pre_S[s[i + 1]  - 'A' ]++ ; 
            }
              for (int j = 0; j < 26; j++) suit += (pre_X[j]== pre_S[j]);
            i32 pos = 1; 
            while(1)
            {
                if(suit == 26)
                {
                    cout << pos << "\n" ;
                    break ; 
                };
                pair < i32 , i32 > new_last ; 
                new_last.first = s[pos] - 'A' ;
               
                if(pre_S[new_last.first] == pre_X[new_last.first]) suit--;
                pre_S[new_last.first]--;
                if(pre_S[new_last.first] == pre_X[new_last.first]) suit++;
                
                pos++;
                 new_last.second = s[pos  - 1 + (i32)x.size()]  - 'A';
                 
                if(pre_S[new_last.second] == pre_X[new_last.second]) suit--;
                pre_S[new_last.second]++;
                if(pre_S[new_last.second] == pre_X[new_last.second]) suit++; 
            }
        }
    }
}

namespace conner_case
{
    void xuli()
    {
        if((i32)s.size() == 0 or (i32)x.size() == 0) return ;


        if( ((i32)s.size() == 1 and (i32)x.size() == 0) or ((i32)s.size() == 0 and (i32 )x.size()== 1)) return ;

    if(x.compare(s) == 0)
    {
        cout << "-1\n" ;  return;
    }


    if((i32)x.size() == (i32)s.size())
    {

        cout << "-1\n" ;return ; 
    }
    bool flag = true ;
    for(i32 i = 1; i < (i32)s.size() ; i++)
    {


        if(s.find(x[i]) == string::npos)
        {
             
            s.find_last_of(s.substr( i , (i32)x.size() + 1)) ;
        }
        else
        {

            s.find_first_of(s.substr( i , (i32)x.size() + 1)) ;
        }
    }

    }
}
i32 main(i32 argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cin >>  s;
    s = " " + s ;
    cin >> q;
        max_length = max(max_length , (i32)s.size()) ;
        
        
            // do dai dai nhat cua X la 6
            
        for(i32 i = 1; i < (i32)s.size() ; i++)
        {
            string res = "" ;
             for(i32 j = 0 ; j < 6 ; j++ )
             {
                 if(i + j == (i32)s.size()) break ;
                 res+=s[ i + j] ;

                 string ans = res ; ;
                 sort(ans.begin() , ans.end()) ;
                 if(__hashmap.find(ans) == __hashmap.end()) __hashmap[ans] = i ;

             }
        }
    
        
        conner_case::xuli() ; 
        
        if(q <= 1000  )
        {
           // sub1::solve()  ;
                sub3::Calc() ; 
        }
        else
        {
           
                sub2::intit() ; 

         }
         
         
    assert(true) ; 
    return 0;
    }
