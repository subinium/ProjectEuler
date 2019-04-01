SZ = 60

mu = [0]*(SZ+1)
mu[1] = 1

for i in range(1,SZ+1):
  for j in range(2*i, SZ+1, i):
    mu[j] -= mu[i]

def f(n):
  n = (2**n)-1
  ret = 0
  for i in range(1,n+1):
    if i * i > n :
      break
    if n % i == 0:
      ret += i + n//i + 2
  return ret

ans = 0

for i in range(1,SZ+1):
  if SZ % i == 0:
    ans += mu[i] * f(SZ//i)

print (ans)

# 3 min 15sec 
