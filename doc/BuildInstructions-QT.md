Build Instructions for Qt5
==========================

This document explains how to build Qt from scratch, minimizing the size of the 
Qt library for use with PowerGrid. If you intend to build PowerGrid yourself in 
order to play it, it is advisory (though not required) to follow this guide.

This guide assumes you're compiling Qt for Windows using MinGW. If not, please 
follow the build guide available at qt-project.org, as platforms beside Windows 
are outside of the scope of this guide. Before you begin, please read ahead first
before executing commands. This may help you prevent some errors.

The entire procedure of compiling Qt takes quite some time (on most machines it may
take somewhere over an hour to complete). As such, make sure you have more than 
enough time available before you begin to follow this guide.

Step 1: Getting the required tools
----------------------------------
Our first step is to get the required tools. The tools required to build Qt are 
as follows: 

1. Git for Windows (http://www.git-scm.org/)
2. Perl (http://www.activestate.com/activeperl/downloads/)
3. Python (https://www.python.org/downloads/)

For each tool, choose the newest version to install (As for Python, version 3.X works fine), 
and select the option to add the tool to your PATH environment variable (for Git, choose the 
second option, to enable Git in Windows command window).

Step 2: Getting the Qt sources
------------------------------
After installing all three tools, open a command prompt window and go into a directory
of your choice (where you want the Qt library to be, e.g. C:\Qt). Invoke the following 
commands:

    git clone git://gitorious.org/qt/qt5 qt5
    cd qt5
    git checkout 5.4

If the first command fails, replace git:// with http:// and retry. This sometimes happens 
with certain router/firewall configurations.

Also note, that if your computer has an SSD, it is advised to checkout the repository to 
a folder on your SSD, as it may speed up compilation a lot!

Step 3: Configure the build
---------------------------
Now you have the contents of the Qt repository on your machine and have checked out the 
'5.4' branch. Now run the following:

    perl init-repository --no-webkit
    configure -opensource -nomake tests -nomake examples -opengl desktop -no-icu

If you needed to replace the git protocol with http in step 2, also add '-http' to the 
init-repository' command.

The above commands will set up your Qt build configuration, excluding webkit and 
the ICU libraries. It also skips the examples and tests (we don't need them anyway).

IMPORTANT: If the configure command ends with telling you that the build will most 
likely fail, then there is something wrong with the configuration. If, at any time, 
unexplainable errors / fault messages occur, you can reset the entire repository by 
calling the following command:

    git submodule foreach --recursive "git clean -dfx"

This will clean the entire repository, and reset you back to the beginning of step 3.
For any errors that cannot be resolved by retrying from there, you can search Google
or the Qt forums for a solution for your specific problem. Often times, someone else 
has had that same problem before. 

Step 4: Building Qt
-------------------
Now everthing is in place and configured. It is advised to first check whether 
Python and g++ are available from your command window. To do so, execute the following
commands:

    g++ --version
    python --version

It is advised to have g++ 4.8.0 or higher, as it supports all C++11 features as well as 
solves some bugs present in Qt when compiled with lower GCC versions.

Execute the following command (replace n with the amount of cores your processor has):

    mingw32-make -j n

For example, on a quad-core CPU, call `mingw32-make -j 4`. On a single-core processor,
you can just execute "mingw32-make" without options, although this takes a really long 
time. 

After you invoke this command, you will have to wait a long, long time. Building Qt 
requires your computer to build all individual Qt modules, which results in a lot of work. 
As the compilation process may take up to a few hours to complete, you can easily do other 
things in the meantime, just remember, that if you want to use your computer in the meantime, 
you will run into problems if you do any CPU-intensive tasks, as your CPU is already 
busy compiling. If you insist on using your computer, you can decrease the amount of cores used.

If you don't have the time, and are willing to take the risk with missing dependencies,
you can build the individual Qt modules required for PowerGrid (at the moment QtCore, QtGui, 
and QtWidgets):

    mingw32-make -j n module-qtcore
    mingw32-make -j n module-qtgui
    mingw32-make -j n module-qtwidgets

Again, replace `n` with how many cores you want to use for compilation. Although this saves a 
lot of time, it cannot be guaranteed that all required dependencies and components are in place.
So use at your own risk!

Step 5: Verifying and setting up Qt Creator
-------------------------------------------
Qt built in this way does not include Qt Creator. Qt Creator is available from 
http://qt-project.org/ (look for Qt Creator download only, not the Qt Library).

Install Qt Creator, and run it. Go to Tools > Options... > Build & Run > Qt Versions. Assert that
there is a Qt version detected in your repository directory, by adding the qmake executable found 
at `<RepositoryRoot>\qtbase\bin\qmake.exe`.

Then go to the Compilers tab, and add MinGW32 if it was not detected by Qt Creator already. 

Next, go to the Kits tab, and add a Kit with the following settings:

    Name:        Desktop Qt 5.3.2 MinGW 32-bit
    Device type: Desktop
    Device:      Local PC (default for Desktop)
    Sysroot:     <empty>
    Compiler:    MinGW 4.8 32bit (or another version, but at least MinGW)
    Debugger:    None (or optionally add "gdb.exe" from your MinGW installation to Debuggers)
    Qt version:  Qt 5.3.2
    Qt mkspec:   <empty>

Most settings will be correct already, aside from the compiler and Qt version (if you have multiple).

When the Kit is added, open src\PowerGrid.pro from the PowerGrid repository, and build a release 
version using the Kit you added (after following the build instructions in the BuildInstructions.md
file). The build should pass. You can verify everything is working by going into the 'dist' directory 
with Windows Explorer and double-click PowerGrid.exe: This should start PowerGrid and load the 
Runescape client.

