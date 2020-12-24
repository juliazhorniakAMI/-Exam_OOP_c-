#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <algorithm>

using namespace std;
//��������� ����������� ����
class absClass
{
public:
	 //����� �������� �������
	virtual string ToFile() = 0;
	virtual void WriteToConsole() = 0;
	virtual void setting() = 0;
	virtual string GetObjModel() = 0;

};


class Parent :public absClass {
protected:
	//�������� ��� id ���������
	static int counter;
	// ���������� ��� ��������
	string cName;
	int* cId = new int;
	//���������� ��� ��'���
	string objModel;
	int objAge;
	string objOwner;


public:

	//�������������� ������ � ������������ �����


	void setting() {}

	string GetcName() {
		return cName;
	}
	string GetObjModel() {
		return objModel;
	}
	int GetObjAge() {
		return objAge;
	}
	string GetObjOwner() {
		return objOwner;
	}
	int GetcId() {
		return *cId;
	}

	// �������� ������ ����������� ��� ��������� 
	Parent() {
		cName = "";
		*cId = ++counter;
		objModel = "";
		objAge = NULL;
		objOwner = "";

	}
	//����������� � �����������
	Parent(string cName, string objName, int objPrice, string objDate) {
		this->cName = cName;
		*cId = ++counter;
		this->objModel = objName;
		this->objAge = objPrice;
		this->objOwner = objDate;

	}
	// ����������� ���������
	Parent(const Parent& c) {
		cName = c.cName;
		cId = c.cId;
		objModel = c.objModel;
		objAge = c.objAge;
		objOwner = c.objOwner;
	}

	~Parent() {
		cout << "Object From Class Container : " << cName << " done\n";
		delete cId;
	}
	//���������� �����
	void SetAge() {
		objAge = 100;
	}
	//����� ������ ��'���� ��� ������ � ����
string ToFile() { return cName + " " + objModel + " " + to_string(objAge) + " " + objOwner ; }
//����� ������ � �������
	void WriteToConsole() {
		cout << "\nCode of Car  : " << *cId << "\nName of Car : " << cName << "\nName of model : " << objModel << " |Age : " << objAge << " |Name of owner : " << objOwner << endl;
	}


};
//���������� �������� ����� ��� ���������� id ���������
int Parent::counter = 0;

// ������� ���� ���������-��'��� ���������� "Material"
class Derived : public Parent {
protected:
	//��������� ���� ������� ������������ �����-����� 
	string objDate_Register;
public:

	//3 ������������(������ ��� ���������,� �����������,���������)
	Derived() :Parent() {
		objDate_Register = "";
	}

	Derived(string cName, string objName, int objPrice, string objDate, string objAmount) :Parent(cName, objName, objPrice, objDate) {
		this->objDate_Register = objAmount;
	}

	Derived(const Derived& c) :Parent(c) {
		objDate_Register = c.objDate_Register;
	}
	//���������� �����
	void SetAge() {
		objAge = 200;
	}
	//�������������� ���������� ����� ����� Contract
	string ToFile() { return cName + " " + objModel + " " + to_string(objAge) + " " + objOwner + " " +objDate_Register; }
	// ����������
	~Derived() {
		cout << "\n\nObject From Class Material : " << cName << " done\n";
	}
	//����� ����� ������� ������������
	string GetObjDate() {
		return objDate_Register;
	}
	//����� ����������� ��'����
	void setting() {
		
		char op;
		while (true) {
			system("CLS");
			//�� ��������� ��������� switch �������� ���� ��'���� � �������
			cout << "1. Change name of car;\t(" << cName << ")" << endl;
			cout << "2. Change model.\t(" << objModel << ")" << endl;
			cout << "3. Change date of the car.\t(" << objDate_Register << ")" << endl;
			cout << "4. Change age.\t(" << objAge << ")" << endl;
			cout << "5. Change owner.\t(" << objOwner << ")" << endl;
			cout << "6. Exit" << endl;
			cin >> op;
			if (op == '6') {
				break;
			}
			switch (op) {
			case '1': {
				cout << "Name of car: " << cName << endl;
				string tmp;
				cout << "Enter new name of car : ";
				cin >> tmp;
				cName = tmp;
				break;
			}
			case '2': {
				cout << "Model : " << objModel << endl;
				string tmp;
				cout << "Enter new model : ";
				cin >> tmp;
				objModel = tmp;
				break;
			}
			case '3': {
				cout << "Date : " << objDate_Register << endl;
				string tmp;
				cout << "Enter new date : ";
				cin >> tmp;
				objDate_Register = tmp;
				break;
			}
			case '4': {
				cout << "Age : " << objAge << endl;
				int tmp;
				cout << "Enter new age : ";
				cin >> tmp;
				objAge = tmp;
				break;
			}

			case '5': {
				cout << "owner : " << objOwner << endl;
				string tmp;
				cout << "Enter owner : ";
				cin >> tmp;
				objOwner = tmp;
				break;
			}
			default: {
				cerr << "Error: wrong operation" << endl;
				system("Pause");
				break;
			}
			}
		}
	}
	//�������������� ���������� ����� ������ �� �������
	void WriteToConsole() {
		cout << "\nCode of car  : " << *cId << "\nName of car : " << cName << "\nName of model : " << objModel << " |Age : " << objAge << " |Owner : " << objOwner << " |Date : " << objDate_Register << endl;
	}

	
};
//// Functor
class Functor {

public:
	// ������������� �������� ()
	bool operator()(Parent* v1, Parent* v2) {
		//����������� �� ����� ��'����
		return v1->GetObjAge() > v2->GetObjAge();
	}

};
//���� ��� ��������� ��'���� � �������� ������ ��������
class Operation {
	//��������� ������ ���������� ������ ���� Contract 
	vector<Parent*> data;
public:
	//� ���������� ������� ��'���� � �����,� ���������� ������� � ����
	Operation() {
				ReadFromStorage();
	}
		
