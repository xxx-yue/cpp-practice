#include"snake.h "
void SetPos(short x, short y)
{
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);

}
void WelcomeToGame()
{
	SetPos(65, 18);
	printf("欢迎来到贪吃蛇小游戏\n");
	SetPos(65, 30);
	system("pause");
	system("cls");
	SetPos(62, 18);
	printf("用↑↓← →分别控制蛇的移动\n");
	SetPos(65, 20);
	printf("F3为加速    F4为减速\n");
	SetPos(65, 22);
	printf("加速将获得更高的分数\n");
	SetPos(65, 30);
	system("pause");
	system("cls");
}
void CreatMap()
{

	//上
	int i = 0;
	for (i = 0; i <=50; i++)
	{
		wprintf(L"%lc", WALL );
	}
	//下
	SetPos(0, 30);
	for (i = 0; i <=50; i++)
		wprintf(L"%lc", WALL );
	//左
	for (i = 0; i<=30; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL );
	}
	//右
	for (i = 0; i <= 30; i++)
	{
		SetPos(100, i);
		wprintf(L"%lc", WALL );
	}
}
void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake( )::malloc( )");
			return; 
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		//头插法插入链表
		if (ps->_pSnake == NULL)//空链表
		{
			ps->_pSnake = cur;
		}
		else//非空链表
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//设置贪吃蛇属性
	ps->_dir = right;//默认向右走
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//单位是毫秒
	ps->_status = ok;
}
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
	again:
	//生成x是二的倍数
	//x：2/98
	//y：1/29
	do
	{
		x = rand() % 97 + 2;
		y = rand() % 29 + 1;
	} while (x % 2 != 0);
	//x和y的坐标不可以和蛇的身体坐标冲突
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}
	//创建食物的节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood( )::malloc( )");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	SetPos(x, y);//定位位置
	wprintf(L"%lc", FOOD);
	ps->_pFood = pFood;
}
void GameStart(pSnake ps)
{
	//先设置窗口的大小和标题，然后再光标隐藏
	system("mode con cols=156 lines=44");
	system("title 贪吃蛇");
	//0.光标隐藏
	HANDLE houtput  = GetStdHandle(STD_OUTPUT_HANDLE);
	//影藏光标操作
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(houtput, &CursorInfo);//设置控制台光标状态
	//getchar();
	//1.打印欢迎界面
	//2.功能介绍
	WelcomeToGame();
	//3.绘制地图
	CreatMap();
	//4.创建蛇
	InitSnake(ps);
	//5.创建食物
	 CreateFood(ps);
	//6.设置食物的相关信息
}
void PrintfHelpInfo()
{
	SetPos(110, 17);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己");
	SetPos(110, 18);
	wprintf(L"%ls", L"用↑↓← →分别控制蛇的移动");
	SetPos(110, 19);
	wprintf(L"%ls", L"F3为加速    F4为减速");
	SetPos(110, 20);
	wprintf(L"%ls", L"加速将获得更高的分数");
	SetPos(110, 21);
	wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");
}
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}
void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;
	//释放下一个位置的节点
	free(pn);
	pn = NULL;
	//打印蛇
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	//重新创建食物
	CreateFood(ps);
}
void NoFood(pSnakeNode  pn, pSnake ps)
{
	//头插法
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//把最后一个节点打印成空格
	//cur = cur->next;
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	//释放最后一个节点
	free(cur->next);
	//把最后一个节点的指针置为空指针
	cur->next = NULL; //倒数第二个节点的next置空 也就是删除后的最后一个节点的next置空
}
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 100 || ps->_pSnake->y == 0 || ps->_pSnake->y == 30)
	{
		ps->_status = kill_by_wall;
	}
}
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur )
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = kill_by_self;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)
{
	//创建一个节点，表示蛇即将到的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove( )::malloc");
		return;
	}
	//pNextNode->next = NULL;  //没有置空next指针  可以不用的哈
	switch (ps->_dir)
	{
	case up:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case down:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case left:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case right:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	//检测下一个坐标处是否是食物
	if (NextIsFood(pNextNode,ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	//检测蛇是否撞墙
	KillByWall(ps );
	//检测蛇是否撞到自己
	KillBySelf(ps);
}
void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintfHelpInfo();
	do
	{
		//打印总分数和食物的分值
		SetPos(110, 9);
		printf("当前食物分数：%2d\n", ps->_food_weight);
		SetPos(110, 10);
		printf("总分数：%d\n", ps->_score);
		if (KEY_PRESS(VK_UP) && ps->_dir != down)
		{
			ps->_dir = up;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != up)
		{
			ps->_dir = down;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != left)
		{
			ps->_dir = right;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != right)
		{
			ps->_dir = left;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
			//暂停
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->_status = end_normal;
			//正常退出游戏
		}
		
		else if (KEY_PRESS(VK_F3))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->_food_weight>2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
			//减速
		}
		SnakeMove(ps);//蛇走一步的过程
		Sleep(ps->_sleep_time);
		
	} while (ps->_status == ok);
}
void GameEnd(pSnake ps)
{
	SetPos(40, 15);
	switch (ps->_status)
	{
	case end_normal:
		printf("你主动结束了游戏\n");
		break;
	case kill_by_self:
		printf("你撞到了自己,游戏结束\n");
		break;
	case kill_by_wall:
		printf("你撞到了墙上，游戏结束\n");
		break;
	}
	//释放链表
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}