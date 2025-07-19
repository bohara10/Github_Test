package BinaryTreeStructure;

import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BinaryTree {

    public static int binaryInsert(BinaryNode rootNode,BinaryNode node){
        if(rootNode==null){
            rootNode = node;
            return rootNode.value;
        }else if(rootNode.value>=node.value){
            return binaryInsert(rootNode.left,node);
        }else return binaryInsert(rootNode.right,node);
    }


    public static boolean search(int searchVal,BinaryNode rootNode){
        if(rootNode==null) return false;
        if(rootNode.value==searchVal) return true;
        if(rootNode.value>searchVal){
            return search(searchVal,rootNode.left);
        }else return search(searchVal,rootNode.right);
    }

    public static boolean search(BinaryNode searchVal,BinaryNode rootNode){
        if(rootNode==null) return false;
        if(rootNode.value==searchVal.value) return true;
        if(rootNode.value>searchVal.value){
            return search(searchVal,rootNode.left);
        }else return search(searchVal,rootNode.right);
    }

    public static void inorderDisplay(BinaryNode rootNode, List<Integer> nums){
        if(rootNode==null){
            return;
        }
        inorderDisplay(rootNode.left,nums);
        nums.add(rootNode.value);
        inorderDisplay(rootNode.right,nums);
    }

    public static void preorderDisplay(BinaryNode rootNode, List<Integer> nums){
        if(rootNode==null){
            return;
        }
        nums.add(rootNode.value);
        preorderDisplay(rootNode.left,nums);
        preorderDisplay(rootNode.right,nums);
    }

    public static void postorderDisplay(BinaryNode rootNode, List<Integer> nums){
        if(rootNode==null){
            return;
        }
        nums.add(rootNode.value);
        postorderDisplay(rootNode.left,nums);
        postorderDisplay(rootNode.right,nums);
    }

    public static List<Integer> breadthFirstSearch(BinaryNode rootNode){
        if(rootNode==null) return null;
        Queue<BinaryNode> queue = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        list.add(rootNode.value);
        queue.add(rootNode);
        while (!queue.isEmpty()){
            BinaryNode current = queue.poll();
            list.add(current.value);
            if(current.left!=null){
                queue.add(current.left);
            }
            if (current.right!=null){
                queue.add(current.right);
            }
        }
        return list;
    }

    public BinaryNode sortedListToBST(LinkedList<Integer> head) {
        if (head == null) return null;
        return buildBST(head, null);
    }

    private BinaryNode buildBST(LinkedList<Integer> head, LinkedList<Integer>tail) {
        if (head == tail) return null;
        LinkedList<Integer> slow = head;
        LinkedList<Integer> fast = head;
        while (fast != tail && fast.next != tail) {
            fast = fast.next.next;
            slow = slow.next;
        }
        BinaryNode root = new BinaryNode(slow.val);
        root.left = buildBST(head, slow);
        root.right = buildBST(slow.next, tail);
        return root;
    }
}

