from tkinter import *
import tkinter
from ctypes import *
bms = cdll.LoadLibrary('./bms.dll')

bms.customer_setName.argtypes = [c_void_p, c_char_p]
bms.customer_setAddress.argtypes = [c_void_p, c_char_p]

class Customer(object):
    def __init__(self, name, phone, address):
        self.obj = bms.customer_new()
        self.setAttribs(name, phone, address)

    def setAttribs(self, name, phone, address):
        bms.customer_setName(c_void_p(self.obj), c_char_p(name))
        bms.customer_setPhoneNumber(c_void_p(self.obj), phone)
        bms.customer_setAddress(c_void_p(self.obj), c_char_p(address))

    def getName(self):
        return c_char_p(bms.customer_getName(self.obj)).value.decode()

    def getPhone(self):
        return bms.customer_getPhoneNumber(self.obj)

    def getAddress(self):
        return c_char_p(bms.customer_getAddress(self.obj)).value.decode()

    def __del__(self):
        bms.customer_free(self.obj)

class Application(tkinter.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.hi_there = tkinter.Button(self)
        self.hi_there["text"] = "Hello World\n(click me)"
        self.hi_there["command"] = self.say_hi
        self.hi_there.pack(side="top")

        self.quit = tkinter.Button(self, text="QUIT", fg="red",
                              command=root.destroy)
        self.quit.pack(side="bottom")

    def say_hi(self):
        print("hi there, everyone!")

root = tkinter.Tk()
app = Application(master=root)

test = Customer(b"Fuck head", 5611234, b"Fuck head st");

print(test.getName())
print(test.getPhone())
print(test.getAddress())

app.mainloop()