			~Operation() {
				WriteToStorage();
			
				
			}
			//����� ���������� � �����
	void ReadFromStorage()
	{
		//�������� ����
		ifstream myfile("file.txt");
		string _cName;
		string _objName;
		int _objPrice;
		string _ObjOwner;
		string _objDate;
	
		//���� �� �����������,���� �������
		if (!myfile)
		{
			throw("Error: file.txt not found");

		}
		//������ ����� ����� ���� ��'����,������� ��� � ���. ����� ���������� ����� � ������� � �����
		for (int i = 0; myfile; i++) {
			if (myfile >> _cName >> _objName >> _objPrice >> _ObjOwner >> _objDate)
			{
				Derived* tmp = new Derived(_cName, _objName, _objPrice, _ObjOwner, _objDate);
				data.push_back(tmp);
			}
		}
		myfile.close();
	}
	 //����� ������ � ����
	void WriteToStorage() {
		ofstream outf("OUT.txt", ios::out);
		if (!outf)
		{
			throw("Error: fileOut.txt not found");

		}
		else {
			for (int i = 0; i < data.size(); i++) {
				outf << data[i]->ToFile() << endl;
			}
		}
		outf.close();
	}
	//����� ��� ������ �� �������
	void Write() {
		for (int i = 0; i < data.size(); i++) {
			data[i]->WriteToConsole();
		}
	}

	
	
	//����� ��� ����������� ��'����
	void setting() {
		cout << "- - - - - - - - - - - - - - - "<<endl;
		Write();
		cout << "Enter code of car : ";
		vector<Parent*>::iterator it;
		int i;
		cin >> i;
		//��������� �������� ��'����,���� ����� �� id
		it = find_if(data.begin(), data.end(), [&](Parent* tmp) {return tmp->GetcId() == i; });
		//��������� ������ ��������� ��������� � ������� ����� setting 
		data[it - data.begin()]->setting();
		

	}
	//����� ����������� ��������
	void Findelem() {
	
		cout << endl;
		cout << "- - - - - - - - - - - - - -"<<endl;
		cout << "Enter the model of car you want to find:" << endl;
		string tmp;
		cin >> tmp;
		//��������� �������� ��������� ��'����,���� �������� �� ������
		auto q = find_if(data.begin(), data.end(), [&](absClass * c) {
			return c->GetObjModel() == tmp;
		
		});
		cout << "Here is the info of object you seeked for: " << endl;
		//������� �� �������
		(*q)->WriteToConsole();
		
	}
	//��������� �������� ��������� 
	Operation& operator+(Derived*& other)
	{

		data.push_back(other);

		return *this;
	}
	
	// ���������
	void Registration() {
				string _cName;
				string _objName;
				int _objPrice;
				string _objOwner;
				string _objDate;
				cout << "- - - - - - - -  - - -"<<endl;
				cout << "Enter name of car : ";
				cin >> _cName;
				cout << "Enter model of the car : ";
				cin >> _objName;
				cout << "Enter age : ";
				cin >> _objPrice;
				cout << "Enter owner : ";
				cin >> _objOwner; 
				cout << "Enter date : ";
				cin >> _objDate;
		
				Derived *m=new Derived(_cName, _objName, _objPrice, _objOwner, _objDate);
				
		
				//����� ����� ��'��� �� ������
				
			
				
				  data.push_back(m);
			
				WriteToStorage();
				cout << "The registration has been made\n";
			}
	//���������� ��'���� �� ����
	void Statistics() {
				Functor f;
				//��� ���������� ������������� �������
				sort(data.begin(), data.end(), f);
				cout << "- - - - - - - - - - - - - -" << endl;
				cout << "\nStatistic of products: " << endl;
				Write();
			}
		
	};
	//��������� �����������
void ForUSER() {
	Operation op;
	short tmp = NULL;
	while (true) {
		//�������� �����,�� ������ ��������
		cout << 
			"\t\tSelect option: \n" <<
			"1.Show Available Cars\n" <<
			"2.Register a car\n" <<
			"3.Show statistics of products by age\n" <<
			"4.Find the info of the car by model\n" <<
			"5.Edit the product\n"<<
			"0.Exit\n\n";
		cin >> tmp;
		switch (tmp)
		{
		case 1: {
		
			op.Write();
			system("Pause");
			break;

		}
		case 2: {
			system("CLS");
			op.Registration();
			system("Pause");
			break;
		}
		case 0: {
			op.~Operation();
			exit(1);
			break;
		}
		case 3: {

			op.	Statistics();
			system("Pause");
			break;
		}
		case 4: {
		
			op.Findelem();
			system("Pause");
			break;
		}
		case 5: {

			op.setting();
			system("Pause");
			break;
		}
		
		default:
			cerr << "Error" << endl;
			system("Pause");
			break;
		}
	}
}

	int main() {
		//������������� �������� �� �������
		try {
			// �������� ������� ���������� �����������
			ForUSER();

		}
		catch (const char* err) {
			cerr << err << endl;
		}

		return 0;
	}
