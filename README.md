
![PowerGrid](http://i.imgur.com/I8SAxWT.png)

PowerGrid is a revolutionary bot platform that aims to provide a more open approach to botting than other clients have shown so far. Being written in C++, PowerGrid also aims to provide a more fluent experience for end-users, and a generally faster and more dynamic programming language to work in.  

## PowerGrid functionality ##
PowerGrid offers a completely new travelling system that allows the user to walk to any location in the Runescape world, while also using available teleports and shortcuts to get to the destination in the fastest possible way.

It also provides a mechanism to check a variety of stats and settings without needing to navigate through widgets, PowerGrid automatically checks these when required, but caches the results so that consecutive calls are much faster. This is mainly required because PowerGrid uses JNI to interact with the Java environment, which is usually slower than interaction from within the Java environment, but the big advantage is that PowerGrid's further processing happens completely separate from the Java Virtual machine, being not only much faster, but also less detectable than executing similar code inside the JVM.

PowerGrid offers a full user interface to travel to any destination or location using either landmarks, special locations such as banks and stores, or even an actual world map, allowing the user to click any tile on the map, after which PowerGrid computes a route and executes it for maximum control.

PowerGrid is, unlike other bots, written in C++. While this causes a delay in transferring data from the Java environment to C++, the C++ functions themselves can be made much faster, and since most code will run outside the Java Virtual Machine, there is also less chance of the Runescape client detecting the bot. 

The loader itself is inspired by the official open-source loader for Runescape, also written in C++. More specifically, PowerGrid uses the very same files as the Runescape loader (and as such requires that the loader is installed in order to work). Because of this, PowerGrid will appear to be a normal loader application, while in reality, PowerGrid monitors various settings, objects, and data structures to use for botting purposes.



## Using PowerGrid ##

PowerGrid comes with its own control frame that is separate from the main Runescape frame.  This is because the Runescape frame is in reality a Java frame, and PowerGrid's control frame is not.

Because of this feature, it is also possible to use PowerGrid to play Runescape normally, without PowerGrid getting in the way. Also, PowerGrid solely uses reflection to monitor the bot, which opens up more dynamic possibilities than when using injection. This is because Runescape's classes themselves are not modified, and this prevents many workarounds that other bot platforms have to make to get the injection to work.
