# PowerGrid Runescape loader #
This folder contains the loader used for loading the Runescape client. Unlike the bot itself, the loader is written in Java. This is because it is easier (and faster) to display a Java Applet in a Java window than in a C++ (Qt) window. 

Also, the loader provides an environment very similar to the official Jagex Applet loader jar file distributed with the official Runescape stand-alone client. This provides a stable environment for the Runescape client and as such prevents Runescape client updates from breaking the loader.

## Running the loader from command line ##
You are free to use this loader for your own purposes. The same license applies to the loader as to the rest of the PowerGrid client (which is GPL version 3, see [here](http://www.gnu.org/licenses/gpl.html)).

The loader can be used with some command line options, which are explained below:

**—force-download** (or -f) - Forces the PowerGrid client to re-download all Runescape client data regardless of whether there is valid data in the cache. This may resolve some spurious errors with starting the client, but is generally slower than having the client automatically decide if downloading the Runescape client data is required. 

**--updater** (or -u) - Collects update data from the remote updater. Enabling this setting causes the loader to communicate with the online updater server to collect the update data. This allows the loader to undo the client's obfuscation and stores it in the file "cache/updateInfo.dat”. It must be noted that without this option, the loader might not work as a bot client, but only as a stand-alone Runescape client (like the official Runescape client)!

**—debug** (or -d) - Prints detailed messages and trace information to the console. This option is   really only useful for developers.

**-quiet**  (or -q) - Prints only short messages to the console. This option is ignored if debug is also specified.

**-verbose** (or -v) - Prints more detailed messages, but not as detailed as the ‘debug’ mode. This option is ignored if either ‘debug’ or ‘quiet’ mode is specified. 

## Running the loader stand-alone ##
If you want to run this client stand-alone, the following command (or similar) is recommended:  

```
    java -jar -Xms512M loader.jar
```
You can also simply double-click the jar file (might not work on some Windows computers).

It is recommended to use the “-Xms512M” flag, as it may speed up loading the Runescape client. This is because Runescape may use quite some amount of memory during startup, and this option reserves 512MB memory in advance, possibly making the client start faster.