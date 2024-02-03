import java.util.Arrays;
import java.util.Scanner;

public class Quick_sort {
    public static void main(String[] args) {
        int s=0,e=0;
        int n;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Size of array");
        n=in.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter elements of Array: ");
        for(int i=0;i<n;i++){
            nums[i]=in.nextInt();
        }
//        Arrays.sort(nums);  Internal Sorting Algorithm i.e Quick Sort
       sort(nums,0,nums.length-1);
        System.out.println(Arrays.toString(nums));
    }
    static void sort(int[] nums,int low,int high){
         if(low>=high){
             return;
         }

         int s = low;
         int e = high;
         int m = s+(e-s)/2;
         int pivot=nums[m];
// Also a reason why if it is already sorted it will not compare
         while(s<=e){
             while(nums[s] < pivot){
                 s++;
             }
             while (nums[e]>pivot){
                 e--;
             }

             if(s<=e){
                int temp=nums[s];
                nums[s]=nums[e];
                nums[e]=temp;
                s++;e--;
             }
         }
         // Now my pivot as coorect index sort the two halves now
         sort(nums, low, e);
         sort(nums, s, high);
    }
}
