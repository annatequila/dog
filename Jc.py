# python 继承

class persion:
    def __init__(self, name,age):
        self.name = name
        self.age =age

    def show(self):
        print(f'名字：{self.name},\n nianl:{self.age};')

class yuangong(persion):
    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary
    def show_sa(self):
        print(f'工资：{self.salary};')

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __repr__(self):
        return f"Point({self.x}, {self.y})"

    def __str__(self):
        return f"({self.x}, {self.y})"

    def __eq__(self, other):
        return isinstance(other, Point) and self.x == other.x and self.y == other.y
# ##############################################
    def __add__(self, other):
        if not isinstance(other, Point):
            return NotImplemented
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        if not isinstance(other, Point):
            return NotImplemented
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        if not isinstance(scalar, (int, float)):
            return NotImplemented
        return Point(self.x * scalar, self.y * scalar)


class lingdao:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.xiashu = yuangong(self.name, self.age, 10000)
        print(f'领导年龄{self.age}')
    @classmethod
    def ss(cls,sui):
        cls.sui= sui
        print('类方法')
        print(cls.sui)
    @staticmethod
    def tt(age):
        print(f'静态方法，年龄：{age}')


# a = yuangong('小明', 18, 5000)
# a.show()
# a.show_sa()

b = [yuangong('小红', 20, 6000), yuangong('小李', 22, 7000),    yuangong('小刚', 24, 8000)]
for bb in b:
    bb.show_sa()
    bb.show()

p1 = Point(1, 1)
p2 = Point(2, 3)
print("p1:", p1)
print("p2:", p2)
print("repr(p2):", repr(p2))


print("p1 == Point(1, 1):", p1 == Point(1, 1))
print("p1 + p2:", p1 + p2)
print("p2 - p1:", p2 - p1)
print("p1 * 3:", p1 * 3)

d = lingdao('王总', 50)
d.xiashu.show_sa()
d.ss(5)
d.tt(34)