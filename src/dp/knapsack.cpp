* Generates an instance of the 0/1 knapsack problem with N items
* and maximum weight W and solves it in time and space 
* proportional to N * W using dynamic programming.

public class Knapsack {

 public static void main(String[] args) {
  int N = Integer.parseInt(args[0]); // number of items
  int W = Integer.parseInt(args[1]); // maximum weight of knapsack
   
  int[] profit = new int[N + 1];
  int[] weight = new int[N + 1];
   
  // generate random instance, items 1..N
  for (int n = 1; n <= N; n++) {
    profit[n] = (int)(Math.random() * 1000);
    weight[n] = (int)(Math.random() * W);
  }
   
 // opt[n][w] = max profit of 
 /  packing items 1..n with weight limit w
 
 // sol[n][w] = does opt solution to pack 
 // items 1..n with weight 
 
 //limit w include item n?
 
  int[][] opt = new int[N + 1][W + 1];
  boolean[][] sol = new boolean[N + 1][W + 1];
   
  for (int n = 1; n <= N; n++) {
    for (int w = 1; w <= W; w++) {
       
      // don't take item n
      int option1 = opt[n - 1][w];
      
      // take item n
      int option2 = Integer.MIN_VALUE;
      if (weight[n] <= w) 
        option2 = profit[n] + opt[n - 1][w - weight[n]];
       
      // select better of two options
      opt[n][w] = Math.max(option1, option2);
      sol[n][w] = (option2 > option1);
     }
   }
   
  // determine which items to take
  boolean[] take = new boolean[N + 1];
  for (int n = N, w = W; n > 0; n--) {
    if (sol[n][w]) {
      take[n] = true;
      w = w - weight[n];
    } else {
      take[n] = false;
    }
  }
  
  // print results
  System.out.println
   ("item" + "\t" + "profit" + "\t" + "weight" + "\t" + "take");
  for (int n = 1; n <= N; n++) {
    System.out.println
     (n + "\t" + profit[n] + "\t" + weight[n] + "\t" + take[n]);
  }
 }
 }