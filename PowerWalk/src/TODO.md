TODO-list
=========

powerwalk.model
-----------------
- maak subklassen van GameObject die objecten in de RSBot environment representeren. (->PATRICK)
    - Item !!! (alle items)
    - TeleportItem extends Item implements Teleportable
    - Wall (PATRICK: implemented, but still have to fetch more wall values)
    - Entity (PATRICK: same as Wall)
    - Door (PATRICK: began working on interaction, but I'm unsure how to find out about the door's state in the RSBot environment)
    - Gate
    - (abstract class Elevator) => Ladder / Stairs / Hatch / Rope (climb up / climb down)

- Interactions and Teleports (->VINCENT)
    - ComplexInteractable extends Interactable
    - Teleportable extends ComplexInteractable
    - Teleportable.use()
    - other Teleports 
    - Lodestones
    - ... 

powerwalk.control
-----------------
- Mapper de World Map laten opslaan in XML

powerwalk.view
--------------
- denk na over gui design (PATRICK: nu een conceptversie, powerwalk.view.MainFrame)
