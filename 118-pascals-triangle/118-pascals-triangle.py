class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = [[1]]
        for i in range(1, numRows):
            ret.append([1] + [ret[i - 1][j - 1] + ret[i - 1][j] for j in range(1, i)] + [1])
        return ret