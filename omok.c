#include "omok.h"

OMOK omok;
short limit_depth;
short limit_result;

const short dx[8] = { 1, -1, -1, 1, 0, 0, 1, -1 };
const short dy[8] = { 1, -1, 1, -1, 1, -1, 0 ,0 };

LPOMOK create_new_omok() {
	omok.time = 0;
	omok.prevPut[0] = omok.prevPut[1] = 0;
	omok.single = true;
	omok.running = true;
	omok.turn = true;
	TRAVEL(
		omok.p_layer[r][c] = 0;
		omok.p_result[r][c] = 0;
		omok.r_layer[r][c] = None;
	);

	return &omok;
}

short count_stone_on_direction(const short x, const short y, const short direction, Stone t) {
	short count = 0;
	for (short _x = x + dx[direction], _y = y + dy[direction];
		InMultiRange(_y, _x); _x += dx[direction], _y += dy[direction]) {
		if (IsStone(omok.r_layer[_y][_x], t))
			count++;
		else
			break;
	}
	return count;
}

bool check_is_end(const short x, const short y, Stone t) {
	for (short d = 0; d < 7; d += 2) {
		if (count_stone_on_direction(x, y, d, t)
			+ count_stone_on_direction(x, y, d + 1, t)
			== END_C)
			return true;
	}
	return false;
}

bool put(const short x, const short y, Stone t) {
	put_alone(x, y, t);

	if (omok.on_put)
		omok.on_put(x, y, t);

	return check_is_end(x, y, t);
}

void put_alone(const short x, const short y, Stone t) {
	omok.time++;
	omok.p_layer[y][x] = BLOCKED;
	for (short d = 0, _x, _y; d < 8; d++) {
		_x = x + dx[d], _y = y + dy[d];
		if (!InMultiRange(_y, _x)) continue;

		switch (omok.p_layer[_y][_x]) {
		case BLOCKED:
			break;
		default:
			omok.p_layer[_y][_x]++;
		}
	}	

	omok.r_layer[y][x] = t;		
}

void undo_put(const short x, const short y) {
	omok.time--;
	omok.p_layer[y][x] = 0;

	for (short d = 0, _x, _y; d < 8; d++) {
		_x = x + dx[d], _y = y + dy[d];
		if (!InMultiRange(_y, _x)) continue;

		switch (omok.p_layer[_y][_x]) {
		case BLOCKED:
			omok.p_layer[y][x]++;
			break;
		default:
			omok.p_layer[_y][_x]--;
		}
	}

	omok.r_layer[y][x] = None;
}

void undo_user_put() {
	if (omok.time > 0 && omok.prevPut[0] != -1) {
		undo_put(omok.prevPut[0], omok.prevPut[1]);
		omok.prevPut[0] = -1, omok.prevPut[1] = -1;
	}		
}

void put_user(const short x, const short y) {
	if (!omok.single && !omok.turn) return;

	omok.prevPut[0] = x, omok.prevPut[1] = y;	
	if (put(x, y, White)) {
		if (omok.on_win)
			omok.on_win();
	}
	else {
		if(omok.single)
			computer();
	}
		
}

void put_client(const short x, const short y, Stone t, bool e) {
	omok.turn = !omok.turn;
	put_alone(x, y, t);	

	if (e) {
		if (omok.on_put)
			omok.on_put(x, y, t);
	}
	return check_is_end(x, y, t);
}

void put_not_user(const short x, const short y) {
	if (put(x, y, Black))
		if (omok.on_lose)
			omok.on_lose(NULL);
}

void computer() {	
	POS pos = { 0, 0, P_LEN, 0 };	
	limit_depth = 0;
	limit_result = 0;

	o_minmax(&pos);
	
	put_not_user(pos.x, pos.y);	
	if (omok.on_log)
		omok.on_log(1000);
}

Stone check_end_who() {
	TRAVEL(
		if (omok.r_layer[r][c] == None) continue;

		if (check_is_end(c, r, omok.r_layer[r][c]))
			return omok.r_layer[r][c];
	);
	return None;
}

short getPropScore(const short time, const short x, const short y, Stone t) {
	short temp_count = 0,
		max_count = 0;

	bool isEnd = false;

	for (short d = 0; d < 7; d += 2) {
		temp_count = count_stone_on_direction(x, y, d, t) + count_stone_on_direction(x, y, d + 1, t);
		
		if (temp_count > max_count)
			max_count = temp_count;

		if (temp_count == END_C)
			isEnd = true;		
	}

	if (isEnd)
		return SCORE(time, max_count, omok.p_layer[y][x] + time);
	return SCORE(0, max_count, omok.p_layer[y][x] + time);
}

short o_max(const short x, const short y, const short time) {
	short ret, best = -32768;		

	ret = getPropScore(time, x, y, White);

	put_alone(x, y, White);

	if (IsEndScore(ret)) {
		limit_depth = time;		
		return -ret;
	}
	if (time == limit_depth)
		return -ret;


	for (short r = 0; r < O_LENGTH; r++) {
		for (short c = 0; c < O_LENGTH; c++) {
			//확률이 존재하는 부분에서만
			if (omok.p_layer[r][c] < 1) continue;

			ret = o_min(c, r, time - 1);

			undo_put(c, r);
			
			if (best < ret)
				best = ret;
		}
	}

	return best;
}

short o_min(const short x, const short y, const short time) {
	short ret, best = 32767;		

	ret = getPropScore(time, x, y, Black);

	put_alone(x, y, Black);

	if (IsEndScore(ret)) {
		limit_depth = time;
		return ret;
	}
	if (time == limit_depth)
		return ret;

	for (short r = 0; r < O_LENGTH; r++) {		
		for (short c = 0; c < O_LENGTH; c++) {
			//확률이 존재하는 부분에서만
			if (omok.p_layer[r][c] < 1) continue;			
			
			ret = o_max(c, r, time - 1);

			undo_put(c, r);

			if (best > ret)
				best = ret;
		}
	}

	return best;
}
//Win Lose - 1000, MAX - 100, TOTAL - 1
short o_minmax(LPPOS pos) {
	short ret, best = -32768;
	
	for (short r = 0; r < O_LENGTH; r++) {
		for (short c = 0; c < O_LENGTH; c++) {
			//확률이 존재하는 부분에서만
			omok.p_result[r][c] = 0;
			if (omok.p_layer[r][c] < 1) continue;				
						
			ret = o_min(c, r, P_LEN);			

			undo_put(c, r);

			//omok.on_log(r * 10000 + c * 100);			
			omok.p_result[r][c] = ret;
						
			if (best < ret) {
				best = ret;	
				pos->x = c;
				pos->y = r;								
			}						
		}
	}	

	return best;
}