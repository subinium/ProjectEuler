MX = 3e6

b, ans = 2, 0
while 4 * b**3 < MX :
    ans += int((MX/(b**3))**0.5)-1
    b += 1

dp = [0] * 70

for i in range(0, 70, 2):
    dp[i] = 1
for i in range(3, 70):
    dp[i] += dp[i-3]

arr = [False]*1000
p = [] 

for i in range(2,1000):
    if arr[i] :
        continue
    p.append(i)
    for j in range(i*i, 1000, i):
        arr[j] = True   

def dfs(idx, val, cnt):
    global p
    if idx == len(p):
        return
    dfs(idx+1, val, cnt)
    



print (p)
