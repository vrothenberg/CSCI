# Programmer:   Vince Rothenberg
# Date:         December 18 2019
# Sources:      GeeksforGeeks, Wikipedia

# Djikstra's shortest path algorithm
# Takes adjacency matrix, starting node and destination nodes as input
# Outputs shortest path cost to each node

import sys

class Graph():

    # Initialize number of nodes and graph
    def __init__(self, nodes):
        self.N = nodes
        self.graph = [[0 for column in range(nodes)]
                         for row in range(nodes)]
        self.start = 0

    def printSolution(self, dist):
        print("Vince Rothenberg\nDecember 18 2019\n")
        print("Djikstra Shortest Path Algorithm\n")
        print("Start Node: %d \n" % (self.start))
        for node in range(self.N):
            print("Node: %d MinDist: %d" % (node, dist[node]))

    def minDistance(self, dist, visited):

        # Initialize min to infinity
        # Graph distance values should be lower than this
        min = float("inf");

        # Iterate over neighbors
        # If
        for n in range(self.N):
            if dist[n] < min and visited[n] == False:
                min = dist[n]
                min_index = n

        return min_index


    def dijkstra(self, start):
        self.start = start

        # Set of minimum distances for each node
        # Initialized to infinity so first weighted distance is always lower
        dist = [float("inf")] * self.N

        # Start node distance is 0 by definition, we're already here!
        dist[start] = 0

        # Visited Set
        visited = [False] * self.N

        for x in range(self.N):
            # Minimum distance from unvisited nodes
            u = self.minDistance(dist, visited)

            visited[u] = True

            # Iterate through each neighbor
            # Check if distance not 0, because 0 indicates non-adjacent
            # Check if not already visited
            # If new distance is lower than current minimum distance, update
            for n in range(self.N):
                if self.graph[u][n] > 0 and visited[n] == False and \
                dist[n] > dist[u] + self.graph[u][n]:
                    dist[n] = dist[u] + self.graph[u][n]

        self.printSolution(dist)


g = Graph(6)
# Adjacency matrix
g.graph = [[0,7,9,0,0,14],
[7,0,10,15,0,0],
[9,10,0,11,0,2],
[0,15,11,0,6,0],
[0,0,0,6,0,9],
[14,0,2,0,9,0]]

# Find shortest path length to each node starting from first node
g.dijkstra(0)
