#!/bin/bash

problem=Minesweeper

python3 -m compileall -b .
mv grader.pyc __main__.pyc
zip -r Minesweeper.zip __main__.pyc Minesweeper.pyc
mv Minesweeper.zip Minesweeper
rm __main__.pyc Minesweeper.pyc
