
res = []
permutation = []
def Perm(numbers, q):
    if len(permutation) == q:
        print(permutation)
        return
    for idx, num in enumerate(numbers):
        if not used[idx]:
            used[idx] = True
            permutation.append(num)
            Perm(numbers, q)
            permutation.pop()
            used[idx] = False


if __name__ == "__main__":
    size = 5
    numbers = [i for i in range(1, size + 1)]
    used = [False] * size
    Perm(numbers, 2)