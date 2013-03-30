public class Josephus
{
  /* todas las posiciones estan entre 0 y n - 1 */
  public static int josephus(int n, int k)
  {
    if(n == 1) return 0;
    return(josephus(n - 1, k) + k) % n;
  }
  /* inicialM es la primera persona que pierde
    (todas las posiciones estan entre 0 y n - 1) */
  public static int josephus(int n, int k, int inicialM)
  {
    int normal = josephus(n, k);
    k %= n;
    normal -= (k - 1);
    if(normal < 0) normal += n;
    normal += inicialM;
    return normal % n;
  }
}