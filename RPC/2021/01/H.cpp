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

map<string, string> professionOfPrefix;
set<string> bannedPrefix;
ull P, R;

void solve(){
    cin>>P>>R;

    while(P--){
      ull C; cin>>C;

      string PROF = "A-";

      while(C--){
        string s; cin>>s;

        if(PROF == "A-")
          PROF = s;

        string actualPrefix = "";
        for(int i=0; i<s.size(); i++){
          actualPrefix+=s[i];

          if(professionOfPrefix.find(actualPrefix) != professionOfPrefix.end() &&
             professionOfPrefix[actualPrefix]!=PROF)
            bannedPrefix.insert(actualPrefix);
          else if(bannedPrefix.find(actualPrefix)==bannedPrefix.end())
            professionOfPrefix[actualPrefix] =  PROF;

        }

        //cout<<professionOfPrefix["d"]<<"\n";

      }

    }

    while(R--){
      ull N; cin>>N;
      set<string> professions;

      while(N--){
        string s; cin>>s;
        if(professionOfPrefix.find(s) != professionOfPrefix.end() &&
           bannedPrefix.find(s) == bannedPrefix.end()){

            professions.insert(professionOfPrefix[s]);
            //cout<<professionOfPrefix[s]<<" ";
        }
      }

      cout<<professions.size()<<"\n";
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

