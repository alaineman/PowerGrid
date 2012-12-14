TODO-list
=========

powerwalk.model
-----------------
- voltooi GameObject en Collision (PATRICK: they grow as needed. Remove this item when you agree to this)
- maak subklassen van GameObject die objecten in de RSBot environment representeren.
    - Wall (PATRICK: implemented, but still have to fetch more wall values)
    - Entity (PATRICK: same as Wall)
    - Door (PATRICK: began working on interaction, but I'm unsure how to find out about the door's state in the RSBot environment)

powerwalk
---------
- maak entrypoint voor plugin
- laat de Bot-klasse methodes in de control package aanroepen

powerwalk.control
-----------------
- maak een PathFinder klasse (Vincent: nadenken over slimme algoritm die korste route vindt.)
- maak een Interactor klasse
- maak een Walker klasse (misschien mbv org.powerbot.game.api.methods.Walking)

powerwalk.view
--------------
- denk na over gui design (PATRICK: nu een conceptversie, powerwalk.view.MainFrame)
