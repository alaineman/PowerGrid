package org.powerbot.game.api.util;

import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

import org.powerbot.game.api.methods.Environment;

/**
 * A utility that generates random numbers.
 *
 * @author Timer
 * @author Paris
 */
public class Random {
	private static final java.util.Random random;

	static {
		java.util.Random r;
		try {
			r = SecureRandom.getInstance("SHA1PRNG");
		} catch (NoSuchAlgorithmException ignored) {
			r = new java.util.Random();
		}
		r.setSeed((long) Environment.getUserId() << 32 ^ System.currentTimeMillis() + r.nextInt(0xffff));
		random = r;
	}

	/**
	 * @return The next random boolean value.
	 */
	public static boolean nextBoolean() {
		return random.nextBoolean();
	}

	/**
	 * Generates a pseudo-random number between two given values.
	 *
	 * @param min The minimum value (inclusive).
	 * @param max The maximum value (exclusive).
	 * @return The generated pseudo-random integer.
	 */
	public static int nextInt(final int min, final int max) {
		if (max < min) {
			return max + random.nextInt(min - max);
		}
		return min + (max == min ? 0 : random.nextInt(max - min));
	}

	/**
	 * Generates a pseudo-random number between two given values.
	 *
	 * @param min The minimum value (inclusive).
	 * @param max The maximum value (exclusive).
	 * @return The generated pseudo-random double.
	 */
	public static double nextDouble(final double min, final double max) {
		return min + random.nextDouble() * (max - min);
	}

	/**
	 * @return A generated pseudo-random double between 0.0 (inclusive) and 1.0 (exclusive).
	 */
	public static double nextDouble() {
		return random.nextDouble();
	}

	/**
	 * Generates a pseudo-random number between the two given values with standard deviation.
	 *
	 * @param min The minimum value (inclusive).
	 * @param max The maximum value (exclusive).
	 * @param sd  Standard deviation.
	 * @return The generated pseudo-random integer.
	 */
	public static int nextGaussian(final int min, final int max, final int sd) {
		return nextGaussian(min, max, min + (max - min) / 2, sd);
	}

	/**
	 * Generates a pseudo-random number between the two given values with standard deviation about a provided mean.
	 *
	 * @param min  The minimum value (inclusive).
	 * @param max  The maximum value (exclusive).
	 * @param mean The mean (>= min & < max).
	 * @param sd   Standard deviation.
	 * @return The generated pseudo-random integer.
	 */
	public static int nextGaussian(final int min, final int max, final int mean, final int sd) {
		if (min == max) {
			return min;
		}
		int rand;
		do {
			rand = (int) (random.nextGaussian() * sd + mean);
		} while (rand < min || rand >= max);
		return rand;
	}
}