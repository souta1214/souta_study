import numpy as np

# A = np.array([1, 2, 3, 4])
A = np.array([[1,2,3],[4,5,6]])
print(A)
#配列の次元数を取得
print(np.ndim(A))
#配列の形状を返す
print(A.shape)

B = np.array([[1,2], [3,4], [5,6]])
print(B)
print(np.ndim(B))
print(B.shape)

#行列の積
print(np.dot(A,B))

