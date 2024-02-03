public class Max_min {
    public static void main(String[] args) {
        int[] arr = {5, 6, 7, 8, 9,1, 2, 3, 4};
        int n = arr.length;
        int[] result = findMinMax(arr, 0, n - 1);
        System.out.println("Minimum element: " + result[0]);
        System.out.println("Maximum element: " + result[1]);
    }

    public static int[] findMinMax(int[] arr, int low, int high) {
        int[] result = new int[2];
        if (low == high) {
            result[0] = arr[low];
            result[1] = arr[low];
            return result;
        }
        if (high - low == 1) {
            if (arr[low] > arr[high]) {
                result[0] = arr[high];
                result[1] = arr[low];
            } else {
                result[0] = arr[low];
                result[1] = arr[high];
            }
            return result;
        }
        int mid = (low + high) / 2;
        int[] leftResult = findMinMax(arr, low, mid);
        int[] rightResult = findMinMax(arr, mid + 1, high);
        result[0] = Math.min(leftResult[0], rightResult[0]);
        result[1] = Math.max(leftResult[1], rightResult[1]);
        return result;
    }
}
