// backSkill.cpp : Defines the entry point for the console application.
// this program is meant to help the user figure out the best way to set up his skill tree in darkorbit.
// by forcing the user to fulfill their requirements for the main 4 stats to upgrade that way the user can 
// first set the pilot points in the required points than he can place the rest in any other place he would like.
// 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//places Pilot points in the spot of choice.
int getNumber(){
	int num;
	
	while(true){
		cin>>num;
	if(!cin){
		num=0;
		cout<<"Incorrect input pleas try again\n";
		cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	}else{
		break;
	}
	}
	return num;
}
void setpnt(int &ppnt, int setingamnt, string name) {
	
	if (ppnt < setingamnt) {
		ppnt = setingamnt;
		cout << name << " has been set to " << ppnt << "\n";
	}
}

// this prompts the user to add points to fulfil the requirements
void totalclk(int &item, int max, int &item1, int max1, int &item2, int max2, int total, string name, string name1, string name2) {

	int totAlo = total;
	if (item + item1 + item2<total) {
		cout << "you have " << total << " pilot points to place in " << name << " or " << name1 << " (whatever you don’t place will be allocated to "<<name2<< " anny more and stat will be set to "<<total<<")\n";
		cout << "How many do you want to place in " << name << "\n";
		cout << "Allocate Pilot points:";
		cin >> item;
		if (item>max) {
			item = max;
		}
		if (item >= totAlo) {
			item = totAlo;
			return;
		}
		else {
			totAlo = total - item;

			cout << "How many do you want to place in " << name1 << "\n";
			cout << "Allocate pilot points:";
			cin >> item1;
			if (item1>max1) {
				item1 = max1;
			}

			if (item1 >= totAlo) {
				item1 = totAlo;
				return;
			}
			else {
				totAlo -= item1;


				item2 = totAlo;
				if (item2>max2) {
					item2 = max2;
					item1 += total - max2;
				}

				cout << item2 << " Pilot points were placed in " << name2;
				cout << "\n\n\n";
			}
			if (item2) {

			}
		}
	}
}
// this prompts the user to add points to fulfil the requirements
void totalclk(int &itnum, int &itnum2, int total, string name1, string name2) {
	if (itnum + itnum2<total) {

		cout << "You have " << total << " pilot points to place in " << name1 << " (the remainder will be placed in " << name2 << " anny more and stat will be set to " << total << ")\n";
		cout << "Allocate pilot points:";
		itnum=getNumber();
		if (itnum>total)
			itnum = total;

		itnum2 = total - itnum;
		cout <<endl<< itnum2 << " Pilot points were placed in " << name2 << "\n";
	}
}
// this prompts the user to pick a place to put your point.
void pickone(int &d, int &c, int &a, string dname, string cname, string aname) {
	if (d + a + c == 0) {
		cout << "\nChoose wich spot to place your pilot point \n";
		cout << "1: " << dname << "\n2: " << cname << "\n3: " << aname << "\n";
		int select = 0;
		cout << "Selection: ";
		select=getNumber();
		if (select == 1) {
			d = 1;
		}
		else
			if (select == 2) {
				c = 1;
			}
			else
				if (select == 3) {
					a = 1;
				}
				else {
					d = 1;
				}
	}
}
// helps the user fulfil the requirements for evasive maneuvers and any other item that helps with defense.
void defenseCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	string Poilet = "Pilot points";
	if (d[0][6] != 0) {

		setpnt(d[0][3], 2, dname[3]);
		setpnt(d[0][5], 3, dname[5]);

	}
	if (d[0][5] != 0) {
		setpnt(d[0][4], 3, dname[4]);

	}
	if (d[0][4] != 0) {
		setpnt(d[0][0], 2, dname[0]);
		cout << "\n\n\n";
	}
	if (d[0][3] + a[0][3] != 0) {
		if (d[0][2] + a[0][2]<2) {
			totalclk(d[0][2], a[0][2], 2, dname[2], aname[2]);

		}
	}
	if (d[0][2] + a[0][2] != 0) {
		pickone(d[0][1], a[0][1], c[0][1], dname[1], cname[1], aname[1]);
	}
	if (d[0][1] + a[0][1] + c[0][1] != 0) {
		pickone(d[0][0], a[0][0], c[0][0], dname[0], cname[0], aname[0]);
	}
}
// helps the user to fufill the requirements for bounty hunter 2 and alien hunter pluss any other items that help with attack power.
void attackCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	cout << "\n";

	if (a[0][8] != 0) {
		setpnt(a[0][3], 2, aname[3]);

		totalclk(a[0][7], c[0][6], 3, aname[7], cname[6]);
	}
	if (a[0][7] + c[0][6] != 0) {
		cout << "\n\n\n";
		totalclk(d[0][5], d[1][5], c[0][5], c[1][5], a[0][6], a[1][6], 5, dname[5], cname[5], aname[6]);
	}
	if (a[0][6] + c[0][5] != 0) {
		cout << "\n\n\n";
		totalclk(a[0][5], c[0][4], 3, aname[5], cname[4]);
	}
	if (c[0][4] != 0) {
		cout << "\n\n\n";
		totalclk(d[0][4], d[1][4], c[0][3], c[1][3], a[0][4], a[1][4], 2, dname[4], cname[3], aname[4]);
	}
	if (a[0][5] != 0) {
		cout << "\n\n\n";
		if (a[0][4]<2)
			a[0][4] = 2;
		if (c[0][3]<2)
			c[0][3] = 2;
		cout << aname[4] << " has been set to " << a[0][4] << "\n";
		cout << cname[3] << " has been set to " << c[0][3] << "\n";
	}
	if (a[0][6] != 0) {
		a[0][0] = 2;
	}

}
//prompts the user to place Pilot points in an upgrade item
void setPoiletPnts(int &chang, int max, string name) {
	cout << "Place desired amount in " << name << " (you may place no more than " << max << " anny more and stat will be set to "<<max<<")\n";
	cout << "allocate Pilot points:";
	chang=getNumber();
	if (chang>max)
		chang = max;
}
// removes the blank lines in a file
void removeBlank() {
	ofstream tempF("temp.txt", ios_base::ate);
	ifstream myFile("file.txt", ios::in);

	string str;

	while (getline(myFile, str))
	{

		if (string::npos&&str != "") {
			tempF << str << "\n";
		}
	}
	tempF.close();
	myFile.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");
}
//fulfils the requirements for luck 2 and luck 1
void colectCalk(int d[][7], int c[][9], int a[][9], string dname[], string cname[], string aname[]) {
	if (c[0][8] != 0) {
		setpnt(a[0][8], 3, aname[8]);
		setpnt(d[0][6], 3, dname[6]);
		setpnt(c[0][2], 2, cname[2]);
	}
	if (c[0][3] != 0) {
		totalclk(d[0][3], d[1][3], c[0][2], c[1][2], a[0][3], a[1][3], 2, dname[2], cname[2], aname[3]);
	}
	if (c[0][2] != 0) {
		setpnt(c[0][1], 2, cname[1]);
	}

}
//prompts user to select a file
string selectfile() {
	removeBlank();
	ifstream myFile("file.txt", ios::in);
	cout << "reading file\n";
	string str = "";
	int lineNum = 1;
	if (myFile.good()) {
		while (getline(myFile, str))
		{

			cout << lineNum << ": " << str;
			cout << endl;
			lineNum++;
		}
	}
	else
		ofstream oMyfile("file.txt", ios_base::ate);
	int select = 0;
	cout << "\nselection: ";
	select=getNumber();
	myFile.close();
	myFile.open("file.txt", ios::in);
	lineNum = 1;
	if (myFile.good())
	{
		string str = "";

		while (getline(myFile, str))
		{

			if (select == lineNum) {

				myFile.close();
				return str;
			}
			lineNum++;
		}
	}
	myFile.close();
	return "";
}
//opens a skill tree file.
void open(int d[][7], int c[][9], int a[][9]) {
	string fn = selectfile();
	removeBlank();
	if (fn != "") {
		ifstream myFile(fn, ios::in);
		string str = "";
		int k = 0;

		if (myFile.good()) {
			while (getline(myFile, str))
			{
				for (unsigned i = 0; i < str.length(); ++i)
				{
					if (k == 0)
						d[0][i] = str.at(i) - 48;
					if (k == 1)
						c[0][i] = str.at(i) - 48;
					if (k == 2)
						a[0][i] = str.at(i) - 48;
				}
				k++;
			}
			cout << "\n\n";
		}
	}


}
//alows the user to save.
void save(int d[][7], int c[][9], int a[][9]) {
	removeBlank();
	cout << "\n\n";
	ifstream myFile("file.txt", ios::in);
	if (myFile.good())
	{
		string str;
		while (getline(myFile, str))
		{
			cout << str;
			cout << endl;
		}
	}
	myFile.close();
	ofstream oMyfile("file.txt", ios_base::app);
	string fname = "";
	while (true) {
		cout << "\nwhat do you want to call your file\nName: ";
		cin.ignore();
		getline(cin, fname);
		if(!cin){
			cout<<"incorrect input pleas try again";
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
					
		}else{
				break;
			}
		
		if (fname.find(".txt") == string::npos)
			fname += ".txt";
		if (fname == "file.txt") {
			cout << "the file name must not be file.txt";
		}
		else {
			break;
		}
	}
	myFile.open("file.txt", ios::in);
	string str = "";
	bool found = false;
	while (getline(myFile, str) && !found)
	{
		if (str.find(fname) != string::npos) {
			found = true;
		}
	}
	if (!found)
		oMyfile << "\n" << fname;

	ofstream newfile(fname, ios_base::ate);
	for (int i = 0; i < 7; i++) {
		newfile << d[0][i];
	}
	newfile << "\n";
	for (int i = 0; i < 9; i++) {
		newfile << c[0][i];
	}
	newfile << "\n";
	for (int i = 0; i < 9; i++) {
		newfile << a[0][i];
	}
	newfile << "\n";
	newfile.close();
}
//helps create a table
string space(int sp) {
	string stp = "";
	for (int i = 0; i < sp; i++) {
		stp += " ";
	}
	return stp;
}
//deletes file
void delSelectFile(string str1) {
	removeBlank();
	ofstream tempF("temp.txt", ios_base::ate);
	ifstream myFile("file.txt", ios::in);
	if (str1 == "") {

	}
	else {

		if (myFile.good())
		{
			string str;

			while (getline(myFile, str))
			{

				if (str.find(str1) == string::npos&&str != "") {
					tempF << str << "\n";
				}
			}
		}

	}
	tempF.close();
	myFile.close();

	remove("file.txt");
	rename("temp.txt", "file.txt");

}

