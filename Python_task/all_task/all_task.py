# #---------------task1----------------------
# def check_user_access(user,resource):
#     if user is None:
#         return "Пользователь не найден"
#     if not user.is_active:
#         return "Пользователь не активен"
#     if not user.has_permission(resource):
#         return "Недостаточно прав"
#     if resource.is_maintenance:
#         return "Ресурс на техническом обсулживании"
#     return "Доступ разрешен"

# def calculate_discount(order):
#     if order.total_amount <= 0:
#         return 0
#     if order.customer_type != ("VIP" or "REGULAR"):
#         return 0
#     if order.customer_type == "VIP":
#         if order.total_amount > 10_000:
#             return order.total_amount * 0.20
#         return order.total_amount * 0.15
#     if order.customer_type == "REGULAR":
#         if order.total_amount > 5_000:
#             return order.total_amount * 0.10
#         return order.total_amount * 0.05

# def process_payment(transaction):
#     if transaction.amount <= 0:
#         return {"status": "error", "message": "Сумма должна быть положительной"}
#     if not transaction.is_valid():
#         return {"status": "error", "message": "Невалидная транзакция"}
#     if not transaction.sender.has_funds(transaction.amount):
#         return {"status": "error", "message": "Недостаточно стредств"}
#     if not transaction.receiver.can_receive_payment():
#         return {"status": "error", "message": "Получатель не может принять платеж"}
#     transaction.execute()
#     return {"status": "error", "message": "Платеж выполнен"}



# def calculate_delivery_cost(order, address, customer_type, weight, total_amount, self_delivery, in_town, far_rg):
#     delivery_cost = 0.0
#     #1.Базовая проверка данных
#     if order is None:
#         return {"success": False, "cost": delivery_cost, "message": "Заказ не существует"}
#     if address is None:
#         return {"success": False, "cost": delivery_cost, "message": "Адрес не указан"}
#     if weight <= 0:
#         return {"success": False, "cost": delivery_cost, "message": "Вес заказа должен быть положительным числом"}

#     #2.Акции и ограничения:
#     if weight > 50:
#         return {"success": False, "cost": delivery_cost, "message": "Максимальный вес для доставки: 50 кг"}
#     if total_amount < 1_000:
#         return {"success": False, "cost": delivery_cost, "message": "Минимальная стоимость заказа для доставки: 1000 рублей" }
#     if self_delivery:
#         return {"success": True, "cost": delivery_cost, "message": "Успешно, самовывоз"}
#     if total_amount >= 10_000 and not far_rg:
#         return {"success": True, "cost": delivery_cost, "message": "Бесплатная доставка при заказе от 10000 рублей (кроме отдаленных регионов)"}

#     #3.Логика расчета
#     if in_town:
#         if weight < 5:
#             delivery_cost += 300
#         if 5 <= weight <= 10:
#             delivery_cost += 500
#         if weight > 10:
#             delivery_cost = 500 + 50 * (weight - 10)
#     if not in_town:
#         delivery_cost = 1_000 + 100 * weight

#     #2.Специальные условия
#     if customer_type == "VIP" and total_amount >= 5_000:
#         delivery_cost = 0.0
#         return {"success": True, "cost": delivery_cost, "message": "Для VIP клиентов: бесплатная доставка при заказе от 5000 рублей"}
#     if customer_type == "NEW":
#         delivery_cost *= 0.85
#     if far_rg:
#         delivery_cost *= 1.2

#     return {"success": True, "cost": delivery_cost, "message": "Доставка оформлена"}

# #Тесты
# # 1. есть ли заказ, есть ли адрес, тип зазазчика, вес, стоимость товара, есть ли самовывоз, есть ли в городе
# print("1.", calculate_delivery_cost(1,1,"",0,5_000, 0, 0, 0))
# print("2.",calculate_delivery_cost(1,1,"",10,5_000, 1, 0, 0))
# print("3.",calculate_delivery_cost(1,1,"VIP",10,5_000, 0, 0, 0))
# print("4.",calculate_delivery_cost(1,1,"NEW",10,5_000, 0, 1, 0))
# print("5.",calculate_delivery_cost(1,1,"",10,5_000, 0, 0, 1))
# print("6.",calculate_delivery_cost(1,1,"",10,10_000, 0, 1, 0))
# print("7.",calculate_delivery_cost(1,1,"",51,10_000, 0, 1, 0))
# print("8.",calculate_delivery_cost(1,1,"",10,999, 0, 1, 0))



