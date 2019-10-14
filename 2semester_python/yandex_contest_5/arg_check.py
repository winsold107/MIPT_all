import functools
import sys


def takes(*args):
    def decorator(f):
        ch_l = []
        for i in args:
            ch_l.insert(0, i)
        ch_l.reverse()

        @functools.wraps(f)
        def wrapper(*args):
            a = 0
            for i in args:
                a += 1
                if a <= len(ch_l):
                    if isinstance(i, ch_l[a-1]):
                        continue
                    else:
                        raise TypeError
            return f(*args)
        return wrapper
    return decorator


exec(sys.stdin.read())
