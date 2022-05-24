#ifndef _O_H_

#define _O_H_

#include <stdbool.h>
#include <Windows.h>

//오목 길이
#define O_LENGTH 15
#define END 5
#define END_C END - 1
#define P_LEN 4
#define BLOCKED -1
//범위
#define InMultiRange(r, c) ((r >= 0 && r < O_LENGTH) && (c >= 0 && c < O_LENGTH))
#define SCORE_END 1000
#define IsEndScore(v) v > SCORE_END
#define SCORE(s, l, t) (s * SCORE_END + l * 100 + t)
//모든 원소 순회하기
#define TRAVEL(innerFn) for(short r = 0; r < O_LENGTH; r++) { \
	for(short c = 0; c < O_LENGTH; c++){ \
		innerFn \
	} \
}
#define OMOK_PORT 3182

//Enum

typedef enum Stone { None = 0, White, Black } Stone;

typedef struct PPOS {
	short x;
	short y;
	short limit;
	short ret;
} POS, *LPPOS;
#define IsStone(v, t) (v == t)
#define Reverse_Stone(v) (v == White ? Black : White)
//Struct

typedef struct tagOmok {
	char p_layer[O_LENGTH][O_LENGTH];
	short p_result[O_LENGTH][O_LENGTH];
	Stone r_layer[O_LENGTH][O_LENGTH];
	bool single;
	bool running;
	bool turn;
	unsigned short time;
	short prevPut[2];

	//Events
	void (*on_log)(const int value);
	void (*on_put)(const short x, const short y, Stone t);
	void (*on_win)(void);
	void (*on_lose)(TCHAR*);
} OMOK, * LPOMOK;


//Methods

LPOMOK create_new_omok();

short count_stone_on_direction(const short x, const short y, const short direction, Stone t);

short getPropScore(const short time, const short x, const short y, Stone t);

bool check_is_end(const short x, const short y, Stone t);

bool put(const short x, const short y, Stone t);

void put_alone(const short x, const short y, Stone t);

void put_user(const short x, const short y);

void put_not_user(const short x, const short y);

void undo_put(const short x, const short y);

void undo_user_put();

void computer();

short o_minmax(LPPOS pos);

short o_max(const short x, const short y, const short time);

short o_min(const short x, const short y, const short time);

bool put_client(const short x, const short y, Stone t, bool e);

Stone check_end_who();

#endif _O_H_