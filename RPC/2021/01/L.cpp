#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

typedef vector<ull> vi;
struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<ull> a;
vector<ull> b;
ull n;

void solve(ull n, ull p){
    vector<ull> min_lamp(n+1, INT_MAX);

    UF uf(n+1);

    while(p--){
        int a, b; cin>>a>>b;
        uf.join(a, b);
    }

    for(ull i=1; i<=n; i++){
      min_lamp[uf.find(i)] = min(min_lamp[uf.find(i)], i);
    }

    set<int> toTurn;
    for(ull i=1; i<=n; i++){
      toTurn.insert(min_lamp[uf.find(i)]);
    }

    for(int ans : toTurn)
      cout<<ans<<" "<<uf.size(ans)<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ull n, p;
    while(cin>>n>>p){
      solve(n, p);
    }

    return 0;
}

