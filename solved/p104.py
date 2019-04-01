from math import log10

def pandi_ck(n):
    n = int(n)
    ck = [0]*10
    ck[0] = 1
    for i in range(9):
        ck[n%10] += 1
        if ck[n%10]==2:
            return False
        n //= 10
    return True

phi, rtf = (1+5**0.5) / 2, (5**0.5)
phi = log10(phi)
rtf = log10(rtf)


def top_digit(n):
    t = n * phi + -rtf
    t = int((pow(10, t - int(t) + 8)))
    return t

f,s,cnt = 1, 1, 2

while True :
    f, s = s, f+s % (10**9)
    cnt+=1
    if pandi_ck(s) and pandi_ck(top_digit(cnt)):
        print (cnt)
        break
