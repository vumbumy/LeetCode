from typing import List


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        indexed = {}
        for i in range(len(groupSizes)):
            indexed[i] = groupSizes[i]

        indexed = sorted(indexed.items(), key=lambda t : t[1], reverse=True)

        groups = []

        group = []
        for i in indexed:
            group.append(i[0])

            if len(group) == i[1]:
                groups.append(group)
                group = []

        return groups


print(Solution().groupThePeople([3, 3, 3, 3, 3, 1, 3]))