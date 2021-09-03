#include "Tetris.h"

int boardX = 0;
int boardY = 0;

int interval = 1000;

bool running;
bool pause;

Object currentObj;

BLOCK objects[BLOCK_COUNT][4][4][4] = {
    //³×¸ð
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
    //±æÂßÀÌ
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_Y},
            {B_N,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_Y},
            {B_N,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N}
        }
    },
    //
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_N,B_N,B_Y,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_Y,B_Y,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_Y,B_N,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_N,B_N,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
    {
        {
            {B_N,B_N,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_N,B_Y,B_Y,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_N,B_N,B_N},
            {B_Y,B_Y,B_Y,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        },
        {
            {B_N,B_Y,B_N,B_N},
            {B_Y,B_Y,B_N,B_N},
            {B_N,B_Y,B_N,B_N},
            {B_N,B_N,B_N,B_N}
        }
    },
};

BLOCK** createBoard(int x, int y)
{
    boardX = x;
    boardY = y;

    BLOCK** board = (BLOCK**)malloc(y * sizeof(BLOCK*));    

    if (board != nullptr) {
        for (int i = 0; i < y; i++) {
            board[i] = (BLOCK*)malloc(x * sizeof(BLOCK));
            memset(board[i], 0, sizeof(BLOCK) * x);
        }
    }    

    srand((unsigned)time(NULL));
    currentObj.isExist = 0;
    running = false;
    pause = false;

    return board;
}

void removeBoard(BLOCK** board) {
    for (int i = 0; i < boardY; i++)
        free(board[i]);
    free(board);
}

char* viewStatus(char* buffer)
{
    if (currentObj.isExist)
        sprintf(buffer, "T bXY %d %d oTRXY %d %d %d %d", boardX, boardY, currentObj.type, currentObj.rot, currentObj.posX, currentObj.posY);
    else
        sprintf(buffer, "F bXY %d %d", boardX, boardY);
    return buffer;
}

void startTetris(BLOCK** board, int interval)
{
    if (!running) {
        running = true;
        setInterval(interval);
        _beginthread(workTetris, 0, board);

        char key;
        while (running) {
            if (!_kbhit()) continue;

            key = _getch();
            switch (key) {
            case 75:
                moveObjWithInput(board, 0);
                break;
            case 77:
                moveObjWithInput(board, 1);
                break;
            case 72:
                rotateObj(board, true);
            }
        }
    }
}

void workTetris(void * _board)
{
    BLOCK** board = (BLOCK**)_board;
    summonObj();

    while (running) {
        if (pause) continue;
        
        Sleep(interval);        
        if (!isCollisionObjToBottom(board)) {
            moveObjToBottom();
        }
        else {            
            objToBlock(board);
            reviewAllLine(board);
            currentObj.isExist = false;
            summonObj();
        }
        drawBoardOnText(board);        
    }
    _endthread();
}

void moveObjToBottom()
{
    currentObj.posY++;
}

void moveObjWithInput(BLOCK** board, short type)
{
    if (!currentObj.isExist) return;

    switch (type) {
    case 0:
        moveObjToLR(board, true);
        break;
    case 1:
        moveObjToLR(board, false);
        break;
    case 2:
        rotateObj(board,false);
        break;
    case 3:
        rotateObj(board,true);
        break;
    }
}

void setInterval(int interv)
{
    if (interv > 100)
        interval = interv;
    else
        interval = 2000;
}

short getRandomObj()
{
    return rand()%BLOCK_COUNT;
}

void drawBoardOnText(BLOCK** board) {
    for (int i = 0; i < boardY; i++) {
        for (int j = 0; j < boardX; j++) {
            if (board[i][j].isBlock) {
                printf("¡á");
            }else if (currentObj.isExist) {
                printf("%s", drawObjInBoardOnText(j, i) ? "¡á" : "¡à");
            }else {
                printf("¡à");
            }
        }            
        printf("\n");
    }
}

bool drawObjInBoardOnText(int pX, int pY)
{
    int gapX = pX - currentObj.posX, gapY = pY - currentObj.posY;

    if (gapX < 0 || gapX > 3 || gapY < 0 || gapY > 3) return false;    

    if (objects[currentObj.type][currentObj.rot][gapY][gapX].isBlock) return true;
    
    return false;
}

void summonObj()
{
    if (currentObj.isExist) return;

    currentObj.isExist = 1;
    currentObj.posX = boardX / 2 - 2;
    currentObj.posY = 1;
    currentObj.type = getRandomObj();  
    currentObj.rot = 0;
}

bool isCollisionObjToBottom(BLOCK** board)
{
    Object simulateObj = currentObj;
    simulateObj.posY++;
    return isCollisionObjInHere(board, simulateObj);
}

bool isCollisionObjInHere(BLOCK** board, Object object) {        

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {            
            if (objects[object.type][object.rot][i][j].isBlock) {
                if (i + object.posY >= boardY
                    || object.posX + j >= boardX
                    || board[object.posY + i][object.posX + j].isBlock) {                    
                    return true;
                }                    
            }
        }
    }
    return false;
}

void objToBlock(BLOCK** board) {       
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (objects[currentObj.type][currentObj.rot][i][j].isBlock) {
                board[i + currentObj.posY][j + currentObj.posX].isBlock = true;                
            }
        }
    }    
}

void setRunning(bool value) {
    running = value;
}

bool isRunning() {
    return running;
}

void pauseTetris() {
    pause = true;
}

void cancelPause() {
    pause = false;
}

void rotateObj(BLOCK** board, bool right) {
    Object simulateObj = currentObj;
    if (right) {
        simulateObj.rot = (simulateObj.rot++) % 4;
        if (!isCollisionObjInHere(board, simulateObj))
            currentObj = simulateObj;
    }
    else {
        simulateObj.rot--;
        if (simulateObj.rot < 0)
            simulateObj.rot = 3;
        if (!isCollisionObjInHere(board, simulateObj))
            currentObj = simulateObj;
    }
}

void moveObjToLR(BLOCK** board, bool direction) {
    Object simulateObj = currentObj;
    if (direction && simulateObj.posX > 0) {
        simulateObj.posX--;
        if (!isCollisionObjInHere(board, simulateObj))
            currentObj = simulateObj;
    }
    else {
        simulateObj.posX++;
        if (!isCollisionObjInHere(board, simulateObj))
            currentObj = simulateObj;
    }
}

void reviewAllLine(BLOCK** board) {
    bool isBlack;
    for (int i = boardY - 1; i > 0; i--) {
        isBlack = false;
        for (int j = 0; j < boardX; j++) {
            if (!board[i][j].isBlock)
                isBlack = true;
        }
        if (!isBlack) {
            destoryLine(board, i);
            pullLine(board, i);
            i--;
        }            
    }
}

void destoryLine(BLOCK** board, int line)
{
    for (int j = 0; j < boardX; j++)
        board[line][j].isBlock = false;
}

void pullLine(BLOCK** board, int line)
{
    for (int i = line; i > 0; i--) {
        for (int j = 0; j < boardX; j++)
            board[i][j] = board[i - 1][j];
    }
}