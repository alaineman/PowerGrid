
PowerGrid is a revolutionary bot platform that aims to provide a more open approach to botting than other clients have shown so far. Being written in C++, PowerGrid also aims to provide a more fluent experience for end-users, and a generally faster and more dynamic programming language to work in.  

## PowerGrid functionality ##
PowerGrid aims to surpass current Runescape bots by revolutionizing the way it deals with its extensions. Where traditional bot clients focus on the botting aspect and work through executing scripts, PowerGrid works in a completely different way: PowerGrid makes use of the provided extensions to improve the tasks it performs. For example, a plugin developer would write an extension to PowerGrid for interacting with a transportation system called "fairy rings" in the Runescape world. This plugin can be loaded by PowerGrid, and the PowerGrid AI can then use the extended functionality to find shorter paths across the world. Such extensions can be created for not only travelling, but also for training virtually all skills.

PowerGrid is, unlike other bots, written in C++. While this causes a delay in transferring data from the Java environment to C++, the C++ functions themselves can be made much faster, and since most code will run outside the Java Virtual Machine, there is also less chance of the Runescape client detecting the bot. 

The loader itself is inspired by the official open-source loader for Runescape, also written in C++. Because of this, PowerGrid will appear to be a normal loader application, while in reality, PowerGrid monitors various settings, objects, and data structures in the Runescape client.

## Building PowerGrid ##
PowerGrid depends on Qt 5.4 and the Java 8 JDK. For complete instructions on how to build PowerGrid, please refer to the build instructions located at "doc/BuildInstructions.md".

## Using PowerGrid ##
Java 8 is required for playing Runescape through PowerGrid. Aside from that, most of PowerGrid's features are added through plugins. Please refer to the documentation of each plugin for information on how it's used. To optimize the experience of playing Runescape, PowerGrid does not place anything in the Runescape window other than the game itself. Instead, all of Powergrid's configuration options are accessible through a second window. 

## Legal notes ##
We believe in the power of free software, and as such we decided to make the entire bot open-source, including the core, api, and applet loader. We believe that together with everyone we can continue to improve PowerGrid, and meet the expectations of our users. Therefore, we licensed the PowerGrid client under the GNU GPL version 3, so that everyone may use it and modify it as they want. The license can be found in the file named 'COPYING' in the root of the PowerGrid repository.

Also, by using PowerGrid you accept that Jagex Co. Ltd. may place restrictions on your use of Runescape including, but not limited to, stat resets, temporary bans, and possibly permanent bans. The authors of PowerGrid do not hold themselves responsible for any damages in any form whatsoever caused by the use of the PowerGrid software. See the GNU GPL version 3 for the details.


Hey, saw this project is C++ very intersted in contacting you.
hegsy3@gmail.com

Cheers
