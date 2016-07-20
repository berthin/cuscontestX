/*
   compare -- compare program and testdata output and return diff output.

   This program is a compare script for 'testcase_run.sh' and executes
   a normal 'diff' to detect correct, presentation-error (whitespace
   mostly ignored) or wrong-answer results.

   Usage: compare <testdata.in> <program.out> <testdata.out> <result.out> <diff.out>

   <testdata.in>   File containing testdata input.
   <program.out>   File containing the program output.
   <testdata.out>  File containing the correct output.
   <result.out>    File describing the judging verdict.
   <diff.out>      File to write program/correct output differences to (optional).

   Exits successfully except when an internal error occurs. Program
   output is considered correct when diff.out is empty (if specified)
   and exitcode is zero.

   Output format of differences:

   - First a line stating from which line differences were found.
   - Then all lines from PREVLINES before that line until end of both
     <program.out> and <testdata.out>, formatted as:

	   '<PROGRAM LINE>' X '<TESTDATA LINE>'

	 The left and right sides are aligned and ending quote (') is
     replaced by an underscore (_) if the line is truncated. The
     middle 'X' is one of the following characters:
	 = both lines are identical
	 ! the lines are different
	 < left contains additional lines not present right
	 > vice versa
     $ only end-of-lines characters differ (e.g. LF vs. CR+LF); note
       that only LF is considered to begin a newline and all CR
       characters are stripped.
 */
#include "config.h" 
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <fstream>

#include "lib.error.h"

using namespace std;

#define EXIT_WA false
#define EXIT_AC true

const char *progname;

/* filenames of commandline arguments */
char *testin, *testout, *progout, *result, *diffout;
FILE *testinfile, *progoutfile;

/* Write result file with result message */
void writeresult(int msg)
{
	FILE *resultfile;

	if ( !(resultfile = fopen(result,"w")) ) error(errno,"cannot open '%s'",result);

  char answer[30];
  switch (msg){
    case EXIT_WA: sprintf(answer, "Wrong Answer"); break;
    case EXIT_AC: sprintf(answer, "Accepted"); break;
  }
	fprintf(resultfile,"result=%s", answer);

	fclose(resultfile);
}

/* Definitions below */
int execdiff(int);
void writediff();

/* Validator bfs definitions */
ifstream testinreader, progansreader;

bool is_integer(const char *s, int &val) {
	int v;
	if (sscanf(s, "%d", &v) != 1) return false;
	val = v;
	return true;
}

bool check_header(int ith_caso){
  char correct_header[30];
  string cur_line;
  sprintf(correct_header, "Caso #%d:", ith_caso);
  getline(progansreader, cur_line);
  if (strcmp(cur_line.c_str(), correct_header) != 0) {
    return (EXIT_WA);
  }
  return true;
}

#define MAX 1004
vector < vector < int > > G;
bool is_root[MAX];
int out_degree[MAX];
int parent[MAX];
bool visited_nodo[MAX];

vector < int > levels[1004];

bool validate_program (){
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

  //fscanf(testinfile, "%d", &n_casos);
  testinreader >> n_casos;
  for (ith_caso = 1; ith_caso <= n_casos; ith_caso++) {
    // reading num of nodes
    //fscanf(testinfile, "%d", &n_nodos);
    testinreader >> n_nodos;

    // init variables
    G = vector < vector < int > > (n_nodos);
    memset(is_root, true, sizeof is_root);
    memset(out_degree, 0, sizeof out_degree);

    // reading tree
    for (i = 0; i < n_nodos - 1; i++) {
      //fscanf(testinfile, "%d %d", &from_nodo, &to_nodo);
      testinreader >> from_nodo >> to_nodo;
      G[from_nodo].push_back(to_nodo);
      is_root[to_nodo] = false;
      parent[to_nodo] = from_nodo;
      out_degree[from_nodo] ++;
    }
    // getting root node
    for (root = 0; !is_root[root]; root++);
    #define show(a) //cout << #a << " " << a << endl
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
    if (check_header(ith_caso) == EXIT_WA){
      return (EXIT_WA);
    }
    
    show(n_levels);
    stack < int > levels_out[n_levels];
    // read output
    num_nodos = 0;
    for (i = 0; i < n_levels; i++){
      // reading output and spliting answer
      getline(progansreader, cur_line);
      //ss.str(cur_line);
      istringstream ss(cur_line);
      tokens.clear();
      while(ss >> trash) tokens.push_back(trash);

      for (j = 0; j < tokens.size(); j++) {
        if (!is_integer(tokens[j].c_str(), nodo))
          return (EXIT_WA);
        if (nodo >= n_nodos)
          return (EXIT_WA);
        num_nodos++;
        levels_out[i].push(nodo);
      }
    }
    if (num_nodos != n_nodos)
      return (EXIT_WA);

    // checking root coincides
    nodo = levels_out[0].top();
    levels_out[0].pop();
    show(nodo);
    if (root != nodo)
      return (EXIT_WA);

    // checking the bfs
    //cout << "checking bfs" << endl;
    memset(visited_nodo, false, sizeof visited_nodo);
    S.push(make_pair(root, 0));
    while (!S.empty()) {
      nodo = S.top().first;
      lvl_nodo = S.top().second;
      S.pop();

      if (out_degree[nodo] == 0) {
        out_degree[parent[nodo]] --;
        if (visited_nodo[nodo])
          return (EXIT_WA);
        visited_nodo[nodo] = true;
      } else {
        if (levels_out[lvl_nodo+1].empty())
          return (EXIT_WA);
        child = levels_out[lvl_nodo+1].top();
        levels_out[lvl_nodo+1].pop();
        if (parent[child] != nodo)
          return (EXIT_WA);
        S.push(make_pair(child, lvl_nodo+1));
      }
    }
    //cout << "passed case" << endl;
    //cout << "...." << endl;
  }
  while (progansreader >> trash) return (EXIT_WA);
	return (EXIT_AC);
}

int main(int argc, char **argv)
{
	/* Read arguments. Note that argc counts the number of arguments
	   including the name of the executed program (argv[0]), thus
	   (argc-1) is the real number of arguments. */

	progname = argv[0];
	if ( argc-1<4 ) error(0,"not enough arguments: %d given, 4 required",argc-1);
	if ( argc-1>5 ) error(0,"too many arguments: %d given, max. 5 accepted",argc-1);
	testin  = argv[1];
	progout = argv[2];
	testout = argv[3];
	result  = argv[4];

  // Open test input and program output
  /*if ((testinfile = fopen (testinfile,"r")) == NULL)
    error(errno,"opening file '%s'",testin);
  if ((progoutfile = fopen (progoutfile,"r")) == NULL)
    error(errno,"opening file '%s'",progoutfile);
  */
  testinreader.open(testin, ifstream::in);
  progansreader.open(progout, ifstream::in);
  
  bool judge_answer = validate_program();
  // close files
  progansreader.close();
  testinreader.close();
  
  writeresult(judge_answer);

  return 0;
}

