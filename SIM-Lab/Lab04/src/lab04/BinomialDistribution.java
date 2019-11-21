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
public class BinomialDistribution extends Distribution {
    
    Long N, K;
    Double P;
    
    public BinomialDistribution(DISTR_TYPE currentDistr, Long N, Double P, Long K) {
        super(currentDistr);
        this.N = N;
        this.P = P;
        this.K = K;
    }
    
    public Double binomialDistribution() {
        return choose(N, K) * (double)Math.pow(P, K) * (double)Math.pow( 1 - P, N - K);
    }
    
    @Override
    public Double getDistribution() {
        return binomialDistribution();
    }

    @Override
    public Double getExpectance() {
        return (double)N * P;
    }

    @Override
    public Double getVariance() {
        return N * P * (1.0 - P);
    }

    @Override
    public Long getParam() {
        return K;
    }
    
}
