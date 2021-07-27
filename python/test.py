#!/usr/bin/env python3

print("Python test start.")
a=11
assert(a)
print("test1")
#assert(b)
print("test2")
class A:
    a=12
    b=13
    def __init__(self) -> None:
        print("init")
    def testf(self):
        print("testf")
ca=A()
print("tt is", ca.a)
ca.testf()