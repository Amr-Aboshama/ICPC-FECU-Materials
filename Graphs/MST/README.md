# Minimum Spanning Tree (MST)
It's a subset of edges so that all the vertices can be reached from all other vertices  
and sum of weights of those edges is minimum.
It has typical usage in many fields. it can be used in roads construction, if you want all the cities to be reachable with minimum cost of construction.  
It's different from Dijkstra, in Dijkstra you have a single source, and you want the minimum cost to reach all other vertices, here you don't have any sources, the MST is for the graph as a whole

## Example
<div align="center">
<img src="https://user-images.githubusercontent.com/32793798/88603034-50e21900-d074-11ea-8609-c599674e4d0a.png" alt="Graph" width="250" height="200">  

Graph
</div>

<div align="center">
<img src="https://user-images.githubusercontent.com/32793798/88603045-55a6cd00-d074-11ea-9458-ece62d4e325f.png" alt="MST" width="250" height="200">  

MST
</div>

## Kruskal's Algorithm
Simply, sort all edges w.r.t its weight, then loop over them and if an edge will connect two different components, add it to the MST  
You can use [DSU](../DSU/README.md) to keep track of the current components.

## Prim's Algorithm
1. Start with a Tree that contain one vertex
2. loop on the adjacent vertices and add them in a min heap or update their value if the current edge weight is lower.
3. extract the minimum vertex and add it to the MST, then repeat step 2
   
```cpp
int prim(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    int cost = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (vis[u])
            continue;
        cost += w;
        vis[u] = 1;
        for (auto& v: adj[u])
        {
            if (!vis[v.first])
                pq.push({v.second, v.first});
        }
    }
    return cost;
}
```
- The priority queue in `c++` doesn't support changing a value of a vertex, so you can push all values, and check when extracting a vertex if it was visited, then don't process it
- The difference between this algorithm and Dijkstra is that you only interested in the weight of the edge that will connect the next vertex, not the cost of the whole path to it (actually there is no path here, nor even a source).

## Practice Problems
- [Dark roads](https://vjudge.net/problem/UVA-11631)
- [Highways](https://vjudge.net/problem/UVA-10147)