def s(n):
    tot = 0
    while n > 0 :
        tot += n%10
        n //= 10
    return tot

ans = -1

for i in range(1,101):
    for j in range(1,101):
        if ans < s(i**j):
            ans = s(i**j)

print (ans)
