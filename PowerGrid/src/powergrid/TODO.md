TODO-list
=========

### PowerGrid maintenance ###
Recheck code for errors, problems, things that could be faster, greater, smaller, 
easier, or just generally better.

*Currently working on it*
  - Chronio (Checking JavaDoc, refactoring static code into objects and creating 
    tests for each class)

*Jobs*
  - Clean up code
    - Revalidate comments and add comments where appropriate
    - Refactor "smelly" code and hard-to-read code
    - Recheck and rewrite JavaDoc
    - Check for dead code and bad weather conditions (asserts)
  - Rewrite interact package to new format (using the Factory)
  - Create JUnit tests for classes
    - Use Mockito where it is useful

### PowerGrid issues, bad design and problems ###
Think about solutions to the following parts in PowerGrid that didn't work out 
the way they should.

*Jobs*
  - powergrid.control.uicontrols package is hard-to-read and does not meet its purpose at all.
    - create a more general representation of the RS user interface.
    - possibly refer to API for implementation details in lower-level RSBot code.
      - This reduces the chance of code-breaking changes from RSBot
      - This is generally faster (RSBot API is highly inefficient)
  - XMLToolBox needs to be checked for style errors and needs to be tested in various situations.
  - Redesign MapViewer, since many things in there are broken due to changes elsewhere
  - Check and actually DO all "TODO" and "FIXME" action items.
  - Why is Door.isOpen() deprecated? Move stateIsOpen() -> isOpen(). It has the same signature.

### PowerGrid feature implementations ###
Think about solutions for potential problems and implement these following 
principles of good software design.

*Jobs*
  - Make sure there is/are:
    - Working interactions using handle method (also ensure that the InteractionHandler can load them)
    - a Fully working GUI 
      - Plugin/Script loading options
      - PowerGrid status display with Task Queue controls (order, add, remove, ...)
    - Working dynamic path finding 
      - with interaction checking for all interaction types
    - Maintainable API for Plugin developers
      - using asserts
      - update / create JavaDoc continuously to match specifications
    - Listener classes and a monitor class for various RSBot states and settings.
      - Allows for passive waiting
      - Easier than wait-in-loop and also more light-weight
      - prevents additional Threads that wait in loops
