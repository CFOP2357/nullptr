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

ull n;
int A[15];

void solve(){
    int a, s, tmp, sum, total = 0;
    cin >> a >> s;

    for(int i = 0; i < a; i++){
        cin >> A[i];
        total += A[i];
    }

    for(int i = 0; i < s; i++){
        sum = 0;
        for(int j = 0; j < a; j++){
            cin >> tmp;
            sum += tmp * A[j];
        }

        long double grade 
        = ((long double)sum) / (5 * total);

        if(grade - trunc(grade) == 0.0){
            cout << 5 * trunc(grade) << " SAME\n";
        }
        else if(grade - trunc(grade) <= 0.5){
            cout << 5 * floor(grade) << " DOWN\n";
        } else {
            cout << 5 * ceil(grade) << " UP\n";
        }
    }

    cout << '\n';

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
