### UC-1: Initialize Game Session
#### Use Case ID: UC-1

#### Use Case Name: Initialize Game Session

### Actor: System

#### Trigger: The application is launched by the user.

#### Main Success Scenario:
1. System initializes the random number generator.
2. System creates Player and Enemy entities with default characteristics.
3. System equips both entities with weapons.
4. System initializes the User Interface subsystem and provides it with references to the game entities.
5. System initializes the Artificial Intelligence subsystem and sets its target.
6. System initializes the Interaction Manager subsystem with a Logger instance.
7. System randomizes the Enemy entity's characteristics based on predefined presets.
8. System sets the game state to RUNNING.
9. System displays the initial game state to the user.
10. Use Case ends successfully.

#### Alternate Flows:

#### A.1. Initialization Failure:
1. If any initialization step fails (e.g., memory allocation error), system captures the exception and displays an error message to the user.
2. System terminates the application with an error code.
3. Use Case ends with failure.

####Postconditions:
- All game subsystems are initialized and operational.
- Player and Enemy entities are created, configured, and ready for gameplay.
- Game state is set to RUNNING.
- Initial game state is displayed to the user.

### UC-2: Execute Game Loop
#### Use Case ID: UC-2

#### Use Case Name: Execute Game Loop

#### Actor: System

#### Trigger: Successful completion of UC-1 (Initialize Game Session).

#### Main Success Scenario:
1. System displays current game state in console.
2. System initiates UC-3 (Acquire Player Action) to get player's input.
3. System determines Enemy's action through Artificial Intelligence subsystem.
4. System displays updated game state.
5. System initiates UC-8 (Resolve Action Combination) to process actions.
6. System displays combat results and event log.
7. System initiates UC-10 (Check Game End Conditions).
8. If game continues, system prompts user to continue and repeats steps 1-7.
9. If game should end, system initiates UC-9 (Terminate Game Session).

#### Postconditions:
- Game loop continues until termination condition is met.
- Game state is updated each iteration.

### UC-3: Acquire Player Action
#### Use Case ID: UC-3

#### Use Case Name: Acquire Player Action

#### Actor: Player

#### Trigger: Game loop requires player input for next action.

#### Main Success Scenario:
1. System displays available action choices to the player.
2. Player inputs action choice (via text command or numeric equivalent).
3. System validates the input against available actions.
4. System sets the player's action to the chosen value.
5. Use Case ends successfully.

#### Alternate Flows:

#### A.1. Invalid Input:
1. If player input doesn't match any valid action, system displays error message and list of valid actions.
2. System prompts for input again.
3. Flow returns to step 2 of Main Success Scenario.

#### Postconditions:
- Player's action is set and ready for processing.
- Input validation is complete.

### UC-4: Execute Attack
#### Use Case ID: UC-4

#### Use Case Name: Execute Attack

#### Actor: Player

#### Main Success Scenario:
1. Player inputs the attack command.
3. System registers the attack intention (sets Player's current action to attack).
4. System transfers control to UC-8 (Resolve Action Combination) to determine the outcome of the attack based on the target's state and action.
5. Use Case ends.

#### Postconditions:
- The attack is registered as current action.
- Control is passed to the action resolution system (UC-8).

### UC-5: Activate Guard
#### Use Case ID: UC-5

#### Use Case Name: Activate Guard

#### Actor: Player

#### Main Success Scenario:
1. Player inputs the guard command.
2. System registers the attack intention (sets Player's current action to attack).
3. System transfers control to UC-8 (Resolve Action Combination) to determine the outcome of the guard based on the target's state and action.
4. Use Case ends.

#### Postconditions:
- The guard is registered as current action.
- Control is passed to the action resolution system (UC-8).

### UC-6: Activate Empower
#### Use Case ID: UC-6

#### Use Case Name: Activate Empower

#### Actor: Player

#### Main Success Scenario:
1. Player inputs the empower command.
2. System registers the empower intention (sets Player's current action to attack).
3. System transfers control to UC-8 (Resolve Action Combination) to determine the outcome of the empowering based on the target's state and action.
4. Use Case ends.

#### Postconditions:
- The empower is registered as current action.
- Control is passed to the action resolution system (UC-8).

### UC-7: Process Effects
#### Use Case ID: UC-7

#### Use Case Name: Process Effects

#### Actor: System

#### Trigger: The end of an entity's turn or the action resolution phase.

#### Main Success Scenario:

1. For each active entity the system applies the effect imposed in the current turn (overrides duration if needed).
2. System registers an EffectEvent for each effect that is applied.
3. For each active entity, system checks its list of active effects.
4. For each effect, system decreases its duration by 1.
5. If an effect's duration reaches 0, the system cancels its modifications and removes it from the entity's active effects list.
6. Use Case ends.

#### Postconditions:
- Effects imposed in current turn are applied.
- Effect durations are updated.
- Expired effects are removed.
- Effect events are logged.

### UC-8: Resolve Action Combination
#### Use Case ID: UC-8

#### Use Case Name: Resolve Action Combination

#### Actor: System

#### Trigger: Two entities have chosen their actions for the turn (e.g., Player and Enemy).

#### Main Success Scenario:
1. System identifies the chosen actions for both entities.
2. System consults the Action Resolution Matrix to determine the appropriate interaction logic.
3. System executes the sequence of actions corresponding to the action pair.
4. System registers all relevant events (e.g. actions and changes in state of entities).
6. System initiates UC-7 (Process Effects) to update effect states.
7. Use Case ends.

#### Postconditions:
- Entity states are updated based on action outcomes.
- All combat events are logged.
- Effects are processed.

### UC-9: Terminate Game Session
#### Use Case ID: UC-9

#### Use Case Name: Terminate Game Session

#### Actor: Player

#### Main Success Scenario:
1. Player decides to terminate the game session.
2. Player initiates the "Terminate Game" action via a system-provided mechanism.
3. System confirms the user's intention to terminate.
4. System gracefully stops all game processes.
5. System releases all allocated resources.
6. Use Case ends.

#### Alternate Flows:
####B.1. Termination upon Victory Condition:

#### Trigger: System detects victory condition (e.g., enemy health ≤ 0).
1. System stops gameplay.
2. System displays victory message.
3. Flow continues from step 4 of Main Success Scenario.

#### B.2. Termination upon Failure Condition:

#### Trigger: System detects failure condition (e.g., player health ≤ 0).
1. System stops gameplay.
2. System displays failure message.
3. Flow continues from step 4 of Main Success Scenario.

#### Postconditions:
1. Game session is terminated.
2. All system resources are released.
