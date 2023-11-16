// 学生信息管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 编译环境：Visual C++ 6.0~2022，EasyX_2023大暑版

#include "student_op.h"//学生信息管理系统.h

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>

#define scanf scanf_s

int choice;
pStudentNode studentLinkHead;

void mouseAndKeyboard_one();
void mouseAndKeyboard_two();
void mouseAndKeyboard_two1();
void mouseAndKeyboard_two2();
void mouseAndKeyboard_two1_four();
void mouseAndKeyboard_two2_four();
void mouseAndKeyboard_two4_1(long long int id);
void drawWindows_one();
void drawWindows_two();
void drawString_const_one();
void drawString_const_two(int x1, int y1, int x2, int y2, const char str[]);
//void drawString_const_scan(int x1, int y1, int x2, int y2, const char str[]);
void teachPassword();
void stuPassword();
void drawWindows_two1();
void drawWindows_two2();
void drawWindows_two3();
void drawWindows_two4();
void drawWindows_two5();
void drawWindows_two6();
void drawWindows_two1_four();
void drawWindows_two2_four();
void drawForm(int row, const char headline[]);
void draw_Page_op(int page);
//int page_op(int page);
void printStudent(pStudentNode L, int page, int row, int page_ex,const char str[]);
void showStudent_TWO_1(pStudentNode L, int page, int row,const char str[]);
void showStudent_TWO_2(pStudentNode L, int page, int row, const char str[]);
void showStudent_TWO_1_4(pStudentNode L, int page, int row, const char str[]);
void showStudent_TWO_2_4(pStudentNode L, int page, int row, const char str[]);
long long int drawScan_intNum(int windowWidth, int windowHeight, const char head_str[], const char inter_str[]);
double drawScan_doubleNum(int windowWidth, int windowHeight, const char head_str[], const char inter_str[]);
void drawScan_char(int windowWidth, int windowHeight, const char head_str[], const char inter_str[], char object_str[]);



//以下用于调用处理绘制各主界面
void drawWindows_one() {	//创建基本界面(
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1680, 850);
	loadimage(&img, "../zhongli.jpg");
	putimage(0, 0, &img);
	SetWorkingImage();
	setfillcolor(CYAN);
	solidellipse(1150, 40, 1300, 100);
	solidellipse(1400, 40, 1550, 100);
	drawString_const_one();//调用自定义函数
	mouseAndKeyboard_one();//鼠标操作

	while (true);//_getch();//system("pause");//有了这行输入代码，才可以显示窗口，，所以别删
	
	closegraph();			// 关闭绘图窗口
}
void drawWindows_two() {	//创建基本界面(
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1400, 778);
	loadimage(&img, "../zhongli xiao haidengjie.jpg");
	putimage(270, 20, &img);
	SetWorkingImage();
	int temp = 20,r=75,h=45;
	setfillcolor(GREEN);
	drawString_const_two(20, temp,     220, temp + r, "   显示学生成绩   ");        temp += r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
	//文字居中也可以单独调用程序执行
	setlinecolor(GREEN);
	setlinestyle(PS_DASHDOT,5);
	line(220 + 50, 20, 220 + 50, temp + h + r + 20);
	//分割线
	setlinestyle(PS_SOLID, 5);
	mouseAndKeyboard_two();//鼠标操作

	while (true);//_getch();//system("pause");//有了这行输入代码，才可以显示窗口，，所以别删

	closegraph();			// 关闭绘图窗口
}

