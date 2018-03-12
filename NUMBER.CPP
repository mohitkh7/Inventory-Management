// Numbering
class Number
{
	int ItemNo;
	int BillNo;
	public :
		void SetItemNo();
		void SetBillNo();
		int ReadItemNo();
		int ReadBillNo();
};
void Number::SetItemNo()
{
	int item;
	ifstream f("default.dat",ios::binary);
	Number No;
	f.read((char*)&No,sizeof(No));
	No.ItemNo++;
	f.close();
	ofstream m("default.dat",ios::binary);
	m.write((char*)&No,sizeof(No));
	m.close();
}
void Number::SetBillNo()
{
	int item;
	ifstream f("default.dat",ios::binary);
	Number No;
	f.read((char*)&No,sizeof(No));
	No.BillNo++;
	f.close();
	ofstream m("default.dat",ios::binary);
	m.write((char*)&No,sizeof(No));
	m.close();
}
int Number::ReadBillNo()
{
	int item;
	ifstream f("default.dat",ios::binary);
	Number No;
	f.read((char*)&No,sizeof(No));
	return ++No.BillNo;
}
int Number::ReadItemNo()
{
	int item;
	ifstream f("default.dat",ios::binary);
	Number No;
	f.read((char*)&No,sizeof(No));
	return ++No.ItemNo;
}



