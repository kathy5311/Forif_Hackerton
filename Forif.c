#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input_w(void)
{
    FILE *f0;
    f0 = fopen("hello.txt", "wt"); //hello.txt ���Ͽ� wt(���� = ��½�Ʈ��) ����
    if ( f0 == NULL )
    {
        printf("Fail to open");

        return -1; // �ü���� -1 ��ȯ : �������� ���α׷� ����
    }

    fputs("hello\n", f0);
    fputs("I LOVE", f0);
    fclose(f0); // ��Ʈ�� �Ҹ�

    return 0;
}

int output_r(void)
{
    FILE *f0;
    char str[100];
    f0 = fopen("hello.txt", "rt");
    if ( f0 == NULL )
    {
        printf("Fail to open");
        return -1; // �ü���� -1 ��ȯ : �������� ���α׷� ����
    }

    fgets(str, sizeof(str), f0);
    printf("%s", str);

    fgets(str, sizeof(str), f0);
    printf("%s", str);
    fclose(f0);

    return 0;
}

int pointer_mani(FILE* file)
{
    rewind(file);
    fclose(file);
}