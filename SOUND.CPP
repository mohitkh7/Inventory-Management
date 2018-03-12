void sound(int i,int j,int time)
{
	for(;i<=j;i+=50)
	{
		sound(i);
		delay(time);
		nosound();
		nosound();
	}
	// continue
}
