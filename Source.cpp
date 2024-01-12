#include<iostream>
#include<fstream>
using namespace std;
class Helper
{
public:
	static int stringLength(const char*);
	static char* GetStringFromBuffer(const char*);
	static bool stringCompare(char*, const char*);
	static void StringConcatenate(const char*&, char*);
};
int Helper::stringLength(const char* cstr)
{
	int count = 0;
	for (int i = 0; cstr[i] != '\0'; i++) {
		count++;
	}
	return count;
}
char* Helper::GetStringFromBuffer(const char* buffer)
{
	int strLen = Helper::stringLength(buffer);
	char* str = 0;

	if (strLen > 0)
	{
		str = new char[strLen + 1];
		char* tempDest = str;
		for (const char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;
		}
		*tempDest = '\0';
	}
	return str;
}
bool Helper::stringCompare(char* str1, const char* str2)
{
	int count = 0;
	if (stringLength(str1) == stringLength(str2)) {
		for (int i = 0; i < stringLength(str1); i++) {
			if (str1[i] == str2[i]) {
				count++;
			}
		}
		if (count == stringLength(str1)) {
			return true;
		}
	}
	else {
		return false;
	}
}
void Helper::StringConcatenate(const char*& cstring1, char* cstring2)
{
	int str1Len, str2Len;
	str1Len = strlen(cstring1);
	str2Len = strlen(cstring2);
	char* newString = new char[str1Len + str2Len + 1];
	int i;
	for (i = 0; i < str1Len; i++) {
		newString[i] = cstring1[i];
	}
	for (int j = 0; j < str2Len; j++) {
		newString[i] = cstring2[j];
		i++;
	}
	newString[str1Len + str2Len] = '\0';
	cstring1 = 0;
	cstring1 = newString;
	newString = 0;
}
class Object;
class Date;
class FaceBook;
class User;
class Page;
class Post;
class Comment;
class Memory;
class Object
{
	char* ID;
public:
	void setId(char*);
	virtual  char* getUserId();
	virtual void printName();
	virtual char* getId();
	virtual void setTimeline(Post*);
	virtual ~Object();
};
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	static Date CurrentDate;
	static void SetCurrentDate(int, int, int);
	bool operator<=(Date&);
	void ReadDataFromFile(ifstream&);
	int getDateDay();
	int getDateMonth();
	int getDateYear();
	void printDate();
	bool memoryDateCheck();
};
class FaceBook
{
	User* currentUser;
	Page** pages;
	User** users;
	Post** posts;
	int totalpages;
	int totalUsers;
	int totalPosts;
	int totalComments;
public:
	FaceBook();
	void LoadAllData();
	void setCurrentUser(const char*);
	User* getCurrentUser();
	Page* searchPageByID(const char*);
	User* searchUserByID(const char*);
	Object* searchObjectById(char*);
	Post* searchPostById(const char*);
	void LoadPagesFromFile();
	void LoadUsersFromFile();
	void LoadPosts();
	void LoadComments();
	void viewLikedList(const char*);
	void likePost(const char*);
	void PostComment(const char*, const char*);
	void ViewPost(const char*);
	void seeYourMemories();
	void viewPage(const char*);
	void memory(const char* str, const char* txt, Object* currentUser);
	void shareMemory(const char*, const char*);
	void Run();
	~FaceBook();
};
class User : public Object
{
	char* ID;
	char* Fname;
	char* Lname;
	Page** LikedPages;
	int pageCount;
	User** friendList;
	Post** Timeline;
	int friendCount = 0;
	int timeLineCount = 0;
public:
	User();
	void readDataFromFile(ifstream&);
	void LikePage(Page*&);
	void AddFriend(User*&);
	void setTimeline(Post*);
	char* getId();
	void ViewFriendList();
	void PrintListview();
	void viewTimeline();
	void viewHomepage();
	void printName();
	int getPageCount();
	void PrintUserPosts();
	void memoryCheck();
	~User();
};
class Page : public Object
{
	char* ID;
	char* Title;
	Post** Timeline;
	int timeLineCount = 0;
public:
	Page();
	void setTimeline(Post*);
	void setPageId(char*);
	char* getId();
	char* getPageTitle();
	void readDataFromFile(ifstream&);
	void printPagesPosts();
	void printName();
	void viewTimeline();
	~Page();
};
class Activity
{
	int Type;
	char* value;
public:
	void ReadDataFromFile(ifstream&);
	char* getValue();
	int getType();
	void activityPrint();
	~Activity();
};
class Post : public Object
{
	char* ID;
	char* Text;
	Date SharedDate;
	Activity* activity;
	Object* SharedBy;
	Object** LikedBy;
	int LikesCount = 0;
	Comment** comments;
	int commentsCount = 0;
public:
	Post();
	Post(char*, Object*);
	void SetSharedBy(Object*);
	void SetLikedBy(Object*);
	void ReadDataFromFile(ifstream&);
	void AddComment(Comment*);
	Comment** getComments();
	int getCommentsCount();
	char* getPostText();
	Date getSharedDate();
	char* getPostId();
	bool dateCheck();
	Activity* getActivity();
	void viewPost(bool, bool);
	void viewlikes();
	void dateDifference();
	~Post();
};
class Comment
{
	Object* commentBy;
	char* Comment_ID;
	char* text;
	int TotalComments;
public:
	Comment();
	Comment(User* current_user, const char* Text);
	void setValues(char*, char*, Object*);
	Object* getCommentBy();
	//char* getCommentText();
	void viewCommentBy();
	void viewCommentText();
	void setTotalComments(int);
	int getTotalComments();
	~Comment();
};

