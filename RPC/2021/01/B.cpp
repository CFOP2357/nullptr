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

ull n, k;

ull dp[10010][110]; //N, K
vector<ull> S, V, P;

void solve(){
    S.clear(); V.clear(); P.clear();

    cin>>n>>k;

    for(int i=0; i<=n; i++)
      for(int j=0; j<=k; j++)
        dp[i][j] = -1;

    for(int i=0; i<n; i++){
      ull s, v, p; cin>>s>>v>>p;
      S.push_back(s);
      V.push_back(max(v, p));
    }

    dp[0][0] = 0;
    for(int i = 0; i<n; i++){
      for(int j=0; j<=k; j++){
        if(dp[i][j]<0)
          continue;
        dp[i+1][min(j+S[i], k)] = max(dp[i+1][min(j+S[i], k)], dp[i][j]);
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+V[i]);
      }
    }

    if(dp[n][k]>=0)
      cout<<dp[n][k]<<"\n";
    else
      cout<<"NO SOLUTION\n";



}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


/*
3
3 1
90 1 500
1 2 3
40 100 40
3 92
90 1 500
1 2 3
40 100 40
3 40
9 1 500
1 2 3
4 100 40
*/
