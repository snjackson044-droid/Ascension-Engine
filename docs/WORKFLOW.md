# ASCENSION — Workflow

ASCENSION ENGINE is a standalone C++ console program: the Awareness,
Observation and Reflection System, v1.0.0.

Directive: "Increase awareness through interaction, observation,
questioning, examination, and reflection."

Principle: "Unvalidated information must not be treated as validated."

## Systems

- Observation Engine — examines input (character / word count, examination points)
- Self-Observation — examines the process of your own thinking
- Question Engine — structures a question for investigation
- Reflection Engine — reflects on a subject, saves reflections to memory
- Perspective Engine — dual perspective examination
- Mathematics Engine — add, subtract, multiply, divide, power
- Memory System — persistent storage in `ascension_memory.txt`, with search
- Event Logger — persistent log in `ascension_events.txt`
- Session Metrics — activity counts (observations, questions, reflections,
  examinations, conversations, calculations). These are activity counts,
  not a measurement of consciousness or actual awareness.

## Build

```sh
g++ -std=c++17 -Wall -Wextra -o ascension ascension.cpp
./ascension
```

Menu: 1 Conversation, 2 Observation, 3 Self-Observation,
4 Question Analysis, 5 Reflection, 6 Dual Perspective,
7 Mathematics, 8 Store Memory, 9 View Memory, 10 Search Memory,
11 Session Metrics, 12 Event History, 0 Shutdown.

## Checks

Local check (mirrors the GitHub workflow):

```sh
sh scripts/ascension-check.sh
```

It compiles with the same flags and runs three smoke tests:
startup/shutdown, observation of "hello world test" (16 characters,
3 words), and math 3 * 4 = 12.

## GitHub workflow

`.github/workflows/ascension.yml` runs on pushes and pull requests
to `main` that touch `ascension.cpp`, `scripts/ascension-check.sh`,
or the workflow file itself. It compiles and runs the same three
smoke tests.
