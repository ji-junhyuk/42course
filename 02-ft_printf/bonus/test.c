/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junji <junji@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:40:00 by junji             #+#    #+#             */
/*   Updated: 2022/07/30 12:25:18 by jijunhyuk        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

// [flag][너비][정밀도], [va]
// (공백)( 0 )(가변인자)
// len 
// 

#define FLAG_LEFT	0b00000001
#define FLAG_ZERO	0b00000010
#define FLAG_HASH	0b00000100
#define FLAG_SPACE	0b00001000
#define FLAG_PLUS	0b00010000
#define PRECISION	0b00100000
int	main(void)
{
	// 정밀도가 없을 때
	printf("[%+10d]]\n", 789); //[-0000000789]
	printf("[%+10d]]\n", 789); //[-0000000789]

	printf("[%+10d]]\n", 789); //[-0000000789]
	printf("[%0 10d]]\n", -789); //[-0000000789]
	printf("[% 010d]]\n", -789); //[-0000000789]
	printf("[%010d]]\n", -789); //[-0000000789]
	printf("[%+10d]]\n", -789); //[-0000000789]
	printf("[%0+10d]]\n", +789); //[-0000000789]
	printf("[% 10.5d]]\n", +789); //[-0000000789]
	printf("[% 10.5d]]\n", -789); //[-0000000789]
	printf("[%+10.5d]]\n", -789); //[-0000000789]
	printf("[%+-10.5d]]\n", -789); //[-0000000789]
								 // 오른쪽 정렬 폭 맨 앞
								 // 0플래그 들어오면 폭을 정밀도
								 //
	printf("[% 10d]\n", -456); //    [  123]
	printf("[% 10.12d]\n", -456); //    [  123]
	printf("[% 10.11d]\n", -456); //    [  123]
	printf("[%+-10.11d]\n", -456); //    [  123]
	/*
	 * %d 
	 */
	// 1. ' '
	// 	1)0
	printf("[% 5.7d]\n", 123); //    [  123]
	printf("[%+5.7d]\n", 123); //    [  123]
	printf("[%5.7d]\n", 123); //    [  123]
	printf("[%020.7d]\n", 123); //    [  123]
	printf("1.' '\n");
	printf("[% 5d]", 123); //    [  123]
	printf("[% 05d]", 123); //   [ 0123]
	printf("[% 05d]", 123); //   [ 0123]
	printf("[% 06d]", 123); //   [ 00123]
	printf("[% 06.3d]", 123); //   [ 00123] : 정밀도가 있으면 flag 0을 무시한다.
							
	printf("[% 05.07d]", 123); //[ 0000123] 
	printf("[% 05.04d]", 123); //[ 0123]
	// 정밀도가 가장 크다면, 정밀도 만큼 0을 붙여준 뒤 
	// 	2)-
	printf("[%- 5d]", 123); //   [ 123 ]
	printf("[%-  6d]", 123); //  [ 123  ]
						
	// 2. '+'
	//  1) 0
	printf("\n2. +\n");
	printf("[% 05d]", 123); //   [ 0123]
	printf("[%+05d]", 123); //   [+0123]
	printf("[%+05d]", -123); //   [-0123]
							
	//  2) -
	printf("[%+-5d]", 123); //   [+123 ]
	printf("[%+-5.8d]", 123); // [+00000123]
	printf("[%+-5.8d]", -123); // [+00000123]
	printf("[%+-5.9d]", -123); // [+00000123]
	printf("[%+-5.9d]", -1234567890); // [+00000123]
	printf("[%+5.8d]", 123); //  [+00000123]
	printf("[%+5.3d]", 123); //  [ +123]
	printf("[%+05.3d]", 123); // [ +123] 
	printf("[%+-5.3d]", 123); // [+123 ]
//(너비)(정밀도)(가변인자길이)							
//	 ---------------- 필요없어보임: 1. 가변인자 문자열로 받아와서 길이 재기.
//	1. 정밀도(flag로 추가)가 있으면 flag 0을 무시한다. 
//	2. LEFT(-)가 없다면,
//    (space) -> 가변인자, precision있다면 0 -> 너비
//    (+, -) -> 가변인자 -> 너비
//    (0) -> 가변인자 -> 너비
//	3. LEFT(-)가 있다면
//
////	printf("precision test\n");
////	#define test 0b00001000
////	int flag = (1 + 2 + 4 + 8);
////	flag &= ~test;
////	// flag는 7이 나와야함
////	printf("%d\n", flag);
}