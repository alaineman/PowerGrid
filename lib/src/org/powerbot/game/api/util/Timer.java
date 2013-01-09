package org.powerbot.game.api.util;

/**
 * A Timer utility.
 *
 * @author Timer, Vulcan
 */
public class Timer {
	private long end;
	private final long start;
	private final long period;

	/**
	 * Instantiates a new Timer with a given time
	 * period in milliseconds.
	 *
	 * @param period Time period in milliseconds.
	 */
	public Timer(final long period) {
		this.period = period * 1000000;
		start = System.nanoTime();
		end = start + this.period;
	}

	/**
	 * Returns the number of milliseconds elapsed since
	 * the start time.
	 *
	 * @return The elapsed time in milliseconds.
	 */
	public long getElapsed() {
		return (System.nanoTime() - start) / 1000000;
	}

	/**
	 * Returns the number of milliseconds remaining
	 * until the timer is up.
	 *
	 * @return The remaining time in milliseconds.
	 */
	public long getRemaining() {
		if (isRunning()) {
			return (end - System.nanoTime()) / 1000000;
		}
		return 0;
	}

	/**
	 * Returns <tt>true</tt> if this timer's time period
	 * has not yet elapsed.
	 *
	 * @return <tt>true</tt> if the time period has not yet passed.
	 */
	public boolean isRunning() {
		return System.nanoTime() < end;
	}

	/**
	 * Restarts this timer using its period.
	 */
	public void reset() {
		end = System.nanoTime() + period;
	}

	/**
	 * Sets the end time of this timer to a given number of
	 * milliseconds from the time it is called. This does
	 * not edit the period of the timer (so will not affect
	 * operation after reset).
	 *
	 * @param ms The number of milliseconds before the timer
	 *           should stop running.
	 * @return The new end time.
	 */
	public long setEndIn(final long ms) {
		end = System.nanoTime() + ms * 1000000;
		return end;
	}

	/**
	 * Returns a formatted String of the time elapsed.
	 *
	 * @return The elapsed time formatted hh:mm:ss.
	 */
	public String toElapsedString() {
		return Time.format(getElapsed());
	}

	/**
	 * Returns a formatted String of the time remaining.
	 *
	 * @return The remaining time formatted hh:mm:ss.
	 */
	public String toRemainingString() {
		return Time.format(getRemaining());
	}
}
