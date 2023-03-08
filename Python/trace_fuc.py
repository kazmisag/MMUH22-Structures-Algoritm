def mystery(n):
    if n<10:
        return n
    else:
        a =n//10
        b =n%10
        return mystery(a+b)

n = mystery(684)
print(n)