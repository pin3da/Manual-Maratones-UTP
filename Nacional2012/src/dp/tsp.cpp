static int[][] distancias;
static Integer[][] dpTsp;
	
// Se llama inicialmente 
// tsp(0, (i << N) - 1)
// donde N es el numero de ciudades
static int tsp(int current, int mask)
{
    if(dpTsp[current][mask] != null)
	    return dpTsp[current][mask];
	if(Integer.bitCount(mask) == 1)
    {
        return dpTsp[current][mask] = 
        distancia[0][Integer.numberOfTrailingZeros(mask)];
    }
    int maskT = mask;
    int j = 0;
    int best = Integer.MAX_VALUE;
    int nextMask = mask & (~(1 << current));
    while(maskT != 0)
    {
        if((maskT & 1) == 1 && j != current)
            best = Math.min(best, 
                   distancias[current][j] + tsp(j, nextMask));
        j++;
        maskT >>= 1;
    }
    return dpTsp[current][mask] = best;
}