//以下用于调用处理第二界面（教师端）内的各选项页
void drawWindows_two1() {
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1680, 850);
	loadimage(&img, "../zhongli dadaliya pojindekexing.jpg");
	putimage(0, 0, &img);
	SetWorkingImage();
	int temp = 20, r = 75, h = 45;
	setfillcolor(LIGHTCYAN);
	drawString_const_two(20, temp, 220, temp + r, "   按班级显示   ");        temp += r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号显示   ");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名显示   ");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩显示");    temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分显示  ");  temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩显示  ");temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
	//文字居中也可以单独调用程序执行
	setlinecolor(LIGHTCYAN);
	setlinestyle(PS_DASHDOT, 5);
	line(220 + 50, 20, 220 + 50, temp + h + r + 20);
	//分割线
	setlinestyle(PS_SOLID, 5);
	mouseAndKeyboard_two1();
}
void drawWindows_two2() {
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1256, 705);
	loadimage(&img, "../zhongli bangwan.png");
	putimage(270, 20, &img);
	SetWorkingImage();
	int temp = 20, r = 75, h = 45;
	setfillcolor(LIGHTCYAN);
	drawString_const_two(20, temp, 220, temp + r, "   按班级查询   ");        temp += r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号查询   ");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名查询   ");      temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩查询");    temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分查询  ");  temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩查询  ");temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
	//文字居中也可以单独调用程序执行
	setlinecolor(LIGHTCYAN);
	setlinestyle(PS_DASHDOT, 5);
	line(220 + 50, 20, 220 + 50, temp + h + r + 20);
	//分割线
	setlinestyle(PS_SOLID, 5);
	mouseAndKeyboard_two2();

}
void drawWindows_two3() {
	//添加 新增
	setfillcolor(WHITE);
	fillroundrect(285, 30, 1650, 820, 25, 25);
	int page = 1;

	int row = 5;

	long long int id = 0;
	pStudentNode newLink = NULL;
	newLink = init(newLink);

	int windowWidth = 500;
	int windowHeight = 100;
	const char head_str[] = "新增学生";
	const char inter_str_id[] = "请输入学号（不填入回车键）";
	id = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str_id);
	printf("%lld---", id);
	outtextxy(760, 420, "---离开此界面需要双击其他按钮！！  ---");

	if (id == 0) {
		ExMessage m;		// 定义消息变量
		double flag = 3;//用来标记页面，避免页面冲突
		while (true)
		{
			// 获取一条鼠标或按键消息
			m = getmessage(EX_MOUSE | EX_KEY);
			//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

			switch (m.message)
			{

			case WM_MOUSEMOVE:
				if (flag == 3) {
					if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

					}
					else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

					}
					else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

					}
					else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
					}
					else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
					}
					else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 620, 220, 695, "      其他操作      ");
					}
					else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 740, 220, 815, "         返回         ");
					}
					else {
						int temp = 20, r = 75, h = 45;
						setfillcolor(GREEN);
						drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
					}
				}

				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					return;
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					return;
				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					return;
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					return;
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					return;
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					return;
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					closegraph();
					flag = 1;
					drawWindows_one();
					//返回
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
				return;	// 按 ESC 键退出程序
			}
		}
		
		return;
		
	}

	search_id(studentLinkHead, newLink, id);

	
	
	if (isEmpty(newLink) == true) {
		outtextxy(760, 260, "---请开始你的操作!  ---");
		
		int clas = 0;
		double mathScore = 0;
		double englishScore = 0;
		double dataHierarchyScore = 0;
		char name[20] = { '\0' };
		const char inter_str_clas[] = "请输入班级（不填入回车键）";
		clas = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str_clas);
		const char inter_str_name[] = "请输入姓名（不填入回车键）";
		drawScan_char(windowWidth, windowHeight, head_str, inter_str_name, name);//void类型，把输入值整合给 name
		const char inter_str_math[] = "请输入高等数学成绩（不填入回车键）";
		mathScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_math);
		const char inter_str_en[] = "请输入英语成绩（不填入回车键）";
		englishScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_en);
		const char inter_str_data[] = "请输入数据结构成绩（不填入回车键）";
		dataHierarchyScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_data);

		double sumScore = mathScore + englishScore + dataHierarchyScore * 1.0;
		double averangeScore = 1.0 * sumScore / 3;

		addStudent(studentLinkHead, id, name, clas, mathScore, englishScore, dataHierarchyScore, averangeScore, sumScore);

		addStudent(newLink, id, name, clas, mathScore, englishScore, dataHierarchyScore, averangeScore, sumScore);
		int page_ex = exploreForm_1(newLink);

		printStudent(newLink, page, row, page_ex, "  新增学生信息  ");

	}
	else {
		settextcolor(RED);//文字颜色
		settextstyle(60, 0, _T("微软雅黑"));//输出文字
		setbkmode(TRANSPARENT);//字体背景色：透明
		outtextxy(760, 360, "---啊哦！  已有此人哦！~~  ---");
			
	}
	destory(newLink);

	ExMessage m;		// 定义消息变量
	double flag = 3;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 3) {
				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 620, 220, 695, "      其他操作      ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 740, 220, 815, "         返回         ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(GREEN);
					drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				return;
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				return;
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				return;
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				return;
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				return;
			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				return;
			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				flag = 1;
				drawWindows_one();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
	return;
}
void drawWindows_two4() {
	//修改
	setfillcolor(WHITE);
	fillroundrect(285, 30, 1650, 820, 25, 25);
	int page = 1;

	int row = 5;

	long long int id = 0;
	pStudentNode newLink = NULL;
	newLink = init(newLink);

	int windowWidth = 500;
	int windowHeight = 100;
	const char head_str[] = "修改学生";
	const char inter_str_id[] = "请输入所修改学生的学号（不填入回车键）";
	id = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str_id);
	//printf("%lld---", id);
	outtextxy(760, 420, "---离开此界面需要双击其他按钮！！  ---");

	if (id == 0) {
		ExMessage m;		// 定义消息变量
		double flag = 3;//用来标记页面，避免页面冲突
		while (true)
		{
			// 获取一条鼠标或按键消息
			m = getmessage(EX_MOUSE | EX_KEY);
			//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

			switch (m.message)
			{

			case WM_MOUSEMOVE:
				if (flag == 3) {
					if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

					}
					else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

					}
					else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

					}
					else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
					}
					else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
					}
					else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 620, 220, 695, "      其他操作      ");
					}
					else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 740, 220, 815, "         返回         ");
					}
					else {
						int temp = 20, r = 75, h = 45;
						setfillcolor(GREEN);
						drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
					}
				}

				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					return;
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					return;
				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					return;
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					return;
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					return;
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					return;
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					closegraph();
					flag = 1;
					drawWindows_one();
					//返回
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
				return;	// 按 ESC 键退出程序
			}
		}

		return;

	}

	search_id(studentLinkHead, newLink, id);



	if (isEmpty(newLink) != true) {
		outtextxy(760, 260, "---请开始你的操作!  ---");
		closegraph();

		initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
		setbkcolor(BROWN);//背景色（支持RGB)
		cleardevice();//将背景色刷新（实际为填涂）到界面
		//这是窗口的基本配置必须放在最前面。。。
		IMAGE img(1256, 705);
		loadimage(&img, "../zhongli qingchen.png");
		putimage(270, 20, &img);
		SetWorkingImage();
		int temp = 20, r = 75, h = 45;
		setfillcolor(LIGHTCYAN);
		drawString_const_two(20, temp, 220, temp + r, "   修改班级   ");        temp += r;
		drawString_const_two(20, temp + h, 220, temp + h + r, "   修改姓名   ");      temp += h + r;
		drawString_const_two(20, temp + h, 220, temp + h + r, "修改高等数学成绩");    temp += h + r;
		drawString_const_two(20, temp + h, 220, temp + h + r, "   修改英语成绩   ");  temp += h + r;
		drawString_const_two(20, temp + h, 220, temp + h + r, "   修改数据结构成绩   ");temp += h + r;
		drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
		//文字居中也可以单独调用程序执行
		setlinecolor(LIGHTCYAN);
		setlinestyle(PS_DASHDOT, 5);
		line(220 + 50, 20, 220 + 50, temp + h + r + 20);
		//分割线
		setlinestyle(PS_SOLID, 5);

		mouseAndKeyboard_two4_1(id);

	}
	else {
		settextcolor(RED);//文字颜色
		settextstyle(60, 0, _T("微软雅黑"));//输出文字
		setbkmode(TRANSPARENT);//字体背景色：透明
		outtextxy(760, 360, "---啊哦！  查无此人哦！~~  ---");

	}
	destory(newLink);

	ExMessage m;		// 定义消息变量
	double flag = 3;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 3) {
				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 620, 220, 695, "      其他操作      ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 740, 220, 815, "         返回         ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(GREEN);
					drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				return;
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				return;
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				return;
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				return;
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				return;
			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				return;
			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				flag = 1;
				drawWindows_one();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
	
	return;
}
void drawWindows_two5() {
	//删除
		setfillcolor(WHITE);
		fillroundrect(285, 30, 1650, 820, 25, 25);
		int page = 1;

		int row = 5;

		long long int id = 0;
		pStudentNode newLink = NULL;
		newLink = init(newLink);

		int windowWidth = 500;
		int windowHeight = 100;
		const char head_str[] = "新增学生";
		const char inter_str_id[] = "请输入学号（不填入回车键）";
		id = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str_id);

		outtextxy(760, 420, "---离开此界面需要双击其他按钮！！  ---");

		if (id == 0) {
			ExMessage m;		// 定义消息变量
			double flag = 3;//用来标记页面，避免页面冲突
			while (true)
			{
				// 获取一条鼠标或按键消息
				m = getmessage(EX_MOUSE | EX_KEY);
				//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

				switch (m.message)
				{

				case WM_MOUSEMOVE:
					if (flag == 3) {
						if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

						}
						else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

						}
						else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

						}
						else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
						}
						else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
						}
						else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 620, 220, 695, "      其他操作      ");
						}
						else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
							setfillcolor(YELLOW);
							drawString_const_two(20, 740, 220, 815, "         返回         ");
						}
						else {
							int temp = 20, r = 75, h = 45;
							setfillcolor(GREEN);
							drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
							drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
						}
					}

					break;
					//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

				case WM_LBUTTONDOWN:

					if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
						return;
					}
					else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
						return;
					}
					else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
						return;
					}
					else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
						return;
					}
					else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
						return;
					}
					else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
						return;
					}
					else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
						closegraph();
						flag = 1;
						drawWindows_one();
						//返回
					}
					break;

				case WM_KEYDOWN:
					if (m.vkcode == VK_ESCAPE)
						closegraph();
					return;	// 按 ESC 键退出程序
				}
			}

			return;

		}

		search_id(studentLinkHead, newLink, id);



		if (isEmpty(newLink) != true) {
			
			deleteStudent(studentLinkHead,id);

			outtextxy(760, 260, "---删除操作成功!  ---");
		}
		else {
			settextcolor(RED);//文字颜色
			settextstyle(60, 0, _T("微软雅黑"));//输出文字
			setbkmode(TRANSPARENT);//字体背景色：透明
			outtextxy(760, 360, "---啊哦！  查无此人哦！~~  ---");

		}
		destory(newLink);

		ExMessage m;		// 定义消息变量
		double flag = 3;//用来标记页面，避免页面冲突
		while (true)
		{
			// 获取一条鼠标或按键消息
			m = getmessage(EX_MOUSE | EX_KEY);
			//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

			switch (m.message)
			{

			case WM_MOUSEMOVE:
				if (flag == 3) {
					if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

					}
					else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

					}
					else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

					}
					else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
					}
					else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
					}
					else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 620, 220, 695, "      其他操作      ");
					}
					else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 740, 220, 815, "         返回         ");
					}
					else {
						int temp = 20, r = 75, h = 45;
						setfillcolor(GREEN);
						drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
					}
				}

				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					return;
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					return;
				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					return;
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					return;
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					return;
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					return;
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					closegraph();
					flag = 1;
					drawWindows_one();
					//返回
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
				return;	// 按 ESC 键退出程序
			}
		}

		return;
}
void drawWindows_two6() {
	//其他操作
	setfillcolor(WHITE);
	fillroundrect(285, 30, 1650, 820, 25, 25);
}

