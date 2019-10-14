# import sys


class ExtendedList(list):

    def __getattr__(self, attr):
        # try:
        if (attr == 'F') or (attr == 'first'):
            return self[0]
        elif (attr == 'L') or (attr == 'last'):
            return self[len(self)-1]
        elif (attr == 'R') or (attr == 'reversed'):
            some_list = self.copy()
            some_list.reverse()
            return some_list
        elif (attr == 'size') or (attr == 'S'):
            return len(self)
        else:
            raise AttributeError
        # except AttributeError:
        #     pass

    def __setattr__(self, attr, val):
        # try:
        if (attr == 'F') or (attr == 'first'):
            self[0] = val
            return self[0]
        elif (attr == 'L') or (attr == 'last'):
            self[len(self)-1] = val
            return self[len(self)-1]
        elif (attr == 'size') or (attr == 'S'):
            if val <= len(self):
                i = 0
                a = len(self)
                while i < a - val:
                    self.pop()
                    i += 1
                return self
            else:
                i = len(self)
                while i < val:
                    self.insert(i, None)
                    i += 1
                return self
        else:
            raise AttributeError
        # except AttributeError:
        #     pass


try:
    listing = ExtendedList([1, 2, 3, 4])
    print(listing.reversed)
    #print(listing.first)
    #print(listing.last)
    listing.F = 0
    listing.abcd
    listing.sat = 2
    print(listing)
    listing.last = 'mur'
    print(listing)
    listing.append(-1)
    print(listing.L)
    print(listing.count(0))
    print(listing.reversed)
    listing.size = 12
    print(listing)
    listing.size = 4
    print(listing)
    print(listing.R)
    listing.L = 2
    print(listing)
except _:
    pass
# exec(sys.stdin.read())
