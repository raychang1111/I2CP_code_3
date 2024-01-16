#  https://www.luogu.com.cn/problem/P1080           ¤j¼Æ
from functools import cmp_to_key
def cmp(a):
    return a[0]*a[1]
def main():
    ans=0
    arr=[]
    curr=[0,0]
    n=int(input())
    curr[0],curr[1]=map(int,input().split())
    for i in range(n):
        temp1,temp2=map(int,input().split())
        arr.append([temp1,temp2])
    arr=sorted(arr,key=cmp)
    for i in range(n):
        ans=max(ans,curr[0]//arr[i][1])
        curr[0]*=arr[i][0]
    print(ans)
if __name__=='__main__':
    main()