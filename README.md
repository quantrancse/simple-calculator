# Simple Calculator

Simple Calculator using Linked List and Stack support funtion with variables

## Getting Started

Simple Calculator using Postfix Algorithm to calculate general mathematic equations and power functions. Using Linked List and Stack to store Token and transfer from Infix to Postfix

### Prerequisites

Install Git and GNU Compiler

```bash
$ apt update
$ apt install git build-essential
```
Clone git:

```bash
$ git clone https://github.com/quantrancse/simple-calculator.git
```

### Installing

Compile:

```bash
$ cd simple-calculator
$ g++ main.cpp -o main
```

## Usage

Run the main.out file

```bash
$ ./main
```
After run:
```bash
$ Enter equation (Split by ';' semicolon): 
```

Enter single equation or multiple equations split by semicolon ';'

### Example

Single equation:

```bash
$ Enter equation (Split by ';' semicolon): -2 + 3 * (5 + 6^-2) - 2^3
$ Result: 5.08
```
Multiple equations:

```bash
$ Enter equation (Split by ';' semicolon): 1 + 1/2 ; 2 * 3.6
$ Result: 1.50
$ Result: 7.20
```
Equations with variables:

```bash
$ Enter equation (Split by ';' semicolon): x = 2 + 3 ; y = x + x ; z = x * y
$ Result:
$ x = 5.00
$ y = 10.00
$ z = 50.00
```

## Authors

* **Tran Trung Quan** - *Student at Ho Chi Minh City University of Technology* - [Quan Tran](https://quantrancse.me)



