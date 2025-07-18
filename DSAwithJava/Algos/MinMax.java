package Algos;

public class MinMax {
    public int GetMax(int[] nums,int start,int end) {
        int maxIndex = 0;

        if(start==end){
            return start;
        }
        else if(start ==end-1){
            if(nums[start]>=nums[end]){
                return start;
            }else return end;
        }
        else{
            int Index1= GetMax(nums,start,(start+end)/2);
            int Index2= GetMax(nums,((start+end)/2)+1,end);
            if(nums[Index1]<nums[Index2]){
                return Index2;
            }else return Index1;
        }
    }

    public int GetMin(int[] nums,int start,int end) {
        int maxIndex = 0;

        if(start==end){
            return start;
        }
        else if(start ==end-1){
            if(nums[start]<=nums[end]){
                return start;
            }else return nums[end];
        }
        else{
            int Index1= GetMin(nums,start,(start+end)/2);
            int Index2= GetMin(nums,((start+end)/2)+1,end);
            if(nums[Index1]<nums[Index2]){
                return nums[Index1];
            }else return nums[Index2];
        }
    }
}
