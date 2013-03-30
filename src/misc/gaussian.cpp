static class Matrix {
  Rational[][] data;
  int rows, cols;
  
  Matrix(int rows, int cols) {
    this.rows = rows;
    this.cols = cols;
    data = new Rational[rows][cols];
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        data[i][j] = Rational.zero;
  } 
  void clonar(Matrix a) {
    Matrix nueva = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        nueva.data[i][j] = data[i][j];
  }

  void swapRow(int row1, int row2) {
    Rational[]tmp = data[row2];
    data[row2] = data[row1];
    data[row1] = tmp;
  }

  void multRow(int row, Rational coeff) {
    for (int j = 0; j < cols; j++)
      data[row][j] = data[row][j].times(coeff);
  }

  void addRows(int destRow, int srcRow, Rational factor) {
    for (int j = 0; j < cols; j++)
      data[destRow][j] = data[destRow][j].
    plus(data[srcRow][j].times(factor));
}

  void printMat() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        System.out.print(data[i][j] + " ");
      System.out.println();
    }
  }
};

static void gaussianElim(Matrix m){
  int rows = m.rows;
  for (int i = 0; i < rows; i++) {
  int maxrow = i;
  Rational maxval = m.data[i][i];
  for (int k = i + 1; k < rows; k++) {
    if (maxval.abs().compareTo(m.data[k][i].abs()) < 0) {
      maxval = m.data[k][i];
      maxrow = k;
    }
  }
  if (maxval.compareTo(Rational.zero) == 0)
    return;
  m.swapRow(maxrow, i);
  m.multRow(i, maxval.reciprocal());
  for (int k = 0; k < rows; k++)
    if (k != i)
      m.addRows(k, i, m.data[k][i].negate());
  }
}