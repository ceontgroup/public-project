package cautrucluachon;

/**
 * @author KEM
 *
 */
public class Bai3 {

	private float a, b, c;
	/**
	 * @category constructor
	 * @param a_ initialize value for member variable a
	 * @param b_ initialize value for member variable b
	 * @param c_ initialize value for member variable c
	 */
	public Bai3(float a_, float b_, float c_)
	{
		a = a_;
		b = b_;
		c = c_;
	}
	public void solve()
	{
		if ( ( a - b ) * ( a - c ) < 0 )
			System.out.println("So trung gian la: " + a);
		if ( ( b - a ) * ( b - c ) < 0 )
			System.out.println("So trung gian la: " + b);
		if ( ( c - a ) * ( c - b ) < 0 )
			System.out.println("So trung gian la: " + c);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai3 stg = new Bai3(5, 3, -7);
		stg.solve();
	}

}
