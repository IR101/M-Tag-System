#include <iostream>
#include <string>
#include <random>

using namespace std;

void banner() {
	cout << "-----------------------------------------"<<endl;
	cout << "-                M-TAG                  -"<<endl;
	cout << "-----------------------------------------"<<endl;
}
void option() {
	cout << "-----------------------------------------"<<endl;
	cout << "-                                       -" << endl;
	cout << "-           1. Registration             -"<<endl;
	cout << "-           2. Toll Tax                 -"<<endl;
	cout << "-           3. Recharge                 -"<<endl;
	cout << "-           4. Display Data             -"<<endl;
	cout << "-           5. Exit                     -"<<endl;
	cout << "-                                       -" << endl;
	cout << "-----------------------------------------"<<endl;
}
int toll[14][14] = {
	{0,30,30,50,70,70,80,90,120,140,160,180,210,240},
	{30,0,30,30,50,60,70,80,100,130,140,160,200,230},
	{30,30,0,30,40,50,60,70,90,120,130,150,190,220},
	{50,30,30,0,30,30,30,40,70,100,110,130,160,190},
	{70,50,40,30,0,30,30,30,50,80,90,110,150,170},
	{70,60,50,30,30,0,30,30,50,70,90,110,140,170},
	{80,70,60,30,30,30,0,30,40,60,80,100,130,160},
	{90,80,70,40,30,30,30,0,30,50,70,90,120,150},
	{120,100,90,70,50,50,40,30,0,30,40,60,90,120},
	{140,130,120,100,80,70,60,50,30,0,30,30,70,100},
	{160,140,130,110,90,90,80,70,40,30,0,30,50,80},
	{180,160,150,130,110,110,100,90,60,30,30,0,30,60},
	{210,200,190,160,150,140,130,120,90,70,50,30,0,30},
	{240,230,220,190,170,170,160,150,120,100,80,60,30,0}
};

int balance[10] = {0,0,0,0,0,0,0,0,0,0};
int cnic[10] = {0,0,0,0,0,0,0,0,0,0};
string v_num[10] = {"","","","","","","","","",""};
int p_num[10] = {0,0,0,0,0,0,0,0,0,0};
int mtag[10] = {0,0,0,0,0,0,0,0,0,0};
int i = 0;

void registration(int cnic, string vehicle_num, int phone_num) {
	::cnic[i] = cnic;
	v_num[i] = vehicle_num;
	p_num[i] = phone_num;
	int j = rand()%99;
	cout << "\n Registered Successfully \n";
	cout << "\n Your M-Tag number is: ";
	cout << j<<endl;
	mtag[i] = j;
	i++;
}

int matching(int mtag_no) {
	for (int i = 0; i < 10; i++) {
		if (mtag[i] == mtag_no) {
			return i;
		}
	}
	return -1;
}

int account(int mtag,int num) {
	int bal = matching(mtag);
	int res = 0;
	if (bal != -1) {
		if (balance[bal] > 0 && balance[bal] >= num) {
			res = balance[bal] - num;
			balance[bal] = res;
		}
		else {
			cout << "\n Your Balance is Insufficient Recharge First \n";
		}
	}
	else {
		cout << "\n Account not exist \n";
	}
	return res;
}


void deduction(int mtag){
	int index1 = 0;
	int index2 = 0;
	string index[14] = { "islamabad","fateh jhang"," awt/sangjani","brahma bahatar","burhan","hazara/segregation toll plaza",
	"ghazi","chach","sawabi","karnal sherkhan","wali interchange","rashaki","charsada","peshawar" };
	if (matching(mtag) != -1) {
		cout << "\n Entering Interchange: ";
		cin.ignore();
		string from;
		getline(cin, from);
		cout << endl;
		cout << " Leaving Interchange: ";
		string to;
		getline(cin, to);
		cout << endl;
		for (int i = 0; i < from.length(); i++) {
			from[i] = tolower(from[i]);
		}
		for (int i = 0; i < to.length(); i++) {
			to[i] = tolower(to[i]);
		}

		for (int i = 0; i < 14; i++) {
			if (index[i] == from) {
				index1 = i;
			}
			if (index[i] == to) {
				index2 = i;
			}
		}
		int num = toll[index1][index2];
		cout << "Your Remaining Balance is :" << account(mtag, num) << endl;
	}
	else {
		cout << " \n Please Register First \n";
	}
}

void recharge(int mtag, int bal) {
	int i = matching(mtag);
	if (i != -1) {
		balance[i] = bal;
	}
	else {
		cout << "\n Please Register First \n";
	}
}
void display() {
	for (int i = 0; i < 10; i++) {
		cout << "CNIC: " << cnic[i]<<"   |   ";
		cout << "M-Tag number: " << mtag[i] << "   |   ";
		cout << "Vehicle number: " << v_num[i] << "   |   ";
		cout << "Phone number: " << p_num[i] << "   |   ";
		cout << "Balance: " << balance[i] << "   |   ";
		cout << endl;
	}
}


int main() {
	int op = 0;
	int cnic = 0;
	string v ="";
	int p = 0;
	int m = 0;
	int b = 0;
	system("CLS");
	banner();
	option();
	cout << "\n Enter Option: ";
	cin >> op;
	while (op != 5) {
		if (op == 1) {
			cout << "\n Enter Your CNIC number: ";
			cin >> cnic;
			cout << "\n Enter Your Vehicle number: ";
			cin.ignore();
			getline(cin, v);
			cout << "\n Enter Your Phone number: ";
			cin >> p;
			registration(cnic,v,p);
			system("pause");
			system("CLS");
			banner();
			option();
			cout << "\n Enter Option: ";
			cin >> op;
		}
		else if (op == 2) {
			cout << "\n Enter Your M-Tag number: ";
			cin >> m;
			deduction(m);
			system("pause");
			system("CLS");
			banner();
			option();
			cout << "\n Enter Option: ";
			cin >> op;
		}
		else if (op == 3) {
			cout << "\n Enter Your M-Tag number: ";
			cin >> m;
			cout << "\n Enter Amount: ";
			cin >> b;
			recharge(m, b);
			system("pause");
			system("CLS");
			banner();
			option();
			cout << "\n Enter Option: ";
			cin >> op;
		}
		else if (op == 4) {
			display();
			system("pause");
			system("CLS");
			banner();
			option();
			cout << "\n Enter Option: ";
			cin >> op;
		}
		else {
			system("CLS");
			banner();
			option();
			cout << "\n Enter Option: ";
			cin >> op;
		}
	}
	cout << "\n\n\n Exiting... \n\n\n\n\n\n\n";
	return 0;
}