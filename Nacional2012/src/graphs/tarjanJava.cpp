public class SCCTarjan {
    static class Node implements Comparable < Node > {
        final int name;
        ArrayList < Node > adjacents = new ArrayList < Node > (100);
        boolean visited = false;
        int lowlink = -1;
        int index = -1;

        public Node(final int argName) {
            name = argName;
        }

        public int compareTo(final Node argNode) {
            return argNode == this ? 0 : -1;
        }
    }

    static int index = 0;
    static ArrayDeque < Node > stack = new ArrayDeque < Node > ();
	
    static ArrayList < ArrayList < Node > > SCC =
	new ArrayList < ArrayList < Node > > ();

    public static ArrayList < ArrayList < Node > > 
	tarjanSCC(ArrayList < Node > nodes)
	{
        index = 0;
        SCC.clear();
        stack.clear();
        for (Node n: nodes)
        if (n.index == -1) tarjan(n);
        return SCC;
    }

    public static void tarjan(Node v) {
        v.index = index;
        v.lowlink = index;
        index++;
        stack.push(v);
        for (Node n: v.adjacents) {
            if (n.index == -1) {
                tarjan(n);
                v.lowlink = Math.min(v.lowlink, n.lowlink);
            } 
			else if (stack.contains(n))
			v.lowlink = Math.min(v.lowlink, n.index);
        }
        if (v.lowlink == v.index) {
            Node n;
            ArrayList < Node > component = 
			new ArrayList < Node > ();
            do {
                n = stack.pop();
                component.add(n);
            }
            while (n != v);
            SCC.add(component);
        }
    }
}