package cautruclap;

/**
 * @author KEM
 *
 */
public class Bai6 {
	private int n;
	public Bai6(int n_)
	{
		n = n_;
	}
	public void solve()
	{
		if ( n <= 0)
			System.out.print("So n qua nho !");
		else
		{
			float s = 0;
			for ( int i = n; i > 0; --i)
			{
				s += 1.0f/i;
			}
			System.out.println("Tong la: "+ s);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai6 tong = new Bai6(3);
		tong.solve();
	}

}
