import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class Template {
    
    //Scanner creado por Santiago Gutierrez
    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            System.setOut(new PrintStream(new \
            BufferedOutputStream(System.out), true));
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {

            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
    
    public static void main(String []args){
        Scanner sc = new Scanner();
        String cadena = sc.next();
        int integer = sc.nextInt();
        double ddouble = sc.nextDouble();
        
        //imprime en una línea
        System.out.println(cadena);
        //imprime con formato (Como en c)
        System.out.printf("%d\n", integer);
        //imprime sin salto de línea
        System.out.print(ddouble);
    }
}
