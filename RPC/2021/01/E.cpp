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

typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 10001000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

ull S, G, K;

bool possible(ull n){
  return (S*n + K*((n*(n-1))/2))>G;
}

ull bS(ull l = 0, ull r = MAX){
  if(l+1 >= r)
    return r;

  ull m = (l+r)/2;

  if(possible(m))
    return bS(l, m);
  return bS(m, r);

}

void solve(){
   cin>>K>>S>>G;

  cout<<bS()<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

