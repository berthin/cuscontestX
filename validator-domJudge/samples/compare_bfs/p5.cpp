#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  int u, v, l;
  scanf("%d", &T);
  for (int iT=1; iT<=T; iT++){
    int N;
    scanf("%d", &N);
    vector < vector < int > > G(N, vector < int > ());
    vector < int > in_degree(N, 0);
    for (int i = 0; i < N - 1; i++) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      in_degree[v]++;
    }
    int root = 0;
    for(; in_degree[root] > 0; root++);
    assert(root < N);
    printf("Caso #%d:\n", iT);
    queue < pair < int, int > > Q;
    Q.push(make_pair(root, 0));
    while (!Q.empty()){
      u = Q.front().first;
      l = Q.front().second;
      Q.pop();
      if (Q.empty())
        printf("%d\n", u);
      if (!Q.empty() && Q.front().second > l){
        printf("%d\n", u);
      }
      if (!Q.empty() && Q.front().second == l){
        printf("%d ", u);
      }
      for (int i = 0; i < G[u].size(); i++)
        Q.push(make_pair(G[u][i], l+1));
    }
  }
}
