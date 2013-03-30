function Kruskal(G = <N, A>: graph; length): set of edges 
 2    Define an elementary cluster C(v) ? {v}.
 3    Initialize a priority queue Q to contain all edges in G, 
      using the weights as keys.
 4    Define a forest T (empty)    //T will ultimately
                                //contain the edges of the MST
 5     // n is total number of vertices
 6    while T has fewer than n-1 edges do
 7      // edge u,v is the minimum weighted route from u to v
 8      (u,v) = Q.removeMin()
 9      // prevent cycles in T. add u,v only if T does not 
		//already contain a path between u and v. 
10      // the vertices has been added to the tree.
11      Let C(v) be the cluster containing v, and let C(u) be
		the cluster containing u.
13      if C(v) != C(u) then
14        Add edge (v,u) to T.
15        Merge C(v) and C(u) into 1 cluster (union(C(v), C(u))
16    return tree T

Este algoritmo se usa con la estructura de datos disjoint-set.