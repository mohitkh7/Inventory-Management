// purchase
void pur()
{
	int i,n,amt=0,bill=0;
	item s;
	Number no;
	int BillNumber=no.ReadBillNo();
	again:
	int j=0,k=0;
	display();
	showu();
	cout<<"\n\nEnter Product ID of Product You Want To Purchase : ";
	cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);
	f.read((char *)&s,sizeof(s));
	while(f)
	{
		if(s.compare(n)==1)
		{
			//s.showad();getch();
			f.seekg(k*sizeof(s),ios::beg);
			s.purchase(amt,BillNumber);
			f.write((char*)&s,sizeof(s));
			j++;
		}
	f.read((char*)&s,sizeof(s));
	k++;
	}
	if(j==0)
		cout<<"\n\nProduct ID Does Not Exist ";
	bill+=amt;
	getch();
	cout<<"\n\nDo You want To Purchase More (y/n) : ";
	char ch=getch();
	if(ch=='y'||ch=='Y')
		goto again;
	/*if(amt!=0)
		s.makebill(amt);*/
	showbill(BillNumber);
	no.SetBillNo();

}
