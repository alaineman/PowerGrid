package org.powerbot.game.api.util.node;

import org.powerbot.game.client.LinkedListNode;

/**
 * @param <N> Node type.
 * @author Timer
 */
@SuppressWarnings("unchecked")
public class LinkedList<N> {
	private final org.powerbot.game.client.LinkedList nl;
	private LinkedListNode current;

	public LinkedList(org.powerbot.game.client.LinkedList nl) {
		this.nl = nl;
	}

	public N getHead() {
		LinkedListNode node = nl.getTail().getNext();

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNext();

		return (N) node;
	}

	public N getNext() {
		LinkedListNode node = current;

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNext();

		return (N) node;
	}
}
