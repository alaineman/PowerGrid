package org.powerbot.game.api.util.node;

/**
 * @author Timer
 */
public class HashTable {
	private org.powerbot.game.client.HashTable nc;
	private org.powerbot.game.client.Node current;
	private int c_index = 0;

	public HashTable(org.powerbot.game.client.HashTable hashTable) {
		nc = hashTable;
	}

	public org.powerbot.game.client.Node getFirst() {
		c_index = 0;
		return getNext();
	}

	public org.powerbot.game.client.Node getNext() {
		if (c_index > 0 && nc.getBuckets()[c_index - 1] != current) {
			org.powerbot.game.client.Node node = current;
			current = node.getNext();
			return node;
		}
		while (c_index < nc.getBuckets().length) {
			org.powerbot.game.client.Node node = nc.getBuckets()[c_index++].getNext();
			if (nc.getBuckets()[c_index - 1] != node) {
				current = node.getNext();
				return node;
			}
		}
		return null;
	}
}
