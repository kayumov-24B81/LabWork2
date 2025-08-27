### Software Requirements Specifications for Laboratory Work №2

### 1.Introduction
#### 1.1. Purpose
    
This Software Requirements Specification (SRS) document defines the functional and non-functional requirements for the console game "L2". This document is intended for use by the professor as the primary source of information regarding what the system must do. This document does not define how (the technical methods) the requirements shall be implemented.

#### 1.2. Scope

The product "L2" is a turn-based console RPG game for a single player. The core gameplay involves controlling a character, battling auto-generated enemy, and tactically using temporary effects that modify characteristics and various actions.

Out of Scope:
- Implementation of a Graphical User Interface (GUI).
- Network or multiplayer mode.
- Game progress save/load system.
- Level or character editor.

#### 1.3. Definitions, Acronyms, and Abbreviations

- Entity - a base game object possessing characteristics. E.g., a player or an enemy.
- Characteristics - numerical attributes of an entity, such as Health, Armor, Damage.
- Effect - a temporary modification of one or more characteristics of an entity. Has a limited duration (e.g., 3 turns).
- Enemy Preset - a predefined set of characteristics used to generate similar enemies.
- Weapon - an item that can be equipped by an entity. It provides a static modifier to the entity's damage and may possess proc-based effects that trigger on certain actions.
- Proc Effect - an effect that has a chance to be applied upon a specific action or event (e.g., "on hit").

#### 1.4 Document Overview

This document is structured as follows:

- Section 1 (Introduction) — Provides overall context, goals, and definitions used in the document.
- Section 2 (Overall Description) — Describes the product in general, its functions, users, and constraints.
- Section 3 (Specific Requirements) — Contains all functional and non-functional requirements presented in a detailed and verifiable manner.

### 2. Overall Description

#### 2.1. Product Perspective

The product is a standalone console application (CLI) operating in a standard operating system terminal. User interaction with the system is performed exclusively by entering text commands from the keyboard and receiving text-based reports on the game state as output. A graphical interface is absent.

#### 2.2. Product Functions (Summary)

- **Character Management**: The system shall provide the user with the ability to control the actions of a player character (attack, defend, use special abilities).
- **Enemy Generation**: The system shall automatically create and manage enemies with random characteristics based on given presets.
- **Effect System**: The system shall provide a mechanism for temporarily modifying entity characteristics (both player and enemies) through applicable effects (e.g., damage increase, defense reduction).
- **Weapon System**: The system shall provide a mechanism for entities to wield weapons. Weapons shall modify the wielder's characteristics and may apply additional effects upon certain actions (e.g., on attack).
- **Combat Management**: The system shall implement turn-based combat, process interactions between entities, calculate damage, and determine the battle outcome.
- **Event Logging**: The system shall record all significant events (attacks, damage taken, effect application) in a structured form for subsequent display to the user.

#### 2.3. User Characteristics

The only user class of the system is the Player. It is assumed that the Player:
- Has basic command-line skills for the operating system.
- Is familiar with the game rules and available commands.
- Has no specific technical knowledge.

#### 2.4. Constraints

- The application must run on Ubuntu version 18.04 or higher operating system.
- The application does not require network access or a graphical server.
- Data input is performed only through the standard input stream (stdin).
- Data output is performed only through the standard output stream (stdout)

#### 2.5. Assumptions and Dependencies

- **Assumption**: The user will enter commands precisely according to the provided syntax. Handling erroneous input may be limited.
- **Dependency**: Building the project requires a g++ compiler.
- **Dependency**: The program depends on the Standard Template Library (STL) and does not require third-party libraries.

### 3. Specific Requirements

#### 3.1. Functional Requirements

##### 3.1.1. Gameplay Requirements

- The system shall provide the user with the ability to enter the `attack`, `guard` and `empower` commands.
- Upon receiving the attack command, the system shall calculate damage taking into account enemy defense in case opponent chooses `guard` option.
- 'damage' shall be randomized.
- The system shall decrease the target's health value by the calculated `damage` value.
- If an entity's health value becomes ≤ 0 after an attack, the system shall decide winner and end the game at the end of the turn.

##### 3.1.2. Effect System Requirements

- The system shall provide a mechanism for creating effects that modify entity characteristics .
- Each effect must have a 'duration' field defining the number of turns for which the effect is active.
- The system shall automatically decrease the `duration` value of each active effect by 1 at the end of the turn of the entity to which it is applied.
- When an effect's `duration` value reaches 0, the system shall automatically cancel the effect's action (revert the modified characteristic to its original value) and remove it from the entity's list of active effects.

##### 3.1.3. Enemy Generation Requirements

