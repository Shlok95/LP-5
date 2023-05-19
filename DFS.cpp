#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>
using namespace std;
class Graph
{
private:
  int V;			// Number of vertices
    vector < vector < int >>adj;	// Adjacency list
public:
    Graph (int V)
  {
    this->V = V;
    adj.resize (V);
  }
  void addEdge (int u, int v)
  {				// Add edge to graph
    adj[u].push_back (v);
    adj[v].push_back (u);
  }
// Depth First Search
  void DFS (int start)
  {
    stack < int >s;		// Create a stack for DFS
// Mark the current node as visited and push it
    vector < bool > visited (V, false);
    visited[start] = true;
    s.push (start);
    while (!s.empty ())
      {
// Pop a vertex from stack and print it
	int u = s.top ();
	cout << u << " ";
	s.pop ();
// Push all adjacent vertices of popped vertex u
#pragma omp parallel for
	for (int i = 0; i < adj[u].size (); i++)
	  {
	    int v = adj[u][i];
	    if (!visited[v])
	      {
		visited[v] = true;
		s.push (v);
	      }
	  }
      }
  }
};

int
main ()
{
  Graph g (7);
  g.addEdge (0, 1);
  g.addEdge (0, 2);
  g.addEdge (1, 3);
  g.addEdge (1, 4);
  g.addEdge (2, 5);
  g.addEdge (2, 6);
  cout << "Depth First Search: ";
  g.DFS (0);
  return 0;
}
