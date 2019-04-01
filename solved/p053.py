def fac(n):
    if n is 0:
        return 1;
    return n*fac(n-1)

def ncr(n,r):
    return fac(n)//(fac(r)*fac(n-r))

ans = 0

for i in range(1,101):
    for j in range(1,i+1):
        if ncr(i,j) >= 1000000:
            ans += 1

print (ans)
