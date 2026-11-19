#!/bin/sh
# Local check for ASCENSION — mirrors .github/workflows/ascension.yml.
# Usage: sh scripts/ascension-check.sh
# Compiles ascension.cpp with the same flags as the workflow, then runs
# the same three smoke tests. Exits non-zero on the first failure.
# The program writes ascension_events.txt / ascension_memory.txt at
# runtime, so the smoke tests run in a temp directory to keep the repo clean.
set -eu

cd "$(dirname "$0")/.."

echo "Compiling ascension.cpp..."
g++ -std=c++17 -Wall -Wextra -o /tmp/ascension_check ascension.cpp
echo "Compile OK."

RUN_DIR=$(mktemp -d /tmp/ascension_check_run.XXXXXX)
trap 'rm -rf "$RUN_DIR" /tmp/ascension_check' EXIT
cd "$RUN_DIR"

echo "Smoke test 1: start up and shut down..."
output=$(printf '0\n' | /tmp/ascension_check)
echo "$output" | grep -q "ASCENSION ENGINE"
echo "$output" | grep -q "Observation Engine: ONLINE"
echo "$output" | grep -q "Initialization complete."
echo "$output" | grep -q "ASCENSION ENGINE TERMINATED."
echo "Smoke test 1 OK."

echo "Smoke test 2: Observation (hello world test)..."
output=$(printf '2\nhello world test\n0\n' | /tmp/ascension_check)
echo "$output" | grep -q "Character count: 16"
echo "$output" | grep -q "Word count: 3"
echo "$output" | grep -q "Observation complete."
echo "Smoke test 2 OK."

echo "Smoke test 3: Mathematics Engine (3 * 4)..."
output=$(printf '7\n3\n*\n4\n0\n' | /tmp/ascension_check)
echo "$output" | grep -q "Result: 12"
echo "Smoke test 3 OK."

echo "All ASCENSION checks passed."
