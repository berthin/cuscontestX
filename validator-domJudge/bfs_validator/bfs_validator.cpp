#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <string>
#include <iterator>
#include <vector>
#include <stack>
#include <sstream>

const int EXIT_AC = 42;
const int EXIT_WA = 43;

using namespace std;

ifstream judgein, judgeans;

FILE *judgemessage = NULL;
FILE *diffpos = NULL;
int judgeans_pos, stdin_pos;
int judgeans_line, stdin_line;


void judge_error(const char *err, ...) {
	va_list pvar;
	va_start(pvar, err);
	// If judgemessage hasn't been set up yet, write error to stderr
	if (!judgemessage) judgemessage = stderr;
	vfprintf(judgemessage, err, pvar);
	fprintf(judgemessage, "\n");
	assert(!"Judge Error");
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
	stream.open(file);
	if (stream.fail()) {
    exit(EXIT_WA);
		judge_error("%s: failed to open %s\n", whoami, file);
	}
}

bool is_integer(const char *s, int &val) {
	int v;
	if (sscanf(s, "%d", &v) != 1) return false;
	val = v;
	return true;
}

// Solution
#define MAX 1004
vector < vector < int > > G;
bool is_root[MAX];
int out_degree[MAX];
int parent[MAX];
bool visited_nodo[MAX];

vector < int > levels[1004];

#define judgeans cin

void check_header(int ith_caso){
  char correct_header[30];
  string cur_line;
  sprintf(correct_header, "Caso #%d:", ith_caso);
  getline(judgeans, cur_line);
  if (strcmp(cur_line.c_str(), correct_header) != 0)
    exit(EXIT_WA);
}
int main(int argc, char **argv) {
	openfile(judgein, argv[1], argv[0]);
	//openfile(judgeans, argv[2], argv[0]);
  exit(EXIT_AC);

  int n_casos, n_nodos;
  int n_levels;
  int i, j, ith_caso;
  vector <string> tokens;

  //istringstream ss;
  int nodo, root, from_nodo, to_nodo;
  int num_nodos;
  int lvl_nodo;
  int child;

  string cur_line;
  string trash;

  judgein >> n_casos;
  for (ith_caso = 1; ith_caso <= n_casos; ith_caso++) {
    // reading num of nodes
    judgein >> n_nodos;

    // init variables
    G = vector < vector < int > > (n_nodos);
    memset(is_root, true, sizeof is_root);
    memset(out_degree, 0, sizeof out_degree);

    // reading tree
    for (i = 0; i < n_nodos - 1; i++) {
      judgein >> from_nodo >> to_nodo;
      G[from_nodo].push_back(to_nodo);
      is_root[to_nodo] = false;
      parent[to_nodo] = from_nodo;
      out_degree[from_nodo] ++;
    }
    // getting root node
    for (root = 0; !is_root[root]; root++);
    #define show(a) cout << #a << " " << a << endl
    show(root);

    // getting n_levels
    n_levels = 0;
    stack < pair < int, int > > S;
    S.push(make_pair(root, 1));
    while (!S.empty()) {
      nodo = S.top().first;
      lvl_nodo = S.top().second;
      S.pop();
      n_levels = max(n_levels, lvl_nodo);
      for (i = 0; i < G[nodo].size(); i++)
        S.push(make_pair(G[nodo][i], lvl_nodo+1));
    }
    
    // check header for test case
    check_header(ith_caso);
    
    show(n_levels);
    stack < int > levels_out[n_levels];
    // read output
    num_nodos = 0;
    for (i = 0; i < n_levels; i++){
      // reading output and spliting answer
      getline(judgeans, cur_line);
      //ss.str(cur_line);
      istringstream ss(cur_line);
      tokens.clear();
      while(ss >> trash) tokens.push_back(trash);

      for (j = 0; j < tokens.size(); j++) {
        if (!is_integer(tokens[j].c_str(), nodo))
          exit(EXIT_WA);
        if (nodo >= n_nodos)
          exit(EXIT_WA);
        num_nodos++;
        levels_out[i].push(nodo);
      }
    }
    if (num_nodos != n_nodos)
      exit(EXIT_WA);

    // checking root coincides
    nodo = levels_out[0].top();
    levels_out[0].pop();
    show(nodo);
    if (root != nodo)
      exit(EXIT_WA);

    // checking the bfs
    cout << "checking bfs" << endl;
    memset(visited_nodo, false, sizeof visited_nodo);
    S.push(make_pair(root, 0));
    while (!S.empty()) {
      nodo = S.top().first;
      lvl_nodo = S.top().second;
      S.pop();

      if (out_degree[nodo] == 0) {
        out_degree[parent[nodo]] --;
        if (visited_nodo[nodo])
          exit(EXIT_WA);
        visited_nodo[nodo] = true;
      } else {
        if (levels_out[lvl_nodo+1].empty())
          exit(EXIT_WA);
        child = levels_out[lvl_nodo+1].top();
        levels_out[lvl_nodo+1].pop();
        if (parent[child] != nodo)
          exit(EXIT_WA);
        S.push(make_pair(child, lvl_nodo+1));
      }
    }
    cout << "passed case" << endl;
    cout << "...." << endl;
  }
  while (judgeans >> trash) exit(EXIT_WA);
	exit(EXIT_AC);
}
