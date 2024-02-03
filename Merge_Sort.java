import java.util.Arrays;
import java.util.Scanner;

public class Merge_Sort {
    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Size of array");
        n=in.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter elements of Array: ");
        for(int i=0;i<n;i++){
            nums[i]=in.nextInt();
        }
       nums=mergesort(nums);
        System.out.println(Arrays.toString(nums));
    }

    public static int[] mergesort(int[] arr){
        if(arr.length<2){
            return arr;
        }
        int mid = arr.length / 2;  // mid

        int[] left =mergesort(Arrays.copyOfRange(arr,0,mid));
        // It Creates new array and passed into recursion calls & same value differnet object i.e. creating new object
        int[] right =mergesort(Arrays.copyOfRange(arr,mid,arr.length));
        return merge(left,right);
    }

     static int[] merge(int[] first,int[] second){
        int[] mix = new int[first.length+ second.length];
        int i=0;
        int j=0;
        int k=0;
        while(i< first.length && j< second.length){
            if(first[i]<=second[j]){
                    mix[k]=first[i];
                    i++;
            }
            else{
                mix[k]=second[j];
                j++;
            }
            k++;
        }
        // It may possible that one of arrays is not complete
        // Copy the remaining elements
        while(i<first.length){
            mix[k]=first[i];
            i++;
            k++;
        }
        while(j<second.length){
            mix[k]=second[j];
            j++;k++;
        }
        return mix;
    }
}


// Java code to implement a merge sort
//public class Merge_Sort {
//
//    // Method to merge two sorted subarrays
//    public static void merge(int[] arr, int left, int mid, int right) {
//        // Find the sizes of the subarrays
//        int n1 = mid - left + 1;
//        int n2 = right - mid;
//
//        // Create temporary arrays to store the subarrays
//        int[] L = new int[n1];
//        int[] R = new int[n2];
//
//        // Copy the data from the original array to the subarrays
//        for (int i = 0; i < n1; i++) {
//            L[i] = arr[left + i];
//        }
//        for (int j = 0; j < n2; j++) {
//            R[j] = arr[mid + 1 + j];
//        }
//
//        // Initialize the indices of the subarrays and the merged array
//        int i = 0, j = 0, k = left;
//
//        // Merge the subarrays by comparing their elements
//        while (i < n1 && j < n2) {
//            if (L[i] <= R[j]) {
//                arr[k] = L[i];
//                i++;
//            } else {
//                arr[k] = R[j];
//                j++;
//            }
//            k++;
//        }
//
//        // Copy the remaining elements of the subarrays if any
//        while (i < n1) {
//            arr[k] = L[i];
//            i++;
//            k++;
//        }
//        while (j < n2) {
//            arr[k] = R[j];
//            j++;
//            k++;
//        }
//    }
//
//    // Method to sort an array using merge sort
//    public static void mergeSort(int[] arr, int left, int right) {
//        // Base case: check if the array has more than one element
//        if (left < right) {
//            // Find the middle point of the array
//            int mid = (left + right) / 2;
//
//            // Sort the left and right halves of the array recursively
//            mergeSort(arr, left, mid);
//            mergeSort(arr, mid + 1, right);
//
//            // Merge the sorted halves
//            merge(arr, left, mid, right);
//        }
//    }
//
//    // Method to print an array
//    public static void printArray(int[] arr) {
//        for (int element : arr) {
//            System.out.print(element + " ");
//        }
//        System.out.println();
//    }
//
//    // Main method to test the code
//    public static void main(String[] args) {
//        // Create an unsorted array
//        int[] arr = {12, 11, 13, 5, 6, 7};
//
//        // Print the original array
//        System.out.println("Given array:");
//        printArray(arr);
//
//        // Sort the array using merge sort
//        mergeSort(arr, 0, arr.length - 1);
//
//        // Print the sorted array
//        System.out.println("Sorted array:");
//        printArray(arr);
//    }
//}
