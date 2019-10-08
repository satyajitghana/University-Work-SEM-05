/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rain_sim;

import java.util.Random;

/**
 *
 * @author shadowleaf
 */
public class RAIN_SIM {
    
    public static Integer[] gen_rn(Double[] distr) {
        Integer[] rn = new Integer[distr.length];
        int temp = 0;
        for (int i = 0 ; i < distr.length; i++) {
            temp += distr[i]*100;
            rn[i] = temp-1;
        }
        
        return rn;
    }
    
    public static void print_arr(Integer[] arr) {
        for (Integer i : arr) {
            System.out.print(i+" ");
        }
        System.out.println();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Random rg = new Random();
        
        // if it rained the previous day
        Double prev_rain_distr[] = {0.50, 0.25, 0.15, 0.05, 0.03, 0.02};
        
        // if it did not rain on previous day
        Double no_prev_rain_distr[] = {0.75, 0.15, 0.06, 0.04};
        
        // create the random_no upper limit
        
        Integer[] prn_rn = gen_rn(prev_rain_distr);
        Integer[] nprn_rn = gen_rn(no_prev_rain_distr);
        
//        print_arr(prn_rn);
//        print_arr(nprn_rn);
        
        // generate 10 random numbers from 10 to 100
        // testing Integer rn[] = {67, 63, 39, 55, 29, 78, 70, 6, 78, 76};
        Integer rn[] = new Integer[10];
        for (int i = 0 ; i < rn.length ; i++) {
            rn[i] = rg.nextInt(89) + 10;
        }
        
        // assuming it has not rained on previous day   
        Boolean has_rained_prev = false;
        
        Integer[] rainfall = new Integer[rn.length];
        Integer n_days_without_rain = 0;
        Integer total_rain = 0;
        
        for (int i = 0 ; i < rn.length ; i++) {
            if (!has_rained_prev) {
                for (int j = 0 ; j < nprn_rn.length ; j++) {
                    if (rn[i] <= nprn_rn[j]) {
                        rainfall[i] = j;
                        break;
                    }
                }
            } else {
                for (int j = 0 ; j < prn_rn.length ; j++) {
                    if (rn[i] <= prn_rn[j]) {
                        rainfall[i] = j;
                        break;
                    }
                }
            }
            
            has_rained_prev = rainfall[i] != 0;
            
            if (!has_rained_prev) {
                n_days_without_rain++;
            } else {
                total_rain += rainfall[i];
            }
            
        }
        
//        print_arr(rainfall);
        System.out.printf("%5s | %15s | %10s\n", "day", "random number", "rainfall");
        for (int i = 0 ; i < rainfall.length ; i++) {
            System.out.printf("%5d | %15d | %10d\n", i+1, rn[i], rainfall[i]);
        }
        
        System.out.printf("Total Rainfall = %d\nNumber of Days without rain = %d\n", total_rain, n_days_without_rain);
        
    }
    
}
