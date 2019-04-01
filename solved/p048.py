MOD = 10000000000

def pw(n, k):
    res = 1;
    for i in range(k):
        res *= n
        res %= MOD
    return res

ans = 0

for i in range(1,1001):
    ans += pw(i,i)
    ans %= MOD

print (ans)
