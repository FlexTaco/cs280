import java.util.*;;
public class test{
    public static void main(String[] args) {
        int []digits = {1,2,3};
        int length = digits.length-1;
        int sum = 0;
        for(int i= 0; i< digits.length; i++){
            sum += digits[i]*Math.pow(10,length);
            length-=1;
        }

        sum+=1;
        int newLength = String.valueOf(sum).length();
        int[] plusOne = new int[newLength];

        //add to new array
        for(int i = 0; i < newLength+1; i++){
            plusOne[i] = (int)(sum/Math.pow(10, newLength-1));
            //System.out.println(plusOne[i]);
            System.out.println(sum);
            newLength-=1;
            sum -= Math.pow(10, newLength);
            System.out.println(sum);
            
        }
        
        
    }
}
