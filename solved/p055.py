def palin(n):
    n = str(n)
    r = n[::-1]
    return n == r

def palin_add(n):
    n = str(n)
    r = n[::-1]
    return int(n)+int(r)


ans = 0

for i in range (1, 10000):
    s = i
    for j in range(0,49):
        s = palin_add(s)
        if palin(s) :
            ans += 1
            break

print (9999-ans)