void mouseAndKeyboard_two4_1(long long int id) {

	ExMessage m;		// 定义消息变量
	double flag = 4.1;//用来标记页面，避免页面冲突
	int row = 20;
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);
		int windowWidth = 500;
		int windowHeight = 100;
		const char head_str[] = "新增学生";

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 4.1) {
				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 20, 220, 95, "   修改班级   ");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(YELLOW);
					drawString_const_two(20, 140, 220, 215, "   修改姓名   ");
				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					
					setfillcolor(YELLOW);
					drawString_const_two(20, 260, 220, 335, "修改高等数学成绩");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					
					setfillcolor(YELLOW);
					drawString_const_two(20, 380, 220, 455, "   修改英语成绩   ");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					
					setfillcolor(YELLOW);
					drawString_const_two(20, 500, 220, 575, "   修改数据结构成绩   ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					
					setfillcolor(YELLOW);
					drawString_const_two(20, 620, 220, 695, "         返回         ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(GREEN);
					drawString_const_two(20, temp, 220, temp + r, "   修改班级   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   修改姓名   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "修改高等数学成绩");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   修改英语成绩   ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   修改数据结构成绩   ");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:
			
			
			

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				//班级
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				pStudentNode newLink = NULL;
				newLink = init(newLink);

				int clas = 0;
				const char inter_str_clas[] = "请输入班级（不填入回车键）";
				clas = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str_clas);
				revise_class(studentLinkHead, newLink, id, clas);
				
				int page_ex = exploreForm_1(newLink);
				int page = 1;
				printStudent(newLink, page, row, page_ex, "  修改后的学生信息  ");
				destory(newLink);
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				//姓名
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				pStudentNode newLink = NULL;
				newLink = init(newLink);
				
				char name[20] = { '\0' };
				const char inter_str_name[] = "请输入姓名（不填入回车键）";
				drawScan_char(windowWidth, windowHeight, head_str, inter_str_name, name);//void类型，把输入值整合给 name
				revise_name(studentLinkHead, newLink, id, name);

				int page_ex = exploreForm_1(newLink);
				int page = 1;
				printStudent(newLink, page, row, page_ex, "  修改后的学生信息  ");
				destory(newLink);
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				//高等数学
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				pStudentNode newLink = NULL;
				newLink = init(newLink);

				double mathScore = 0;
				const char inter_str_math[] = "请输入高等数学成绩（不填入回车键）";
				mathScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_math);
				revise_mathScore(studentLinkHead, newLink, id, mathScore);

				int page_ex = exploreForm_1(newLink);
				int page = 1;
				printStudent(newLink, page, row, page_ex, "  修改后的学生信息  ");
				destory(newLink);
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				//英语
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				pStudentNode newLink = NULL;
				newLink = init(newLink);

				double englishScore = 0;
				const char inter_str_en[] = "请输入英语成绩（不填入回车键）";
				englishScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_en);
				revise_englishScore(studentLinkHead, newLink, id, englishScore);

				int page_ex = exploreForm_1(newLink);
				int page = 1;
				printStudent(newLink, page, row, page_ex, "  修改后的学生信息  ");
				destory(newLink);
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				//数据结构
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				pStudentNode newLink = NULL;
				newLink = init(newLink);

				double dataHierarchyScore = 0;
				const char inter_str_data[] = "请输入数据结构成绩（不填入回车键）";
				dataHierarchyScore = drawScan_doubleNum(windowWidth, windowHeight, head_str, inter_str_data);
				revise_dataHierarchyScore(studentLinkHead, newLink, id, dataHierarchyScore);

				int page_ex = exploreForm_1(newLink);
				int page = 1;
				printStudent(newLink, page, row, page_ex, "  修改后的学生信息  ");
				destory(newLink);
			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				closegraph();
				flag = 2;
				drawWindows_two();
			}
			
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
}

//以下用于调用处理绘制第二界面（教师端）下的“按照某科成绩排序（或查询）”内的各选项页
void drawWindows_two1_four() {
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1680, 850);
	loadimage(&img, "../zhongli beiying.jpg");
	putimage(0, 0, &img);
	SetWorkingImage();
	int temp = 20, r = 75, h = 45;
	setfillcolor(LIGHTGRAY);
	drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩显示");        temp += r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩显示   ");  temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩显示");temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
	//文字居中也可以单独调用程序执行
	setlinecolor(LIGHTBLUE);
	setlinestyle(PS_DASHDOT, 5);
	line(220 + 50, 20, 220 + 50, temp + h + r + 20);
	//分割线
	setlinestyle(PS_SOLID, 5);
	mouseAndKeyboard_two1_four();
}
void drawWindows_two2_four() {
	initgraph(1680, 850);	// 创建绘图窗口，大小为 1650x580 像素
	setbkcolor(BROWN);//背景色（支持RGB)
	cleardevice();//将背景色刷新（实际为填涂）到界面
	//这是窗口的基本配置必须放在最前面。。。
	IMAGE img(1248, 770);
	loadimage(&img, "../zhongli tiandongwanxiang.jpg");
	putimage(270, 20, &img);
	SetWorkingImage();
	int temp = 20, r = 75, h = 45;
	setfillcolor(LIGHTGRAY);
	drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩查询");        temp += r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩查询   ");  temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩查询");temp += h + r;
	drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
	//文字居中也可以单独调用程序执行
	setlinecolor(LIGHTBLUE);
	setlinestyle(PS_DASHDOT, 5);
	line(220 + 50, 20, 220 + 50, temp + h + r + 20);
	//分割线
	setlinestyle(PS_SOLID, 5);
	mouseAndKeyboard_two2_four();
}

//以下用于调用处理学生端和教师端
void stuPassword() {

}
void teachPassword() {
	drawWindows_two();
}

