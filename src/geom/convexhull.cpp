
/** Monotone chain algoritm **/

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
  
using namespace std;
#define REMOVE_REDUNDANT

typedef double T;

const T EPS = 1e-7;

struct PT {
  T x, y;
  PT() {}
  PT(T x, T y): x(x),
  y(y) {}
  bool operator < (const PT & rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  bool operator == (const PT & rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
};
T cross(PT p, PT q) {
  return p.x * q.y - p.y * q.x;
}
T area2(PT a, PT b, PT c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
#ifdef REMOVE_REDUNDANT

bool between(const PT & a, const PT & b, const PT & c) {
  return (fabs(area2(a, b, c)) < EPS && 
  (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif

void ConvexHull(vector < PT > & pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector < PT > up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size() - 2], up.back(),...
      ...pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(),...
      ...pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  #ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) 
       dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
  #endif
}

/***Graham scan Algorithm**/

//Graham scan: Complexity: O(n log n)
struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};

point pivot;

inline int distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b){
  return sqrt(distsqr(a, b));
}

//retorna > 0 si c esta a la izquierda del segmento AB
//retorna < 0 si c esta a la derecha del segmento AB
//retorna == 0 si c es colineal con el segmento AB
inline
int cross(const point &a, const point &b, const point &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

//Self < that si esta a la derecha del segmento Pivot-That
bool angleCmp(const point &self, const point &that){
  int t = cross(pivot, that, self);
  if (t < 0) return true;
  if (t == 0){
    //Self < that si está más cerquita
    return (distsqr(pivot, self) < distsqr(pivot, that));
  }
  return false;
}

vector<point> graham(vector<point> p){
  //Metemos el más abajo más a la izquierda en la posición 0
  for (int i=1; i<p.size(); ++i){
    if (p[i].y < p[0].y ||
        (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }

  pivot = p[0];
  sort(p.begin(), p.end(), angleCmp);

  //Ordenar por ángulo y eliminar repetidos.
  //Si varios puntos tienen el mismo angulo el más lejano
  //queda después en la lista
  vector<point> chull(p.begin(), p.begin()+3);

  //Ahora sí!!!
  for (int i=3; i<p.size(); ++i){
    while (chull.size() >= 2 &&
           cross(chull[chull.size()-2],
                 chull[chull.size()-1],
                 p[i]) <=0){
      chull.erase(chull.end() - 1);
    }
    chull.push_back(p[i]);
  }
  //chull contiene los puntos del convex hull ordenados
  //anti-clockwise.  No contiene ningún punto repetido.  El
  //primer punto no es el mismo que el último, i.e, la última
  //arista va de chull[chull.size()-1] a chull[0]
  return chull;
}