L <- Empty list that will contain the sorted elements
S <- Set of all nodes with no incoming edges
while S is non-empty do
   remove a node n from S
   insert n into L
   for each node m with an edge e from n to m do
       remove edge e from the graph
       if m has no other incoming edges then
           insert m into S
if graph has edges then
   output error message (graph has at least one cycle)
else
   output message (proposed topologically sorted order: L)