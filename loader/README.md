## PowerGrid Runescape loader ##
This folder contains the loader used for loading the Runescape client. Unlike the bot itself, the loader is written in Java. This is because it is easier (and faster) to display a Java Applet in a Java window than in a C++ (Qt) window. 

Also, the loader provides an environment very similar to the official Jagex Applet loader jar file distributed with the official Runescape stand-alone client. This provides a stable environment for the Runescape client and as such prevents Runescape client updates from breaking the loader.

### Using this loader ###
You are free to use this loader for your own purposes. The same license applies to the loader as to the rest of the PowerGrid client (which is GPL, see [here](http://www.gnu.org/licenses/gpl.html)).

The loader can be used with some command line options, which are explained below:

**--quickload** - Prevents the client from re-downloading the client data and this reduces loading times a lot. However, it may also mean that the Applet cannot run because it is outdated.

**--update** - Collects update data from the remote updater. Enabling this setting causes the loader to communicate with the online updater server to collect the update data. This allows the loader to undo the client's obfuscation and enables communication with the Runescape client from external applications.

**--devmode** - Creates an additional window containing development tools. Not really useful for anyone except developers.

If you want to run this client stand-alone, the following command (or similar) is recommended:  

```
    java -jar -Xms256M loader.jar
```
You can also simply double-click the jar file.

Alternatively, if you want to run this client from another client, call the following from within that client:
```
    net.pgrid.loader.AppletLoader.main(new String[] {"--update"});
```
Including "--update" as a parameter will instruct the client to enable the updater, which is required to undo the client's obfuscation and to allow communication with the running Runescape client.