#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct De
{
	string cau_hoi, a, b, c, d, dap_an;
};

vector <De> cauhoi;
int n;

void doccauhoi();
void xuatcauhoi();
bool kiemTra(De &q);
void chon();

void doccauhoi(ifstream &doc, vector <De> &cauhoi)
{
	doc>>n;
	string tam;
	getline(doc, tam);
	cauhoi.resize(n);
	for (int i=0; i<n; i++)
	{
		getline(doc, cauhoi[i].cau_hoi);
		getline(doc, cauhoi[i].a);
		getline(doc, cauhoi[i].b);
		getline(doc, cauhoi[i].c);
		getline(doc, cauhoi[i].d);
		getline(doc, cauhoi[i].dap_an);
	}
}

void xuatcauhoi(vector <De> &cauhoi)
{
	int diem=0;
	for(int i=0; i<cauhoi.size(); i++)
	{
		cout << cauhoi[i].cau_hoi<<endl;
		cout << cauhoi[i].a<<endl;
		cout << cauhoi[i].b<<endl;
		cout << cauhoi[i].c<<endl;
		cout << cauhoi[i].d<<endl;
		if (kiemTra(cauhoi[i])==true)
		{
			cout << "Dung"<<endl;
			diem++;
		}
		else 
		{
			cout <<"Sai"<<endl;
			cout <<"Dap an dung la "<<cauhoi[i].dap_an<<endl;
		}
	}
	cout <<"So diem cua ban : "<<diem<<endl;
}

bool kiemTra(De &q)
{
	int diem=0;
	string dapanng;
	cout << "Moi ban nhap dap an: ";
	cin>>dapanng;
	if(dapanng==q.dap_an)
		return true;
	else
		return false;
}

void menu()
{
	cout << "Nhap 1 de mo Bo de 1"<<endl;
	cout << "Nhap 2 de mo Bo de 2"<<endl;
	cout << "Nhap 3 de mo Bo de 3"<<endl;
	cout << "Nhap bat ki khac 1, 2, 3 de thoat!"<<endl;
}

void chon()
{
	menu();
	vector <De> cauhoi;
	ifstream doc;
	int select;
	cout << "Lua chon cua ban: ";
	cin >> select;
	switch (select)
	{
		case 1:
			system("cls");
			doc.open("D:/demo/bode1.txt", ios::in);
			doccauhoi(doc, cauhoi);
			xuatcauhoi(cauhoi);
			chon();
			break;
		case 2:
			system("cls");
			doc.open("D:/demo/bode2.txt", ios::in);
			doccauhoi(doc, cauhoi);
			xuatcauhoi(cauhoi);
			chon();
			break;
		case 3: 
			system("cls");
			doc.open("D:/demo/bode3.txt", ios::in);
			doccauhoi(doc, cauhoi);
			xuatcauhoi(cauhoi);
			chon();
			break;
		case 4:
			exit(0);
			break;
	}
}

int main ()
{
	chon();
}
