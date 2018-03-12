// Delete
void del()
{
	ifstream f("item.dat",ios::binary);
	ofstream j("temp.dat",ios::binary);
	int n,i,k=0;
	item s;
	display();
	showad();
	cout<<"\n\nItem Id To be Deleted ";
	cin>>n;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(s.compare(n)!=1)
				j.write((char*)&s,sizeof(s));
		else
			k=1;
	}
	if(k==0)
		cout<<"\nItem Id Does Not Exist ";
	else
		cout<<"\nItem No "<<n<<" deleted ";
	f.close();
	j.close();
	remove("item.dat");
	rename("temp.dat","item.dat");
}