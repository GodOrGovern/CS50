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
    cost = [[0] * (len(a) + 1)] * (len(b) + 1)
    cost[0] = [(row, None) for row in range(len(a) + 1)]
    cost = list(zip(*cost))
    cost = [list(row) for row in cost]
    cost[0] = [(col, None) for col in range(len(b) + 1)]
    for row in range(1, len(a) + 1):
        for col in range(1, len(b) + 1):
            cond = [(1, Operation(3).__str__()) if a[row-1] != b[col-1] else (0, None)]
            trans = [
                (cost[row-1][col][0] + 1, Operation(1).__str__()),
                (cost[row][col-1][0] + 1, Operation(2).__str__()),
                (cost[row-1][col-1][0] + cond[0][0], cond[0][1]),
            ]
            cost[row][col] = min(trans, key=lambda x: x[0])
    return cost