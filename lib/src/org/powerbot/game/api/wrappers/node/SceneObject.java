package org.powerbot.game.api.wrappers.node;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Polygon;
import java.lang.ref.SoftReference;
import java.util.Set;

import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.util.node.Nodes;
import org.powerbot.game.api.wrappers.Area;
import org.powerbot.game.api.wrappers.Entity;
import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.graphics.CapturedModel;
import org.powerbot.game.api.wrappers.graphics.model.SceneObjectModel;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Cache;
import org.powerbot.game.client.HardReference;
import org.powerbot.game.client.HashTable;
import org.powerbot.game.client.Model;
import org.powerbot.game.client.Node;
import org.powerbot.game.client.RSAnimable;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSInteractable;
import org.powerbot.game.client.RSInteractableData;
import org.powerbot.game.client.RSObject;
import org.powerbot.game.client.RSObjectDef;
import org.powerbot.game.client.RSObjectDefLoader;

/**
 * @author Timer
 */
public class SceneObject implements Entity, Locatable, Identifiable {
	private final RSObject object;
	private final int type;
	private final int plane;

	public SceneObject(final RSObject obj, final int type, final int plane) {
		this.object = obj;
		this.type = type;
		this.plane = plane;
	}

	public Area getArea() {
		if (object instanceof RSAnimable) {
			final RSAnimable animable = (RSAnimable) object;
			final int bX = Game.getBaseX(), bY = Game.getBaseY();
			final Tile tile1 = new Tile(
					bX + (int) animable.getX1(),
					bY + (int) animable.getY1(),
					plane
			);
			final Tile tile2 = new Tile(
					bX + (int) animable.getX2(),
					bY + (int) animable.getY2(),
					plane
			);
			return new Area(tile1, tile2);
		}
		return null;
	}

	public int getId() {
		return object.getId();
	}

	public int getType() {
		return type;
	}

	public int getPlane() {
		return plane;
	}

	public RSObject getInstance() {
		return object;
	}

	public RegionOffset getRegionOffset() {
		final RSInteractable location = (RSInteractable) object;
		final RSInteractableData data = location.getData();
		return new RegionOffset((int) data.getLocation().getX() / 512, (int) data.getLocation().getY() / 512, plane);
	}

	public Tile getLocation() {
		final RegionOffset localTile = getRegionOffset();
		return new Tile(Game.getBaseX() + localTile.getX(), Game.getBaseY() + localTile.getY(), localTile.getPlane());
	}

	public SceneObjectDefinition getDefinition() {
		final HashTable rsObjectDefLoaders = Context.client().getRSGroundInfo().getRSObjectDefLoaders().getCache().getTable();
		final Node ref = Nodes.lookup(rsObjectDefLoaders, getId());
		if (ref != null) {
			if (ref instanceof HardReference) {
				return new SceneObjectDefinition((RSObjectDef) ((HardReference) ref).get());
			} else if (ref instanceof SoftReference) {
				final Object def = ((SoftReference<?>) ref).get();
				if (def != null) {
					return new SceneObjectDefinition((RSObjectDef) def);
				}
			}
		}
		return null;
	}

	public CapturedModel getModel() {
		if (object != null) {
			final Model model = object.getModel();
			if (model != null) {
				return new SceneObjectModel(model, this);
			}
		}
		return null;
	}

	public boolean validate() {
		final RegionOffset offset = getRegionOffset();
		final Set<SceneObject> v_objects = SceneEntities.getLocalAt(offset.getX(), offset.getY(), -1);
		final int id = this.getId();
		for (final SceneObject object : v_objects) {
			if (object.object == this.object && object.getId() == id) {
				return true;
			}
		}
		return false;
	}

	public Point getCentralPoint() {
		final CapturedModel model = getModel();
		return model != null ? model.getCentralPoint() : getLocation().getCentralPoint();
	}

	public Point getNextViewportPoint() {
		final CapturedModel model = getModel();
		return model != null ? model.getNextViewportPoint() : getLocation().getNextViewportPoint();
	}

	public boolean contains(final Point point) {
		final CapturedModel model = getModel();
		return model != null ? model.contains(point) : getLocation().contains(point);
	}

	public boolean isOnScreen() {
		final CapturedModel model = getModel();
		return model != null ? model.isOnScreen() : getLocation().isOnScreen();
	}

	public Polygon[] getBounds() {
		final CapturedModel model = getModel();
		return model != null ? model.getBounds() : getLocation().getBounds();
	}

	public boolean hover() {
		final CapturedModel model = getModel();
		return model != null ? model.hover() : getLocation().hover();
	}

	public boolean click(final boolean left) {
		final CapturedModel model = getModel();
		return model != null ? model.click(left) : getLocation().click(left);
	}

	public boolean interact(final String action) {
		final CapturedModel model = getModel();
		return model != null ? model.interact(action) : getLocation().interact(action);
	}

	public boolean interact(final String action, final String option) {
		final CapturedModel model = getModel();
		return model != null ? model.interact(action, option) : getLocation().interact(action, option);
	}

	public void draw(final Graphics render) {
		final CapturedModel model = getModel();
		if (model != null) {
			model.draw(render);
		} else {
			getLocation().draw(render);
		}
	}

	@Override
	public boolean equals(final Object o) {
		if (o instanceof SceneObject) {
			final SceneObject object = (SceneObject) o;
			return object.object == this.object;
		}
		return false;
	}

	@Override
	public String toString() {
		return "location[ref=" + System.identityHashCode(object) + ",id=" + getId() + ",plane=" + plane + ",type=" + Integer.toString(type) + "]";
	}
}
