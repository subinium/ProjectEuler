import math

def pell_equ(D):
    limit = int(math.sqrt(D))
    if limit * limit == D: return 0
    m, d, a = 0, 1, limit
    px, x, py, y = 1, a, 0, 1
    while x*x-D*y*y != 1:
        m = d*a-m
        d = (D-m*m) // d
        a = (limit+m) // d
        x, y, px, py = a*x+px, a*y+py, x, y
    return x

mx, ans, SZ = 0, 0, 1000

for i in range(2,SZ+1):
    l = pell_equ(i)
    if l > mx:
        mx, ans = l, i 

print (mx, ans)
