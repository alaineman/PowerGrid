package org.powerbot.game.api.wrappers.graphics;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Polygon;
import java.util.ArrayList;
import java.util.Arrays;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.methods.node.Menu;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.wrappers.Entity;
import org.powerbot.game.api.wrappers.Verifiable;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Model;
import org.powerbot.game.client.ModelCapture;

public abstract class CapturedModel implements Entity {
	private final Verifiable verifiable;

	/**
	 * Returns a filter that matches against the array of point indices for the
	 * A vertices of each triangle. Use in scripts is discouraged.
	 *
	 * @param vertex_a The array of indices for A vertices.
	 * @return The vertex point index based model filter.
	 */
	public static Filter<CapturedModel> newVertexFilter(final short[] vertex_a) {
		return new Filter<CapturedModel>() {
			public boolean accept(final CapturedModel m) {
				return Arrays.equals(m.indices1, vertex_a);
			}
		};
	}

	protected int[] xPoints;
	protected final int[] yPoints;
	protected int[] zPoints;

	protected final short[] indices1;
	protected final short[] indices2;
	protected final short[] indices3;

	protected final int numVertices;
	protected final int numFaces;

	public CapturedModel(final Model model, final Verifiable verifiable) {
		this.verifiable = verifiable;
		xPoints = model.getXPoints();
		yPoints = model.getYPoints();
		zPoints = model.getZPoints();
		indices1 = model.getIndices1();
		indices2 = model.getIndices2();
		indices3 = model.getIndices3();
		if (model instanceof ModelCapture) {
			numVertices = ((ModelCapture) model).getNumVertices();
			numFaces = ((ModelCapture) model).getNumFaces();
		} else {
			numVertices = Math.min(xPoints.length, Math.min(yPoints.length, zPoints.length));
			numFaces = Math.min(indices1.length, Math.min(indices2.length, indices3.length));
		}
	}

	protected abstract int getLocalX();

	protected abstract int getLocalY();

	protected abstract int getPlane();

	protected abstract void update();

	public boolean validate() {
		return verifiable == null || verifiable.validate();
	}

	public Point getCentralPoint() {
		if (numFaces < 1) {
			return new Point(-1, -1);
		}
		int totalXAverage = 0;
		int totalYAverage = 0;
		int totalHeightAverage = 0;
		int index = 0;

		final int x = getLocalX();
		final int y = getLocalY();
		final int height = Calculations.calculateTileHeight(x, y, getPlane());

		final int[][] points = projectVertices();

		while (index < numFaces) {
			final int index1 = indices1[index];
			final int index2 = indices2[index];
			final int index3 = indices3[index];
			if (points[index1][2] + points[index2][2] + points[index3][2] == 3) {
				totalXAverage += (xPoints[index1] + xPoints[index2] + xPoints[index3]) / 3;
				totalYAverage += (zPoints[index1] + zPoints[index2] + zPoints[index3]) / 3;
				totalHeightAverage += (yPoints[index1] + yPoints[index2] + yPoints[index3]) / 3;
			}
			index++;
		}

		final Point averagePoint = Calculations.worldToScreen(
				x + totalXAverage / numFaces,
				height + totalHeightAverage / numFaces,
				y + totalYAverage / numFaces
		);

		if (Calculations.isOnScreen(averagePoint)) {
			return averagePoint;
		}
		return new Point(-1, -1);
	}

	public Point getNextViewportPoint() {
		final java.util.List<Point> foundPoints = new ArrayList<Point>();
		final int[][] points = projectVertices();
		for (int index = 0; index < numVertices; index++) {
			if (points[index][2] == 1) {
				foundPoints.add(new Point(points[index][0], points[index][1]));
			}
		}
		if (foundPoints.size() > 0 && isOnScreen()) {
			return foundPoints.get(Random.nextInt(0, foundPoints.size()));
		}
		return new Point(-1, -1);
	}

	public boolean contains(final Point point) {
		final Polygon[] polygons = getBounds();
		for (final Polygon triangle : polygons) {
			if (triangle.contains(point.x, point.y)) {
				return true;
			}
		}
		return false;
	}

