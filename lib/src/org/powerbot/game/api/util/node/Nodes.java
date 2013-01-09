package org.powerbot.game.api.util.node;

import org.powerbot.game.client.Node;

/**
 * @author Timer
 */
public class Nodes {
	/**
	 * @param nc The node cache to check
	 * @param id The id of the node
	 * @return A <tt>Node</tt> object corresponding to the ID in the nodecache.
	 */
	public static Node lookup(final org.powerbot.game.client.HashTable nc, final long id) {
		try {
			if (nc == null || nc.getBuckets() == null || id < 0) {
				return null;
			}

			final Node n = nc.getBuckets()[(int) (id & nc.getBuckets().length - 1)];
			for (Node node = n.getNext(); node != n; node = node.getNext()) {
				if (node.getId() == id) {
					return node;
				}
			}
		} catch (final Exception ignored) {
		}
		return null;
	}
}