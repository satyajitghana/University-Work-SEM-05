/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kstest;

import java.util.Arrays;

/**
 *
 * @author shadowleaf
 */
public class KSTEST {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)         {
            System.out.println("KS Test");

            Double[] rn = {0.58, 0.92, 0.12, 0.03, 0.99, 0.29, 0.79, 0.57, 0.64};
            Arrays.sort(rn);
            Integer N = rn.length;

            Double Dplus = Double.MIN_VALUE;
            Double Dminus = Double.MIN_VALUE;

            Double i = 1.0;
            for (int idx = 0; idx < N; idx++) {
                Double newDplus = ((i / N) - rn[idx]);
                Double newDminus = rn[idx] - ((i - 1) / N);

                Dplus = Math.max(Dplus, newDplus);
                Dminus = Math.max(Dminus, newDminus);

//            System.out.printf("newDplus = %.10f, newDminus = %.10f\n", newDplus, newDminus);
//                System.out.printf("Dplus_%d = %.10f, Dminus_%d = %.10f\n", idx + 1, newDplus, idx + 1, newDminus);

                i += 1.0;
            }

            Double D = Math.max(Dplus, Dminus);

            System.out.printf("Dplus : %.10f\nDminus : %.10f\nD : %.10f\n", Dplus, Dminus, D);

            Double alpha = 0.05d;
            Double Dcritical = 0.432d;
            
            System.out.printf("alpha : %.10f, Dcritical : %.10f\n", alpha, Dcritical);
            
            if (D <= Dcritical) {
                System.out.printf("Since D less than Dcritical, Fail to reject null hypothesis\n");
            } else {
                System.out.printf("Since D is greater than Dcritical, Reject Null Hypothesis\n");
            }
        }
    
}
