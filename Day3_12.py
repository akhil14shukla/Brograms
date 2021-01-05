class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return a list of integers
    

    def solve(self, A, B):
        d = dict()
        for i in range(0, len(A)):
            count1 = 0
            count2 = 0
            for j in range(0, i+1):
                if(A[i] >= A[j]):
                    count1 = count1 + 1
            for j in range(i, len(A)):
                if(A[i] >= A[j]):
                    count2 = count2 + 1
            d[A[i]] = count1*count2
        d = sorted(d)
        print(d.values())
A = [1,2,4]
B = [1,2,4]
Solution.solve(0,A,B)
