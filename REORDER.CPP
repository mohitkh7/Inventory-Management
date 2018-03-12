/*// reorder
void reorder()
{
	display();
	item t;
	int n;
	cout<<"Enter Item
	ifstream f("item.dat");
	while(f.read((char*)&t,sizeof(t)))
	{
		if(t.order()==1)*/
// reoredr
void reorder()
{
	int i,n,k=0,j=0;
	item s;
	display();
	showad();
	cout<<"\n\nEnter Product ID of Product To be Reorder : ";
	cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);
	f.read((char *)&s,sizeof(s));
	while(f)
	{
		if(s.compare(n)==1)
		{
			f.seekg(k*sizeof(s),ios::beg);
			s.order(0,0);
			f.write((char*)&s,sizeof(s));
			j++;
		}
	f.read((char*)&s,sizeof(s));
	k++;
	}
	if(j==0)
		cout<<"\n\nProduct ID Does Not Exist ";
}
void reorderall()
{
	int i,n,k=0,z=0;
	item s;
	display();
	showad();
	//cout<<"\n\nEnter Product ID of Product To be Reorder : ";
	//cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);
	f.read((char *)&s,sizeof(s));
	while(f)
	{
			//f.seekg(k*sizeof(s),ios::beg);
			s.order(1,z);
			f.read((char*)&s,sizeof(s));
	}
	f.close();
	if(z==1)
	{
	cout<<"\n\n Do You Want To Reorder All Listed Item (y/n)";
	char ch;
	ch=getch();
	if(ch=='y'||ch=='Y')
		{
			fstream f("item.dat",ios::in|ios::out|ios::binary);
			f.read((char*)&s,sizeof(s));
			while(f)
			{
				s.order(2,0);
				f.seekg(k*sizeof(s),ios::beg);
				f.write((char*)&s,sizeof(s));
				f.read((char*)&s,sizeof(s));
				k++;
			}
			f.close();
		}
	}
}
