#include <stdio.h>

void day01(void)
{
	printf("a partridge in a pear tree.\n");
	return;
}
void day02(void)
{
	printf("two turtle doves, and ");
	day01();
	return;
}
void day03(void)
{
	printf("three French hens, ");
	day02();
	return;	
}
void day04(void)
{
	printf("four calling birds, ");
	day03();
	return;
}
void day05(void)
{
	printf("FIVE GOLDEN RINGS, ");;
	day04();
	return;
}
void day06(void)
{
	printf("six geese a-laying, ");
	day05();
	return;
}
void day07(void)
{
	printf("seven swans a-swimming, ");
	day06();
	return;
}
void day08(void)
{
	printf("eight maids a-milking, ");
	day07();
	return;
}
void day09(void)
{
	printf("nine ladies dancing, ");
	day08();
	return;
}
void day10(void)
{
	printf("ten lords a-leaping, ");
	day09();
	return;
}
void day11(void)
{
	printf("eleven pipers piping, ");
	day10();
	return;
}
void day12(void)
{
	printf("twelve drummers drumming, ");
	day11();
	return;
}

int main( ) {
	printf("\nOn the first day of Christmas, my true love gave to me\n");
	day01();
	printf("\nOn the second day of Christmas, my true love gave to me\n");
	day02();
	printf("\nOn the third day of Christmas, my true love gave to me\n");
	day03();
	printf("\nOn the fourth day of Christmas, my true love gave to me\n");
	day04();
	printf("\nOn the fifth day of Christmas, my true love gave to me\n");
	day05();
	printf("\nOn the sixth day of Christmas, my true love gave to me\n");
	day06();
	printf("\nOn the seventh day of Christmas, my true love gave to me\n");
	day07();
	printf("\nOn the eighth day of Christmas, my true love gave to me\n");
	day08();
	printf("\nOn the nineth day of Christmas, my true love gave to me\n");
	day09();
	printf("\nOn the tenth day of Christmas, my true love gave to me\n");
	day10();
	printf("\nOn the eleventh day of Christmas, my true love gave to me\n");
	day11();
	printf("\nOn the twelfth day of Christmas, my true love gave to me\n");
	day12();

	return 0;
}