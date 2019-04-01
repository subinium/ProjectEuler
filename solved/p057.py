a = 1
b = 1
ans = 0

for i in range(0,1000):
    aa = a+2*b
    bb = a+b
    a = aa
    b = bb
    if len(str(a))>len(str(b)):
        ans += 1

print(ans)
