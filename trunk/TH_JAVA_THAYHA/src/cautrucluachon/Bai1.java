package cautrucluachon;

/**
 * @author KEM
 *
 */
public class Bai1 {

	private float hsa, hsb;	
	/**
	 * @category constructor
	 * @param a initialize value for member variable a
	 * @param b initialize value for member variable b
	 */
	public Bai1(float a, float b)
	{
		hsa = a;
		hsb = b;
	}
	/**
	 * @see solve
	 */
	public void solve()
	{
		if ( hsa == 0 )
		{
			if ( hsb == 0 )
				System.out.println("Phuong trinh vo so nghiem !");
			else
				System.out.println("Phuong trinh vo nghiem !!");
		}
		else
		{
			System.out.println("Phuong trinh co nghiem la: " + ( -hsb/hsa ) );
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Bai1 ptb1 = new Bai1( 1 , 2 );
		ptb1.solve();
		ptb1 = new Bai1( 0, 1 );
		ptb1.solve();
		ptb1 = new Bai1( 0, 0 );
		ptb1.solve();
	}

}
