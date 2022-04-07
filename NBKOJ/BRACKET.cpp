#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;
using i64 = int64_t ; 
using i32 = int32_t ; 

template < class X , class Y > inline bool maximize(X &a , Y b)
{
    if(a >= b) return false; 
    a = b ;
    return true ;
}
template <class X , class Y > inline bool minimize(X &a , Y b)
{
    if(a <= b) return false;
    a = b ;
    return true ; 
}

i64 open[100006]  = {} , close[100006]  = {}; 
string s ; 
i64 l , r ;
i64 m ; 
 
const i64 N = 1e6 + 2 ; 

struct NODE
{
    i64 LOCK ; 
    i64 OPEN ; 
    i64 CLOSE ; 
} Seg_tree[N*4 + 2] ; 
 
namespace solve
{
    inline void build( i64 idx , i64 L , i64 R) 
    {
        if(L == R) 
        {
            Seg_tree[idx].LOCK = 0 ; 
            if(s[L] == '(') 
            {
                Seg_tree[idx].OPEN = 1 ;
                Seg_tree[idx].CLOSE = 0 ;
            }
            else
            {
                Seg_tree[idx].OPEN = 0 ; 
                Seg_tree[idx].CLOSE = 1;  
            }
            return ; 
        }
        i64 Mid = (L + R) >> 1 ; 
        build(idx >> 1 , L , Mid) ; 
        build(idx >> 1 | 1 , Mid + 1 , R) ; 
 
         tuple < i64 , i64 , i64 >  Tmp_general , Tmp_first , Tmp_second ; 
        get<0>(Tmp_general)  = Seg_tree[idx].LOCK  ;
        get<0>(Tmp_first)= Seg_tree[idx << 1].LOCK ; 
        get<1>(Tmp_general) = Seg_tree[idx].OPEN  ;
        get<1>(Tmp_first) = Seg_tree[idx << 1].OPEN ; 
        get<2>(Tmp_general) = Seg_tree[idx].CLOSE  ;
        get<2>(Tmp_first) = Seg_tree[idx << 1].CLOSE ;  
        get<0>(Tmp_second) = Seg_tree[idx << 1 | 1].LOCK ;
        get<1>(Tmp_second) = Seg_tree[idx << 1 | 1].OPEN ; 
        get<2>(Tmp_second) = Seg_tree[idx << 1 | 1].CLOSE ;  
        i64 Diff_to_lock = min(get<1>(Tmp_first) , get<2>(Tmp_second)) ; 
        get<0>(Tmp_general) = get<0>(Tmp_first) + get<0>(Tmp_second) + (Diff_to_lock << 1) ;
        get<1>(Tmp_general) = get<1>(Tmp_first) + get<1>(Tmp_second) - Diff_to_lock; 
        get<2>(Tmp_general) = get<2>(Tmp_first) + get<2>(Tmp_second) - Diff_to_lock ;   
    }

    NODE Update(i64 idx, i64 L , i64 R , i64 U , i64 V)
    {
        if(L > V || R <  U) 
        {
            return { 0 , 0 ,0 }  ; 
        }
        if(U <= L && R <= V) 
        {
            return { Seg_tree[idx].LOCK , Seg_tree[idx].OPEN , Seg_tree[idx].CLOSE} ; 
        }
        i64 Mid = (L + R) >> 1 ;
        
       pair < NODE , NODE > L_R ; 
       L_R.first = Update(idx << 1 , L , Mid , U , V) ;
       L_R.second = Update(idx << 1 | 1 , Mid + 1 , R , U , V) ; 

       i64 Diff_to_lock = min(L_R.first.OPEN , L_R.second.CLOSE) ; 

       tuple < i64 , i64 , i64 > KEY ; 
       get<0>(KEY) = L_R.first.LOCK + L_R.second.LOCK + (Diff_to_lock << 1) ; 
       get<1>(KEY) = L_R.first.OPEN + L_R.second.OPEN - Diff_to_lock ; 
       get<2>(KEY) = L_R.first.CLOSE + L_R.second.CLOSE - Diff_to_lock ; 
       
       return {get<0>(KEY) , get<1>(KEY) , get<2>(KEY)} ;  
     }
    inline void Inp_Out()
    {
       cin >> s; 
       i64 __size = s.length() ; 
       build(1 , 0 , __size - 1) ; 

       cin >> m  ;
        
       while(m-->0)
       {
           cin >> l >> r; 
           cout << Update( 1 , 0 , __size - 1 , l - 1 , r - 1).LOCK << "\n" ; 
               }

    }

}

