// Sarah Gilliland
// UVA 11080 -  Place the Guards
// I used a 1D-vector representation for the graph because I was advised by Taylor Mendez that it would make traversing the graph to check for edge cases easier.
// I used a DFS bipartite checking algorithm to distinguish which vertices would need to have a guard in order to cover the map

#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

// Function returns min number of guards needed if possible and -1 if not possible
int Bipartite(int, vector<int>[]);

int main()
{
    int T, v, e, f, t;
    cin >> T;

    while (T--)
    {
        cin >> v >> e; // read in number of vertices (junctions) and edges (streets)

        vector<int> city[v]; // Create the city map adjacency vector

        for (int j = 0; j < e; j++)
        {
            cin >> f >> t; // two junctions, f and t, have a street connecting them
                           // add f and t to adjacency vector
            city[f].push_back(t);
            city[t].push_back(f);
        }

        cout << Bipartite(v, city) << '\n';
    }

    return 0;
}

// modified from the isBipartite implementation from https://www.geeksforgeeks.org/bipartite-graph/
int Bipartite(int V, vector<int> city[])
{
    int numGuards, current, currentColor;
    vector<int> color(V, -1); // color of each vertex, initially -1 for uncolored

    // queue for BFS storing a vertex and its color
    queue<pair<int, int>> q;

    numGuards = 0;

    // loop through subgraphs in case graph is not connected
    for (int i = 0; i < V; i++)
    {
        int count[2] = {0}; // array to count number of guards that may be used for either color

        //if not coloured
        if (color[i] == -1)
        {
            //coloring with 0 (first color for bipartite algorithm)
            q.push({i, 0});
            color[i] = 0;
            ++count[color[i]];

            // still vertices (junctions) in queue
            while (!q.empty())
            {
                // Dequeue a vertex from queue
                pair<int, int> temp = q.front();
                q.pop();

                //current vertex
                current = temp.first;
                // color of current vertex
                currentColor = temp.second;

                // find vertices connected to current vertex
                for (auto it = begin(city[current]); it != end(city[current]); ++it)
                {
                    int j = *it;

                    // impossible (-1) if a self loop
                    if (color[j] == currentColor)
                        return -1;

                    // color[j] was not assigned a color
                    if (color[j] == -1)
                    {
                        //coloring with opposite color to that of parent
                        if (currentColor)
                            color[j] = 0;
                        else
                            color[j] = 1;

                        ++count[color[j]];
                        q.push({j, color[j]});
                    }
                }
            }
            // increment numGuards counter with the minimum number of guards needed in the subgraph
            numGuards += max(1, min(count[0], count[1]));
        }
    }
    // graph is bipartite so return total number of guards needed
    return numGuards;
}