Powerwalk
=========

Introduction
------------
PowerWalk is a walking plug-in for RSBot. It aims to completely replace the current RSBot Walking facility by embedding functionality that would allow the user to select any destination in the RS world, after which PowerWalk would compute the shortest path to that destination and walk there, using all available shortcuts and teleports in the process. 

This is a huge improvement over the existing Walking facility, which does not allow for such complex tasks. The current Walking facility only allows for travelling small distances at a time, does not look at teleports or shortcuts, and also does not check whether running could be enabled to speed up the travel.

PowerWalk is designed both for end-users and scripters: End-users can use the Graphical user interface to easily select a destination to travel to, while scripters can use PowerWalk's travel methods to travel between places more efficiently.

As for now, PowerWalk still uses the RSBot Walking facility at its core. However, most of PowerWalk works independantly from RSBot, and as such is highly resistant against code-breaking changes in RSBot.

Powerwalk can also be used by multiple scripts, without needing a clone of PowerWalk along with every script that uses it. This is an important matter, because PowerWalk is quite a robust facility, which could slow down the RSBot client a bit on older or slower machines. Having multiple instances of PowerWalk could decrease the performance of the scripts running on top of PowerWalk, so reducing this redundancy is a useful addition to PowerWalk. It also allows for PowerWalk map data gathered in one session to be carried over to the other, regardless of what script is running.

Another reason for placing PowerWalk outside of all other scripts, is that updates and fixes for PowerWalk can be released, without requiring the users to wait for updates for each individual script that uses it. Instead, users can update PowerWalk itself, and the fixes and changes made will be available to all scripts automatically. After that, scripters can update their scripts to newer versions at their own leisure, without worrying about checking whether they are using the latest PowerWalk version all the time. This is also convenient when unexpected bugs occur in PowerWalk, since these bugs can be fixed without requiring all scripters to release new versions again because of those bugs.

Current functionality
---------------------
- The Bot can find paths between two points.
- The Bot is able to follow paths it computed.
- The Bot remembers the environment and uses that information to get around walls and objects
- The Bot is able to use Lodestones to minimize the required walking distance

First upcoming functionality
----------------------------
The Bot is able to use (simple) interactions that will help the bot to find more efficient paths between points.

Long-term planning
------------------
Eventually, the bot will be able to move around freely over the World Map, 
can use interactions, and can compute and follow paths from one point to another.
