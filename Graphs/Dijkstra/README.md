# Dijkstra's Algorithm
> It’s used to get the shortest path from a single source to all vertices of positively weighted graphs. 

## Algorithm
0. Initially the shortest path to all vertices = ∞, except for the source = 0
1. Start with the source vertex and calculate the costs from it to all directly
connected vertices.
2. If the cost of the current vertex + the cost of the edge of the connected
vertex < the shortest path of the connected vertex (which is initially = ∞),  
then the shortest path of the connected vertex will be = the cost of the
current vertex + the cost of this edge.
3. After calculating the costs of all directly connected vertices, you select
from them the vertex with the minimum shortest path and repeat steps 1,2. 

## Example
<img src="https://user-images.githubusercontent.com/32793798/88547106-90c9e180-d01d-11ea-930e-bbee7cf1c5c9.png" width="400" height="400" alt="step-1">
<img src="https://user-images.githubusercontent.com/32793798/88547171-a3dcb180-d01d-11ea-8806-345d74af1628.png" width="400" height="400" alt="step-2">
<img src="https://user-images.githubusercontent.com/32793798/88547179-a63f0b80-d01d-11ea-89b8-5d39790d9ada.png" width="400" height="400" alt="step-3">
<img src="https://user-images.githubusercontent.com/32793798/88547189-a939fc00-d01d-11ea-97d9-5b66e6e93403.png" width="400" height="400" alt="step-4">
<img src="https://user-images.githubusercontent.com/32793798/88547199-accd8300-d01d-11ea-9956-3c6258b895e7.png" width="400" height="400" alt="step-5">
<img src="https://user-images.githubusercontent.com/32793798/88547208-af2fdd00-d01d-11ea-8ac8-614effa315d4.png" width="400" height="400" alt="step-6">

## Implementation
We need something that keep the vertices sorted in it, we have two
choices: either the set or the priority queue, each of them has a complexity
of `O(log(N))`, but the constant of the complexity of the set is bigger than the
priority queue, which means that the priority queue is faster.

The priority queue implementation is a max heap, it takes three template
parameters: the data type of the elements, the type of the internal
container (vector by default) and compare which is a binary predicate that
takes two elements as arguments and returns a bool (`std::less` by default).
Because we want the priority queue to keep the minimum element in the
front of the queue (not the maximum element), so we give it the third
parameter `<std::greater>` (if “a” is not greater than “b”, then “a” should be
at the front).

The priority queue will do all the work of minimization for you.
We will store the edges in adj list as before, but we need to store the
weight as well, so we will use pair. 

### What if we need to get the path itself?
You can store the parents of the vertices and after you apply Dijkstra, you
loop from the destination vertex until you reach the source vertex which
have parent = -1 and keep pushing vertices in a vector, then print them in
reverse order. 

```cpp
void dijkstra(int source, int n)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, source});
    fill(sp, sp+n, OO);
    sp[source] = 0;
    par[source] = -1;
    while (!pq.empty())
    {
        int u = pq.top().second;
        ll c = pq.top().first;
        pq.pop();
        if (sp[u] < c)
            continue;
        for (auto& v: adj[u])
        {
            if (c + v.second < sp[v.first])
            {
                sp[v.first] = c+v.second;
                par[v.first] = u;
                pq.push({sp[v.first], v.first});
            }
        }
    }   
}
```

### Important notes:
Be careful of overflow when the weight is large, so use `long long` instead of
`int`.

If an overflow happened, you would keep pushing wrong values in the
queue and you will get memory limit or time limit exceeded.

We put the cost at the first parameter of the pair of the priority queue, to
make the queue sorted with respect to cost (the default sort of the pair is
to sort with respect to the first parameter, then the second). 

```cpp
if(c>sp[u])
    continue; 
```
this line to save time (because you may push an edge into the queue many
times, but you don't want to process it if its cost is bigger than the `sp` of it
already), but it won't affect on the answer because you don't change `sp` of
any vertex unless it's less than the current `sp` 

## Practice Problems
- [Dijkstra?](https://codeforces.com/contest/20/problem/C) - [Solution](Dijkstra.cpp)
- [Planets](https://codeforces.com/problemset/problem/229/B)