package cautruclap;

/**
 * @author KEM
 *
 */
public class Bai8 {
	private int n;
	public Bai8( int tsn)
	{
		n = tsn;
	}
	static public int giaiThua(int n)
	{
		int s = 1;
		for ( int i = n; i > 0; --i)
		{
			s *= i;
		}
		return s;
	}
	public void tinh()
	{		
		if ( n <= 0)
			System.out.print("So n qua nho");
		else
		{
			float s = 0;
			for ( int i = 1; i <= n; ++i)
			{
				s += 1.0f/giaiThua(2*i - 1);
			}
			System.out.print("Tong la: "+s);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai8 b8 = new Bai8(3);
		b8.tinh();
	}

}