//以下用于调用处理显示固定的字符串
void drawString_const_one() {
	char str1[10] = { "教师端"};
	char str2[10] = { "学生端" };
	settextcolor(LIGHTBLUE);//文字颜色
	
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 29;
	f.lfWeight = 6;
	//设置文字样式
	settextstyle(&f);//输出文字
	setbkmode(TRANSPARENT);//字体背景色：透明

	outtextxy(1180, 55, str1);
	outtextxy(1430, 55, str2);
}
void drawString_const_two(int x1, int y1, int x2, int y2, const char str[]) {
	
	//printf_s("%d %d\n", y1, y2);
	fillroundrect(x1, y1, x2, y2, 25, 25);

	settextcolor(LIGHTBLUE);//文字颜色
	
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 25;
	f.lfWeight = 500;

	//设置文字样式
	settextstyle(25,0,_T("微软雅黑"));//输出文字
	setbkmode(TRANSPARENT);//字体背景色：透明

	outtextxy(x1 + 20, y1 + 25, str);
}
void drawString_const_scan(int x1, int y1, int x2, int y2, const char str[]) {

	//printf_s("%d %d\n", y1, y2);
	fillroundrect(x1, y1, x2, y2, 25, 25);

	settextcolor(LIGHTBLUE);//文字颜色

	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 25;
	f.lfWeight = 500;

	//设置文字样式
	settextstyle(25, 0, _T("微软雅黑"));//输出文字
	setbkmode(TRANSPARENT);//字体背景色：透明

	outtextxy(x1 + 20, y1 + 5, str);
}
void drawString_const_page(int x1, int y1, int x2, int y2, const char str[]) {

	//printf_s("%d %d\n", y1, y2);
	
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 3);

	fillroundrect(x1, y1, x2, y2, 25, 25);

	settextcolor(LIGHTBLUE);//文字颜色
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 25;
	f.lfWeight = 500;
	//设置文字样式
	settextstyle(25, 0, _T("微软雅黑"));//输出文字
	setbkmode(TRANSPARENT);//字体背景色：透明

	outtextxy(x1+5, y1 + 2, str);
	
	setlinestyle(PS_SOLID, 5);
}
void drawString_form_headline(int x1, int y1, const char str[]) {
	settextcolor(BLACK);//文字颜色
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 65;
	f.lfWeight = 500;
	//设置文字样式
	settextstyle(25, 0, _T("微软雅黑"));//输出文字
	setbkmode(TRANSPARENT);//字体背景色：透明

	outtextxy(x1, y1, str);
}

//以下用于调用处理各界面的鼠标操作
void mouseAndKeyboard_one() {
	ExMessage m;		// 定义消息变量
	
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		printf_s("坐标(x1,y1)： %d , %d \n", m.x, m.y);

		switch (m.message)
		{
			
			case WM_MOUSEMOVE:
				if (m.x > 1150 && m.y > 40 && m.x<1300 && m.y < 100) {
					setfillcolor(YELLOW);
					solidellipse(1150, 40, 1300, 100);
					drawString_const_one();
					
				}
				else if (m.x > 1400 && m.y > 40 && m.x<1550 && m.y < 100) {
					setfillcolor(YELLOW);
					solidellipse(1400, 40, 1550, 100);
					drawString_const_one();
					
				}
				else {
					setfillcolor(CYAN);
					solidellipse(1150, 40, 1300, 100);
					solidellipse(1400, 40, 1550, 100);
					drawString_const_one();
					
				}
				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:
				if (m.x > 1150 && m.y > 40 && m.x < 1300 && m.y < 100) {
					closegraph();
					teachPassword();
				}
				else if (m.x > 1400 && m.y > 40 && m.x < 1550 && m.y < 100) {
					closegraph();
					stuPassword();
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
					return ;	// 按 ESC 键退出程序
		}
	}
}
void mouseAndKeyboard_two() {
	ExMessage m;		// 定义消息变量
	double flag = 2;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		//printf_s("坐标(x2,y2)： %d , %d \n", m.x, m.y);

		switch (m.message)
		{

			case WM_MOUSEMOVE:
				if (flag == 2) {
					if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 20, 220, 95, "   显示学生成绩   ");

					}
					else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 140, 220, 215, "   查询学生成绩   ");

					}
					else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 260, 220, 335, "录入新的学生成绩");

					}
					else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 380, 220, 455, "修改已有学生成绩");
					}
					else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 500, 220, 575, "   删除学生数据   ");
					}
					else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 620, 220, 695, "      其他操作      ");
					}
					else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
						setfillcolor(YELLOW);
						drawString_const_two(20, 740, 220, 815, "         返回         ");
					}
					else {
						int temp = 20, r = 75, h = 45;
						setfillcolor(GREEN);
						drawString_const_two(20, temp, 220, temp + r, "   显示学生成绩   ");        temp += r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   查询学生成绩   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "录入新的学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "修改已有学生成绩");      temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "   删除学生数据   ");    temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "      其他操作      ");  temp += h + r;
						drawString_const_two(20, temp + h, 220, temp + h + r, "         返回         ");
					}
				}

				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					closegraph();
					flag = 2.1;
					drawWindows_two1();
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					closegraph();
					flag = 2.1;
					drawWindows_two2();
				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					//closegraph();
					flag = 2.3;
					drawWindows_two3();
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					drawWindows_two4();
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					drawWindows_two5();
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					drawWindows_two6();
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					closegraph();
					flag = 1;
					drawWindows_one();
					//返回
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
					return;	// 按 ESC 键退出程序
			}
	}
}
void mouseAndKeyboard_two1() {
	ExMessage m;		// 定义消息变量
	double flag = 2.1;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		//printf_s("坐标(x2.1,y2.1)： %d , %d \n", m.x, m.y);
		
		int row = 20;
		//此处row数据仅作为测试使用
		
		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 2.1) {
				setlinecolor(CYAN);
				setlinestyle(PS_SOLID, 5);

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "   按班级显示   ");
					
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按学号显示   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "   按姓名显示   ");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "按某科成绩显示");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 500, 220, 575, " 按平均分显示  ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 620, 220, 695, " 按总成绩显示  ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 740, 220, 815, "       返回        ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTCYAN);
					drawString_const_two(20, temp, 220, temp + r, "   按班级显示   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号显示   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名显示   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩显示");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分显示  ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩显示  ");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				//int row = exploreForm_2(studentLinkHead) + 1;
				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_class(studentLinkHead);

					showStudent_TWO_1(studentLinkHead, page, row,"   按班级显示   ");
				}
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				
				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_id(studentLinkHead);

					showStudent_TWO_1(studentLinkHead, page, row, "   按学号显示   ");
				}
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				
				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_name(studentLinkHead);

					showStudent_TWO_1(studentLinkHead, page, row, "   按姓名显示   ");
				}
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				flag = 2.14;
				drawWindows_two1_four();
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_averange(studentLinkHead);

					showStudent_TWO_1(studentLinkHead, page, row, " 按平均分显示  ");
				}

			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				
				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_sum(studentLinkHead);

					showStudent_TWO_1(studentLinkHead, page, row, " 按总成绩显示  ");
				}

			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				flag = 2;
				drawWindows_two();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
				return;	// 按 ESC 键退出程序
		}
	}
}
void mouseAndKeyboard_two1_four() {
	ExMessage m;		// 定义消息变量
	double flag = 2.14;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		printf_s("坐标(x2.1.4,y2.1.4)： %d , %d \n", m.x, m.y);

		int row = 20;
		//此处row数据仅作为测试使用

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 2.14) {
				setlinecolor(LIGHTBLUE);
				setlinestyle(PS_SOLID, 5);

				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "按高等数学成绩显示");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按英语成绩显示   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "按数据结构成绩显示");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "          返回           ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTGRAY);
					drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩显示");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩显示   ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩显示");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_math(studentLinkHead);

					showStudent_TWO_1_4(studentLinkHead, page, row, "按高等数学成绩显示");
				}
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_english(studentLinkHead);

					showStudent_TWO_1_4(studentLinkHead, page, row, "   按英语成绩显示   ");
				}
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					showStu_dataHierarchy(studentLinkHead);

					showStudent_TWO_1_4(studentLinkHead, page, row, "按数据结构成绩显示");
				}
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				flag = 2.1;
				drawWindows_two1();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
}
void mouseAndKeyboard_two2() {
	ExMessage m;		// 定义消息变量
	double flag = 2.2;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		printf_s("坐标(x2.2,y2.2)： %d , %d \n", m.x, m.y);

		int row = 20;
		//此处row数据仅作为测试使用

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 2.2) {
				setlinecolor(CYAN);
				setlinestyle(PS_SOLID, 5);
				setfillcolor(WHITE);
				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "   按班级查询   ");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按学号查询   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "   按姓名查询   ");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "按某科成绩查询");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 500, 220, 575, " 按平均分查询  ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 620, 220, 695, " 按总成绩查询  ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 740, 220, 815, "       返回        ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTCYAN);
					drawString_const_two(20, temp, 220, temp + r, "   按班级查询   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩查询");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分查询  ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩查询  ");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					int clas = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按班级搜索";
					const char inter_str[] = "请输入班级（不填入回车键）";
					clas = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_class(studentLinkHead, newLink, clas);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {

						showStudent_TWO_2(newLink, page, row, "   按班级查询   ");

					}
					destory(newLink);
				}
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				// "   按学号查询   "
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);
				
				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					long long int id = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按学号搜索";
					const char inter_str[] = "请输入学号（不填入回车键）";
					id = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_id(studentLinkHead, newLink, id);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "   按学号查询   ");
					}
					destory(newLink);
				}

			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				//"   按姓名查询   "
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					char name[20] = {'\0'};

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按姓名搜索";
					const char inter_str[] = "请输入姓名（不填入回车键）";
					drawScan_char(windowWidth, windowHeight, head_str, inter_str,name);//void类型，把输入值整合给 name

					search_name(studentLinkHead, newLink, name);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "   按姓名查询   ");
					}
					destory(newLink);
				}
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				flag = 2.24;
				drawWindows_two2_four();
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				// " 按平均分查询  "
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					double averangeScore = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按平均分搜索";
					const char inter_str[] = "请输入平均分（不填入回车键）";
					averangeScore = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_averangeScore(studentLinkHead, newLink, averangeScore);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "   按平均分查询   ");
					}
					destory(newLink);
				}

			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				//" 按总成绩  "
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					double sumScore = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按总成绩搜索";
					const char inter_str[] = "请输入总成绩（不填入回车键）";
					sumScore = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_sumScore(studentLinkHead, newLink, sumScore);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "   按总成绩查询   ");
					}
					destory(newLink);
				}

			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				flag = 2;
				drawWindows_two();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
}
void mouseAndKeyboard_two2_four() {
	ExMessage m;		// 定义消息变量
	double flag = 2.24;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		printf_s("坐标(x2.2.4,y2.2.4)： %d , %d \n", m.x, m.y);

		int row = 20;

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 2.24) {
				setlinecolor(LIGHTBLUE);
				setlinestyle(PS_SOLID, 5);
				if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "按高等数学成绩查询");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按英语成绩查询   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "按数据结构成绩查询");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "          返回           ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTGRAY);
					drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩查询");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩查询   ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩查询");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:

			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					double mathScore = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按高等数学成绩搜索";
					const char inter_str[] = "请输入高等数学成绩（不填入回车键）";
					mathScore = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_mathScore(studentLinkHead, newLink, mathScore);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "  按高等数学查询  ");
					}
					destory(newLink);
				}
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					double englishScore = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按英语成绩搜索";
					const char inter_str[] = "请输入英语成绩（不填入回车键）";
					englishScore = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_englishScore(studentLinkHead, newLink, englishScore);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "  按英语成绩查询  ");
					}
					destory(newLink);
				}
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(WHITE);
				fillroundrect(285, 30, 1650, 820, 25, 25);

				int page = 1;
				if (isEmpty(studentLinkHead) == true) {
					settextcolor(RED);//文字颜色
					settextstyle(60, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明
					outtextxy(760, 360, "---啊哦！  数据为 空  ---");
				}
				else {
					double dataHierarchyScore = -1;

					pStudentNode newLink = NULL;
					newLink = init(newLink);

					int windowWidth = 500;
					int windowHeight = 100;
					const char head_str[] = "按数据结构成绩搜索";
					const char inter_str[] = "请输入数据结构成绩（不填入回车键）";
					dataHierarchyScore = drawScan_intNum(windowWidth, windowHeight, head_str, inter_str);

					search_dataHierarchyScore(studentLinkHead, newLink, dataHierarchyScore);

					if (isEmpty(newLink) == true) {

						settextcolor(RED);//文字颜色
						settextstyle(60, 0, _T("微软雅黑"));//输出文字
						setbkmode(TRANSPARENT);//字体背景色：透明
						outtextxy(760, 360, "---啊哦！  数据为 空  ---");

					}
					else {
						showStudent_TWO_2(newLink, page, row, "  按数据结构查询  ");
					}
					destory(newLink);
				}
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				flag = 2.2;
				drawWindows_two2();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
}


