package cautrucluachon;

/**
 * @author KEM
 *
 */
public class Bai2 {
	private float hsa, hsb, hsc;
	/**
	 * @category constructor
	 * @param a initialize value for member a
	 * @param b initialize value for member b
	 * @param c initialize value for member c
	 */
	public Bai2( float a, float b, float c )
	{
		hsa = a;
		hsb = b;
		hsc = c;
	}
	/**
	 * @see solve
	 */
	public void solve()
	{
		if ( hsa == 0 )
		{
			System.out.println("Khong phai phuong trinh bac hai");
		}
		else
		{
			float delta = hsb * hsb - 4 * hsa * hsc;
			if ( delta < 0 )
				System.out.println("Phuong trinh vo nghiem");
			else if ( delta == 0 )
				System.out.println("Phuong trinh co nghiem la: " + ( -hsb/( 2*hsa )));
			else 
			{
				System.out.println("Nghiem x1 = " + ( (-hsb - Math.sqrt(delta))/( 2*hsa )));
				System.out.println("Nghiem x2 = " + ( (-hsb + Math.sqrt(delta))/( 2*hsa )));
			}			
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai2 ptb2 = new Bai2(1, 2, -3);
		ptb2.solve();
	}

}
