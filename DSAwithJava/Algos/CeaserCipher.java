package Algos;

public class CeaserCipher{
    private int keyInc;
    public String encrypt(String message,char key){
        char[] chars = message.toCharArray();
        key=Character.toUpperCase(key);
        keyInc = (int)key-'A';
        for(int i=0;i<chars.length;i++){
            if(Character.isLetter(chars[i])){
                int num=0;
                if(Character.isUpperCase(chars[i])){
                    num = (int)chars[i]-65;
                    num=(num+keyInc+26)%26+65;
                    chars[i]=(char)num;
                }else{
                     num = (int)chars[i]-97;
                    num=(num+keyInc+26)%26+97;
                    chars[i]=(char)num;
                }
            }
        }
        return new String(chars);
    }
    public String decrypt(String message,char key){
        char[] chars = message.toCharArray();
        key=Character.toUpperCase(key);
        keyInc = (int)key-'A';
        for(int i=0;i<chars.length;i++){
            if(Character.isLetter(chars[i])){
                int num=0;
                if(Character.isUpperCase(chars[i])){
                    num = (int)chars[i]-65;
                    num=(num-keyInc+26)%26+65;
                    chars[i]=(char)num;
                }else{
                    num = (int)chars[i]-97;
                    num=(num-keyInc+26)%26+97;
                    chars[i]=(char)num;
                }
            }
        }
        return new String(chars);
    }
}
