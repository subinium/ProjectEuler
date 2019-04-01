ans = 0
for i in range(1,10):
    for j in range(1,100):
        if len(str(i**j))==j:
            ans+=1

print (ans)
