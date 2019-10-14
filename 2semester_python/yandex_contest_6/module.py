def force_load(path):
    with open(path, mode='r') as f:
        lines = [line for line in f]

    for i in range(len(lines)-1):
        for j in range(i+1, len(lines)):
            pass
#not done