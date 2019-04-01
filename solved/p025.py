arr = [1, 0]

for i in range(2,10000):
    tmp = arr[i-2] + arr[i-1]
    arr.append(tmp);
    if len(str(tmp)) == 1000:
        print (i)
        break

print(arr[12])
