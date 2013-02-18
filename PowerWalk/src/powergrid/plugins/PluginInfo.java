package powergrid.plugins;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * Annotation interface for Plugins.
 * <p/>
 * It is a slightly adapted version of RSBot's Manifest. Wereas Manifest had 
 * topic, vip, hidden and singleinstance fields, PluginInfo simply has a 
 * requiredVersion that lists the minimal required PowerGrid version for the plugin to 
 * work correctly. It is advised that developers set this field to the version of 
 * PowerGrid they tested with.
 * <p/>
 * It is possible for Plugins to be run without any PluginInfo at all. However, this
 * prevents users from recognizing your plugin, so it is strongly advised to include
 * as much info as possible.
 * <p/>
 * @author Chronio
 */
@Retention(RetentionPolicy.RUNTIME)
public @interface PluginInfo {
    String name() default "Nameless Plugin";
    String description() default "<no description>";
    String[] authors() default "<unknown>";
    String website() default "";
    double version() default 1.0;
    double requiredVersion() default 0;
}
