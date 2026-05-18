#1
import os

def Min(ls):
    m = float("inf")
    for c in ls:
        if c < m:
            m = c
    return m

def Max(ls):
    m = float("-inf")
    for c in ls:
        if c > m:
            m = c
    return m

def Mean(ls):
    return sum(ls) / len(ls)

def Median(ls):
    sorted_ls = sorted(ls)
    middle = len(sorted_ls) // 2

    if len(sorted_ls) % 2 != 0:
        return sorted_ls[middle]
    else:
        return (sorted_ls[middle - 1] + sorted_ls[middle]) / 2


Dir = os.path.join(os.getcwd(), 'data')

frames = []

for file in os.listdir(Dir):
    frames.append(os.path.join(Dir, file))

with open("frames_out.txt", "w") as file_out:

    for path in frames:

        with open(path, "r") as f:

            data = f.readlines()
            data_float = list(map(float, data))

            dic = {
                "Min": Min(data_float),
                "Max": Max(data_float),
                "Mean": Mean(data_float),
                "Median": Median(data_float)
            }

            file_out.write(path + " " + str(dic))
            file_out.write("\n")

print("Done!")

#2
def validate_password(n):
    alf = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    simb = '!@#$%^&*()_+-=[]{}|;:,.<>?`'
    st = 0
    za = 0
    v1 = len(n) >= 8
    v2 = False
    v3 = False
    v4 = False

    for c1 in n:
        if c1.isalpha():
            v2 = True
            break

    for c2 in n:
        if c2.isdigit():
            v3 = True
            break

    for c3 in simb:
        if c3 in n:
            v4 = True
            break

    for c4 in n:
        if c4 in alf:
            za += 1
        elif c4 in alf.lower():
            st += 1

    v5 = (za != 0 and st != 0)

    return (v1 and v2 and v3 and v4 and v5, {
        'length': v1,
        'has_letter': v2,
        'has_digit': v3,
        'has_special': v4,
        'has_uppercase': za != 0,
        'has_lowercase': st != 0
    })

password = validate_password(input())

while password[0] == False:
    print(password)
    password = validate_password(input("Не валидный пароль! Повтори попытку: "))
print("Done!")

#3
from random import choice, shuffle
from time import sleep

def generate_password(length, char):
    password = ''
    for _ in range(length):
        password += choice(char)
    return password

upper = "ABCDEFGHJKLMNPQRSTUVWXYZ"
lower = "abcdefghijkmnopqrstuvwxyz"
digits = "23456789"
special = "!@#$%^&*()_+-=[]{}|;:,.<>?"
char = ''

choose = input("Do you want the password to be set automatically? y/n ")
if choose == 'y':
    char = upper + lower + digits + special
    length_password = 12
else:
    reset_try = True
    while reset_try:
        try:
            length_password = int(input("How long is your password? Minimal length is 8: "))
            if length_password < 8:
                print("Password length must be at least 8 characters!")
                continue
            reset_try = False
        except ValueError:
            print("Error 404 :(\nWe need digits!")
            reset_try = True

    ch_upper = input("Do you want to use UPPER letters? y/n ")
    ch_lower = input("Do you want to use LOWER letters? y/n ")
    ch_digits = input("Do you want to use DIGITS? y/n ")
    ch_special = input("Do you want to use SPECIAL symbols? y/n ")

    if ch_upper == 'y':
        char += upper
    if ch_lower == 'y':
        char += lower
    if ch_special == 'y':
        char += special
    if ch_digits == 'y':
        char += digits

if char == "":
    print("Oups! Bad Bad! I need more information! Okey I'll take my variants :)")
    char = upper + lower + digits + special
    sleep(1.5)

if choose != 'y':
    temp_char = ''
    temp_password = []

    if ch_upper == 'y':
        temp_password.append(choice(upper))
        temp_char += upper
    if ch_lower == 'y':
        temp_password.append(choice(lower))
        temp_char += lower
    if ch_digits == 'y':
        temp_password.append(choice(digits))
        temp_char += digits
    if ch_special == 'y':
        temp_password.append(choice(special))
        temp_char += special

    for _ in range(length_password - len(temp_password)):
        temp_password.append(choice(temp_char if temp_char else char))

    shuffle(temp_password)
    password = ''.join(temp_password)
else:
    password = generate_password(length_password, char)

print(password)
