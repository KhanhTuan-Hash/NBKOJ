#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
const int MAX = 1e5+7;
const int MOD = 1e9+7;
#define faster cin.tie(0)->sync_with_stdio(false);
function < int64_t (int64_t , int64_t ) >eucilid =[](int64_t A , int64_t B)
{
	if(B == 0 ) return A ; 
	else return eucilid(B , A % B) ; 
} ; 
int64_t def[100007];
	unordered_set<int64_t> cur_gcd;
	set<int64_t> current;
int32_t main(int32_t argc,char*argv[]) {
	faster
	int64_t n;
	memset(def,-1,sizeof(def));
	cin >> n;
	for(int32_t i = 0; i < n; ++i) {
		cin >> def[i];
		for(auto it = current.begin(); it != current.end();) {
			auto g = *it;
			it = current.erase(it);
			auto gcdf = eucilid(g,def[i]);
			current.insert(gcdf);cur_gcd.insert(gcdf);
			//if(cur_gcd[i] == 1) break;
		}
		current.insert(def[i]);
		cur_gcd.insert(def[i]);
	}
	return cout << cur_gcd.size() << '\n',0;
}

