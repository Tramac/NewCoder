import sys
 
a=sys.stdin.readline().strip()
b=sys.stdin.readline().strip().split(" ")
c=sys.stdin.readline().strip().split(" ")
 
print(" ".join(sorted(set(b+c),key=int)))
