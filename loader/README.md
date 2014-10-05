About the Java loader
=====================

The Java loader is set up as a Java project using an Ant build script to build and run 
the project. You can open the project in your preferred IDE as you would any other Ant 
project. 

Note that there is auxilary data for Netbeans, allowing a more fluent integration 
between the Ant targets and your Netbeans IDE. It also allows your IDE to open the Ant 
project without any configuration. On Eclipse, you have to "Import existing project into
workspace" and make sure the option to make a copy is not selected (otherwise changes you
make are not reflected by git).

The Ant build script provides standard targets like clean, build, jar and run. Also, in order
to make it easier to run the project as a whole, there is a run-native target, which runs the 
native client. Note, however, that you should make sure there is a working build of the native
client, as the Ant build script does not build the native client.