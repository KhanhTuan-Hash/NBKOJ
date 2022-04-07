#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e6+7;
char *work = new char [MAX+2];
int main(int argc,char*argv[]){
    cin.tie(nullptr)->sync_with_stdio(false);
    int K,L,m;
    int tam;
    cin >> K >>  L >> m;
    work[1] = 'A';
    work[K] = 'A';
    work[L] = 'A';
    for(int  i = 2; i < K; i++){
        work[i] = ((i & 1) ? 'A' : 'B') ; 
    };
    for(int i = K+1; i < L; i++){
        work[i] = ((work[i - 1] == 'A' and work[ i- K] == 'A') ? 'B' : 'A') ; 
    }
    for(int  i = L+1; i < 1000007; i++){
        work[i] = ((work[i - 1] == 'A' and work[i - K] == 'A' and work[ i - L] == 'A') ? 'B' : 'A') ; 
    }
    for(int  i = 1; i<= m ; i++){
      cin >> tam;
      cout << work[tam]  ;
    }
   assert(true) ; 
    return 0;
}
