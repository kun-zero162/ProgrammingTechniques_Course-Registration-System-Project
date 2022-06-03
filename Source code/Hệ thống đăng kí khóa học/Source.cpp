#include"Header.h"
int z, o;
List_Year lY;
void Menu(List_Account_Staff& l1)
{
	List_Account_Empty_Staff(l1);
	ReadFileAccount_Staff(l1);
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t\t\t\t    WELCOME TO THE COURSE REGISTRATION SYSTEM" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*************************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*\t    ";
	TxtColor(12);
	cout << "I AM AN ACADEMIC STAFF MEMBER";
	TxtColor(11);
	cout << "       *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*\t    I AM A STUDENT                      *" << endl;
	cout << "\t\t\t\t\t*************************************************" << endl;
	cout << endl << endl;
	GoToXY(45, 22);
	cout << "E            : EXIT   ";
	GoToXY(45, 23);
	cout << "ENTER        : CHOOSE";
	GoToXY(45, 24);
	cout << "W, UP ARROW  : UP";
	GoToXY(45, 25);
	cout << "S, DOWN ARROW: DOWN";
	int x = SelectMenu();
	ProcessMenu(x, l1);
}
void TxtColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void GoToXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Day System_date()
{
	Day d;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	d.month = 1 + newtime.tm_mon;
	d.day = newtime.tm_mday;
	d.year = 1900 + newtime.tm_year;
	return d;
}
void List_Account_Empty_Staff(List_Account_Staff& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}
Node* CreateNode(Account x)
{
	Node* p = new Node;
	p->a = x;
	p->Next = NULL;
	return p;
}
void Add_Tail_Staff(List_Account_Staff& l, Node* p)
{
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else
	{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
void ReadFileAccount_Staff(List_Account_Staff& l)
{
	ifstream myfile;
	myfile.open("AccountStaff.csv", ios::in);
	string line;
	getline(myfile, line);
	while (myfile.good())
	{
		Account x;
		getline(myfile, x.name, ',');
		getline(myfile, x.pass, '\n');
		Node* p = CreateNode(x);
		Add_Tail_Staff(l, p);
	}
}
void List_Student_Empty(List_Student& l) {
	l.SHead = NULL;
	l.STail = NULL;
}
Node_Student* Create(Student s)
{
	Node_Student* p = new Node_Student;
	p->a = s;
	p->pNext = NULL;
	p->pNextCourse = new Node_Student * [100];
	p->n = -1;
	return p;
}
void AddTailClass(List_Student& l, Node_Student* p)
{
	if (l.SHead == NULL)
	{
		l.SHead = p;
		l.STail = p;
	}
	else
	{
		l.STail->pNext = p;
		l.STail = p;
	}
}
void AddTailCourse(Node_Semester*& S, Node_Course*& C, List_Student& l, Node_Student* p, int STT)
{
	p->n = STT;
	if (l.SHead == NULL)
	{
		p->pNextCourse[p->n] = NULL;
		l.SHead = p;
		l.STail = p;
	}
	else
	{
		int stt = -1;
		Node_Course_Signed* temp = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			temp = l.STail->a.l1.CHead;
			while (temp != NULL)
			{
				if (temp->C.NameCourse == C->c.NameCourse)
				{
					stt = temp->stt;
					break;
				}
				temp = temp->CNext;
			}
			p->pNextCourse[p->n] = NULL;
			l.STail->pNextCourse[stt] = p;
			l.STail = p;
			break;
		case 2:
			temp = l.STail->a.l2.CHead;
			while (temp != NULL)
			{
				if (temp->C.NameCourse == C->c.NameCourse)
				{
					stt = temp->stt;
					break;
				}
				temp = temp->CNext;
			}
			p->pNextCourse[p->n] = NULL;
			l.STail->pNextCourse[stt] = p;
			l.STail = p;
			break;
		case 3:
			temp = l.STail->a.l3.CHead;
			while (temp != NULL)
			{
				if (temp->C.NameCourse == C->c.NameCourse)
				{
					stt = temp->stt;
					break;
				}
				temp = temp->CNext;
			}
			p->pNextCourse[p->n] = NULL;
			l.STail->pNextCourse[stt] = p;
			l.STail = p;
			break;
		}
	}
}
void List_Class_Empty(List_Class& l)
{
	l.CHead = NULL;
	l.CTail = NULL;
}
Node_Class* Create(Class c)
{
	Node_Class* p = new Node_Class;
	p->c = c;
	p->CNext = NULL;
	return p;
}
void AddHead(List_Class& l, Node_Class* p)
{
	if (l.CHead == NULL)
	{
		l.CHead = p;
		l.CTail = p;
	}
	else
	{
		p->CNext = l.CHead;
		l.CHead = p;
	}
}
void List_Course_Empty(List_Course& lC)
{
	lC.CHead = NULL;
	lC.CTail = NULL;
}
Node_Course* Create_Course(Course c)
{
	Node_Course* p = new Node_Course;
	p->c = c;
	p->CNext = NULL;
	return p;
}
void AddTail_Course(List_Course& lC, Node_Course*& p)
{
	if (lC.CHead == NULL)
	{
		lC.CHead = p;
		lC.CTail = p;
	}
	else
	{
		lC.CTail->CNext = p;
		lC.CTail = p;
	}
}
void List_Semester_Empty(List_Semester& l)
{
	l.SHead = NULL;
	l.STail = NULL;
}
Node_Semester* Create(Semester s)
{
	Node_Semester* p = new Node_Semester;
	p->s = s;
	p->Next = NULL;
	return p;
}
void AddTail_Semester(List_Semester& l, Node_Semester* p)
{
	if (l.SHead == NULL)
	{
		l.SHead = p;
		l.STail = p;
	}
	else
	{
		l.STail->Next = p;
		l.STail = p;
	}
}
void List_Year_Empty(List_Year& l)
{
	l.YHead = NULL;
	l.YTail = NULL;
}
Node_Year* Create(Year y)
{
	Node_Year* p = new Node_Year;
	p->y = y;
	p->yNext = NULL;
	return p;
}
void AddHead_Year(List_Year& l, Node_Year*& p)
{
	if (l.YHead == NULL)
	{
		l.YHead = p;
		l.YTail = p;
	}
	else
	{
		p->yNext = l.YHead;
		l.YHead = p;
	}
}
bool Login_Staff(List_Account_Staff& l, Account x)
{
	bool kt = false;
	Node* temp = l.Head;
	while (temp != NULL)
	{
		if (temp->a.name == x.name && temp->a.pass == x.pass)
		{
			kt = true;
			break;
		}
		temp = temp->Next;
	}
	return kt;
}
void PrintMenu(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(52, 19);
		TxtColor(11);
		cout << "I AM A STUDENT";
		GoToXY(52, 18);
		TxtColor(12);
		cout << "I AM AN ACADEMIC STAFF MEMBER";
		GoToXY(0, 20);
		break;
	case 2:
		GoToXY(52, 18);
		TxtColor(11);
		cout << "I AM AN ACADEMIC STAFF MEMBER";
		GoToXY(52, 19);
		TxtColor(12);
		cout << "I AM A STUDENT";
		GoToXY(0, 20);
		break;
	}
}
int SelectMenu()
{
	int selection = 1;
	while (1)
	{
		PrintMenu(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			switch (selection)
			{
			case 1:
				selection++;
				break;
			case 2:
				selection = 1;
				break;
			}
		}
		if (move == 'W' || move == 72)
		{
			switch (selection)
			{
			case 1:
				selection = 2;
				break;
			case 2:
				selection--;
				break;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'E')
		{
			exit(0);
		}
	}
}
void ProcessMenu(int choose, List_Account_Staff& l1)
{
	switch (choose)
	{
	case 1:
		system("cls");
		TxtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t\t\t\tWELCOME TO THE COURSE REGISTRATION SYSTEM" << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t*                ";
		TxtColor(12);
		cout << "LOG IN";
		TxtColor(11);
		cout << "                  *" << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		cout << endl << endl;
		GoToXY(45, 22);
		cout << "A            : BACK   ";
		GoToXY(45, 23);
		cout << "ENTER        : CHOOSE";
		GoToXY(45, 24);
		cout << "W, UP ARROW  : UP";
		GoToXY(45, 25);
		cout << "S, DOWN ARROW: DOWN";
		GoToXY(0, 30);
		SelectMenu_Login(choose, l1);
		break;
	case 2:
		MenuSelectSchoolYear(lY);
		break;
	}
}
void MenuSelectSchoolYear(List_Year& lY)
{
	system("cls");
	Node_Year* temp = lY.YHead;
	if (temp == NULL)
	{
		TxtColor(12);
		GoToXY(15, 3);
		cout << "YOU HAVEN'T CREATED ANY SCHOOL YEAR YET.PLEASE CREATE A NEW SCHOOL YEAR BEFORE LOGIN" << endl;
		GoToXY(15, 4); system("pause");
		Menu(l1);
	}
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\t\tCHOOSE YOUR SCHOOL YEARS" << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	while (temp != NULL)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t*              ";
		TxtColor(11);
		cout << temp->y.start << "-" << temp->y.end;
		TxtColor(11);
		cout << "               *" << endl;
		temp = temp->yNext;
	}
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectMenu_SelectSchoolYear();
	ProcessMenuSelectSchoolYear(y);
}
void PrintMenuSelectSchoolYear(int selection)
{
	int dem = 1;
	int i = 18;
	Node_Year* temp = lY.YHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			GoToXY(55, i);
			TxtColor(12);
			cout << temp->y.start << "-" << temp->y.end;
			i++;
			dem++;
			temp = temp->yNext;
		}
		else
		{
			GoToXY(55, i);
			TxtColor(11);
			cout << temp->y.start << "-" << temp->y.end;
			temp = temp->yNext;
			i++;
			dem++;
		}
	}
	GoToXY(0, 24);
}
int SelectMenu_SelectSchoolYear()
{
	int n = CountNode(lY);
	int selection = 1;
	while (1)
	{
		PrintMenuSelectSchoolYear(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
		{
			return selection;
		}
		if (move == 'A')
		{
			Menu(l1);
		}
	}
}
void ProcessMenuSelectSchoolYear(int selection)
{
	int dem = 1;
	Node_Year* temp = lY.YHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			MenuSelectClass(temp);
			break;
		}
		dem++;
		temp = temp->yNext;
	}
}
void MenuSelectClass(Node_Year*& p)
{
	system("cls");
	Node_Class* temp = p->y.l.CHead;
	if (temp == NULL)
	{
		TxtColor(12);
		GoToXY(15, 3);
		cout << "YOU HAVEN'T CREATED ANY CLASS YET.PLEASE CREATE A NEW CLASS BEFORE LOGIN" << endl;
		GoToXY(15, 4); system("pause");
		Menu(l1);
	}
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\t\tCHOOSE YOUR CLASS" << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	while (temp != NULL)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t*                 ";
		TxtColor(11);
		cout << temp->c.Name_Class;
		TxtColor(11);
		cout << "               *" << endl;
		temp = temp->CNext;
	}
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectMenu_SelectClass(p);
	ProcessMenuSelectClass(y, p);
}
void PrintMenuSelectClass(int selection, Node_Year*& Y)
{
	int n = CountNode_Class(Y->y.l);
	int dem = 1;
	int i = 18;
	Node_Class* temp = Y->y.l.CHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			GoToXY(58, i);
			TxtColor(12);
			cout << temp->c.Name_Class;
			i++;
			dem++;
			temp = temp->CNext;
		}
		else
		{
			GoToXY(58, i);
			TxtColor(11);
			cout << temp->c.Name_Class;
			temp = temp->CNext;
			i++;
			dem++;
		}
	}
	GoToXY(0, 24);
}
int SelectMenu_SelectClass(Node_Year*& Y)
{
	int n = CountNode_Class(Y->y.l);
	int selection = 1;
	while (1)
	{
		PrintMenuSelectClass(selection, Y);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n;
			}
			else
				selection--;
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuSelectSchoolYear(lY);
		}
	}
}
void ProcessMenuSelectClass(int selection, Node_Year*& Y)
{
	int dem = 1;
	Node_Class* temp = Y->y.l.CHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			if (temp->c.ls.SHead == NULL)
			{
				system("cls");
				TxtColor(12);
				GoToXY(15, 3);
				cout << "YOU HAVEN'T ADD ANY STUDENT TO CLASS YET.PLEASE ADD STUDENT TO CLASS BEFORE LOGIN" << endl;
				GoToXY(15, 4); system("pause");
				MenuSelectClass(Y);
				break;
			}
			MenuLoginStudent(Y, temp);
			break;
		}
		dem++;
		temp = temp->CNext;
	}
}
void MenuLoginStudent(Node_Year*& y, Node_Class*& c)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t\t\t\tWELCOME TO THE COURSE REGISTRATION SYSTEM" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*                ";
	TxtColor(12);
	cout << "LOG IN";
	TxtColor(11);
	cout << "                  *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	cout << endl << endl;
	GoToXY(45, 22);
	cout << "A            : BACK   ";
	GoToXY(45, 23);
	cout << "ENTER        : CHOOSE";
	GoToXY(45, 24);
	cout << "W, UP ARROW  : UP";
	GoToXY(45, 25);
	cout << "S, DOWN ARROW: DOWN";
	GoToXY(0, 30);
	SelectMenuLoginStudent(y, c);
}
void SelectMenuLoginStudent(Node_Year*& y, Node_Class*& c)
{
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'A')
		{
			kt = 1;
			MenuSelectClass(y);
		}
		if (move == 13)
		{
			kt = 1;
			LoginStudent(c, y);
		}
	}
}
bool CheckLoginStudent(Node_Class*& c, Account x, Node_Student*& s)
{
	Node_Student* temp = c->c.ls.SHead;
	bool kt = false;
	while (temp != NULL)
	{
		if (temp->a.a.name == x.name && temp->a.a.pass == x.pass)
		{
			kt = true;
			s = temp;
			break;
		}
		temp = temp->pNext;
	}
	return kt;
}
void LoginStudent(Node_Class*& c, Node_Year*& p)
{
	system("cls");
	Account x;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t\t\t\tWELCOME TO THE COURSE REGISTRATION SYSTEM" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	TxtColor(2);
	cout << "\t\t\t\t\t   PLEASE ENTER USERNAME AND PASSWORD" << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t   ";
	TxtColor(11);
	cout << "Username:";
	TxtColor(15);
	getline(cin, x.name);
	string cache;
	cache = x.name;
	TxtColor(11);
	cout << "\t\t\t\t\t   Password:";
	TxtColor(15);
	cin >> x.pass;
	cin.ignore();
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	Node_Student* s = NULL;
	if (CheckLoginStudent(c, x, s))
	{
		MenuStudentOption(s, p);
	}
	else
	{
		GoToXY(22, 23);
		TxtColor(12);
		cout << "Account or password is wrong!!Press A to back or Press EnTer to login again" << endl;
		SelectMenu_InPutLoginStudent(p, c);
	}
}
void SelectMenu_InPutLoginStudent(Node_Year*& p, Node_Class*& c)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			LoginStudent(c, p);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			MenuSelectClass(p);
		}
	}
}
void SelectMenu_Login(int choose, List_Account_Staff& l1)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'A')
		{
			kt = 1;
			Menu(l1);
		}
		if (move == 13)
		{
			kt = 1;
			Menu_InPutLogin(choose, l1, cache);
		}
	}
}
void SelectMenu_InPutLogin(int choose, List_Account_Staff& l1)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			Menu_InPutLogin(choose, l1, cache);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			ProcessMenu(choose, l1);
		}
	}
}
void Menu_InPutLogin(int choose, List_Account_Staff& l1, string cache)
{
	system("cls");
	Account x;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t\t\t\tWELCOME TO THE COURSE REGISTRATION SYSTEM" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	TxtColor(2);
	cout << "\t\t\t\t\t   PLEASE ENTER USERNAME AND PASSWORD" << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t   ";
	TxtColor(11);
	cout << "Username:";
	TxtColor(15);
	getline(cin, x.name);
	cache = x.name;
	TxtColor(11);
	cout << "\t\t\t\t\t   Password:";
	TxtColor(15);
	cin >> x.pass;
	cin.ignore();
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	if (choose == 1)
	{
		if (Login_Staff(l1, x))
		{
			MenuOption(x, l1, cache);
		}
		else
		{
			GoToXY(22, 21);
			TxtColor(12);
			cout << "Account or password is wrong!!Press A to back or Press EnTer to login again" << endl;
			SelectMenu_InPutLogin(choose, l1);
		}
	}
}
void PrintMenuStaffOption(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "CREATE A SCHOOL YEAR";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE A SCHOOL YEAR";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE A SCHOOL YEAR";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 4:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE A SCHOOL YEAR";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	}
}
int SelectMenuStaffOption()
{
	int selection = 1;
	while (1)
	{
		PrintMenuStaffOption(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 4)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 4;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
	}
}
void MenuOption(Account x, List_Account_Staff& l1, string cache)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	TxtColor(2);
	cout << "\t\t\t\t\t\tLOGGED IN SUCCESSFULLY" << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << x.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "CREATE A SCHOOL YEAR";
	TxtColor(11);
	cout << "              *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "VIEW YOUR PROFILE INFORMATION";
	TxtColor(11);
	cout << "     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "CHANGE PASSWORD";
	TxtColor(11);
	cout << "                   *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                           *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	cout << endl << endl;
	GoToXY(45, 27);
	cout << "ENTER        : CHOOSE";
	GoToXY(45, 28);
	cout << "W, UP ARROW  : UP";
	GoToXY(45, 29);
	cout << "S, DOWN ARROW: DOWN";
	GoToXY(0, 30);
	int y = SelectMenuStaffOption();
	ProcessMenuStaffOption(x, y, l1, cache);
}
void ProcessMenuStaffOption(Account a, int selection, List_Account_Staff& l1, string cache)
{
	ProfileStaff p;
	switch (selection)
	{
	case 1:
		system("cls");
		Menu_SchoolYear(a, lY, l1);
		break;
	case 2:
	{
		system("cls");
		List_Profile_Staff l;
		List_Profile_Empty_Staff(l);
		ReadFileProfile_Staff(l);
		NodeProfile* temp = l.pHead;
		while (temp != NULL)
		{
			if (temp->data.User == a.name)
			{
				Output(temp->data);
			}
			temp = temp->pNext;
		}
		GoToXY(10, 8);
		TxtColor(12);
		cout << "Please press Enter to go back !";
		Select_Profile(a, cache, l1);
	}
	break;
	case 3:
		system("cls");
		ChangePassword_Staff(l1, cache);
		WritefileAccount_Staff(l1);
		cin.ignore();
		Menu(l1);
		break;
	case 4:
		Menu(l1);
		break;
	}
}
void WritefileAccount_Staff(List_Account_Staff& l)
{
	Node* temp = l.Head;
	ofstream myfile;
	myfile.open("AccountStaff.csv", ios::out);
	myfile << "tai khoan,mat khau" << endl;
	while (temp != NULL)
	{
		if (temp->a.name == "" && temp->a.pass == "")break;
		else
		{
			myfile << temp->a.name << "," << temp->a.pass << endl;
			temp = temp->Next;
		}
	}
	myfile.close();
}
void PrintMenuStudentOption(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "ENROLL IN A COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW LIST OF ENROLLED COURSES";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 25);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ENROLL IN A COURSE";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "VIEW LIST OF ENROLLED COURSES";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 25);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ENROLL IN A COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW LIST OF ENROLLED COURSES";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 25);
		break;
	case 4:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ENROLL IN A COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW LIST OF ENROLLED COURSES";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 25);
		break;
	case 5:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ENROLL IN A COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW LIST OF ENROLLED COURSES";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW YOUR PROFILE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "CHANGE PASSWORD";
		GoToXY(45, 24);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 25);
	}
}
int SelectMenuStudentOption()
{
	int selection = 1;
	while (1)
	{
		PrintMenuStudentOption(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 5)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 5;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
	}
}
void MenuStudentOption(Node_Student*& s, Node_Year*& Y)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	TxtColor(2);
	cout << "\t\t\t\t\t\tLOGGED IN SUCCESSFULLY" << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "ENROLL IN A COURSE";
	TxtColor(11);
	cout << "                *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "VIEW LIST OF ENROLLED COURSES";
	TxtColor(11);
	cout << "     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "VIEW YOUR PROFILE INFORMATION";
	TxtColor(11);
	cout << "     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "CHANGE PASSWORD";
	TxtColor(11);
	cout << "                   *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                           *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	cout << endl << endl;
	GoToXY(45, 26);
	cout << "A            : BACK   ";
	GoToXY(45, 27);
	cout << "ENTER        : CHOOSE";
	GoToXY(45, 28);
	cout << "W, UP ARROW  : UP";
	GoToXY(45, 29);
	cout << "S, DOWN ARROW: DOWN";
	GoToXY(0, 30);
	int y = SelectMenuStudentOption();
	ProcessMenuStudentOption(s, Y, y);
}
void ProcessMenuStudentOption(Node_Student*& s, Node_Year*& Y, int selection)
{
	switch (selection)
	{
	case 1:
		system("cls");
		Enroll(s, Y);
		break;
	case 2:
		system("cls");
		ChooseSemester(s, Y);
		break;
	case 3:
		show_student_profile(s);
		system("pause");
		MenuStudentOption(s, Y);
		break;
	case 4:
		system("cls");
		ChangePassword_Student(s);
		cin.ignore();
		Menu(l1);
		break;
	case 5:
		Menu(l1);
		break;
	}
}
void show_student_profile(Node_Student*& s)
{
	system("cls");
	TxtColor(11);
	cout << "\t\t\t\t\t-----YOUR PROFILE INFORMATION----" << endl;
	TxtColor(7);
	cout << "\t\t\t\t\t\tClass         :" << s->a.Class << endl;
	cout << "\t\t\t\t\t\tName          :" << s->a.Surname << " " << s->a.Name << endl;
	cout << "\t\t\t\t\t\tGender        :" << s->a.Gender << endl;
	cout << "\t\t\t\t\t\tDate of Birth :" << s->a.Date.Day << "/" << s->a.Date.Month << "/" << s->a.Date.Year << endl;
	cout << "\t\t\t\t\t\tStudent ID    :" << s->a.StudentID << endl;
	cout << "\t\t\t\t\t\tSocial ID     :" << s->a.SocialID << endl << endl;
}
void ChangePassword_Student(Node_Student*& S)
{
	Account x;
	string key, key1;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t           CHANGE PASSWORD" << endl << endl;
	cout << "\t\t\t\t\tCURRENT USERNAME    :" << S->a.a.name << endl;
	cout << "\t\t\t\t\tCURRENT PASSWORD    :";
	cin >> x.pass;
	cin.ignore();
	TxtColor(14);
	bool kt = false;
	TxtColor(11);
	if (S->a.a.pass == x.pass)
	{
		cout << "\t\t\t\t\tNEW PASSWORD        :";
		cin >> key;
		cout << "\t\t\t\t\tCONFIRM NEW PASSWORD:";
		cin >> key1;
		while (key1 != key)
		{
			TxtColor(12);
			cout << "\t\t\t\t\t    Password incorrect! Please re-enter!" << endl;
			TxtColor(11);
			cout << "\t\t\t\t\tCONFIRM NEW PASSWORD: ";
			cin >> key1;
		}
		if (key1 == key)
		{
			S->a.a.pass = key;
			TxtColor(12);
			cout << endl;
			cout << "\t\t\tPassword changed successfully.Please login again to apply changes. " << endl;
			cout << "\t\t\t";
			system("pause");
			kt = true;
		}
	}
	if (kt == false)
	{
		TxtColor(12);
		cout << endl;
		cout << "\t\t\t\tPassword is wrong.Please login again." << endl;
		GoToXY(32, 21); system("pause");
		system("cls");
		ChangePassword_Student(S);
	}
}
void ChangePassword_Staff(List_Account_Staff& l, string cache)
{
	Account x;
	string key, key1;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t           CHANGE PASSWORD" << endl << endl;
	cout << "\t\t\t\t\tCURRENT USERNAME    :" << cache << endl;
	cout << "\t\t\t\t\tCURRENT PASSWORD    :";
	cin >> x.pass;
	cin.ignore();
	TxtColor(14);
	bool kt = false;
	Node* temp = l.Head;
	while (temp != NULL)
	{
		TxtColor(11);
		if (temp->a.pass == x.pass && temp->a.name == cache)
		{
			cout << "\t\t\t\t\tNEW PASSWORD        :";
			cin >> key;
			cout << "\t\t\t\t\tCONFIRM NEW PASSWORD:";
			cin >> key1;
			while (key1 != key)
			{
				TxtColor(12);
				cout << "\t\t\t\t\t    Password incorrect! Please re-enter!" << endl;
				TxtColor(11);
				cout << "\t\t\t\t\tCONFIRM NEW PASSWORD: ";
				cin >> key1;
			}
			if (key1 == key)
			{
				temp->a.pass = key;
				TxtColor(12);
				cout << endl;
				cout << "\t\t\tPassword changed successfully.Please login again to apply changes.\n " << endl;
				cout << "\t\t\t";
				system("pause");
				kt = true;
				break;
			}
		}

		temp = temp->Next;
	}
	if (kt == false)
	{
		TxtColor(12);
		cout << endl;
		cout << "\t\t\t\tPassword is wrong.Please login again.";
		GoToXY(32, 21); system("pause");
		system("cls");
		ChangePassword_Staff(l, cache);
	}
}

