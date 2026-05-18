import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('company_sales_data.csv')

print(df.head())
print(df.columns)

#1
plt.figure(figsize=(10, 5))
plt.plot(df['month_number'], df['total_profit'], marker='o')
plt.xlabel('Номер месяца')
plt.ylabel('Общая прибыль')
plt.title('Общая прибыль по месяцам')
plt.grid(True)
plt.show()

#2
plt.figure(figsize=(10, 5))
plt.plot(df['month_number'], df['total_units'],
         linestyle='--', color='red', marker='o',
         markersize=6, linewidth=3, label='Общее количество')
plt.xlabel('Номер месяца')
plt.ylabel('Количество проданных единиц')
plt.title('Общее количество проданных единиц по месяцам')
plt.legend(loc='lower right')
plt.grid(True)
plt.show()

#3
plt.figure(figsize=(12, 6))
products = ['facecream', 'facewash', 'toothpaste', 'bathingsoap', 'shampoo', 'moisturizer']
for product in products:
    plt.plot(df['month_number'], df[product], marker='o', label=product)
plt.xlabel('Номер месяца')
plt.ylabel('Количество продаж')
plt.title('Продажи всех продуктов по месяцам')
plt.legend(loc='upper left', bbox_to_anchor=(1, 1))
plt.grid(True)
plt.tight_layout()
plt.show()

fig, axes = plt.subplots(2, 3, figsize=(15, 10))
axes = axes.flatten()
for i, product in enumerate(products):
    axes[i].plot(df['month_number'], df[product], marker='o', color='blue')
    axes[i].set_title(product)
    axes[i].set_xlabel('Номер месяца')
    axes[i].set_ylabel('Продажи')
    axes[i].grid(True)
plt.tight_layout()
plt.show()

#4
plt.figure(figsize=(10, 5))
plt.scatter(df['month_number'], df['toothpaste'], color='green', s=100)
plt.xlabel('Номер месяца')
plt.ylabel('Продажи зубной пасты')
plt.title('Продажи зубной пасты по месяцам')
plt.grid(True, linestyle='--')
plt.show()

#5
x = np.arange(len(df['month_number']))
width = 0.35

plt.figure(figsize=(12, 6))
plt.bar(x - width/2, df['facecream'], width, label='Крем для лица', color='blue')
plt.bar(x + width/2, df['facewash'], width, label='Пенка для умывания', color='orange')
plt.xlabel('Номер месяца')
plt.ylabel('Количество проданных единиц')
plt.title('Продажи крема для лица и пенки для умывания')
plt.xticks(x, df['month_number'])
plt.legend()
plt.grid(True, axis='y')
plt.show()

#6
total_sales = {product: df[product].sum() for product in products}
plt.figure(figsize=(8, 8))
plt.pie(total_sales.values(), labels=total_sales.keys(), autopct='%1.1f%%', startangle=90)
plt.title('Общие продажи продуктов за год')
plt.show()

#7
plt.figure(figsize=(12, 6))
plt.stackplot(df['month_number'],
              [df['facecream'], df['facewash'], df['toothpaste'],
               df['bathingsoap'], df['shampoo'], df['moisturizer']],
              labels=products, alpha=0.7)
plt.xlabel('Номер месяца')
plt.ylabel('Количество продаж')
plt.title('Слоеная диаграмма продаж всех продуктов')
plt.legend(loc='upper left', bbox_to_anchor=(1, 1))
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()

#8
fig = plt.figure(figsize=(15, 12))

for i in range(1, 10):
    ax = fig.add_subplot(3, 3, i)
    ax.set_title(f'График {i}')
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.grid(True)

plt.tight_layout()
plt.show()