/*
void mouseAndKeyboard_two2_class() {
	ExMessage m;		// 定义消息变量
	double flag = 2.21;//用来标记页面，避免页面冲突
	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		printf_s("坐标(x2.2,y2.2)： %d , %d \n", m.x, m.y);

		int row = 20;
		//此处row数据仅作为测试使用

		switch (m.message)
		{

		case WM_MOUSEMOVE:
			if (flag == 2.21) {
				setlinecolor(CYAN);
				setlinestyle(PS_SOLID, 5);
				if (m.x > 340 && m.y > 50 && m.x < 520 && m.y < 90) {
					fillroundrect(285, 30, 1650, 820, 25, 25);
					setfillcolor(LIGHTGREEN);
					drawString_const_scan(340, 50, 520, 90, " 输入班级信息  ");
				}
				else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "   按班级查询   ");
				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按学号查询   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "   按姓名查询   ");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "按某科成绩查询");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 500, 220, 575, " 按平均分查询  ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 620, 220, 695, " 按总成绩查询  ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 740, 220, 815, "       返回        ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTCYAN);
					drawString_const_two(20, temp, 220, temp + r, "   按班级查询   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩查询");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分查询  ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩查询  ");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
				}
			}

			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:
			if ( true)
			{
				
			}
			else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				//"   按班级查询   "
				return;

			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				// "   按学号查询   "
				return;
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				//"   按姓名查询   "
				return;
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				flag = 2.24;
				drawWindows_two2_four();
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				// " 按平均分查询  "
				return;
			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				//" 按总成绩  "
				return;
			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				flag = 2;
				drawWindows_two();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			return;	// 按 ESC 键退出程序
		}
	}
}
*/

//以下用于调用处理翻页操作
void draw_Page_op(int page) {
	setfillcolor(WHITE);
	drawString_const_page(290, 730, 370, 760, "上一页");
	drawString_const_page(1565, 730, 1645, 760, "下一页");
	drawString_const_page(290, 785, 370, 815,"第     页");
	TCHAR page_op[50];
	_stprintf_s(page_op, _T("%d"),page);
	outtextxy(290+30,785, page_op);
}

