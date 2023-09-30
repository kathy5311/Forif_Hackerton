#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input_w(void)
{
    FILE *f0;
    f0 = fopen("hello.txt", "wt"); //hello.txt 파일에 wt(쓰기 = 출력스트림) 생성
    if ( f0 == NULL )
    {
        printf("Fail to open");

        return -1; // 운영체제에 -1 반환 : 비정상적 프로그램 종료
    }

    fputs("hello\n", f0);
    fputs("I LOVE", f0);
    fclose(f0); // 스트림 소멸

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
        return -1; // 운영체제에 -1 반환 : 비정상적 프로그램 종료
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