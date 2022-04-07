#include <bits/stdc++.h>
#define TASK "NATDIV"
using namespace std;
typedef long long int64;
#define faster cin.tie(nullptr)->sync_with_stdio(0);
const int MAX = 1e6;
int64 af[MAX+16],as[MAX+17];
int64 test,l,r;
int main(int argc,char**argv){
    faster
    #ifndef ONLINE_JUDGE
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #endif
    for(int64 i = 1; i <= MAX; i++){
        if (i != 1){
            af[i]+= 2;   as[i]+= i + 1;
        }
        else{
            af[i]++;    as[i]+=i;
        }
        if(i == 1)
            continue;
        
    for(int64 j = i*2; j <= MAX; j+=i){
       af[j]++;
        as[j]+=i;
    }
    af[i] += af[i-1];
    as[i] += as[i-1];
    }
    cin >> test;
    while(test--){
        cin >> l >> r;
        if(l ==1){
            cout << af[r] << " "<< as[r] << "\n";
        }
        else{
        int64 res = af[r] - af[l - 1];
      int64 rem = as[r] - as[l - 1];
        cout << res << " "<< rem << "\n";
    }
    }
    return 0;
}
