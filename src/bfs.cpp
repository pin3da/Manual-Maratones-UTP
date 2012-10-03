/*
Se considera un Grafo NO dirigido.
*/
 
int N; // number of vertices
vvi G; // lists of adjacent vertices
   
   
void bfs(){ 
  int start_vertex = 0; 
  vi V(N, false); 
  queue<int> Q; 
  Q.push(start_vertex); 
  V[start_vertex] = true; 
  while(!Q.empty()) { 
    int i = Q.front(); 
    Q.pop();
    foreach(G[i], it) { 
      if(!V[*it]) { 
        V[*it] = true; 
        Q.push(*it); 
      } 
    } 
  } 
}  
