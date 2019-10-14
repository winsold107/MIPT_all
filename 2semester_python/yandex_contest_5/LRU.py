from collections import OrderedDict
from functools import wraps


def cache(argument):
    def decorator(func):
        data = OrderedDict()

        @wraps(func)
        def wrapper(*args, **kwargs):
            key = (tuple(args), tuple(sorted(kwargs.items())))

            if key in data:
                return data[key]
            else:
                data[key] = func(*args, **kwargs)

            if len(data) > argument:
                data.popitem(last=False)

            return data[key]
        return wrapper
    return decorator


def fib(n):
    if n == 1 or n == 0:
        return 1
    return fib(n-1) + fib(n-2)



from datetime import datetime

# start = datetime.now()
# print(fib(36))
# end = datetime.now()
# print(end-start)


@cache(100)
def fib(n):
    if n == 1 or n == 0:
        return 1
    return fib(n-1) + fib(n-2)

start = datetime.now()
print(fib(36))
end = datetime.now()
print(end-start)
