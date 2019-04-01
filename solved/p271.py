N = 13082761331670030

# N is 2 * 3 * 5 * 7 * 11 * 17 * 19 * 23 * 29 * 31 * 37 * 41 * 43

prime = []
remain = []
sz = 0
ans = 0

def crt(pr, r, n):
    sz = len(pr)

    s = []
    for i in pr:
        ntmp = n//i
        for j in range(0,i):
            if (ntmp*j)%i == 1:
                s.append(j)
                break

    ret = 0
    for i in range(0,sz):
        ret += (n//pr[i]) * r[i] * s[i]
        ret %= n

    return ret

def dfs(remain_arr,idx):
    global prime, remain, N, ans, sz
    if idx == sz:
        ans += crt(prime,remain_arr,N)
    else :
        for i in range(0,len(remain[idx])):
            rtmp = remain_arr[::]
            rtmp.append(remain[idx][i])
            dfs(rtmp,idx+1)

def prime_factor(n):
    prime = []
    flag = 2
    while n != 1:
        if n % flag == 0 :
            prime.append(flag)
            n //= flag
        else :
            flag += 1
    return prime

def prime_remain(prime):
    ret = []
    for i in prime:
        remain_i = []
        for j in range(1, i):
            if (j**3)%i==1 :
                remain_i.append(j)
        ret.append(remain_i)
    return ret

def euler271(n):
    global prime, remain, sz, ans
    prime = prime_factor(n)
    remain = prime_remain(prime)
    sz = len(prime)
    dfs([],0)
    print (ans-1) # because 1 is included in answer

euler271(N)
