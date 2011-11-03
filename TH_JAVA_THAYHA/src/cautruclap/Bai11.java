package cautruclap;
import java.util.Scanner;
/**
 * @author KEM
 *
 */
public class Bai11 {	
	public void nhap()
	{		
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap mot so nguyen:" );
		int n = sc.nextInt();
		System.out.print("So "+ n +" la so nguyen to: " + laNguyenTo(n));
	}
	public static boolean laNguyenTo(int n)
	{
		if ( n < 2)
			return false;
		int i = 3;
		for (i = 3; i < n/2; i++)
			if ( n % i == 0)
				return false;
		if ( i > n / 2) return true;
		else 
			return false;
	}
	public static void main( String [] args)
	{
		Bai11 b11 = new Bai11();
		b11.nhap();
	}
}