void List_Profile_Empty_Staff(List_Profile_Staff& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NodeProfile* CreateNodeProfile(ProfileStaff x)
{
	NodeProfile* a = new NodeProfile;
	a->data = x;
	a->pNext = NULL;
	return a;
}
void Add_Tail_Staff_Profile(List_Profile_Staff& l, NodeProfile* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void ReadFileProfile_Staff(List_Profile_Staff& l)
{
	ifstream myfile;
	myfile.open("ProfileStaff.csv", ios::in);
	string line;
	getline(myfile, line);
	while (myfile.good())
	{
		ProfileStaff x;
		getline(myfile, x.User, ',');
		getline(myfile, x.Name, ',');
		getline(myfile, x.Gender, ',');
		getline(myfile, x.Day, ',');
		getline(myfile, x.Month, ',');
		getline(myfile, x.Year, ',');
		getline(myfile, x.SocialID, '\n');
		NodeProfile* p = CreateNodeProfile(x);
		Add_Tail_Staff_Profile(l, p);
	}
}
void Output(ProfileStaff p)
{
	GoToXY(20, 1);
	TxtColor(12);
	cout << "YOUR PROFILE" << endl;
	GoToXY(10, 3);
	TxtColor(11);
	cout << "Full Name   : " << p.Name << endl;
	GoToXY(10, 4);
	cout << "Gender      : " << p.Gender << endl;
	GoToXY(10, 5);
	cout << "Day of Birth: " << p.Day << "/" << p.Month << "/" << p.Year << endl;
	GoToXY(10, 6);
	cout << "Social ID   : " << p.SocialID << endl;
}
void Select_Profile(Account x, string cache, List_Account_Staff& l1)
{
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			MenuOption(x, l1, cache);
		}
	}
}
void Read_File_Student(List_Student& l, string namefile)
{
	ifstream myfile;
	myfile.open("namefile", ios_base::in);
	while (!myfile.eof())
	{
		Student s;
		getline(myfile, s.a.name, ',');
		getline(myfile, s.a.pass, ',');
		getline(myfile, s.Surname, ',');
		getline(myfile, s.Name, ',');
		getline(myfile, s.Gender, ',');
		getline(myfile, s.StudentID, ',');
		getline(myfile, s.Date.Day, ',');
		getline(myfile, s.Date.Month, ',');
		getline(myfile, s.Date.Year, ',');
		getline(myfile, s.SocialID, ',');
		s.Class = namefile;
		Node_Student* p = Create(s);
		AddTailClass(l, p);
	}
}
bool checkTimeYear(Year y)
{
	Day d;
	d = System_date();
	if (d.month == 9 && d.year == stoi(y.start))
		return true;
	return false;
}
bool checkSame(Year y)
{
	Node_Year* temp = lY.YHead;
	while (temp != NULL)
	{
		if (temp->y.start == y.start && temp->y.end == y.end)
		{
			return false;
		}
		temp = temp->yNext;
	}
	return true;
}
void MenuCreateSchoolYear(List_Year& lY, Account a)
{
	Year y;
	List_Class_Empty(y.l);
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t    ";
	TxtColor(12);
	cout << "Enter start year:";
	TxtColor(15);
	cin >> y.start;
	do
	{
		TxtColor(11);
		cout << "\t\t\t\t\t    Enter end year:";
		TxtColor(15);
		cin >> y.end;
		cin.ignore();
		TxtColor(11);
		if (stoi(y.end) != stoi(y.start) + 1)
		{
			GoToXY(27, 24);
			cout << "!!! The end of the school year must be 1 year from the start of the school year." << endl;
			cout << "\t\t\t\t      Please press A to go back or press Enter to re-enter." << endl;
			SelectCreateSchoolYear(a);
		}
	} while (stoi(y.end) != stoi(y.start) + 1);
	cout << "\t\t\t\t\t******************************************" << endl;
	if (checkTimeYear(y) == false)
	{
		cout << "The start time of the school year does not match the real time.Please press A to go back or press Enter to re-enter." << endl;
		SelectCreateSchoolYear(a);
	}
	if (checkSame(y) == false)
	{
		GoToXY(25, 24);
		cout << "The school year has been duplicated.Please press A to go back or press Enter to re-enter." << endl;
		SelectCreateSchoolYear(a);
	}
	List_Semester_Empty(y.s);
	List_Class_Empty(y.l);
	for (int i = 0; i < 3; i++)
	{
		Node_Semester* k = new Node_Semester;
		k->s.Name_Semester = i + 1;
		k->s.l1.CHead = NULL;
		k->s.l1.CTail = NULL;
		k->Next = NULL;
		AddTail_Semester(y.s, k);
	}
	Node_Year* temp = lY.YHead;
	while (temp != NULL)
	{
		Node_Class* temp1 = temp->y.l.CHead;
		while (temp1 != NULL)
		{
			Node_Class* c = new Node_Class;
			c->c.Name_Class = temp1->c.Name_Class;
			c->c.Totalnumberstudent = temp1->c.Totalnumberstudent;
			c->CNext = NULL;
			List_Student_Empty(c->c.ls);
			AddStudent(c);
			AddHead(y.l, c);
			temp1 = temp1->CNext;
		}
		temp = temp->yNext;
	}
	Node_Year* p = Create(y);
	AddHead_Year(lY, p);
	Menu_SchoolYear(a, lY, l1);
}
void PrintMenuSchoolYear(int selection)
{
	bool kt = false;
	int n = CountNode(lY);
	int dem = 2;
	if (selection == 1)
	{
		GoToXY(45, 20);
		TxtColor(12);
		cout << "CREATE A NEW SCHOOL YEAR";
		Node_Year* temp = lY.YHead;
		int i = 21;
		while (temp != NULL)
		{
			GoToXY(45, i);
			TxtColor(11);
			cout << temp->y.start << "-" << temp->y.end;
			i++;
			temp = temp->yNext;
		}
		GoToXY(45, i);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
	}
	else
	{
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE A NEW SCHOOL YEAR";
		int i = 21;
		Node_Year* temp = lY.YHead;
		while (temp != NULL)
		{
			if (dem == selection)
			{
				kt = true;
				GoToXY(45, i);
				TxtColor(12);
				cout << temp->y.start << "-" << temp->y.end;
				i++;
				dem++;
				temp = temp->yNext;
			}
			else
			{
				GoToXY(45, i);
				TxtColor(11);
				cout << temp->y.start << "-" << temp->y.end;
				temp = temp->yNext;
				i++;
				dem++;
			}
		}
		if (kt == true)
		{
			GoToXY(45, i);
			TxtColor(11);
			cout << "LOG OUT";
		}
		else
		{
			GoToXY(45, i);
			TxtColor(12);
			cout << "LOG OUT";
		}
		GoToXY(0, 24);
	}
}
int SelectMenu_SchoolYear(Account x, string cache)
{
	int n = CountNode(lY);
	int selection = 1;
	while (1)
	{
		PrintMenuSchoolYear(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n + 2)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n + 2;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
		{
			return selection;
		}
		if (move == 'A')
		{
			MenuOption(x, l1, cache);
		}
	}
}
void Menu_SchoolYear(Account a, List_Year& lY, List_Account_Staff& l1)
{
	system("cls");
	Node_Year* temp = lY.YHead;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "CREATE A NEW SCHOOL YEAR";
	TxtColor(11);
	cout << "          *" << endl;
	while (temp != NULL)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t*    ";
		TxtColor(11);
		cout << temp->y.start << "-" << temp->y.end;
		TxtColor(11);
		cout << "                         *" << endl;
		temp = temp->yNext;
	}
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                           *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	string cache;
	int y = SelectMenu_SchoolYear(a, cache);
	ProcessMenuSChoolYear(a, y, lY, l1);
}
void ProcessMenuSChoolYear(Account a, int selection, List_Year& lY, List_Account_Staff& l1)
{
	int dem = 2;
	if (selection == 1)
	{
		system("cls");
		MenuCreateSchoolYear(lY, a);
	}
	else
	{
		Node_Year* temp = lY.YHead;
		while (temp != NULL)
		{
			if (dem == selection)
			{
				MenuSchoolYear(a, temp, lY);
				break;
			}
			dem++;
			temp = temp->yNext;
		}
		if (temp == NULL)
		{
			Menu(l1);
		}
	}
}
void PrintMenuYear(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(55, 20);
		TxtColor(12);
		cout << "Class";
		GoToXY(55, 21);
		TxtColor(11);
		cout << "Semester";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(55, 20);
		TxtColor(11);
		cout << "Class";
		GoToXY(55, 21);
		TxtColor(12);
		cout << "Semester";
		GoToXY(0, 24);
		break;
	}
}
int SelectMenuYear(Account x)
{
	int selection = 1;
	while (1)
	{
		PrintMenuYear(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 2)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 2;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
		{
			return selection;
		}
		if (move == 'A')
		{
			Menu_SchoolYear(x, lY, l1);
		}
	}
}
void MenuSchoolYear(Account a, Node_Year*& p, List_Year& lY)
{
	system("cls");
	Node_Year* temp = lY.YHead;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*              ";
	TxtColor(12);
	cout << "Class";
	TxtColor(11);
	cout << "                   *" << endl;
	cout << "\t\t\t\t\t*              ";
	TxtColor(11);
	cout << "Semester";
	TxtColor(11);
	cout << "                *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectMenuYear(a);
	ProcessMenuYear(a, y, p, lY);
}
void ProcessMenuYear(Account a, int selection, Node_Year*& p, List_Year& lY)
{
	switch (selection)
	{
	case 1:
		MenuClass(a, p);
		break;
	case 2:
		MenuSemester(a, p->y.s, p);
		break;
	}
}
void CreateClass(List_Class& lC)
{
	Class c;
	cout << "Enter name class:";
	getline(cin, c.Name_Class);
	Read_File_Student(c.ls, c.Name_Class);
	Node_Class* x = Create(c);
	AddHead(lC, x);
}
int CountNode(List_Year l)
{
	Node_Year* p = l.YHead;
	int dem = 0;
	while (p != NULL)
	{
		dem++;
		p = p->yNext;
	}
	return dem;
}
int CountNode_Class(List_Class l)
{
	Node_Class* temp = l.CHead;
	int dem = 0;
	while (temp != NULL)
	{
		dem++;
		temp = temp->CNext;
	}
	return dem;
}
void MenuClass(Account a, Node_Year*& p)
{
	system("cls");
	Node_Class* temp = p->y.l.CHead;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "CREATE A NEW CLASS";
	TxtColor(11);
	cout << "                *" << endl;
	while (temp != NULL)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t*    ";
		TxtColor(11);
		cout << temp->c.Name_Class;
		TxtColor(11);
		cout << "                            *" << endl;
		temp = temp->CNext;
	}
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                           *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectMenu_Class(p, a);
	ProcessMenuClass(a, y, p);
}
void PrintMenuClass(int selection, Node_Year*& Y)
{
	bool kt = false;
	int n = CountNode_Class(Y->y.l);
	int dem = 2;
	if (selection == 1)
	{
		GoToXY(45, 20);
		TxtColor(12);
		cout << "CREATE A NEW CLASS";
		Node_Class* temp = Y->y.l.CHead;
		int i = 21;
		while (temp != NULL)
		{
			GoToXY(45, i);
			TxtColor(11);
			cout << temp->c.Name_Class;
			i++;
			temp = temp->CNext;
		}
		GoToXY(45, i);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
	}
	else
	{
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE A NEW CLASS";
		int i = 21;
		Node_Class* temp = Y->y.l.CHead;
		while (temp != NULL)
		{
			if (dem == selection)
			{
				kt = true;
				GoToXY(45, i);
				TxtColor(12);
				cout << temp->c.Name_Class;
				i++;
				dem++;
				temp = temp->CNext;
			}
			else
			{
				GoToXY(45, i);
				TxtColor(11);
				cout << temp->c.Name_Class;
				temp = temp->CNext;
				i++;
				dem++;
			}
		}
		if (kt == true)
		{
			GoToXY(45, i);
			TxtColor(11);
			cout << "LOG OUT";
		}
		else
		{
			GoToXY(45, i);
			TxtColor(12);
			cout << "LOG OUT";
		}
		GoToXY(0, 24);
	}
}
int SelectMenu_Class(Node_Year*& Y, Account x)
{
	int n = CountNode_Class(Y->y.l);
	int selection = 1;
	while (1)
	{
		PrintMenuClass(selection, Y);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n + 2)
			{
				selection = 1;
			}
			else
				selection++;
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n + 2;
			}
			else
				selection--;
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuSchoolYear(x, Y, lY);
		}
	}
}
void ProcessMenuClass(Account a, int selection, Node_Year*& Y)
{
	int dem = 2;
	if (selection == 1)
	{
		system("cls");
		MenuCreateClass(Y, a);
	}
	else
	{
		Node_Class* temp = Y->y.l.CHead;
		while (temp != NULL)
		{
			if (dem == selection)
			{
				ClassProcess(a, Y, temp);
				break;
			}
			dem++;
			temp = temp->CNext;
		}
		if (temp == NULL)
		{
			Menu(l1);
		}
	}
}
bool CheckSameClass(Class c, List_Class& lc)
{
	Node_Class* temp = lc.CHead;
	while (temp != NULL)
	{
		if (temp->c.Name_Class == c.Name_Class)
		{
			return false;
		}
		temp = temp->CNext;
	}
	return true;
}
void MenuCreateClass(Node_Year*& Y, Account a)
{
	system("cls");
	Class c;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t    ";
	TxtColor(12);
	cout << "Enter class name:";
	TxtColor(15);
	cin >> c.Name_Class;
	cin.ignore();
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
	if (c.Name_Class != "19CTT3" && c.Name_Class != "19HOH3" && c.Name_Class != "18TTH1" && c.Name_Class != "18SHH1" && c.Name_Class != "17CTT3" && c.Name_Class != "17KVL3" && c.Name_Class != "20HOH3" && c.Name_Class != "20CTT3" && c.Name_Class != "20CTT2")
	{
		GoToXY(20, 24);
		TxtColor(12);
		cout << "YOU ENTERED THE WRONG CLASS NAME, PLEASE PRESS A TO GO BACK OR PREES ENTER TO RE-ENTER";
		SelectCreateClass(a, Y);
	}
	else if (CheckSameClass(c, Y->y.l) == false)
	{
		GoToXY(20, 24);
		TxtColor(12);
		cout << "YOU ENTERED THE SAME CLASS NAME, PLEASE PRESS A TO GO BACK OR PREES ENTER TO RE-ENTER";
		SelectCreateClass(a, Y);
	}
	List_Student_Empty(c.ls);
	Node_Class* C = Create(c);
	AddHead(Y->y.l, C);
	MenuClass(a, Y);
}
void PrintInfClass(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW CLASS LIST";
		GoToXY(45, 20);
		TxtColor(12);
		cout << "ADD STUDENTS TO CLASS";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "SEE CLASS GRADES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(45, 21);
		TxtColor(12);
		cout << "VIEW CLASS LIST";
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ADD STUDENTS TO CLASS";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "SEE CLASS GRADES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW CLASS LIST";
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ADD STUDENTS TO CLASS";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "SEE CLASS GRADES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 4:
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW CLASS LIST";
		GoToXY(45, 20);
		TxtColor(11);
		cout << "ADD STUDENTS TO CLASS";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "SEE CLASS GRADES";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	}
}
int SelectClass(Account a, Node_Year*& p)
{
	int selection = 1;
	while (1)
	{
		PrintInfClass(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 4)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 4;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuClass(a, p);
		}
	}
}
void AddStudent(Node_Class*& C)
{
	ifstream fin;
	fin.open(C->c.Name_Class + ".csv", ios::in);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << C->c.Name_Class << ".csv !!!" << endl;
	}
	else
	{
		List_Student_Empty(C->c.ls);
		string line;
		getline(fin, line);
		for (int i = 0; i < C->c.Totalnumberstudent; i++)
		{
			Student s;
			s.Class = C->c.Name_Class;
			getline(fin, s.a.name, ',');
			getline(fin, s.a.pass, ',');
			getline(fin, s.Surname, ',');
			getline(fin, s.Name, ',');
			getline(fin, s.Gender, ',');
			getline(fin, s.StudentID, ',');
			getline(fin, s.Date.Day, ',');
			getline(fin, s.Date.Month, ',');
			getline(fin, s.Date.Year, ',');
			getline(fin, s.SocialID, '\n');
			s.l1.CHead = s.l1.CTail = NULL;
			s.l1.Sum_Course = 0;
			s.l1.semester = 1;
			s.l2.CHead = s.l2.CTail = NULL;
			s.l2.Sum_Course = 0;
			s.l2.semester = 2;
			s.l3.CHead = s.l3.CTail = NULL;
			s.l3.Sum_Course = 0;
			s.l3.semester = 3;
			s.sumcourse = 0;
			Node_Student* S = Create(s);
			AddTailClass(C->c.ls, S);
		}
		TxtColor(12);
		cout << "\t\t\t\t     Successfully added " << C->c.Totalnumberstudent << " students to the class!!!" << endl;
	}
	fin.close();
}
void ViewClassList(Account a, Node_Class*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t**********************************************************************************" << endl;
	cout << "\t\t**********************************************************************************" << endl;
	cout << endl << endl;
	Node_Student* s = C->c.ls.SHead;
	int stt = 0;
	cout << "\t\t List of class " << C->c.Name_Class << endl;
	cout << "\t\t" << setw(10) << left << "STT" << setw(15) << left << "MSSV" << "Name" << endl;
	while (s != NULL)
	{
		stt++;
		TxtColor(7);
		cout << "\t\t" << setw(10) << left << stt << setw(10) << left << s->a.StudentID << s->a.Surname << " " << s->a.Name << endl;
		s = s->pNext;
	}
}
void MenuAddStudent(Account a, Node_Class*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t**********************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t ";
	TxtColor(12);
	if (C->c.Totalnumberstudent > 0)
	{
		GoToXY(35, 13);
		cout << "The class has been added students, cannot be added.!!" << endl;
	}
	else
	{
		do
		{
			cout << "Enter the number of students(No more than 50 students):";
			TxtColor(15);
			cin >> C->c.Totalnumberstudent;
		} while (C->c.Totalnumberstudent > C->c.MAX);
		AddStudent(C);
	}
	cin.ignore();
	TxtColor(11);
	cout << "\t\t\t\t\t******************************************" << endl;
}