# #-----------------task2-------------------------------------

# #1
# import os

# def Min(ls):
#     m = float("inf")
#     for c in ls:
#         if c < m:
#             m = c
#     return m

# def Max(ls):
#     m = float("-inf")
#     for c in ls:
#         if c > m:
#             m = c
#     return m

# def Mean(ls):
#     return sum(ls) / len(ls)

# def Median(ls):
#     sorted_ls = sorted(ls)
#     middle = len(sorted_ls) // 2

#     if len(sorted_ls) % 2 != 0:
#         return sorted_ls[middle]
#     else:
#         return (sorted_ls[middle - 1] + sorted_ls[middle]) / 2


# Dir = os.path.join(os.getcwd(), 'data')

# frames = []

# for file in os.listdir(Dir):
#     frames.append(os.path.join(Dir, file))

# with open("frames_out.txt", "w") as file_out:

#     for path in frames:

#         with open(path, "r") as f:

#             data = f.readlines()
#             data_float = list(map(float, data))

#             dic = {
#                 "Min": Min(data_float),
#                 "Max": Max(data_float),
#                 "Mean": Mean(data_float),
#                 "Median": Median(data_float)
#             }

#             file_out.write(path + " " + str(dic))
#             file_out.write("\n")

# print("Done!")

# #2
# def validate_password(n):
#     alf = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
#     simb = '!@#$%^&*()_+-=[]{}|;:,.<>?`'
#     st = 0
#     za = 0
#     v1 = len(n) >= 8
#     v2 = False
#     v3 = False
#     v4 = False

#     for c1 in n:
#         if c1.isalpha():
#             v2 = True
#             break

#     for c2 in n:
#         if c2.isdigit():
#             v3 = True
#             break

#     for c3 in simb:
#         if c3 in n:
#             v4 = True
#             break

#     for c4 in n:
#         if c4 in alf:
#             za += 1
#         elif c4 in alf.lower():
#             st += 1

#     v5 = (za != 0 and st != 0)

#     return (v1 and v2 and v3 and v4 and v5, {
#         'length': v1,
#         'has_letter': v2,
#         'has_digit': v3,
#         'has_special': v4,
#         'has_uppercase': za != 0,
#         'has_lowercase': st != 0
#     })

# password = validate_password(input())

# while password[0] == False:
#     print(password)
#     password = validate_password(input("Не валидный пароль! Повтори попытку: "))
# print("Done!")

# #3
# from random import choice, shuffle
# from time import sleep

# def generate_password(length, char):
#     password = ''
#     for _ in range(length):
#         password += choice(char)
#     return password

# upper = "ABCDEFGHJKLMNPQRSTUVWXYZ"
# lower = "abcdefghijkmnopqrstuvwxyz"
# digits = "23456789"
# special = "!@#$%^&*()_+-=[]{}|;:,.<>?"
# char = ''

# choose = input("Do you want the password to be set automatically? y/n ")
# if choose == 'y':
#     char = upper + lower + digits + special
#     length_password = 12
# else:
#     reset_try = True
#     while reset_try:
#         try:
#             length_password = int(input("How long is your password? Minimal length is 8: "))
#             if length_password < 8:
#                 print("Password length must be at least 8 characters!")
#                 continue
#             reset_try = False
#         except ValueError:
#             print("Error 404 :(\nWe need digits!")
#             reset_try = True

#     ch_upper = input("Do you want to use UPPER letters? y/n ")
#     ch_lower = input("Do you want to use LOWER letters? y/n ")
#     ch_digits = input("Do you want to use DIGITS? y/n ")
#     ch_special = input("Do you want to use SPECIAL symbols? y/n ")

