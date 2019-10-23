/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atm_sim;

import java.util.concurrent.atomic.AtomicLong;

/**
 *
 * @author shadowleaf
 */
public class BromineRandom {

    private final AtomicLong seed;

    private static final long MULTIPLIER = 0x5DEECE66DL;
    private static final long ADDEND = 0xBL;
    private static final long MASK = (1L << 48) - 1;

    public BromineRandom(long seed) {
        this.seed = new AtomicLong(initialScramble(seed));

    }

    private static long initialScramble(long seed) {
        return (seed ^ MULTIPLIER) & MASK;
    }

    /**
     * Generates the next pseudorandom number.
     *
     * <p>
     * The general contract of {@code next} is that it returns an {@code int}
     * value and if the argument {@code bits} is between {@code 1} and
     * {@code 32} (inclusive), then that many low-order bits of the returned
     * value will be (approximately) independently chosen bit values, each of
     * which is (approximately) equally likely to be {@code 0} or {@code 1}. The
     * method {@code next} is implemented by class {@code Random} by atomically
     * updating the seed to
     * <pre>{@code (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1)}</pre> and
     * returning
     * <pre>{@code (int)(seed >>> (48 - bits))}.</pre>
     *
     * This is a linear congruential pseudorandom number generator, as defined
     * by D. H. Lehmer and described by Donald E. Knuth in
     * <i>The Art of Computer Programming,</i> Volume 3:
     * <i>Seminumerical Algorithms</i>, section 3.2.1.
     *
     * @param bits random bits
     * @return the next pseudorandom value from this random number generator's
     * sequence
     * @since 1.1
     */
    protected int next(int bits) {
        long oldseed, nextseed;
        AtomicLong _seed = this.seed;
        do {
            oldseed = _seed.get();
            nextseed = (oldseed * MULTIPLIER + ADDEND) & MASK;
        } while (!_seed.compareAndSet(oldseed, nextseed));
        return (int) (nextseed >>> (48 - bits));
    }

    /**
     * Returns a pseudorandom, uniformly distributed {@code int} value between 0
     * (inclusive) and the specified value (exclusive), drawn from this random
     * number generator's sequence. The general contract of {@code nextInt} is
     * that one {@code int} value in the specified range is pseudorandomly
     * generated and returned. All {@code bound} possible {@code int} values are
     * produced with (approximately) equal probability. The method
     * {@code nextInt(int bound)} is implemented by class {@code Random} as if
     * by:
     * <pre> {@code
     * public int nextInt(int bound) {
     *   if (bound <= 0)
     *     throw new IllegalArgumentException("bound must be positive");
     *
     *   if ((bound & -bound) == bound)  // i.e., bound is a power of 2
     *     return (int)((bound * (long)next(31)) >> 31);
     *
     *   int bits, val;
     *   do {
     *       bits = next(31);
     *       val = bits % bound;
     *   } while (bits - val + (bound-1) < 0);
     *   return val;
     * }}</pre>
     *
     * <p>The hedge "approx
     * imately" is used in the foregoing description only because the next
     * method is only approximately an unbiased source of independently chosen
     * bits. If it were a perfect source of randomly chosen bits, then the
     * algorithm shown would choose {@code int} values from the stated range
     * with perfect uniformity.
     * <p>
     * The algorithm is slightly tricky. It rejects values that would result in
     * an uneven distribution (due to the fact that 2^31 is not divisible by n).
     * The probability of a value being rejected depends on n. The worst case is
     * n=2^30+1, for which the probability of a reject is 1/2, and the expected
     * number of iterations before the loop terminates is 2.
     * <p>
     * The algorithm treats the case where n is a power of two specially: it
     * returns the correct number of high-order bits from the underlying
     * pseudo-random number generator. In the absence of special treatment, the
     * correct number of <i>low-order</i> bits would be returned. Linear
     * congruential pseudo-random number generators such as the one implemented
     * by this class are known to have short periods in the sequence of values
     * of their low-order bits. Thus, this special case greatly increases the
     * length of the sequence of values returned by successive calls to this
     * method if n is a small power of two.
     *
     * @param bound the upper bound (exclusive). Must be positive.
     * @return the next pseudorandom, uniformly distributed {@code int} value
     * between zero (inclusive) and {@code bound} (exclusive) from this random
     * number generator's sequence
     * @throws IllegalArgumentException if bound is not positive
     * @since 1.2
     */
    public int nextInt(int bound) {
        if (bound <= 0) {
            throw new IllegalArgumentException("Bad Bound");
        }

        int r = next(31);
        int m = bound - 1;
        if ((bound & m) == 0) // i.e., bound is a power of 2
        {
            r = (int) ((bound * (long) r) >> 31);
        } else {
            for (int u = r;
                    u - (r = u % bound) + m < 0;
                    u = next(31))
                ;
        }
        return r;
    }
}
