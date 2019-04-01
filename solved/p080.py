from decimal import getcontext, Decimal

getcontext().prec = 105 # 정밀도 설정

L, d, s = 100, 100, 0
p = pow(10, d-1)

for i in range(2, L):
    q = Decimal(i).sqrt()
    if q % 1 == 0 :
        continue
    else :
        s += sum(int(c) for c in str(q * p)[:d])

print (s)