#     if ch_upper == 'y':
#         char += upper
#     if ch_lower == 'y':
#         char += lower
#     if ch_special == 'y':
#         char += special
#     if ch_digits == 'y':
#         char += digits

# if char == "":
#     print("Oups! Bad Bad! I need more information! Okey I'll take my variants :)")
#     char = upper + lower + digits + special
#     sleep(1.5)

# if choose != 'y':
#     temp_char = ''
#     temp_password = []

#     if ch_upper == 'y':
#         temp_password.append(choice(upper))
#         temp_char += upper
#     if ch_lower == 'y':
#         temp_password.append(choice(lower))
#         temp_char += lower
#     if ch_digits == 'y':
#         temp_password.append(choice(digits))
#         temp_char += digits
#     if ch_special == 'y':
#         temp_password.append(choice(special))
#         temp_char += special

#     for _ in range(length_password - len(temp_password)):
#         temp_password.append(choice(temp_char if temp_char else char))

#     shuffle(temp_password)
#     password = ''.join(temp_password)
# else:
#     password = generate_password(length_password, char)

# print(password)


# #-------------------task3------------------------------------
# import os


# def is_float(value):
#         try:
#             float(value)
#             return True
#         except ValueError:
#             return False


# def values(data):
#         data = data.strip()

#         if data == '':
#             return '', 'str'

#         elif data.isdigit() or (data[0] == '-' and data[1:].isdigit()):
#             return int(data), 'int'

#         elif is_float(data):
#             return float(data), 'float'

#         else:
#             return data, 'str'


# def delimiter(line):
#     delimiters = [',', '\t', '|', ';']

#     for delim in delimiters:
#         if delim in line:
#             return delim

#     return ','


# def has_header(data):

#     first = data[0].split(delimiter(data[0]))

#     for elem in first:

#         val, typ = values(elem)

#         if typ == 'str':
#             return True

#     return False


# Dir = 'data1'

# frames = []

# for file in os.listdir(Dir):
#     frames.append(Dir + '/' + file)


# with open("frames_out", "w") as file_out:

#     for i in range(len(frames)):

#         with open(frames[i], "r", encoding='utf-8') as f:

#             data = f.readlines()

#             first_st = has_header(data)

#         dell = delimiter(data[0])

#         header = []

#         start = 0

#         if first_st:
#             header = data[0].strip().split(dell)
#             start = 1

#         types_list = []
#         data_list = []

#         if start < len(data):

#             first_line = data[start].split(dell)

#             for part in first_line:

#                 val, typ = values(part)

#                 types_list.append(typ)

#         for line in data[start:]:

#             parts = line.strip().split(dell)

#             values_list = []

#             for part in parts:

#                 val, typ = values(part)

#                 values_list.append(val)

#             data_list.append(values_list)

#         print({
#             'header': header,
#             'data': data_list,
#             'types': types_list
#         })

#         print()

# #-------------------task6-----------------------------------

# import pandas as pd
# import matplotlib.pyplot as plt
# import numpy as np

# df = pd.read_csv('company_sales_data.csv')

# print(df.head())
# print(df.columns)

# #1
# plt.figure(figsize=(10, 5))
# plt.plot(df['month_number'], df['total_profit'], marker='o')
# plt.xlabel('Номер месяца')
# plt.ylabel('Общая прибыль')
# plt.title('Общая прибыль по месяцам')
# plt.grid(True)
# plt.show()

# #2
# plt.figure(figsize=(10, 5))
# plt.plot(df['month_number'], df['total_units'],
#          linestyle='--', color='red', marker='o',
#          markersize=6, linewidth=3, label='Общее количество')
# plt.xlabel('Номер месяца')
# plt.ylabel('Количество проданных единиц')
# plt.title('Общее количество проданных единиц по месяцам')
# plt.legend(loc='lower right')
# plt.grid(True)
# plt.show()

