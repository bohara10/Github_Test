package Algos;

public class VignereCipher {
    private String key;

    public VignereCipher(String key){
        this.key = key;
    }

    public String encrypt(String plainText){
        char[] plainArray = plainText.toCharArray();
        key=key.toUpperCase();
        char[] keyArray = key.toCharArray();
        int keylen = keyArray.length;
        for (int i = 0; i < plainArray.length; i++) {
            if(Character.isLetter(plainArray[i])) {
                int y=(int)keyArray[i%keylen]-'A';
                if(Character.isUpperCase(plainArray[i])) {
                    int x = (int)plainArray[i]-'A';
                    plainArray[i]=(char)(((x+y+26)%26)+'A');
                }else{
                    int x = (int)plainArray[i]-'a';
                    plainArray[i]=(char)(((x+y+26)%26)+'a');
                }
            }
        }
        return new String(plainArray);
    }


    public String decrypt(String cipherText) {
        char[] plainArray = cipherText.toCharArray();
        key=key.toUpperCase();
        char[] keyArray = key.toCharArray();
        int keylen = keyArray.length;
        for (int i = 0; i < plainArray.length; i++) {
            if(Character.isLetter(plainArray[i])) {
                int y=(int)keyArray[i%keylen]-'A';
                if(Character.isUpperCase(plainArray[i])) {
                    int x = (int)plainArray[i]-'A';
                    plainArray[i]=(char)(((x-y+26)%26)+'A');
                }else{
                    int x = (int)plainArray[i]-'a';
                    plainArray[i]=(char)(((x-y+26)%26)+'a');
                }
            }
        }
        return new String(plainArray);
    }
}
