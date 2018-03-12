void menu()
{
	back:
	display();
	cout<<"Menu:\n\n1.Admin Login\n2.Customer Menu\n3.Exit\n";
	int i;
	i=getch();
	if(i==49)
		admin();
	if(i==50)
		customer();
	if(i==51)
		exit(0);
	cout<<"\nWrong Option :(";
	getch();
	goto back;
}