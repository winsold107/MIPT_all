class Range:

    def __init__(self, n1, n2=None, step=None):
        if n1 is None:
            raise ValueError('n1 can not be None')

        if n2 is None and step is not None:
            raise ValueError()

        if step == 0:
            raise ValueError('Range() arg 3 must not be zero')

        if n2 is None:
            self.__init(0, n1, 1)
        elif step is None:
            self.__init(n1, n2, 1)
        else:
            assert n1 is not None and n2 is not None and step is not None
            self.__init(n1, n2, step)

    def __init(self, start, stop, step):
        self.start = start
        self.stop = stop
        self.step = step

        self.current_value = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current_value >= self.stop:
            self.current_value = self.start
            raise StopIteration()

        return_value = self.current_value
        self.current_value += self.step
        return return_value

    def __len__(self):
        start = self.start
        stop = self.stop
        step = self.step

        assert step != 0

        if stop <= start and step > 0 or start <= stop and step < 0:
            return 0

        res = (abs(stop - start)-1) / abs(step)

        return int(res) + 1

    @staticmethod
    def between(start, stop, val):
        return start <= val < stop or stop < val <= start

    def __contains__(self, item):
        start = self.start
        stop = self.stop
        step = self.step

        if self.step < 0:
            start = -start
            stop = -stop
            step = -step
            item = -item

        return (item - start) % step == 0 and start <= item < stop

    def __str__(self):
        res = 'Range({start}, {stop}'.format(start=self.start, stop=self.stop)
        if self.step != 1:
            res += (', ' + str(self.step))

        res += ')'

        return res

    def __getitem__(self, index):
        start = self.start
        stop = self.stop
        step = self.step

        if self.step < 0:
            start = -start
            stop = -stop
            step = -step

        if index < 0:
            index = len(self) + index

        res = start + index * step
        if res >= stop or res < start:
            raise IndexError

        if self.step < 0:
            res = -res

        return res

    def __repr__(self):
        return str(self)


for start in range(-50, 50):
    for stop in range(-50, 50):
        for step in range(-50, 50):
            if step == 0:
                continue
            rl = len(range(start, stop, step))
            Rl = len(Range(start, stop, step))
            if rl != Rl:
                print("start={}, stop={}, step={}, correct={}, our={}".format(start, stop, step, rl, Rl))
            assert rl == Rl

print("len passed")

for start in range(-25, 25):
    for stop in range(-25, 25):
        for step in range(-25, 25):
            if step == 0:
                continue
            for i in range(-25, 25):
                R = Range(start, stop, step)
                r = range(start, stop, step)
                cond = (i in r) != (i in R)
                if cond:
                    print("start={}, stop={}, step={}, number={}, correct={}, our={}".
                          format(start, stop, step, i, i in r, i in R))
                assert not cond

print("contains passed")

for start in range(-50, 50):
    for stop in range(-50, 50):
        for step in range(-50, 50):
            if step == 0:
                continue
            r = str(range(start, stop, step))
            R = str(Range(start, stop, step))
            if r[1:] != R[1:]:
                print("start={}, stop={}, step={}, correct={}, our={}".format(start, stop, step, r, R))
            assert r[1:] == R[1:]

print("str passed")


for start in range(-25, 25):
    for stop in range(-25, 25):
        for step in range(-25, 25):
            if step == 0:
                continue
            for i in range(-25, 25):
                R = Range(start, stop, step)
                r = range(start, stop, step)
                try:
                    cond = (r[i] == R[i])
                except IndexError:
                    continue

                if not cond:
                    print("start={}, stop={}, step={}, index={}, correct={}, our={}".
                          format(start, stop, step, i, r[i], R[i]))
                assert cond

print("indexing passed")