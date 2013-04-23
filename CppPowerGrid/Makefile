
# The compiler to use
CMP = g++

# Reference the OS type here. your JDK's include directory should contain a 
# folder with this name.
OS = darwin

# The Java home directory
JAVA_HOME = /Library/Java/JavaVirtualMachines/jdk1.7.0_17.jdk/Contents/Home

# reference to the Java library here
FRAMEWORKS = JavaVM

# add the library dependancies here
LIBS = -lcurl -lcurlpp

# Add all required object files here
OBJECTS = Launcher.o reflect/JavaEnv.o
SUBDIRS = . reflect

# Do not edit below here
CFLAGS = -g -02 -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/$(OS)
LFLAGS = -g -02 $(LIBS) -framework $(FRAMEWORKS)

powergrid: $(OBJECTS)
	$(CMP) $(LFLAGS) $(OBJECTS) -o powergrid

.recurse: $(SUBDIRS)
	for i in $(SUBDIRS); do make $i || break; done

%.o: %.cpp
	$(CMP) $(CFLAGS) -c $<