txt = ""
for i in range(0,2000000):
    txt += str(i)

idx = 1
ans = 1

for i in range(0,7):
    ans *= int(txt[idx])
    idx *= 10

print(ans)
