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
platforms it should be similar, although this hasn't been tested.

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

Step 3: While we're busy...
---------------------------
Qt Creator will now invoke make and make install automatically, and copy all we need to the 'dist' 
directory. However, for compiling (the most time-consuming task), MinGW's make will only use one 
core by default. A waste of time if you have a multi-core processor! Therefore we are going to instruct 
make to build multiple targets at the same time, making more efficient use of your multi-core processor.

Beware that this only works for the GCC version of make! When you use the Visual Studio compiler on 
Windows, Qt already does this step for you using a tool called jom. In other build configurations, 
please look up the documentation for your build tools to achieve similar functionality.

We go to the place we added the 'ant jar' command earlier. At the 'make' comment (not 'make install'),
add '-j 4' (without the quotes) to the 'Make arguments' field (Replace '4' with the actual number of cores
you want to use for compiling. Setting this higher than the amount of cores in your processor will 
most likely not speed up compilation. For example, when you have a dual-core processor, you would
enter '-j 2', instead of '-j 4'. 

One last remark: when you use all cores in your processor for compilation, your computer may respond slow or
seem to lag during compilation. This is normal, since all cores are being fully used. If you still want to do other 
things at the same time, you may wish to reserve one (or maybe even two) cores for other things, so that 
you can continue to use your computer normally in the meantime.


