
	public class Chicken{
		public static void main(String[] args){
		for(int i=0;i<=20;i++){
				for(int j=0;j<=33;j++){
					for(int k=0;k<=100-i-j;k++){
						if((i+j+k==100) && (i*5+j*3+k/3==100)){
							System.out.println(i+"\t"+j+"\t"+k);	
						}
					}
				}
			}
		}
	}


