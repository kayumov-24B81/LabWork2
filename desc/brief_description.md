### General system description

#### Purpose
This system is turn-based RPG where the player fights generated enemy using a fixed set of actions

#### Key Functionalities
1. **Enemy Generation**: Enemies are dynamically generated using predefined presets.
2. **Player Actions**: The player can choose to attack, defend, or empower their character.
3. **Action Interactions**: Unique effects occur based on combinations of player and enemy actions.
4. **Randomness Factor**: Damage calculations and interaction outcomes are influenced by random number generation (RNG).
5. **Turn Notifications**: At the end of each turn, detailed information about character actions and status changes is displayed in the console.

#### Technology stack
- **Programming language**: C++ (with standard libraries)
- **Tools**:
 - Git for version control
 - GitHub Actions for continous integration
 - Doxygen for automated documentation generation

#### Limitations 
- The system works only on Linux
- The system is compatible only with g++ compiler
