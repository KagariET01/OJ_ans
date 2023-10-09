from queue import Queue
import time
import os
import json
import colorama
from colorama import Fore, Style
import threading
import sys
import copy


inf=open("io/01.out","r")
outf=open("io/01.out","r")
t=int(inf.readline())

for i in range(t):
	inin=inf.readline()
	ouou=outf.readline()
	