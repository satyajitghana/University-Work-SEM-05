/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab05;

import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author shadowleaf
 */
public class Lab05 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        {
            // X_n+1 = (aX_n + c) mod m
            // X_0 = 27
            // a = 17
            // c = 43
            // m = 100
            // n = 20

            System.out.println("LCG ----------\n");

            Integer a = 17, c = 43, m = 100, n = 20;

            ArrayList<Integer> X = new ArrayList<>();
            X.add(27);

            System.out.printf("X0 = %d, a = %d, c = %d, m = %d, n = %d\n", X.get(0), a, c, m, n);

            for (int i = 0; i < n; i++) {
                X.add((a * X.get(i) + c) % m);
            }

            Integer i = 0;
            for (Integer e : X) {
                System.out.printf("X%d = %d, ", i++, e);
            }
            System.out.println("\n");
        }

        {
            System.out.println("MCG ----------\n");
            // a = 13
            // m = 2^6
            // X_0 = 1, 2, 3, 4
            Integer a = 13;
            Integer m = 1 << 6;
            // important
            ArrayList<Integer> C = new ArrayList(Arrays.asList(17, 0));

            ArrayList<ArrayList<Integer>> X = new ArrayList<>();

            X.add(new ArrayList(Arrays.asList(1))); // X0 = 1
            X.add(new ArrayList(Arrays.asList(2))); // X0 = 2
            X.add(new ArrayList(Arrays.asList(3))); // X0 = 3
            X.add(new ArrayList(Arrays.asList(4))); // X0 = 4

            for (Integer c : C) {

                for (int i = 0; i < X.size(); i++) {
                    Integer X0 = X.get(i).get(0);
//                    if ( (X0 % 2 == 0) && (c == 0) ) {
//                        continue;
//                    }
                    System.out.printf("X0 = %d, a = %d, c = %d, m = %d\n", X0, a, c, m);
                    Integer j = 0;
                    while (true) {
                        Integer Xnew = (a * X.get(i).get(j++) + c) % m;
                        X.get(i).add(Xnew);
                        if (Xnew.equals(X0)) {
                            System.out.printf("P = %d\n", j);
                            Integer k = 0;
                            for (Integer e : X.get(i)) {
                                System.out.printf("X%d = %d, ", k++, e);
                            }
                            System.out.println("\n");
                            break;
                        }
                    }
                }
            }
        }
    }

}
