![PowerGrid](http://80.57.59.56/styles/skymiles_red/imageset/site_logo.png)

PowerGrid is a revolutionary bot platform that aims to provide a more open approach to botting than other clients have shown so far. Being written in C++, PowerGrid also aims to provide a more fluent experience for end-users, and a generally faster and more dynamic programming language to work in.  

## PowerGrid functionality ##
PowerGrid offers a completely new travelling system that allows the user to walk to any location in the Runescape world, while also using available teleports and shortcuts to get to the destination in the fastest possible way.

It also provides a mechanism to check a variety of stats and settings without needing to navigate through widgets, PowerGrid automatically checks these when required, but caches the results so that consecutive calls are much faster. This is mainly required because PowerGrid uses JNI to interact with the Java environment, which is usually slower than interaction from within the Java environment, but the big advantage is that PowerGrid's further processing happens completely separate from the Java Virtual machine, being not only much faster, but also less detectable than executing similar code inside the JVM.

PowerGrid offers a full user interface to travel to any destination or location using either landmarks, special locations such as banks and stores, or even an actual world map, allowing the user to click any tile on the map, after which PowerGrid computes a route and executes it for maximum control.

PowerGrid is, unlike other bots, written in C++. While this causes a delay in transferring data from the Java environment to C++, the C++ functions themselves can be made much faster, and since most code will run outside the Java Virtual Machine, there is also less chance of the Runescape client detecting the bot. 

The loader itself is inspired by the official open-source loader for Runescape, also written in C++. Because of this, PowerGrid will appear to be a normal loader application, while in reality, PowerGrid monitors various settings, objects, and data structures to use for botting purposes.

## Using PowerGrid ##
PowerGrid comes with its own control frame that is separate from the main Runescape frame.  This is because the Runescape frame is in reality a Java frame, and PowerGrid's control frame is not.

Because of this feature, it is also possible to use PowerGrid to play Runescape normally, without PowerGrid getting in the way. Also, PowerGrid solely uses reflection to monitor the bot, which opens up more dynamic possibilities than when using injection. This is because Runescape's classes themselves are not modified, and this prevents many workarounds that other bot platforms have to make to get the injection to work.

## Legal notices ##
Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar

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
