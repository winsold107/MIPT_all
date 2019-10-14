from contextlib import contextmanager

class supresser:
    def __init__(self, *args):
        self.type = args

    def __enter__(self):
        pass

    def __exit__(self, exc_type, exc, traceback):
        return exc_type is not None and exc_type in self.type


@contextmanager
def retyper(type_from, type_to):
    ex = None
    try:
        yield
    except type_from as e:
        ex = e

    if ex is not None:
        raise type_to(*ex.args).with_traceback(ex.__traceback__)


@contextmanager
def dumper(stream):
    try:
        yield
    except Exception as e:
        stream.write(str(e))
        stream.write(str(e.__traceback__))
        raise
