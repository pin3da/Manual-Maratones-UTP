public class Sudoku
{
  static final int tS = 4;
  static final int tS2 = 16;
  static int visitado = 1 << (tS2 + 1);

  static void marcar(int i, int j, int n)
  {
    int mascara = 1 << n;
    sudoku[i][j] = mascara + visitado;
    mascara = ~mascara;
    int iMenor = (i / tS) * tS;
    int iMayor = iMenor + tS;
    int jMenor = (j / tS) * tS;
    int jMayor = jMenor + tS;
    for(int a = 0; a < tS2; a++)
    {
      if(a != j)
        sudoku[i][a] &= mascara;
      if(a != i)
        sudoku[a][j] &= mascara;
    }
    for(int a = iMenor; a < iMayor; a++)
      for(int b = jMenor; b < jMayor; b++)
        if(a != i || b != j)
          sudoku[a][b] &= mascara;
  }

  static long tiempoDentro = 0;
  static int idMascara = 0;
  static int[][][] zonas = new int[tS2 * 3][tS2][2];
  static int[] actuales = new int[tS2];

  public static void limpiarZona(int[][] zona, int[] actuales,
                                   int[] grupos, int[] tamGrupos,
                                  int[][] sudoku, int[] visitados)
  {
    while(true)
    {
      int iActual = 0;
      forExterno:
      for(int i = 0; i <= tS2; i++)
      {
        if(tamGrupos[i] == -1)
          break;
        for(int j = 0; j < tamGrupos[i]; j++)
        {
          int indice = grupos[iActual + j];
          int valor = sudoku[zona[indice][0]][zona[indice][1]];
          if(valor >= visitado || tamGrupos[i] == 1)
          {
            tamGrupos[i]--;
            for(int k = iActual + j; k < tS2 - 1; k++)
              grupos[k] = grupos[k + 1];
            if(tamGrupos[i] == 0)
            {
              for(int k = i; k < tS2; k++)
                tamGrupos[k] = tamGrupos[k + 1];
              i--;
              continue forExterno;
            }
            else
            {
              j--;
              continue;
            }
          }
        }
        iActual += tamGrupos[i];
      }
      break;
    }
    idMascara++;
    while(true)
    {
      int iActual = 0;
      forExterno:
      for(int i = 0; i <= tS2; i++)
      {
        int tamActual = tamGrupos[i];
        if(tamActual == -1)
          break;
        int mascaraActual = 1 << tamActual;
        mascaraActual--;
        for(int mascara = 1; mascara < mascaraActual; mascara++)
        {
          int temp = mascara;
          int m = 0;
          for(int j = 0; j < tamActual; j++)
          {
            if((temp & 1) == 1)
                        {
              m |= sudoku[zona[grupos[iActual + j]][0]]
                            [zona[grupos[iActual + j]][1]];
                        }
            temp >>= 1;
          }
          int tamCuenta = Integer.bitCount(m);
          if(tamCuenta == tamActual)
            continue;
          if(visitados[m] == idMascara)
            continue;
          temp = ~m;
          int cuenta = 0;
          for(int j = 0; j < tamActual; j++)
          {
            int valor = sudoku[zona[grupos[iActual + j]][0]]
                        [zona[grupos[iActual + j]][1]];
            if((valor & temp) == 0)
              cuenta++;
          }
          if(cuenta == tamCuenta)
          {
            int posA = 0;
            for(int j = 0; j < tamActual; j++)
            {
              int valor = sudoku[zona[grupos[iActual + j]][0]]
                            [zona[grupos[iActual + j]][1]];
              if((valor & temp) == 0)
                actuales[posA++] = grupos[iActual + j];
            }
            for(int j = 0; j < tamActual; j++)
            {
              int valor = sudoku[zona[grupos[iActual + j]][0]]
                            [zona[grupos[iActual + j]][1]];
              if((valor & temp) != 0)
              {
                actuales[posA++] = grupos[iActual + j];
                sudoku[zona[grupos[iActual + j]][0]]
                [zona[grupos[iActual + j]][1]] &= temp;
              }
            }
            for(int k = 0; k < tamActual; k++)
              grupos[iActual + k] = actuales[k];
            tamGrupos[i] = cuenta;
            for(int k = tS2; k > i; k--)
              tamGrupos[k] = tamGrupos[k - 1];
            tamGrupos[i + 1]  = tamActual - cuenta;
            i--;
            continue forExterno;
          }
          visitados[m] = idMascara;
        }
        iActual += tamActual;
      }
      break;
    }
  }

  static int[] visitados = new int[1 << (tS2 + 1)];

  public static void limpiar(int[][] sudoku,
                               int[][] grupos,
                            int[][] tamGrupos)
  {
    for(int i = 0; i < tS2 * 3; i++)
      limpiarZona(zonas[i], actuales, grupos[i],
                        tamGrupos[i], sudoku, visitados);
  }

  static int[][] sudoku = new int[tS2][tS2];
  static int[][] grupos = new int[tS2 * 3][tS2];
  static int[][] tamGrupos = new int[tS2 * 3][tS2 + 1];
  static int[][][] backtrack = new int[tS2 * tS2][tS2][tS2];

  static int[][][] backtrackGrupos = new int[tS2 * tS2][tS2 * 3]
    [tS2];

  static int[][][] backtrackTamGrupos = new int[tS2 * tS2]
    [tS2 * 3][tS2 + 1];

  static boolean backtrack(int altura, int[][] sudoku,
                             int[][] grupos, int[][] tamGrupos)
  {
    int sumAnterior = 0;
    int sumMejor = Integer.MAX_VALUE;
    boolean termino = true;
    int iMejor = 0;
    int jMejor = 0;
    while(sumMejor > 1 && sumAnterior != sumMejor)
    {
      sumAnterior = sumMejor;
      iMejor = 0;
      jMejor = 0;
      termino = true;
      sumMejor = Integer.MAX_VALUE;
      for(int i = 0; i < tS2; i++)
        for(int j = 0; j < tS2; j++)
        {
          int pos = Integer.bitCount(sudoku[i][j]);
          if(sudoku[i][j] == 0)
            return false;
          if(sudoku[i][j] <= todos)
            termino = false;
          if(sudoku[i][j] <= todos && pos <= sumMejor)
          {
            sumMejor = pos;
            iMejor = i;
            jMejor = j;
          }
        }
      if(sumMejor != 1)
        limpiar(sudoku, grupos, tamGrupos);
    }
    if(termino)
    {
      for(int i = 0; i < tS2; i++)
      {
        for(int j = 0; j < tS2; j++)
        {
          int temp = sudoku[i][j];
          for(int k = 0; k < tS2; k++)
          {
            if((temp & 1) == 1)
              System.out.print((char) ('A' + k));
            temp >>= 1;
          }
        }
        System.out.println();
      }
      return true;
    }
    if(sumMejor == 1)
    {
      int pos = 0;
      int temp = sudoku[iMejor][jMejor];
      for(int i = 0; i < tS2; i++)
      {
        if((temp & 1) == 1)
          pos = i;
        temp >>= 1;
      }
      marcar(iMejor, jMejor, pos);
      return backtrack(altura + 1, sudoku, grupos, tamGrupos);
    }
    else
    {
      for(int j = 0; j < tS2; j++)
        for(int k = 0; k < tS2; k++)
          backtrack[altura][j][k] = sudoku[j][k];
      for(int j = 0; j < tS2 * 3; j++)
        for(int k = 0; k < tS2; k++)
          backtrackGrupos[altura][j][k] = grupos[j][k];
      for(int j = 0; j < tS2 * 3; j++)
        for(int k = 0; k <= tS2; k++)
          backtrackTamGrupos[altura][j][k] = tamGrupos[j][k];
      int temp = sudoku[iMejor][jMejor];
      for(int i = 0; i < tS2; i++)
      {
        if((temp & 1) == 1)
        {
          int pos = i;
          for(int j = 0; j < tS2; j++)
            for(int k = 0; k < tS2; k++)
              sudoku[j][k] = backtrack[altura][j][k];
          for(int j = 0; j < tS2 * 3; j++)
            for(int k = 0; k < tS2; k++)
              grupos[j][k] = backtrackGrupos[altura][j][k];
          for(int j = 0; j < tS2 * 3; j++)
            for(int k = 0; k <= tS2; k++)
              tamGrupos[j][k] = backtrackTamGrupos[altura][j][k];
          marcar(iMejor, jMejor, pos);
          if(backtrack(altura + 1, sudoku, grupos, tamGrupos))
            return true;
        }
        temp >>= 1;
      }
      return false;
    }
  }


  static void generarZonas()
  {
    for(int i = 0; i < tS2; i++)
    {
      for(int j = 0; j < tS2; j++)
      {
        zonas[i][j][0] = i;
        zonas[i][j][1] = j;
      }
    }
    for(int i = 0; i < tS2; i++)
    {
      for(int j = 0; j < tS2; j++)
      {
        zonas[i + tS2][j][0] = j;
        zonas[i + tS2][j][1] = i;
      }
    }
    int cuenta = 0;
    for(int i = 0; i < tS; i++)
      for(int j = 0; j < tS; j++)
      {
        int ia = i * tS;
        int ib = ia + tS;
        int ja = j * tS;
        int jb = ja + tS;
        int actual = 0;
        for(int a = ia; a < ib; a++)
          for(int b = ja; b < jb; b++)
          {
            zonas[cuenta + tS2 * 2][actual][0] = a;
            zonas[cuenta + tS2 * 2][actual++][1] = b;
          }
        cuenta++;
      }
  }
  static int todos = (1 << tS2) - 1;
}
