import java.util.Scanner;

class FunctionTest{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("�������һ������:");
		int a = sc.nextInt();
		
		System.out.println("������ڶ�������:");
		int b = sc.nextInt();
		
		int result = getMax(a,b);
		System.out.println("�ϴ�ֵ�ǣ�" +result);
		
	}
	
	
	public static int getMax(int a, int b) {
		if(a > b) {
			return a;
		}else{
			return b;
		}
	}
}