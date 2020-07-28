# DSU
> DSU is an abbreviation of “disjoint-set union” (aka “union-find data structure”).  


> It’s used to keep track of number of connected elements in a set, its advantage is that you can use it to know the number of connected vertices after each adding of an edge (it’s useful for large number of queries).  

## Algorithm

> We have two main operations: union and find_set. 

 
> In the beginning, we will set the parent of each vertex in the graph to itself,  
so that, if we have 5 vertices they will look like: {1}, {2}, {3}, {4}, {5} each  
element is alone in its set.  

> If there is an edge between 1 and 2 we will make a union of 1 and 2 and  
they will look like {1, 2}, {3}, {4}, {5}, we set the parent of 2 to 1.  

> Each time we make a union we set the parent of the first (or second)  
element to the parent of the second (or first) element.  

> Find_set will return the parent of the given node specifying which set it belongs to.  


```
If we have the following sets: {1,2,3,4}, {5,6}, {7},then:  
Find_set(1) = 1; Find_set(2) = 1; Find_set(3) = 1; Find_set(4) = 1;  
Find_set(5) = 5; Find_set(6) = 5;  
Find_set(7) = 7;  
```

## Implementation
```cpp
const int N = 2e5+5;
int par[N], arr[N];
int findPar(int n)
{
    if (n == par[n])
        return n;
    return par[n] = findPar(par[n]);
}

void link(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (v == u)
        return;
    par[u] = v;
    arr[v] += arr[u];
}
```
`par` is an array that holds the parent of the nodes, and `arr` is an array that holds the number of elements in each set.  
```cpp
return par[n] = find_set(par[n]);
```
> this line has a great effect in reducing the complexity of find_set function as it updates the parent of the nodes in a certain set as it’s going, thus if we are asking about the parent of a certain node in a large set, we don’t have to traverse all the set to reach the parent of this node.  

> To have a better idea consider this example: `{1,2,3,4}, {5,6}, {7}`  
The par array will look like: `[1,1,1,1,5,5,7]`.

## Problems
- [Virtual Friends](https://vjudge.net/problem/UVA-11503) - [Solution](virtual_friends.cpp)
- [Knight Tournament](https://codeforces.com/problemset/problem/356/A) - [Solution](Knight_Tournament.cpp)
- [Vessels](https://codeforces.com/problemset/problem/371/D)
- [Civilization](https://codeforces.com/problemset/problem/455/C)
- [Destroying Array](https://codeforces.com/problemset/problem/722/C)
- [POSTERS - Election Posters](https://www.spoj.com/problems/POSTERS/en/)
- [String Reconstruction](https://codeforces.com/problemset/problem/827/A)
