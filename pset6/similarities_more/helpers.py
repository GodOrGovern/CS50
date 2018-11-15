from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""
    cost = [[None for x in range(len(b) + 1)] for y in range(len(a) + 1)]
    for h in range(1, len(a) + 1):
        cost[h][0] = (h, Operation(1)) 
    for j in range(1, len(b) + 1):
        cost[0][j] = (j, Operation(2))
    cost[0][0] = (0, None)
    for row in range(1, len(a) + 1):
        for col in range(1, len(b) + 1):
            cond = [1 if a[row-1] != b[col-1] else 0]
            trans = [
                (cost[row-1][col][0] + 1, Operation(1)),
                (cost[row][col-1][0] + 1, Operation(2)),
                (cost[row-1][col-1][0] + cond[0], Operation(3)),
            ]
            cost[row][col] = min(trans, key=lambda x: x[0])
    return cost