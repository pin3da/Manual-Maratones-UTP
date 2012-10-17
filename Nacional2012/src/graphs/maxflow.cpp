int max_flow()  
result = 0
  while (true) 
    augmenting path found
    path_capacity = find_path()
    if (d = 0) exit while
    else result += path_capacity
  end while
  return result

int bfs() 
  queue Q
  push source to Q
  mark source as visited
  keep an array from with the semnification: from[x] is the 
previous vertex visited in the shortest path from the source to x;
initialize from with -1 (or any other sentinel value) 
  while Q is not empty
    where = pop from Q 
    for each vertex next adjacent to where
      if next is not visited and capacity[where][next] > 0
        push next to Q
        mark next as visited
        from[next] = where
        if next = sink
          exit while loop
    end for
  end while
  where = sink, path_cap = infinity
  while from[where] > -1
    prev = from[where] // the previous vertex 
    path_cap = min(path_cap, capacity[prev][where])
    where = prev
  end while
while 
loop will not be entered
  where = sink
  while from[where] > -1
    prev = from[where]
    capacity[prev][where] -= path_capacity
        capacity[where][prev] += path_capacity
    where = prev
  end while
  if path_cap = infinity
    return 0
  else return path_cap


int pfs() 
  priority queue PQ
  push node(source, infinity, -1) to PQ
  keep the array from as in bfs()
  // if no augmenting path is found, path_cap will remain 0
  path_cap = 0
  while PQ is not empty
    node aux = pop from PQ
    where = aux.vertex, cost = aux.priority 
    if we already visited where continue
    from[where] = aux.from
    if where = sink 
      path_cap = cost
      exit while loop
    mark where as visited
    for each vertex next adjacent to where
      if capacity[where][next] > 0
        new_cost = min(cost, capacity[where][next])
        push node(next, new_cost, where) to PQ
    end for
  end while
  // update the residual network
  where = sink
  while from[where] > -1
    prev = from[where]
    capacity[prev][where] -= path_cap
    capacity[where][prev] += path_cap
    where = prev
  end while
  return path_cap
