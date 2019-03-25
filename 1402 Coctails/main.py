from math import *

n = int(input())

answ = 0

for i in range(n, 1, -1):
	current = 1
	for j in range(i):
		current *= n - j
	#print(current)
	answ += current

print(answ)
