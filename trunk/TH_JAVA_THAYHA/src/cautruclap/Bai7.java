package cautruclap;

/**
 * @author KEM
 *
 */
public class Bai7 {
	private int n;
	public Bai7(int n_)
	{
		n = n_;
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
		float s = 15;
		if ( n <= 0 )
			System.out.println("So n qua nho");
		else
		{
			float dau = -1;
			for (int i = 1; i <= n; ++i)
			{
				s += 1.0f/giaiThua(i)*dau;
				dau *= -1;
			}
			System.out.println("Tong la: " + s);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai7 b7 = new Bai7(2);
		b7.tinh();
	}

}
