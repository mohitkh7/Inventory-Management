// to create Back up of the file 
void backup()
{
	display();
	item t;
	char ch;
	cout<<"\n\n1.To Backup Data\n2.To Retrieve Backup Data\n";
	ch=getch();
	if(ch=='1')
	{
		ifstream org("item.dat",ios::binary);
		ofstream copy("backup.dat",ios::binary);
		while(org.read((char*)&t,sizeof(t)))
		{
			copy.write((char*)&t,sizeof(t));
		}
		cout<<"\n\nFile Backed Up ";
		org.close();
		copy.close();
	}
	else if(ch=='2')
	{
		ifstream back("backup.dat",ios::binary);
		ofstream dest("item.dat",ios::binary);
		while(back.read((char*)&t,sizeof(t)))
		{
			dest.write((char*)&t,sizeof(t));
		}
		cout<<"\n\nData Retrieved ";
		dest.close();
		back.close();
	}
	else
		cout<<"\n\n Invalid Input ..\try again";
		getch();
}
		

	