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

        Distribution.DISTR_TYPE currDistr;

        Integer choice;

        System.out.print("Enter the Distrubution you want\n1.\tBinomial\n2.\tGeometrical\n3.\tNegative Binomial\n4.\tPoisson\nYour Choice : ");
        choice = input.nextInt();

        Distribution distr = null;

        switch (choice) {
            case 1: {
                // Binomial
                currDistr = Distribution.DISTR_TYPE.BINOM;
                System.out.print("Enter N : ");
                Long N = input.nextLong();
                System.out.print("Enter X : ");
                Long K = input.nextLong();
                System.out.println("Enter P (success) : ");
                Double P = input.nextDouble();

                distr = new BinomialDistribution(currDistr, N, P, K);
            }
            break;
            case 2: {
                // Geometrical
                currDistr = Distribution.DISTR_TYPE.GEOMT;
                System.out.print("Enter P (success) : ");
                Double P = input.nextDouble();
                System.out.print("Enter K : ");
                Long K = input.nextLong();

                distr = new GeometricDistribution(currDistr, P, K);
            }
            break;
            case 3: {
                // Negative Binomial
                currDistr = Distribution.DISTR_TYPE.NBINOM;
                System.out.print("Enter P (success) : ");
                Double P = input.nextDouble();
                System.out.print("Enter R : ");
                Long R = input.nextLong();

                distr = new NegativeBinomialDistribution(currDistr, P, R);
            }
            break;
            case 4: {
                // Poisson
                currDistr = Distribution.DISTR_TYPE.POISSON;
                System.out.print("Enter lambda : ");
                Double lambda = input.nextDouble();
                System.out.print("Enter K : ");
                Long K = input.nextLong();

                distr = new PoissonDistribution(currDistr, lambda, K);
            }
            break;
        }

        if (distr != null) {
            System.out.printf("P( X = %d ) = %.10f\nE[X] = %.10f\nVar[X] = %.10f\n",
                    distr.getParam(), distr.getDistribution(), distr.getExpectance(), distr.getVariance());
        } else {
            System.out.println("DISTR IS NULL");
        }

    }

}
