from collections import Mapping, Set, Sequence
from array import array

string_types = str if str is bytes else (str, bytes)
iteritems = lambda mapping: getattr(mapping, 'iteritems', mapping.items)()


def objwalk(obj, path=(), memo=None, lis=[]):
    if memo is None:
        memo = set()
    iterator = None
    if isinstance(obj, Mapping):
        iterator = iteritems
    elif isinstance(obj, (Sequence, Set)) and not isinstance(obj, string_types):
        iterator = enumerate
    if iterator:
        if id(obj) not in memo:
            memo.add(id(obj))
            for path_component, value in iterator(obj):
                for result in objwalk(value, path + (path_component,), memo, lis):
                    if isinstance(result, str):
                        for i in result:
                            lis.insert(0, i)
                            yield i
                    elif isinstance(result, array):
                        for i in result:
                            lis.insert(0, i)
                            yield i
                    else:
                        lis.insert(0, result)
                        yield result
            memo.remove(id(obj))
    else:
        yield obj


def flatit(inp):
    lis = list()
    for res in objwalk(inp):
        print(res)
        # if isinstance(res, str):
        #     for i in res:
        #         lis.insert(0, i)
        # elif isinstance(res, array):
        #     for i in res:
        #         lis.insert(0, i)
        # else:
        #     lis.insert(0, res)
    lis.reverse()
    # return lis


flatit(([1, [2, 3]], ['test'], range(0, 3, 1)))