void PrintMenuStudent(int select, Node_Class*& C)
{
	Node_Student* s = C->c.ls.SHead;
	int dem = 1;
	int i = 7;
	while (s != NULL)
	{
		if (dem == select)
		{
			GoToXY(51, i);
			TxtColor(12);
			cout << s->a.Surname << " " << s->a.Name;
			s = s->pNext;
			dem++;
			i++;
		}
		else {
			GoToXY(51, i);
			TxtColor(11);
			cout << s->a.Surname << " " << s->a.Name;
			s = s->pNext;
			dem++;
			i++;
		}
	}
	GoToXY(0, select);
}
int SelectStudent(Account a, Node_Year* Y, Node_Class*& C)
{
	int selection = 1;
	while (1)
	{
		PrintMenuStudent(selection, C);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == C->c.Totalnumberstudent)
			{
				selection = 1;
			}
			else
				selection++;
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = C->c.Totalnumberstudent;
			}
			else
				selection--;
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			ClassProcess(a, Y, C);
		}
	}
}
void MenuStudent(Account a, Node_Student*& s, int total)
{
	Node_Course_Signed* C1 = s->a.l1.CHead;

	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t**********************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\tScoreboard Semester 1\n\n";
	TxtColor(12);
	cout << setw(10) << left << "NO" << setw(30) << left << "Course name" << setw(15) << left << "Point process" << setw(15) << left << "Midterm score" << setw(15) << left << "Final score" << setw(15) << left << "Summary score" << endl;
	float tong1 = 0;
	for (int i = 0; (i < s->a.l1.Sum_Course) && C1 != NULL; i++)
	{
		TxtColor(7);
		tong1 += C1->C.s.total;
		cout << setw(10) << left << i + 1 << setw(30) << left << C1->C.NameCourse << setw(15) << left << C1->C.s.plus << setw(15) << left << C1->C.s.Mid_term << setw(15) << left << C1->C.s.End_term << setw(15) << left << C1->C.s.total << endl;
		C1 = C1->CNext;
	}
	cout << endl;
	if (s->a.l1.Sum_Course != 0)
	{
		tong1 = tong1 / s->a.l1.Sum_Course;
	}
	TxtColor(11);
	cout << "\t\t\t\t\tGPA in semester 1:" << tong1 << endl << endl << endl << endl;
	Node_Course_Signed* C2 = s->a.l2.CHead;
	TxtColor(11);
	cout << "\t\t\t\t\tScoreboard Semester 2\n\n";
	TxtColor(12);
	cout << setw(10) << left << "NO" << setw(30) << left << "Course name" << setw(15) << left << "Point process" << setw(15) << left << "Midterm score" << setw(15) << left << "Final score" << setw(15) << left << "Summary score" << endl;
	float tong2 = 0;
	for (int i = 0; (i < s->a.l2.Sum_Course) && C2 != NULL; i++)
	{
		TxtColor(7);
		tong2 += C2->C.s.total;
		cout << setw(10) << left << i + 1 << setw(30) << left << C2->C.NameCourse << setw(15) << left << C2->C.s.plus << setw(15) << left << C2->C.s.Mid_term << setw(15) << left << C2->C.s.End_term << setw(15) << left << C2->C.s.total << endl;
		C2 = C2->CNext;
	}
	cout << endl;
	if (s->a.l1.Sum_Course != 0)
	{
		tong2 = tong2 / s->a.l2.Sum_Course;
	}
	TxtColor(11);
	cout << "\t\t\t\t\tGPA in semester 2:" << tong2 << endl << endl << endl << endl;
	Node_Course_Signed* C3 = s->a.l3.CHead;
	TxtColor(11);
	cout << "\t\t\t\t\tScoreboard Semester 3\n\n";
	TxtColor(12);
	cout << setw(10) << left << "NO" << setw(30) << left << "Course name" << setw(15) << left << "Point process" << setw(15) << left << "Midterm score" << setw(15) << left << "Final score" << setw(15) << left << "Summary score" << endl;
	float tong3 = 0;
	for (int i = 0; (i < s->a.l3.Sum_Course) && C3 != NULL; i++)
	{
		TxtColor(7);
		tong2 += C3->C.s.total;
		cout << setw(10) << left << i + 1 << setw(30) << left << C3->C.NameCourse << setw(15) << left << C3->C.s.plus << setw(15) << left << C3->C.s.Mid_term << setw(15) << left << C3->C.s.End_term << setw(15) << left << C3->C.s.total << endl;
		C3 = C3->CNext;
	}
	cout << endl;
	if (s->a.l1.Sum_Course != 0)
	{
		tong3 = tong3 / s->a.l3.Sum_Course;
	}
	TxtColor(11);
	cout << "\t\t\t\t\tGPA in semester 3:" << tong3 << endl << endl;
	TxtColor(10);
	float tong4 = (tong1 + tong2 + tong3) / 3;
	cout << "\t\t\t\t\tOVERALL GPA: " << tong4 << endl << endl;
}
void ProcessStudent(Account a, int select, Node_Year* Y, Node_Class*& C)
{
	Node_Student* s = C->c.ls.SHead;
	int dem = 0;
	while (s != NULL)
	{
		dem++;
		if (select == dem)
		{
			MenuStudent(a, s, C->c.Totalnumberstudent);
			system("pause");
			SeeScore(a, Y, C);
			break;
		}
		s = s->pNext;
	}
}
void SeeScore(Account a, Node_Year* Y, Node_Class*& C)
{
	Node_Student* s = C->c.ls.SHead;
	system("cls");
	TxtColor(14);
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	while (s != NULL)
	{
		if (s == C->c.ls.SHead)
		{
			TxtColor(11);
			cout << "\t\t\t\t\t           ";
			TxtColor(12);
			cout << s->a.Surname << " " << s->a.Name;
			TxtColor(11);
			cout << "         " << endl;
			s = s->pNext;
		}
		else
		{
			TxtColor(11);
			cout << "\t\t\t\t\t           ";
			TxtColor(11);
			cout << s->a.Surname << " " << s->a.Name;
			TxtColor(11);
			cout << "         " << endl;
			s = s->pNext;
		}
	}
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectStudent(a, Y, C);
	ProcessStudent(a, y, Y, C);
}
void ProcessClass(Account a, int selection, Node_Year*& Y, Node_Class*& C)
{
	switch (selection)
	{
	case 1:
		MenuAddStudent(a, C);
		GoToXY(40, 16); TxtColor(5); system("pause");
		ClassProcess(a, Y, C);
		break;
	case 2:
		ViewClassList(a, C);
		system("pause");
		ClassProcess(a, Y, C);
		break;
	case 3:
		SeeScore(a, Y, C);
		break;
	case 4:
		Menu(l1);
		break;
	}
}
void ClassProcess(Account a, Node_Year*& Y, Node_Class*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "ADD STUDENTS TO CLASS";
	TxtColor(11);
	cout << "             *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "VIEW CLASS LIST";
	TxtColor(11);
	cout << "                   *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "SEE CLASS GRADES";
	TxtColor(11);
	cout << "                  *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                           *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectClass(a, Y);
	ProcessClass(a, y, Y, C);
}
void PrintMenuSemester(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(50, 20);
		TxtColor(12);
		cout << "Semester 1";
		GoToXY(50, 21);
		TxtColor(11);
		cout << "Semester 2";
		GoToXY(50, 22);
		TxtColor(11);
		cout << "Semester 3";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(50, 20);
		TxtColor(11);
		cout << "Semester 1";
		GoToXY(50, 21);
		TxtColor(12);
		cout << "Semester 2";
		GoToXY(50, 22);
		TxtColor(11);
		cout << "Semester 3";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(50, 20);
		TxtColor(11);
		cout << "Semester 1";
		GoToXY(50, 21);
		TxtColor(11);
		cout << "Semester 2";
		GoToXY(50, 22);
		TxtColor(12);
		cout << "Semester 3";
		GoToXY(0, 24);
		break;
	}
}
int SelectMenu_Semester(Account x, Node_Year*& Y)
{
	int selection = 1;
	while (1)
	{
		PrintMenuSemester(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 3)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 3;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuSchoolYear(x, Y, lY);
		}
	}
}
void MenuSemester(Account a, List_Semester& lS, Node_Year*& y)
{
	system("cls");
	Node_Semester* temp = lS.SHead;
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	int dem = 1;
	while (dem <= 3)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t*         ";
		TxtColor(11);
		cout << "Semester " << dem;
		TxtColor(11);
		cout << "                   *" << endl;
		dem++;
	}
	cout << "\t\t\t\t\t****************************************" << endl;
	z = SelectMenu_Semester(a, y);
	ProcessMenuSemester(a, z, lS, y);
}
void ProcessMenuSemester(Account a, int selection, List_Semester& lS, Node_Year*& y)
{
	switch (selection)
	{
	case 1:
		system("cls");
		MenuSemesterOption(a, lS.SHead, y);
		break;
	case 2:
		system("cls");
		MenuSemesterOption(a, lS.SHead->Next, y);
		break;
	case 3:
		system("cls");
		MenuSemesterOption(a, lS.STail, y);
		break;
	}
}
void PrintMenuSemesterOption(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "CREATE TIME OF A SEMESTER";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "CREATE A COURSE REGISTRATION SESSION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW LIST OF COURSES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE TIME OF A SEMESTER";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "CREATE A COURSE REGISTRATION SESSION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW LIST OF COURSES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE TIME OF A SEMESTER";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "CREATE A COURSE REGISTRATION SESSION";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "VIEW LIST OF COURSES";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 4:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "CREATE TIME OF A SEMESTER";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "CREATE A COURSE REGISTRATION SESSION";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "VIEW LIST OF COURSES";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	}
}
int SelectMenuSemesterOption(Account a, Node_Semester*& S, Node_Year*& y)
{
	int selection = 1;
	while (1)
	{
		PrintMenuSemesterOption(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 4)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 4;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuSemester(a, y->y.s, y);
		}
	}
}
void MenuSemesterOption(Account x, Node_Semester*& S, Node_Year*& y)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << x.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "CREATE TIME OF A SEMESTER";
	TxtColor(11);
	cout << "                *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "CREATE A COURSE REGISTRATION SESSION";
	TxtColor(11);
	cout << "     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "VIEW LIST OF COURSES";
	TxtColor(11);
	cout << "                     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                                  *" << endl;
	cout << "\t\t\t\t\t***********************************************" << endl;
	int a = SelectMenuSemesterOption(x, S, y);
	ProcessMenuSemesterOption(x, a, S, y);
}
void ProcessMenuSemesterOption(Account a, int selection, Node_Semester*& S, Node_Year* y)
{
	switch (selection)
	{
	case 1:
		system("cls");
		CreateDateOfSemester(a, z, S, y);
		Select_Semester(a, S, y);
		break;
	case 2:
		system("cls");
		MenuCreateSession(S, S->s.l1, a);
		MenuSemesterOption(a, S, y);
		break;
	case 3:
		system("cls");
		ViewListCourse(a, S, y);
		break;
	case 4:
		Menu(l1);
		break;
	}
}
void PrintInforCourse(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "EXPORT STUDENT LIST TO CSV FILE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW THE SCORE BOARD OF THE COURSE";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "UPDATE COURSE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "DELETE COURSE";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "EXPORT STUDENT LIST TO CSV FILE";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "VIEW THE SCORE BOARD OF THE COURSE";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "UPDATE COURSE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "DELETE COURSE";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "EXPORT STUDENT LIST TO CSV FILE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW THE SCORE BOARD OF THE COURSE";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "UPDATE COURSE INFORMATION";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "DELETE COURSE";
		GoToXY(0, 24);
		break;

	case 4:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "EXPORT STUDENT LIST TO CSV FILE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "VIEW THE SCORE BOARD OF THE COURSE";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "UPDATE COURSE INFORMATION";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "DELETE COURSE";
		GoToXY(0, 24);
		break;
	}
}
int SelectInforCourse(Account a, Node_Semester*& S, Node_Year* y)
{
	int selection = 1;
	while (1)
	{
		PrintInforCourse(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 4)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 4;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			ViewListCourse(a, S, y);
		}
	}
}
int SelectListCource(Account a, Node_Semester*& S, Node_Year* y)
{
	int n = CountCourse(S);
	int selection = 1;
	while (1)
	{
		PrintMenuCourse(selection, S);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuSemesterOption(a, S, y);
		}
	}
}
void ProcessInforCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	switch (select)
	{
	case 1:
		ExportCSV(a, S, y, C);
		break;
	case 2:
		ViewTheScoreBoardOfACourse(a, S, y, C);
		system("pause");
		Coursed(a, S, y, C);
		break;
	case 3:
		MenuUpdateCourse(a, S, y, C);
		break;
	case 4:
		RemoveCourseCreated(C, S, y, a);
		system("pause");
		ViewListCourse(a, S, y);
		break;
	}
}
void MenuUpdateCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*******************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "NAME'S COURSE";
	TxtColor(11);
	cout << "                        *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "ID";
	TxtColor(11);
	cout << "                                   *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "TEACHER'S NAME";
	TxtColor(11);
	cout << "                       *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "NUMBER OF CREDITS";
	TxtColor(11);
	cout << "                    *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "NUMBER OF STUDENTS IN THE COURSE";
	TxtColor(11);
	cout << "     *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "CHANGE THE TIMETABLE";
	TxtColor(11);
	cout << "                 *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "UPDATE SCORE";
	TxtColor(11);
	cout << "                         *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                              *" << endl;
	cout << "\t\t\t\t\t*******************************************" << endl;
	int x = SelectMenuUpdateCourse(a, S, y, C);
	ProcessMenuUpdateCourse(a, x, S, y, C);
}
void PrintMenuUpdateCourse(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 4:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(12);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 5:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(12);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 6:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(12);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 7:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(12);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	case 8:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "NAME'S COURSE";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "ID";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "TEACHER'S NAME";
		GoToXY(45, 23);
		TxtColor(11);
		cout << "NUMBER OF CREDITS";
		GoToXY(45, 24);
		TxtColor(11);
		cout << "NUMBER OF STUDENTS IN THE COURSE";
		GoToXY(45, 25);
		TxtColor(11);
		cout << "CHANGE THE TIMETABLE";
		GoToXY(45, 26);
		TxtColor(11);
		cout << "UPDATE SCORE";
		GoToXY(45, 27);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 28);
		break;
	}
}
int SelectMenuUpdateCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& c)
{
	int selection = 1;
	while (1)
	{
		PrintMenuUpdateCourse(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 8)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 8;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			Coursed(a, S, y, c);
		}
	}
}
void ProcessMenuUpdateCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	switch (select)
	{
	case 1:
		ChangeNameOfCourse(a, S, y, C);
		break;
	case 2:
		ChangeID(a, S, y, C);
		break;
	case 3:
		ChangeNameOfTeacher(a, S, y, C);
		break;
	case 4:
		ChangeNumberOfCredits(a, S, y, C);
		break;
	case 5:
		ChangeMaxNumberOfStudent(a, S, y, C);
		break;
	case 6:
		ChangeTheTimetable(a, S, y, C);
		break;
	case 7:
		ChangeScoreStudent(a, S, y, C);
		break;
	case 8:
		Menu(l1);
		break;
	}
}
void PrintStudentofCourse(Node_Semester*& S, int select, Node_Course*& C)
{
	Node_Student* s = C->c.l.SHead;
	int dem = 1;
	int i = 7;
	while (s != NULL)
	{

		if (dem == select)
		{
			GoToXY(51, i);
			TxtColor(12);
			cout << s->a.Surname << " " << s->a.Name;
			dem++;
			i++;
		}
		else {
			GoToXY(51, i);
			TxtColor(11);
			cout << s->a.Surname << " " << s->a.Name;
			dem++;
			i++;
		}
		int stt = -1;
		Node_Course_Signed* tam = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = s->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 2:
			tam = s->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 3:
			tam = s->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;

		}
	}
	GoToXY(0, select);
}
int SelectStudentofCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int selection = 1;
	while (1)
	{
		PrintStudentofCourse(S, selection, C);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == C->c.TotalStudent)
			{
				selection = 1;
			}
			else
				selection++;
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = C->c.TotalStudent;
			}
			else
				selection--;
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void PrintMenuMark(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "PROCESS MARK";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "MIDTERM MARK";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "FINAL MARK";
		GoToXY(0, 25);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "PROCESS MARK";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "MIDTERM MARK";
		GoToXY(45, 22);
		TxtColor(11);
		cout << "FINAL MARK";
		GoToXY(0, 25);
		break;
	case 3:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "PROCESS MARK";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "MIDTERM MARK";
		GoToXY(45, 22);
		TxtColor(12);
		cout << "FINAL MARK";
		GoToXY(0, 25);
		break;
	}
}
int SelectMarkChange(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int selection = 1;
	while (1)
	{
		PrintMenuMark(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 3)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 3;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
			ChangeScoreStudent(a, S, y, C);
	}
}
void ChangeMark(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s, int select)
{
	Node_Course_Signed* cs = NULL;
	if (S->s.Name_Semester == s->a.l1.semester)
	{
		cs = s->a.l1.CHead;
	}
	else if (S->s.Name_Semester == s->a.l2.semester)
	{
		cs = s->a.l2.CHead;
	}
	else {
		cs = s->a.l3.CHead;

	}
	while (cs != NULL)
	{
		if (cs->C.NameCourse == C->c.NameCourse)
		{
			break;
		}
		cs = cs->CNext;
	}
	float point;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	if (cs == NULL)
	{
		GoToXY(40, 15);
		cout << "STUDENTS WHO HAVE NOT REGISTERED FOR THIS COURSE CANNOT CHANGE THEIR GRADES" << endl;
		GoToXY(40, 16); system("pause");
		ChangeStudent(a, S, y, C, s);
	}
	else {
		GoToXY(50, 10);
		int kt = 0;
		switch (select)
		{
		case 1:
			cout << "Current process mark: " << cs->C.s.plus;
			GoToXY(50, 11);
			cout << "Enter new process mark: ";
			cin >> point;
			GoToXY(40, 13); TxtColor(12);
			cout << "ARE YOU SURE TO CHANGE MARK" << endl;
			GoToXY(40, 14); TxtColor(14);
			cout << "Press A to Cancel or Press Enter to Apply" << endl;
			while (kt == 0)
			{
				int move = _getch();
				move = toupper(move);
				if (move == 13)
				{
					kt = 1;
					cs->C.s.plus = point;
					cs->C.s.total = (cs->C.s.plus * 20 + cs->C.s.Mid_term * 30 + cs->C.s.End_term * 50) / 100;
					system("cls");
					GoToXY(40, 3); TxtColor(12);
					cout << "You have successfully changed the mark" << endl;
					GoToXY(40, 5); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
				if (move == 'A')
				{
					kt = 1;
					GoToXY(40, 15);
					cout << "You have canceled the change" << endl;
					GoToXY(40, 16); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
			}
			break;
		case 2:
			cout << "Current midterm mark: " << cs->C.s.Mid_term;
			GoToXY(50, 11);
			cout << "Enter new midterm mark: ";
			cin >> point;
			GoToXY(40, 13); TxtColor(12);
			cout << "ARE YOU SURE TO CHANGE MARK" << endl;
			GoToXY(40, 14); TxtColor(14);
			cout << "Press A to Cancel or Press Enter to Apply" << endl;
			while (kt == 0)
			{
				int move = _getch();
				move = toupper(move);
				if (move == 13)
				{
					kt = 1;
					cs->C.s.Mid_term = point;
					cs->C.s.total = (cs->C.s.plus * 20 + cs->C.s.Mid_term * 30 + cs->C.s.End_term * 50) / 100;
					system("cls");
					GoToXY(40, 3); TxtColor(12);
					cout << "You have successfully changed the mark" << endl;
					GoToXY(40, 5); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
				if (move == 'A')
				{
					kt = 1;
					GoToXY(40, 15);
					cout << "You have canceled the change" << endl;
					GoToXY(40, 16); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
			}
			break;
		case 3:
			cout << "Current final mark: " << cs->C.s.End_term;
			GoToXY(50, 11);
			cout << "Enter new final mark: ";
			cin >> point;			
			GoToXY(40, 13); TxtColor(12);
			cout << "ARE YOU SURE TO CHANGE MARK" << endl;
			GoToXY(40, 14); TxtColor(14);
			cout << "Press A to Cancel or Press Enter to Apply" << endl;
			while (kt == 0)
			{
				int move = _getch();
				move = toupper(move);
				if (move == 13)
				{
					kt = 1;
					cs->C.s.End_term = point;
					cs->C.s.total = (cs->C.s.plus * 20 + cs->C.s.Mid_term * 30 + cs->C.s.End_term * 50) / 100;
					system("cls");
					GoToXY(40, 3); TxtColor(12);
					cout << "You have successfully changed the mark" << endl;
					GoToXY(40, 5); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
				if (move == 'A')
				{
					kt = 1;
					GoToXY(40, 15);
					cout << "You have canceled the change" << endl;
					GoToXY(40, 16); system("pause");
					ChangeStudent(a, S, y, C, s);
				}
			}
			break;
		}
	}
}
void ProcessMarkChange(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s, int select)
{
	ChangeMark(a, S, y, C, s, select);
}
void ChangeStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tStudent's Name :" << s->a.Surname << " " << s->a.Name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "PROCESS MARK";
	TxtColor(11);
	cout << "                      *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "MIDTERM MARK";
	TxtColor(11);
	cout << "                      *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "FINAL MARK";
	TxtColor(11);
	cout << "                        *" << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	int x = SelectMarkChange(a, S, y, C);
	ProcessMarkChange(a, S, y, C, s, x);
}
void ProcessStudentofCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	Node_Student* s = C->c.l.SHead;
	int dem = 0;
	while (s != NULL)
	{
		dem++;
		if (select == dem)
		{
			ChangeStudent(a, S, y, C, s);
		}
		int stt = -1;
		Node_Course_Signed* tam = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = s->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 2:
			tam = s->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 3:
			tam = s->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;

		}
	}
}
void ChangeScoreStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	Node_Student* s = C->c.l.SHead;
	system("cls");
	TxtColor(14);
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	while (s != NULL)
	{
		if (s == C->c.l.SHead)
		{
			TxtColor(11);
			cout << "\t\t\t\t\t           ";
			TxtColor(12);
			cout << s->a.Surname << " " << s->a.Name;
			TxtColor(11);
			cout << "         " << endl;
		}
		else
		{
			TxtColor(11);
			cout << "\t\t\t\t\t           ";
			TxtColor(11);
			cout << s->a.Surname << " " << s->a.Name;
			TxtColor(11);
			cout << "         " << endl;
		}
		int stt = -1;
		Node_Course_Signed* tam = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = s->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 2:
			tam = s->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 3:
			tam = s->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;

		}
	}
	cout << "\t\t\t\t\t****************************************" << endl;
	int x = SelectStudentofCourse(a, S, y, C);
	ProcessStudentofCourse(a, x, S, y, C);
}
void ChangeNameOfCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	string namecourse;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	GoToXY(40, 10);
	cout << "Current course's name: " << C->c.NameCourse;
	GoToXY(40, 11);
	cout << "Enter new course's name: ";
	getline(cin, namecourse);
	GoToXY(40, 13); TxtColor(12);
	cout << "ARE YOU SURE TO CHANGE COURSE'S NAME" << endl;
	GoToXY(40, 14); TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Apply" << endl;
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			C->c.NameCourse = namecourse;
			system("cls");
			GoToXY(40, 3); TxtColor(12);
			cout << "You have successfully changed the course's name" << endl;
			GoToXY(40, 5); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
		if (move == 'A')
		{
			kt = 1;
			GoToXY(40, 15);
			cout << "You have canceled the change" << endl;
			GoToXY(40, 16); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void ChangeID(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	string id;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	GoToXY(40, 10);
	cout << "Current ID: " << C->c.ID;
	GoToXY(40, 11);
	cout << "Enter new ID: ";
	getline(cin, id);
	GoToXY(40, 13); TxtColor(12);
	cout << "ARE YOU SURE TO CHANGE ID" << endl;
	GoToXY(40, 14); TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Apply" << endl;
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			C->c.ID = id;
			system("cls");
			GoToXY(40, 3); TxtColor(12);
			cout << "You have successfully changed the ID" << endl;
			GoToXY(40, 5); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
		if (move == 'A')
		{
			kt = 1;
			GoToXY(40, 15);
			cout << "You have canceled the change" << endl;
			GoToXY(40, 16); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void ChangeNameOfTeacher(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	string teachername;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	GoToXY(40, 10);
	cout << "Current teacher's name: " << C->c.NameTeacher;
	GoToXY(40, 11);
	cout << "Enter new teacher's name: ";
	getline(cin, teachername);
	GoToXY(40, 13); TxtColor(12);
	cout << "ARE YOU SURE TO CHANGE ID" << endl;
	GoToXY(40, 14); TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Apply" << endl;
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			C->c.NameTeacher = teachername;
			system("cls");
			GoToXY(40, 3); TxtColor(12);
			cout << "You have successfully changed the teacher's name" << endl;
			GoToXY(40, 5); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
		if (move == 'A')
		{
			kt = 1;
			GoToXY(40, 15);
			cout << "You have canceled the change" << endl;
			GoToXY(40, 16); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void ChangeNumberOfCredits(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int numbercredit;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	GoToXY(40, 10);
	cout << "Current number of credits: " << C->c.NumberofCredits;
	GoToXY(40, 11);
	cout << "Enter new number of credits: ";
	cin >> numbercredit;
	GoToXY(40, 13); TxtColor(12);
	cout << "ARE YOU SURE TO CHANGE NUMBER OF CREDITS" << endl;
	GoToXY(40, 14); TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Apply" << endl;
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			C->c.NumberofCredits = numbercredit;
			system("cls");
			GoToXY(40, 3); TxtColor(12);
			cout << "You have successfully changed the number of credits" << endl;
			GoToXY(40, 5); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
		if (move == 'A')
		{
			kt = 1;
			GoToXY(40, 15);
			cout << "You have canceled the change" << endl;
			GoToXY(40, 16); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void ChangeMaxNumberOfStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int max;
	system("cls");
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	GoToXY(40, 10);
	cout << "Max's current of student in the course: " << C->c.MAX;
	GoToXY(40, 11);
	cout << "Enter new max of student in the course: ";
	cin >> max;
	GoToXY(40, 13); TxtColor(12);
	cout << "ARE YOU SURE TO CHANGE MAX STUDENT IN THE COURSE" << endl;
	GoToXY(40, 14); TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Apply" << endl;
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			C->c.MAX = max;
			system("cls");
			GoToXY(40, 3); TxtColor(12);
			cout << "You have successfully changed the max student in the course" << endl;
			GoToXY(40, 5); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
		if (move == 'A')
		{
			kt = 1;
			GoToXY(40, 15);
			cout << "You have canceled the change" << endl;
			GoToXY(40, 16); system("pause");
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void ChangeTheTimetable(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	system("cls");
	GoToXY(0, 6);
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	TxtColor(7);
	cout << "\t\t\t\t\tThe current session: Day 1:" << C->c.ses.day1 << " - Time 1" << C->c.ses.time1 << endl;
	cout << "\t\t\t\t\t                     Day 2:" << C->c.ses.day2 << " - Time 2" << C->c.ses.time2 << endl;
	GoToXY(35, 15); TxtColor(3);
	cout << "CHOOSE THE SESSION YOU WANT TO CHANGE " << endl;
	GoToXY(45, 16);
	cout << "CHANGE SESSION DAY 1" << endl;
	GoToXY(45, 17);
	cout << "CHANGE SESSION TIME 1" << endl;
	GoToXY(45, 18);
	cout << "CHANGE SESSION DAY 2" << endl;
	GoToXY(45, 19);
	cout << "CHANGE SESSION TIME 2" << endl;
	int x = SelectMenuSession(a, S, y, C);
	ProcessMenuSelectSession(a, x, S, y, C);
}
void ProcessMenuSelectSession(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	switch (select)
	{
	case 1:
	{
		system("cls");
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t***********************************************" << endl;
		TxtColor(7);
		cout << "\t\t\t\t\tThe current session: " << "Day 1:" << C->c.ses.day1 << " - Time 1:" << C->c.ses.time1 << endl;
		cout << "\t\t\t\t\t                     " << "Day 2:" << C->c.ses.day2 << " - Time 2:" << C->c.ses.time2 << endl;
		GoToXY(40, 11);
		cout << "Enter new session day 1: ";
		string day1;
		getline(cin, day1);
		GoToXY(40, 13); TxtColor(12);
		cout << "ARE YOU SURE TO CHANGE SESSION DAY 1" << endl;
		GoToXY(40, 14); TxtColor(14);
		cout << "Press A to Cancel or Press Enter to Apply" << endl;
		int kt = 0;
		while (kt == 0)
		{
			int move = _getch();
			move = toupper(move);
			if (move == 13)
			{
				kt = 1;
				C->c.ses.day1 = day1;
				system("cls");
				GoToXY(40, 3); TxtColor(12);
				cout << "You have successfully changed session day 1" << endl;
				GoToXY(40, 5); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
			if (move == 'A')
			{
				kt = 1;
				GoToXY(40, 15);
				cout << "You have canceled the change" << endl;
				GoToXY(40, 16); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
		}
	}
	case 2:
	{
		system("cls");
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t***********************************************" << endl;
		TxtColor(7);
		cout << "\t\t\t\t\tThe current session: " << "Day 1:" << C->c.ses.day1 << " - Time 1:" << C->c.ses.time1 << endl;
		cout << "\t\t\t\t\t                     " << "Day 2:" << C->c.ses.day2 << " - Time 2:" << C->c.ses.time2 << endl;
		GoToXY(40, 11);
		cout << "Enter new session time 1: ";
		string time1;
		getline(cin, time1);
		GoToXY(40, 13); TxtColor(12);
		cout << "ARE YOU SURE TO CHANGE SESSION TIME 1" << endl;
		GoToXY(40, 14); TxtColor(14);
		cout << "Press A to Cancel or Press Enter to Apply" << endl;
		int kt = 0;
		while (kt == 0)
		{
			int move = _getch();
			move = toupper(move);
			if (move == 13)
			{
				kt = 1;
				C->c.ses.time1 = time1;
				system("cls");
				GoToXY(40, 3); TxtColor(12);
				cout << "You have successfully changed session time 1" << endl;
				GoToXY(40, 5); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
			if (move == 'A')
			{
				kt = 1;
				GoToXY(40, 15);
				cout << "You have canceled the change" << endl;
				GoToXY(40, 16); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
		}
	}
	case 3:
	{
		system("cls");
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t***********************************************" << endl;
		TxtColor(7);
		cout << "\t\t\t\t\tThe current session: " << "Day 1:" << C->c.ses.day1 << " - Time 1:" << C->c.ses.time1 << endl;
		cout << "\t\t\t\t\t                     " << "Day 2:" << C->c.ses.day2 << " - Time 2:" << C->c.ses.time2 << endl;
		GoToXY(40, 11);
		cout << "Enter new session day 2: ";
		string day2;
		getline(cin, day2);
		GoToXY(40, 13); TxtColor(12);
		cout << "ARE YOU SURE TO CHANGE SESSION DAY 2" << endl;
		GoToXY(40, 14); TxtColor(14);
		cout << "Press A to Cancel or Press Enter to Apply" << endl;
		int kt = 0;
		while (kt == 0)
		{
			int move = _getch();
			move = toupper(move);
			if (move == 13)
			{
				kt = 1;
				C->c.ses.day2 = day2;
				system("cls");
				GoToXY(40, 3); TxtColor(12);
				cout << "You have successfully changed session day 2" << endl;
				GoToXY(40, 5); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
			if (move == 'A')
			{
				kt = 1;
				GoToXY(40, 15);
				cout << "You have canceled the change" << endl;
				GoToXY(40, 16); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
		}
	}
	case 4:
	{
		system("cls");
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t***********************************************" << endl;
		TxtColor(7);
		cout << "\t\t\t\t\tThe current session: " << "Day 1:" << C->c.ses.day1 << " - Time 1:" << C->c.ses.time1 << endl;
		cout << "\t\t\t\t\t                     " << "Day 2:" << C->c.ses.day2 << " - Time 2:" << C->c.ses.time2 << endl;
		GoToXY(40, 11);
		cout << "Enter new session time 2: ";
		string time2;
		getline(cin, time2);
		GoToXY(40, 13); TxtColor(12);
		cout << "ARE YOU SURE TO CHANGE SESSION TIME 2" << endl;
		GoToXY(40, 14); TxtColor(14);
		cout << "Press A to Cancel or Press Enter to Apply" << endl;
		int kt = 0;
		while (kt == 0)
		{
			int move = _getch();
			move = toupper(move);
			if (move == 13)
			{
				kt = 1;
				C->c.ses.time2 = time2;
				system("cls");
				GoToXY(40, 3); TxtColor(12);
				cout << "You have successfully changed session time 1" << endl;
				GoToXY(40, 5); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
			if (move == 'A')
			{
				kt = 1;
				GoToXY(40, 15);
				cout << "You have canceled the change" << endl;
				GoToXY(40, 16); system("pause");
				ChangeTheTimetable(a, S, y, C);
			}
		}
	}
	}
}
void PrintMenuSelectSession(int select)
{
	switch (select)
	{
	case 1:
		GoToXY(45, 16);
		TxtColor(12);
		cout << "CHANGE SESSION DAY 1";
		GoToXY(45, 17);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 1";
		GoToXY(45, 18);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 2";
		GoToXY(45, 19);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 2";
		GoToXY(0, 15);
		break;
	case 2:
		GoToXY(45, 16);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 1";
		GoToXY(45, 17);
		TxtColor(12);
		cout << "CHANGE SESSION TIME 1";
		GoToXY(45, 18);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 2";
		GoToXY(45, 19);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 2";
		GoToXY(0, 15);
		break;
	case 3:
		GoToXY(45, 16);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 1";
		GoToXY(45, 17);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 1";
		GoToXY(45, 18);
		TxtColor(12);
		cout << "CHANGE SESSION DAY 2";
		GoToXY(45, 19);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 2";
		GoToXY(0, 15);
		break;
	case 4:
		GoToXY(45, 16);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 1";
		GoToXY(45, 17);
		TxtColor(11);
		cout << "CHANGE SESSION TIME 1";
		GoToXY(45, 18);
		TxtColor(11);
		cout << "CHANGE SESSION DAY 2";
		GoToXY(45, 19);
		TxtColor(12);
		cout << "CHANGE SESSION TIME 2";
		GoToXY(0, 15);
		break;
	}
}
int SelectMenuSession(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int selection = 1;
	while (1)
	{
		PrintMenuSelectSession(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 4)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 4;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuUpdateCourse(a, S, y, C);
		}
	}
}
void PrintExport(int select)
{
	switch (select)
	{
	case 1:
		GoToXY(45, 20);
		TxtColor(12);
		cout << "EXPORT STUDENT LIST TO CSV";
		GoToXY(45, 21);
		TxtColor(11);
		cout << "IMPORT THE SCOREBOARD TO THE SYSTEM";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(45, 20);
		TxtColor(11);
		cout << "EXPORT STUDENT LIST TO CSV";
		GoToXY(45, 21);
		TxtColor(12);
		cout << "IMPORT THE SCOREBOARD TO THE SYSTEM";
		GoToXY(0, 24);
		break;
	}
}
int SelectExport(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	int selection = 1;
	while (1)
	{
		PrintExport(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 2)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 2;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			Coursed(a, S, y, C);
		}
	}
}
void Export(Node_Course*& C, Node_Semester*& S)
{
	system("cls");
	ofstream outdata;
	outdata.open(C->c.NameCourse + ".csv", ios::out);
	Node_Student* s = C->c.l.SHead;
	outdata << "No,Student ID,Process Mark,Midterm Mark,Final Mark,Total Mark" << endl;
	int no = 0;
	while (s != NULL)
	{
		no++;
		outdata << no << "," << s->a.StudentID << ", , , , " << endl;
		int stt = -1;
		Node_Course_Signed* tam = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = s->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 2:
			tam = s->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 3:
			tam = s->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;

		}
	}
	outdata.close();
	TxtColor(12);
	GoToXY(15, 3);
	cout << "The list of students has been exported to a CSV file successfully" << endl;
	GoToXY(15, 4);
	cout << "      Teachers, please import the scores into the file." << endl;
	GoToXY(30, 5); system("pause");
}
void ImPort(Node_Course*& C, Node_Semester*& S)
{
	system("cls");
	ifstream indata;
	string line;
	indata.open(C->c.NameCourse + ".csv", ios::in);
	Node_Student* s = C->c.l.SHead;
	getline(indata, line);
	while (indata.good() && s != NULL)
	{
		string temp;
		getline(indata, temp, ',');
		getline(indata, s->a.StudentID, ',');
		Node_Course_Signed* c = NULL;
		if (s->a.l1.semester == S->s.Name_Semester)
		{
			c = s->a.l1.CHead;
		}
		else if (s->a.l2.semester == S->s.Name_Semester)
		{
			c = s->a.l2.CHead;
		}
		else
		{
			c = s->a.l3.CHead;
		}
		while (c != NULL)
		{
			if (c->C.NameCourse == C->c.NameCourse)
			{
				getline(indata, temp, ',');
				c->C.s.plus = stof(temp);
				getline(indata, temp, ',');
				c->C.s.Mid_term = stof(temp);
				getline(indata, temp, ',');
				c->C.s.End_term = stof(temp);
				getline(indata, temp, '\n');
				c->C.s.total = stof(temp);
				break;
			}
			c = c->CNext;
		}
		Node_Course_Signed* tam = new Node_Course_Signed;
		int stt = -1;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = s->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 2:
			tam = s->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;
		case 3:
			tam = s->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			s = s->pNextCourse[stt];
			break;

		}
	}
	indata.close();
	TxtColor(12);
	GoToXY(15, 3);
	cout << "Scores have been entered and sent to the system" << endl;
	GoToXY(15, 4); system("pause");
}
void ProcessExport(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, int select)
{
	switch (select)
	{
	case 1:
		Export(C, S);
		ExportCSV(a, S, y, C);
		break;
	case 2:
		ImPort(C, S);
		ExportCSV(a, S, y, C);
		break;
	}
}
void ExportCSV(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "EXPORT STUDENT LIST TO CSV";
	TxtColor(11);
	cout << "               *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "IMPORT THE SCOREBOARD TO THE SYSTEM";
	TxtColor(11);
	cout << "      *" << endl;
	cout << "\t\t\t\t\t***********************************************" << endl;
	int x = SelectExport(a, S, y, C);
	ProcessExport(a, S, y, C, x);
}
void ViewTheScoreBoardOfACourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	Node_Student* temp = C->c.l.SHead;
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t**********************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl << endl;
	cout << "\t\t\t\t\t\tSCOREBOARD:" << C->c.NameCourse << endl;
	TxtColor(12);
	cout << setw(10) << left << "NO" << setw(20) << left << "SURNAME" << setw(10) << left << "NAME" << setw(15) << left << " PLUS MARK" << setw(15) << left << "MIDTERM MARK" << setw(15) << left << "FINAL MARK" << setw(15) << left << "TOTAL MARK" << endl;
	for (int i = 0; i < C->c.TotalStudent && temp != NULL; i++)
	{
		Node_Course_Signed* temp1 = NULL;
		if (S->s.Name_Semester == temp->a.l1.semester)
		{
			temp1 = temp->a.l1.CHead;
		}
		else if (S->s.Name_Semester == temp->a.l2.semester)
		{
			temp1 = temp->a.l2.CHead;
		}
		else {
			temp1 = temp->a.l3.CHead;

		}
		while (temp1 != NULL)
		{
			if (C->c.NameCourse == temp1->C.NameCourse)
			{
				TxtColor(7);
				cout << setw(10) << left << i + 1 << setw(20) << left << temp->a.Surname << setw(14) << left << temp->a.Name << setw(15) << left << temp1->C.s.plus << setw(15) << left << temp1->C.s.Mid_term << setw(15) << left << temp1->C.s.End_term << setw(15) << left << temp1->C.s.total << endl;
				break;
			}
			temp1 = temp1->CNext;
		}
		int stt = -1;
		Node_Course_Signed* tam = new Node_Course_Signed;
		switch (S->s.Name_Semester)
		{
		case 1:
			tam = temp->a.l1.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			temp = temp->pNextCourse[stt];
			break;
		case 2:
			tam = temp->a.l2.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			temp = temp->pNextCourse[stt];
			break;
		case 3:
			tam = temp->a.l3.CHead;
			while (tam != NULL)
			{
				if (tam->C.NameCourse == C->c.NameCourse)
				{
					stt = tam->stt;
					break;
				}
				tam = tam->CNext;
			}
			temp = temp->pNextCourse[stt];
			break;

		}
	}
	cout << endl;
}
void Coursed(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "EXPORT STUDENT LIST TO CSV FILE";
	TxtColor(11);
	cout << "          *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(12);
	cout << "VIEW THE SCORE BOARD OF THE COUSE";
	TxtColor(11);
	cout << "        *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "UPDATE COURSE INFORMATION";
	TxtColor(11);
	cout << "                *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t*    ";
	TxtColor(11);
	cout << "DELETE COURSE";
	TxtColor(11);
	cout << "                            *" << endl;
	cout << "\t\t\t\t\t***********************************************" << endl;
	int x = SelectInforCourse(a, S, y);
	ProcessInforCourse(a, x, S, y, C);
}
void ProcessListCourse(Account a, int select, Node_Semester*& S, Node_Year* y)
{
	Node_Course* C = S->s.l1.CHead;
	int dem = 0;
	while (C != NULL)
	{
		dem++;
		if (dem == select)
		{
			Coursed(a, S, y, C);
			break;
		}
		C = C->CNext;
	}
}

void ViewListCourse(Account a, Node_Semester*& S, Node_Year* y)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\t     USERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t***********************************************" << endl;
	Node_Course* C = S->s.l1.CHead;
	while (C != NULL)
	{
		if (C == S->s.l1.CHead)
		{
			TxtColor(12);
			cout << "\t\t\t\t\t     " << C->c.NameCourse << endl;
		}
		else
		{
			TxtColor(11);
			cout << "\t\t\t\t\t     " << C->c.NameCourse << endl;
		}
		C = C->CNext;
	}
	cout << "\t\t\t\t\t***********************************************" << endl;
	int x = SelectListCource(a, S, y);
	ProcessListCourse(a, x, S, y);
}
void CreateDateOfSemester(Account a, int selection, Node_Semester* s, Node_Year*& y)
{
	Day d = System_date();
	if (s->s.start.day != 0)
	{
		TxtColor(12);
		GoToXY(30, 1);
		cout << "You have entered the semester dates.Cannot re-enter";
	}
	else
	{
		Day start, end;
		system("cls");
		TxtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t****************************************" << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t    ";
		TxtColor(12);
		cout << "Enter start date:";
		TxtColor(15);
		cin >> start.day >> start.month >> start.year;
		TxtColor(12);
		cout << "\t\t\t\t\t    Enter end date  :";
		TxtColor(15);
		cin >> end.day >> end.month >> end.year;
		cin.ignore();
		TxtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		s->s.Name_Semester = selection;
		switch (selection)
		{
		case 1:
			if (d.month != 9)
			{
				GoToXY(25, 24);
				cout << "It's not time to create semesters 1 yet. Please press A to go back or press Enter to re-enter !" << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			else if (start.year == stoi(y->y.start) && start.month == 9 && end.year == stoi(y->y.end) && end.month <= 1)
			{
				if (start.day >= d.day)
				{
					s->s.start = start;
					s->s.end = end;
				}
				else
				{
					GoToXY(25, 24);
					cout << "Dates of semester 1 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
					SelectCreateDateOfSemester(a, selection, s, y);
				}
			}
			else
			{
				GoToXY(25, 24);
				cout << "Dates of semester 1 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			break;
		case 2:
			if (d.month != 2 || d.year != stoi(y->y.end))
			{
				GoToXY(25, 24);
				cout << "It's not time to create semesters 2 yet. Please press A to go back or press Enter to re-enter !" << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			else if (start.year == end.year && start.year == stoi(y->y.end) && (start.month == 2 && d.day >= start.day) && end.month <= 5)
			{
				if (start.month < end.month)
				{
					s->s.start = start;
					s->s.end = end;
				}
				else
				{
					GoToXY(25, 24);
					cout << "Dates of semester 2 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
					SelectCreateDateOfSemester(a, selection, s, y);
				}
			}
			else {
				GoToXY(25, 24);
				cout << "Dates of semester 2 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			break;
		case 3:
			if (d.month != 6 || d.year != stoi(y->y.end))
			{
				GoToXY(25, 24);
				cout << "It's not time to create semesters 3 yet. Please press A to go back or press Enter to re-enter !" << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			else if (start.year == end.year && start.year == stoi(y->y.end) && (start.month == 6 && start.day <= d.day) && end.month <= 8)
			{
				if (start.month < end.month)
				{
					s->s.start = start;
					s->s.end = end;
				}
				else
				{
					GoToXY(25, 24);
					cout << "Dates of semester 2 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
					SelectCreateDateOfSemester(a, selection, s, y);
				}
			}
			else {
				GoToXY(25, 24);
				cout << "Dates of semester 2 are incorrect. Please press A to go back or press Enter to re-enter ! " << endl;
				SelectCreateDateOfSemester(a, selection, s, y);
			}
			break;
		}
	}
}
void Select_Semester(Account x, Node_Semester* S, Node_Year* y)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			MenuSemesterOption(x, S, y);
		}
	}
}
void SelectCreateSchoolYear(Account a)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			MenuCreateSchoolYear(lY, a);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			Menu_SchoolYear(a, lY, l1);
		}
	}
}
void SelectCreateClass(Account a, Node_Year*& y)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			MenuCreateClass(y, a);
		}
		if (move == 'A')
		{
			kt = 1;
			MenuClass(a, y);
		}
	}
}
void SelectCreateDateOfSemester(Account a, int selection, Node_Semester* s, Node_Year*& y)
{
	string cache = "";
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			CreateDateOfSemester(a, selection, s, y);
		}
		if (move == 'A')
		{
			kt = 1;
			system("cls");
			MenuSemesterOption(a, s, y);
		}
	}
}
void MenuCreateSession(Node_Semester*& S, List_Course& lC, Account a)
{
	Day day = System_date();
	bool check;
	if (S->s.BeginRegister.day == 0)
	{
		do {
			system("cls");
			TxtColor(14);
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << endl << endl;
			TxtColor(3);
			cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
			TxtColor(11);
			cout << "\t\t\t\t\t****************************************" << endl;
			cout << "\t\t\t\t\t    ";
			TxtColor(12);
			cout << "Enter session start date: " << endl;
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Day: ";
				TxtColor(15);
				cin >> S->s.BeginRegister.day;
				cin.ignore();
			} while (S->s.BeginRegister.day < 1 || S->s.BeginRegister.day > 31);
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Month: ";
				TxtColor(15);
				cin >> S->s.BeginRegister.month;
				cin.ignore();
			} while (S->s.BeginRegister.month < 1 || S->s.BeginRegister.month > 12);
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Year: ";
				TxtColor(15);
				cin >> S->s.BeginRegister.year;
			} while (S->s.BeginRegister.year != day.year && S->s.BeginRegister.year != (day.year + 1));
			cout << "\t\t\t\t\t    ";
			TxtColor(12);
			cout << "Enter session end date: " << endl;
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Day: ";
				TxtColor(15);
				cin >> S->s.EndRegister.day;
				cin.ignore();
			} while (S->s.EndRegister.day < 1 || S->s.EndRegister.day > 31);
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Month: ";
				TxtColor(15);
				cin >> S->s.EndRegister.month;
				cin.ignore();
			} while (S->s.EndRegister.month < 1 || S->s.EndRegister.month > 12);
			do
			{
				cout << "\t\t\t\t\t\t    ";
				TxtColor(11);
				cout << "Year: ";
				TxtColor(15);
				cin >> S->s.EndRegister.year;
			} while (S->s.EndRegister.year != day.year && S->s.BeginRegister.year != (day.year + 1));
			TxtColor(11);
			check = CheckSessionDate(S->s.BeginRegister, S->s.EndRegister, S->s.start);
		} while (!check);
		List_Course_Empty(lC);
		TxtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		system("pause");
		CreateSession(S, lC, a);
	}
	else
	{
		day = System_date();
		if (day.month > S->s.EndRegister.month)
		{
			system("cls");
			TxtColor(14);
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << endl << endl;
			TxtColor(3);
			cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
			TxtColor(11);
			cout << "\t\t\t\t\t****************************************" << endl;
			cout << "\t\t\t\t\t    ";
			TxtColor(12);
			cout << "The course registration session has expired. " << endl;
			TxtColor(11);
			cout << "\t\t\t\t\t****************************************" << endl;
			system("pause");
		}
		else if (day.month == S->s.EndRegister.month && day.day > S->s.EndRegister.day)
		{
			day = System_date();
			system("cls");
			TxtColor(14);
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t                                                                                       " << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << "\t\t***************************************************************************************" << endl;
			cout << endl << endl;
			TxtColor(3);
			cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
			TxtColor(11);
			cout << "\t\t\t\t\t****************************************" << endl;
			cout << "\t\t\t\t\t    ";
			TxtColor(12);
			cout << "The course registration session has expired. " << endl;
			system("pause");
		}
		else
		{
			CreateSession(S, lC, a);
		}
	}
}
void CreateSession(Node_Semester*& S, List_Course& lC, Account a)
{
	int n;
	Course c;
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(12);
	cout << "\t\t\t\t\t    Enter number of courses: ";
	TxtColor(15);
	cin >> n;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string course;
		string id;
		string teacher;
		Session s;
		system("cls");
		TxtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t****************************************" << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t    ";
		TxtColor(12);
		cout << "Name of course: ";
		TxtColor(15);
		getline(cin, course, '\n');
		cout << "\t\t\t\t\t    ";
		TxtColor(11);
		cout << "Course ID: ";
		TxtColor(15);
		getline(cin, id);
		TxtColor(12);
		cout << "\t\t\t\t\t    Course's name of the teacher: ";
		TxtColor(15);
		getline(cin, teacher);
		cout << "\t\t\t\t\t    ";
		TxtColor(11);
		cout << "Number of credits of the course: ";
		TxtColor(15);
		cin >> c.NumberofCredits;
		cin.ignore();
		TxtColor(12);
		cout << "\t\t\t\t\t    Course's theory class start day (e.g: Monday): ";
		TxtColor(15);
		getline(cin, s.day1);
		TxtColor(11);
		cout << "\t\t\t\t\t    Course's theory class start period (e.g: 1): ";
		TxtColor(15);
		getline(cin, s.time1);
		TxtColor(12);
		cout << "\t\t\t\t\t    Course's pratical class start day (e.g: Monday): ";
		TxtColor(15);
		getline(cin, s.day2);
		TxtColor(11);
		cout << "\t\t\t\t\t    Course's pratical class start period (e.g: 1): ";
		TxtColor(15);
		getline(cin, s.time2);
		c.NameCourse = course;
		c.ID = id;
		c.NameTeacher = teacher;
		c.ses = s;
		c.l.SHead = NULL;
		c.l.STail = NULL;
		c.MAX = 50;
		Node_Course* p = Create_Course(c);
		AddTail_Course(lC, p);
		cout << "\t\t\t\t\t    ";
		TxtColor(12);
		cout << "You have just created " << i + 1 << " course(s)." << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t******************************************" << endl;
		system("pause");
	}
}
bool CheckSessionDate(Day a, Day b, Day c)
{
	bool check = true;
	if (a.month < c.month)
	{
		cout << "\t\t\t\t\t******************************************" << endl;
		cout << "The session start date must not be before " << c.day << "/" << c.month << "/" << c.year << "." << endl;
		check = false;
		system("pause");
	}
	else if (a.month == c.month)
	{
		if (a.day < c.day)
		{
			cout << "\t\t\t\t\t******************************************" << endl;
			cout << "The session start date must not be before " << c.day << "/" << c.month << "/" << c.year << "." << endl;
			check = false;
			system("pause");
		}
		else if (a.month == 9 && a.day > 30)
		{
			cout << "\t\t\t\t\t******************************************" << endl;
			cout << "The session start date is incorrect." << endl;
			check = false;
			system("pause");
		}
		else
		{
			if (a.month == b.month)
			{
				if ((b.day - a.day) > 7)
				{
					cout << "\t\t\t\t\t******************************************" << endl;
					cout << "The time of the session must not be more than 7 days." << endl;
					check = false;
					system("pause");
				}
				else if ((b.day - a.day) < 3)
				{
					cout << "\t\t\t\t\t******************************************" << endl;
					cout << "The time of the session must not be less than 3 days." << endl;
					check = false;
					system("pause");
				}
			}
			else if (a.month < b.month)
			{
				if (a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10 || a.month == 12)
				{

					if ((b.day + 31 * (b.month - a.month) - a.day) > 7)
					{
						cout << "\t\t\t\t\t******************************************" << endl;
						cout << "The time of the session must not be more than 7 days." << endl;
						check = false;
						system("pause");
					}
					else if ((b.day + 31 * (b.month - a.month) - a.day) < 3)
					{
						cout << "\t\t\t\t\t******************************************" << endl;
						cout << "The time of the session must not be less than 3 days." << endl;
						check = false;
						system("pause");
					}
				}
				else if (a.month == 2)
				{
					if (a.year % 4 == 0 && a.year % 100 != 0)
					{
						if ((b.day + 29 * (b.month - a.month) - a.day) > 7)
						{
							cout << "\t\t\t\t\t******************************************" << endl;
							cout << "The time of the session must not be more than 7 days." << endl;
							check = false;
							system("pause");
						}
						else if ((b.day + 29 * (b.month - a.month) - a.day) < 3)
						{
							cout << "\t\t\t\t\t******************************************" << endl;
							cout << "The time of the session must not be less than 3 days." << endl;
							check = false;
							system("pause");
						}
					}
					else
					{
						if ((b.day + 28 * (b.month - a.month) - a.day) > 7)
						{
							cout << "\t\t\t\t\t******************************************" << endl;
							cout << "The time of the session must not be more than 7 days." << endl;
							check = false;
							system("pause");
						}
						else if ((b.day + 28 * (b.month - a.month) - a.day) < 3)
						{
							cout << "\t\t\t\t\t******************************************" << endl;
							cout << "The time of the session must not be less than 3 days." << endl;
							check = false;
							system("pause");
						}
					}
				}
				else
				{
					if ((b.day + 30 * (b.month - a.month) - a.day) > 7)
					{
						cout << "\t\t\t\t\t******************************************" << endl;
						cout << "The time of the session must not be more than 7 days." << endl;
						check = false;
						system("pause");
					}
					else if ((b.day + 30 * (b.month - a.month) - a.day) < 3)
					{
						cout << "\t\t\t\t\t******************************************" << endl;
						cout << "The time of the session must not be less than 3 days." << endl;
						check = false;
						system("pause");
					}
				}
			}
		}
	}
	else if (a.month > c.month)
	{
		cout << "\t\t\t\t\t******************************************" << endl;
		cout << "The session start date must be before " << c.month + 1 << "/" << c.year << "." << endl;
		check = false;
		system("pause");
	}
	return check;
}
int SelectSemester(Node_Student*& s, Node_Year*& Y)
{
	int selection = 1;
	while (1)
	{
		PrintMenuSemester(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 3)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 3;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuStudentOption(s, Y);
		}
	}
}
int CountCourse(Node_Semester*& SM)
{
	int dem = 0;
	Node_Course* C = SM->s.l1.CHead;
	while (C != NULL)
	{
		dem++;
		C = C->CNext;
	}
	return dem;
}
void PrintMenuCourse(int select, Node_Semester*& SM)
{
	Node_Course* C = SM->s.l1.CHead;
	int dem = 0;
	int i = 20;
	while (C != NULL)
	{
		dem++;
		if (dem == select)
		{
			GoToXY(45, i);
			TxtColor(12);
			cout << C->c.NameCourse;
		}
		else {
			GoToXY(45, i);
			TxtColor(11);
			cout << C->c.NameCourse;
		}
		i++;
		C = C->CNext;
	}
	GoToXY(0, 24);
}
int SelectCoure(Node_Student*& s, Node_Year* Y, Node_Semester*& SM)
{
	int selection = 1;
	int n = CountCourse(SM);
	while (1)
	{
		PrintMenuCourse(selection, SM);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			Enroll(s, Y);
		}
	}
}
void PrintMenuRegist(int select)
{
	switch (select)
	{
	case 1:
		GoToXY(52, 30);
		TxtColor(12);
		cout << "Register for the course";
		GoToXY(61, 31);
		TxtColor(11);
		cout << "Back";
		GoToXY(0, 20);
		break;
	case 2:
		GoToXY(52, 30);
		TxtColor(11);
		cout << "Register for the course";
		GoToXY(61, 31);
		TxtColor(12);
		cout << "Back";
		GoToXY(0, 20);
		break;
	}
}
int SelectRegist()
{
	int selection = 1;
	while (1)
	{
		PrintMenuRegist(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 2)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 2;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
	}
}

