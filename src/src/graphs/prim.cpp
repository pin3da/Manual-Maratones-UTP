Min-heap
Initialization
inputs: A graph, a function returning edge weights weight-function,
and an initial vertex
Initial placement of all vertices in the 'not yet seen' set, set 
initial vertex to be added to the tree, and place all vertices in a 
min-heap to allow for removal of the min distance from the minimum graph.
for each vertex in graph
   set min_distance of vertex to 8
   set parent of vertex to null
   set minimum_adjacency_list of vertex to empty list
   set is_in_Q of vertex to true
set min_distance of initial vertex to zero
add to minimum-heap Q all vertices in graph, keyed by min_distance

/*

Algorithm
In the algorithm description above,
nearest vertex is Q[0], now latest addition
fringe is v in Q where distance of v < 8 after nearest vertex is 
removed
not seen is v in Q where distance of v = 8 after nearest vertex 
is removed
The while loop will fail when remove minimum returns null. 
The adjacency list is set to allow a directional graph to be
returned.
time complexity: V for loop, log(V) for the remove function 

*/

while latest_addition = remove minimum in Q

set is_in_Q of latest_addition to false

add latest_addition to (minimum_adjacency_list of 
(parent of latest_addition))

add (parent of latest_addition) to 
(minimum_adjacency_list of latest_addition)
  
for each adjacent of latest_addition
{

  if ( (is_in_Q of adjacent) and 
  (weight-function(latest_addition, adjacent) < 
   min_distance of adjacent) )
  {

    set parent of adjacent to latest_addition

    set min_distance of adjacent to 
    weight-function(latest_addition, adjacent)

    update adjacent in Q, order by min_distance

  }

}
