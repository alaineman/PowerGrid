![PowerGrid](http://powergrid-client.net/styles/skymiles_red/imageset/site_logo.png)

PowerGrid is a revolutionary bot platform that aims to provide a more open approach to botting than other clients have shown so far. Being written in C++, PowerGrid also aims to provide a more fluent experience for end-users, and a generally faster and more dynamic programming language to work in.  

## PowerGrid functionality ##
PowerGrid aims to surpass current Runescape bots by revolutionizing the way it deals with its extensions. Where traditional bot clients focus on the botting aspect and work through executing scripts, PowerGrid works in a completely different way: PowerGrid makes use of the provided extensions to improve the tasks it performs. For example, a plugin developer would write an extension to PowerGrid for interacting with a transportation system called "fairy rings" in the Runescape world. This plugin can be loaded by PowerGrid, and the PowerGrid AI can then use the extended functionality to find shorter paths across the world. Such extensions can be created for not only travelling, but also for training virtually all skills.

PowerGrid is, unlike other bots, written in C++. While this causes a delay in transferring data from the Java environment to C++, the C++ functions themselves can be made much faster, and since most code will run outside the Java Virtual Machine, there is also less chance of the Runescape client detecting the bot. 

The loader itself is inspired by the official open-source loader for Runescape, also written in C++. Because of this, PowerGrid will appear to be a normal loader application, while in reality, PowerGrid monitors various settings, objects, and data structures to use for botting purposes.

## Building PowerGrid ##
PowerGrid depends on Qt 5.1 (or higher) and Java (a JDK is required for building).
For complete instructions on how to build PowerGrid, please refer to 
“doc/BuildInstructions.md”

## Using PowerGrid ##
PowerGrid comes with its own control frame that is separate from the main Runescape frame.  This is because the Runescape frame is in reality a Java frame, and PowerGrid's control frame is not.

Because of this feature, it is also possible to use PowerGrid to play Runescape normally, without PowerGrid getting in the way. Also, PowerGrid solely uses reflection to monitor the bot, which opens up more dynamic possibilities than when using injection. This is because Runescape's classes themselves are not modified, and this prevents many workarounds that other bot platforms have to make to get the injection to work.

## Legal notices ##
We believe in the power of free software, and as such we decided to make the entire bot open-source, including the core, api, and applet loader. We believe that together with everyone we can continue to improve PowerGrid, and meet the expectations of our users. Therefore, we licensed PowerGrid under the GNU GPL version 3, so that everyone may use it and modify it as they want.

The license information that applies to PowerGrid (the GNU GPL v3) is mentioned below:

Copyright 2014 Patrick Kramer, Vincent Wassenaar

PowerGrid is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

PowerGrid is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

The GNU General Public License (version 3) can be found in the file 
called 'COPYING' in the root of the PowerGrid repository. It can 
also be found at http://www.gnu.org/licenses.

### External code and libraries ###

To certain parts of the source, another license applies than the 
GNU General Public License. These parts are mentioned here, along 
with the appropriate license.

#### JACE ####
PowerGrid makes use of a modified version of JACE, a wrapper around the JNI to make it
easier (and more intuitive) to communicate between Java and C++. The following license 
applies:

Copyright (c) 2002, Toby Reyelts
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
Neither the name of Toby Reyelts nor the names of his contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
