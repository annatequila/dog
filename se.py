if __name__ == "__main__":
     
    print('你可以滴')

name = "小明"
age = 18
print("名字:", name)
print("年龄:", age)


name = 'xiaoming'
age = 18

print('ming自:',name)
print('年龄：', age)

score = 90
if score >= 90:
    print('优秀')
elif score >= 80:
    print('良好')
else:
    print('及格')
for i in range(5):
    print('循环次数:', i)
count = 0
while count < 3:
    print('while:',count)
    count += 1

for i in range(1,6):
    print('循环次数:', i)

def add(x,y):
    c = x + y
    return c

re = add(3,5)
print(re)

fruits = ['苹果', '香蕉', '橘子']
for f in fruits:
    print('水果:', f)

sq =[x*x for x in range(1,6)]
print('平方数:', sq)

st = {'name': '小明', 'age': 18}
print('字典:', st)

for key in st:
    print('键:', key, '值:', st[key])

sts = [st, {'name': '小红', 'age': 20}, {'name': '小刚', 'age': 22}]
print('字典列表:', sts)

for s in sts:
    print('字典列表元素:', s)

print(st['name'])

st['sc'] = "A"
print('添加新键值对:', st)

class dog:
    def __init__(self, name, age):
        self.name = name

        self.age = age

    def bark(self):
        print(self.name,'汪汪汪')
        print(self.name,'年龄:', self.age)

d = dog('小黑', 3)
d.bark()

d.name = '小白'
d.age = 4
d.bark()    
