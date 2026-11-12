
# FSM of a Microwave

A Finite State Machine (FSM) is a mathematical model used by programmers, mathematicians, engineers, and other professionals to describe systems with a finite number of states.

A finite state machine for a microwave has a limited number of states representing the different actions and operating modes of the device. Transitions between these states are triggered by specific inputs or events.

In this project, I developed a command-line microwave simulator using the **C programming language**. The simulation uses two binary inputs (door and timer) and three operating states.

The first state **(00)** represents the microwave door being open. The second state **(01)** represents the microwave door being closed without cooking. The third state **(10)** represents the microwave cooking with the door closed and the timer started.

This project was originally developed as a first-semester university assignment in 2023 and later revisited to improve its functionality, input validation, and state transitions.

## Features

- Interactive command-line interface (CLI)
- Three operating states using Finite State Machine logic
- Door and timer controls using binary inputs
- ASCII-art microwave visualization
- Three-second cooking countdown
- Automatic return to the Door Closed state after cooking
- Input validation for invalid numbers and nonnumeric characters
- Graceful program termination using `-1`

## States

1. **Door Open (00)** — The microwave door is open, and cooking cannot begin.
2. **Door Closed (01)** — The microwave door is closed and ready to start cooking.
3. **Cooking (10)** — The microwave performs its cooking countdown.

## Inputs

The simulation uses two binary inputs:

1. **D (0/1)** = Door Open (0) / Door Closed (1)
2. **T (0/1)** = Timer Stopped (0) / Timer Started (1)

The application also accepts `-1` at either input prompt to terminate the simulation.

## FSM Diagram

The following diagram illustrates the three operating states and their transitions in the revised microwave simulation.

![Microwave FSM Diagram](img/fsm_diagram.png)

The microwave must first enter the Door Closed state before cooking can begin. After the cooking countdown finishes, the application automatically returns to the Door Closed state.

## State Transitions

| Current State | Input / Event | Next State |
|---|---|---|
| Door Open (00) | D = 0 | Door Open (00) |
| Door Open (00) | D = 1 | Door Closed (01) |
| Door Closed (01) | D = 0 | Door Open (00) |
| Door Closed (01) | D = 1, T = 0 | Door Closed (01) |
| Door Closed (01) | D = 1, T = 1 | Cooking (10) |
| Cooking (10) | Countdown completed | Door Closed (01) |

During the cooking countdown, the application does not accept additional inputs. Once the countdown finishes, it automatically returns to the Door Closed state.

## Truth Table

The truth table represents the current state bits (`s0`, `s1`), door input (`D`), timer input (`T`), next-state bits (`S0`, `S1`), and cooking output (`M`).

![Microwave FSM Truth Table](img/truth_table.png)

The table covers the three valid operating states and their binary input combinations.

## Karnaugh Maps

Karnaugh maps illustrate the Boolean representation of the FSM's next-state and output functions.

The maps are based on the three valid operating states: Door Open (00), Door Closed (01), and Cooking (10).

![Microwave FSM Karnaugh Maps](img/kmap_fsm.png)

The unused state (11) is represented using don't-care values (`X`) for Boolean simplification. The revised C implementation uses conditional statements to implement the transitions.

## Visualization

The application uses ASCII art to represent the microwave and display its operating state directly in the terminal.

### First State — Door Open (00)

![Door Open](img/door_opened.png)

This image shows the starting state, where the microwave door is open and cooking has not started.

### Second State — Door Closed (01)

![Door Closed](img/door_closed.png)

This image shows the second state, where the microwave door is closed but cooking has not started.

### Third State — Cooking (10)

![Cooking](img/cooking.png)

This image demonstrates the three-second cooking countdown and the automatic return to the Door Closed state after cooking completes.

### Program Termination

![Program Termination](img/program_terminated.png)

The simulation can be terminated by entering `-1` at any input prompt.

## How to Run

### Requirements

- GCC compiler
- Terminal or command prompt
- A compatible C development environment, such as MSYS2 UCRT64 on Windows

### Step 1 — Clone the Repository

```bash
git clone https://github.com/titoditomartin/fsm-improved.git
cd fsm-improved
```

Alternatively, download the repository as a ZIP file and extract it.

### Step 2 — Compile the Program

Compile the FSM library:

```bash
gcc -c mylib/mylib.c -o mylib.o
```

Compile the main application:

```bash
gcc main.c mylib.o -o main.exe
```

### Step 3 — Run the Program

On Windows:

```bash
./main.exe
```

### How to Use

1. Enter `0` or `1` to control the microwave door.
2. Enter `0` or `1` to stop or start the timer.
3. Close the door before starting the cooking process.
4. When cooking begins, the microwave counts down from 3 to 1.
5. After cooking completes, the microwave automatically returns to the Door Closed state.
6. Enter `-1` at any input prompt to exit the simulation.

Invalid inputs are rejected, and the application prompts the user to enter a valid value.

## Project Structure

```text
fsm-improved/
├── img/
│   ├── cooking.png
│   ├── door_closed.png
│   ├── door_opened.png
│   ├── fsm_diagram.png
│   ├── kmap_fsm.png
│   ├── program_terminated.png
│   └── truth_table.png
├── mylib/
│   ├── mylib.c
│   └── mylib.h
├── .gitignore
├── Makefile
├── README.md
└── main.c
```

### Main Components

- **main.c** — Handles user input, ASCII-art visualization, cooking countdown, and application flow.
- **mylib/mylib.c** — Contains the finite state machine transition logic.
- **mylib/mylib.h** — Declares the FSM function.
- **Makefile** — Provides build configuration for the project.
- **img/** — Contains the FSM documentation and application screenshots.

## Improvements

This project was originally developed in 2023 as a first-semester university assignment.

In 2026, I revisited the project to improve its reliability and usability while preserving the original command-line microwave simulation concept.

The improvements include:

- Corrected state-transition behavior
- Improved validation for numeric and nonnumeric inputs
- Automatic return to the Door Closed state after cooking
- Graceful program termination
- Improved code readability
- Updated technical documentation

The original academic implementation, including its initial Boolean equations and supporting documentation, is preserved in a separate repository.

**Original Repository:** [fsm](https://github.com/titoditomartin/fsm)

## Technologies and Concepts

- **Programming Language:** C
- **Compiler:** GCC
- **Interface:** Command-Line Interface (CLI)
- **Build Tool:** Make
- **Concepts:** Finite State Machines, State Transitions, Boolean Logic, Input Validation, and ASCII Art
