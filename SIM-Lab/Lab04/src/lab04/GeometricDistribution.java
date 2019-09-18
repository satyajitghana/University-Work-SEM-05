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
public class GeometricDistribution extends Distribution {
    
    Double P;
    Long K;
    
    public GeometricDistribution(DISTR_TYPE currentDistr, Double P, Long K) {
        super(currentDistr);
        this.P = P;
        this.K = K;
    }
    
    public Double geometricDistribution() {
        return (double)Math.pow(1 - P, K - 1) * P;
    }
    
    @Override
    public Double getDistribution() {
        return geometricDistribution();
    }

    @Override
    public Double getExpectance() {
        return (1.0) / P;
    }

    @Override
    public Double getVariance() {
        return (1 - P) / (P * P);
    }

    @Override
    public Long getParam() {
        return K;
    }
    
}
