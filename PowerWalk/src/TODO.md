TODO-list
=========

powerwalk.model
-----------------
- Grid-klasse maken en WorldMap en DungeonMap deze laten gebruiken << Grid contains arrays for each tile, indexed by depth (use offset due to neg. value)
- Offset fixen
- voltooi GameObject en Collision
- maak subklassen van GameObject die objecten in de RSBot environment representeren.
-- Wall
-- NPC (Entity)
-- Door
-- Interaction interface

powerwalk
---------
- maak entrypoint voor plugin
- maak een Bot-klasse die methodes in de control package aanroept

powerwalk.control
-----------------
- maak een PathFinder klasse
- maak een Interactor klasse
- maak een Walker klasse (mbv org.powerbot.game.api.methods.Walking)

powerwalk.view
--------------
- denk na over gui design