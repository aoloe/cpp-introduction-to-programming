#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# © 2018, MIT license, Ale Rimoldi <a.l.e@graphicslab.org>

import sys
from subprocess import call, Popen, PIPE

def compile(file):
    call(["g++", "-std=c++17", "-o", "test", file])
    
def run(args, token_i, debug = False):
    run_command = Popen( "./test",
        stdin=PIPE, stdout=PIPE, shell=True )
    arguments = ' '.join(str(t) for t in args) + "\n" 
    out, err = run_command.communicate(arguments.encode())
    token = out.decode('utf-8').split()
    if debug:
        print(token)
    token_n = len(token)
    token_i = [t if t > 0 else token_n + t for t in token_i]
    return [int(x) if x.isnumeric() else x for i, x in enumerate(token) if i in token_i]

def test(a, b, error_message):
    if a == b:
        sys.stdout.write('\x1b[1;34m' + '✓' + '\x1b[0m')
    else:
        print()
        sys.stderr.write('\x1b[1;31m' + '✗' + '\x1b[0m' + '\n')
        print(error_message);
        print(a);
        print('≠');
        print(b);
        sys.exit();

file = 'input-calculator.cpp'
compile(file)
# pass the values 1, 2, 3 and 4 to the program and read the 3rd last and last words in the output
result = run([1, 2, 1, 3], [-3, -1])
# compare the result with the values [5, 6]
test(result, [5, 6], file)

basic_tests = [
    [[1, 2, '+', 1, 3], [5, 6], ' +'],
    [[1, 2, '-', 1, 3], [1, 6], ' -'],
    [[1, 2, '*', 1, 3], [1, 6], ' *'],
    [[1, 2, '/', 1, 3], [3, 2], ' /']
]
def do_basic_tests(filename):
    for t in basic_tests:
        result = run(t[0], [-3, -1])
        test(result, t[1], filename + t[2])

filename = 'branching_calculator.cpp'
compile(filename)
do_basic_tests(filename)

filename = 'branching_calculator_error_checking.cpp'
compile(filename)
do_basic_tests(filename)

result = run([1, 2, '+', 1, 0], [-3, -1])
test(result, [0, 0], file + ' +0e')

result = run([1, 2, '+', 0, 2], [-3, -1])
test(result, [2, 4], file + ' +0ok')

result = run([1, 2, '/', 0, 2], [-7, -6, -5, -3, -1])
test(result, ['can', 'not', 'be', 0, 0], file + ' /0e')

filename = 'loops_calculator_simplify.cpp'
compile(filename)
do_basic_tests(filename)

result = run([1, 2, '+', 1, 2], [-3, -1])
test(result, [1, 1], file + ' + .5*2')

result = run([2, 3, '*', 3, 4], [-3, -1])
test(result, [1, 2], file + ' + .5*2')

print()
