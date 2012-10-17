function TarjanOLCA(u)
    MakeSet(u);
    u.ancestor := u;
    for each v in u.children do
        TarjanOLCA(v);
        Union(u,v);
        Find(u).ancestor := u;
    u.colour := black;
    for each v such that {u,v} in P do
        if v.colour == black
            print 
			Tarjans Least Common Ancestor of 
			 u
			 and 
			 v
			 is
			Find(v).ancestor + ".";
				  
				 
struct Query;

struct Nodo
{
   vector <Nodo*> adjacentes;
   vector <Query*> queries;
   int numero;
   long long distanciaCero;
   Nodo *parent;
   Nodo *ancestor;
   int rank;
   bool encontrado;

   void clear(int i)
   {
       numero = i;
       distanciaCero = 0;
       adjacentes.clear();
       queries.clear();
       encontrado = false;
   }
};

struct Query
{
   Nodo *a, *b;
   long long respuesta;
};

Nodo nodos[100001];
Query queries[100001];

void makeSet(Nodo *x)
{
    x->parent = x;
    x->rank   = 0;
}

Nodo* find(Nodo *x)
{
    if(x->parent == x)
       return x;
    else
    {
       x->parent = find(x->parent);
       return x->parent;
    }
}

int unir(Nodo *x, Nodo *y)
{
    Nodo *xRoot = find(x);
    Nodo *yRoot = find(y);
    if(xRoot->rank > yRoot->rank)
        yRoot->parent = xRoot;
    else if(xRoot->rank < yRoot->rank)
        xRoot->parent = yRoot;
    else if(xRoot != yRoot)
    {
        yRoot->parent = xRoot;
        xRoot->rank = xRoot->rank + 1;
    }
}

void tarjanOLCA(Nodo *u)
{
   makeSet(u);
   u->ancestor = u;
   for(int i = 0; i < u->adjacentes.size(); i++)
   {
       tarjanOLCA(u->adjacentes[i]);
       unir(u, u->adjacentes[i]);
       find(u)->ancestor = u;
   }
   u->encontrado = true;
   for(int i = 0; i < u->queries.size(); i++)
   {
       Query *actual = u->queries[i];
       Nodo *v;
       if(u == actual->a)
           v = actual->b;
       else
           v = actual->a;
       if(v->encontrado)
       {
           Nodo *ancestro = find(v)->ancestor;
           actual->respuesta = (procesar query aqui)  

		}	
   }
}


