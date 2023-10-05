import time
import os
import json
import colorama
from colorama import Fore, Style
os.system("rm run")
print("building")
if(os.system("g++ -o run main.cpp")):
	print(Fore.YELLOW+"COMPILER ERROR!")
	exit()

print("loading CFG")
cfg=json.loads(open("config.json","r").read())
count=0
allac=True
for i in cfg:
	print("test",count,":",end=" ")
	if(open(i["input"],"r").read()==""):
		print("ERROR! File is empty!")
		continue
	stt=time.time()
	if(os.system(".\\run < "+i["input"]+" > "+i["output"])):
		print("test",count,"result:",Fore.RED+"RUNTIME ERROR!",end=" ")
		exit()
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