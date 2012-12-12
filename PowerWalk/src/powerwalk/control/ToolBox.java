package powerwalk.control;

/**
 * Utility class providing shortcuts to standard commonly used tasks
 * @author P.Kramer
 */
public abstract class ToolBox {
    
    /**
     * returns the first index i was found in arr, or -1 if arr does not contain i
     * @param i the element to look for
     * @param arr the array to search in
     * @return the index of i in arr
     */
    public static int arrayIndexOf(int i, int[] arr) {
        for (int k=0;k<arr.length;k++) {
            if (arr[k] == i) return k;
        }
        return -1;
    }
    
}