# #3
# plt.figure(figsize=(12, 6))
# products = ['facecream', 'facewash', 'toothpaste', 'bathingsoap', 'shampoo', 'moisturizer']
# for product in products:
#     plt.plot(df['month_number'], df[product], marker='o', label=product)
# plt.xlabel('Номер месяца')
# plt.ylabel('Количество продаж')
# plt.title('Продажи всех продуктов по месяцам')
# plt.legend(loc='upper left', bbox_to_anchor=(1, 1))
# plt.grid(True)
# plt.tight_layout()
# plt.show()

# fig, axes = plt.subplots(2, 3, figsize=(15, 10))
# axes = axes.flatten()
# for i, product in enumerate(products):
#     axes[i].plot(df['month_number'], df[product], marker='o', color='blue')
#     axes[i].set_title(product)
#     axes[i].set_xlabel('Номер месяца')
#     axes[i].set_ylabel('Продажи')
#     axes[i].grid(True)
# plt.tight_layout()
# plt.show()

# #4
# plt.figure(figsize=(10, 5))
# plt.scatter(df['month_number'], df['toothpaste'], color='green', s=100)
# plt.xlabel('Номер месяца')
# plt.ylabel('Продажи зубной пасты')
# plt.title('Продажи зубной пасты по месяцам')
# plt.grid(True, linestyle='--')
# plt.show()

# #5
# x = np.arange(len(df['month_number']))
# width = 0.35

# plt.figure(figsize=(12, 6))
# plt.bar(x - width/2, df['facecream'], width, label='Крем для лица', color='blue')
# plt.bar(x + width/2, df['facewash'], width, label='Пенка для умывания', color='orange')
# plt.xlabel('Номер месяца')
# plt.ylabel('Количество проданных единиц')
# plt.title('Продажи крема для лица и пенки для умывания')
# plt.xticks(x, df['month_number'])
# plt.legend()
# plt.grid(True, axis='y')
# plt.show()

# #6
# total_sales = {product: df[product].sum() for product in products}
# plt.figure(figsize=(8, 8))
# plt.pie(total_sales.values(), labels=total_sales.keys(), autopct='%1.1f%%', startangle=90)
# plt.title('Общие продажи продуктов за год')
# plt.show()

# #7
# plt.figure(figsize=(12, 6))
# plt.stackplot(df['month_number'],
#               [df['facecream'], df['facewash'], df['toothpaste'],
#                df['bathingsoap'], df['shampoo'], df['moisturizer']],
#               labels=products, alpha=0.7)
# plt.xlabel('Номер месяца')
# plt.ylabel('Количество продаж')
# plt.title('Слоеная диаграмма продаж всех продуктов')
# plt.legend(loc='upper left', bbox_to_anchor=(1, 1))
# plt.grid(True, alpha=0.3)
# plt.tight_layout()
# plt.show()

# #8
# fig = plt.figure(figsize=(15, 12))

# for i in range(1, 10):
#     ax = fig.add_subplot(3, 3, i)
#     ax.set_title(f'График {i}')
#     ax.set_xlabel('X')
#     ax.set_ylabel('Y')
#     ax.grid(True)

# plt.tight_layout()
# plt.show()




#---------------------task7--------------------------------

# import numpy as np
# import matplotlib.pyplot as plt


# def load_data(filename):
#     x, y = [], []
#     with open(filename, 'r', encoding='utf-8') as f:
#         for line in f.readlines()[1:]:
#             if line.strip():
#                 parts = line.strip().split(';')
#                 x.append(float(parts[0]))
#                 y.append(np.nan if parts[1] == 'NaN' else float(parts[1]))
#     return np.array(x), np.array(y)


# def linear_interp(x1, y1, x2, y2, x):
#     return y1 + (y2 - y1) * (x - x1) / (x2 - x1)


# def quadratic_interp(xp, yp, x):
#     A = np.array([[xp[0]**2, xp[0], 1], [xp[1]**2, xp[1], 1], [xp[2]**2, xp[2], 1]])
#     coef = np.linalg.solve(A, yp)
#     return coef[0]*x**2 + coef[1]*x + coef[2]


