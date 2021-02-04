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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1001

const int MOD = 1e9;

/*
int modpow(int x, int n, int m){
    if(n == 0)
        return 1 % m;
    ull u + modpow(x, n / 2, m);
    u = (u * u) % m;
    if(n % 2 == 1)
        u = (u * x) % m;
    return u;
}
*/

ull p(ll a, ull b){
    if(a < 0)
        a += MOD;

    if(b==0)
        return 1;
    if(b==1)
        return a;

    ull ans = p(a,b/2);
    ans *= ans;
    ans %= MOD;

    if(b%2){
        ans *= a;
        ans %= MOD;
    }

    return ans;

}
ll arr[102];

void solve(){
    ull k, q, num, x;
    cin >> k >> q;
    for(int i = 0; i < k; i++)
        cin >> arr[i];
    for(int i = 0; i < q; i++){
        cin >> num;
      cout << p(arr[num % k], 1 + num / k) << '\n';
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
