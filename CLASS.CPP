//class
class item
{
	private:
		int id,price,cp,reorder,min,stock;
		float profit;
		char name[50],unit[10];
	public:
		void enter(int z)
		{
			display();
			Number n;
			if(z==1)
				id=n.ReadItemNo();
			cout<<"\n\nEnter Product Details\n\nProduct id : "<<id;
			cout<<"\n\nEnter Product Name : ";gets(name);
			cout<<"\nEnter Unit Of Product : ";gets(unit);
			cout<<"\nEnter Cost Price of Product : ";cin>>cp;
			cout<<"\nEnter Selling Price of Product : ";cin>>price;
			pro();
			cout<<"\nEnter Current Stock ";cin>>stock;
			cout<<"\nEnter Minimun Stock when to notify Reorder : ";cin>>min;
			cout<<"\nEnter Amount to be Reordered ";cin>>reorder;
			cout<<"\n\nNew Product "<<name<<" Added in Stock ";
			if(z==1)
				n.SetItemNo();
		}
		/*void itemid()
		{
			item t;int i=0;
			ifstream f("item.dat",ios::binary);
			f.seekg(-76,ios::end);
			f.read((char*)&t,sizeof(t));
			if(t.id<1 || t.id>1000)
				id=1;
			else
				id=(t.id+1);
			f.close();
		}
	       /*	void itemid()
		{
			item t;int i=0;
			display();
			ifstream f("item.dat",ios::binary);
			f.read((char*)&t,sizeof(t));
			while(f)
			{
				++i;
				f.read((char*)&t,sizeof(t));
			}
			id=(i+1);
		}*/
		void pro()
		{
			profit=((price-cp)*(100/cp));
			cout<<"\t\tProfit : "<<profit<<" %\n";
		}
		void showu()
		{
			cout<<setw(7)<<id<<setw(17)<<name<<setw(10)<<price<<setw(17)<<stock<<" "<<unit;
		}
		void showad()
		{
			//cout<<setw(3)"ID"<<setw(10)<<"Name"<<setw(10)<<"Cost"<<setw(10)<<"Price"<<setw(10)<<"Profit%"<<setw(11)<<"In Stock"<<setw(10)<<"Min Qty"<<setw(10)<<"Reorder Qty\n\n" ;
			cout<<setw(4)<<id<<setw(10)<<name<<setw(10)<<cp<<setw(10)<<price<<setw(10)<<profit<<setw(7)<<stock<<" "<<unit<<setw(10)<<min<<setw(13)<<reorder;
		}
		int compare(int n)
		{
			if(n==id)
				return 1;
			else
				return 2;
		}
		void order(int n, int &z)
		{
			int j;
			if(n==0)
				{
					cout<<"\nEnter Amount of "<<name<<" to be Reodered : ";
					cin>>j;
					stock+=j;
					cout<<"\n"<<j<<" "<<unit<<" "<<name<<" Reordered . Updated Stock :"<<stock<<" "<<unit;
					getch();
				}
			if(n==1)
				if(stock<min)
					{
						cout<<"\n"<<name<<" need to be Reordered.  Current Stock : "<<stock<<" "<<unit<<" is below Mentioned Min Qty. ";
						z=1;
					}
			if(n==2 & stock<min)
			{
				stock+=reorder;
				cout<<"\n"<<name<<" Reordered ";getch();
			}
		}
		void purchase(int &amt, int z)
		{
			int qty;
			cout<<"\n Enter Qty. of "<<name<<" you want to purchase : ";
			cin>>qty;
			if(qty<=stock)
			{
				cout<<"\n\nYou want to purchase "<<qty<<" "<<unit<<" of "<<name<<" at price "<<price;
				amt=qty*price;
				cout<<"\n\nTotal Amount : "<<amt;
				cout<<"\n\nConfirm Purchase (y/n) : ";
				char ch=getch();
				if(ch=='y' || ch=='Y')
				{
					stock-=qty;
					cout<<"\n"<<qty<<" "<<unit<<" of "<<name<<" Purchased ";
					makebill(qty,z);
				}
				else
				{
					cout<<" Purchase CANCELLED ";
					amt=0;
				}
			}
			else
			{
				cout<<"\n"<<qty<<" "<<unit<<" "<<name<<" is not available in stock ";
				cout<<"\n\nKindly order Less than "<<qty<<" "<<unit<<" or Visit Later ";
				amt=0;
			}
		}
		void makebill(int Qty,int z)
		{

			ofstream f("bill.dat",ios::binary|ios::app);
			struct B
			{
				int billno;
				char Name[50],Unit[20];
				int Qty;
				float Price,Amount;
			};
			B bill;
			bill.billno=z;
			strcpy(bill.Name,name);
			bill.Qty=Qty;
			bill.Price=price;
			bill.Amount=Qty*price;
			strcpy(bill.Unit,unit);
			f.write((char*)&bill,sizeof(bill));
			getch();
			f.close();
		}

};


