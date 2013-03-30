#include < vector > 
#include < utility > 
using namespace std;

class KuhnImplementation { 
  public: int n, k;
  vector < vector < int > > g;
  vector < int > pairs_of_right, pairs_of_left;
  vector < bool > used;
  
  bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
      int to = g[v][i] - n;
      if (pairs_of_right[to] == -1 || kuhn(pairs_of_right[to])){
        pairs_of_right[to] = v;
        pairs_of_left[v] = to;
        return true;
      }
    }
    return false;
}
  
 vector <pair<int,int>> find_max_matching ...
               ...(vector<vector<int>> & _g, int _n, int _k){
    g = _g;
    //g[i] is a list of adjacent vertices to vertex i, where
    //i is from left part and g[i][j] is from right part
    n = _n;
    //n is number of vertices in left part of graph
    k = _k;
    //k is number of vertices in right part of graph
    
    pairs_of_right = vector <int> (k, - 1);
    pairs_of_left = vector <int> (n, - 1);
    //pairs_of_right[i] is a neighbor of vertex i from right part,
    //on marked edge. pairs_of_left[i]  is a neighbor of vertex 
    //i from left part, on marked edge
    used = vector < bool > (n, false);
    
    
    bool path_found;
    do {
      fill(used.begin(), used.end(), false);
      path_found = false;
//remember to start only from free vertices which are not visited yet
      for (int i = 0; i < n; ++i)
        if (pairs_of_left[i] < 0 && !used[i]) 
          path_found |= kuhn(i);
    } while (path_found);
    
    
    vector < pair < int, int > > res;
    for (int i = 0; i < k; i++)
      if (pairs_of_right[i] != -1) 
        res.push_back(make_pair(pairs_of_right[i], i+n));
    
    return res;
  }
};