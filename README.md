# Monty Program

Monty is an interpreter for a custom stack-based programming language. It reads Monty bytecode files containing commands and executes them.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Functionality](#functionality)
- [Usage](#usage)
- [Getting Started](#getting-started)

## Introduction

Monty is a simple stack-based programming language interpreter. It reads Monty bytecode files, which contain a series of commands (opcodes) that dictate how the program should execute.

## Features

- Stack-based execution model
- Support for various stack manipulation and arithmetic operations
- Printing characters and strings
- Error handling for common issues like stack underflow, division by zero, etc.


## Functionality

###Opcode Reference
- push: Pushes an element onto the stack
- pop: Removes the top element of the stack
- add, sub, mul, div, mod: Arithmetic operations
- pall, pint, pchar, pstr: Printing operations
- swap, nop: Stack manipulation operations

## Usage

1. Clone the repository:
```bash
git clone https://github.com/DevBasem/monty.git
```
2. Compile:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
3. Run the program:
```bash
./monty <bytecodes>
```
