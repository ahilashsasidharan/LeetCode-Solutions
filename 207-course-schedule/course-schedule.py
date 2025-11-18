class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        # Create Adjacency List (Ignore Nodes/Courses without Prerequisites as They Always Can Be Completed)
        graph = defaultdict(list)
        for u, v in prerequisites:
            graph[u].append(v)

        # Run DFS For All Nodes
        finished = set()
        in_progress = []

        for node in range(numCourses):
            if node in finished:
                continue

            stack = [(node, False)]
            
            while stack:
                curr, expanded = stack.pop()

                if expanded:
                    in_progress.remove(curr)
                    finished.add(curr)
                    continue

                if curr in in_progress:
                    return False

                if curr in finished:
                    continue

                in_progress.append(curr)

                stack.append((curr, True))
                
                for neighbour in graph[curr]:
                    if neighbour in in_progress:
                        return False
                    if neighbour not in finished:
                        stack.append((neighbour, False))
            
        return True
            

            