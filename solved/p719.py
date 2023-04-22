def check(N, M):
    if N>M: return False
    if N==M: return True
    t = 10
    while t < M:
        q, r = divmod(M,t)
        if r<N and check(N-r, q):
            return True
        t *= 10
    return False

def T(N):
    ret = 0
    for i in range(2, N+1):
        if i*i > N: break
        ret += i*i*check(i, i*i)
    return ret 

if __name__ == '__main__':
    print(T(10000))
    print(T(1000000000000))