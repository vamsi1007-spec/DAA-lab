import sys

n = int(input("Enter number of vertices: "))

cost = []
print("Enter adjacency matrix:")
for i in range(n):
    row = list(map(int, input().split()))
    cost.append(row)

selected = [False] * n
selected[0] = True

edges = 0
total_cost = 0

while edges < n - 1:
    minimum = sys.maxsize
    x = 0
    y = 0

    for i in range(n):
        if selected[i]:
            for j in range(n):
                if not selected[j] and cost[i][j] != 0:
                    if minimum > cost[i][j]:
                        minimum = cost[i][j]
                        x = i
                        y = j

    print(x, "-", y, ":", cost[x][y])
    total_cost += cost[x][y]
    selected[y] = True
    edges += 1

print("Total cost =", total_cost)