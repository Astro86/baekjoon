def fibo(n):
    if(arr[n] > 0):
        return arr[n]
    if(n == 0):
        return arr[0]
    if(n == 1):
        return arr[1]
    arr[n] = fibo(n-1) + fibo(n-2)
    return arr[n]


arr = [0]*50
n = int(input())
arr[0] = 0
arr[1] = 1
print(fibo(n))
