#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <cstdlib>
struct ProfileStaff
{
	string User;
	string Name;
	string Gender;
	string Day;
	string Month;
	string Year;
	string SocialID;
};
struct NodeProfile
{
	ProfileStaff data;
	NodeProfile* pNext;
};
struct List_Profile_Staff
{
	NodeProfile* pHead;
	NodeProfile* pTail;
};
struct DayofBirth
{
	string Day;
	string Month;
	string Year;
};
struct Score
{
	float Mid_term = -1;
	float End_term = -1;
	float total = -1;
	float plus = -1;
};
struct  Session
{
	string day1;
	string time1;
	string day2;
	string time2;
};
struct Course_Signed
{
	string NameCourse;
	string ID;
	string NameTeacher;
	int NumberofCredits;
	Session ses;
	Score s;
};
struct Node_Course_Signed
{
	int stt;
	Course_Signed C;
	Node_Course_Signed* CNext;
};
struct List_Course_Signed
{
	int semester;
	int Sum_Course;
	Node_Course_Signed* CHead;
	Node_Course_Signed* CTail;
};
struct Account
{
	string name;
	string pass;
};
struct Node
{
	Account a;
	Node* Next;
};
struct List_Account_Staff
{
	Node* Head;
	Node* Tail;
};
struct Student
{
	Account a;
	string Surname;
	string Name;
	string Gender;
	string StudentID;
	DayofBirth Date;
	string SocialID;
	List_Course_Signed l1;
	List_Course_Signed l2;
	List_Course_Signed l3;
	int sumcourse;
	string Class;
};
struct Node_Student
{
	Student a;
	int n;
	Node_Student* pNext;
	Node_Student** pNextCourse;
};
struct List_Student
{
	Node_Student* SHead;
	Node_Student* STail;
};
struct Course
{
	string NameCourse;
	string ID;
	string NameTeacher;
	int NumberofCredits;
	int TotalStudent = 0;
	int MAX;
	Session ses;
	List_Student l;
};
struct Node_Course
{
	Course c;
	Node_Course* CNext;
};
struct List_Course
{
	Node_Course* CHead;
	Node_Course* CTail;
};
struct Class
{
	string Name_Class;
	int Totalnumberstudent = 0;
	int MAX = 50;
	List_Student ls;
};
struct Node_Class
{
	Class c;
	Node_Class* CNext;
};
struct List_Class
{
	Node_Class* CHead;
	Node_Class* CTail;
};
struct Day
{
	int day = 0;
	int month = 0;
	int year = 0;
};
struct Semester
{
	int Name_Semester;
	Day start;
	Day end;
	List_Course l1;
	Day BeginRegister;
	Day EndRegister;
};
struct Node_Semester
{
	Semester s;
	Node_Semester* Next;
};
struct List_Semester
{
	Node_Semester* SHead;
	Node_Semester* STail;
};
struct Year
{
	string start;
	string end;
	List_Semester s;
	List_Class l;
};
struct Node_Year
{
	Year y;
	Node_Year* yNext;
};
struct List_Year
{
	Node_Year* YHead;
	Node_Year* YTail;
};
static List_Account_Staff l1;
void Menu(List_Account_Staff& l1);
int SelectMenu();
void ProcessMenu(int choose, List_Account_Staff& l1);
void PrintMenu(int selection);
void Menu_InPutLogin(int choose, List_Account_Staff& l1, string cache);
void SelectMenu_InPutLogin(int choose, List_Account_Staff& l1);
void TxtColor(int i);
bool Login_Staff(List_Account_Staff& l, Account x);
void ReadFileAccount_Staff(List_Account_Staff& l);
void Add_Tail_Staff(List_Account_Staff& l, Node* p);
Node* CreateNode(Account x);
void List_Account_Empty_Staff(List_Account_Staff& l);
void GoToXY(int pX, int pY);
void PrintMenuStaffOption(int selection);
int SelectMenuStaffOption();
void ProcessMenuStaffOption(Account a, int selection, List_Account_Staff& l1, string cache);
void SelectMenu_Login(int choose, List_Account_Staff& l1);
void PrintMenuStudentOption(int selection);
int SelectMenuStudentOption();
void ChangePassword_Student(Node_Student*& S);
void WritefileAccount_Staff(List_Account_Staff& l);
void ChangePassword_Staff(List_Account_Staff& l, string cache);
void List_Profile_Empty_Staff(List_Profile_Staff& l);
NodeProfile* CreateNodeProfile(ProfileStaff x);
void Add_Tail_Staff_Profile(List_Profile_Staff& l, NodeProfile* p);
void ReadFileProfile_Staff(List_Profile_Staff& l);
void Output(ProfileStaff p);
void MenuOption(Account x, List_Account_Staff& l1, string cache);
void Select_Profile(Account x, string cache, List_Account_Staff& l1);
void List_Student_Empty(List_Student& l);
Node_Student* Create(Student s);
void AddTailClass(List_Student& l, Node_Student* p);
void List_Class_Empty(List_Class& l);
Node_Class* Create(Class c);
void AddHead(List_Class& l, Node_Class* p);
void List_Semester_Empty(List_Semester& l);
void AddCourse_Signed(List_Course_Signed& l, Node_Course*& C, Node_Student*& s, int& STT);
void AddTailCourse(Node_Semester*& S, Node_Course*& C, List_Student& l, Node_Student* p, int STT);
void List_Course_Empty(List_Course& lC);
Node_Course* Create_Course(Course c);
void AddTail_Course(List_Course& lC, Node_Course*& p);
Node_Semester* Create(Semester s);
void AddTail_Semester(List_Semester& l, Node_Semester* p);
void List_Year_Empty(List_Year& l);
Node_Year* Create(Year y);
void AddHead_Year(List_Year& l, Node_Year*& p);
int CountNode(List_Year l);
void PrintMenuSchoolYear(int selection);
int SelectMenu_SchoolYear(Account x, string cache);
void ProcessMenuSChoolYear(Account a, int selection, List_Year& lY, List_Account_Staff& l1);
void Menu_SchoolYear(Account a, List_Year& lY, List_Account_Staff& l1);
void MenuCreateSchoolYear(List_Year& lY, Account a);
void MenuSchoolYear(Account a, Node_Year*& p, List_Year& lY);
int SelectMenuYear(Account x);
void ProcessMenuYear(Account a, int selection, Node_Year*& p, List_Year& lY);
void PrintMenuYear(int selection);
int CountNode_Class(List_Class l);
void MenuClass(Account a, Node_Year*& p);
int SelectMenu_Class(Node_Year*& Y, Account x);
void PrintMenuClass(int selection, Node_Year*& Y);
void MenuClass(Account a, Node_Year*& p);
void ProcessMenuClass(Account a, int selection, Node_Year*& Y);
void MenuCreateClass(Node_Year*& Y, Account a);
void ClassProcess(Account a, Node_Year*& Y, Node_Class*& C);
void PrintInfClass(int selection);
int SelectClass(Account a, Node_Year*& p);
void ProcessClass(Account a, int selection, Node_Year*& Y, Node_Class*& C);
void MenuAddStudent(Account a, Node_Class*& C);
void AddStudent(Node_Class*& C);
void ViewClassList(Account a, Node_Class*& C);
Day System_date();
bool checkTimeYear(Year y);
bool checkSame(Year y);
void MenuSemester(Account a, List_Semester& lS, Node_Year*& y);
void PrintMenuSemester(int selection);
int SelectMenu_Semester(Account x, Node_Year*& Y);
void ProcessMenuSemester(Account a, int selection, List_Semester& lS, Node_Year*& y);
void SeeScore(Account a, Node_Year* Y, Node_Class*& C);
void ProcessStudent(Account a, int select, Node_Year* Y, Node_Class*& C);
void MenuStudent(Account a, Node_Student*& s, int total);
int SelectStudent(Account a, Node_Year* Y, Node_Class*& C);
void PrintMenuStudent(int select, Node_Class*& C);
void PrintMenuSemesterOption(int selection);
int SelectMenuSemesterOption(Account a, Node_Semester*& S, Node_Year*& y);
void ProcessMenuSemesterOption(Account a, int selection, Node_Semester*& S, Node_Year* y);
void MenuSemesterOption(Account x, Node_Semester*& S, Node_Year*& y);
void CreateDateOfSemester(Account a, int selection, Node_Semester* s, Node_Year*& y);
void Select_Semester(Account x, Node_Semester* S, Node_Year* y);
void SelectCreateSchoolYear(Account a);
void SelectCreateDateOfSemester(Account a, int selection, Node_Semester* s, Node_Year*& y);
void MenuCreateSession(Node_Semester*& S, List_Course& lC, Account a);
bool CheckSessionDate(Day a, Day b, Day c);
void CreateSession(Node_Semester*& S, List_Course& lC, Account a);
int CountNode_Course(Node_Course* c, List_Course lC);
void Remove1Course(Node_Course* c, List_Course& l);
void RemoveCourseCreated(Node_Course*& c, Node_Semester*& S, Node_Year* y, Account a);
void ConfirmRemoveCourse(Node_Course*& c, Node_Semester*& S, Node_Year* y, Account a);
void MenuStudentOption(Node_Student*& s, Node_Year*& Y);
void MenuSelectSchoolYear(List_Year& lY);
void PrintMenuSelectSchoolYear(int selection);
int SelectMenu_SelectSchoolYear();
void ProcessMenuSelectSchoolYear(int selection);
void MenuSelectClass(Node_Year*& p);
void PrintMenuSelectClass(int selection, Node_Year*& Y);
int SelectMenu_SelectClass(Node_Year*& Y);
void ProcessMenuSelectClass(int selection, Node_Year*& Y);
void MenuLoginStudent(Node_Year*& y, Node_Class*& c);
void SelectMenuLoginStudent(Node_Year*& y, Node_Class*& c);
bool CheckLoginStudent(Node_Class*& c, Account x, Node_Student*& s);
void LoginStudent(Node_Class*& c, Node_Year*& p);
void SelectMenu_InPutLoginStudent(Node_Year*& p, Node_Class*& c);
void SelectCreateClass(Account a, Node_Year*& y);
bool CheckSameClass(Class c, List_Class& lc);
void ProcessMenuStudentOption(Node_Student*& s, Node_Year*& Y, int selection);
void Enroll(Node_Student*& s, Node_Year*& Y);
int SelectSemester(Node_Student*& s, Node_Year*& Y);
void ProcessSemester(Node_Student*& s, int select, Node_Year*& Y);
void EnrollCoured(Node_Student*& s, Node_Year* Y, Node_Semester*& SM);
int CountCourse(Node_Semester*& SM);
void PrintMenuCourse(int select, Node_Semester*& SM);
int SelectCoure(Node_Student*& s, Node_Year* Y, Node_Semester*& SM);
void Courssing(Node_Student*& s, Node_Year* Y, Node_Semester*& SM, Node_Course*& C);
void PrintMenuRegist(int select);
int SelectRegist();
void ProcessRegist(Node_Student*& s, Node_Year* Y, Node_Semester*& SM, Node_Course*& C, int select);
void AddTail_CourseSigned(List_Course_Signed& lC, Node_Course_Signed*& C);
void Register(Node_Student*& s, Node_Course*& C, Node_Semester*& SM);
bool checkSameCourse(List_Course_Signed l, Node_Course*& C);
int CountNode_Course_Signed(List_Course_Signed c);
void PrintMenu_Course_Signed(int selection, List_Course_Signed c);
int SelectMenu_Course_Signed(List_Course_Signed lc, Node_Student*& s, Node_Year*& y);
void MenuCourse_Signed(Node_Semester*& S, Node_Student*& st, Node_Year*& y, List_Course_Signed& s);
void ProcessMenuCourse_Signed(Node_Student*& s, int selection, List_Course_Signed& lc, Node_Year*& y, Node_Semester*& S);
void PrintMenuCourse_Signed(int selection);
int SelectMenuCourse_Signed(Node_Student*& st, List_Course_Signed s, Node_Year*& y, Node_Semester*& S);
void MenuCourse_Signed_Option(Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, Node_Year*& Y, Node_Semester*& S);
void ProcessMenuCourse_Signed_Option(Node_Semester*& S, Node_Student*& s, int selection, Node_Course_Signed*& c, List_Course_Signed& lc, Node_Year*& y);
void ViewScoreBoard(Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc);
void RemoveHead(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l);
void RemoveTail(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l);
void RemoveHeadCourse(List_Course& l);
void RemoveTailCourse(List_Course& l);
void Remove1Position(Node_Semester*& S, Node_Student*& s, List_Course_Signed& l, int selection);
void RemoveCourseEnrolled(Node_Semester*& S, Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, int selection, Node_Year*& y);
void SelectRemove(Node_Semester*& S, Node_Student*& s, Node_Course_Signed*& c, List_Course_Signed& lc, int selection, Node_Year*& y);
void show_student_profile(Node_Student*& s);
int SelectListCource(Account a, Node_Semester*& S, Node_Year* y);
void ViewListCourse(Account a, Node_Semester*& S, Node_Year* y);
void PrintInforCourse(int selection);
int SelectInforCourse(Account a, Node_Semester*& S, Node_Year* y);
void Coursed(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ProcessListCourse(Account a, int select, Node_Semester*& S, Node_Year* y);
void ProcessInforCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ViewTheScoreBoardOfACourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void PrintExport(int select);
int SelectExport(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void Export(Node_Course*& C, Node_Semester*& S);
void ImPort(Node_Course*& C, Node_Semester*& S);
void ProcessExport(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, int select);
void ExportCSV(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void MenuUpdateCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void PrintMenuUpdateCourse(int selection);
int SelectMenuUpdateCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& c);
void ProcessMenuUpdateCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeNameOfCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeID(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeNameOfTeacher(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeNumberOfCredits(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeMaxNumberOfStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void PrintStudentofCourse(Node_Semester*& S, int select, Node_Course*& C);
int SelectStudentofCourse(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void PrintMenuMark(int selection);
int SelectMarkChange(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeMark(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s, int select);
void ProcessMarkChange(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s, int select);
void ChangeStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C, Node_Student*& s);
void ProcessStudentofCourse(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeScoreStudent(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChangeTheTimetable(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ProcessMenuSelectSession(Account a, int select, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void PrintMenuSelectSession(int select);
int SelectMenuSession(Account a, Node_Semester*& S, Node_Year* y, Node_Course*& C);
void ChooseSemester(Node_Student*& s, Node_Year* Y);