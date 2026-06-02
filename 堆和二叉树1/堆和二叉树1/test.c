#include"Heap.h"
#include<time.h>
void HpTest1()
{
	int a[] = { 8,5,65,98,23,5,7,8,9,10,12,15 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");
}
void HeapTest2()
{
	int a[] = { 25,98,3,56,8555,5,698,0.6 };
	HeapSort(a, 9);
}
void CreatNDate()
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}
void HeapTest3()
{
	int k;
	printf("请输入k的值为:>");
	scanf("%d", &k);
	int* a = (int*)malloc(sizeof(int) * k);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* filename = "data.txt";
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(file, "%d", &a[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}
	int x = 0;
	while (fscanf(file, "%d", &x) > 0)
	{
		if (x > a[0])
		{
			a[0] = x;
			AdjustDown(a, k, 0);
		}
	}
	printf("最大前%d个数:", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//int main()
//{
//	//HpTest1();
//	//HeapTest2();
//	//CreatNDate();
//	//HeapTest3();
//	return 0;
//}
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	return node1;
}
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}
	printf("%d", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void 前Order(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	InOrder(root->left);
	InOrder(root->right);
}
void 后Order(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	InOrder(root->right);
	printf("%d ", root->data);
}
int fun(int n)
{
	if (n == 0)
		return 0;
	return fun(n - 1) + n;
}
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == 0)
//		return 0;
//	else ++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}
//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else ++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}
//
void TreeSize(BTNode* root, int* psize)
{
	if (root == NULL)
		return;
	else ++(*psize);
	TreeSize(root->left, psize);
	TreeSize(root->right, psize);
}
//计算这一颗树有多少叶子
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//计算树的高度有几层
int TreeHeight(BTNode* root)
{
	if (root == 0)
		return 0;
	int rightheight = TreeHeight(root->right);
	int leftheight = TreeHeight(root->left);
	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;//加1是算上了自己这一层
}
//计算第k层有多少叶子
int TreeLevelKSize(BTNode* root, int k)
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}
//二叉树查找值为k的节点
BTNode* TreeFind(BTNode* root, int x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
}
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
#include"Queue.h"
//广度优先遍历
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
//判断二叉树是否是完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}
void InserSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//n个数字需要n-1趟的交换排序,而从0到n-2共有n-1个数字,所以是小于n-1
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end+1] = tmp;
	}
}
int main()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	InserSort(a, 8);
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
}