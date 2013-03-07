TODO-list
=========

### PowerGrid maintenance ###
*Currently working on it: 
  - Chronio (Checking JavaDoc, refactoring static code and creating tests for each class)*

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

*Jobs*
  - powergrid.control.uicontrols package is hard-to-read and does not meet its purpose at all.
    - create a more general representation of the RS user interface.
    - possibly refer to API for implementation details in lower-level RSBot code.
      - This reduces the chance of code-breaking changes from RSBot
      - This is generally faster
    - 
  - XMLToolBox needs to be checked for style errors and needs to be tested in various situations.

### PowerGrid feature implementations ###

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
  - Optionally create:
    - Listener classes and a monitor class for various RSBot states and settings.
      - Allows for passive waiting
      - Easier than wait-in-loop and also more light-weight
      - prevents additional Threads that wait in loops
    - 