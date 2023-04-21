#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define ERROR -1
#define OK 1

typedef struct HString{
	char *str;
	int len;
}HString;

int Concat_String(HString *s1, HString *s2, HString *s){
	int i, j, s_len;
	if(s)
		free(s->str);
	s_len = s1->len + s2->len;
	if ((s->str = (char *)malloc(sizeof(char) * s_len )) == NULL){
		printf("申请失败\n");
		return ERROR;
	}

	for(i = 0; i < s1->len; i++){
		s->str[i] = s1->str[i];
	}
	for(j = 0; j < s2->len; j++){
		s->str[i + j] = s2->str[j];
	}
	s->str[s_len] = '\0';
	s->len = s_len;
//	free(s1->str);
//	free(s2->str);

	return OK;
}

int main(){
	HString s;
	HString s1 = {"abc", 3};
	HString s2 = {"def", 3};
	Concat_String(&s1, &s2, &s);
	printf("%s\n%d", s.str, s.len);
	free(s.str);
	return 0;
}

