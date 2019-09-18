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
public class NegativeBinomialDistribution extends Distribution {
    
    Double P;
    Long R;

    public NegativeBinomialDistribution(DISTR_TYPE currentDistr, Double P, Long R) {
        super(currentDistr);
        this.P = P;
        this.R = R;
    }

    @Override
    public Double getDistribution() {
        return R / P;
    }

    @Override
    public Double getExpectance() {
        return R / P;
    }

    @Override
    public Double getVariance() {
        return (R * (1.0 - P)) / (P * P);
    }

    @Override
    public Long getParam() {
        return R;
    }
    
}
