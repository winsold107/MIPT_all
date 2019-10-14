from itertools import *
import operator


def dict_merge(*dict_args):
    return dict((x, y) for d in dict_args for x, y in d.items())


def transpose(matrix):
    return list(zip_longest(*matrix))


def uniq(inp):
    seen = set()
    for x in inp:
        if x in seen:
            continue
        seen.add(x)
    return list(seen)


def product(vect1, vect2):
    return sum(map(operator.mul, vect1, vect2))