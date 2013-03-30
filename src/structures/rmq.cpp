// Ojo: Utiliza N log N memoria
int[] buildRMQ(int[] vector, int n) {
    int logn = 0;
    for (int k = 1; k < n; k *= 2)++logn;
    int[] b = new int[n * logn];
    System.arraycopy(vector, 0, b, 0, n);
    int delta = 0;
    for (int k = 1; k < n; k *= 2) {
        System.arraycopy(b, delta, b, n + delta, n);
        delta += n;

        for (int i = 0; i < n - k; i++) 
			b[i + delta] = Math.min(b[i + delta],
							        b[i + k + delta]);
    }
    return b;
}

// Responde queries en tiempo constante
// para mayor velocidad se pueden precalcular
// los k, e, z para todos los y - x posibles.
int minimum(int[] rmq, int x, int y) {
    int z = y - x, k = 0, e = 1, s;
    s = (((z & 0xffff0000) != 0) ? 1 : 0) << 4;
    z >>= s;
    e <<= s;
    k |= s;
    s = (((z & 0x0000ff00) != 0) ? 1 : 0) << 3;
    z >>= s;
    e <<= s;
    k |= s;
    s = (((z & 0x000000f0) != 0) ? 1 : 0) << 2;
    z >>= s;
    e <<= s;
    k |= s;
    s = (((z & 0x0000000c) != 0) ? 1 : 0) << 1;
    z >>= s;
    e <<= s;
    k |= s;
    s = (((z & 0x00000002) != 0) ? 1 : 0) << 0;
    z >>= s;
    e <<= s;
    k |= s;
    return Math.min(rmq[x + n * k], rmq[y + n * k - e + 1]);
}