void AddTail_CourseSigned(List_Course_Signed& lC, Node_Course_Signed*& C)
{
	if (lC.CHead == NULL)
	{
		lC.CHead = C;
		lC.CTail = C;
	}
	else {
		lC.CTail->CNext = C;
		lC.CTail = C;
	}
}
bool checkSameCourse(List_Course_Signed l, Node_Course*& C)
{
	Node_Course_Signed* p = l.CHead;
	while (p != NULL)
	{
		if (p->C.ses.day1 == C->c.ses.day1)
		{
			if (p->C.ses.time1 == C->c.ses.time1)
			{
				return false;
			}
		}
		if (p->C.ses.day2 == C->c.ses.day1)
		{
			if (p->C.ses.time2 == C->c.ses.time1)
			{
				return false;
			}
		}
		if (p->C.ses.day1 == C->c.ses.day2)
		{
			if (p->C.ses.time1 == C->c.ses.time2)
			{
				return false;
			}
		}
		if (p->C.ses.day2 == C->c.ses.day2)
		{
			if (p->C.ses.time2 == C->c.ses.time2)
			{
				return false;
			}
		}
		p = p->CNext;
	}
	return true;
}
void AddCourse_Signed(List_Course_Signed& l, Node_Course*& C, Node_Student*& s, int& STT)
{
	s->a.sumcourse++;
	Node_Course_Signed* p = new Node_Course_Signed;
	p->C.ID = C->c.ID;
	p->C.NameCourse = C->c.NameCourse;
	p->C.NameTeacher = C->c.NameTeacher;
	p->C.NumberofCredits = C->c.NumberofCredits;
	p->C.ses = C->c.ses;
	p->stt = s->a.sumcourse - 1;
	STT = p->stt;
	p->CNext = NULL;
	l.Sum_Course += 1;
	AddTail_CourseSigned(l, p);
}
void Register(Node_Student*& s, Node_Course*& C, Node_Semester*& SM)
{
	system("cls");
	if (C->c.TotalStudent >= C->c.MAX)
	{
		TxtColor(12);
		GoToXY(15, 3);
		cout << "The course is full of students" << endl;
		GoToXY(15, 4); system("pause");
	}
	else
	{
		switch (SM->s.Name_Semester)
		{
		case 1:
			if (s->a.l1.Sum_Course >= 5)
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "No more courses can be registered. Each student can only register for a maximum of 5 courses" << endl;
				GoToXY(15, 4); system("pause");

			}
			else if (!checkSameCourse(s->a.l1, C))
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "Course has been duplicated" << endl;
				GoToXY(15, 4); system("pause");
			}
			else
			{
				int STT = -1;
				AddCourse_Signed(s->a.l1, C, s, STT);
				AddTailCourse(SM, C, C->c.l, s, STT);
				C->c.TotalStudent += 1;

				TxtColor(12);
				GoToXY(15, 3);
				cout << "Sign up for the course successfully" << endl;
				GoToXY(15, 4); system("pause");
			}
			break;
		case 2:
			if (s->a.l2.Sum_Course >= 5)
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "No more courses can be registered. Each student can only register for a maximum of 5 courses" << endl;
				GoToXY(15, 4); system("pause");
			}
			else if (!checkSameCourse(s->a.l2, C))
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "Course has been duplicated" << endl;
				GoToXY(15, 4); system("pause");
			}
			else {
				int STT = -1;
				AddCourse_Signed(s->a.l1, C, s, STT);
				AddTailCourse(SM, C, C->c.l, s, STT);
				C->c.TotalStudent += 1;
				TxtColor(12);
				GoToXY(15, 3);
				cout << "Sign up for the course successfully" << endl;
				GoToXY(15, 4); system("pause");
			}
			break;
		case 3:
			if (s->a.l3.Sum_Course >= 5)
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "No more courses can be registered. Each student can only register for a maximum of 5 courses" << endl;
				GoToXY(15, 4); system("pause");
			}
			else if (!checkSameCourse(s->a.l3, C))
			{
				TxtColor(12);
				GoToXY(15, 3);
				cout << "Course has been duplicated" << endl;
				GoToXY(15, 4); system("pause");
			}
			else {
				int STT = -1;
				AddCourse_Signed(s->a.l1, C, s, STT);
				AddTailCourse(SM, C, C->c.l, s, STT);
				C->c.TotalStudent += 1;
				TxtColor(12);
				GoToXY(15, 3);
				cout << "Sign up for the course successfully" << endl;
				GoToXY(15, 4); system("pause");
			}
			break;
		}
	}
}
void ProcessRegist(Node_Student*& s, Node_Year* Y, Node_Semester*& SM, Node_Course*& C, int select)
{
	switch (select)
	{
	case 1:
		Register(s, C, SM);
		Courssing(s, Y, SM, C);
		break;
	case 2:
		EnrollCoured(s, Y, SM);
		break;
	}
}
void Courssing(Node_Student*& s, Node_Year* Y, Node_Semester*& SM, Node_Course*& C)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t********************************" << endl;
	TxtColor(7);
	cout << "\t\t\t\t\tName Course: " << C->c.NameCourse << endl;
	cout << "\t\t\t\t\tID: " << C->c.ID << endl;
	cout << "\t\t\t\t\tTeacher: " << C->c.NameTeacher << endl;
	cout << "\t\t\t\t\tNumber of credits: " << C->c.NumberofCredits << endl;
	cout << "\t\t\t\t\tSession: " << C->c.ses.day1 << " : " << C->c.ses.time1 << endl;
	cout << "\t\t\t\t\t         " << C->c.ses.day2 << " : " << C->c.ses.time2 << endl;
	cout << "\t\t\t\t\tNumber of students enrolled in the course: " << C->c.TotalStudent << "/" << C->c.MAX << endl;
	cout << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t\t*******************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t\t*   ";
	TxtColor(12);
	cout << "Register for the course";
	TxtColor(11);
	cout << "   *" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t\t*            ";
	TxtColor(11);
	cout << "Back";
	TxtColor(11);
	cout << "             *" << endl;
	cout << "\t\t\t\t\t\t*******************************" << endl;
	cout << endl << endl;
	int x = SelectRegist();
	ProcessRegist(s, Y, SM, C, x);
}
void ProcessCourse(Node_Student*& s, Node_Year* Y, Node_Semester*& SM, int select)
{
	int dem = 0;
	Node_Course* C = SM->s.l1.CHead;
	while (C != NULL)
	{
		dem++;
		if (dem == select)
		{
			Courssing(s, Y, SM, C);
			break;
		}
		C = C->CNext;
	}
}
void EnrollCoured(Node_Student*& s, Node_Year* Y, Node_Semester*& SM)
{
	Day d = System_date();
	int kt = 0;
	switch (SM->s.Name_Semester)
	{
	case 1:
		if (d.year == SM->s.start.year)
		{
			if (SM->s.BeginRegister.month == SM->s.EndRegister.month)
			{
				if (d.month == SM->s.BeginRegister.month)
				{
					if ((d.day >= SM->s.BeginRegister.day && d.day <= SM->s.EndRegister.day))
					{
						kt = 1;
						break;
					}
				}
			}
			else {
				if (d.month == SM->s.BeginRegister.month)
				{
					if (d.day >= SM->s.BeginRegister.day)
					{
						kt = 1;
					}
				}
				if (d.month == SM->s.EndRegister.month)
				{
					if (d.day <= SM->s.EndRegister.day)
					{
						kt = 1;
					}
				}
			}
		}
		break;
	case 2:
		if (d.year == SM->s.end.year)
		{
			if (SM->s.BeginRegister.month == SM->s.EndRegister.month)
			{
				if (d.month == SM->s.BeginRegister.month)
				{
					if ((d.day >= SM->s.BeginRegister.day && d.day <= SM->s.EndRegister.day))
					{
						kt = 1;
						break;
					}
				}
			}
			else {
				if (d.month == SM->s.BeginRegister.month)
				{
					if (d.day >= SM->s.BeginRegister.day)
					{
						kt = 1;
					}
				}
				if (d.month == SM->s.EndRegister.month)
				{
					if (d.day <= SM->s.EndRegister.day)
					{
						kt = 1;
					}
				}
			}
		}
		break;
	case 3:
		if (d.year == SM->s.end.year)
		{
			if (SM->s.BeginRegister.month == SM->s.EndRegister.month)
			{
				if (d.month == SM->s.BeginRegister.month)
				{
					if ((d.day >= SM->s.BeginRegister.day && d.day <= SM->s.EndRegister.day))
					{
						kt = 1;
						break;
					}
				}
			}
			else {
				if (d.month == SM->s.BeginRegister.month)
				{
					if (d.day >= SM->s.BeginRegister.day)
					{
						kt = 1;
					}
				}
				if (d.month == SM->s.EndRegister.month)
				{
					if (d.day <= SM->s.EndRegister.day)
					{
						kt = 1;
					}
				}
			}
		}
		break;
	}
	if (kt == 0)
	{
		TxtColor(12);
		GoToXY(15, 3);
		cout << "THIS IS NOT THE TIME TO SIGN UP FOR A COURSE" << endl;
		GoToXY(15, 4); system("pause");
		Enroll(s, Y);
	}
	else {
		system("cls");
		TxtColor(14);
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t                                                                                       " << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << "\t\t***************************************************************************************" << endl;
		cout << endl << endl;
		TxtColor(3);
		cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
		TxtColor(11);
		cout << "\t\t\t\t\t********************************" << endl;
		Node_Course* C = SM->s.l1.CHead;
		while (C != NULL)
		{
			if (C == SM->s.l1.CHead)
			{
				TxtColor(11);
				cout << "\t\t\t\t\t     ";
				TxtColor(12);
				cout << C->c.NameCourse << endl;
				C = C->CNext;
			}
			else {
				TxtColor(11);
				cout << "\t\t\t\t\t     ";
				TxtColor(11);
				cout << C->c.NameCourse << endl;
				C = C->CNext;
			}
		}
		TxtColor(11);
		cout << "\t\t\t\t\t********************************" << endl;
		cout << endl << endl;
		int x = SelectCoure(s, Y, SM);
		ProcessCourse(s, Y, SM, x);
	}
}
void ProcessSemester(Node_Student*& s, int select, Node_Year*& Y)
{
	switch (select)
	{
	case 1:
		system("cls");
		MenuCourse_Signed(Y->y.s.SHead, s, Y, s->a.l1);
		break;
	case 2:
		system("cls");
		MenuCourse_Signed(Y->y.s.SHead->Next, s, Y, s->a.l2);
		break;
	case 3:
		system("cls");
		MenuCourse_Signed(Y->y.s.STail, s, Y, s->a.l3);
		break;
	}
}
void ProcessSemesternow(Node_Student*& s, int select, Node_Year*& Y)
{
	switch (select)
	{
	case 1:
		system("cls");
		EnrollCoured(s, Y, Y->y.s.SHead);
		break;
	case 2:
		system("cls");
		EnrollCoured(s, Y, Y->y.s.SHead->Next);
		break;
	case 3:
		system("cls");
		EnrollCoured(s, Y, Y->y.s.STail);
		break;
	}
}
void Enroll(Node_Student*& s, Node_Year*& Y)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t********************************" << endl;
	Node_Semester* S = Y->y.s.SHead;
	while (S != NULL)
	{
		if (S == Y->y.s.SHead)
		{
			TxtColor(11);
			cout << "\t\t\t\t\t*         ";
			TxtColor(12);
			cout << "Semester " << S->s.Name_Semester;
			TxtColor(11);
			cout << "           *" << endl;
			S = S->Next;
		}
		else
		{
			TxtColor(11);
			cout << "\t\t\t\t\t*         ";
			TxtColor(11);
			cout << "Semester " << S->s.Name_Semester;
			TxtColor(11);
			cout << "           *" << endl;
			S = S->Next;
		}
	}
	cout << "\t\t\t\t\t********************************" << endl;
	cout << endl << endl;
	int x = SelectSemester(s, Y);
	ProcessSemesternow(s, x, Y);
}
int CountNode_Course_Signed(List_Course_Signed c)
{
	Node_Course_Signed* temp = c.CHead;
	int dem = 0;
	while (temp != NULL)
	{
		dem++;
		temp = temp->CNext;
	}
	return dem;
}
void PrintMenu_Course_Signed(int selection, List_Course_Signed c)
{
	int n = CountNode_Course_Signed(c);
	int dem = 1;
	int i = 20;
	Node_Course_Signed* temp = c.CHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			GoToXY(52, i);
			TxtColor(12);
			cout << temp->C.NameCourse;
			i++;
			dem++;
			temp = temp->CNext;
		}
		else
		{
			GoToXY(52, i);
			TxtColor(11);
			cout << temp->C.NameCourse;
			temp = temp->CNext;
			i++;
			dem++;
		}
	}
	GoToXY(0, 24);
}
int SelectMenu_Course_Signed(List_Course_Signed lc, Node_Student*& s, Node_Year*& y)
{
	int n = CountNode_Course_Signed(lc);
	int selection = 1;
	while (1)
	{
		PrintMenu_Course_Signed(selection, lc);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == n)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = n;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
		{
			return selection;
		}
		if (move == 'A')
		{
			ChooseSemester(s, y);
		}
	}
}
void ChooseSemester(Node_Student*& s, Node_Year* Y)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t********************************" << endl;
	Node_Semester* S = Y->y.s.SHead;
	while (S != NULL)
	{
		if (S == Y->y.s.SHead)
		{
			TxtColor(11);
			cout << "\t\t\t\t\t*         ";
			TxtColor(12);
			cout << "Semester " << S->s.Name_Semester;
			TxtColor(11);
			cout << "           *" << endl;
			S = S->Next;
		}
		else {
			TxtColor(11);
			cout << "\t\t\t\t\t*         ";
			TxtColor(11);
			cout << "Semester " << S->s.Name_Semester;
			TxtColor(11);
			cout << "           *" << endl;
			S = S->Next;
		}
	}
	cout << "\t\t\t\t\t********************************" << endl;
	cout << endl << endl;
	int x = SelectSemester(s, Y);
	ProcessSemester(s, x, Y);
}
void MenuCourse_Signed(Node_Semester*& S, Node_Student*& st, Node_Year*& y, List_Course_Signed& s)
{
	system("cls");
	Node_Course_Signed* temp = s.CHead;
	if (temp == NULL)
	{
		system("cls");
		GoToXY(30, 1); TxtColor(12);
		cout << "You haven't signed up any course yet.Please sign up for a course to continue." << endl;
		GoToXY(30, 2); system("pause");
		MenuStudentOption(st, y);
	}
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << st->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	while (temp != NULL)
	{
		TxtColor(11);
		cout << "\t\t\t\t\t\t    ";
		TxtColor(11);
		cout << temp->C.NameCourse;
		TxtColor(11);
		cout << "                            " << endl;
		temp = temp->CNext;
	}
	cout << "\t\t\t\t\t****************************************" << endl;
	o = SelectMenu_Course_Signed(s, st, y);
	ProcessMenuCourse_Signed(st, o, s, y, S);
}
void ProcessMenuCourse_Signed(Node_Student*& s, int selection, List_Course_Signed& lc, Node_Year*& y, Node_Semester*& S)
{
	int dem = 1;
	Node_Course_Signed* temp = lc.CHead;
	while (temp != NULL)
	{
		if (dem == selection)
		{
			MenuCourse_Signed_Option(s, temp, lc, y, S);
			break;
		}
		dem++;
		temp = temp->CNext;
	}
}
void PrintMenuCourse_Signed(int selection)
{
	switch (selection)
	{
	case 1:
		GoToXY(52, 20);
		TxtColor(12);
		cout << "VIEW YOUR SCOREBOARD";
		GoToXY(41, 21);
		TxtColor(11);
		cout << "REMOVE A COURSE FROM THE ENROLLED LIST";
		GoToXY(58, 22);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 2:
		GoToXY(52, 20);
		TxtColor(11);
		cout << "VIEW YOUR SCOREBOARD";
		GoToXY(41, 21);
		TxtColor(12);
		cout << "REMOVE A COURSE FROM THE ENROLLED LIST";
		GoToXY(58, 22);
		TxtColor(11);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	case 3:
		GoToXY(52, 20);
		TxtColor(11);
		cout << "VIEW YOUR SCOREBOARD";
		GoToXY(41, 21);
		TxtColor(11);
		cout << "REMOVE A COURSE FROM THE ENROLLED LIST";
		GoToXY(58, 22);
		TxtColor(12);
		cout << "LOG OUT";
		GoToXY(0, 24);
		break;
	}
}
int SelectMenuCourse_Signed(Node_Student*& st, List_Course_Signed s, Node_Year*& y, Node_Semester*& S)
{
	int selection = 1;
	while (1)
	{
		PrintMenuCourse_Signed(selection);
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			if (selection == 3)
			{
				selection = 1;
			}
			else
			{
				selection++;
			}
		}
		if (move == 'W' || move == 72)
		{
			if (selection == 1)
			{
				selection = 3;
			}
			else
			{
				selection--;
			}
		}
		if (move == 13)
			return selection;
		if (move == 'A')
		{
			MenuCourse_Signed(S, st, y, s);
		}
	}
}
void MenuCourse_Signed_Option(Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, Node_Year*& Y, Node_Semester*& S)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << s->a.a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t\t    ";
	TxtColor(12);
	cout << "VIEW YOUR SCOREBOARD";
	TxtColor(11);
	cout << "                  " << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t ";
	TxtColor(11);
	cout << "REMOVE A COURSE FROM THE ENROLLED LIST";
	TxtColor(11);
	cout << "    " << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t\t\t  ";
	TxtColor(11);
	cout << "LOG OUT";
	TxtColor(11);
	cout << "                                   " << endl;
	cout << "\t\t\t\t\t****************************************" << endl;
	int y = SelectMenuCourse_Signed(s, lc, Y, S);
	ProcessMenuCourse_Signed_Option(S, s, y, c, lc, Y);
}
void ProcessMenuCourse_Signed_Option(Node_Semester*& S, Node_Student*& s, int selection, Node_Course_Signed*& c, List_Course_Signed& lc, Node_Year*& y)
{
	switch (selection)
	{
	case 1:
		ViewScoreBoard(s, c, lc);
		GoToXY(26, 10); system("pause");
		MenuCourse_Signed_Option(s, c, lc, y, S);
		break;
	case 2:
		RemoveCourseEnrolled(S, s, c, lc, o, y);
		break;
	case 3:
		Menu(l1);
		break;
	}
}
void ViewScoreBoard(Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc)
{
	system("cls");
	TxtColor(12);
	cout << "\t\t\t\tCourse:" << c->C.NameCourse << endl << endl;
	TxtColor(11);
	cout << "\t\t\t  Full name: " << s->a.Surname << " " << s->a.Name << endl;
	cout << "\t\t\t  Studen ID: " << s->a.StudentID << endl << endl;
	TxtColor(12);
	cout << "\t\t\t\tYOUR LEARNING OUTCOMES" << endl;
	TxtColor(11);
	cout << "\t\t\t  Midterm Mark:" << c->C.s.Mid_term << endl;
	cout << "\t\t\t  Final Mark  :" << c->C.s.End_term << endl;
	cout << "\t\t\t  Plus Mark   :" << c->C.s.plus << endl;
	cout << "\t\t\t  Total Mark  :" << c->C.s.total << endl;
}
void Remove1Position(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l, int selection)
{
	int nNode = CountNode_Course_Signed(l);
	if (selection == 1)
	{
		RemoveHead(S, s, l);
	}
	else
	{
		if (nNode == selection)
		{
			RemoveTail(S, s, l);
		}
		else
		{
			int dem = 0;
			string line;
			Node_Course_Signed* temp = l.CHead;
			while (dem < nNode && temp->CNext != NULL)
			{
				dem++;
				if (dem == selection - 1)
				{
					line = temp->CNext->C.NameCourse;
					Node_Course_Signed* p = temp->CNext;
					temp->CNext = temp->CNext->CNext;
					delete p;
					l.Sum_Course--;
					break;
				}
				temp = temp->CNext;
			}
			Node_Course* C = S->s.l1.CHead;
			while (C != NULL)
			{
				if (C->c.NameCourse == line)
				{
					Node_Student* st = C->c.l.SHead;
					Node_Student* pre = C->c.l.SHead;
					int stt = -1;
					switch (S->s.Name_Semester)
					{
					case 1:
						while (st != NULL)
						{
							if (C->c.l.SHead->a.SocialID == s->a.SocialID)
							{
								stt = s->a.l1.CHead->stt;
								Node_Student* dts = C->c.l.SHead;
								C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
								dts->pNextCourse[stt] = NULL;
								C->c.TotalStudent--;
								break;
							}
							else 
							{
								if (st->a.StudentID == s->a.StudentID)
								{
									int stt5 = -1;
									Node_Course_Signed* tam2 = st->a.l1.CHead;

									while (tam2 != NULL)
									{

										if (tam2->C.NameCourse == line)
										{
											stt5 = tam2->stt;
											break;
										}
										tam2 = tam2->CNext;
									}
									pre->pNextCourse[stt] = st->pNextCourse[stt5];
									st->pNextCourse[stt5] = NULL;
									C->c.TotalStudent--;
									break;
								}
							}
							pre = st;
							Node_Course_Signed* tam = st->a.l1.CHead;
							while (tam != NULL)
							{
								if (tam->C.NameCourse == line)
								{
									stt = tam->stt;
									break;
								}
								tam = tam->CNext;
							}
							st = st->pNextCourse[stt];
						}
						break;
					case 2:
						while (st != NULL)
						{
							if (C->c.l.SHead->a.SocialID == s->a.SocialID)
							{
								stt = s->a.l2.CHead->stt;
								Node_Student* dts = C->c.l.SHead;
								C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
								dts->pNextCourse[stt] = NULL;
								C->c.TotalStudent--;
								break;
							}
							else 
							{
								if (st->a.StudentID == s->a.StudentID)
								{
									int stt2 = -1;
									Node_Course_Signed* tam2 = st->a.l2.CHead;
									while (tam2 != NULL)
									{
										if (tam2->C.NameCourse == line)
										{
											stt2 = tam2->stt;
											break;
										}
										tam2 = tam2->CNext;
									}
									pre->pNextCourse[stt] = st->pNextCourse[stt2];
									st->pNextCourse[stt2] = NULL;
									C->c.TotalStudent--;
									break;
								}
							}
							pre = st;
							Node_Course_Signed* tam = st->a.l2.CHead;
							while (tam != NULL)
							{
								if (tam->C.NameCourse == line)
								{
									stt = tam->stt;
									break;
								}
								tam = tam->CNext;
							}
							st = st->pNextCourse[stt];
						}
						break;
					case 3:
						while (st != NULL)
						{
							if (C->c.l.SHead->a.SocialID == s->a.SocialID)
							{
								stt = s->a.l3.CHead->stt;
								Node_Student* dts = C->c.l.SHead;
								C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
								dts->pNextCourse[stt] = NULL;
								C->c.TotalStudent--;
								break;
							}
							else 
							{
								if (st->a.StudentID == s->a.StudentID)
								{
									int stt3 = -1;
									Node_Course_Signed* tam2 = st->a.l3.CHead;

									while (tam2 != NULL)
									{
										if (tam2->C.NameCourse == line)
										{
											stt3 = tam2->stt;
											break;
										}
										tam2 = tam2->CNext;
									}
									pre->pNextCourse[stt] = st->pNextCourse[stt3];
									st->pNextCourse[stt3] = NULL;
									C->c.TotalStudent--;
									break;
								}
							}
							pre = st;
							Node_Course_Signed* tam = st->a.l3.CHead;
							while (tam != NULL)
							{
								if (tam->C.NameCourse == line)
								{
									stt = tam->stt;
									break;
								}
								tam = tam->CNext;
							}

							st = st->pNextCourse[stt];
						}
						break;
					}
				}
				C = C->CNext;
			}
		}
	}
}

