## PowerGrid Runescape loader ##
This folder contains the loader used for loading the Runescape client. Unlike the bot itself, the loader is written in Java. This is because it is easier (and faster) to display a Java Applet in a Java window than in a C++ (Qt) window. Also, the loader provides an environment very similar to the official Jagex Applet loader jar file distributed with the official Runescape stand-alone client.

### Using this loader ###
You are free to use this loader for your own purposes. The same license applies to the loader as to the rest of the PowerGrid client (which is GPL, see [here](http://www.gnu.org/licenses/gpl.html)).

The loader can be used with some command line options, which are explained below:

**--quickload** - Prevents the client from re-downloading the client data and this reduces loading times a lot. However, it may also mean that the Applet cannot run because it is outdated.

**--loader-only** - Prevents the client from performing bot-related tasks. This reduces loading time a bit, and is recommended when using the loader stand-alone (without PowerGrid).

If you want to run this client stand-alone, the following command (or similar) is recommended:  

```
    java -jar -Xms256M -Xincgc loader.jar --no-updater
```