TODO-list
=========

powerwalk.model
---------------
- Make subclasses of GameObject that represent objects in the RSBot environment (low priority).
<<<<<<< HEAD

- powerwalk.model.world.resources
    - [c] MAYBE? : Farmpatches extends AbstractResource ????

- Interactions and Teleports (->VINCENT)
=======
    - class Gateway extends GameObject implements Interactable ("SSO" door)
    - class Gate extends Gateway (Is this required when Gateway pretty much covers this?)
    - class Ladder extends Elevator (Create and integrate in pahfinder AFTER teleportables)
    - class Stairs extends Elevator (@see Ladder)
    - class Hatch extends Elevator (@see Ladder)
    - class Rope extends Elevator (@see Ladder)

- powerwalk.model.world.resources (AFTER PathFinder - Interactable integration)
    - class Tree extends AbstractResource
    - class Ore extends AbstractResource
    - class FishingSpot extends AbstractResource
    - MAYBE: class Farmpatches extends AbstractResource

- Interactions and Teleports (-> VINCENT)
>>>>>>> origin/master
    - test each interaction, so that it always works.
    - transportable factory (-> PATRICK)

- Item manager (Inventory checking, ground items, etc...)

- Refactor Point.f_score to a HashMap in powerwalk.control.PathFinder, since 
  it's really only used there. (-> WHOEVER is doing teleportable integration, since he's messing with pathfinder anyway)

- Make the pathfinder compatible for teleportables, lodestones and transportables. Basic steps below:
    - Add all available teleports and lodestones at startup to "pending" queue.
    - Run A* as usual.
    - During path building / reducing, if two nodes are more than 15 tiles apart, consider then teleports, and add destination.
    - During execution, if two nodes are more than 15 tiles apart, consider them teleports, and retrieve correct type.
    - Use teleport with appropriate method and proceed as usual.

powerwalk.data
--------------
- Data toevoegen (-> EVERYONE)

