#include "Tetris.h"

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

TETRIS* createTetris(int x, int y)
{
    TETRIS* tetris = (TETRIS*)malloc(sizeof(TETRIS));

    tetris->width = x;
    tetris->height = y;
    tetris->blockSize = 25;

    tetris->board = (BLOCK**)malloc(y * sizeof(BLOCK*));

    if (tetris->board != nullptr) {
        for (int i = 0; i < y; i++) {
            tetris->board[i] = (BLOCK*)malloc(x * sizeof(BLOCK));
            memset(tetris->board[i], 0, sizeof(BLOCK) * x);
        }
    }        

    tetris->curObj = (OBJECT*)malloc(sizeof(OBJECT));

    tetris->curObj->isExist = false;
    tetris->score = 0;
    tetris->running = false;
    tetris->pause = false;

    return tetris;
}

void removeTetris(TETRIS* tetris) {
    for (int i = 0; i < tetris->height; i++)
        free(tetris->board[i]);
    free(tetris->board);
    free(tetris->curObj);
    free(tetris);
}

char* viewStatus(TETRIS* tetris, char* buffer)
{
    if (tetris->curObj->isExist)
        sprintf(buffer, "T bXY %d %d oTRXY %d %d %d %d", tetris->width, tetris->height, tetris->curObj->type, tetris->curObj->rot, tetris->curObj->posX, tetris->curObj->posY);
    else
        sprintf(buffer, "F bXY %d %d", tetris->width, tetris->height);
    return buffer;
}

void startTetris(TETRIS* tetris, void (*work)(void*)) {
    if (tetris->running) return;

    tetris->running = true;

    srand((unsigned)time(NULL));

    _beginthread(workTetris, 0, tetris);

    if(work != nullptr)
        work(tetris);
}

void workTetris(void* ptr) {
    TETRIS* tetris = (TETRIS*)ptr;    

    summonObj(tetris);

    while (tetris->running) {
        if (tetris->pause) continue;

        Sleep(tetris->interval);

        if (!isCollisionObjToBottom(tetris))
            (tetris->curObj->posY)++;        
        else {
            objToBlock(tetris);
            if (checkEnd(tetris)) {
                tetris->running = false;
            }
            else {
                reviewAllLine(tetris);
                summonObj(tetris);
            }
        }
    }
    _endthread();
}

void startTetrisOnText(TETRIS* tetris, int interval)
{
    if (!tetris->running) {
        tetris->running = true;
        tetris->interval = interval;
        _beginthread(workTetrisOnText, 0, tetris);

        char key;
        while (tetris->running) {
            if (!_kbhit()) continue;

            key = _getch();
            switch (key) {
            case 75:
                moveObjWithInput(tetris, 0);
                break;
            case 77:
                moveObjWithInput(tetris, 1);
                break;
            case 72:
                rotateObj(tetris, true);
                break;
            case 80:
                moveObjToBtm(tetris);
                break;
            }
            drawBoardOnText(tetris);
        }
    }
}

void workTetrisOnText(void * _tetris)
{
    TETRIS* tetris = (TETRIS*)_tetris;
    summonObj(tetris);

    while (tetris->running) {
        if (tetris->pause) continue;
        
        Sleep(tetris->interval);        
        if (!isCollisionObjToBottom(tetris)) {
            (tetris->curObj->posY)++;
        }
        else {            
            objToBlock(tetris);
            if (checkEnd(tetris)) {
                tetris->running = false;
            } else {
                reviewAllLine(tetris);                
                summonObj(tetris);
            }            
        }
        drawBoardOnText(tetris);
    }
    _endthread();
}

void moveObjToBtm(TETRIS* tetris) {
    OBJECT object = *(tetris->curObj);
    for (int i = 0; i < tetris->height; i++) {
        object.posY = tetris->curObj->posY + i;
        if (isCollisionObjInHere(tetris, object)) {
            tetris->curObj->posY = object.posY - 1;
            objToBlock(tetris);
            break;
        }
    }
}

void moveObjWithInput(TETRIS* tetris, short type)
{
    if (!tetris->curObj->isExist) return;

    switch (type) {
    case 0:
        moveObjToLR(tetris, true);
        break;
    case 1:
        moveObjToLR(tetris, false);
        break;
    case 2:
        rotateObj(tetris,false);
        break;
    case 3:
        rotateObj(tetris,true);
        break;
    }
}

char getRndObj()
{
    return rand()%BLOCK_COUNT;
}

void drawBoardOnText(TETRIS* tetris) {
    for (int i = 0; i < tetris->height; i++) {
        for (int j = 0; j < tetris->width; j++) 
            printf("%s", isBlockInHere(tetris, j, i) > -1 ? "¡á" : "¡à");                 
        printf("\n");
    }
}

char isBlockInHere(TETRIS* tetris, int x, int y) {
    if (tetris->board[y][x].isBlock) {
        return tetris->board[y][x].color;
    }
    else if(tetris->curObj->isExist && isObjBlockInHere(tetris, x, y)) {
        return tetris->curObj->type;
    }
    return -1;
}

bool isObjBlockInHere(TETRIS* tetris, int pX, int pY)
{
    int gapX = pX - tetris->curObj->posX, gapY = pY - tetris->curObj->posY;

    if (gapX < 0 || gapX > 3 || gapY < 0 || gapY > 3) return false;    

    if (objects[tetris->curObj->type][tetris->curObj->rot][gapY][gapX].isBlock) return true;
    
    return false;
}

