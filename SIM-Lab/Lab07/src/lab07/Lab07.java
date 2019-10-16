/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab07;

import java.util.Arrays;

/**
 *
 * @author shadowleaf
 */
public class Lab07 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        {
            System.out.println("KS Test");

            Double[] rn = {0.44, 0.81, 0.14, 0.05, 0.93};
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
                System.out.printf("Dplus_%d = %.10f, Dminus_%d = %.10f\n", idx + 1, newDplus, idx + 1, newDminus);

                i += 1.0;
            }

            Double D = Math.max(Dplus, Dminus);

            System.out.printf("Dplus : %.10f\nDminus : %.10f\nD : %.10f\n", Dplus, Dminus, D);

            Double alpha = 0.05;
        }

        {
            System.out.println("\nChi-Square Test");

            Integer[][] data_obs = {{200, 150, 50}, {250, 300, 50}};

            Integer nrows = data_obs.length;
            Integer ncols = data_obs[0].length;

            Integer[] col_total = new Integer[ncols];
            Integer[] row_total = new Integer[nrows];

            Integer total = 0;

            int row, col;

            // calculate col totals
            for (col = 0; col < col_total.length; col++) {
                col_total[col] = 0;
                for (row = 0; row < nrows; row++) {
                    col_total[col] += data_obs[row][col];
                }

                total += col_total[col];
            }

            // calculate row totals
            for (row = 0; row < row_total.length; row++) {
                row_total[row] = 0;
                for (col = 0; col < ncols; col++) {
                    row_total[row] += data_obs[row][col];
                }
            }

//            System.out.println(Arrays.toString(row_total));
//            System.out.println(Arrays.toString(col_total));
//            System.out.println(total);
            Double[][] data_exp = new Double[nrows][ncols];

            // calculate expected values
            for (row = 0; row < nrows; row++) {
                for (col = 0; col < ncols; col++) {
                    data_exp[row][col] = col_total[col] * row_total[row] / (double) total;
//                    System.out.printf("%.5f ", data_exp[row][col]);
                }
//                System.out.println();
            }

            Double chi_sqr = 0.0;

            // calculate chi square
            for (row = 0; row < nrows; row++) {
                for (col = 0; col < ncols; col++) {
                    Double Oi = (double) data_obs[row][col];
                    Double Ei = data_exp[row][col];
                    chi_sqr += (Oi - Ei) * (Oi - Ei) / Ei;
                }
            }

            System.out.printf("Chi-Square = %.10f\n", chi_sqr);

            Integer dfree = (nrows - 1) * (ncols - 1);

            Double alpha = 0.05;

        }
    }

}
