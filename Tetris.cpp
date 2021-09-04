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

    _beginthread(workTetris, 0, tetris);

    if(work != nullptr)
        work(tetris);
}

void workTetris(void* ptr) {
    TETRIS* tetris = (TETRIS*)ptr;

    srand((unsigned)time(NULL));

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

short getRndObj()
{
    return rand()%BLOCK_COUNT;
}

void drawBoardOnText(TETRIS* tetris) {
    for (int i = 0; i < tetris->height; i++) {
        for (int j = 0; j < tetris->width; j++) {
            if (tetris->board[i][j].isBlock) {
                printf("¡á");
            }else if (tetris->curObj->isExist) {
                printf("%s", drawObjInBoardOnText(tetris, j, i) ? "¡á" : "¡à");
            }else {
                printf("¡à");
            }
        }            
        printf("\n");
    }
}

bool drawObjInBoardOnText(TETRIS* tetris, int pX, int pY)
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
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (objects[object->type][object->rot][i][j].isBlock) {
                tetris->board[i + object->posY][j + object->posX].isBlock = true;
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
    if (direction) {
        simulateObj.posX--;
        if (!isCollisionObjInHere(tetris, simulateObj))
            *(tetris->curObj) = simulateObj;
    }
    else {
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