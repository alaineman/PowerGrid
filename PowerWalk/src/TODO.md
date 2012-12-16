TODO-list
=========

[c] means that the list item is a class name that has to be implemented
[m] means that the list item is a method name that has to be implemented
[i] means that the list item is a interface name that has to be implemented

general
-------
- Add JavaDoc comments to public methods that don't have it.
- Make a class Tree describing what each class does.
- Optional: write documentation for other script writers about the top-level methods of powerwalk

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
    - [c] ... (other Teleportables)

powerwalk.control
-----------------
- [m] Mapper.save() (->PATRICK)
- [m] Mapper.load() (->PATRICK)
- [c] WidgetManager
    -[m] openQuestWidget()
    -[m] openNoticeboard()
    -[m] openXXX() .... etc

powerwalk.view
--------------
- Fix destination list
- Allow "travel to" command for each destination
- Embed more functionality from the Bot class
