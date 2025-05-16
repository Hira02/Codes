#decorators take another function as argument, modify it and returns a new function which extends the existing function
def my_decorator(func):
    def wrapper():
        print("before calling func, all flow as it is")
        func()# this will not chnage the existing function but will add new functionality
        print("after calling func, all flow as it is post")
        # return func
    return wrapper

@my_decorator
def myFunc(): # this will spread as    myFunc  =  my_decorator(myFunc)
    print(" hey you")
myFunc()