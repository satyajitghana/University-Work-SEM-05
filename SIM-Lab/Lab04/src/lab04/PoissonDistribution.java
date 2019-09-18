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
public class PoissonDistribution extends Distribution {

    Double lambda;
    Long K;

    public PoissonDistribution(DISTR_TYPE currentDistr, Double lambda, Long K) {
        super(currentDistr);

        this.lambda = lambda;
        this.K = K;
    }

    @Override
    public Double getDistribution() {
        Double ans = Math.pow(lambda, K) * Math.exp(-lambda);
        for (Long i = 1l; i <= K; i++) {
            ans /= i;
        }

        return ans;
    }

    @Override
    public Double getExpectance() {
        return lambda;
    }

    @Override
    public Double getVariance() {
        return getExpectance();
    }

    @Override
    public Long getParam() {
        return K;
    }

}
