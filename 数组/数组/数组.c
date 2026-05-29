#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include <stdlib.h>
//int main()
//{
//	char arr1[] = "nihao";
//	char arr2[] = "*****";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		system("cls");
//		printf("%s\n", arr2);
//		Sleep(1000);
//	}
//	return 0;
//
//}
int main()
{
	int left = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 7;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	
	int find = 1;
	while(find)
	{
		int mid = left + right/2;
		if (mid > key)
		{
			right = mid - 1;
		}
		else if (mid < key)
		{
			left = mid + 1;
		}
		else if (key == mid)
		{
			printf("你找的数字就是%d", key);
			find = 0;
			break;
		}
	}
}