- The system shall create enemy instances based on predefined presets (e.g., "Knight", "Goblin").
- An enemy preset shall unambiguously define its base characteristics: `health`, `damage`, `armor`.
- The system shall provide a method for retrieving a random preset from a given list.

##### 3.1.4. Logging Requirements

- The system shall log the result of each attack, including the attacker's identifier, the target's identifier, and the damage dealt.
- The system shall log the fact of application and removal of each effect, including its type and target.

##### 3.1.5. Combat Resolution Requirements

###### 3.1.5.1. Combat Flow

- The system shall resolve the interaction between the Player and the Enemy each turn based on their chosen actions (`attack`, `guard`, `empower`).
- The resolution order shall be: Action Resolution -> Effect Updates.

###### 3.1.5.2. Action Resolution Rules

The system shall resolve actions according to the following decision matrix:

### **Action Resolution Decision Matrix**

| Player Action | Enemy Action | System Behavior & Event Logging |
| :--- | :--- | :--- |
| **ATTACK** | **ATTACK** | **Behavior:** Calculate damage for both entities. The target for each attack is chosen randomly (50% chance for each).<br>**Logging:** An attack event shall be logged for both entities. |
| **GUARD** | **GUARD** | **Behavior:** Apply a defensive state to both entities for the duration of this turn, reducing incoming damage.<br>**Logging:** A guard event shall be logged for both entities. |
| **EMPOWER** | **EMPOWER** | **Behavior:** Apply an empowered state to both entities for the duration of this turn, enhancing their characteristics.<br>**Logging:** An empower event shall be logged for both entities. |
| **ATTACK** | **GUARD** | **Behavior:** The attacking entity attacks. The guarding entity has a 50% chance to perform a successful counterattack.<br>**Logging:** An attack event shall be logged. A guard event shall be logged, indicating success or failure of the counterattack. |
| **GUARD** | **ATTACK** | **Behavior:** IThe attacking entity attacks. The guarding entity has a 50% chance to perform a successful counterattack.<br>**Logging:** An attack event shall be logged. A guard event shall be logged, indicating success or failure of the counterattack. |
| **ATTACK** | **EMPOWER** | **Behavior:** IThe attacking entity always deals damage. The empowering entity has a 50% chance to successfully complete its empowerment action before being attacked.<br>**Logging:** An attack event shall be logged. An empower event shall be logged, indicating success or failure of the empowerment. |
| **EMPOWER** | **ATTACK** | **Behavior:** The attacking entity always deals damage. The empowering entity has a 50% chance to successfully complete its empowerment action before being attacked.<br>**Logging:** A guard event and an empower event shall be logged. |
| **GUARD** | **EMPOWER** | **Behavior:** The guarding entity enters a defensive state. The empowering entity enters an empowered state.<br>**Logging:** A guard event and an empower event shall be logged. |
| **EMPOWER** | **GUARD** | **Behavior:** The empowering entity enters an empowered state. The guarding entity enters a defensive state.<br>**Logging:** An empower event and a guard event shall be logged. |

###### 3.1.5.3. Effect Processing

- After action resolution, the system shall process all active effects for both the Player and the Enemy.
- For each entity, the system shall check its list of effects waiting for application. For each effect in this list, the system shall log an update.
- The system shall then call update effects for each entity, which must apply new effects, update the duration of active ones, and remove expired effects.

###### 3.1.5.4. Logging Requirements for Combat

- The system shall reset the event log at the beginning of each turn's resolution sequence.
- The system shall create and add a corresponding event object to the log for every significant action and state change during combat resolution.
- All events shall capture the context of the action (e.g., the source and target entities).

##### 3.1.6. Weapon System Requirements

- The system shall provide a base structure for weapons that defines common characteristics and behavior.
- The system shall allow entities to equip a weapon.
- An equipped weapon shall modify the base characteristics of its wielder .
- A weapon shall have the ability to apply effects to a target upon a specific action.
- The system shall support the creation of specific weapon types that inherit from the base weapon structure and define their own modifiers and effect triggers.

#### 3.2. Non-Functional Requirements

##### 3.2.2. Usability Requirements
- The status of all active effects for the player and the current enemy must be explicitly displayed in the interface before a turn is taken.

##### 3.2.3. Reliability Requirements
- The application must not crash (with a `Segmentation Fault`, `Exception`, etc.) on any user input. Invalid input must be handled with an error message.

#### 3.3. Interface Requirements

##### 3.3.1. User Interfaces
- The interface shall be text-based and implemented via standard console input/output.
- The main game loop shall sequentially output:
    - The current game state (weapon, characteristics, name of entities).
    - The list of available commands.
    - An input prompt (`"> "`).