void RemoveCourseEnrolled(Node_Semester*& S, Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, int selection, Node_Year*& y)
{
	int dem = 0;
	Node_Course_Signed* temp = lc.CHead;
	while (temp != NULL)
	{
		dem++;
		if (dem == selection)
		{
			system("cls");
			GoToXY(40, 5); TxtColor(12);
			cout << "ARE YOU SURE TO REMOVE THIS COURSE" << endl;
			GoToXY(40, 6); TxtColor(14);
			cout << "Press A to Cancel or Press Enter to Remove" << endl;
			SelectRemove(S, s, c, lc, selection, y);
			break;
		}
		temp = temp->CNext;
	}
}
void SelectRemove(Node_Semester*& S, Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, int selection, Node_Year*& y)
{
	while (true)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			Remove1Position(S, s, lc, selection);
			system("pause");
			MenuCourse_Signed(S, s, y, lc);
			break;
		}
		if (move == 'A')
		{
			MenuCourse_Signed_Option(s, c, lc, y, S);
			break;
		}
	}
}
int CountNode_Course(Node_Course* c, List_Course lC)
{
	Node_Course* temp = lC.CHead;
	int dem = 0;
	while (temp != NULL)
	{
		dem++;
		temp = temp->CNext;
	}
	return dem;
}
void RemoveHead(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l)
{
	if (l.CHead == NULL)
	{
		cout << "You haven't signed up any courses" << endl;
	}
	else
	{
		string line = l.CHead->C.NameCourse;
		Node_Course_Signed* temp = l.CHead;
		l.CHead = l.CHead->CNext;
		delete temp;
		l.Sum_Course--;
		Node_Course* C = S->s.l1.CHead;
		while (C != NULL)
		{
			if (C->c.NameCourse == line)
			{
				Node_Student* st = C->c.l.SHead;
				Node_Student* pre = C->c.l.SHead;
				int stt = -1;
				switch (S->s.Name_Semester)
				{
				case 1:
					while (st != NULL)
					{
						if (C->c.l.SHead->a.SocialID == s->a.SocialID)
						{
							stt = s->a.l1.CHead->stt;
							Node_Student* dts = C->c.l.SHead;
							C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
							dts->pNextCourse[stt] = NULL;
							C->c.TotalStudent--;
							break;
						}
						else
						{
							if (st->a.StudentID == s->a.StudentID)
							{
								int stt5 = -1;
								Node_Course_Signed* tam2 = st->a.l1.CHead;

								while (tam2 != NULL)
								{
									if (tam2->C.NameCourse == line)
									{
										stt5 = tam2->stt;
										break;
									}
									tam2 = tam2->CNext;
								}
								pre->pNextCourse[stt] = st->pNextCourse[stt5];
								st->pNextCourse[stt5] = NULL;
								C->c.TotalStudent--;
								break;
							}
						}
						pre = st;
						Node_Course_Signed* tam = st->a.l1.CHead;
						while (tam != NULL)
						{
							if (tam->C.NameCourse == line)
							{
								stt = tam->stt;
								break;
							}
							tam = tam->CNext;
						}
						st = st->pNextCourse[stt];
					}
					break;
				case 2:
					while (st != NULL)
					{
						if (C->c.l.SHead->a.SocialID == s->a.SocialID)
						{
							stt = s->a.l2.CHead->stt;
							Node_Student* dts = C->c.l.SHead;
							C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
							dts->pNextCourse[stt] = NULL;
							C->c.TotalStudent--;
							break;
						}
						else
						{
							if (st->a.StudentID == s->a.StudentID)
							{
								int stt6 = -1;
								Node_Course_Signed* tam2 = st->a.l2.CHead;

								while (tam2 != NULL)
								{
									if (tam2->C.NameCourse == line)
									{
										stt6 = tam2->stt;
										break;
									}
									tam2 = tam2->CNext;
								}
								pre->pNextCourse[stt] = st->pNextCourse[stt6];
								st->pNextCourse[stt6] = NULL;
								C->c.TotalStudent--;
								break;
							}
						}
						pre = st;
						Node_Course_Signed* tam = st->a.l2.CHead;
						while (tam != NULL)
						{
							if (tam->C.NameCourse == line)
							{
								stt = tam->stt;
								break;
							}
							tam = tam->CNext;
						}
						st = st->pNextCourse[stt];
					}
					break;
				case 3:
					while (st != NULL)
					{
						if (C->c.l.SHead->a.SocialID == s->a.SocialID)
						{
							stt = s->a.l3.CHead->stt;
							Node_Student* dts = C->c.l.SHead;
							C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
							dts->pNextCourse[stt] = NULL;
							C->c.TotalStudent--;
							break;
						}
						else 
						{
							if (st->a.StudentID == s->a.StudentID)
							{
								int stt7 = -1;
								Node_Course_Signed* tam2 = st->a.l3.CHead;

								while (tam2 != NULL)
								{
									if (tam2->C.NameCourse == line)
									{
										stt7 = tam2->stt;
										break;
									}
									tam2 = tam2->CNext;
								}
								pre->pNextCourse[stt] = st->pNextCourse[stt7];
								st->pNextCourse[stt7] = NULL;
								C->c.TotalStudent--;
								break;
							}
						}
						pre = st;
						Node_Course_Signed* tam = st->a.l3.CHead;
						while (tam != NULL)
						{
							if (tam->C.NameCourse == line)
							{
								stt = tam->stt;
								break;
							}
							tam = tam->CNext;
						}
						st = st->pNextCourse[stt];
					}
					break;
				}
			}
			C = C->CNext;
		}
	}
}
void RemoveTail(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l)
{
	string line = l.CTail->C.NameCourse;
	for (Node_Course_Signed* a = l.CHead; a != NULL; a = a->CNext)
	{
		if (a->CNext == l.CTail)
		{
			Node_Course_Signed* temp = l.CTail;
			a->CNext = NULL;
			delete temp;
			l.CTail = a;
			l.Sum_Course--;
			break;
		}
	}
	Node_Course* C = S->s.l1.CHead;
	while (C != NULL)
	{
		if (C->c.NameCourse == line)
		{
			Node_Student* st = C->c.l.SHead;
			Node_Student* pre = C->c.l.SHead;
			int stt = -1;
			switch (S->s.Name_Semester)
			{
			case 1:
				while (st != NULL)
				{
					if (C->c.l.SHead->a.SocialID == s->a.SocialID)
					{
						stt = s->a.l1.CHead->stt;
						Node_Student* dts = C->c.l.SHead;
						C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
						dts->pNextCourse[stt] = NULL;
						C->c.TotalStudent--;
						break;
					}
					else
					{
						if (st->a.StudentID == s->a.StudentID)
						{
							int stt8 = -1;
							Node_Course_Signed* tam2 = st->a.l1.CHead;
							while (tam2 != NULL)
							{
								if (tam2->C.NameCourse == line)
								{
									stt8 = tam2->stt;
									break;
								}
								tam2 = tam2->CNext;
							}
							pre->pNextCourse[stt] = st->pNextCourse[stt8];
							st->pNextCourse[stt8] = NULL;
							C->c.TotalStudent--;
							break;
						}
					}
					pre = st;
					Node_Course_Signed* tam = st->a.l1.CHead;
					while (tam != NULL)
					{
						if (tam->C.NameCourse == line)
						{
							stt = tam->stt;
							break;
						}
						tam = tam->CNext;
					}
					st = st->pNextCourse[stt];
				}
				break;
			case 2:
				while (st != NULL)
				{
					if (C->c.l.SHead->a.SocialID == s->a.SocialID)
					{
						stt = s->a.l2.CHead->stt;
						Node_Student* dts = C->c.l.SHead;
						C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
						dts->pNextCourse[stt] = NULL;
						C->c.TotalStudent--;
						break;
					}
					else
					{
						if (st->a.StudentID == s->a.StudentID)
						{
							int stt9 = -1;
							Node_Course_Signed* tam2 = st->a.l2.CHead;
							while (tam2 != NULL)
							{
								if (tam2->C.NameCourse == line)
								{
									stt9 = tam2->stt;
									break;
								}
								tam2 = tam2->CNext;
							}
							pre->pNextCourse[stt] = st->pNextCourse[stt9];
							st->pNextCourse[stt9] = NULL;
							C->c.TotalStudent--;
							break;
						}
					}
					pre = st;
					Node_Course_Signed* tam = st->a.l2.CHead;
					while (tam != NULL)
					{
						if (tam->C.NameCourse == line)
						{
							stt = tam->stt;
							break;
						}
						tam = tam->CNext;
					}

					st = st->pNextCourse[stt];
				}
				break;
			case 3:
				while (st != NULL)
				{
					if (C->c.l.SHead->a.SocialID == s->a.SocialID)
					{
						stt = s->a.l3.CHead->stt;
						Node_Student* dts = C->c.l.SHead;
						C->c.l.SHead = C->c.l.SHead->pNextCourse[stt];
						dts->pNextCourse[stt] = NULL;
						C->c.TotalStudent--;
						break;
					}
					else 
					{
						if (st->a.StudentID == s->a.StudentID)
						{
							int stt10 = -1;
							Node_Course_Signed* tam2 = st->a.l3.CHead;

							while (tam2 != NULL)
							{
								if (tam2->C.NameCourse == line)
								{
									stt10 = tam2->stt;
									break;
								}
								tam2 = tam2->CNext;
							}
							pre->pNextCourse[stt] = st->pNextCourse[stt10];
							st->pNextCourse[stt10] = NULL;
							C->c.TotalStudent--;
							break;
						}
					}
					pre = st;
					Node_Course_Signed* tam = st->a.l3.CHead;
					while (tam != NULL)
					{
						if (tam->C.NameCourse == line)
						{
							stt = tam->stt;
							break;
						}
						tam = tam->CNext;
					}
					st = st->pNextCourse[stt];
				}
				break;
			}
		}
		C = C->CNext;
	}
}

