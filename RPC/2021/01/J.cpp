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

#define MAX 1000010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

ull gauss(ull n){
  return (n*(n+1))/2;
}

vector <ull> ans(MAX);
void pre(){
  ans[1] = gauss(1);

  for(int i=2; i<MAX; i++)
    ans[i] = gauss(i) + ans[i-1];

}


void solve(){
    a.clear(); b.clear();
    cin>>n;
    cout<<ans[n]<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    pre();

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

