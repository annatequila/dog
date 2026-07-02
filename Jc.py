# python 继承

class persion:
    def __init__(self, name,age):
        self.name = name
        self.age =age

    def show(self):
        print(f'名字：{self.name},\n nianl:{self.age}')

class yuangong(persion):
    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary
    def show_sa(self):
        print('工资：', self.salary)



# a = yuangong('小明', 18, 5000)
# a.show()
# a.show_sa()

b = [yuangong('小红', 20, 6000), yuangong('小李', 22, 7000),    yuangong('小刚', 24, 8000)]
for bb in b:
    bb.show_sa()