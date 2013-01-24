TODO-list
=========

Below are the most direct TODO-items and their requirements. They are placed in 
order of importance, so it is advised to take on the top most action item that is 
not claimed by anyone (using [NAME]). [DONE] can be placed in front of achieved 
subgoals to indicate progress.

+--------Thoughts Box (Add stuff that you want to discuss here)----------------+
| Chronio: Maybe refactor 'powerwalk.control.noticeboard' somewhere else.      |
| Chronio: See 'Household work', point 3.                                      |
+------------------------------------------------------------------------------+

- Household work (I know: boring, but it has to happen, too)
    1. Clean up Git repo where possible
    2. (Re-)write documentation
        20. check / update Javadoc to match latest changes / features
        21. update the class tree file with info on all classes
        22. check / update README.md file.
    3. Decide on a global progressing plan regarding PW / PG 
        30. What about PowerWalk 2.0?
        31. When to release?
        32. Keep providing limited support for PowerWalk or not?
        33. What to expect from PowerWalk 2.0?
        34. What about PowerGrid?
        35. We're going to fast, consider 'undressing' before release as PowerWalk
        36. Keep 'awesome' features for PowerGrid or not?

- Test Lodestone for edge cases
    1. Lodestone will not be used for short-distance travels
    2. Lodestone will not be used when distance to final destination does not differ much
    3. Lodestones will always activate in other cases

- Enable dynamic Lodestone checking
    1. Enable when PathFinding and Lodestones are not yet checked.
    2. Assuming unlocked Lodestones do not change, do not recheck for each computed path.
    3. Read from cache when Lodestones have been checked already.

- Test interactions (stand-alone, without PathFinder)
    1. 'Simple' handlers
        10. WaterbirthIsle
        11. EntranaBoat
        12. IcebergBoat
        13. JatizsoBoat
        14. LunarIsleShip
        15. MiscellaniaShip
        16. MusaPointShip
        17. NeitiznotBoat
        18. PiratesCove
        19. ShiloCart
    2. Manifold handlers
        20. Canoe
        21. CharterShip
        22. FairyRing
        23. GnomeGlider
        24. HotAirBalloon
        25. MagicCarpet
        26. Minecart
        27. SpiritTree
    3. Doors and Gateways (priority)
        30. Door
        31. Gate
        32. Portal
        33. Shortcuts

- Extend PathFinder with interactions
    1. Door
    2. Gate
    3. Shortcuts
    4. ... (others)

- Make 'TravelToNearest' command and test it
    1. Method always travels to nearest destination (including Teleports)
    2. Method allows for filter of params (specific ore type, for example) and choose destination accordingly
    3. Method is location independant (involves having specialLocation data in environment)

- Gadgets, Details, Cool stuff and more...
    1. Have a 'thoughts' balloon for PowerWalk, allowing the end-user to 'peek' into PowerWalk's decisions.
        10. This allows for ad-hoc decision-making without end-users going nuts due to PowerWalk doing 'weird' things.
        11. It's easier to debug tasks when you know what PowerWalk's up to.
        12. It would provide the idea that PowerWalk works as an actual player and therefore enhance the awsomeness of PowerWalk.
    2. Add (more) cool and would-be-awesome ideas to this list.
