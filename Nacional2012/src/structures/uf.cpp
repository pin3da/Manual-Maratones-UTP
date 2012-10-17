static class DisjointSet {
  int[] p, rank;
  public DisjointSet(int size) {
    rank = new int[size];
    p = new int[size];
    for (int i = 0; i < size; i++) {
      make_set(i);
    }
  }
  public void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  public void merge(int x, int y) {
    link(find_set(x), find_set(y));
  }
  public void link(int x, int y) {
    if (rank[x] > rank[y]) p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y] += 1;
    }
  }
  public int find_set(int x) {
    if (x != p[x]) p[x] = find_set(p[x]);
    return p[x];
  }
}