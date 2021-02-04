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
ull n, q;
stack<int> stk;
multiset<int> ms;

void solve(){
    cin >> n;
    stk = stack<int> ();
    ms.clear();
    for(int i = 0; i < n; i++){
        cin >> q;
        if(q == 1){
            cin >> q;
            stk.push(q);
            ms.insert(q);
        } else if(q == 2 and not stk.empty()){
            ms.erase(ms.find(stk.top()));
            stk.pop();
        } else if(q == 3){
            if(stk.empty())
                cout << "Empty!\n";
            else 
                cout << abs(*ms.begin() - *ms.rbegin() ) << '\n';
        }
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
