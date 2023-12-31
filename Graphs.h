// File: Graphs.h
// Graph library header file for use with Asn#6
/*
______________________________________________________________________________________________

  This file describes a structure for a weighted undirected graph with a maximum of Vmax = 50 
  vertices and Emax = Vmax(Vmax-1)/2 edges. The verices are numbered 0,1,...V-1. The graph is
  assumed to be on a text file in the form of an adjacency matrix. The weights on the edges are
  assumed to be positive integers with zero weight indicating the absence of an edge. 
  An edge (u,v,w) existing between nodes (u) and (v) with weight (w) is modeled as a class
  (Edge). When loaded from the text file, the weights are stored in a  2-D 
  array (AdjMatrix) representing the adjacency matrix. Another  array (edges) stores 
  the non-zero edges in the graph. The functions declared here are needed to implement:

  (1) Depth First Search (DFS_Algorithm) algorithm for graph traversal.
  (2) Dijkstra's Algorithm to compute the shortest paths from a given source node to all other
      nodes in the graph.
_______________________________________________________________________________________________	
*/

#ifndef GRAPHS_H
#define GRAPHS_H
#include <string>
#include "Edge.h"
using namespace std;

const int Vmax = 50;					// Maximum number of vertices
const int Emax = Vmax*(Vmax-1)/2;		// Maximum number of edges

class Graphs
{
   public:
	
//_____________________________________
	// Member Functions
	// Class Constructor & Destructor
	Graphs();
	~Graphs();

// Function Prototypes___________________

	char VertexName(const int s) const;		// Map vertex number to a name (character)
	void getGraph(string fname);		// Get Graph from text File (fname)
	void DisplayAdjecencyMatrix() const;			// Display Ajacency Matrix
	int  NumberOfVertices() const;		// Get number of vertices (V)
	int  NumberOfEdges() const;		// Get Number of Non-zero edges (E)
	void DisplayEdges() const;			// Display Graph edges
	void DFS_Algorithm();				// Depth First Search Traversal (DFS_Algorithm)
	void ShortestPath(int s);			// Shortest paths from node (s)

//______________________________________________________________________________________________


   private:
	   
	   int V, E;				// No.of vertices (V) and edges (E) 
	   weightType AdjMatrix[Vmax][Vmax];	// Adjacency Matrix
	   Edge edges[Emax];			// Array of non-zero edges
	   weightType distance[Vmax];		// Distance array for shortest paths
	   int via[Vmax];			// Via array for shortest paths
	   bool processed[Vmax];		// processed array for shortest paths
	   int order;				// Order of Visit of a node in the DFS_Algorithm
	   int val[Vmax];			// Array holding order of traversal of nodes
	   void GetEdges();			// Get Non-Zero edges from adjacency matrix  
	   void printEdge(Edge e) const;	// Output an edge (e)
	   void PrintPathSourceToDestination(int s,int i) const;	// Print path from source (s) to destination (i)
	   void VisitNode(int k);			// Node Visit Function (needed for DFS_Algorithm)
};
#endif // GRAPHS_H
#include "Graphs.cpp"
  
