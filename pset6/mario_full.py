import cs50

n = 0

while True:
    print("Height: ", end="")
    n = cs50.get_int()
    if n > 0 or n < 23:
        break
print(n)

for i in range(n):
    for j in range(n-i):
        print(" ", end="",)
    for k in range(n-(n-1)+i):
        print("#", end="")
    print(" ", end="")
    for k in range(n-(n-1)+i):
        print("#", end="")
    print()
