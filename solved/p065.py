
a = [2]

for i in range(0,99):
    if i%3==0 or i%3==2:
        a.append(1);
    else :
        a.append(2*((i+2)//3))
b = a[::-1]

def gcd(a, b):
    if a%b==0:
        return b
    else :
        return gcd(b,a%b)

mo = 1
so = 1

for i in range(1,100):
    print(b[i])
    so += b[i]*mo
    tmp = so
    so = mo
    mo = tmp
    g = gcd(so,mo)
    so //= g
    mo //=g

ret = 0

while mo > 0 :
    ret += mo%10
    mo //= 10

print(ret)

