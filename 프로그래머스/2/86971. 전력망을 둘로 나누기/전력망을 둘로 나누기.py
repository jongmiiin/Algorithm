import math

def solution(n, wires):
    nodes = [[] for _ in range(n+1)]
    for wire in wires:
        nodes[wire[0]].append(wire[1])
        nodes[wire[1]].append(wire[0])
    mn = 104
    def count_top(n, flag, node_a, node_b):
        flag[n] = True
        count = 1
        for node in nodes[n]:
            if (n==node_a and node==node_b) or (n==node_b and node==node_a):
                continue
            if not flag[node]:
                count += count_top(node, flag, node_a, node_b)
        return count
        
    for wire in wires:
        flag = [False] * (n+1)
        a = count_top(wire[0], flag, wire[0], wire[1])
        b = n-a
        mn = min(mn, abs(b-a))
        
    return mn