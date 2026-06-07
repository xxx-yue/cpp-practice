#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
#include<windows.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("text.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//FILE* fopen(const char* filename, const char* mode);
//int main()
//{
//	FILE* p;
//	p = fopen("mylife.txt", "w");
//	if (p != NULL)
//	{
//		fputs("open example", p);
//		fclose(p);
//		p = NULL;
//	}
//	return 0;
// }

//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int ch;
//	while ((ch = fgetc(p)) != EOF)
//	{
//		putchar(ch);
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char str[] = "byebye fputc\n123";
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		fputc(str[i], p);
//		i++;
//	}
//	
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char ch[50];
//	fgets(ch,50,p );
//	printf("%s", ch);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char ch[20] = "happy puppy";
//	fputs(ch, p);
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int fseek(FILE* stream, long int offset, int origin);
//int main()
//{
//	FILE* p;
//	p = fopen("exeample.txt", "wb");
//	fputs("this is an apple.", p);
//	fseek(p, 9, SEEK_SET);
//	fputs("sam", p);
//	fclose(p);
//	return 0;
//}

//long int ftell(FILE* stream);
//int main()
//{
//	FILE* p;
//	long size;
//	p = fopen("myfile.txt", "rb");
//	if (p == NULL)
//		perror("fopen");
//	else
//	{
//		fseek(p, 0, SEEK_END);
//		size = ftell(p);
//		fclose(p);
//		p = NULL;
//		printf("该文件共有%d个字符\n", size);
//	}
//	return 0;
//}

//int main()
//{
//	FILE* p;
//	p = fopen("myfile1.txt", "rb");
//	fseek(p, 0, SEEK_END);
//	int i =ftell(p);
//	printf("%d\n", i);
//	return 0;
//}

//void remind(FILE* p);
//int main()
//{
//	int n;
//	FILE* p;
//	char buffer[27];
//	p = fopen("myfile1.txt", "w+");
//	for (n = 'a'; n <= 'z'; n++)
//		fputc(n , p);
//	rewind(p);
//	fread(buffer, 1, 26, p);
//	fclose(p);
//	buffer[26] = '\0';
//	printf(buffer );
//	return 0;
//}

//int main()
//{
//	int c;
//	FILE* p = fopen("text.txt", "r");
//	if (!p)
//	{
//		perror("fopen");
//		return EXIT_FAILURE;
//	}
//	while ((c = fgetc(p)) != EOF)
//	{
//		putchar(c);
//	}
//	if (ferror(p))
//	{
//		puts("i/0 error when reading");
//	}
//	else if (feof(p))
//	{
//		puts("end of file reached successfully");
//	}
//	fclose(p);
//	return 0;
//}
//
//enum{size = 5};
//int main()
//{
//	double a[size] = { 1.,2.,3.,4.,5. };
//	FILE* p = fopen("test.bin", "wb");
//	fwrite(a, sizeof * a, size, p);
//	fclose(p);
//	double b[size];
//	p = fopen("test.bin", "rb");
//	size_t ret = fread(b, sizeof * b, size, p);
//	if (ret == size)
//	{
//		puts("array read successfully,contens:");
//			for (int n = 0; n < size; ++n)
//			{
//				printf("%f ", b[n]);
//			}
//	}
//	else
//	{
//		if (feof(p))
//			puts("error reading test.bin : unexpected end of file\n");
//		else if (ferror(p))
//		{
//			perror("error reading test bin");
//		}
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	fputs("abcdef", p);
//	Sleep(10000);
//	printf("开睡");
//	fflush(p);
//	Sleep(10000);
//	printf("睡完了");
//	fclose(p);
//	p = NULL;
//	return 0;
//}

int fputc(int character, FILE* stream);
//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputc('a', p);
//	fputc('b', p);
//	fputc('c', p);
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	for (int i = 'a'; i <= 'z'; i++)
//		fputc(i, p);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int c = fgetc(p);
//		fputc(c, stdout);
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}

int feof(FILE* stream);
int ferror(FILE* stream);
//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int c = fgetc(p);
//		if (c == EOF)
//		{
//			if (feof(p))
//			{
//				printf("1");
//				break;
//			}
//			else if (ferror(p))
//			{
//				printf("2");
//				break;
//			}
//		}
//		fputc(c, stdout);
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int  i = 0;
//	int c = fgetc(p);
//	if (c == EOF)
//	{
//		if (feof(p))
//			printf("读完了");
//		else if (ferror(p))
//			printf("出错了");
//		else
//			fputc(c, stdout);
//	}
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* p = fopen("test,txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("abc\0def", p);
//	fputs("hehe", p);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	char arr1[] = "**************";
//	fgets(arr1, sizeof(arr1), p);
//	char arr2[] = "**************";
//	fgets(arr2, sizeof(arr2), p);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	fclose(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	char arr1[] = "1655********45894\n";
//	fgets(p, sizeof(arr1), arr1);
//	char arr2[] = "**2411451**";
//	fgets(p, sizeof(arr2), arr2);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

int fprintf(FILE* stream, const char* format);

//int main()
//{
//	struct stu a = { "张三",55,65.2 };
//	FILE* p = fopen("test.txt","w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(p, "%s %d %f","张三",55,65.2);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

int fscanf(FILE* stream, const char* format);
//int main()
//{
//	struct stu a = { 0 };
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fscanf(p, "%s %d%f", a.name, (&a.age), (&a.score));
//	fprintf(stdout, "%s %d %f", a.name, a.age, a.score);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

size_t fwrite(const void* ptr, size_t size, size_t count, FILE* pf);
//int main()
//{
//	int data[] = { 1,2,3,4,5 };
//	FILE* pf = fopen("data.bin", "wb");
//	if (pf  == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	if (fwrite(data, sizeof(int), 5, pf) != 5)
//	{
//		perror("fweite");
//		return -2;
//	}
//	fclose(pf);
//	pf = NULL;
//
//}
size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
//int main()
//{
//	int data[5] = { 0 };
//	FILE* pf = fopen("data.bin", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	if (fread(data, sizeof(int), 5, pf) != 5)
//	{
//		perror("fweite");
//		return -2;
//	}
//	fclose(pf);
//	pf = NULL;
//	printf("%d",data[1]);
//	return 0;
//}

int sprintf(char* ptr, const char* format, ...);
struct stu
{
	char name[20];
	int age;
	float score;
};
//int main()
//{
//	struct stu a = { "zhangsan",100,85.5f };
//	char arr[100] = { 0 };
//	sprintf(arr, "%s %d %f", a.name, a.age, a.score);
//	printf("%s ", arr);
//	return 0;
//}

//int main()
//{
//	struct stu a = { 0 };
//	char arr[100] = "zhangsan 100 85.5";
//	sscanf(arr, "%s %d %f", a.name, &a.age, &a.score);
//	printf("%s ", arr);
//	return 0;
//}

//int main()
//{
//	printf("hello world");
//}


//int main()
//{
//	FILE* p = fopen("test.txt", "w+");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("abcdefghi", p);
//	fflush(p);
//	fseek(p, 1, SEEK_SET);
//	int ch = fgetc(p);
//	printf("%c", ch);
//	fseek(p, -1, SEEK_CUR);
//	fputs("hello", p);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

