/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab04;



/**
 *
 * @author shadowleaf
 */
public abstract class Distribution {
    
    public static enum DISTR_TYPE {
        BINOM, GEOMT, NBINOM, POISSON
    };

    public Distribution(DISTR_TYPE currentDistr) {
        this.currentDistr = currentDistr;
    }
    
    
    public DISTR_TYPE currentDistr;
    
    public static Long choose(Long n, Long r) {
        if (r > n/2)
            r = n - r;
        
        Long ans = 1l;
        for (int i = 1 ; i <= r ; i++) {
            ans *= (n - r + i);
            ans /= i;
        }
        
        return ans;
    }
    
    public abstract Long getParam();
    
    /**
     *
     * Calculates P(X = K) generally speaking
     * 
     * @return
     */
    public abstract Double getDistribution();
    
    public abstract Double getExpectance();
    
    public abstract Double getVariance();
    
}
