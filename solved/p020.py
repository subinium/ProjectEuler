def f(n):
    ret = 1
    for i in range(1,n+1):
        ret *= i
    return ret

print(sum(map(int,str(f(100)))))