//以下用于表格的绘制及输出
void numToStr(long long int num, char str[]) {
	int i = 0, j = 0;
	do
	{
		str[i++] = num % 10 + 48;
		num /= 10;
	} while (num);
	str[i] = '\0';
	for (;j < i / 2;j++)
	{
		str[j] = str[j] + str[i - 1 - j];
		str[i - 1 - j] = str[j] - str[i - 1 - j];
		str[j] = str[j] - str[i - 1 - j];
	}
	
}
void printStudent(pStudentNode L, int page, int row,int page_ex,const char str[]) {//按表格输出
	//pStudentNode qq = L;
	pStudentNode q = L;
	int const_row = 20;//标准满页输出 20 行
	//q = q->next;
	if (page != 0) {
		int i = 0;
		for (i = 1;i <=(page-1)* const_row;i++) {
			q = q->next;
		}
		//printf_s("iiiiiiiiiiiiiiiiiiiiiiiiii %d\n", i);
	}
	
	//int page_ex = exploreForm_1(q);//page_ex ：不满页
	
	if (page != page_ex) {
		row = 20;
		drawForm(row,str);
		draw_Page_op(page);

		int h_ini = 428 + 8, r_ini = 90 + 1, h = 137, r = 33, i = 1;
		outtextxy(h_ini, r_ini, "       学号      ");
		outtextxy(h_ini + h, r_ini, "      姓名      ");
		outtextxy(h_ini + h * 2, r_ini, "      班级      ");
		outtextxy(h_ini + h * 3, r_ini, "   高数成绩   ");
		outtextxy(h_ini + h * 4, r_ini, "   英语成绩   ");
		outtextxy(h_ini + h * 5, r_ini, "数据结构成绩");
		outtextxy(h_ini + h * 6, r_ini, "    平均分     ");
		outtextxy(h_ini + h * 7, r_ini, "      总分      ");
		for (i = 1;i <= row;i++) {
			r_ini += r;
			q = q->next;
			if (q == NULL) {
				break;
			}
			// 输出数值 id，先将数字格式化输出为字符串（自适应字符集）
			char id[100];
			//printf_s("%lld~~", q->id);
			numToStr(q->id, id);
			//_itoa_s(q->id, id, 10);
			//printf_s("%s****", id);
			//_stprintf_s(id, _T("%ld"), q->id);		// 高版本 VC 推荐使用 _stprintf_s 函数
			//TCHAR name[50];
			//_stprintf_s(name, _T("%d"), q->name);
			TCHAR clas[50];
			_stprintf_s(clas, _T("%d"), q->clas);
			TCHAR mathScore[50];
			_stprintf_s(mathScore, _T("%lf"), q->mathScore);
			TCHAR englishScore[50];
			_stprintf_s(englishScore, _T("%lf"), q->englishScore);
			TCHAR dataHierarchyScore[50];
			_stprintf_s(dataHierarchyScore, _T("%lf"), q->dataHierarchyScore);
			TCHAR averangeScore[50];
			_stprintf_s(averangeScore, _T("%lf"), q->averangeScore);
			TCHAR sumScore[50];
			_stprintf_s(sumScore, _T("%lf"), q->sumScore);

			outtextxy(h_ini, r_ini,id);
			outtextxy(h_ini + h, r_ini, q->name);
			outtextxy(h_ini + h * 2, r_ini, clas);
			outtextxy(h_ini + h * 3, r_ini, mathScore);
			outtextxy(h_ini + h * 4, r_ini, englishScore);
			outtextxy(h_ini + h * 5, r_ini, dataHierarchyScore);
			outtextxy(h_ini + h * 6, r_ini, averangeScore);
			outtextxy(h_ini + h * 7, r_ini, sumScore);
		}

	}
	else {
		row = exploreForm_2(q);	
		//printf_s("rowwwwwwwwwwwwwwwwwwwwwwwwwww:%d\n", row);
		drawForm(row,str);
		draw_Page_op(page);

		int h_ini = 428 + 8, r_ini = 90 + 1, h = 137, r = 33, i = 1;
		outtextxy(h_ini, r_ini, "       学号      ");
		outtextxy(h_ini + h, r_ini, "      姓名      ");
		outtextxy(h_ini + h * 2, r_ini, "      班级      ");
		outtextxy(h_ini + h * 3, r_ini, "   高数成绩   ");
		outtextxy(h_ini + h * 4, r_ini, "   英语成绩   ");
		outtextxy(h_ini + h * 5, r_ini, "数据结构成绩");
		outtextxy(h_ini + h * 6, r_ini, "    平均分     ");
		outtextxy(h_ini + h * 7, r_ini, "      总分      ");
		while(q!=NULL) {
			r_ini += r;
			q = q->next;
			if (q == NULL) {
				break;
			}

			//printf_s("000000000000000000000");
			
			// 输出数值 id，先将数字格式化输出为字符串（自适应字符集）
			char id[100];
			//printf_s("%lld~~", q->id);
			numToStr(q->id, id);
			//_itoa_s(q->id, id, 10);
			//printf_s("%s****", id);

			//_stprintf_s(id, _T("%lld"), q->id);		// 高版本 VC 推荐使用 _stprintf_s 函数
			//TCHAR name[50];
			//_stprintf_s(name, _T("%d"), q->name);
			TCHAR clas[50];
			_stprintf_s(clas, _T("%d"), q->clas);
			TCHAR mathScore[50];
			_stprintf_s(mathScore, _T("%lf"), q->mathScore);
			TCHAR englishScore[50];
			_stprintf_s(englishScore, _T("%lf"), q->englishScore);
			TCHAR dataHierarchyScore[50];
			_stprintf_s(dataHierarchyScore, _T("%lf"), q->dataHierarchyScore);
			TCHAR averangeScore[50];
			_stprintf_s(averangeScore, _T("%lf"), q->averangeScore);
			TCHAR sumScore[50];
			_stprintf_s(sumScore, _T("%lf"), q->sumScore);

			outtextxy(h_ini, r_ini,id);
			outtextxy(h_ini + h, r_ini, q->name);
			outtextxy(h_ini + h * 2, r_ini, clas);
			outtextxy(h_ini + h * 3, r_ini, mathScore);
			outtextxy(h_ini + h * 4, r_ini, englishScore);
			outtextxy(h_ini + h * 5, r_ini, dataHierarchyScore);
			outtextxy(h_ini + h * 6, r_ini, averangeScore);
			outtextxy(h_ini + h * 7, r_ini, sumScore);
			

		}


	}

}
void showStudent_TWO_1(pStudentNode L, int page, int row, const char str[])
{

	int pageSUM = exploreSum(studentLinkHead);
	int page_ex = exploreForm_1(studentLinkHead);//page_ex ：不满页
	while (true) {

		if (isEmpty(L) == true) {
			//outtextxy(680, 1150, "---啊哦！  数据为 空  ---");
			return;
		}
		setfillcolor(WHITE);
		fillroundrect(285, 30, 1650, 820, 25, 25);

		//printf_s("psummmmmmmmmmmmmmmm:%d~~~当前page %d\n", pageSUM,page);

		if (page < 1) {
			page = 1;
		}
		else if (page > pageSUM) {
			page = pageSUM;
		}
		printStudent(L, page, row, page_ex, str);

		//printf_s("ppppppppppppppp:%d\n", page);

		ExMessage m;		// 定义消息变量
		//double flag = 2.1;//用来标记页面，避免页面冲突

			// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{

		case WM_MOUSEMOVE:

			setlinecolor(CYAN);
			setlinestyle(PS_SOLID, 5);
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(290, 730, 370, 760, "上一页");
				setlinestyle(PS_SOLID, 5);

				fillroundrect(290, 730, 370, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(290 + 5, 730 + 2, "上一页");

				setlinestyle(PS_SOLID, 5);

			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(1565, 730, 1645, 760, "下一页");
				setlinestyle(PS_SOLID, 3);

				fillroundrect(1565, 730, 1645, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(1565 + 5, 730 + 2, "下一页");

				setlinestyle(PS_SOLID, 5);
			}
			else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 20, 220, 95, "   按班级显示   ");

			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 140, 220, 215, "   按学号显示   ");

			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 260, 220, 335, "   按姓名显示   ");
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 380, 220, 455, "按某科成绩显示");
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 500, 220, 575, " 按平均分显示  ");
			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 620, 220, 695, " 按总成绩显示  ");
			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 740, 220, 815, "       返回        ");
			}
			else {
				int temp = 20, r = 75, h = 45;
				setfillcolor(LIGHTCYAN);
				drawString_const_two(20, temp, 220, temp + r, "   按班级显示   ");        temp += r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号显示   ");      temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名显示   ");      temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩显示");    temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分显示  ");  temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩显示  ");temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
			}


			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				page--;
				//continue;
			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				page++;
				//continue;
			}
			else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				return;

			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				return;

			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				return;

			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				return;
			}
			else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
				return;

			}
			else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
				return;

			}
			else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
				closegraph();
				drawWindows_two();

				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			// 按 ESC 键退出程序
		}
	}

	//return;
}
void showStudent_TWO_2(pStudentNode L, int page, int row,const char str[])
{
	
	int pageSUM = exploreSum(studentLinkHead);
	int page_ex = exploreForm_1(studentLinkHead);//page_ex ：不满页
	while (true) {

			if (isEmpty(L) == true) {
				//outtextxy(680, 1150, "---啊哦！  数据为 空  ---");
				return;
			}
			setfillcolor(WHITE);
			fillroundrect(285, 30, 1650, 820, 25, 25);
			
			//printf_s("psummmmmmmmmmmmmmmm:%d~~~当前page %d\n", pageSUM,page);
			
			if (page < 1) {
				page = 1;
			}
			else if(page > pageSUM) {
				page = pageSUM;
			}
			printStudent(L, page, row, page_ex,str);
			
			//printf_s("ppppppppppppppp:%d\n", page);

			ExMessage m;		// 定义消息变量
			//double flag = 2.1;//用来标记页面，避免页面冲突

				// 获取一条鼠标或按键消息
			m = getmessage(EX_MOUSE | EX_KEY);

			switch (m.message)
			{

			case WM_MOUSEMOVE:

				setlinecolor(CYAN);
				setlinestyle(PS_SOLID, 5);
				if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
					setlinecolor(GREEN);
					//drawString_const_page(290, 730, 370, 760, "上一页");
					setlinestyle(PS_SOLID, 5);

					fillroundrect(290, 730, 370, 760, 25, 25);

					settextcolor(LIGHTBLUE);//文字颜色
					LOGFONT f;
					gettextstyle(&f);
					f.lfHeight = 25;
					f.lfWeight = 500;
					//设置文字样式
					settextstyle(25, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明

					outtextxy(290 + 5, 730 + 2, "上一页");

					setlinestyle(PS_SOLID, 5);

				}
				else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
					setlinecolor(GREEN);
					//drawString_const_page(1565, 730, 1645, 760, "下一页");
					setlinestyle(PS_SOLID, 3);

					fillroundrect(1565, 730, 1645, 760, 25, 25);

					settextcolor(LIGHTBLUE);//文字颜色
					LOGFONT f;
					gettextstyle(&f);
					f.lfHeight = 25;
					f.lfWeight = 500;
					//设置文字样式
					settextstyle(25, 0, _T("微软雅黑"));//输出文字
					setbkmode(TRANSPARENT);//字体背景色：透明

					outtextxy(1565 + 5, 730 + 2, "下一页");

					setlinestyle(PS_SOLID, 5);
				}
				else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 20, 220, 95, "   按班级查询   ");

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 140, 220, 215, "   按学号查询   ");

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 260, 220, 335, "   按姓名查询   ");
				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 380, 220, 455, "按某科成绩查询");
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 500, 220, 575, " 按平均分查询  ");
				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 620, 220, 695, " 按总成绩查询  ");
				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					setfillcolor(LIGHTGREEN);
					drawString_const_two(20, 740, 220, 815, "       返回        ");
				}
				else {
					int temp = 20, r = 75, h = 45;
					setfillcolor(LIGHTCYAN);
					drawString_const_two(20, temp, 220, temp + r, "   按班级查询   ");        temp += r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按学号查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "   按姓名查询   ");      temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "按某科成绩查询");    temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按平均分查询  ");  temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, " 按总成绩查询  ");temp += h + r;
					drawString_const_two(20, temp + h, 220, temp + h + r, "       返回        ");
				}


				break;
				//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

			case WM_LBUTTONDOWN:
				if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
					page--;
					//continue;
				}
				else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
					page++;
					//continue;
				}
				else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
					return;

				}
				else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
					return;

				}
				else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
					return;

				}
				else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
					return;
				}
				else if (m.x > 20 && m.y > 500 && m.x < 220 && m.y < 575) {
					return;

				}
				else if (m.x > 20 && m.y > 620 && m.x < 220 && m.y < 695) {
					return;

				}
				else if (m.x > 20 && m.y > 740 && m.x < 220 && m.y < 815) {
					closegraph();
					drawWindows_two();

					//返回
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					closegraph();
				// 按 ESC 键退出程序
			}
	}
	
	//return;
}
void showStudent_TWO_1_4(pStudentNode L, int page, int row, const char str[])
{

	int pageSUM = exploreSum(studentLinkHead);
	int page_ex = exploreForm_1(studentLinkHead);//page_ex ：不满页
	while (true) {

		if (isEmpty(L) == true) {
			//outtextxy(680, 1150, "---啊哦！  数据为 空  ---");
			return;
		}
		setfillcolor(WHITE);
		fillroundrect(285, 30, 1650, 820, 25, 25);

		//printf_s("psummmmmmmmmmmmmmmm:%d~~~当前page %d\n", pageSUM,page);

		if (page < 1) {
			page = 1;
		}
		else if (page > pageSUM) {
			page = pageSUM;
		}
		printStudent(L, page, row, page_ex, str);

		//printf_s("ppppppppppppppp:%d\n", page);

		ExMessage m;		// 定义消息变量
		//double flag = 2.1;//用来标记页面，避免页面冲突

			// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{

		case WM_MOUSEMOVE:

			setlinecolor(CYAN);
			setlinestyle(PS_SOLID, 5);
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(290, 730, 370, 760, "上一页");
				setlinestyle(PS_SOLID, 5);

				fillroundrect(290, 730, 370, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(290 + 5, 730 + 2, "上一页");

				setlinestyle(PS_SOLID, 5);

			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(1565, 730, 1645, 760, "下一页");
				setlinestyle(PS_SOLID, 3);

				fillroundrect(1565, 730, 1645, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(1565 + 5, 730 + 2, "下一页");

				setlinestyle(PS_SOLID, 5);
			}
			setlinecolor(LIGHTBLUE);
			setlinestyle(PS_SOLID, 5);
			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 20, 220, 95, "按高等数学成绩显示");

			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 140, 220, 215, "   按英语成绩显示   ");

			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 260, 220, 335, "按数据结构成绩显示");
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 380, 220, 455, "          返回           ");
			}
			else {
				int temp = 20, r = 75, h = 45;
				setfillcolor(LIGHTGRAY);
				drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩显示");        temp += r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩显示   ");  temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩显示");temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
			}


			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				page--;
				//continue;
			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				page++;
				//continue;
			}
			else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				return;
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				return;
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				return;
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				drawWindows_two1();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			// 按 ESC 键退出程序
		}
	}

	//return;
}
void showStudent_TWO_2_4(pStudentNode L, int page, int row, const char str[])
{

	int pageSUM = exploreSum(studentLinkHead);
	int page_ex = exploreForm_1(studentLinkHead);//page_ex ：不满页
	while (true) {

		if (isEmpty(L) == true) {
			//outtextxy(680, 1150, "---啊哦！  数据为 空  ---");
			return;
		}
		setfillcolor(WHITE);
		fillroundrect(285, 30, 1650, 820, 25, 25);

		//printf_s("psummmmmmmmmmmmmmmm:%d~~~当前page %d\n", pageSUM,page);

		if (page < 1) {
			page = 1;
		}
		else if (page > pageSUM) {
			page = pageSUM;
		}
		printStudent(L, page, row, page_ex, str);

		//printf_s("ppppppppppppppp:%d\n", page);

		ExMessage m;		// 定义消息变量
		//double flag = 2.1;//用来标记页面，避免页面冲突

			// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{

		case WM_MOUSEMOVE:

			setlinecolor(CYAN);
			setlinestyle(PS_SOLID, 5);
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(290, 730, 370, 760, "上一页");
				setlinestyle(PS_SOLID, 5);

				fillroundrect(290, 730, 370, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(290 + 5, 730 + 2, "上一页");

				setlinestyle(PS_SOLID, 5);

			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				setlinecolor(GREEN);
				//drawString_const_page(1565, 730, 1645, 760, "下一页");
				setlinestyle(PS_SOLID, 3);

				fillroundrect(1565, 730, 1645, 760, 25, 25);

				settextcolor(LIGHTBLUE);//文字颜色
				LOGFONT f;
				gettextstyle(&f);
				f.lfHeight = 25;
				f.lfWeight = 500;
				//设置文字样式
				settextstyle(25, 0, _T("微软雅黑"));//输出文字
				setbkmode(TRANSPARENT);//字体背景色：透明

				outtextxy(1565 + 5, 730 + 2, "下一页");

				setlinestyle(PS_SOLID, 5);
			}
			setlinecolor(LIGHTBLUE);
			setlinestyle(PS_SOLID, 5);
			if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 20, 220, 95, "按高等数学成绩查询");

			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 140, 220, 215, "   按英语成绩查询   ");

			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 260, 220, 335, "按数据结构成绩查询");
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				setfillcolor(LIGHTGREEN);
				drawString_const_two(20, 380, 220, 455, "          返回           ");
			}
			else {
				int temp = 20, r = 75, h = 45;
				setfillcolor(LIGHTGRAY);
				drawString_const_two(20, temp, 220, temp + r, "按高等数学成绩查询");        temp += r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "   按英语成绩查询   ");  temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "按数据结构成绩查询");temp += h + r;
				drawString_const_two(20, temp + h, 220, temp + h + r, "          返回           ");
			}


			break;
			//上面部分实现的是鼠标移动目标后显示高亮（有利于用户快速精准选择目标坐标进行下一步操作）

		case WM_LBUTTONDOWN:
			if (m.x > 290 && m.y > 730 && m.x < 370 && m.y < 760) {
				page--;
				//continue;
			}
			else if (m.x > 1565 && m.y > 730 && m.x < 1645 && m.y < 760) {
				page++;
				//continue;
			}
			else if (m.x > 20 && m.y > 20 && m.x < 220 && m.y < 95) {
				return;
			}
			else if (m.x > 20 && m.y > 140 && m.x < 220 && m.y < 215) {
				return;
			}
			else if (m.x > 20 && m.y > 260 && m.x < 220 && m.y < 335) {
				return;
			}
			else if (m.x > 20 && m.y > 380 && m.x < 220 && m.y < 455) {
				closegraph();
				drawWindows_two1();
				//返回
			}
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				closegraph();
			// 按 ESC 键退出程序
		}
	}

	//return;
}


