SZ = int(1e15)
MOD = int(1e9)

def sq_sum(n):
    return n*(n+1)*(2*n+1)//6

high = SZ
ANS = 0

while high != 0:
    cnt = SZ // high
    low = (SZ//(cnt+1)) 
    # print(cnt,high,low)
    ANS += cnt * (sq_sum(high) - sq_sum(low))
    high = low

print (int(ANS % MOD))
