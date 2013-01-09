package org.powerbot.game.api.methods;

import java.awt.image.BufferedImage;
import java.io.File;

import org.powerbot.core.randoms.AntiRandom;
import org.powerbot.game.bot.Context;

public class Environment {
	public static String getDisplayName() {
		return Context.get().getDisplayName();
	}

	public static int getUserId() {
		return Context.get().getUserId();
	}

	public static BufferedImage captureScreen() {
		return Context.captureScreen();
	}

	public static BufferedImage getScreenBuffer() {
		return Context.getScreenBuffer();
	}

	public static void saveScreenCapture() {
		Context.saveScreenCapture();
	}

	public static void saveScreenCapture(final String name) {
		Context.saveScreenCapture(name);
	}

	public static File getStorageDirectory() {
		final File dir = new File(
				System.getProperty("java.io.tmpdir"),
				Context.get().getScriptHandler().getDefinition().getName().replace('.', File.pathSeparatorChar)
		);
		if (!dir.isDirectory()) {
			dir.mkdirs();
		}
		return dir;
	}

	public static void enableRandom(final Class<? extends AntiRandom> random, final boolean enable) {
		Context.get().getScriptHandler().getRandomHandler().enable(random, enable);
	}

	public static boolean isRandomEnabled(final Class<? extends AntiRandom> random) {
		return Context.get().getScriptHandler().getRandomHandler().isEnabled(random);
	}
}
