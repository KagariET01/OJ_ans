import time
import os
import json
import colorama
from colorama import Fore, Style
import threading
os.system("rm run")
print("building")
if(os.system("g++ -o run main.cpp")):
	print(Fore.YELLOW+"COMPILER ERROR!")
	exit()

print("loading CFG")
cfg=json.loads(open("config.json","r").read())
count=0
allac=True

stt=0
edt=0

def runcode():
	if(os.system(".\\run < "+i["input"]+" > "+i["output"])):
		print("test",count,"result:",Fore.RED+"RUNTIME ERROR!",end=" ")
	edt-time.time()

def timer():
	stt=time.time()
	time.sleep(i["tl"]+2)
	edt=time.time

runcode_event=threading.Thread(target=runcode)
timer_event=threading.Thread(target=timer)



for i in cfg:
	print("test",count,":",end=" ")
	if(open(i["input"],"r").read()==""):
		print("ERROR! File is empty!")
		continue
	
	threading.Thread(target=runcode).start()
	time.sleep(i["tl"]+3)


	edt=time.time()
	outf=open(i["output"],"r").read().lower()
	ansf=open(i["answer"],"r").read().lower()
	ans=True
	if(outf!=ansf):
		print(Fore.RED+"WRONG ANSWER!",end=" ")
		ans=False
	if((edt-stt)>i["tl"]):
		print(Fore.RED+"Time Limit Exceed!",end=" ")
		ans=False
	if(ans):
		print(Fore.GREEN+"ACCEPT!",end="")
	else:
		allac=False
	
	print(Fore.WHITE+" time:",(edt-stt))
	count+=1

if(allac):
	print(Fore.GREEN+"Example Test Passed")