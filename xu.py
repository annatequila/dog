import numpy as np


# class Dog:
#     species = "Felix"  # 类属性（共享）
#     def __init__(self, name, age):
#         self.name = name        # 实例属性
#         self.age = age

#     def bark(self):
#         print(f"{self.species}")
#         print(f"{self.name}：汪汪！")
#     def sit(self):
#         print(f"{self.name}坐下了。")

# class Cat:
#     species = "Felis"  # 类属性（共享）
#     def __init__(self, name):
#         self.name = name  # 实例属性（每个对象不同）
#     def meow(self):
#         print(f"{self.species}")
#         print(f"{self.name}：喵喵！")


class Animal:
    def speak(self):
        raise NotImplementedError

class Dog(Animal):
    def speak(self):
        return "汪汪"

class Cat(Animal):
    def speak(self):
        return "喵喵"

for a in (Dog(), Cat()):
    print(a.speak())  # 多态：相同接口，不同实现


class fath:
    def __init__(self, name):
        self.name = name
        self.age = self.name + '的年龄'
        print("父类构造函数被调用")
    def show(self):
        print("掉了")

class son(fath):
    def __init__(self, name):
        super().__init__(name)  # 调用父类构造函数
        print("儿子")
        print(f"{self.age}")

ff = son('haizi')
ff.show()
# f = Cat("小hon") 
# f.meow()


# d = Dog("小白", 3)
# d.bark()

# c = Cat("小花")
# c.meow()
