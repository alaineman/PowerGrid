package powergrid.plugins;

import java.lang.annotation.Documented;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * Annotation interface for Plugins.
 * <p/>
 * It is a slightly adapted version of RSBot's Manifest. Whereas Manifest had 
 * topic, vip, hidden and singleinstance fields, PluginInfo simply has a 
 * requiredVersion that lists the minimal required PowerGrid version for the 
 * plugin to work correctly. It is advised that developers set this field to 
 * the version of PowerGrid they tested with. PowerGrid will accept all 
 * Plugins that require PowerGrid's own version or lower.
 * <p/>
 * It is possible for Plugins to be run without any PluginInfo at all. However, this
 * prevents users from recognizing your plugin, so it is strongly advised to include
 * as much info as possible. Leaving out PluginInfo also breaks certain pieces 
 * of auxiliary code, making it harder for users to control the different 
 * functions of the Plugin. Therefore it's highly recommended to include it.
 * <p/>
 * @author Chronio
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
public @interface PluginInfo {
    
    /** The name of the Plugin. 
     *  This is preferrably a unique name to avoid confusion.
     */
    String name() default "Nameless Plugin";
    
    /** The Plugin's description. 
     */
    String description() default "<no description>";
    
    /** The author(s) of the Plugin. 
     */
    String[] authors() default "<unknown>";
    
    /** The website on which more information about the Plugin can be found. 
     */
    String website() default "";
    
    /** An array containing the required Plugin classes for this Plugin to work. 
     * The Plugin will be rejected when not all requirements are found. 
     */
    Class<? extends Plugin>[] required() default {};
    
    /** The version of the plugin. 
     */ 
    double version() default 1.0;
    
    /** The required PowerGrid version this Plugin needs to work correctly. 
     * PowerGrid will reject all Plugins with a higher requiredVersion attribute 
     * than PowerGrid's own version. 
     */
    double requiredVersion() default 0;
}
