TODO-list
=========

Below are the most direct TODO-items and their requirements. They are placed in 
order of importance, so it is advised to take on the top most action item that is 
not claimed by anyone (using [NAME]). [DONE] can be placed in front of achieved 
subgoals to indicate progress.

### PowerGrid maintenance ###
  - Clean up code
    - Revalidate comments and add comments where appropriate
    - Refactor "smelly" code and hard-to-read code
    - Recheck and rewrite JavaDoc
    - Check for dead code and bad weather conditions
    - Possibly: Checkstyle validate all code
  - Rewrite interact package to new format (using the Factory)
  - Create JUnit tests for classes where appropriate
    - Possibly use Mockito

### PowerGrid feature implementations ###
  - Make sure there is/are:
    - Working interactions using handle method
    - a Mapper that maps the environment to a bitset representation instead of the current mapping
    - a Fully working GUI with Plugin/Script loading options
    - Working dynamic path finding with interaction checking
    - Maintainable API for Plugin developers