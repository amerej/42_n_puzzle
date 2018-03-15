class EightPuzzleProblem:
    # grid is 9-array of the 3x3 8-puzzle grid in row-major order
    # 0 represents empty block
    def __init__(self, grid):
        self.grid = list(grid)
        for i in xrange(len(grid)):
            if self.grid[i] == 0:
                self.pos0 = i
                break

    # We'll define state to be tuple([grid], pos0, [path])
    def getStartState(self):
        return (self.grid, self.pos0, [])

    # Goal state is [1,2,3,4,5,6,7,8,0]
    def isGoalState(self, state):
        grid, pos0, _ = state
        for i in xrange(8):
            if grid[i] != i+1:
                return False
        return pos0 == 8

    def getSuccessors(self, state):
        moves = []
        grid, pos0, path = state

        def generateMove(incr, action):
            pathCopy = list(path)
            pathCopy.append(action)
            gridCopy = list(grid)
            gridCopy[pos0], gridCopy[pos0 + incr] = gridCopy[pos0 + incr], gridCopy[pos0]
            moves.append((gridCopy, pos0 + incr, pathCopy))

        if pos0 >= 3: # Slide empty block UP
            generateMove(-3, 'U')
        if pos0 <= 5: # Slide empty block DOWN
            generateMove(3, 'D')
        if (pos0 % 3) > 0: # Slide empty block LEFT
            generateMove(-1, 'L')
        if (pos0 % 3) < 2: # Slide empty block RIGHT
            generateMove(1, 'R')
        return moves

# Data Structures
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        return self.stack.pop()

    def top(self):
        return self.stack[-1]

    def empty(self):
        return len(self.stack) == 0

from collections import deque
class Queue:
    def __init__(self):
        self.queue = deque()
    def push(self, item):
        self.queue.append(item)
    def pop(self):
        return self.queue.popleft()
    def empty(self):
        return len(self.queue) == 0

import heapq
class PriorityQueue:
    def __init__(self, priorityFunction):
        self.priorityFunction = priorityFunction
        self.heap = []

    def push(self, item):
        heapq.heappush(self.heap, (self.priorityFunction(item), item))

    def pop(self):
        (_, item) = heapq.heappop(self.heap)
        return item

    def empty(self):
        return len(self.heap) == 0

# Search Algorithms
def graphSearch(problem, strategy):
    start = problem.getStartState()
    explored = set([str(start[0])])
    strategy.push(start)

    while not strategy.empty():
        node = strategy.pop()
        if problem.isGoalState(node):
            # return the solution path and no. of explored nodes
            return (node[2], len(explored))
        for move in problem.getSuccessors(node):
            gridCopy = str(move[0])
            if gridCopy not in explored:
                explored.add(gridCopy)
                strategy.push(move)
    return None

def depthFirstSearch(problem):
    return graphSearch(problem, Stack())

def breadthFirstSearch(problem):
    return graphSearch(problem, Queue())

def uniformCostSearch(problem):
    return graphSearch(problem, PriorityQueue(lambda state: len(state[2])))

def astarSearch(problem, heuristic):
    # A* uses path cost from start state + heuristic estimate to a goal
    totalCost = lambda state: len(state[2]) + heuristic(state)
    return graphSearch(problem, PriorityQueue(totalCost))

def hammingDistance(grid):
    return len([i for i in xrange(len(grid)) if grid[i] != 0 and grid[i] != i+1])

def manhattanDistance(grid):
    def distance(i):
        return 0 if grid[i] == 0 else abs(((grid[i]-1) / 3) - (i / 3)) + abs(((grid[i]-1) % 3) - (i % 3))
    return sum(distance(i) for i in xrange(len(grid)))

if __name__ == '__main__':
    eightPuzzleInstance = [3,0,7,2,8,1,6,4,5]
    problem = EightPuzzleProblem(eightPuzzleInstance)

    print "Hamming Distance: ", hammingDistance(eightPuzzleInstance)
    print "Manhattan Distance: ", manhattanDistance(eightPuzzleInstance)

    print "\nAlgorithm", "Nodes Explored", "Path Length"

    solution = depthFirstSearch(problem)
    print "DFS", solution[1], len(solution[0])

    solution = breadthFirstSearch(problem)
    print "BFS", solution[1], len(solution[0])

    solution = uniformCostSearch(problem)
    print "UFS", solution[1], len(solution[0])

    solution = astarSearch(problem, lambda state: hammingDistance(state[0]))
    print "A* with Hamming distance", solution[1], len(solution[0])

    solution = astarSearch(problem, lambda state: manhattanDistance(state[0]))
    print "A* with Manhattan distance", solution[1], len(solution[0])
