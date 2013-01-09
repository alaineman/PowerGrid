package org.powerbot.game.api.util.node;

import org.powerbot.game.client.Node;
import org.powerbot.game.client.NodeDeque;

/**
 * @param <N> Node type.
 * @author Timer
 */
@SuppressWarnings("unchecked")
public class Deque<N> {
	private final NodeDeque nl;
	private Node current;

	public Deque(NodeDeque nl) {
		this.nl = nl;
	}

	public int size() {
		int size = 0;
		Node node = nl.getTail().getNext();

		while (node != nl.getTail()) {
			node = node.getNext();
			size++;
		}

		return size;
	}

	public N getHead() {
		Node node = nl.getTail().getNext();

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNext();

		return (N) node;
	}

	public N getNext() {
		Node node = current;

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNext();

		return (N) node;
	}
}
