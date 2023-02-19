#include<stdio.h>
#include<string.h>
#include<assert.h>
//memmove 将源字符串的部分字符拷贝至目标字符串，且可以处理内存重叠
void *my_memmove(void* a,const void* b, size_t num)//为了确保各种类型数组传递过来都可以进行，所以形参类型为void*
{
	void* ret = a;//因为a是有可能变化的，所以这里没有直接返回a
	assert(a && b);
	if (a < b)
	{
		while (num--)
		{
			*(char*)a = *(char*)b;//因为是无符号指针，所以不能直接解引用
			a = (char*)a + 1;
			b = (char*)b + 1;//因为是无符号指针，且我们要一个字节一个字节拷贝，所以不能直接++
		}
	}
	else
	{
		while (num--)//第一次这里num是20
		{
			*((char*)a + num) = *((char*)b + num);//第一次这里num是19
		}
	}
	return ret;
}
void printf1(int* arr, int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	printf1(arr1, sz);
	my_memmove(arr1+2,arr1,20);//数字为字节数，20个字节为5个整型元素
	printf1(arr1,sz);
	return 0;
}