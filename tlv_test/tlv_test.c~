#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tlv_pak{
	int	tag;
	int 	length;
	char 	data[0];
}tlv_pak;



int main(){
	tlv_pak *a;
	int 	a_length = 10;
	a = (tlv_pak *)malloc(sizeof(tlv_pak) + sizeof(char)*a_length);
	a->tag     = 0x0000ffff;
	a->length  = a_length;
	strncpy(a->data, "abcdefghi", 10);
	printf("%d %d %s\n", a->tag, a->length, a->data);
	return 0;
}
