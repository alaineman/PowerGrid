package org.powerbot.game.api.util.net;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Lightweight grand exchange utility.
 * No external libs required.
 *
 * @author Aion
 */
public final class GeItem {
	public static final String HOST = "http://services.runescape.com";

	public static final String[] QUERIES = {
			"/m=itemdb_rs/api/catalogue/detail.json?item=",
			"/m=itemdb_rs/results.ws?query=",
			"/m=itemdb_rs/3816_obj_sprite.gif?id=",
			"/m=itemdb_rs/3816_obj_big.gif?id="
	};

	private final Map<String, String> map;

	private GeItem(final Map<String, String> map) {
		if (map == null || map.isEmpty()) {
			throw new IllegalArgumentException("Argument cannot be null or empty.");
		}
		this.map = map;
	}

	/**
	 * Gets the price change for the last 180 days.
	 *
	 * @return the price change for the last 180 days
	 */
	public double get180DayChange() {
		return Double.parseDouble(map.get("day180"));
	}

	/**
	 * Gets the price change for the last 30 days.
	 *
	 * @return the price change for the last 30 days
	 */
	public double get30DayChange() {
		return Double.parseDouble(map.get("day30"));
	}

	/**
	 * Gets the price change for the last 90 days.
	 *
	 * @return the price change for the last 90 days
	 */
	public double get90DayChange() {
		return Double.parseDouble(map.get("day90"));
	}

	/**
	 * Gets this item's category.
	 *
	 * @return the category for this item
	 */
	public String getCategory() {
		return map.get("type");
	}

	/**
	 * Gets this item's description.
	 *
	 * @return this item's description
	 */
	public String getDescription() {
		return map.get("description");
	}

	/**
	 * Gets this item's id.
	 *
	 * @return this item's id
	 */
	public int getId() {
		return Integer.parseInt(map.get("id"));
	}

	/**
	 * Gets a copy of the <code>Map</code> that holds information about this <code>GeItem</code>.
	 *
	 * @return a <code>Map</code> holding information about this grand exchange item
	 */
	public Map<String, String> getMap() {
		return new HashMap<>(map);
	}

	/**
	 * Gets this item's name.
	 *
	 * @return this item's name
	 */
	public String getName() {
		return map.get("name");
	}

	/**
	 * Gets this item's price.
	 *
	 * @return this item's price
	 */
	public int getPrice() {
		return parseNumber(map.get("price"));
	}

	/**
	 * Gets the URL of this item's sprite.
	 *
	 * @return an <code>URL</code> instance of this item's sprite
	 * @see #getSpriteURL(boolean)
	 */
	public URL getSpriteURL() {
		return getSpriteURL(false);
	}

	/**
	 * Gets the URL of this item's sprite.
	 *
	 * @param large <tt>true</tt> to get the large version
	 * @return an <code>URL</code> instance of this item's sprite
	 */
	public URL getSpriteURL(final boolean large) {
		try {
			return new URL(map.get("icon" + (large ? "_large" : "")));
		} catch (MalformedURLException e) {
			try {
				return new URL(HOST + QUERIES[large ? 3 : 2] + getId());
			} catch (MalformedURLException ignored) {
			}
		}
		return null;
	}

	/**
	 * Gets today's change price.
	 *
	 * @return today's change price
	 */
	public int getTodayChange() {
		return parseNumber(map.get("today"));
	}

	/**
	 * Checks whether this item is members' only.
	 *
	 * @return <tt>true</tt> if members' only; otherwise <tt>false</tt>
	 */
	public boolean isMember() {
		return Boolean.parseBoolean(map.get("members"));
	}

