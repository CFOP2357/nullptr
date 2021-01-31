while True:
  n, m = map(int, input().split())
  if n == 0 and m == 0:
    break
  A = set(map(int, input().split()))
  B = set(map(int, input().split()))
  print(len(A.difference(B)), end = " ")
  print(len(A.intersection(B)), end = " ")
  print(len(B.difference(A)), end = " ")
  print(len(A.union(B)))



