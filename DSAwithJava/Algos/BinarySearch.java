package Algos;
public class BinarySearch {

    public String toHex(int num){
        StringBuilder sb = new StringBuilder();
        while(num>0){
            int remainder = num%16;
            num = num/16;
            if(remainder<10){
                sb.append(remainder);
            } else  {
                sb.append(gethexVal(remainder));
            }
        }
        sb=sb.reverse();
        return sb.toString();
    }

    public char gethexVal(int num){
        return (char)(55+num);
    }
}