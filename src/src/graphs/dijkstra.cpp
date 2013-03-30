/***
* Recordar, typedef pair<int,int> pii;
* typedef vector<pii> vii;
* typedef vector<vii> vvii;
***/

vi D (N, 987654321);
vi P (N, -1);
// D[i] es la distancia desde el vértice inicial hasta i
// P[i] es el predecesor de i en la ruta más corta
priority_queue < pii, vector < pii >, greater < pii > >Q;
//Cola de prioridad con comparador Mayor,
//top() retorna la distancia más lejana.
//Inicializar el vértice inicial.
D[0] = 0;
Q.push (pii (0, 0));
while (!Q.empty ()) {
  pii top = Q.top ();
  Q.pop ();
  int v = top.second, d = top.first;
  if (d <= D[v]) {
    foreach(G[v], it) {
      int v2 = it->first, cost = it->second;
      if (D[v2] > D[v] + cost) {
        D[v2] = D[v] + cost;
        P[v2] = v;
        Q.push (pii (D[v2], v2));
      }
    }
  }
}

//Código basado en TopCoder Algorithms tutorials.
