#include<stdlib.h>
#include<stdio.h>

#define MAX_LEN 100
#define ERROR -1
#define OK 1

typedef struct Sqstring{
	char str[MAX_LEN];
	int len;
}SqString;

SqString Concat_String(SqString *s1, SqString *s2){
	SqString s;
	int i, j;
	if(s1->len + s2->len > MAX_LEN)
		exit(1);
	for(i = 0; i < s1->len - 1; i++){
		s.str[i] = s1->str[i];
	}
	for(j = 0; j < s2->len; j++){
		s.str[i + j] = s2->str[j];
	}
	s.len = s1->len + s2->len - 1;
	return s;
}

SqString SubString(SqString s, int pos, int len){
	int i;
	SqString sub;
	if(pos < 1 || pos + len > s.len - 1 || len < 0 || pos > s.len)
		exit(ERROR);
	for(i = 0; i < len; i++){
		sub.str[i] = s.str[pos - 1 + i];
	}
	sub.len = len + 1;
	return sub;
}


int main(){
	SqString s1 = {"abc", 4};
	SqString s2 = {"def", 4};
	SqString s = Concat_String(&s1, &s2);
	printf("%s\n", s.str);
	printf("%d", s.len);

	SqString sub = SubString(s, 1, 3);
	printf("\n%s\n%d", sub.str, sub.len);
	return 0;
}



