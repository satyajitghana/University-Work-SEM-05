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
public class Distribution {
    
    public static enum DISTR_TYPE {
        BINOM, GEOMT, NBINOM
    };

    public Distribution(DISTR_TYPE currentDistr, Long N, Long K, Double P) {
        this.currentDistr = currentDistr;
        this.N = N;
        this.K = K;
        this.P = P;
    }
    
    
    DISTR_TYPE currentDistr;
    
    public Long N, K;
    public Double P;
    
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
    
    public Double binomialDistribution() {
        return choose(N, K) * (double)Math.pow(P, K) * (double)Math.pow( 1 - P, N - K);
    }
    
    public Double geometricDistribution() {
        return (double)Math.pow(1 - P, K) * P;
    }
    
    public Double negativeBinomialDistribution() {
        return 0.0;
    }
    
    public Double getDistribution() {
        switch(currentDistr) {
            case BINOM:
                return binomialDistribution();
            case GEOMT:
                return geometricDistribution();
            case NBINOM:
                return negativeBinomialDistribution();
        }
        
        return 0.0;
    }
    
    public Double getExpectance() {
        switch(currentDistr) {
            case BINOM:
                return N * P;
            case GEOMT:
                return (1-P) / P;
            case NBINOM:
                return 0.0;
        }
        
        return 0.0;
    }
    
    public Double getVariance() {
        switch(currentDistr) {
            case BINOM:
                return N * P * (1.0 - P);
            case GEOMT:
                return (1-P) / (P * P);
            case NBINOM:
                return 0.0;
        }
        
        return 0.0;
    }
}
