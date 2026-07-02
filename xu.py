import numpy as np

class Dog:
    def __init__(self, name, age):
        self.name = name        # 实例属性
        self.age = age

    def bark(self):
        print(f"{self.name}：汪汪！")
    def sit(self):
        print(f"{self.name}坐下了。")













d = Dog("小白", 3)
d.bark()
d.sit()

