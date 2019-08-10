import os
import sys 

def subfolder(path):
    print(path)
    #lst = os.listdir(path)
    for i in os.listdir(path):
        childpath = os.path.join(path,i)
        if (os.path.isdir(childpath)):
            print (childpath)
            subfolder(childpath)
        
        print(i)
			

cwd = os.getcwd()
print(sys.argv[1])

subfolder(cwd)
