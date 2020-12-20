#include <stdio.h>

void towerOfHanoi(int num, char src, char dst, char temp)
{
    if (num < 1)
        return;
    towerOfHanoi(num - 1, src, temp, dst);
    printf("\n 디스크 %d을(를) 막대 %c에서 막대 %c로 옮겨라", num, src, dst);
    towerOfHanoi(num - 1, temp, dst, src);
}

int main()
{
    int num = 4;
    printf("하노이의 탑에서 이동은 다음과 같습니다.\n");
    towerOfHanoi(num, 'A', 'C', 'B');
    return (0);
}