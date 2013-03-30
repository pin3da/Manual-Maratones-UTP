static class SubSets implements Iterator <Integer>, Iterable <Integer>
{
    int N;
    int X;
    boolean termino = false;
		
    SubSets(int n) {
        N = n;
        X = N;
    }


    public boolean hasNext() {
        if(!termino && X == 0) {
            termino = true;
            return true;
        }
        return !termino;
    }

    public Integer next() {
        int ant = X;
        X = (X - 1) & N;
        return ant;
    }

    public void remove() {}
		
    public Iterator<Integer> iterator() {
        return this;
    }		
}

Se itera sobre los subsets de la siguiente manera

for(int subset : new SubSets(N))
{
    //trabajar con el subset aqui
}