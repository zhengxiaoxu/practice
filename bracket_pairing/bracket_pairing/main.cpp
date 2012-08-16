/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  bracket pairing main function
 *
 *        Version:  1.0
 *        Created:  08/16/2012 08:08:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


extern void is_fit(char *a, char *stack);

char str[5][10000];
char stack[10000];
int main(){
	int a;
	scanf("%d \n", &a);
	int i;
	for(i = 0; i < a; i++){
		scanf("%s", &str[i][0]);
	}
	for(i = 0; i < a; i++)
		is_fit(&str[i][0], stack);
	return 0;
}
