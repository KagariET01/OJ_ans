def detect(x: int,y: int) -> int:
    black_box.count1 += 1
    if(black_box.count1 > 125000000):
        wa("too many detect queries")
    if(x<1 or y<1 or x>black_box.N or y>black_box.N):
        wa("invalid detect query")
    return black_box.arr[x][y]

def defuse(x: int,y: int):
    black_box.count2 += 1
    if(black_box.count2 > black_box.N):
        wa("too many defuse operations")
    if(x<2 or y<2 or x>black_box.N-1 or y>black_box.N-1):
         wa("invalid defuse operation")
    if(black_box.vis[x][y]==0):
        black_box.vis[x][y] = 1
        for i in black_box.mines:
            if(int(i[0])==x and int(i[1])==y):
                black_box.correct += 1

if __name__ == '__main__':
    N = int(input())

    import Minesweeper

    def wa(msg):
        print('Wrong Answer: ' + msg)
        exit(0)

    class Black_Box:
        def __init__(self, N):
            self.count1 = 0
            self.count2 = 0
            self.correct = 0
            self.N = N
            self.mines = []
            self.vis = [[0]*510 for _ in range(510)]
            self.arr = [[0]*510 for _ in range(510)]

    black_box = Black_Box(N)
    for i in range(N):
        x, y = map(int, input().split(' '))
        black_box.mines.append([x,y])

    for i in range(N):
        x,y = black_box.mines[i][0],black_box.mines[i][1]
        for j in range(-1,2):
            for k in range(-1,2):
                black_box.arr[x+j][y+k] += 1

    Minesweeper.defuse_mines(N)

    print(f'Accepted: {black_box.N} {black_box.count1} {black_box.count2} {black_box.correct}')
