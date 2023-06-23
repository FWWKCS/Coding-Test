reminder = []
for i in range(10):
    num = int(input())
    reminder.append(num % 42)

print(len(list(set(reminder))))