void summonObj(TETRIS* tetris)
{
    if (tetris->curObj->isExist) return;

    tetris->end = 2;

    tetris->curObj->isExist = 1;
    tetris->curObj->posX = tetris->width / 2 - 2;
    tetris->curObj->posY = tetris->end - 1;
    tetris->curObj->type = getRndObj();
    tetris->curObj->rot = 0;
}

bool isCollisionObjToBottom(TETRIS* tetris)
{
    OBJECT simulateObj = *(tetris->curObj);
    simulateObj.posY++;
    return isCollisionObjInHere(tetris, simulateObj);
}

bool isCollisionObjInHere(TETRIS* tetris, OBJECT object) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {            
            if (objects[object.type][object.rot][i][j].isBlock) {
                if (i + object.posY >= tetris->height
                    || object.posX + j >= tetris->width
                    || tetris->board[object.posY + i][object.posX + j].isBlock) {                    
                    return true;
                }                    
            }
        }
    }
    return false;
}

void objToBlock(TETRIS* tetris) {
    OBJECT* object = tetris->curObj;
    for (int i = 0, y, x; i < 4; i++) {
        y = i + object->posY;
        for (int j = 0; j < 4; j++) {
            x = j + object->posX;
            if (objects[object->type][object->rot][i][j].isBlock) {
                tetris->board[y][x].isBlock = true;
                tetris->board[y][x].color = object->type;
            }
        }
    }
    object->isExist = false;
}

void rotateObj(TETRIS* tetris, bool right) {
    OBJECT simulateObj = *(tetris->curObj);
    if (right) {
        simulateObj.rot = (simulateObj.rot + 1) % 4;        
        if (!isCollisionObjInHere(tetris, simulateObj))
            *(tetris->curObj) = simulateObj;
    }
    else {
        simulateObj.rot--;
        if (simulateObj.rot < 0)
            simulateObj.rot = 3;
        if (!isCollisionObjInHere(tetris, simulateObj))
            *(tetris->curObj) = simulateObj;
    }
}

void moveObjToLR(TETRIS* tetris, bool direction) {
    OBJECT simulateObj = *(tetris->curObj);
    if (direction && simulateObj.posX > 0) {
        simulateObj.posX--;
        if (!isCollisionObjInHere(tetris, simulateObj))
            *(tetris->curObj) = simulateObj;
    }
    else if (!direction){
        simulateObj.posX++;
        if (!isCollisionObjInHere(tetris, simulateObj))
            *(tetris->curObj) = simulateObj;
    }
}

void reviewAllLine(TETRIS* tetris) {
    bool isBlack;
    for (int i = tetris->height - 1; i > 0; i--) {
        isBlack = false;
        for (int j = 0; j < tetris->width; j++) {
            if (!tetris->board[i][j].isBlock)
                isBlack = true;
        }
        if (!isBlack) {
            destoryLine(tetris, i);
            pullLine(tetris, i);
            tetris->score++;
            i--;
        }            
    }
}

void destoryLine(TETRIS* tetris, int line)
{
    for (int j = 0; j < tetris->width; j++)
        tetris->board[line][j].isBlock = false;
}

void pullLine(TETRIS* tetris, int line)
{
    for (int i = line; i > 0; i--) {
        for (int j = 0; j < tetris->width; j++)
            tetris->board[i][j] = tetris->board[i - 1][j];
    }
}

bool checkEnd(TETRIS* tetris) {
    for (int i = 0; i < tetris->width; i++)
        if (tetris->board[tetris->end][i].isBlock)
            return true;
    return false;
}

//FORM

void drawTetrisOnForm(TETRIS* tetris, HDC hdc)
{
    HBRUSH origin, red, orange, yellow, green, purple, blue, skyblue, empty, cur;    
    const int BLOCK = tetris->blockSize;
    
    red = CreateSolidBrush(RGB(255, 0, 0));
    orange = CreateSolidBrush(RGB(255, 94, 0));
    yellow = CreateSolidBrush(RGB(255, 228, 0));
    green = CreateSolidBrush(RGB(0, 255, 0));
    purple = CreateSolidBrush(RGB(217, 65, 197));
    blue = CreateSolidBrush(RGB(0, 0, 255));
    skyblue = CreateSolidBrush(RGB(135, 206, 235));
    empty = CreateSolidBrush(RGB(255, 255, 255));
    cur = empty;

    origin = (HBRUSH)SelectObject(hdc, empty);

    for (int i = 0, h = tetris->height; i < h; i++) {
        for (int j = 0, w = tetris->width; j < w; j++) {
            switch (isBlockInHere(tetris, j, i)) {
            case EMPTY:
                cur = empty;
                break;
            case RED:
                cur = red;
                break;
            case ORANGE:
                cur = orange;
                break;
            case YELLOW:
                cur = yellow;
                break;
            case GREEN:
                cur = green;
                break;
            case PURPLE:
                cur = purple;
                break;
            case BLUE:
                cur = blue;
                break;
            case SKYBLUE:
                cur = skyblue;
                break;
            }
            SelectObject(hdc, cur);
            Rectangle(hdc, BLOCK * j, BLOCK * i, (j + 1) * BLOCK, (i + 1) * BLOCK);
        }
    }


    SelectObject(hdc, origin);
    DeleteObject(red);
    DeleteObject(orange);
    DeleteObject(yellow);
    DeleteObject(green);
    DeleteObject(purple);
    DeleteObject(blue);
    DeleteObject(skyblue);
    DeleteObject(empty);
}