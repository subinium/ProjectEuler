class Fibo:
    def __init__(self, N):
        self.N = N
        fibo, fibo_cum = [], []
        st, ed, tsum = 1, 1, 0
        for i in range(100):
            if ed > N: break
            fibo.append(ed)
            tsum += ed
            fibo_cum.append(tsum)
            st, ed = ed, st+ed

        self.fibo = fibo[::-1]
        self.fibo_cum = fibo_cum[::-1]
        self.l = len(fibo)
        self.ans = pow(2, self.l)
        self.dfs(0, 0)
        print(self.ans)

    def dfs(self, idx, cum_sum):
        if cum_sum > self.N:
            self.ans -= pow(2, self.l-idx)
            return
        if idx == self.l: return
        if cum_sum + self.fibo_cum[idx] < self.N: return
        self.dfs(idx+1, cum_sum+self.fibo[idx])
        self.dfs(idx+1, cum_sum)
        
    
if __name__ == '__main__':
    Fibo(int(1e2))
    Fibo(int(1e4))
    Fibo(int(1e13))
    