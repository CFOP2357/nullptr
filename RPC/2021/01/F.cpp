#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define MAX 1001

int ejex[] = {0, -1, 1,  0},
    ejey[] = {1,  0, 0, -1};

struct celda{
  int dist, xprev, yprev;
};

char mapa[MAX][MAX];
struct celda caminos[MAX][MAX];
bool visitado[MAX][MAX];

void solve(int caso){
  
  //lectura
  int n, m, 
      x, y;
  cin>>m>>n; //leemos al reves las dimensiones
 


  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>mapa[i][j];
      //posicion inicial
      if(mapa[i][j] == '@')
        x = i, y = j;
    }
  }
 
  //se usaran al reconstruir camino
  int xI = x, yI = y;

  //guardamos todos los caminos
  memset(visitado, 0, sizeof(visitado));
  visitado[x][y] = 1;
  caminos[x][y].dist = 0;
  caminos[x][y].xprev = x;
  caminos[x][y].yprev = y;
    
  queue<pair<int, int> >c;
  c.push({x, y});
  while(c.size()){
    x = c.front().first;
    y = c.front().second;
    c.pop();
    for(int i = 0; i < 4; i++){
      int X = x + ejex[i],
          Y = y + ejey[i];
      if(X > -1 && X < n && Y > -1 && Y < m && !visitado[X][Y] && mapa[X][Y] != '#'){
        visitado[X][Y] = 1;
        caminos[X][Y].dist = caminos[x][y].dist + 1;
        caminos[X][Y].xprev = x;
        caminos[X][Y].yprev = y;
        c.push({X, Y});
      }
    }
  }
  //buscamos la distancia maxima
  int distMax = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(mapa[i][j] != '#')
        distMax = max(distMax, caminos[i][j].dist);

  vector<string>ans;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(caminos[i][j].dist == distMax){
            //reconstruimos camino
            string camino = "";
            x = i, y = j;
            //while(x == caminos[x][y].xprev && y == caminos[x][y].yprev){
            while(!(x == xI && y == yI)){
              for(int k = 0; k < 4; k++) //L U R D
                if(x + ejex[k] == caminos[x][y].xprev && y + ejey[k] == caminos[x][y].yprev){
                  if(k == 0)
                    camino += "L";
                  else if(k == 1)
                    camino += "D";
                  else if(k == 2)
                    camino += "U";
                  else 
                    camino += "R";  

                  x += ejex[k];
                  y += ejey[k];
                  break;
                }                                      
            }
            reverse(all(camino));
            ans.push_back(camino);
        }
    sort(all(ans));
    cout<<"Case "<<caso<<":\n";
    cout<<ans.size()<<" "<<distMax<<"\n";
    for(auto i : ans)
       cout<<i<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

/*

5
6 5
...#.#
.##...
..@.##
#.#...
...#.#
6 5
.###.#
.##...
..@.##
#.#...
...#.#
5 6
#####
#..#.
#.###
#...#
###@#
.....
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#...#
..#.#..
13 13
######.######
#####...#####
####.....####
###.......###
##.........##
#...........#
......@......
#...........#
##.........##
###.......###
####.....####
#####...#####
######.######
 
*/