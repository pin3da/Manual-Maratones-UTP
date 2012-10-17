public class Poker
{
  static class Carta implements Comparable <Carta>
  {
    int valor;
    int pinta;

    @Override
    public int compareTo(Carta otra)
    {
      if(valor < otra.valor)
        return 1;
      else if(valor > otra.valor)
        return -1;
      else
        return 0;
    }
  }

  static Carta generarCarta(char [] carta)
  {
    int valor;
    try
    {
      valor = Integer.parseInt(carta[0] + "");
    }
    catch(Exception e)
    {
      if(carta[0] == 'T')
      {
        valor = 10;
      }
      else if(carta[0] == 'J')
      {
        valor = 11;
      }
      else if(carta[0] == 'Q')
      {
        valor = 12;
      }
      else if(carta[0] == 'K')
      {
        valor = 13;
      }
      else
      {
        valor = 14;
      }
    }
    int pinta;
    switch(carta[1])
    {
      case 'H': pinta = 1; break;
      case 'D': pinta = 2; break;
      case 'S': pinta = 3; break;
      default: pinta = 4; break;
    }
    Carta c = new Carta();
    c.pinta = pinta;
    c.valor = valor;
    return c;
  }

  // Retorna un long que establece el orden relativo de las
  // manos en un juego de poker normal
  // si la mano A le gana la mano B entonces
  // A.darValor() > B.darValor()
  // si empatan entonces A.darValor() == B.darValor()
  static long darValor(Carta [] mano)
  {
    Arrays.sort(mano);
    ArrayList <Integer> repetidas = new ArrayList <Integer> ();
    int tipo = 0;
    for(int i = 0; i < 5; i++)
      repetidas.add(1);
    for(int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 5; j++)
      {
        if(j != i)
        {
          if (mano[i].compareTo(mano[j]) == 0)
          {
            repetidas.set(i, repetidas.get(i) + 1);
          }
        }
      }
    }
    ArrayList <Integer> manoN = new ArrayList <Integer> ();
    if(repetidas.contains(4))
    {
      tipo = 7;
      for(int i = 0; i < 4; i++)
        manoN.add(mano[repetidas.indexOf(4)].valor);
      manoN.add(mano[repetidas.indexOf(1)].valor);
    }
    else if(repetidas.contains(3) && repetidas.contains(2))
    {
      tipo = 6;
      for(int i = 0; i < 3; i++)
        manoN.add(mano[repetidas.indexOf(3)].valor);
      for(int i = 0; i < 2; i++)
        manoN.add(mano[repetidas.indexOf(2)].valor);
    }
    else if(repetidas.contains(3))
    {
      tipo = 3;
      for(int i = 0; i < 3; i++)
        manoN.add(mano[repetidas.indexOf(3)].valor);
      manoN.add(mano[repetidas.indexOf(1)].valor);
      manoN.add(mano[repetidas.lastIndexOf(1)].valor);
    }
    else if(repetidas.contains(2))
    {
      if(repetidas.indexOf(2) + 1 != repetidas.lastIndexOf(2))
      {
        tipo = 2;
        for(int i = 0; i < 2; i++)
          manoN.add(mano[repetidas.indexOf(2)].valor);
        for(int i = 0; i < 2; i++)
          manoN.add(mano[repetidas.lastIndexOf(2)].valor);
        manoN.add(mano[repetidas.indexOf(1)].valor);
      }
      else
      {
        tipo = 1;
        for(int i = 0; i < 2; i++)
          manoN.add(mano[repetidas.indexOf(2)].valor);
        for(int i = 0; i < 5; i++)
        {
          if(repetidas.get(i) == 1)
          {
            manoN.add(mano[i].valor);
          }
        }
      }
    }
    else
    {
      for(Carta c : mano)
      {
        manoN.add(c.valor);
      }
      boolean color = true;
      int pinta = mano[0].pinta;
      for(Carta c : mano)
      {
        if(c.pinta != pinta)
          color = false;
      }
      boolean escalera = true;
      // si la escalera A-5 es permitida
      // entonces se debe cambiar para
      // aceptar 2,3,4,5,14 como escalera
      // aca.
      int valor = mano[0].valor;
      for(Carta c : mano)
      {
        if(c.valor != valor)
          escalera = false;
        else
          valor--;
      }
      if(escalera && color)
        tipo = 8;
      else if(color)
        tipo = 5;
      else if(escalera)
        tipo = 4;
    }
    long valorMano = tipo * 10000000000L;
    valorMano += manoN.get(0) * 100000000;
    valorMano += manoN.get(1) * 1000000;
    valorMano += manoN.get(2) * 10000;
    valorMano += manoN.get(3) * 100;
    valorMano += manoN.get(4);
    return valorMano;
  }
}
