/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practice;

import java.util.Arrays;
import java.util.Random;

/**
 *
 * @author shadowleaf
 */
public class Practice {

    public static void singleServer() {
        Random random = new Random(0);

        int N = 10;

        int[] IAT = new int[N + 1];
        int[] ST = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            IAT[i] = random.nextInt(80) + 1;
            ST[i] = random.nextInt(60) + 1;
        }

        int[] AT = new int[N + 1];
        int[] SS = new int[N + 1];
        int[] SE = new int[N + 1];
        int[] IDLE = new int[N + 1];
        int[] WAIT = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            AT[i] = AT[i - 1] + IAT[i];

            SS[i] = SE[i - 1] >= AT[i] ? SE[i - 1] : AT[i];
            SE[i] = SS[i] + ST[i];

            IDLE[i] = SS[i] >= SE[i - 1] ? SS[i] - SE[i - 1] : 0;
            WAIT[i] = SS[i] <= AT[i] ? 0 : SS[i] - AT[i];
        }

        System.out.println("REQNO\tIAT\tAT\tSS\tSE\tST\tWAIT\tIDLE");
        for (int i = 1; i <= N; i++) {
            String out = i + "\t"
                    + IAT[i] + "\t"
                    + AT[i] + "\t"
                    + SS[i] + "\t"
                    + SE[i] + "\t"
                    + ST[i] + "\t"
                    + WAIT[i] + "\t"
                    + IDLE[i];
            System.out.println(out);
        }
    }

    public static void tests() {
        {
            // KS Test
            Double[] rn = {0.44, 0.81, 0.14, 0.05, 0.93};
            Double N = (double) rn.length;
            Arrays.sort(rn);

            Double Dplus = Double.NEGATIVE_INFINITY;
            Double Dminus = Double.NEGATIVE_INFINITY;

            Double i = 1.0;
            for (Double Ri : rn) {
                Dplus = Math.max(Dplus, i / N - Ri);
                Dminus = Math.max(Dminus, Ri - (i - 1) / N);

                i += 1.0;
            }

            Double D = Math.max(Dplus, Dminus);

            System.out.printf("Dplus : %.10f\nDminus : %.10f\nD : %.10f\n", Dplus, Dminus, D);
        }
        {
            // Chi-Sq Test
            Integer[][] data_obs = {
                {200, 150, 50},
                {250, 300, 50}
            };
            Double[][] data_expected = new Double[3][3];

            Integer n_rows = data_obs.length;
            Integer n_cols = data_obs[0].length;

            Integer[] row_sum = new Integer[n_rows];
            Integer[] col_sum = new Integer[n_cols];

            for (int i = 0; i < n_rows; i++) {
                row_sum[i] = 0;
                for (int j = 0; j < n_cols; j++) {
                    row_sum[i] += data_obs[i][j];
//                    col_sum[j] += data_obs[i][j];
                }
            }
            for (int j = 0; j < n_cols; j++) {
                col_sum[j] = 0;
                for (int i = 0; i < n_rows; i++) {
                    col_sum[j] += data_obs[i][j];
                }
            }

            Double total = Arrays.stream(row_sum).mapToDouble(Integer::doubleValue).sum();

            for (int i = 0; i < n_rows; i++) {
                for (int j = 0; j < n_cols; j++) {
                    data_expected[i][j] = row_sum[i] * col_sum[j] / total;
                }
            }

            Double chi_sq = 0.0d;

            for (int i = 0; i < n_rows; i++) {
                for (int j = 0; j < n_cols; j++) {
                    Double Oi = data_obs[i][j] * 1.0;
                    Double Ei = data_expected[i][j];
                    chi_sq += (Oi - Ei) * (Oi - Ei) / Ei;
                }
            }

            System.out.printf("Chi-Square = %.10f\n", chi_sq);
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

    }

}
