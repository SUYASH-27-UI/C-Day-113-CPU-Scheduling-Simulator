# C-Day-113-CPU-Scheduling-Simulator
# C Day 113 – CPU Scheduling Simulator

## Project Description
A C program that simulates two CPU scheduling algorithms: First Come First Serve (FCFS) and Shortest Job First (SJF).

## Features
- Accepts multiple processes.
- Calculates waiting time.
- Calculates turnaround time.
- Calculates average waiting time.
- Calculates average turnaround time.
- Compares FCFS and SJF scheduling results.

## Technologies Used
- C Programming
- Structures
- Arrays
- Sorting
- Functions

## Scheduling Algorithms
1. FCFS – Executes processes in their input order.
2. SJF – Executes the process with the shortest burst time first.

## How to Run
Compile using:
`gcc scheduling.c -o scheduling`

Run:
`./scheduling`

## Learning Outcome
Learned how CPU scheduling works and how FCFS and SJF algorithms affect waiting time and turnaround time.

## Note
This educational simulator assumes all processes arrive at time zero. SJF is non-preemptive.
