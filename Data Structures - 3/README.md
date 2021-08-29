# [Data Structures - 3](https://vjudge.net/contest/455722) #

## [F-RMQ](https://vjudge.net/contest/455722#problem/F) ##
> Editorial by Sajjat

**Solution**
- It is a straightforward problem of range query. It can be solved using **Sparse Table, Segment Tree, Binary Index Tree.**
- Here it is solved using the sparse table.

**Time Complexity:** for build sparse table *O(NlogN)*, for each query *O(1).*

### [Sample Code (C++)](https://github.com/MH-Sajjat/Editorials/blob/main/Data%20Structures%20-%203/F-RMQ.cpp) ###

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

**Time complexity:** for build LCA sparse table *O(NlogN)*, for each query *O(logN)*. Total complexity *O(NlogN) + O(QLogN)*
### [Sample Code (C++)](https://github.com/MH-Sajjat/Editorials/blob/main/Data%20Structures%20-%203/N-LCA.cpp) ###
