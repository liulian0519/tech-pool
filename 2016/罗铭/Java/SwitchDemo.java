import java.util.Scanner;

class SwitchDemo {
	public static void main(String[] args) {
		//��������¼�����
		Scanner sc = new Scanner(System.in);
		
		//���Ƽ���¼������
		System.out.println("������һ������(1-7):");
		int week = sc.nextInt();
		
		//switch�ж����
		switch(week) {
			case 1:
				System.out.println("����һ");
				break;
			case 2:
				System.out.println("���ڶ�");
				break;
			case 3:
				System.out.println("������");
				break;
			case 4:
				System.out.println("������");
				break;
			case 5:
				System.out.println("������");
				break;
			case 6:
				System.out.println("������");
				break;
			case 7:
				System.out.println("������");
				break;
			default:
				System.out.println("���������������");
				break;
			
				
		}
	}
}