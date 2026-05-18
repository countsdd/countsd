import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv('data.csv', sep=';')

print(data.head())

x = data.iloc[:, 0]
y = data.iloc[:, 1]

N = len(y)

print("Количество наблюдений N =", N)

L = 3

z = []

for i in range(N):
    left = max(0, i - L)
    right = min(N, i + L + 1)

    avg = np.mean(y[left:right])
    z.append(avg)

plt.figure(figsize=(10, 5))
plt.plot(x, y, label='Исходный ряд')
plt.plot(x, z, label='Скользящее среднее')

plt.title('Сглаживание методом скользящего среднего')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid()

plt.show()

alpha = 0.3

exp_smooth = [y.iloc[0]]

for i in range(1, N):
    s = alpha * y.iloc[i] + (1 - alpha) * exp_smooth[i - 1]
    exp_smooth.append(s)

plt.figure(figsize=(10, 5))
plt.plot(x, y, label='Исходный ряд')
plt.plot(x, exp_smooth, label='Экспоненциальное сглаживание')

plt.title('Экспоненциальное сглаживание')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid()

plt.show()