# def find_nearest(x, y, idx, n):
#     left, right = [], []
#     for i in range(idx-1, -1, -1):
#         if not np.isnan(y[i]):
#             left.append((x[i], y[i]))
#             if len(left) == n: break
#     for i in range(idx+1, len(x)):
#         if not np.isnan(y[i]):
#             right.append((x[i], y[i]))
#             if len(right) == n: break
#     return left, right

# def interpolate(x, y, method='linear'):
#     y_filled = y.copy()
#     for i in range(len(x)):
#         if np.isnan(y[i]):
#             if method == 'linear':
#                 left, right = find_nearest(x, y, i, 1)
#                 if left and right:
#                     y_filled[i] = linear_interp(left[0][0], left[0][1], right[0][0], right[0][1], x[i])
#             else:  # quadratic
#                 left, right = find_nearest(x, y, i, 2)
#                 points = []
#                 if len(left) >= 2 and len(right) >= 1:
#                     points = left[:2] + right[:1]
#                 elif len(left) >= 1 and len(right) >= 2:
#                     points = left[:1] + right[:2]
#                 elif len(left) >= 3:
#                     points = left[:3]
#                 elif len(right) >= 3:
#                     points = right[:3]
#                 if len(points) >= 3:
#                     points.sort(key=lambda p: p[0])
#                     y_filled[i] = quadratic_interp([p[0] for p in points], [p[1] for p in points], x[i])
#     return y_filled


# x, y = load_data('lab2_data.csv')
# nan_idx = np.where(np.isnan(y))[0]


# plt.plot(x, y, 'bo-', label='Исходные данные')
# plt.scatter(x[nan_idx], [plt.ylim()[0]]*len(nan_idx), color='red', marker='x', label='Пропуски')
# plt.legend()
# plt.show()

# y_lin = interpolate(x, y, 'linear')
# y_quad = interpolate(x, y, 'quadratic')

# print("Линейная:", [f"x={x[i]:.0f}, y={y_lin[i]:.2f}" for i in nan_idx])
# print("Квадратичная:", [f"x={x[i]:.0f}, y={y_quad[i]:.2f}" for i in nan_idx])


# plt.plot(x, y_lin, 'g-', label='Линейная интерполяция')
# plt.plot(x, y_quad, 'r-', label='Квадратичная интерполяция')
# plt.scatter(x[nan_idx], y_lin[nan_idx], color='green', marker='o', facecolors='none')
# plt.scatter(x[nan_idx], y_quad[nan_idx], color='red', marker='s', facecolors='none')
# plt.legend()
# plt.show()



# #------------------task10--------------------------------------


# import pandas as pd
# import numpy as np
# import matplotlib.pyplot as plt

# data = pd.read_csv('data.csv', sep=';')

# print(data.head())

# x = data.iloc[:, 0]
# y = data.iloc[:, 1]

# N = len(y)

# print("Количество наблюдений N =", N)

# L = 3

# z = []

# for i in range(N):
#     left = max(0, i - L)
#     right = min(N, i + L + 1)

#     avg = np.mean(y[left:right])
#     z.append(avg)

# plt.figure(figsize=(10, 5))
# plt.plot(x, y, label='Исходный ряд')
# plt.plot(x, z, label='Скользящее среднее')

# plt.title('Сглаживание методом скользящего среднего')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.legend()
# plt.grid()

# plt.show()

# alpha = 0.3

# exp_smooth = [y.iloc[0]]

# for i in range(1, N):
#     s = alpha * y.iloc[i] + (1 - alpha) * exp_smooth[i - 1]
#     exp_smooth.append(s)

# plt.figure(figsize=(10, 5))
# plt.plot(x, y, label='Исходный ряд')
# plt.plot(x, exp_smooth, label='Экспоненциальное сглаживание')

# plt.title('Экспоненциальное сглаживание')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.legend()
# plt.grid()

# plt.show()

