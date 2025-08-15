package BinaryTreeStructure;

public class BinaryNode {
    public int value;
    public BinaryNode right;
    public BinaryNode left;

    public BinaryNode(){
        this.right = null;
        this.left = null;
    }

    public BinaryNode(int data){
        this.value = data;
        this.left = null;
        this.right = null;

    }
}
