Set up Qt Creator to autobuild everything at once
=================================================

This document explains how to set up Qt Creator in such a way that the entire project 
(including the Java loader) is automatically built with only Qt Creator's build command.
This ensures you are never running an outdated client version and prevents switching 
between Netbeans and Qt Creator more than required.

Step 1: Find the path to Apache Ant 
-----------------------------------
First we have to make sure Qt Creator has access to Apache Ant, which is the build tool 
that Netbeans uses. It works in a similar way as the make command does for various 
languages including C and C++, but it is primarily intended for Java. Netbeans comes 
with its own distribution of Apache Ant, which we can use to let Qt Creator build the
Java loader jar file whenever we build the project. If you want, you can install and 
configure Ant yourself, but since Netbeans already has it set up, we can simply use it
from there.

To achieve this, we first have to locate the Ant tool within Netbeans. It is usually found 
at "<NetbeansRoot>/extide/ant/bin". <NetbeansRoot> is usually "C:\Program Files\Netbeans <version>\" 
on Windows, and "Applications/Netbeans/Netbeans <version>.app/Contents/Resources/NetBeans/" on 
Mac OS X (right-click the Netbeans app and select "show package contents" to see it). On other 
platforms it should be similar, although I haven't tested it.

Step 2: Make Qt Creator execute ant automatically.
--------------------------------------------------
Once we found the path, we must then tell Qt Creator where it is. In Qt Creator, go to 
Projects > Build settings > Build Environment and select the entry with PATH in the list 
below. Click "Edit" and add the path you just found to the end of the list of paths already 
there. For Windows, split paths with a semicolon, and on other platforms with a colon. 
Warning: Do not remove anything from the path there, or your build may fail!

Now that Qt Creator can find ant, we need to make Qt Creator actually run it when building PowerGrid. 
To do this, while still in Build Settings, go to the section labeled Build Steps and click 
"Add Build Step" > "Custom Process Step" and fill in "ant" as command and "jar" as arguments (do not 
include the quotes). Set the Working directory to the root of the Netbeans project, which is the 
directory named "loader" in the PowerGrid repository. This will tell ant to compile and create a 
jar file from the project there. The settings of the Netbeans project are set
so that ant will place the resulting jar file in a directory called "dist" in the repository's 
root directory. The QMake .pro file is also configured to place the resulting executable there, 
meaning that everything is put together automatically so that everything can be run from Qt Creator.

Now Qt Creator will call Apache Ant to build and create the loader jar file after it finished building 
the PowerGrid application, ensuring that you always run the latest version of both the C++ client and 
the Java loader.