//admin
void admin()
{
	display();
	//change();
	password();
	top:
	display();
	cout<<"Menu :\n1.Add New Item\n2.Show All Product\n3.Delete Product\n4.Modify Product\n5.Reorder Product\n6.Reorder All\n7.Change Password\n8.Backup or Retrieve Data\n9.Back To Main Menu\n";
	int i;
	i=getch();
	switch(i)
	{
		case 49:
			add();
			break;
		case 50:
			showad();
			break;
		case 51:
			del();
			break;
		case 52:
			modify();
			break;
		case 53:
			reorder();
			break;
		case 54:
			reorderall();
			break;
		case 55:
			change();
			break;
		case 56:
			backup();
			break;
		case 57:
			menu();
			break;
		default:
			cout<<"\nWrong Option :(";
	}
	getch();
	goto top;
}