//以下用于调用处理表格的绘制
void drawForm(int row,const char headline[]) {
	drawString_form_headline(865, 50, headline);//标题输出

	setlinecolor(BLACK);//线条颜色
	setlinestyle(PS_SOLID, 1);//线条形状与粗度
	int h_ini = 428, r_ini = 90, h = 137, r = 33, i = 1;
	line(h_ini-1,r_ini,1524, r_ini);
	for (i = 1;i <= row+1;i++) {
		r_ini += r;
		line(h_ini, r_ini, 1524, r_ini);
	}
	int ii = 9;
	while (ii--) {
		line(h_ini, 90, h_ini, r_ini);
		h_ini += h;
	}
	
}
long long int drawScan_intNum(int windowWidth,int windowHeight,const char head_str[],const char inter_str[]) {
	long long int num=0;

	// 定义字符串缓冲区，并接收用户输入
	char s[10000] = { '\0' };

	int maxScanNum = 30;//最多输入多少

	//InputBox(str, 9, "请输入", "测试", "空", 100, 100, false);
	//输给谁，（最多）输多少，提示什么，窗口提示什么，默认值，宽，高，是否禁止取消
	InputBox(s,maxScanNum,inter_str,head_str,0, windowWidth, windowHeight,false);
	
	// 将用户输入转换为数字
	int i = 0;
	for (i = 0; i < maxScanNum;i++) {
		if ((s[i] < '0' || s[i]>'9') && s[i] != '\0') {
			num = -1;
			break;
		}//非法数值处理
		if (s[i] == '\0')
		{
			break;
		}
		num = num * 10 + (s[i]-'0');
		//先筛条件，再算数据
	}
	//num = atoi(ss);
	//printf_s("%lld", num);
	return num;
}
double drawScan_doubleNum(int windowWidth, int windowHeight, const char head_str[], const char inter_str[]) {
	double num = 0.0;

	// 定义字符串缓冲区，并接收用户输入
	char s[100] = { '\0'};

	int maxScanNum = 30;//最多输入多少

	//InputBox(str, 9, "请输入", "测试", "空", 100, 100, false);
	//输给谁，（最多）输多少，提示什么，窗口提示什么，默认值，宽，高，是否禁止取消
	InputBox(s, maxScanNum, inter_str, head_str, 0, windowWidth, windowHeight, false);

	// 将用户输入转换为数字
	int i = 0;
	for (i = 0; (s[i] != '\0' || i < maxScanNum);i++) {
		
		if (s[i] == '.') {
			break;
		}
		if ((s[i] < '0' || s[i]>'9') && s[i] != '\0') {
			num = -1;
			break;
		}//非法数值处理
		if (s[i] == '\0')
		{
			break;
		}
		num = 1.0 * num * 10 + (s[i] - '0') * 1.0;
		//先筛条件，再算数据
	}
	double j = 0.1;
	for (j = 0.1, i++; (s[i] != '\0' && i < maxScanNum && num != -1);i++) {

		if ((s[i] < '0' || s[i]>'9') && s[i] != '\0') {
			num = -1;
			break;
		}//非法数值处理
		if (s[i] == '\0')
		{
			break;
		}
		num = 1.0 * num + (s[i] - '0') * 1.0 * j;
		j *= 0.1;
		//先筛条件，再算数据
	}
	return num;

}
void drawScan_char(int windowWidth, int windowHeight, const char head_str[], const char inter_str[],char object_str[]) {
	//InputBox();

	int maxScanNum = 50;//最多输入多少

	//InputBox(str, 9, "请输入", "测试", "空", 100, 100, false);
	//输给谁，（最多）输多少，提示什么，窗口提示什么，默认值，宽，高，是否禁止取消
	InputBox(object_str, maxScanNum, inter_str, head_str, 0, windowWidth, windowHeight, false);

}

void main()
{
	
	studentLinkHead = init(studentLinkHead);
	
	drawWindows_one();

	_getch();
	closegraph();

}
