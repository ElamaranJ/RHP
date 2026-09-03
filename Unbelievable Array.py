import sys
input = sys.stdin.readline

T = int(input())

for tc in range(1, T + 1):
    n, q = map(int, input().split())
    A = list(map(int, input().split()))
    mp = list(range(100001))

    print("Case " + str(tc) + ":")

    for _ in range(q):
        op = list(map(int, input().split()))

        if op[0] == 1:
            x, y = op[1], op[2]
            for i in range(1, 100001):
                if mp[i] == x:
                    mp[i] = y
        else:
            idx = op[1] - 1
            print(mp[A[idx]])
