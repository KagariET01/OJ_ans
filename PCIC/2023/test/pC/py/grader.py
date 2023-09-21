def is_broken(k: int) -> int:
    if not type(k) is int:
        wa("invalid broken query")
    black_box.count += 1
    if black_box.count > 60:
        wa("too many queries")
    if k <= 0 or k > black_box.M:
        wa("invalid broken query")
    if k > black_box.h:
        return 1
    return 0

if __name__ == '__main__':
    M, h = map(int, input().split(' '))

    import Egg

    def wa(msg):
        print('Wrong Answer: ' + msg)
        exit(0)

    class Black_Box:
        def __init__(self, M, h):
            self.count = 0
            self.M = M
            self.h = h

    black_box = Black_Box(M, h)

    rt = Egg.height_limit(M)
    if rt != h:
        wa("incorrect height")
    else:
        print("Accepted: " + str(black_box.count))
