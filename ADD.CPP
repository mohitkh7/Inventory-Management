// add new product
void add()
{
	display();
	item t;
	ofstream f("item.dat",ios::app|ios::binary);
	t.enter(1);
	f.write((char*)&t,sizeof(t));
	f.close();
}