	/**
	 * Fetches data for the given item id.
	 *
	 * @param itemId the item id to look up
	 * @return an instance of <code>GeItem</code>; otherwise <code>null</code> if unable to fetch data
	 * @see #lookup(String)
	 */
	public static GeItem lookup(final int itemId) {
		if (itemId <= 0) {
			throw new IllegalArgumentException("item id cannot be less than or equal to 0.");
		}
		try {
			final URL url = new URL(HOST + QUERIES[0] + itemId);
			final Scanner s = new Scanner(url.openStream());
			String line = s.useDelimiter("\\A").next();
			s.close();
			// Little "trick" against items whose description contains commas.
			line = line.replaceAll("},", "}~").replaceAll("\",\"", "\"~\"").replaceFirst(",\"type", "~\"type");
			// Much less hassle than making a custom JSON parser / adding external libs.
			final String[] lines = line.replace("\"", "").split("~");
			final Map<String, String> map = new HashMap<>();
			for (int i = 0; i < lines.length; i++) {
				final String[] data = lines[i].split(":", 2);
				if (data[0].equals("{item")) {
					data[0] = "icon";
					data[1] = data[1].substring(6);
				} else if (data[0].equals("current")) {
					continue;
				} else if (data[0].matches("(price|change)")) {
					final String prevKey = lines[i - 1].split(":", 2)[0];
					if (data[0].equals("price")) {
						if (map.containsKey(data[0])) {
							data[0] = prevKey;
						}
					} else {
						data[0] = prevKey;
					}
				}
				map.put(data[0], data[1].replaceAll("[+%}]", "").trim());
			}
			return new GeItem(map);
		} catch (final IOException ignored) {
		}
		return null;
	}

	/**
	 * Fetches the id of the given item name and then calls {@link #lookup(int)}.
	 * To ensure a match, the parameter must be the item's full name as this
	 * method uses {@link String#equalsIgnoreCase(String)}.
	 *
	 * @param name the name of the item to look up
	 * @return an instance of <code>GeItem</code>; otherwise <code>null</code> if unable to fetch data
	 * @see #lookup(int)
	 */
	public static GeItem lookup(final String name) {
		if (name == null || name.isEmpty()) {
			throw new IllegalArgumentException("Argument cannot be null or empty.");
		}
		try {
			final URL url = new URL(HOST + QUERIES[1] + URLEncoder.encode(name, "UTF-8"));
			final Scanner scanner = new Scanner(url.openStream());
			int itemId = -1;
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (line.contains("did not return any results.</div>")) {
					break;
				} else if (line.contains("_obj_sprite.gif?id=")) {
					line = line.substring(line.indexOf("?id") + 4);
					final String itemName = line.substring(line.indexOf("=") + 2, line.length() - 2);
					if (itemName.equalsIgnoreCase(name)) {
						itemId = Integer.parseInt(line.substring(0, line.indexOf("\"")));
						break;
					}
				}
			}
			scanner.close();
			if (itemId != -1) {
				return lookup(itemId);
			}
		} catch (final IOException ignored) {
		}
		return null;
	}

	private int parseNumber(final String number) {
		// Added a negative lookbehind to prevent expressions such as "4.k"
		if (number.matches("^-?[0-9.]+(?<!\\.)[kmb]+$")) {
			double price = Double.parseDouble(number.substring(0, number.length() - 1));
			final double multiplier;
			switch (number.charAt(number.length() - 1)) {
			case 'b':
				multiplier = 1000000000D;
				break;
			case 'm':
				multiplier = 1000000D;
				break;
			case 'k':
				multiplier = 1000D;
				break;
			default:
				multiplier = 1D;
			}
			price *= multiplier;
			return (int) price;
		}
		try {
			return Integer.parseInt(number.replace(",", ""));
		} catch (NumberFormatException ignored) {
			System.out.println("Unexpected number: " + number);
		}
		// Hopefully, this will never be reached.
		return Integer.parseInt(number.replaceAll("[kmb.,]", ""));
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("GeItem[");
		sb.append("item name: ").append(getName()).append(" | ");
		sb.append("item id: ").append(getId()).append(" | ");
		sb.append("description: ").append(getDescription()).append(" | ");
		sb.append("category: ").append(getCategory()).append(" | ");
		sb.append("member: ").append(isMember()).append(" | ");
		sb.append("price: ").append(getPrice()).append(" | ");
		sb.append("change[today: ").append(getTodayChange()).append(" | ");
		sb.append("30-day: ").append(get30DayChange()).append(" | ");
		sb.append("90-day: ").append(get90DayChange()).append(" | ");
		sb.append("180-day: ").append(get180DayChange()).append("] | ");
		sb.append("sprite[normal: ").append(getSpriteURL().toString()).append(" | ");
		sb.append("large: ").append(getSpriteURL(true).toString()).append("]]");
		return sb.toString();
	}
}
