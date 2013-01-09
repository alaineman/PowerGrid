package org.powerbot.game.api.methods.widget;

import java.awt.event.KeyEvent;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.input.Keyboard;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;

/**
 * @author Timer
 */
public class Camera {
	public static int getX() {
		final Client client = Context.client();
		return client.getCamPosX();
	}

	public static int getY() {
		final Client client = Context.client();
		return client.getCamPosY();
	}

	public static int getZ() {
		final Client client = Context.client();
		return client.getCamPosZ();
	}

	public static int getYaw() {
		final Client client = Context.client();
		return (int) (client.getCameraYaw() / 45.51);
	}

	public static int getPitch() {
		final Client client = Context.client();
		return (int) ((client.getCameraPitch() - 1024) / 20.48);
	}

	public synchronized static boolean setPitch(final boolean up) {
		if (up) {
			return setPitch(100);
		}
		return setPitch(0);
	}

	public synchronized static boolean setPitch(final int percent) {
		int curAlt = getPitch();
		int lastAlt = 0;
		if (curAlt == percent) {
			return true;
		}

		final boolean up = curAlt < percent;
		Keyboard.pressKey(up ? (char) KeyEvent.VK_UP : (char) KeyEvent.VK_DOWN, 0, 0);

		final Timer timer = new Timer(100);
		while (timer.isRunning()) {
			if (lastAlt != curAlt) {
				timer.reset();
			}

			lastAlt = curAlt;
			Task.sleep(Random.nextInt(5, 10));
			curAlt = getPitch();

			if (up && curAlt >= percent) {
				break;
			} else if (!up && curAlt <= percent) {
				break;
			}
		}

		Keyboard.releaseKey(up ? (char) KeyEvent.VK_UP : (char) KeyEvent.VK_DOWN, 0, 0);
		return curAlt == percent;
	}

	public synchronized static void setAngle(final char direction) {
		switch (direction) {
		case 'n':
			setAngle(0);
			break;
		case 'w':
			setAngle(90);
			break;
		case 's':
			setAngle(180);
			break;
		case 'e':
			setAngle(270);
			break;
		default:
			setAngle(0);
			break;
		}
	}

	public synchronized static boolean setNorth() {
		return WidgetCache.getCompass().click(true);
	}

	public synchronized static boolean setNorth(final int up) {
		return WidgetCache.getCompass().click(true) && setPitch(up);
	}

	public synchronized static void setAngle(int degrees) {
		degrees %= 360;
		if (getAngleTo(degrees) > 5) {
			Keyboard.pressKey((char) KeyEvent.VK_LEFT, 0, 0);
			final Timer timer = new Timer(500);
			int ang, prev = -1;
			while ((ang = getAngleTo(degrees)) > 5 && Game.getClientState() == 11 && timer.isRunning()) {
				if (ang != prev) {
					timer.reset();
				}
				prev = ang;
				Task.sleep(10);
			}
			Keyboard.releaseKey((char) KeyEvent.VK_LEFT, 0, 0);
		} else if (getAngleTo(degrees) < -5) {
			Keyboard.pressKey((char) KeyEvent.VK_RIGHT, 0, 0);
			final Timer timer = new Timer(500);
			int ang, prev = -1;
			while ((ang = getAngleTo(degrees)) < -5 && Game.getClientState() == 11 && timer.isRunning()) {
				if (ang != prev) {
					timer.reset();
				}
				prev = ang;
				Task.sleep(10);
			}
			Keyboard.releaseKey((char) KeyEvent.VK_RIGHT, 0, 0);
		}
	}

	public static int getAngleTo(final int degrees) {
		int ca = getYaw();
		if (ca < degrees) {
			ca += 360;
		}
		int da = ca - degrees;
		if (da > 180) {
			da -= 360;
		}
		return da;
	}

	public synchronized static void turnTo(final Locatable l) {
		turnTo(l, 0);
	}

	public synchronized static void turnTo(final Locatable l, final int dev) {
		int angle = getMobileAngle(l);
		angle = Random.nextInt(angle - dev, angle + dev + 1);
		setAngle(angle);
	}

	public static int getMobileAngle(final Locatable mobile) {
		final Tile t = mobile.getLocation();
		final Tile me = Players.getLocal().getLocation();
		int angle = ((int) Math.toDegrees(Math.atan2(t.getY() - me.getY(), t.getX() - me.getX()))) - 90;
		return angle;
	}
}
