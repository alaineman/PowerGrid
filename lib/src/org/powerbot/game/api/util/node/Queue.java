package org.powerbot.game.api.util.node;

import org.powerbot.game.client.NodeSub;
import org.powerbot.game.client.NodeSubQueue;

/**
 * @param <N> Node type.
 * @author Timer
 */
@SuppressWarnings("unchecked")
public class Queue<N extends org.powerbot.game.client.NodeSub> {
	private final NodeSubQueue nl;
	private org.powerbot.game.client.NodeSub current;

	public Queue(NodeSubQueue nl) {
		this.nl = nl;
	}

	public int size() {
		int size = 0;
		org.powerbot.game.client.NodeSub node = nl.getTail().getNextSub();

		while (node != nl.getTail()) {
			node = node.getNextSub();
			size++;
		}

		return size;
	}

	public N getHead() {
		org.powerbot.game.client.NodeSub node = nl.getTail().getNextSub();

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNextSub();

		return (N) node;
	}

	public N getNext() {
		org.powerbot.game.client.NodeSub node = current;

		if (node == nl.getTail()) {
			current = null;
			return null;
		}
		current = node.getNextSub();

		return (N) node;
	}
}
