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
// Breadth First Search
  void BFS (int start)
  {
    queue < int >q;		// Create a queue for BFS
// Mark the current node as visited and enqueue it
    vector < bool > visited (V, false);
    visited[start] = true;
    q.push (start);
    while (!q.empty ())
      {				// Traverse the graph
// Dequeue a vertex from queue and print it
	int u = q.front ();
	cout << u << " ";
	q.pop ();
// Enqueue all adjacent vertices of dequeued vertex u
#pragma omp parallel for
	for (int i = 0; i < adj[u].size (); i++)
	  {
	    int v = adj[u][i];
	    if (!visited[v])
	      {
		visited[v] = true;
		q.push (v);
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
  cout << "Breadth First Search: ";
  g.BFS (0);
  return 0;
}
