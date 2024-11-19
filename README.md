# push_swap

**push_swap** is a sorting algorithm project from the 42 curriculum. It requires creating a program that sorts a stack of integers using a specific set of operations and evaluates its efficiency based on the number of operations performed.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [How It Works](#how-it-works)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Allowed Operations](#allowed-operations)
- [Evaluation](#evaluation)

## About the Project

The **push_swap** project is designed to challenge your understanding of algorithms and data structures. The goal is to sort a stack of integers using a limited set of operations while achieving the smallest number of operations possible.

This project emphasizes:

- Stack manipulation.
- Algorithm optimization.
- Problem-solving under constraints.

## Features

- Implementation of sorting algorithms optimized for small data sets.
- Support for different stack operations.
- Handles errors and invalid inputs gracefully.

## How It Works

1. The program takes a list of integers as input and initializes two stacks:
   - Stack `A` (unsorted integers).
   - Stack `B` (empty at the start).

2. The goal is to sort `A` in ascending order using a predefined set of operations.

3. The program outputs a sequence of operations to achieve the sorting.

## Getting Started

### Prerequisites

- A C compiler (GCC or Clang).
- GNU Make.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/armhakob/push_swap.git
   cd push_swap
2. Compile the program:
   ```bash
     make
   ```
This will create `push_swap` executable.

### Usage

Run the program with a list of integers as arguments:
```bash
./push_swap [list of integers]
```
Example:
```bash
./push_swap 3 2 5 1 4
```
The output will be a sequence of operations to sort the integers.

### Allowed Operations

The following operations can be used to manipulate the stacks:
- `sa`: Swap the first two elements of stack `A`.
- `sb`: Swap the first two elements of stack `B`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element of stack `B` onto stack `A`.
- `pb`: Push the top element of stack `A` onto stack `B`.
- `ra`: Rotate stack `A` (shift all elements up, top becomes bottom).
- `rb`: Rotate stack `B`.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack `A` (shift all elements down, bottom becomes top).
- `rrb`: Reverse rotate stack `B`.
- `rrr`: Perform `rra` and `rrb` simultaneously.

### Evaluation

The project is evaluated based on:

1. __Correctness__: The program must always sort the integers correctly.

2. __Efficiency__: The number of operations must be minimized, especially for smaller data sets (e.g., 3, 5, or 100 integers).
