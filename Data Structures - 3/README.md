# [Data Structures - 3](https://vjudge.net/contest/455722) #

## [F-RMQ](https://vjudge.net/contest/455722#problem/F) ##
> Editorial by Sajjat

**Solution**
- It is a straightforward problem of range query. It can be solved using **Sparse Table, Segment Tree, Binary Index Tree.**
- Here it is solved using the sparse table.

**Time Complexity:**
- For build sparse table *O(NlogN)*
- For each query *O(1).*

### [Sample Code (C++)](https://github.com/MH-Sajjat/Editorials/blob/main/Data%20Structures%20-%203/F-RMQ.cpp) ###

<br>

## [N-Lectures Room](https://vjudge.net/contest/455722#problem/K) ##
> Editorial by Sajjat

**Solution**
- Denote that
  - *depth[i]* = distance between root to node *i*.
  - *subTree[i]* = size of subtree of node *i*.
  - *lca(u, v)* = lowest common ancestor of node *u* and *v*. 
- From the overvation we have to consider for each query-
  - If *u = v* then the answere is *N*.
  - If *depth[u] = depth[v]* then find *l = lca(u, v)* and then find ancestor of *u* and *v* node that are the children of *l*. Assume that they are *x* and *y*. So the answere is *N - subTree[x] - subTree[y]*.
  - In all other cases first find distance between *u* and *v* node. If the distance is odd then the answare is 0, otherwise assume that *depth[u] > depth[v]*. Then find *distance(a, b) / 2*-th ancestor of *u* (let's denote it as *p1*), *(distance(a, b) / 2 - 1)*-th ancestor of vertex *a* (denote it as *p2*). Answer is *subTree[p1] - subTRee[p2].*

**Time Complexity**
- for build LCA sparse table *O(NlogN)*
- For each query *O(logN)
- Total : *O(NlogN) + O(QlogN)*

### [Sample Code (C++)](https://github.com/MH-Sajjat/Editorials/blob/main/Data%20Structures%20-%203/N-LCA.cpp) ###
<br>

## [N-LCA](https://vjudge.net/contest/455722#problem/N) ##
> Editorial by Sajjat

**Solution**
- Let *lca(u, v)* is a function that return the lowest common ancestor of node u and v.
- By making node 1 as the root, create a tree.
- in each query, you are given 3 values r, u, v where r = root, u and v are others two nodes.
- Let *x = lca(r, u), y = lca(r, v), z = lca(u, v).*
- from the graph, we get three observations
  - if x = y then the result is z
  - if y = z then the result is x
  - if z = x then the result is y

**Time complexity:**
- For build LCA sparse table *O(NlogN)*
- For each query *O(logN)*
- Total *O(NlogN) + O(QLogN)*

### [Sample Code (C++)](https://github.com/MH-Sajjat/Editorials/blob/main/Data%20Structures%20-%203/N-LCA.cpp) ###
