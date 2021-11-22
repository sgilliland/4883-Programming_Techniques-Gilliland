// Sarah Gilliland
// UVA 1112 - Mice and Maze
// Dijkstra's single source shortest path algorithm
// This program uses an adjacency matrix representation of the graph 
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;

// function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool shortest[], int N) 
{ 
	// Initialize min values 
	int min = INT_MAX;
  int index; 

	for (int i = 0; i < N; i++) {
    if (shortest[i] == false && dist[i] <= min){
      min = dist[i];
      index = i; 
    }
  }

	return index; 
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int** graph, int exit, int N, int* dist) 
{
	bool shortest[N];             // bool array for if cell is in shortest path
	
	for (int i = 0; i < N; i++)   // Set all distances to INT_MAX and shortest[] to false 
  { 
    dist[i] = INT_MAX;
    shortest[i] = false; 
  }
	
	dist[exit] = 0;                // Distance of exit cell from itself is always 0 

	for (int j = 0; j < N - 1; j++) // Find shortest path for all cells 
  { 
		
		int u = minDistance(dist, shortest, N); // u is min distance and in shortest path
		shortest[u] = true; 

		
		for (int v = 0; v < N; v++)   // Update dist value
    {
      // if dist[u] is not in shortest, there is an edge from u to v, and total weight of path from exit to v through u is smaller than current value of dist[v] 
			if (!shortest[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
      } 
    }
	}

} 

// Function to create the 2D array for the maze
int** Make2dArray(int width, int height)
{
    int** newMaze;
    newMaze = new int*[height];

    for(int i = 0; i < height; i++){
        newMaze[i] = new int[width];
    }

    return newMaze;
}

// Function to display the number of mice
void display(int* otherDist, int V, int T)
{
  int numMice = 0;
  for (int i = 1; i < V; i++)
    {
      if (otherDist[i] <= T)
      {
        numMice++;
      }
    }
    cout << numMice;
}

// Function to deallocate all arrays
void clear(int** g, int* d, int* od){
  delete [] g;
  delete [] d;
  delete [] od;
}

int main() 
{ 
  int tests, counter = 0;
  int N, E, T, M, numMice;
  int a, b, time;
  string x;
  
  cin >> tests;

  int** maze;             // 2D array to hold the maze
  int* dist;              // array to hold distance from exit to cell
  int* otherDist;         // array to hold distance from cell to exit

  while(counter < tests)
  {
    getline(cin, x);		  // read in the blank line
    cin >> N;             // read in number of cells
    cin >> E;             // read in index of the exit cell
    cin >> T;             // read in starting value of timer
    cin >> M;             // read in number of connections

    N++;

    maze = Make2dArray(N, N);

    dist = new int[N];     // Allocate memory for distance arrays
    otherDist = new int[N];

    
    for(int i = 0; i < M; i++)          // Read in all connections
    {
      cin >> a >> b >> time;            // a -> b with time of (int)time
      maze[a][b] = time;                // add to maze array
    }

    for (int j = 0; j < N; j++)
    {
      otherDist[j] = INT_MAX;           // set all values of otherDist to INT_MAX
    }
    
    for (int r = 1; r < N; r++)         // for all cells except the exit cell
    {
      dijkstra(maze, r, N, dist);       // run dijkstras

      if (otherDist[r] > dist[E])       // distance from exit to cell > cell to exit
      {
        otherDist[r] = dist[E];
      }
    }

    display(otherDist, N, T);
    clear(maze, dist, otherDist);

    if (counter != tests - 1)           // output formatting
      cout << "\n\n";
    else
      cout << '\n';

    counter++;
  }
  return 0;
} 