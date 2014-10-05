Build Instructions
==================

Make sure to have installed Netbeans / Eclipse / Ant (with JDK 8 or higher), Qt (5.1.0 or higher), 
and a C++ toolchain supported by Qt (You can use Qt for Windows bundled with MinGW for easy set up).

If you also want to be able to generate documentation for PowerGrid, you also need Doxygen. 
The Doxyfile for the project resides in the 'doc' directory.

The 'loader' directory contains a Ant Java project with the Runescape client loader.
The 'src' directory contains the C++ source. You can open the file 'src/PowerGrid.pro' in 
Qt Creator (bundled with Qt) to view/edit the PowerGrid source files. 

When you open the C++ project for the first time, you are given the option to choose a toolchain 
and build directories for the Debug and Release targets. You are advised to leave all settings 
on default, but if you do change the build directories, please make sure the paths to these 
directories start with 'build'. This way they are not accidentally added to the git repository.

After this, it is possible to configure Qt to build everything at once and place the resulting 
executable including all Qt dependencies and the Java loader (which is also automatically 
compiled if needed) in the 'dist' directory. This ensures you are never running an outdated 
client version and prevents switching between your IDE and Qt Creator more than required.

First we have to make sure Qt Creator has access to Apache Ant, which is the build tool 
that both Netbeans and Ecplise use. It works in a similar way as the make command does for 
various  languages including C and C++, but it is primarily intended for Java. Your IDE comes 
with its own distribution of Apache Ant, which we can use to let Qt Creator build the
Java loader jar file whenever we build the project. If you want, you can download and install Ant 
yourself, but since your IDE already has it set up, we can also use it from there.

For Netbeans, you can do the following:
We first have to locate the Ant tool within Netbeans. It is usually found 
at "<NetbeansRoot>/extide/ant/bin". <NetbeansRoot> is usually "C:\Program Files\Netbeans <version>\" 
on Windows, "Applications/Netbeans/Netbeans <version>.app/Contents/Resources/NetBeans/" on 
Mac OS X (right-click the Netbeans app and select "show package contents" to see it) and on Ubuntu,
Netbeans installs by default to "~/netbeans-<version>/". On other platforms it should be similar, 
although this hasn't been verified. On Ecplise, it works in a similar way.

You can also download Apache Ant from http://ant.apache.org/, and extract it to a directory of your 
choice (An IDE is not required to build/run the project).

Once we found the path, we must then tell Qt Creator where it is. In Qt Creator, go to 
Projects > Build settings > Build Environment and select the entry with PATH in the list 
below. Click "Edit" and add the path you just found to the end of the list of paths already 
there. For Windows, split paths with a semicolon, and on other platforms with a colon. 
Warning: Do not remove anything from the path there, or your build may fail!

Now that Qt Creator can find ant, we need to make Qt Creator actually run it when building PowerGrid. 
To do this, while still in Build Settings, go to the section labeled Build Steps and click 
"Add Build Step" > "Custom Process Step" and fill in "ant.bat" as command and "jar" as arguments (do not 
include the quotes). Set the Working directory to "%{buildDir}\..\loader". This will tell ant to compile 
and create a jar file from the project there. The Ant script is set to place the resulting jar file in 
a directory called "dist" in the repository's root directory. The QMake .pro file is also configured to 
place the resulting executable there, meaning that everything is put together automatically so that 
everything can be run from Qt Creator.

Still in the 'Build Steps' section, add another step. This time, choose 'Make' as the type of build step.
In the field 'Make arguments', add 'install'. This copies the dependencies for PowerGrid to the 'dist' 
directory. If you only run the project from Qt Creator, you don't need to do this (Qt Creator adds the Qt 
libraries to the PATH). However, by copying the dependencies, it is possible to run PowerGrid stand-alone.
Please also consider the fact that the total size of the libraries can be over 200MB (depending on the 
specific platform/version of Qt), mainly due to the size of Qt's Debug libraries. If you don't have a lot 
of disk space to spare, it may not be useful to copy the libraries.

Now Qt Creator will call Apache Ant to build and create the loader jar file after 'make' finished building 
the PowerGrid application, ensuring that you always run the latest version of both the C++ client and 
the Java loader.

Qt Creator will now invoke make and make install automatically, and copy all we need to the 'dist' 
directory. However, for compiling (the most time-consuming task), MinGW's make will only use one 
core by default. A waste of time if you have a multi-core processor! Therefore we are going to instruct 
make to build multiple targets at the same time, making more efficient use of your multi-core processor.

Beware that this only works for the GCC version of make (including MinGW's make utility)! When you use the 
Visual Studio compiler on Windows, Qt Creator already does this step for you using a tool called jom. In 
other build configurations, please look up the documentation for your build tools to achieve similar 
functionality.

We go to the place we added the 'ant jar' command earlier. At the 'make' comment (not 'make install'),
add '-j 4' (without the quotes) to the 'Make arguments' field (Replace '4' with the actual number of cores
you want to use for compiling. Setting this higher than the amount of cores in your processor will 
most likely not speed up compilation, but it may cause your computer to hang while it's busy. For example, 
when you have a dual-core processor, you would enter '-j 2', instead of '-j 4'. 

One remark about multi-threaded compiling: when you use all cores in your processor for compilation, your 
computer may respond slow or seem to lag during compilation (depending on your hardware). This is normal, 
since all cores are being fully used. If you still want to do other things at the same time, you may wish 
to reserve one (or maybe even two) cores for other things, so that you can continue to use your computer 
normally in the meantime.

When you build PowerGrid, the Qt5XXX libraries are automatically copied along to the 'dist' directory. 
However, the pre-built Qt5 version offered on qt-project.org has extra dependencies to the ICU libraries.
These libraries provide internationalisation and Unicode support, and are only required for the Qt Webkit 
module. Since PowerGrid does not use Qt Webkit, it is possible to build Qt from scratch without webkit 
support, saving over 20MB of disk space in the final application. For a guide on how to build Qt for this 
purpose, see the 'BuildInstructions-QT.md' file.

While running the build, please be aware of the following: For reasons unknown, the RS client may not be 
able to find some native libraries when launched from within Qt Creator. This has as an effect that 
hardware-accelerated graphics are not available. This is indicated by the option "Safe Mode" being selected
in the graphics options. Running the native client standalone from the "dist" directory or through the Ant
build script seems to work correctly, though.