void RemoveHeadCourse(List_Course& l)
{
	if (l.CHead == NULL)
	{
		cout << "No course created." << endl;
	}
	else
	{
		Node_Course* temp = l.CHead;
		l.CHead = l.CHead->CNext;
		delete temp;
	}
}
void RemoveTailCourse(List_Course& l)
{
	Node_Course* p = l.CHead;
	for (Node_Course* a = l.CHead; a != NULL; a = a->CNext)
	{
		if (a == l.CTail)
		{
			Node_Course* temp = a;
			p->CNext = a->CNext;
			delete temp;
			break;
		}
		p = a;
	}
}
void Remove1Course(Node_Course* c, List_Course& l)
{
	if (l.CHead->c.NameCourse == c->c.NameCourse)
	{
		RemoveHeadCourse(l);
	}
	else
	{
		if (l.CTail->c.NameCourse == c->c.NameCourse)
		{
			RemoveTailCourse(l);
		}
		else
		{
			Node_Course* temp = l.CHead;
			Node_Course* temp1 = l.CHead;
			while (temp != NULL)
			{
				if (temp->c.NameCourse == c->c.NameCourse)
				{
					Node_Course* p = temp;
					temp1->CNext = temp->CNext;
					delete p;
					break;
				}
				temp1 = temp;
				temp = temp->CNext;
			}
		}
	}
}
void RemoveCourseCreated(Node_Course*& c, Node_Semester*& S, Node_Year* y, Account a)
{
	system("cls");
	TxtColor(14);
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t                                                                                       " << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << endl << endl;
	TxtColor(3);
	cout << "\t\t\t\t\t\tUSERNAME: " << a.name << endl << endl;
	TxtColor(11);
	cout << "\t\t\t\t\t****************************************" << endl;
	cout << "\t\t\t\t\t    ";
	TxtColor(12);
	cout << "ARE YOU SURE TO REMOVE THIS COURSE " << endl;
	cout << "\t\t\t\t\t    "; TxtColor(14);
	cout << "Press A to Cancel or Press Enter to Remove" << endl;
	ConfirmRemoveCourse(c, S, y, a);
}
void ConfirmRemoveCourse(Node_Course*& c, Node_Semester*& S, Node_Year* y, Account a)
{
	int kt = 0;
	while (kt == 0)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 13)
		{
			kt = 1;
			Remove1Course(c, S->s.l1);
		}
		if (move == 'A')
		{
			kt = 1;
			Coursed(a, S, y, c);
		}
	}
}
