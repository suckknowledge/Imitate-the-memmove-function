#include<stdio.h>
#include<string.h>
#include<assert.h>
//memmove ��Դ�ַ����Ĳ����ַ�������Ŀ���ַ������ҿ��Դ����ڴ��ص�
void *my_memmove(void* a,const void* b, size_t num)//Ϊ��ȷ�������������鴫�ݹ��������Խ��У������β�����Ϊvoid*
{
	void* ret = a;//��Ϊa���п��ܱ仯�ģ���������û��ֱ�ӷ���a
	assert(a && b);
	if (a < b)
	{
		while (num--)
		{
			*(char*)a = *(char*)b;//��Ϊ���޷���ָ�룬���Բ���ֱ�ӽ�����
			a = (char*)a + 1;
			b = (char*)b + 1;//��Ϊ���޷���ָ�룬������Ҫһ���ֽ�һ���ֽڿ��������Բ���ֱ��++
		}
	}
	else
	{
		while (num--)//��һ������num��20
		{
			*((char*)a + num) = *((char*)b + num);//��һ������num��19
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
	my_memmove(arr1+2,arr1,20);//����Ϊ�ֽ�����20���ֽ�Ϊ5������Ԫ��
	printf1(arr1,sz);
	return 0;
}