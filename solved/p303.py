import queue

def f(n):
    cnt = 0
    ck = [False]*n
    q = queue.Queue()
    q.put(1)
    q.put(2)
    while q.qsize() > 0:
        f = q.get()
        if ck[f%n] :
            continue
        ck[f%n] = True
        # print(cnt)
        if f%n == 0 :
            return f//n
        if not ck[(f*10)%n] :
            q.put(f*10)
        if not ck[(f*10+1)%n] :
            q.put(f*10 +1)
        if not ck[(f*10+2)%n] :
            q.put(f*10 +2)
    return 0

ans, SZ = 0, 10000

for i in range(1, SZ+1):
    ans += f(i)
    if i% 1000 == 0 : print(i)

print(ans)

# 4m 15s
