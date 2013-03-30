/*
recordar 
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
*/
int N; // Número de vertices.
vvi G; // Grafo.
vi visited; // Vector de visitados.
 
void dfs(int i) { 
  if(!visited[i]) { 
    visited[i] = true; 
    for_each(all(G[i]), dfs); 
  } 
}
  
bool check_graph_connected_dfs() { 
  int start_vertex = 0; 
  visited = vi(N, false); 
  dfs(start_vertex); 
  return (find(all(V), 0) == V.end()); 
} 
