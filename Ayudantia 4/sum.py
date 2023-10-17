def sum(*args):
    r = 0
    for i in args:
        r += i;
    return r

if __name__ == '__main__':

    print(sum(1, 2, 3, 4, 5))
