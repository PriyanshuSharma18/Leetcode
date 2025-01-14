class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        n=len(A)
        arr=[0]*(n+1) #Counting the elements into array
        res=[0]*n

        cnt=0

        for i in range(n):
            arr[A[i]]+=1
            if arr[A[i]]==2: 
                cnt+=1
            
            arr[B[i]]+=1
            if arr[B[i]]==2:
                cnt+=1
            
            res[i]=cnt
    
        return res