void deleteFile() {
	string fn = selectfile();
	delSelectFile(fn);
	if (fn != "") {

		if (remove(fn.c_str()) != 0)
		{
			perror("Error deleting file");
		}
		else
		{
			puts("File successfully deleted");
		}

	}
}
//displays information
string arrTostring(int d[], int c[], int a[], string dname[], string cname[], string aname[]) {
	string rst = "";
	int totpnt = 0;
	string attak = " Attack ";
	string colect = " Colect ";
	cout << endl << colect << space(33 - colect.length()) << attak << space(33 - attak.length()) << " Defense \n\n";

	for (int i = 0; i < 9; i++) {
		cout << cname[i] << " = " << c[i] << space(27 - cname[i].length());
		cout << aname[i] << " = " << a[i] << space(27 - aname[i].length());
		if (i < 7) {
			cout << dname[i] << " = " << d[i];
			totpnt += d[i] + c[i] + a[i];
		}
		else {
			totpnt += c[i] + a[i];
		}
		cout << "\n";
	}
	cout << "The total Pilot points used were " << totpnt << "\n\n";
	return rst;
}
inline bool exists_test0 (const string name) {
	ifstream f(name.c_str());
	return f.good();
}
int main(int argc, char *argv[]) {
	// initialize the information needed
	string dname[7] = { "\"Ship hull 1\"", "\"Engineering\"","\"Shield engineering\"", "\"Evasive maneuvers 1\"","\"Ship hull 2\"", "\"Shield mechanics\"", "\"Evasive maneuvers 2\"" };
	string cname[9] = { "\"Tactics\"","\"Logistics\"", "\"Luck 1\"", "\"Cruelty 1\"","\"Tractor beam 1\"", "\"Greed\"","\"Tractor beam 2\"","\"Cruelty 2\"", "\"luck 2\"" };
	string aname[9] = { "\"Detonation 1\"", "\"Explosives\"", "\"Heat-seeking missiles\"", "\"Bounty hunter 1\"","\"Rocket fusion\"", "\"Alien hunter\"",  "\"Detonation 2\"","\"Electro-optics\"","\"Bounty hunter 2\"" };
	if(!exists_test0 ("file")){
		ofstream newfile("colecting", ios_base::ate);
		newfile<<"2022353\n022000303\n000200003";
		newfile.close();
		newfile.open("file.txt");
		newfile<<"colecting";
		newfile.close();
	}
	int totPPnt = 0;
	int d[2][7] = { { 0 },{ 2,5,5,2,3,5,3 } };
	int c[2][9] = { { 0 },{ 5,5,2,2,5,5,5,3,3 } };
	int a[2][9] = { { 0 },{ 2,5,5,2,5,5,3,5,3 } };
	int selection = 1;
	while (selection == 1 || selection == 2 || selection == 3||selection==4)
	{
		int totPPnt = 0;
		int d[2][7] = { { 0 },{ 2,5,5,2,3,5,3 } };
		int c[2][9] = { { 0 },{ 5,5,2,2,5,5,5,3,3 } };
		int a[2][9] = { { 0 },{ 2,5,5,2,5,5,3,5,3 } };
		//prompts the user to choose one of the fallowing
		cout << "it is advised to use www.darkskill.info as a reference.\n";
		cout << "1: Open document\n";
		cout << "2: Build skill tree\n";
		cout << "3: Delete file\n";
		cout<<"4: Help\n";
		cout << "5: End\n";
		cout << "Selection: ";
		selection=getNumber();
		if (selection == 1) {
			//alows user to open a skill tree file.
			open(d, c, a);
			arrTostring(d[0], c[0], a[0], dname, cname, aname);
		}
		if (selection == 2) {
			//prompts the user to place Pilot points in the 4 main items
			setPoiletPnts(d[0][6], d[1][6], dname[6]);
			setPoiletPnts(c[0][8], c[1][8], cname[8]);
			setPoiletPnts(a[0][8], a[1][8], aname[8]);
			setPoiletPnts(a[0][5], a[1][5], aname[5]);
			//prompts the user to fulfil the requirements
			colectCalk(d, c, a, dname, cname, aname);
			attackCalk(d, c, a, dname, cname, aname);
			defenseCalk(d, c, a, dname, cname, aname);
			//displays the result so the user can apply in the game
			arrTostring(d[0], c[0], a[0], dname, cname, aname);
			//prompts the user to save there skill tree
			char decide='w';
			while(true){
			cout << "Would you like to save y for yes n for no\n";
			cin>>decide;
			if(cin){
			if (decide == 'y'){
				save(d, c, a);
				break;
			}
			}else{
				
				cout<<"Incorrect input pleas try again";
				cin.clear(); // reset failbit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			}
		}
		if (selection == 3) {
			//alows the user to delete a file.
			deleteFile();
		}
		if(selection==4)
			cout<<"\n This program allows you to build a Darkorbit skill tree backwards read carefully.\n it is advised to use www.darkskill.info as a reference.";
	}
}
}