	public boolean isOnScreen() {
		final int[][] points = projectVertices();
		for (int index = 0; index < numFaces; index++) {
			final int index1 = indices1[index];
			final int index2 = indices2[index];
			final int index3 = indices3[index];
			if (points[index1][2] + points[index2][2] + points[index3][2] == 3) {
				return true;
			}
		}
		return false;
	}

	public Polygon[] getBounds() {
		final int[][] points = projectVertices();
		ArrayList<Polygon> polys = new ArrayList<Polygon>(numFaces);
		for (int index = 0; index < numFaces; index++) {
			final int index1 = indices1[index];
			final int index2 = indices2[index];
			final int index3 = indices3[index];

			final int xPoints[] = new int[3];
			final int yPoints[] = new int[3];

			xPoints[0] = points[index1][0];
			yPoints[0] = points[index1][1];
			xPoints[1] = points[index2][0];
			yPoints[1] = points[index2][1];
			xPoints[2] = points[index3][0];
			yPoints[2] = points[index3][1];

			if (points[index1][2] + points[index2][2] + points[index3][2] == 3) {
				polys.add(new Polygon(xPoints, yPoints, 3));
			}
		}
		return polys.toArray(new Polygon[polys.size()]);
	}

	public boolean hover() {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(Point point) {
				return true;
			}
		});
	}

	public boolean click(final boolean left) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(Point point) {
				Mouse.click(left);
				return true;
			}
		});
	}

	public boolean interact(final String action) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action);
			}
		});
	}

	public boolean interact(final String action, final String option) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action, option);
			}
		});
	}

	public void draw(final Graphics render) {
		final int[][] screen = projectVertices();

		for (int index = 0; index < numFaces; index++) {
			int index1 = indices1[index];
			int index2 = indices2[index];
			int index3 = indices3[index];

			int point1X = screen[index1][0];
			int point1Y = screen[index1][1];
			int point2X = screen[index2][0];
			int point2Y = screen[index2][1];
			int point3X = screen[index3][0];
			int point3Y = screen[index3][1];

			if (screen[index1][2] + screen[index2][2] + screen[index3][2] == 3) {
				render.drawLine(point1X, point1Y, point2X, point2Y);
				render.drawLine(point2X, point2Y, point3X, point3Y);
				render.drawLine(point3X, point3Y, point1X, point1Y);
			}
		}
	}

	public int[][] projectVertices() {
		final Context context = Context.get();
		final Calculations.Toolkit toolkit = context.getToolkit();
		final Calculations.Viewport viewport = context.getViewport();

		update();
		final int locX = getLocalX();
		final int locY = getLocalY();
		final int height = Calculations.calculateTileHeight(locX, locY, getPlane());

		final int[][] screen = new int[numVertices][3];
		for (int index = 0; index < numVertices; index++) {
			final int x = xPoints[index] + locX;
			final int y = yPoints[index] + height;
			final int z = zPoints[index] + locY;

			final float _z = (viewport.zOff + (viewport.zX * x + viewport.zY * y + viewport.zZ * z));
			final float _x = (viewport.xOff + (viewport.xX * x + viewport.xY * y + viewport.xZ * z));
			final float _y = (viewport.yOff + (viewport.yX * x + viewport.yY * y + viewport.yZ * z));

			if (_x >= -_z && _x <= _z && _y >= -_z && _y <= _z) {
				screen[index][0] = Math.round(toolkit.absoluteX + (toolkit.xMultiplier * _x) / _z);
				screen[index][1] = Math.round(toolkit.absoluteY + (toolkit.yMultiplier * _y) / _z);
				screen[index][2] = 1;
			} else {
				screen[index][0] = -1;
				screen[index][1] = -1;
				screen[index][2] = 0;
			}
		}
		return screen;
	}

	public int getNumFaces() {
		return numFaces;
	}

	public short[] getIndices1() {
		return indices1;
	}

	public short[] getIndices2() {
		return indices2;
	}

	public short[] getIndices3() {
		return indices3;
	}

	@Override
	public boolean equals(final Object o) {
		return o != null && o instanceof CapturedModel && Arrays.equals(((CapturedModel) o).indices1, indices1);
	}

	@Override
	public String toString() {
		return "[faces=" + numFaces + "vertices=" + numVertices + "] " + Arrays.toString(indices1);
	}
}
