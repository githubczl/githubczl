#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// 计算模式串的 next 数组
void get_next(char* pattern, int* next) {
    int i = 0, j = -1;
    int len = strlen(pattern);

    next[0] = -1; // next[0] 固定为 -1

    while (i < len) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

// 在文本串中查找模式串，返回第一次出现的位置
int kmp(char* text, char* pattern) {
    int i = 0, j = 0;
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int next[MAX_LEN];

    get_next(pattern, next); // 计算模式串的 next 数组

    while (i < text_len && j < pattern_len) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if (j == pattern_len) { // 找到了
        return i - j;
    }
    else { // 没有找到
        return -1;
    }
}

int main() {
    char text[MAX_LEN], pattern[MAX_LEN];
    int pos;

    printf("请输入文本串：\n");
    scanf("%s", text);

    printf("请输入模式串：\n");
    scanf("%s", pattern);

    pos = kmp(text, pattern);

    if (pos == -1) {
        printf("没有找到模式串！\n");
    }
    else {
        printf("模式串第一次出现的位置为：%d\n", pos);
    }

    return 0;
}

