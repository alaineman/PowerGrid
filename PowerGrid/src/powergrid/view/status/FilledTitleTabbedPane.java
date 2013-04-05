package powergrid.view.status;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Insets;
import javax.swing.Icon;
import javax.swing.JLabel;
import javax.swing.JTabbedPane;
import javax.swing.UIManager;
import javax.swing.plaf.synth.Region;
import javax.swing.plaf.synth.SynthConstants;
import javax.swing.plaf.synth.SynthContext;
import javax.swing.plaf.synth.SynthLookAndFeel;
import javax.swing.plaf.synth.SynthStyle;

public class FilledTitleTabbedPane extends JTabbedPane {

	private static final long serialVersionUID = 1L;

	public FilledTitleTabbedPane() {
		super();
	}

	public FilledTitleTabbedPane(int tabPlacement) {
		super(tabPlacement);
	}

	private Insets getTabInsets() {
		Insets i = UIManager.getInsets("TabbedPane.tabInsets");
		if (i != null) {
			return i;
		} else {
			SynthStyle style = SynthLookAndFeel.getStyle(this,
					Region.TABBED_PANE_TAB);
			SynthContext context = new SynthContext(this,
					Region.TABBED_PANE_TAB, style, SynthConstants.ENABLED);
			return style.getInsets(context, null);
		}
	}

	private Insets getTabAreaInsets() {
		Insets i = UIManager.getInsets("TabbedPane.tabAreaInsets");
		if (i != null) {
			return i;
		} else {
			SynthStyle style = SynthLookAndFeel.getStyle(this,
					Region.TABBED_PANE_TAB_AREA);
			SynthContext context = new SynthContext(this,
					Region.TABBED_PANE_TAB_AREA, style, SynthConstants.ENABLED);
			return style.getInsets(context, null);
		}
	}

	@Override
	public void doLayout() {
		int tabCount = getTabCount();
		if (tabCount == 0)
			return;
		Insets tabInsets = getTabInsets();
		Insets tabAreaInsets = getTabAreaInsets();
		Insets insets = getInsets();
		int areaWidth = getWidth() - tabAreaInsets.left - tabAreaInsets.right
				- insets.left - insets.right;
		int tabWidth = 0; // = tabInsets.left + tabInsets.right + 3;
		int gap = 0;

		switch (getTabPlacement()) {
		case LEFT:
		case RIGHT:
			tabWidth = areaWidth / 4;
			gap = 0;
			break;
		case BOTTOM:
		case TOP:
		default:
			tabWidth = areaWidth / tabCount;
			gap = areaWidth - (tabWidth * tabCount);
		}
		// "3" is magic number @see BasicTabbedPaneUI#calculateTabWidth
		tabWidth = tabWidth - tabInsets.left - tabInsets.right - 3;
		for (int i = 0; i < tabCount; i++) {
			JLabel l = (JLabel) getTabComponentAt(i);
			if (l == null)
				break;
			l.setPreferredSize(new Dimension(tabWidth + (i < gap ? 1 : 0), l
					.getPreferredSize().height));
		}
		super.doLayout();
	}

	@Override
	public void insertTab(String title, Icon icon, Component component,
			String tip, int index) {
		super.insertTab(title, icon, component, tip == null ? title : tip,
				index);
		JLabel label = new JLabel(title, JLabel.CENTER);
		Dimension dim = label.getPreferredSize();
		Insets tabInsets = getTabInsets();
		label.setPreferredSize(new Dimension(0, dim.height + tabInsets.top
				+ tabInsets.bottom));
		setTabComponentAt(index, label);
	}
}
