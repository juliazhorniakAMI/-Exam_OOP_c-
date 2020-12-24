//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <algorithm>
//
//using namespace std;
//
//class absClass
//{
//public:
//	virtual string getString() = 0;
//	virtual void WriteToConsole() = 0;
//	virtual void setting() = 0;
//};
//
//
//class Contract :public absClass {
//protected:
//	static int count;
//	string cName;
//	int* cId = new int;
//
//	string objName;
//	int objPrice;
//	string objDate;
//
//
//public:
//
//	// Constructors
//	Contract() {
//		cName = "";
//		*cId = ++count;
//		objName = "";
//		objPrice = NULL;
//		objDate = "";
//
//	}
//
//	Contract(string cName, string objName, int objPrice, string objDate) {
//		this->cName = cName;
//		*cId = ++count;
//		this->objName = objName;
//		this->objPrice = objPrice;
//		this->objDate = objDate;
//
//	}
//
//	Contract(const Contract& c) {
//		cName = c.cName;
//		cId = c.cId;
//		objName = c.objName;
//		objPrice = c.objPrice;
//		objDate = c.objDate;
//	}
//
//	// Destructor
//	~Contract() {
//		cout << "Object From Class Container : " << cName << " done\n";
//		delete cId;
//	}
//
//	// Override Virutal Methods
//	string getString() { return ""; }
//	void WriteToConsole() {}
//	void setting() {}
//
//
//	// Methods Get
//	string GetcName() {
//		return cName;
//	}
//	string GetObjName() {
//		return objName;
//	}
//	int GetObjPrice() {
//		return objPrice;
//	}
//	string GetObjDate() {
//		return objDate;
//	}
//	int GetcId() {
//		return *cId;
//	}
//
//
//	// Overloading Operator
//	bool operator>(Contract& other) {
//
//		return this->objPrice > other.objPrice;
//	}
//
//	// Перекритий Метод
//	void getInfo() {
//		cout << "\nName Object : " << cName << "\nName of material : " << objName << " |Price ($) : " << objPrice << " |Date : " << objDate << endl;
//	}
//
//
//};
//int Contract::count = 0;
//
//class Material : public Contract {
//protected:
//	int objAmount;
//
//public:
//
//	// Constructors
//	Material() :Contract() {
//		objAmount = NULL;
//	}
//
//	Material(string cName, string objName, int objPrice, string objDate, int objAmount) :Contract(cName, objName, objPrice, objDate) {
//		this->objAmount = objAmount;
//	}
//
//	Material(const Material& c) :Contract(c) {
//		objAmount = c.objAmount;
//	}
//
//	// Destructor
//	~Material() {
//		cout << "\n\nObject From Class Material : " << cName << " done\n";
//	}
//
//	// Override Virutal Methods
//	string getString() { return cName + " " + objName + " " + to_string(objPrice) + " " + objDate + " " + to_string(objAmount); }
//	void WriteToConsole() { cout << "\nId : " << *cId << "\nName Object : " << cName << "\nName of material : " << objName << " |Price ($) : " << objPrice << " |Date : " << objDate << " |Amount : " << objAmount << endl; }
//	void setting() {
//		uint8_t op = NULL;
//		while (true) {
//			system("CLS");
//			cout << "1. Change name of contract;\t(" << cName << ")" << endl;
//			cout << "2. Change Name.\t(" << objName << ")" << endl;
//			cout << "3. Change Amount.\t(" << objAmount << ")" << endl;
//			cout << "4. Change price.\t(" << objPrice << ")" << endl;
//			cout << "5. Change date.\t(" << objDate << ")" << endl;
//			cout << "6. Exit" << endl;
//			cin >> op;
//			if (op == '6') {
//				break;
//			}
//			switch (op) {
//			case '1': {
//				cout << "Name of contract: " << cName << endl;
//				string tmp;
//				cout << "Enter new name of contract : ";
//				cin >> tmp;
//				cName = tmp;
//				break;
//			}
//			case '2': {
//				cout << "Name : " << objName << endl;
//				string tmp;
//				cout << "Enter new name : ";
//				cin >> tmp;
//				objName = tmp;
//				break;
//			}
//			case '3': {
//				cout << "Amount : " << objAmount << endl;
//				int tmp;
//				cout << "Enter amount : ";
//				cin >> tmp;
//				objAmount = tmp;
//				break;
//			}
//			case '4': {
//				cout << "Price : " << objPrice << endl;
//				int tmp;
//				cout << "Enter new price : ";
//				cin >> tmp;
//				objPrice = tmp;
//				break;
//			}
//
//			case '5': {
//				cout << "Date : " << objDate << endl;
//				string tmp;
//				cout << "Enter date : ";
//				cin >> tmp;
//				objDate = tmp;
//				break;
//			}
//			default: {
//				cerr << "Error: wrong operation" << endl;
//				system("Pause");
//				break;
//			}
//			}
//		}
//	}
//
//	// Method Get (новий метод відносно батьківського)
//	int GetObjAmount() {
//		return objAmount;
//	}
//
//	// Перекритий Метод
//	void getInfo() {
//		cout << "\nName Object : " << cName << "\nName of material : " << objName << " |Price ($) : " << objPrice << " |Date : " << objDate << " |Amount : " << objAmount << endl;
//	}
//
//
//
//};
//
//
//
//// Functor
//class Functor {
//
//public:
//
//	bool operator()(Contract* v1, Contract* v2) {
//
//		return *v1 > * v2;
//	}
//
//};
//
//
//
//// All Function 
//class Command {
//	vector<Contract*> data;
//public:
//
//	Command() {
//		ReadFromStorage();
//	}
//
//	~Command() {
//		WriteToStorage();
//		for (size_t i = 0; i < data.size(); i++) {
//			delete data[i];
//		}
//
//	}
//
//	void ReadFromStorage()
//	{
//
//		ifstream myfile("file.txt");
//		string _cName;
//		string _objName;
//		int _objPrice;
//		string _objDate;
//		int _objAmount;
//
//		if (!myfile)
//		{
//			throw("Error: file.txt not found");
//
//		}
//
//		for (int i = 0; myfile; i++) {
//			if (myfile >> _cName >> _objName >> _objPrice >> _objDate >> _objAmount)
//			{
//				Material* tmp = new Material(_cName, _objName, _objPrice, _objDate, _objAmount);
//				data.push_back(tmp);
//			}
//		}
//		myfile.close();
//	}
//
//	void WriteToStorage() {
//		ofstream outf("file.txt", ios::out);
//		if (!outf)
//		{
//			throw("Error: file.txt not found");
//
//		}
//		else {
//			for (int i = 0; i < data.size(); i++) {
//				outf << data[i]->getString() << endl;
//			}
//		}
//		outf.close();
//	}
//
//	void Write() {
//		for (int i = 0; i < data.size(); i++) {
//			data[i]->WriteToConsole();
//		}
//	}
//
//	void addObject() {
//		string _cName;
//		string _objName;
//		int _objPrice;
//		string _objDate;
//		int _objAmount;
//
//		cout << "Enter name of object : ";
//		cin >> _cName;
//		cout << "Enter name of material : ";
//		cin >> _objName;
//		cout << "Enter price : ";
//		cin >> _objPrice;
//		cout << "Enter date : ";
//		cin >> _objDate;
//		cout << "Enter amount : ";
//		cin >> _objAmount;
//
//		Material* tmp = new Material(_cName, _objName, _objPrice, _objDate, _objAmount);
//		data.push_back(tmp);
//		WriteToStorage();
//		cout << "Added successfully\n";
//	}
//
//	void setting() {
//		Write();
//		vector<Contract*>::iterator it;
//		cout << "\nEnter id : ";
//		int i;
//		cin >> i;
//
//		it = find_if(data.begin(), data.end(), [&](Contract* tmp) {return tmp->GetcId() == i; });
//		data[it - data.begin()]->setting();
//
//	}
//
//	void stat() {
//		Functor f;
//		sort(data.begin(), data.end(), f);
//		cout << "\nStatistic : " << endl;
//		Write();
//	}
//
//
//};
//
//
//
//void menu() {
//	Command com;
//	short userInput = NULL;
//	while (true) {
//		system("CLS");
//		cout << "\t\t\tWelcome to the MainMenu! \n" <<
//			"\t\tSelect an option from the following: \n" <<
//			"1.....Show Object\n" <<
//			"2.....Add Object\n" <<
//			"3.....Sort Vector By Price\n" <<
//			"4.....Find And Edit Object\n" <<
//			"0.....Close Program\n\n";
//		cin >> userInput;
//		switch (userInput)
//		{
//		case 1: {
//			system("CLS");
//			com.Write();
//			system("Pause");
//			break;
//
//		}
//		case 2: {
//			system("CLS");
//			com.addObject();
//			system("Pause");
//			break;
//		}
//		case 0: {
//			com.~Command();
//			exit(1);
//			break;
//		}
//		case 3: {
//			system("CLS");
//			com.stat();
//			system("Pause");
//			break;
//		}
//		case 4: {
//			system("CLS");
//			com.setting();
//			system("Pause");
//			break;
//		}
//		default:
//			cerr << "Error: wrong operation" << endl;
//			system("Pause");
//			break;
//		}
//	}
//}
//
//
//
//int main() {
//
//	try {
//
//		menu();
//
//	}
//	catch (const char* err) {
//		cerr << err << endl;
//	}
//
//
//}