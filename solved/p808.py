def prime(n, era):
    l = len(era)
    for i in range(2, l):
        if not era[i]: continue
        for j in range(i*i, l, i):
            era[j] = False

def check_palin(n):
    s = str(n)

    q = str(int(int(s[::-1])**0.5))
    qr = int(q)**2
    return era[int(q)] and s[::-1]==str(qr) and n!=qr

if __name__ == '__main__':
    N = int(1e8)
    era = [True for _ in range(N)]
    prime(N, era)
    ans, idx = 0, 0
    # print(check_palin(1681))
    for i in range(5, N):
        if era[i] and check_palin(i*i):
            ans += i*i
            idx += 1 
            if idx == 50: break
    print(idx)
    print(ans)