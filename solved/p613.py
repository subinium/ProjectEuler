# integral ((pi/2+arctan(x/(4-y))+arctan(y/(3-x)))/(12*pi)), x=0...3, y=0...4-(4x/3)

from sympy import integrate, Symbol, pprint, atan, pi, N

x = Symbol('x')
y = Symbol('y')

f = (atan(x/(4-y)) + atan(y/(3-x)) + pi/2)

pprint(f)

print(str(N(integrate(integrate(f,(y,0,4-(4*x/3))),(x,0,3))/(12*pi)))[0:12])
