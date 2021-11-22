// @author llxiaoyuan https://github.com/llxiaoyuan/
// https://www.52pojie.cn/forum.php?mod=viewthread&tid=1548533&page=1#pid40756724
// https://www.youtube.com/watch?v=CzjgiVU5bII&t=148s

#include <stdint.h>
#include <stdio.h>

typedef struct _V
{
	int32_t v : 1;
}V;

V table[4][5] =
{
	{0,0},
	{0,1},
	{1,0},
	{1,1}
};

int good(int C1, int C2, int C3, int C4, int C5)
{
	for (size_t row = 0; row < 4; row++) {
		int sum = 0;
		sum += C1 * table[row][0].v;
		sum += C2 * table[row][1].v;
		sum += C3 * table[row][2].v;
		sum += C4 * table[row][3].v;
		sum += C5 * table[row][4].v;
		if (sum != 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	for (size_t row = 0; row < 4; row++)
	{
		table[row][2].v = table[row][0].v ^ table[row][1].v;
		table[row][3].v = table[row][0].v | ~table[row][1].v;
		table[row][4].v = 1;
	}

	/*
	0 0 0 1 1
	0 1 1 0 1
	1 0 1 1 1
	1 1 0 1 1
	*/

	//for (size_t row = 0; row < 4; row++)
	//{
	//	for (size_t col = 0; col < 5; col++)
	//	{
	//		printf("%d ", table[row][col].v);
	//	}
	//	printf("\n");
	//}

	//if (good(1, -1, -1, -2, 2)) {
	//	printf("%d %d %d %d %d\n", 1, -1, -1, -2, -2);
	//}

	for (int C1 = -10; C1 < 10; C1++) {
		for (int C2 = -10; C2 < 10; C2++) {
			for (int C3 = -10; C3 < 10; C3++) {
				for (int C4 = -10; C4 < 10; C4++) {
					for (int C5 = -10; C5 < 10; C5++) {
						//printf("%08d %08d %08d %08d %08d\n", C1, C2, C3, C4, -C5);
						if (good(C1, C2, C3, C4, C5)) {
							//printf("%08d %08d %08d %08d %08d\n", C1, C2, C3, C4, -C5);
							printf("(((%d * x) + (%d * y) + (%d * (x ^ y)) + (%d * (x | ~y)) + (%d)) == 0) &&\n", C1, C2, C3, C4, -C5);
						}
					}
				}
			}
		}
	}

	for (int x = -1000; x < 1000; x++) {
		for (int y = -1000; y < 1000; y++) {
			if (!(
				(((-4 * x) + (4 * y) + (4 * (x ^ y)) + (8 * (x | ~y)) + (8)) == 0) &&
				(((-3 * x) + (3 * y) + (3 * (x ^ y)) + (6 * (x | ~y)) + (6)) == 0) &&
				(((-2 * x) + (2 * y) + (2 * (x ^ y)) + (4 * (x | ~y)) + (4)) == 0) &&
				(((-1 * x) + (1 * y) + (1 * (x ^ y)) + (2 * (x | ~y)) + (2)) == 0) &&
				(((0 * x) + (0 * y) + (0 * (x ^ y)) + (0 * (x | ~y)) + (0)) == 0) &&
				(((1 * x) + (-1 * y) + (-1 * (x ^ y)) + (-2 * (x | ~y)) + (-2)) == 0) &&
				(((2 * x) + (-2 * y) + (-2 * (x ^ y)) + (-4 * (x | ~y)) + (-4)) == 0) &&
				(((3 * x) + (-3 * y) + (-3 * (x ^ y)) + (-6 * (x | ~y)) + (-6)) == 0) &&
				(((4 * x) + (-4 * y) + (-4 * (x ^ y)) + (-8 * (x | ~y)) + (-8)) == 0)
				))
			{
				printf("error\n");
				getchar();
			}
		}
	}
	printf("good\n");
	return 0;
}

