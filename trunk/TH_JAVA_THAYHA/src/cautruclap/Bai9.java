package cautruclap;

/**
 * @author KEM
 *
 */
public class Bai9 {
	
	private int n;
	public Bai9(int tsn)
	{
		n = tsn;
	}
	public void tinh()
	{
		if ( n < 1)
			System.out.print("So n qua nho");
		else
		{
			long s = 1;
			while ( n > 1 )
			{
				s *= n;
				n -= 2;
			}
			System.out.print("Tich la: "+ s);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai9 b9 = new Bai9(12);
		b9.tinh();
	}

}
