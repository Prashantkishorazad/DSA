class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        n = len(positions)
        
        robots = [(positions[i], healths[i], directions[i], i) for i in range(n)]
        robots.sort()
        
        stack = []
        health = healths[:]  # copy
        
        for pos, h, d, idx in robots:
            if d == 'R':
                stack.append(idx)
            else:
                while stack and health[idx] > 0:
                    top = stack[-1]
                    
                    if health[top] < health[idx]:
                        health[top] = 0
                        stack.pop()
                        health[idx] -= 1
                    elif health[top] > health[idx]:
                        health[top] -= 1
                        health[idx] = 0
                        break
                    else:
                        health[top] = 0
                        health[idx] = 0
                        stack.pop()
                        break
        
        return [health[i] for i in range(n) if health[i] > 0]