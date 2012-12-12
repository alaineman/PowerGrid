TODO-list
=========

powerwalk.model
-----------------
- voltooi GameObject en Collision (PATRICK: they grow as needed. Remove this item when you agree to this)
- maak subklassen van GameObject die objecten in de RSBot environment representeren.
    - Wall (PATRICK: implemented, but waiting for RSBot client patch in order to retrieve wall values)
    - Entity (PATRICK: same as Wall)
    - Door (PATRICK: only have to work out how to interact with objects in the RSBot environment)

powerwalk
---------
- maak entrypoint voor plugin
- maak een Bot-klasse die methodes in de control package aanroept

powerwalk.control
-----------------
- maak een PathFinder klasse
- maak een Interactor klasse
- maak een Walker klasse (misschien mbv org.powerbot.game.api.methods.Walking)

powerwalk.view
--------------
- denk na over gui design (PATRICK: nu een conceptversie, powerwalk.view.MainFrame)