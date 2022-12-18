#include <stdio.h>
#include <stdbool.h>

char tahta[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char sira = 'X';

void tahtayiCiz()
{
    printf(" %c | %c | %c\n", tahta[0][0], tahta[0][1], tahta[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tahta[1][0], tahta[1][1], tahta[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tahta[2][0], tahta[2][1], tahta[2][2]);
}

void hamleyiAl()
{
    int satir, sutun;
    printf("Lütfen satır ve sütun değerlerini (1-3 arası) girin: ");
    scanf("%d%d", &satir, &sutun);

    satir--;
    sutun--;

    if (tahta[satir][sutun] != ' ')
    {
        printf("Bu hücre dolu. Lütfen başka bir hücre seçin.\n");
        hamleyiAl();
    }
    else
        tahta[satir][sutun] = sira;
}

bool kazananVarMi(char c)
{
    for (int i = 0; i < 3; i++)
        if (tahta[i][0] == c && tahta[i][1] == c && tahta[i][2] == c)
            return 1;

    for (int i = 0; i < 3; i++)
        if (tahta[0][i] == c && tahta[1][i] == c && tahta[2][i] == c)
            return 1;

    if (tahta[0][0] == c && tahta[1][1] == c && tahta[2][2] == c)
        return 1;

    if (tahta[0][2] == c && tahta[1][1] == c && tahta[2][0] == c)
        return 1;

    return 0;
}

int main()
{
    while (1)
    {
        tahtayiCiz();
        hamleyiAl();
        if (kazananVarMi(sira))
        {
            printf("%c kazandı!", sira);
            break;
        }
        if (sira == 'X')
            sira = 'O';
        else
            sira = 'X';
    }
    return 0;
}
