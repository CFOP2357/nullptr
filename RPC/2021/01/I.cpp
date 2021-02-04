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

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    ull a, b, r;
    cin >> a >> b;
    while(a and b){
        if(a < 0){
            b += 2;
            a = -a;
        }
        r = b % 4;

        if(r > 1)
            cout << '-';
        
        cout << a;

        if(r & 1ULL)
            cout << 'i';

        cout << '\n';

        cin >> a >> b;
    }    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