//Date class Definition
Date::Date()
{
}
void Date::SetCurrentDate(int d, int m, int y)
{
	CurrentDate.day = d;
	CurrentDate.month = m;
	CurrentDate.year = y;
}
Date Date::CurrentDate = Date();
void Date::ReadDataFromFile(ifstream& fin)
{
	fin >> day;
	fin >> month;
	fin >> year;
}
void Date::printDate()
{
	cout << "...(" << day << "/" << month << "/" << year << ")" << endl;
}
int Date::getDateDay()
{
	return day;
}
int Date::getDateMonth()
{
	return month;
}
int Date::getDateYear()
{
	return year;
}
bool Date::operator<=(Date& rhs)
{
	if (day == rhs.day || day == rhs.day - 1) {
		if (month == rhs.month) {
			if (year == rhs.year) {
				return true;
			}
		}
	}
	return false;
}
bool Date::memoryDateCheck()
{
	if (day == CurrentDate.day && month == CurrentDate.month) {
		return true;
	}
	else
		return false;
}
//Object Class Definition
char* Object::getId()
{
	return ID;
}
void Object::printName()
{
}
void Object::setId(char* id)
{
	ID = Helper::GetStringFromBuffer(id);
}
char* Object::getUserId()
{
	return ID;
}
void Object::setTimeline(Post*)
{
}
Object::~Object()
{
	if (ID) {
		delete[] ID;
	}
}
//page Class Definition
Page::Page()
{
}
void Page::printName()
{
	cout << Title;
}
void Page::readDataFromFile(ifstream& fin)
{
	char id[5];
	char title[50];
	fin >> id;
	fin.getline(title, 50);
	ID = Helper::GetStringFromBuffer(id);
	Title = Helper::GetStringFromBuffer(title);
}
void Page::printPagesPosts()
{
	for (int i = 0; i < timeLineCount; i++) {
		if (Timeline[i]->dateCheck()) {
			Timeline[i]->viewPost(0, 1);
		}
	}
}
void Page::setTimeline(Post* A_Post)
{
	if (!Timeline) {
		Timeline = new Post * [10];
	}
	Timeline[timeLineCount] = A_Post;
	if (A_Post != 0) {
		timeLineCount++;
	}
}
void Page::setPageId(char* id)
{
	ID = id;
}
char* Page::getId()
{
	return ID;
}
char* Page::getPageTitle()
{
	return Title;
}
void Page::viewTimeline()
{
	cout << Title << " -Time Line\n\n" << endl;
	for (int i = 0; i < timeLineCount; i++) {
		Timeline[i]->viewPost(1, 1);
	}
}
Page::~Page()
{
	if (ID != 0) {
		delete[] ID;
		ID = 0;
	}
	if (Title != 0) {
		delete[] Title;
		Title = 0;
	}
	for (int i = 0; i < timeLineCount; i++) {
		delete Timeline[i];
	}
	delete[] Timeline;
	Timeline = 0;
}
//Activity Class Definition
void Activity::ReadDataFromFile(ifstream& file)
{
	file >> Type;
	char textVal[80];
	file.getline(textVal, 80);
	value = Helper::GetStringFromBuffer(textVal);
}
void Activity::activityPrint()
{
	const char* activity;
	if (Type == 1) {
		activity = " is feeling";
	}
	else if (Type == 2) {
		activity = " is thinking about";
	}
	else if (Type == 3) {
		activity = " is making";
	}
	else {
		activity = " is celebrating";
	}
	cout << activity << value << endl;
}
int Activity::getType()
{
	return Type;
}
char* Activity::getValue()
{
	return value;
}
Activity::~Activity()
{
	if (value) {
		delete[] value;
	}
}
//Post Class Definition
Post::Post()
{
}
Post::Post(char* postText, Object* shared_By)
{
	SharedBy = shared_By;
	Text = postText;
	SharedDate = Date::CurrentDate;
}
void Post::viewlikes()
{
	for (int i = 0; i < LikesCount; i++) {
		cout << LikedBy[i]->getId() << " - ";
		LikedBy[i]->printName();
		cout << endl;
	}
}
bool Post::dateCheck()
{
	if (SharedDate <= Date::CurrentDate) {
		return true;
	}
	else {
		return false;
	}
}
Comment** Post::getComments()
{
	return comments;
}
int Post::getCommentsCount()
{
	return commentsCount;
}
char* Post::getPostText()
{
	return Text;
}
Date Post::getSharedDate()
{
	return SharedDate;
}
Activity* Post::getActivity()
{
	return activity;
}
char* Post::getPostId()
{
	return ID;
}
void Post::ReadDataFromFile(ifstream& fin)
{
	char id[10];
	char text[150];
	int activityCheck;
	fin >> activityCheck;
	fin >> id;
	ID = Helper::GetStringFromBuffer(id);
	SharedDate.ReadDataFromFile(fin);
	fin.getline(text, 150);
	if (text[0] == '\t' || text[0] == '\0') {
		fin.getline(text, 150);
	}
	Text = Helper::GetStringFromBuffer(text);
	if (activityCheck == 2) {
		activity = new Activity;
		activity->ReadDataFromFile(fin);
	}
}
void Post::viewPost(bool dateFlag, bool commentFlag)
{
	SharedBy->printName();
	if (activity) {
		activity->activityPrint();
	}
	else {
		cout << " shared ";
	}
	cout << Text;
	if (dateFlag == 1) {
		SharedDate.printDate();
	}
	else {
		cout << endl;
	}
	if (commentFlag == 1) {
		for (int i = 0; i < commentsCount; i++) {
			cout << "\t\t";
			comments[i]->viewCommentBy();
			comments[i]->viewCommentText();
		}
	}
}
void Post::AddComment(Comment* ptr)
{
	if (!comments) {
		comments = new Comment * [10];
	}
	comments[commentsCount] = ptr;
	if (ptr != 0) {
		commentsCount++;
	}
}
void Post::SetSharedBy(Object* ptr)
{
	SharedBy = ptr;
}
void Post::SetLikedBy(Object* ptr)
{
	if (!LikedBy) {
		LikedBy = new Object * [10];
	}
	LikedBy[LikesCount] = ptr;
	if (ptr != 0) {
		LikesCount++;
	}
}
void Post::dateDifference()
{
	if (SharedDate.memoryDateCheck() == 1) {
		cout << Date::CurrentDate.getDateYear() - SharedDate.getDateYear() << " Years Ago" << endl;
		viewPost(1, 0);
	}
}
Post::~Post()
{
	if (ID) {
		delete[] ID;
	}
	if (Text) {
		delete[] Text;
	}
	SharedBy = nullptr;
	if (activity) {
		delete activity;
	}
	if (LikedBy) {
		for (int i = 0; i < LikesCount; i++) {
			if (LikedBy[i])
				LikedBy[i] = nullptr;
		}
		delete[] LikedBy;
	}
	if (comments) {
		for (int i = 0; i < commentsCount; i++) {
			if (comments[i]) {
				delete comments[i];
			}
		}
		delete[] comments;
	}
}
//User Class Definition
User::User()
{
}
void User::PrintUserPosts()
{
	for (int i = 0; i < timeLineCount; i++) {
		if (Timeline[i]->dateCheck() == 1) {
			Timeline[i]->viewPost(0, 1);
		}
	}
}
int User::getPageCount()
{
	return pageCount;
}
void User::printName()
{
	cout << Fname << " " << Lname;
}
void User::setTimeline(Post* A_Post)
{
	if (!Timeline) {
		Timeline = new Post * [10];
	}
	Timeline[timeLineCount] = A_Post;
	if (A_Post != 0) {
		timeLineCount++;
	}
}
char* User::getId()
{
	return ID;
}
void User::readDataFromFile(ifstream& fin)
{
	char id[5];
	char fname[20];
	char lname[20];
	char userbuffer[5];
	char pagebuffer[5];
	fin >> id;
	fin >> fname;
	fin >> lname;
	ID = Helper::GetStringFromBuffer(id);
	Fname = Helper::GetStringFromBuffer(fname);
	Lname = Helper::GetStringFromBuffer(lname);
}
void User::LikePage(Page*& pagePtr)
{
	if (!LikedPages) {
		LikedPages = new Page * [10];
	}
	LikedPages[pageCount] = pagePtr;
	if (pagePtr != 0) {
		pageCount++;
	}
}
void User::AddFriend(User*& userPtr)
{
	if (!friendList) {
		friendList = new User * [10];
	}
	friendList[friendCount] = userPtr;
	if (userPtr != 0) {
		friendCount++;
	}
}
void User::ViewFriendList()
{
	cout << Fname << " " << Lname << " Friend List" << "\n\n\n";
	for (int i = 0; i < friendCount; i++) {
		cout << friendList[i]->ID << "-" << friendList[i]->Fname << " " << friendList[i]->Lname << endl;
	}
}
void User::PrintListview()
{
	cout << Fname << " " << Lname << " Liked Pages" << "\n\n\n";
	for (int i = 0; i < pageCount; i++) {
		cout << LikedPages[i]->getId() << "-" << LikedPages[i]->getPageTitle() << endl;
	}
}
void User::viewTimeline()
{
	cout << Fname << " " << Lname << " -Time Line\n\n" << endl;
	for (int i = 0; i < timeLineCount; i++) {
		Timeline[i]->viewPost(1, 1);
	}
}
void User::viewHomepage()
{
	cout << Fname << " " << Lname << " -Home Page\n\n" << endl;
	for (int i = 0; i < friendCount; i++) {
		friendList[i]->PrintUserPosts();
	}
	for (int i = 0; i < pageCount; i++) {
		LikedPages[i]->printPagesPosts();
	}
}
void User::memoryCheck()
{
	for (int i = 0; i < timeLineCount; i++) {
		Timeline[i]->dateDifference();
	}
}
User::~User()
{
	if (ID != 0) {
		delete[] ID;
		ID = 0;
	}
	if (Fname != 0) {
		delete[] Fname;
		Fname = 0;
	}
	if (Lname != 0) {
		delete[] Lname;
		Lname = 0;
	}
	if (LikedPages) {
		delete[] LikedPages;
		LikedPages = 0;
	}
	if (friendList) {
		delete[] friendList;
		friendList = 0;
	}
	for (int i = 0; i < timeLineCount; i++) {
		if (Timeline[i])
			delete Timeline[i];
		Timeline[i] = NULL;
	}
	delete[] Timeline;
	Timeline = 0;
}
//Comment Class Degfinition
Comment::Comment()
{
}
Comment::Comment(User* current_user, const char* Text)
{
	int newid;
	newid = Comment::TotalComments + 1;
	char buffer[5];
	const char* c = "c";
	_itoa_s(newid, buffer, 2, 10);
	Helper::StringConcatenate(c, buffer);
	Comment_ID = Helper::GetStringFromBuffer(c);
	text = Helper::GetStringFromBuffer(Text);
	commentBy = current_user;
}
void Comment::setTotalComments(int TC)
{
	TotalComments = TC;
}
int Comment::getTotalComments()
{
	return TotalComments;
}
void Comment::viewCommentText()
{
	cout << text << endl;
}
void Comment::viewCommentBy()
{
	commentBy->printName();
	cout << " wrote: ";
}
Object* Comment::getCommentBy()
{
	return commentBy;
}
void Comment::setValues(char* id, char* Text, Object* obj)
{
	Comment_ID = Helper::GetStringFromBuffer(id);
	text = Helper::GetStringFromBuffer(Text);
	commentBy = obj;
}
Comment::~Comment()
{
	if (text)
	{
		delete[] text;
	}

	if (Comment_ID)
	{
		delete[] Comment_ID;
	}

	commentBy = nullptr;
}
//Memory Class Definition
class Memory : public Post
{
	Post* originalPost;
public:
	Memory();
	Memory(Post*&, char*, Object*);
	~Memory();
};
Memory::Memory()
{}
Memory::Memory(Post*& A_Post, char* text, Object* userptr) : Post(text, userptr)
{
	originalPost = A_Post;
	originalPost->dateDifference();
}
Memory::~Memory()
{
	if (originalPost) {
		originalPost = nullptr;
	}
}
//FaceBook Class Definition
FaceBook::FaceBook()
{
}
void FaceBook::setCurrentUser(const char* user)
{
	cout << "Command:  Set current user u7" << endl;
	searchUserByID(user)->printName();
	cout << " successfully Set Current User" << endl;
}
User* FaceBook::getCurrentUser()
{
	return currentUser;
}
void FaceBook::LoadPagesFromFile()
{
	ifstream fin;
	fin.open("SocialNetworkPages.txt");
	fin >> totalpages;
	pages = new Page * [totalpages];
	for (int i = 0; i < totalpages; i++) {
		pages[i] = new Page;
		pages[i]->readDataFromFile(fin);
	}
}
Post* FaceBook::searchPostById(const char* id)
{
	bool found;
	for (int i = 0; i < totalPosts; i++) {
		found = Helper::stringCompare(posts[i]->getPostId(), id);
		if (found == true) {
			return posts[i];
		}
	}
}
Page* FaceBook::searchPageByID(const char* id)
{
	bool found;
	for (int i = 0; i < totalpages; i++) {
		found = Helper::stringCompare(pages[i]->getId(), id);
		if (found == true) {
			return pages[i];
		}
	}
}
User* FaceBook::searchUserByID(const char* userid)
{
	bool found;
	for (int i = 0; i < totalUsers; i++) {
		found = Helper::stringCompare(users[i]->getId(), userid);
		if (found == true) {
			return users[i];
		}
	}
}
Object* FaceBook::searchObjectById(char* temp)
{
	Object* O1 = 0;
	bool found;
	if (temp[0] == 'u') {
		O1 = searchUserByID(temp);
	}
	if (O1) {
		return O1;
	}
	else {
		O1 = searchPageByID(temp);
	}
	if (O1) {
		return O1;
	}
}
void FaceBook::LoadUsersFromFile()
{
	ifstream fin;
	fin.open("SocialNetworkUsers.txt");
	fin >> totalUsers;
	Page* pagePtr;
	User* userPtr;
	char temp[5];
	int usercount = 0;
	int count = 0;
	int k = 0;
	char*** TempFriendIds;
	TempFriendIds = new char** [totalUsers];
	users = new User * [totalUsers];
	for (int i = 0; i < totalUsers; i++)
	{
		TempFriendIds[i] = new char* [10];
		users[i] = new User;
		users[i]->readDataFromFile(fin);
		int j = 0;
		for (int a = 0; a < 5; a++) {
			temp[a] = '\0';
		}
		while (temp[0] != '-') {
			fin >> temp;
			if (temp[0] == '-') {
				fin >> temp;
				while (temp[0] != '-') {
					if (temp[0] == '-') {
						break;
					}
					pagePtr = searchPageByID(temp);
					users[i]->LikePage(pagePtr);
					fin >> temp;
				}
				break;
			}
			usercount = Helper::stringLength(temp);
			TempFriendIds[i][j] = Helper::GetStringFromBuffer(temp);
			j++;
		}
		TempFriendIds[i][j] = NULL;
	}
	fin.close();
	for (int i = 0; i < totalUsers; i++) {
		for (int j = 0; TempFriendIds[i][j] != NULL; j++) {
			userPtr = searchUserByID(TempFriendIds[i][j]);
			users[i]->AddFriend(userPtr);
		}
	}
	for (int i = 0; i < totalUsers; i++) {
		for (int j = 0; TempFriendIds[i][j] != NULL; j++) {
			delete[] TempFriendIds[i][j];
		}
		delete[] TempFriendIds[i];
	}
	delete[] TempFriendIds;
	pagePtr = 0;
	userPtr = 0;
}
void FaceBook::LoadPosts()
{
	ifstream fin;
	fin.open("SocialNetworkPosts.txt");
	char Temp[10];
	fin >> totalPosts;
	posts = new Post * [totalPosts];
	for (int i = 0; i < totalPosts; i++) {
		posts[i] = new Post;
		posts[i]->ReadDataFromFile(fin);
		fin >> Temp;
		Object* objPtr = searchObjectById(Temp);
		posts[i]->SetSharedBy(objPtr);
		if (Temp[0] == 'u') {
			User* userptr = searchUserByID(Temp);
			userptr->setTimeline(posts[i]);
		}
		else {
			Page* pagePtr = searchPageByID(Temp);
			pagePtr->setTimeline(posts[i]);
		}
		char** tempLikedBy = 0;
		tempLikedBy = new char* [10];
		int k = 0;
		while (Temp[0] != '-') {
			fin >> Temp;
			if (Temp[0] != '-') {
				tempLikedBy[k] = Helper::GetStringFromBuffer(Temp);
				k++;
			}
		}
		for (int j = 0; j < k; j++) {
			Object* likedPtr = searchObjectById(tempLikedBy[j]);
			posts[i]->SetLikedBy(likedPtr);
		}
	}
	fin.close();
}
void FaceBook::LoadComments()
{
	ifstream fin;
	fin.open("SocialNetworkComments.txt");
	fin >> totalComments;
	char id[5];
	Object* CommentBy;
	char postId[10];
	char commentBy[5];
	char text[80];
	for (int i = 0; i < totalComments; i++) {
		Comment* comment = new Comment;
		fin >> id;
		fin >> postId;
		Post* postPtr = searchPostById(postId);
		postPtr->AddComment(comment);
		fin >> commentBy;
		fin.getline(text, 80);
		CommentBy = searchObjectById(commentBy);
		comment->setValues(id, text, CommentBy);
	}
}
void FaceBook::viewLikedList(const char* A_Post)
{
	cout << "Post Liked By" << endl;
	searchPostById(A_Post)->viewlikes();
}
void FaceBook::likePost(const char* A_Post)
{
	searchPostById(A_Post)->SetLikedBy(currentUser);
}
void FaceBook::PostComment(const char* post_id, const char* text)
{
	Comment* cmnt = new Comment(currentUser, text);
	searchPostById(post_id)->AddComment(cmnt);
}
void FaceBook::ViewPost(const char* A_post)
{
	searchPostById(A_post)->viewPost(1, 1);
}
void FaceBook::seeYourMemories()
{
	cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.\n" << endl;
	cout << "On this Day" << endl;
	currentUser->memoryCheck();
}
void FaceBook::viewPage(const char* page)
{
	searchPageByID(page)->viewTimeline();
}
void FaceBook::memory(const char* cstring, const char* Text, Object* currentuser)
{
	char* text = Helper::GetStringFromBuffer(Text);
	Post* Postptr = searchPostById(cstring);
	Post* PostPtr2 = new Memory(Postptr, text, currentuser);
	currentUser->setTimeline(PostPtr2);
}
void FaceBook::shareMemory(const char* postId, const char* text)
{
	cout << "~~~";
	currentUser->printName();
	cout << " shared a memory~~~" << endl;
	cout << text;
	Date::CurrentDate.printDate();
	memory(postId, text, currentUser);
}
void FaceBook::LoadAllData()
{
	LoadPagesFromFile();
	LoadUsersFromFile();
	LoadPosts();
	LoadComments();
}
void FaceBook::Run()
{
	cout << "Command:  Set current System Date 15 11 2017 " << endl;
	Date::SetCurrentDate(15, 11, 2017);
	cout << "System Date: ";
	Date::CurrentDate.printDate();
	cout << "\n\n";
	setCurrentUser("u7");
	cout << "\n\n";
	currentUser = searchUserByID("u7");
	cout << "Command:  View Friend List\n" << endl;
	currentUser->ViewFriendList();
	cout << "\n\n";
	cout << "Command:    View Liked Pages\n" << endl;
	currentUser->PrintListview();
	cout << "\n\n\n";
	cout << "Command:    View Home\n" << endl;
	currentUser->viewHomepage();
	cout << "\n\n\n";
	cout << "Command:    View TimeLine\n" << endl;
	currentUser->viewTimeline();
	cout << "\n\n\n";
	cout << "Command:    ViewLikedList(Post5)\n" << endl;
	viewLikedList("post5");
	cout << "\n\n\n";
	cout << "Command:   LikePost(post5)" << endl;
	likePost("post5");
	cout << "Command:   ViewLikedList(Post5)\n" << endl;
	viewLikedList("post5");
	cout << "\n\n\n";
	cout << "Command:    PostComment(post4, Good Luck for your Result)" << endl;
	cout << "Command:    ViewPost(post4)\n" << endl;
	PostComment("post4", "Good Luck for your Result");
	ViewPost("post4");
	cout << "\n\n\n";
	cout << "Command:    PostComment(post8, Thanks for the wishes)" << endl;
	cout << "Command:    ViewPost(post8)\n" << endl;
	PostComment("post8", "Thanks for the wishes");
	ViewPost("post8");
	cout << "\n\n\n";
	cout << "Command:    SeeYourMemories()\n" << endl;
	seeYourMemories();
	cout << "\n\n\n";
	cout << "Command:    SharedMemory(post10, Never thought I will be specialist in this field...)" << endl;
	cout << "Command:      View Timeline\n" << endl;
	shareMemory("post10", "Never thought I will be specialist in this field...");
	cout << endl;
	currentUser->viewTimeline();
	cout << "\n\n\n";
	cout << "Command:    ViewPage(p1)\n" << endl;
	viewPage("p1");
	cout << "\n\n\n";
	setCurrentUser("u11");
	currentUser = searchUserByID("u11");
	cout << "Command:   View TimeLine\n" << endl;
	currentUser->viewTimeline();
	cout << "\n\n\n";
	cout << "Command:   View Home\n" << endl;
	currentUser->viewHomepage();

}
FaceBook::~FaceBook()
{
	for (int i = 0; i < totalpages; i++) {
		if (pages[i])
			delete[] pages[i];
	}
	delete[] pages;
	pages = 0;
	for (int i = 0; i < totalUsers; i++) {
		delete[] users[i];
	}
	delete[] users;
	users = 0;
	if (posts)
		delete[] posts;
	posts = 0;
	currentUser = nullptr;
}
int main()
{
	FaceBook fb;
	fb.LoadAllData();
	fb.Run();
	return 0;
}