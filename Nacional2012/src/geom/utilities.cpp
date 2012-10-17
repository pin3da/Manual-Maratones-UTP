struct point {
  double x;
  double y;

  point () {}
  point (double x_, double y_):x (x_), y (y_) {}

  bool operator < (const point & other) const {
    if (x == other.x)
      return y < other.y;
    return x < other.x;
  }

  double dist (const point & other) {
    double a = x - other.x;
    double b = y - other.y;
    return sqrt (a * a + b * b);
  }
  /**
  * Compara el punto C con el segmento AB.
  * Retorna 0 si son colineales.
  * Mayor que cero si está a la izquierda.
  * Menor que cero si está a la derecha.  
  */
  int cross (const point & a, const point & b) {
    return (b.x - a.x) * (y - a.y) - (x - a.x) * (b.y - a.y);
  }

  void multEsc (int e) {
    this->x *= e;
    this->y *= e;
  }

};
