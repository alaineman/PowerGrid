TODO-list
=========

[c] means that the list item is a class name that has to be implemented
[m] means that the list item is a method name that has to be implemented
[i] means that the list item is a interface name that has to be implemented

general
-------
- Add JavaDoc comments to public methods that don't have it.
- write documentation for other script writers about the top-level methods of powerwalk

powerwalk.model
---------------
- Collect raw values for GameObject subclasses (->VINCENT)
- Make subclasses of GameObject that represent objects in the RSBot environment. 
    - [c] Gate
    - [c] Ladder
    - [c] Stairs
    - [c] Hatch
    - [c] Rope

- Interactions and Teleports (->VINCENT)
    - [c] Boat
    - [c] ... (other Teleportables)

powerwalk.control
-----------------
- [c] WidgetManager
    -[m] openQuestWidget()
    -[m] openNoticeboard()
    -[m] openXXX() .... etc

powerwalk.data
--------------
- Determine locations of banks, shops, and depositboxes and store them in 
  specialLocations.xml. Then it can be implemented and tested.

powerwalk.view
--------------
- Embed more functionality from the Bot class (->PATRICK)
