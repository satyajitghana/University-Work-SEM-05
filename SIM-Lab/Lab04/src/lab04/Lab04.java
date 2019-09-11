/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab04;

import java.util.Scanner;

/**
 *
 * @author shadowleaf
 */
public class Lab04 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Distribution.DISTR_TYPE currDistr = Distribution.DISTR_TYPE.BINOM;

        Integer choice;

        System.out.print("Enter the Distrubution you want\n1.\tBinomial\n2.\tGeometrical\n3.\tNegative Binomial\nYour Choice : ");
        choice = input.nextInt();

        switch (choice) {
            case 1:
                currDistr = Distribution.DISTR_TYPE.BINOM;
                break;
            case 2:
                currDistr = Distribution.DISTR_TYPE.GEOMT;
                break;
            case 3:
                currDistr = Distribution.DISTR_TYPE.NBINOM;
                break;
        }

        Long N, K;
        Double P;

        System.out.print("Enter the number of trials : ");
        N = input.nextLong();

        System.out.print("Enter the number of success you want out of N : ");
        K = input.nextLong();

        System.out.print("Enter the probability of success : ");
        P = input.nextDouble();

        Distribution distr = new Distribution(currDistr, N, K, P);

        System.out.printf("P( X = %d ) = %.10f\nE[X] = %.10f\nVar[X] = %.10f\n",
                K, distr.getDistribution(), distr.getExpectance(), distr.getVariance());

    }

}
