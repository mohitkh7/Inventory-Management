struct B
{
		int billno;
		char Name[50],Unit[20];
		int Qty;
		float Price,Amount;
/*		struct date
		{
			 unsigned char day;        /* 1--31 */
/*			 unsigned char month;      /* 1--12 */
/*			 unsigned int  year;       /* 1980--2099 */
/*			 unsigned char dayofweek;  /* 0--6; 0 = Sunday */
/*		}D;*/

};
int no()
{
		B t;int i=0,billno;
			fstream f("bill.dat",ios::binary|ios::in|ios::out);
			cout<<"\n\n "<<sizeof(t);
			f.seekg((-6),ios::end);
			f.read((char*)&t,sizeof(t));
			if(t.billno<1 || t.billno>1000)
				billno=1;
			else
				billno=(t.billno+1);
			f.close();
			return billno;
}
/*void makebill(int amt)
{
	bill b;
	b.billno=no();
	b.amt=amt;
	cout<<"\n constructing Bill Number "<<b.billno<<"  "<<b.amt;
	fstream f("bill.dat",ios::binary|ios::app|ios::in|ios::out);
	f.write((char*)&b,sizeof(b));
	f.close();
} */
void showbill(int BillNumber)
{
	B b;
	int Final=0;
	int k=1;
	ifstream f("bill.dat",ios::binary);
	//clrscr();
	display();
	cout<<"Here 's Your Bill ";
	cout<<"\n\n*******************************************************************************";
	cout<<setw(42)<<"ABC Grocerry Shop\n";
	cout<<setw(40)<<"TIN No. 123456789";
	cout<<"\n\n Bill Number : "<<BillNumber;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"S. No."<<setw(10)<<"Name"<<setw(13)<<"Qty"<<setw(10)<<"Price"<<setw(10)<<"Amount";
	cout<<"\n--------------------------------------------------------------------------------";
	while(f.read((char*)&b,sizeof(b)))
	{
		if(BillNumber==b.billno)
		 {
			cout<<"\n"<<setw(6)<<k<<setw(10)<<b.Name<<setw(10)<<b.Qty<<" "<<b.Unit<<setw(10)<<b.Price<<setw(10)<<b.Amount<<"\n";
			Final+=b.Amount;
			k++;
		 }
	}
	cout<<"--------------------------------------------------------------------------------";
	cout<<"Total"<<setw(44)<<Final;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<""<<setw(40)<<"Thank You "<<"\n"<<setw(43)<<"Plz Visit Again ";
	cout<<"\n********************************************************************************";
	f.close();
}
void bill()
{
	display();
	cout<<"Enter Bill Number ";
	int n,k=0;;
	cin>>n;
	ifstream f("bill.dat",ios::binary);
	B b;
	while(f.read((char*)&b,sizeof(b)))
	{
		if(n==b.billno)
		 {
			k++;
		 }
	}
	if(k!=0)
		showbill(n);
	else
		cout<<" Bill No. Does Not Exist ";
	getch();
}





