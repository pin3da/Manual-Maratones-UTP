#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>

using namespace std;

#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) rep(i,0,n)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
x != (v).end(); ++x)
#define D(x) cout << #x " = " << x << endl;

typedef long long int lld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int main(){

  return 0;
}


static class Scanner {

    BufferedReader br =
	new BufferedReader(new InputStreamReader(System. in ));
	
    StringTokenizer st = new StringTokenizer("");

    String nextLine() {
        try {
            String l = br.readLine();
            return l;
        } catch (Exception e) {
            throw new RuntimeException();
        }
    }
    public String next() {
        while (!st.hasMoreTokens()) {
            String linea = nextLine();
            if (linea == null) return null;
            st = new StringTokenizer(linea);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

	
    public double nextDouble() {
        return Double.parseDouble(next());
    }

    // Y asi para cualquier next (por ejemplo: nextBigInteger)
	
	// Retorna null si es el fin de la entrada
    public Integer nextInteger() {
		String l = next();
		if(l == null)
			return null;
        return Integer.parseInt(l);
    }
}