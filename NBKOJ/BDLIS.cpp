#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define oo LLONG_MAX
#define xx LLONG_MIN

template <class T> void maximize(T &a, T b) {a = max(a,b);}
template <class T> void minimize(T &a, T b) {a = min(a,b);}

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    int64_t n ;
    cin >> n;
  vector<int64_t> a(n)  ,dp(n+1) , cnt(n+1 , oo) ;
    int64_t res = 0;
    for(int64_t &x : a) cin >> x;
     cnt[0] = xx;
     
    for (int64_t x: a) {
        int64_t temp = lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
        cnt[temp] = x;
       maximize(res, temp) ; 
    }
    cout << res ;
    assert(true);
    return 0;
}
