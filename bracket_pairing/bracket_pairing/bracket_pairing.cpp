/*
 * =====================================================================================
 *
 *       Filename:  bracket_pairing.c
 *
 *    Description:  the programme to solve bracket pairing problem 
 *
 *        Version:  1.0
 *        Created:  08/16/2012 04:41:14 PM
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


void is_fit(char *a, char *stack){
	int i = 0;
	while (*a != '\0'){
		if((*a == '(')||(*a == '[')){
			stack[i] = *a;
			++i;
		}
		else if(*a == ')'){
			if(stack[i-1] == '(')
				--i;
			else{
				stack[i] = *a;
				++i;
			}
		}
		else if(*a == ']'){
			if(stack[i-1] == '[')
				--i;
			else{
				stack[i] =*a;
				++i;
			}
		}
		++a;
	}
	if(i == 0)
		printf("Yes\n");
	else
		printf("No\n");
}