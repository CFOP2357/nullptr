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
#define MOD (ull)INT_MAX

vector<ull> a;
vector<ull> b;
ull n;

set<ull> fibNumber;
void solve(){

    cin>>n;

    if(fibNumber.find(n) != fibNumber.end())
      cout<<"YES\n";
    else
      cout<<"NO\n";

}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    ull a = 1, b=0;
    fibNumber.insert(1);
    fibNumber.insert(0);
    for(int i=2; i<=10000; i++){
        b+=a;
        b%=MOD;
        swap(a, b);
        fibNumber.insert(a);
    }

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

