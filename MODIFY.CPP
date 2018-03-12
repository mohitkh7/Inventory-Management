// Modify
void modify()
{
	int i,n,k=0,j=0;
	item s;
	display();
	showad();
	cout<<"\n\nEnter Product ID of Product To be Modified : ";
	cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);
	f.read((char *)&s,sizeof(s));
	while(f)
	{
		if(s.compare(n)==1)
		{
			s.showad();getch();
			f.seekg(k*sizeof(s),ios::beg);
			s.enter(0);
			f.write((char*)&s,sizeof(s));
			j++;
		}
	f.read((char*)&s,sizeof(s));
	k++;
	}
	if(j==0)
		cout<<"\n\nProduct ID Does Not Exist ";
}
