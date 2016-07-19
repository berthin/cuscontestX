#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#define show(x) cout << #x << " " << x << endl

#define MAX_N 1000
#define MIN_N 100


int main(int n_args, char *argv[]){
  srand(time(0));

  FILE *testinfile, *testoutfile;
  if (n_args == 1){
    printf("This program receives at least one argument ./program <test_input> <test_output>\n");
    printf("test_output is optional\n");
    return 0;
  }
  if (n_args > 1)
    testinfile = fopen(argv[1], "w");
  if (n_args > 2)
    testoutfile = fopen(argv[2], "w");

  int T = 100;
  fprintf(testinfile, "%d\n", T);

  int tree_level, n_nodes, root, nodes_at_level, idx_nodes;
  vector < int > nodes;
  vector < pair < int, int > > E;

  for (int ith_T = 1; ith_T <= T; ith_T++) {
    // printing # of nodes
    while ((n_nodes = (rand() % MAX_N) + 1) < MIN_N);
    fprintf(testinfile, "%d\n", n_nodes);
    nodes.clear();
    for (int i = 0; i < n_nodes; i++) nodes.push_back(i);
    random_shuffle(nodes.begin(), nodes.end());
    idx_nodes = n_nodes - 1;
  
    // setting tree level
    while((tree_level = (rand() % n_nodes)) > n_nodes * 0.3 || tree_level < n_nodes * 0.15);
    vector < vector < int > > nodes_per_level(tree_level);

    // adding root to the first level
    nodes_per_level[0].push_back(nodes[idx_nodes--]);

    // complete the rest of the graph
    for (int i = 1; i < tree_level; i++) {
      while((nodes_at_level = rand() % (idx_nodes - tree_level + i)) <= 0);

      assert(nodes_at_level > 0);
      while (nodes_at_level --) {
        nodes_per_level[i].push_back(nodes[idx_nodes--]);
      }
    }
    while (idx_nodes >= 0) nodes_per_level[tree_level - 1].push_back(idx_nodes--);

    //create edges
    E.clear();
    for (int i = 1; i < tree_level; i++){
      for (int j = 0; j < nodes_per_level[i].size(); j++) {
        int parent = rand() % nodes_per_level[i - 1].size();
        E.push_back(make_pair(nodes_per_level[i - 1][parent], nodes_per_level[i][j]));
      }
    }

    //print test in
    random_shuffle(E.begin(), E.end());
    fprintf(testinfile, "%d %d", E[0].first, E[0].second);
    for (int i = 1; i < tree_level - 1; i++) fprintf(testinfile, " %d %d", E[i].first, E[i].second);
    fprintf(testinfile, "\n");

    //print test out
    fprintf(testoutfile, "Caso #%d\n", ith_T);
    for (int i = 0; i < tree_level; i++) {
      fprintf(testoutfile, "%d", nodes_per_level[i][0]);
      for (int j = 1; j < nodes_per_level[i].size(); j++)
        fprintf(testoutfile, " %d", nodes_per_level[i][j]); 
      fprintf(testoutfile, "\n");
    }
  }
  fclose(testinfile);
  fclose(testoutfile);
  return 0;
}
