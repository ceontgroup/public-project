package cautruclap;

/**
 * @author KEM
 *
 */
public class Bai10 {
	private int n;
	public Bai10(int hsn)
	{
		n = hsn;
	}
	public void tinh()
	{
		int s = 0, t = 1;
		if ( n < 0)
			System.out.print("So n khong hop le");
		else
		{
			if ( n < 10)
			{
				s = n;
				t = n;
			}
			else
			{
				int tem = n;
				while ( tem != 0 )
				{
					s += tem%10;
					t *= tem%10;
					tem /= 10;
				}				
			}
			System.out.println("Tich la: "+ t);
			System.out.print("Tong la: "+ s);
		}
	}
	public static void main( String[] args)
	{
		Bai10 b10 = new Bai10(1235);
		b10.tinh();
	}
}