//const i64 N = (i64)(1e6+2) ; 


struct Marvel 
{
    i64 Optimal  , Op , Cl ; 
} ; 

Marvel SEG[4*N ] ; 
Marvel operator + (const Marvel &LEFT , const Marvel &RIGHT)
{
    Marvel Sum ; 
    i64 diff = min(LEFT.Op , RIGHT.Cl) ;
    // diff = min (so dau '(' thua ra o phia ben trai ,  so dau ')'thua ra o phai ben phai ) - 
    // -> de kq toi uu o nut index thi ta co the noi day ngoac toi uu o 2 con 
    //sau do minh se them min (...) ; 
    Sum.Optimal = LEFT.Optimal + RIGHT.Optimal + diff ; 
    Sum.Op = LEFT.Op + RIGHT.Op - diff;
    Sum.Cl = LEFT.Cl + RIGHT.Cl - diff;  
    return Sum ; 
}

inline void Build_tree(i64 INDEX , i64 L , i64 R)
{
    if(L == R)
    {
        // doan l - > r chi co 1 phan tu 
      //  SEG[INDEX] = ((s[L] == '(') ? ({ 0 , 1 , 0}) : ({ 0 , 0 , 1})) ;
        if(s[L] == '(') 
        {
            SEG[INDEX] = { 0 , 1 , 0 } ; 
        }
        else 
        {
            SEG[INDEX] = { 0 , 0 , 1} ; 
        }
        return  ; 
    }
    i64 MID = (L + R) >> 1 ; 
    Build_tree(INDEX << 1 , L , MID) ; 
    Build_tree(INDEX << 1 | 1 , MID + 1 , R ) ; 
    SEG[INDEX] = SEG[INDEX << 1] + SEG[INDEX << 1 | 1] ; 
}
// cap nhap  lay  min 

Marvel GET_QUE(i64 INDEX , i64 L , i64 R , i64 Un , i64 Vn)
{
    if(L > Vn || R < Un) return { 0 , 0 , 0 }  ; 
    if(L >= Un && R <= Vn) return SEG[INDEX] ; 
    i64 MID = (L + R ) >> 1; 
    return  GET_QUE(INDEX << 1 , L , MID , Un , Vn)
                        + GET_QUE(INDEX << 1 | 1 , MID + 1 , R , Un , Vn )  ; 
}

inline void TREE()
{
    cin >> s >> m ; 
    s = "!" + s ;
    Build_tree(1 , 1 , s.size()) ; 
    while(m-->0)
    {
        i64 trai , phai ; 
        cin >> trai >> phai ;
        Marvel TMP = GET_QUE(1 , 1 , s.size() , trai , phai ) ; 
        cout << (TMP.Optimal << 1) << "\n" ;  
    }
}
i32 main(i32 argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ; 
    auto sub_bip = [&]() -> void 
    {
    cin >> s >> m ; 
    i64 _size = s.size() ; 
    for(i64 i = 0 ; i < _size;  i++)
    {
        if(s[i] == ')') 
        {
            close[i] = 1; 
        }
        if(s[i] == '(')
        {
            open[i] = 1;  
        }
        open[i] = open[i] + (open[i-1]) ; 
        close[i] = close[i] = (close[ i - 1]) ; 
        close[i] = min(close[i] , open[i]) ; 
    }

     while(m-->0)
     {
         cin  >> l >> r ;
         if(l > r) continue ; 
         open[l] = (( l == r)  ? open[l == r ]  : open[l] + open[l - 1]) ; 
         close[l] = (( l == r) ? close[l == r] : close[l] + close[l - 1]) ; 
         i64 t = l ;
         while(s[t - l ] != '(') t++ ; 
         pair < i64 , i64 > Get ;
         Get.first = abs(close[r - 1] - close[t - 2] ); 
         Get.second = abs(open[r - 1]  - open[t - 2]) ; 
        cout << min(Get.first , Get.second) * 2  <<"\n" ; 
     }
    } ;
   if(m == 1){
      solve::Inp_Out() ;   
   } 
   TREE() ; 
   assert(true) ;
   return 0 ; 
}

/// y tuong cho sub_1 : prefix  on range with open and close 
// full sub : segment _tree or frenwick
